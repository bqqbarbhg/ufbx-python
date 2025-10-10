import os
import argparse
import ufbx_ir as ir
import json
import re
import dataclasses
from dataclasses import dataclass
from typing import Optional

g_file: ir.File = None
g_outfile = None
g_indent = 0

py_types: dict[str, "PythonType"] = { }
py_structs: dict[str, "PythonStruct"] = { }
py_enums: dict[str, "PythonEnum"] = { }
py_funcs: dict[str, "PythonFunc"] = { }

pyi_structs = set()

module_types = []
module_funcs = []

@dataclass
class PythonArg:
    name: str
    typ: str
    fmt: str
    ptr: str
    arg: str
    vars: str
    ctx: Optional[str] = None
    pre: Optional[str] = None
    post: Optional[str] = None
    input_type: Optional[str] = None
    input_name: Optional[str] = None

    def to_self(self, method: "PythonMethod"):
        ps = py_structs[method.ir.self_type]

        return dataclasses.replace(self,
            name="self", typ="", fmt="", ptr="", vars=f"""
                {ps.name} *{self.name} = ({ps.name}*)self;
            """
        )

def emit(line=""):
    global g_indent
    global g_outfile
    if line:
        print("    " * g_indent + line, file=g_outfile)
    else:
        print("", file=g_outfile)

def indent(delta=1):
    global g_indent
    g_indent += delta

def unindent(delta=1):
    global g_indent
    g_indent -= delta

def get_struct_python_name(st: ir.Struct):
    name = ir.to_pascal(st.short_name)
    return name

def get_func_name(fn: ir.Function):
    name = fn.short_name
    if fn.is_catch:
        name = name.replace("catch_", "")
    if fn.is_len:
        name = name[:-4]
    return name

def emit_lines(extra: str):
    lines = extra.splitlines()
    while lines[0].strip() == "":
        lines = lines[1:]
    while lines[-1].strip() == "":
        lines = lines[:-1]
    if not lines:
        return

    first_indent = re.match("(    )*", lines[0]).group(0)
    for line in lines:
        line = line.removeprefix(first_indent)
        emit(line)

def emit_prefix():
    emit_lines("""
        #include "prelude.h"
    """)

c_types = {
    "void": "void",
    "char": "char",
    "int8_t": "int8_t",
    "uint8_t": "uint8_t",
    "int32_t": "int32_t",
    "uint32_t": "uint32_t",
    "int64_t": "int64_t",
    "uint64_t": "uint64_t",
    "float": "float",
    "double": "double",
    "size_t": "size_t",
    "uintptr_t": "uintptr_t",
    "ptrdiff_t": "ptrdiff_t",
    "bool": "bool",
    "ufbx_real": "ufbx_real",
}

primitive_fmt = {
    "int32_t": ("i", "int", lambda v: f"(int32_t){v}"),
    "uint32_t": ("I", "unsigned int", lambda v: f"(uint32_t){v}"),
    "int64_t": ("L", "long long", lambda v: f"(int64_t){v}"),
    "uint64_t": ("K", "unsigned long long", lambda v: f"(uint64_t){v}"),
    "float": ("f", "float", lambda v: f"{v}"),
    "double": ("d", "double", lambda v: f"{v}"),
    "size_t": ("n", "Py_ssize_t", lambda v: f"(size_t){v}"),
    "uintptr_t": ("n", "Py_ssize_t", lambda v: f"(uintptr_t){v}"),
    "ptrdiff_t": ("n", "Py_ssize_t", lambda v: f"(ptrdiff_t){v}"),
    "bool": ("p", "int", lambda v: f"{v} != 0"),
    "ufbx_real": ("d", "double", lambda v: f"(ufbx_real){v}"),
}

primitive_types = {
    "void": "None",
    "char": "int",
    "int8_t": "int",
    "uint8_t": "int",
    "int32_t": "int",
    "uint32_t": "int",
    "int64_t": "int",
    "uint64_t": "int",
    "float": "float",
    "double": "float",
    "size_t": "int",
    "uintptr_t": "int",
    "ptrdiff_t": "int",
    "bool": "bool",
    "ufbx_real": "float",
    "ufbx_string": "str",
    "ufbx_blob": "bytes",
}

pod_types = {
    "ufbx_vec2": "Vec2",
    "ufbx_vec3": "Vec3",
    "ufbx_vec4": "Vec4",
    "ufbx_quat": "Quat",
    "ufbx_matrix": "Matrix",
}

create_funcs = {
    "scene": "Scene_create",
    "anim": "Anim_create",
    "bakedAnim": "BakedAnim_create",
    "geometryCache": "GeometryCache_create",
}

@dataclass
class BufferSpec:
    prim_type: str
    format: str
    shape: tuple[int, ...]

buffer_specs = {
    "ufbx_bool_list": BufferSpec("bool", "?", (1,)),
    "ufbx_int32_list": BufferSpec("int32_t", "i", (1,)),
    "ufbx_real_list": BufferSpec("ufbx_real", "d", (1,)),
    "ufbx_vec2_list": BufferSpec("ufbx_real", "d", (2,1)),
    "ufbx_vec3_list": BufferSpec("ufbx_real", "d", (3,1)),
    "ufbx_vec4_list": BufferSpec("ufbx_real", "d", (4,1)),
    "ufbx_face_list": BufferSpec("uint32_t", "I", (2,1)),
    "ufbx_edge_list": BufferSpec("uint32_t", "I", (2,1)),
}

class PythonType:
    def __init__(self, ir_type: ir.Type):
        self.ir = ir_type

    def pyi_name(self) -> str:
        prim = primitive_types.get(self.ir.key)
        if prim:
            return prim

        pod = pod_types.get(self.ir.key)
        if pod:
            return pod

        en = py_enums.get(self.ir.key)
        if en:
            return en.name

        nullable = self.ir.is_nullable

        if self.ir.kind == "struct":
            ps = py_structs[self.ir.key]
            if ps.is_emitted or ps.is_emitted_pod or ps.ir.is_list:
                if self.ir.key in pyi_structs:
                    name = ps.name
                else:
                    name = f"\"{ps.name}\""
                if nullable:
                    return f"Optional[{name}]"
                else:
                    return name
        elif self.ir.kind == "pointer":
            inner = py_types[self.ir.inner].pyi_name()
            if nullable:
                return f"Optional[{inner}]"
            else:
                return inner
        elif self.ir.kind == "array":
            inner = py_types[self.ir.inner].pyi_name()
            if self.ir.array_length and self.ir.array_length <= 4:
                inner_str = ", ".join([inner] * self.ir.array_length)
                return f"Tuple[{inner_str}]"
            else:
                return f"Tuple[{inner}, ...]"

        return "Any"

    def c_ufbx_name(self) -> str:
        c_name = c_types.get(self.ir.key)
        if c_name:
            return c_name

        if self.ir.kind == "struct":
            return py_structs[self.ir.key].ir.name
        elif self.ir.kind == "pointer":
            inner = py_types[self.ir.inner]
            if inner.ir.is_const:
                return inner.c_ufbx_name() + " const*"
            else:
                return inner.c_ufbx_name() + " *"
        else:
            return "???"

    def c_name(self) -> str:
        c_name = c_types.get(self.ir.key)
        if c_name:
            return c_name

        if self.ir.kind == "struct":
            return py_structs[self.ir.key].name
        elif self.ir.kind == "pointer":
            inner = py_types[self.ir.inner]
            if inner.ir.is_const:
                return inner.c_name() + " const*"
            else:
                return inner.c_name() + " *"
        else:
            return "???"

class PythonField:
    def __init__(self, ps: "PythonStruct", ir_field: ir.Field):
        self.ir = ir_field
        self.struct = ps
        self.name = self.ir.name
        self.upper = self.ir.name.upper()
        self.lower = self.ir.name.lower()
        self.slot = f"SLOT_{ps.upper}__{self.upper}"

def crawl_fields(ps: "PythonStruct", list: list[PythonField], field: ir.Field):
    if field.private:
        return

    if field.name:
        list.append(PythonField(ps, field))
        return

    ft = g_file.types[field.type]
    if ft.kind == "struct":
        fs = g_file.structs[ft.key]
        if fs.is_union:
            irs = g_file.structs[field.type]
            for child in irs.fields:
                if child.union_preferred:
                    crawl_fields(ps, list, child)
        else:
            irs = g_file.structs[field.type]
            for child in irs.fields:
                crawl_fields(ps, list, child)

class PythonMethod:
    def __init__(self, ps: "PythonStruct", ir_member: ir.MemberFunction):
        self.ir = ir_member
        self.struct = ps
        self.name = self.ir.member_name.removesuffix("_len")

class PythonStruct:
    def __init__(self, ir_struct: ir.Struct):
        self.ir = ir_struct
        self.name = get_struct_python_name(self.ir)
        self.upper = self.ir.short_name.upper()
        self.fields = []

        do_emit = True
        if self.ir.is_pod or self.ir.is_anonymous or self.ir.is_list or self.ir.is_input or self.ir.is_callback or self.ir.is_interface:
            do_emit = False
        if self.ir.name in manual_types:
            do_emit = False
        self.is_emitted = do_emit

        do_pod = False
        if self.ir.is_pod and ir_struct.name not in pod_types:
            do_pod = True
        self.is_emitted_pod = do_pod

        do_from = True
        if not do_emit:
            do_from = False
        if self.ir.name == "ufbx_element":
            do_from = False
        if self.ir.is_element:
            do_from = False
        self.has_from = do_from

        for field in self.ir.fields:
            if field.private:
                continue

            if field.name:
                self.fields.append(PythonField(self, field))
            else:
                crawl_fields(self, self.fields, field)

        methods: list[PythonMethod] = []
        for mf_name in self.ir.member_functions:
            mf = g_file.member_functions[mf_name]
            methods.append(PythonMethod(self, mf))
        self.methods = methods

class PythonEnumValue:
    def __init__(self, ir_value: ir.EnumValue):
        self.ir = ir_value
        self.name = self.ir.short_name

class PythonEnum:
    def __init__(self, ir_enum: ir.Enum):
        self.ir = ir_enum
        self.name = get_struct_python_name(self.ir)
        self.upper = self.ir.short_name.upper()
        self.values = []

        for key in self.ir.values:
            value = g_file.enum_values[key]
            pv = PythonEnumValue(value)
            self.values.append(pv)

class PythonFunc:
    def __init__(self, ir_func: ir.Function):
        self.ir = ir_func
        self.name = get_func_name(self.ir)

        do_emit = True
        if self.ir.is_inline: do_emit = False
        if self.ir.is_ffi: do_emit = False
        if self.ir.catch_name: do_emit = False
        if self.ir.len_name: do_emit = False
        if self.ir.kind in ("retain", "free"): do_emit = False
        if self.ir.name in unsupported_funcs: do_emit = False
        self.is_emitted = do_emit

        input_type = None
        input_name = None

        args = []
        try:
            args = [func_arg(arg) for arg in self.ir.arguments]
        except FunctionArgNotImplemented as e:
            if self.is_emitted:
                print(f"cannot emit '{self.ir.name}': {e}")
            self.is_emitted = False
        args = [arg for arg in args if arg]
        self.args = args

        for arg in args:
            if arg.input_type:
                assert not input_type
                input_type = arg.input_type
                input_name = arg.input_name
        self.input_type = input_type
        self.input_name = input_name

    def get_args(self, method: Optional[PythonMethod]):
        if method:
            args = self.args[:]
            ix = method.ir.self_index
            args[ix] = args[ix].to_self(method)
            return args
        else:
            return self.args

manual_types = {
    "ufbx_string",
    "ufbx_blob",
    "ufbx_void_list",
    "ufbx_const_prop_override_desc_list",
    "ufbx_const_transform_override_list",
    "ufbx_vertex_attrib",
    "ufbx_inflate_input",
    "ufbx_inflate_retain",
    "ufbx_panic",
    "ufbx_error",
    "ufbx_vertex_stream",
}

pyobject_primtive = {
    "void": lambda _: "Py_NewRef(Py_None)",
    "char": lambda v: f"PyLong_FromUnsignedLong((unsigned long){v})",
    "int8_t": lambda v: f"PyLong_FromLong((long){v})",
    "uint8_t": lambda v: f"PyLong_FromUnsignedLong((unsigned long){v})",
    "int32_t": lambda v: f"PyLong_FromLong((long){v})",
    "uint32_t": lambda v: f"PyLong_FromUnsignedLong((unsigned long){v})",
    "int64_t": lambda v: f"PyLong_FromLongLong((long long){v})",
    "uint64_t": lambda v: f"PyLong_FromUnsignedLongLong((unsigned long long){v})",
    "float": lambda v: f"PyFloat_FromDouble({v})",
    "double": lambda v: f"PyFloat_FromDouble({v})",
    "size_t": lambda v: f"PyLong_FromSize_t({v})",
    "uintptr_t": lambda v: f"PyLong_FromSize_t((size_t){v})",
    "ptrdiff_t": lambda v: f"PyLong_FromSsize_t((Py_ssize_t){v})",
    "bool": lambda v: f"Py_NewRef({v} ? Py_True : Py_False)",
    "ufbx_real": lambda v: f"PyFloat_FromDouble({v})",
}

# TODO: Bounds checking
pyobject_primtive_from = {
    "char": lambda v: f"(char)PyLong_AsUnsignedLong({v})",
    "int8_t": lambda v: f"(int8_t)PyLong_AsLong({v})",
    "uint8_t": lambda v: f"(uint8_t)PyLong_AsUnsignedLong({v})",
    "int32_t": lambda v: f"(int32_t)PyLong_AsLong({v})",
    "uint32_t": lambda v: f"(uint32_t)PyLong_AsUnsignedLong({v})",
    "int64_t": lambda v: f"(int64_t)PyLong_AsLongLong({v})",
    "uint64_t": lambda v: f"(uint64_t)PyLong_AsUnsignedLongLong({v})",
    "float": lambda v: f"(float)PyFloat_AsDouble({v})",
    "double": lambda v: f"PyFloat_AsDouble({v})",
    "size_t": lambda v: f"PyLong_AsSize_t({v})",
    "uintptr_t": lambda v: f"(uintptr_t)PyLong_AsSize_t({v})",
    "ptrdiff_t": lambda v: f"(ptrdiff_t)PyLong_AsSsize_t({v})",
    "bool": lambda v: f"PyObject_IsTrue({v})",
    "ufbx_real": lambda v: f"(ufbx_real)PyFloat_AsDouble({v})",
}

pyobject_manual = {
    "ufbx_vec2": lambda v: f"Vec2_from(&{v})",
    "ufbx_vec3": lambda v: f"Vec3_from(&{v})",
    "ufbx_vec4": lambda v: f"Vec4_from(&{v})",
    "ufbx_quat": lambda v: f"Quat_from(&{v})",
    "ufbx_matrix": lambda v: f"Matrix_from(&{v})",
    "ufbx_string": lambda v: f"String_from({v})",
    "ufbx_blob": lambda v: f"Blob_from({v})",
}

manual_to = {
    "ufbx_vec2": ("Vec2", "ufbx_vec2", lambda v: f"Vec2_to({v})", lambda v: v),
    "ufbx_vec3": ("Vec3", "ufbx_vec3", lambda v: f"Vec3_to({v})", lambda v: v),
    "ufbx_vec4": ("Vec4", "ufbx_vec4", lambda v: f"Vec4_to({v})", lambda v: v),
    "ufbx_quat": ("Quat", "ufbx_quat", lambda v: f"Quat_to({v})", lambda v: v),
    "ufbx_matrix": ("Matrix", "ufbx_matrix", lambda v: f"Matrix_to({v})", lambda v: v),
}

unsupported_funcs = {
    "ufbx_inflate",
    "ufbx_tessellate_nurbs_curve",
    "ufbx_tessellate_nurbs_surface",
    "ufbx_subdivide_mesh",
    "ufbx_evaluate_prop",
    "ufbx_evaluate_prop_len",
    "ufbx_evaluate_prop_len_flags",
    "ufbx_evaluate_props",
    "ufbx_load_stdio",
    "ufbx_load_stdio_prefix",
    "ufbx_load_stream_prefix",
    "ufbx_format_error",
    # Unnecessary
    "ufbx_find_prop_concat",
    # TODO: We might want these
    "ufbx_find_string_len",
    "ufbx_find_blob_len",
    # IO
    "ufbx_open_file",
    "ufbx_open_file_ctx",
    "ufbx_open_memory",
    "ufbx_open_memory_ctx",
    "ufbx_default_open_file",
    # Maybe sometime
    "ufbx_generate_indices",
    # Threads
    "ufbx_thread_pool_run_task",
    "ufbx_thread_pool_set_user_ptr",
    "ufbx_thread_pool_get_user_ptr",
    # TODO: Shallow copies
    "ufbx_evaluate_props_flags_len",
    # Topology
    "ufbx_catch_compute_topology",
    "ufbx_catch_generate_normal_mapping",
    "ufbx_catch_topo_next_vertex_edge",
    "ufbx_catch_topo_prev_vertex_edge",
    "ufbx_catch_compute_normals",
    # Maybe
    "ufbx_add_blend_shape_vertex_offsets",
    "ufbx_add_blend_vertex_offsets",
}

def cbool(b):
    return "true" if b else "false"

def to_pyobject(irt: ir.Type, expr: str, ctx: str):
    prim = pyobject_primtive.get(irt.key)
    if prim:
        return "", prim(expr)

    pod = pyobject_manual.get(irt.key)
    if pod:
        return "", pod(expr)

    if irt.kind == "pointer":
        inner = g_file.types[irt.inner]
        if inner.kind == "struct":
            ist = g_file.structs[inner.key]
            ps = py_structs[inner.key]
            if ist.is_element or ist.name == "ufbx_element":
                return "", f"Element_from({expr}, {ctx})"
            elif ps.is_emitted or ist.is_list:
                return "", f"{ps.name}_from({expr}, {ctx})"
    elif irt.kind == "struct":
        irs = g_file.structs[irt.key]
        if irs.is_list:
            ps = py_structs[irs.name]
            return "", f"{ps.name}_from({expr}, {ctx})"

        ps = py_structs.get(irs.name)
        if ps and ps.has_from:
            return "", f"{ps.name}_from(&{expr}, {ctx})"
        if ps and ps.is_emitted_pod:
            return "", f"{ps.name}_from(&{expr})"
    elif irt.kind == "array":
        if irt.array_length:
            expr_name = expr.removeprefix("self->")
            expr_name = expr_name.removeprefix("data->")
            expr_name = re.sub("[^a-z0-9]+", "_", expr_name.lower())
            arr_name = f"arr_{expr_name}"
            tup_name = f"tup_{expr_name}"

            inner = g_file.types[irt.inner]
            inner_pt = py_types[inner.key]
            inner_c = inner_pt.c_ufbx_name()
            if not inner_c.endswith("*"):
                inner_c += " "

            elem_extra, elem_var = to_pyobject(inner, f"{arr_name}[i]", ctx)
            assert not elem_extra

            extra = f"""
                {inner_c}*{arr_name} = {expr};
                PyObject *{tup_name} = PyTuple_New({irt.array_length});
                if (!{tup_name}) return NULL;
                for (size_t i = 0; i < {irt.array_length}; i++) {{
                    PyTuple_SetItem({tup_name}, i, {elem_var});
                }}
            """

            return extra, tup_name

    elif irt.kind == "enum":
        pe = py_enums[irt.key]
        return "", f"PyObject_CallFunction({pe.name}_Enum, \"i\", (int){expr})"

    return "", f"to_pyobject_todo(\"{irt.key}\")"

def from_pyobject(irt: ir.Type, expr: str):
    prim = pyobject_primtive_from.get(irt.key)
    if prim:
        return prim(expr)

    manual = manual_to.get(irt.key)
    if manual:
        return manual[2](expr)

    en = py_enums.get(irt.key)
    if en:
        # TODO: Bounds check
        return f"({irt.key})PyLong_AsLong({expr})"

    rs = py_structs.get(irt.key)
    if rs:
        if rs.is_emitted_pod:
            return f"{rs.name}_to({expr})"

    return None

def emit_error_forward():
    err_enum = g_file.enums["ufbx_error_type"]
    emit()
    emit(f"static PyObject *error_type_objs[{len(err_enum.values)}];")

def emit_getter(ps: PythonStruct, pf: PythonField):
    emit()
    emit(f"static PyObject *{ps.name}_get_{pf.lower}({ps.name} *self, void *closure) {{")
    indent()

    field_type = g_file.types[pf.ir.type]
    extra, value = to_pyobject(field_type, f"self->data->{pf.ir.name}", "self->ctx")

    emit_lines(f"""
        PyObject *slot = self->slots[{pf.slot}];
        if (slot) return Py_NewRef(slot);
        if (!self->ctx->ok) return Context_error(self->ctx);
    """)

    if extra:
        emit_lines(extra)
    
    emit_lines(f"""
        slot = {value};
        self->slots[{pf.slot}] = slot;
        return Py_NewRef(slot);
    """)

    unindent()
    emit("}")

def emit_enum(pe: PythonEnum):
    emit(f"static PyObject *{pe.name}_Enum;")

def emit_list(ps: PythonStruct):
    if not ps.ir.is_list:
        return
    if ps.ir.name in manual_types:
        return

    data_field = ps.fields[0]
    ptr_type = py_types[data_field.ir.type]
    data_type = py_types[ptr_type.ir.inner]

    name = ps.name
    module_types.append(ps.name)

    # Struct declaration
    emit("")
    emit_lines(f"""
        typedef struct {{
            PyObject_HEAD
            Context *ctx;
            Py_ssize_t shape[2];
            {ps.ir.name} data;
        }} {name};
    """)

    # Mapping
    emit()
    emit_lines(f"""
        static Py_ssize_t {name}_len({name} *self, PyObject *key) {{
            return (Py_ssize_t)self->data.count;
        }}
    """)

    # Getter
    get_arg = "self->data.data[index]"
    extra, get_expr = to_pyobject(data_type.ir, get_arg, "self->ctx")
    emit()
    emit_lines(f"""
        static PyObject *{name}_item({name} *self, Py_ssize_t index) {{
            if (!self->ctx->ok) return Context_error(self->ctx);
            size_t count = self->data.count;
            if (index < 0 || (size_t)index >= count) {{
                PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
                return NULL;
            }}
    """)
    indent()
    if extra:
        emit_lines(extra)
    emit(f"return {get_expr};")
    unindent()
    emit("}")

    # Traverse
    emit()
    emit_lines(f"""
        static int {ps.name}_traverse({ps.name} *self, visitproc visit, void *arg) {{
            Py_VISIT(self->ctx);
            return 0;
        }}
    """)

    # Clear
    emit()
    emit_lines(f"""
        static int {ps.name}_clear({ps.name} *self) {{
            Py_CLEAR(self->ctx);
            return 0;
        }}
    """)

    # Dealloc
    emit()
    emit_lines(f"""
        void {ps.name}_dealloc({ps.name} *self) {{
            PyObject_GC_UnTrack(self);
            {ps.name}_clear(self);
            Py_TYPE(self)->tp_free((PyObject *) self);
        }}
    """)

    # Buffer protocol
    buffer_spec = buffer_specs.get(ps.ir.name)
    if buffer_spec:
        emit()

        strides = ", ".join(f"{s} * sizeof({buffer_spec.prim_type})" for s in buffer_spec.shape)

        emit_lines(f"""
            static Py_ssize_t {ps.name}_strides[] = {{ {strides} }};
            static int {ps.name}_getbuffer(PyObject *exporter, Py_buffer *view, int flags) {{
                if (view == NULL) {{
                    PyErr_SetString(PyExc_BufferError, "NULL view in getbuffer");
                    return -1;
                }}

                {ps.name} *self = ({ps.name}*)exporter;
                if (!self->ctx->ok) {{
                    Context_error(self->ctx);
                    return -1;
                }}

                Py_INCREF(self);

                self->ctx->buffer_refs++;

                view->obj = (PyObject*)self;
                view->buf = (void*)self->data.data;
                view->len = (Py_ssize_t)self->data.count * sizeof({data_type.ir.key});
                view->readonly = 1;
                view->itemsize = sizeof({buffer_spec.prim_type});
                view->format = \"{buffer_spec.format}\";
                view->ndim = {len(buffer_spec.shape)};
                view->shape = self->shape;
                view->strides = {ps.name}_strides;
                view->suboffsets = NULL;
                view->internal = NULL;
                return 0;
            }}
        """)

        emit()
        emit_lines(f"""
            static void {ps.name}_releasebuffer(PyObject *exporter, Py_buffer *view) {{
                {ps.name} *self = ({ps.name}*)exporter;
                self->ctx->buffer_refs--;
                Py_DECREF(self);
            }}
        """)

        emit()
        emit_lines(f"""
            static PyBufferProcs {ps.name}_Buffer = {{
                .bf_getbuffer = {ps.name}_getbuffer,
                .bf_releasebuffer = {ps.name}_releasebuffer
            }};
        """)

    # Type declaration
    emit()
    emit_lines(f"""
    static PySequenceMethods {ps.name}_Sequence = {{
        .sq_length = (lenfunc)&{name}_len,
        .sq_item = (ssizeargfunc)&{name}_item,
    }};

    static PyTypeObject {ps.name}_Type = {{
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "ufbx.{ps.name}",
        .tp_doc = PyDoc_STR("{ps.name}"),
        .tp_basicsize = sizeof({ps.name}),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
        .tp_new = PyType_GenericNew,
        .tp_as_sequence = &{ps.name}_Sequence,
        .tp_dealloc = (destructor)&{ps.name}_dealloc,
        .tp_traverse = (traverseproc)&{ps.name}_traverse,
        .tp_clear = (inquiry)&{ps.name}_clear,
    """)
    indent()

    if buffer_spec:
        emit_lines(f"""
            .tp_as_buffer = &{ps.name}_Buffer,
        """)

    unindent()
    emit("};")

    # Create helper
    emit()
    emit_lines(f"""
    static PyObject *{ps.name}_from({ps.ir.name} list, Context *ctx) {{
        {ps.name} *obj = ({ps.name}*)PyObject_CallObject((PyObject*)&{ps.name}_Type, NULL);
        if (!obj) return NULL;
        obj->ctx = (Context*)Py_NewRef(ctx);
        obj->data = list;
    """)

    indent()
    if buffer_spec:
        if len(buffer_spec.shape) == 2:
            emit_lines(f"""
                obj->shape[0] = (Py_ssize_t)list.count;
                obj->shape[1] = {buffer_spec.shape[0]};
            """)
        elif len(buffer_spec.shape) == 1:
            emit_lines(f"""
                obj->shape[0] = (Py_ssize_t)list.count;
            """)
        else:
            raise RuntimeError("bad shape")

    emit_lines(f"""
        return (PyObject*)obj;
    """)
    unindent()
    emit("}")

def emit_pod_struct_forward(ps: PythonStruct):
    if not ps.is_emitted_pod:
        return

    emit_lines(f"""
        static PyObject *{ps.name}_from(const {ps.ir.name} *v);
        static {ps.ir.name} {ps.name}_to(PyObject *v);
    """)

def emit_struct_forward(ps: PythonStruct):
    if not ps.is_emitted:
        return

    if ps.has_from:
        emit(f"static PyObject *{ps.name}_from({ps.ir.name} *data, Context *ctx);")

def emit_pod_struct(ps: PythonStruct):
    if not ps.is_emitted_pod:
        return

    pyi_structs.add(ps.ir.name)

    # Struct declaration
    emit()
    emit_lines(f"""
        static PyObject *{ps.name}_Type;
    """)

    num_fields = len(ps.fields)

    # From
    emit()
    emit_lines(f"""
        static PyObject *{ps.name}_from(const {ps.ir.name} *v) {{
            PyObject *r = PyTuple_New({num_fields});
            if (!r) return NULL;
    """)
    indent()
    for ix, field in enumerate(ps.fields):
        field_irt = g_file.types[field.ir.type]
        expr = f"v->{field.name}"
        extra, top = to_pyobject(field_irt, expr, "")
        if extra:
            emit_lines(extra)
        emit(f"PyTuple_SetItem(r, {ix}, {top});")
    emit_lines(f"""
        PyObject *result = PyObject_CallObject({ps.name}_Type, r);
        Py_XDECREF(r);
        return result;
    """)
    unindent()
    emit("}")

    # To
    emit()
    emit_lines(f"""
        static {ps.ir.name} {ps.name}_to(PyObject *v) {{
            {ps.ir.name} r;
    """)
    indent()
    for ix, field in enumerate(ps.fields):
        field_irt = g_file.types[field.ir.type]
        expr = f"PyTuple_GetItem(v, {ix})"
        top = from_pyobject(field_irt, expr)
        emit(f"r.{field.name} = {top};")
    emit("return r;")
    unindent()
    emit("}")


def emit_struct(ps: PythonStruct):
    if not ps.is_emitted:
        return False

    module_types.append(ps.name)

    # Slot names
    slot_count = 0
    slot_count_name = f"SLOT_COUNT_{ps.upper}"
    if ps.fields:
        emit("")
        slot_count = len(ps.fields)
        emit(f"#define {slot_count_name} {slot_count}")
        emit("enum {")
        indent()
        for field in ps.fields:
            emit(f"{field.slot},")
        unindent()
        emit("};")

    # Struct declaration
    emit("")
    if ps.ir.is_element and ps.ir.name != "ufbx_element":
        emit_lines(f"""
            typedef struct {{
                union {{
                    Element elem;
                    struct {{
                        PyObject_HEAD
                        {ps.ir.name} *data;
                        Context *ctx;
                    }};
                }};
        """)
    else:
        emit_lines(f"""
            typedef struct {{
                PyObject_HEAD
                {ps.ir.name} *data;
                Context *ctx;
        """)
    indent()

    if slot_count > 0:
        emit(f"PyObject *slots[{slot_count_name}];")

    unindent()
    emit_lines(f"""
        }} {ps.name};
    """)

    # Field getters
    for pf in ps.fields:
        emit_getter(ps, pf)

    # Traverse
    emit()
    emit_lines(f"""
        static int {ps.name}_traverse({ps.name} *self, visitproc visit, void *arg) {{
    """)
    indent()

    if ps.ir.is_element:
        emit("if (Element_traverse((Element*)self, visit, arg) < 0) return -1;")
    else:
        emit("Py_VISIT(self->ctx);")

    if slot_count > 0:
        emit_lines(f"""
                for (size_t i = 0; i < {slot_count_name}; i++) {{
                    Py_VISIT(self->slots[i]);
                }}
        """)
    emit("return 0;")
    unindent()
    emit("}")

    # Clear
    emit()
    emit_lines(f"""
        static int {ps.name}_clear({ps.name} *self) {{
    """)
    indent()

    if ps.ir.is_element:
        emit("if (Element_clear((Element*)self) < 0) return -1;")
    else:
        emit("Py_CLEAR(self->ctx);")

    if slot_count > 0:
        emit_lines(f"""
                for (size_t i = 0; i < {slot_count_name}; i++) {{
                    Py_CLEAR(self->slots[i]);
                }}
        """)

    emit("return 0;")
    unindent()
    emit("}")

    # Dealloc
    emit()
    emit_lines(f"""
        void {ps.name}_dealloc({ps.name} *self) {{
            PyObject_GC_UnTrack(self);
            {ps.name}_clear(self);
            Py_TYPE(self)->tp_free((PyObject *) self);
        }}
    """)

    getset = None
    if ps.fields:
        emit("")
        slot_count = len(ps.fields)
        emit(f"static PyGetSetDef {ps.name}_getset[] = {{")
        indent()
        for pf in ps.fields:
            emit(f"{{ \"{pf.name}\", (getter){ps.name}_get_{pf.lower}, NULL, \"{pf.name}\" }},")
        emit("{ NULL },")
        unindent()
        emit("};")
        getset = f"{ps.name}_getset"

    flags = "Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC"
    if ps.ir.name == "ufbx_element":
        flags += "|Py_TPFLAGS_BASETYPE"

    # Member functions
    if ps.methods:
        emit()
        for member in ps.methods:
            pf = py_funcs[member.ir.func]
            if pf.input_type:
                emit(f"static PyObject *{ps.name}_{member.name}(PyObject *self, PyObject *args, PyObject *kwargs);")
            else:
                emit(f"static PyObject *{ps.name}_{member.name}(PyObject *self, PyObject *args);")

        emit()
        emit(f"static PyMethodDef {ps.name}_methods[] = {{")
        indent()
        for member in ps.methods:
            pf = py_funcs[member.ir.func]
            if pf.input_type:
                emit(f"{{ \"{member.name}\", (PyCFunction)&{ps.name}_{member.name}, METH_VARARGS|METH_KEYWORDS, NULL }},")
            else:
                emit(f"{{ \"{member.name}\", &{ps.name}_{member.name}, METH_VARARGS, NULL }},")
        emit(f"{{ NULL }},")
        unindent()
        emit("};")

    # Type declaration
    emit()
    emit_lines(f"""
    static PyTypeObject {ps.name}_Type = {{
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "ufbx.{ps.name}",
        .tp_doc = PyDoc_STR("{ps.name}"),
        .tp_basicsize = sizeof({ps.name}),
        .tp_itemsize = 0,
        .tp_flags = {flags},
        .tp_new = PyType_GenericNew,
        .tp_dealloc = (destructor)&{ps.name}_dealloc,
        .tp_traverse = (traverseproc)&{ps.name}_traverse,
        .tp_clear = (inquiry)&{ps.name}_clear,
    """)
    indent()

    if getset:
        emit(f".tp_getset = {getset},")

    if ps.ir.is_element:
        emit(f".tp_base = &Element_Type,")

    if ps.methods:
        emit(f".tp_methods = {ps.name}_methods,")

    unindent()
    emit("};")

    # Create helper
    if ps.has_from:
        emit()
        emit_lines(f"""
        static PyObject *{ps.name}_from({ps.ir.name} *data, Context *ctx) {{
            {ps.name} *obj = ({ps.name}*)PyObject_CallObject((PyObject*)&{ps.name}_Type, NULL);
            if (!obj) return NULL;
            obj->ctx = (Context*)Py_NewRef(ctx);
            obj->data = data;
            return (PyObject*)obj;
        }}
        """)

def emit_input_struct(ps: PythonStruct):
    if not ps.ir.is_input:
        return

    emit()
    emit(f"static int to_{ps.ir.short_name}({ps.ir.name} *dst, PyObject *src) {{")
    indent()

    emit_lines(f"""
        if (!src) return 0;
    """)

    has_any = any(from_pyobject(g_file.types[field.ir.type], "value") for field in ps.fields)

    if has_any:
        emit("PyObject *value;")

    for field in ps.fields:
        irt = g_file.types[field.ir.type]
        to_dst = from_pyobject(irt, "value")

        if to_dst:
            emit_lines(f"""
                value = PyDict_GetItemString(src, \"{field.name}\");
                if (value) {{
                    dst->{field.name} = {to_dst};
                    if (PyErr_Occurred()) return -1;
                }}
            """)

    emit("return 0;")
    unindent()
    emit("}")

def emit_element():
    emit()
    emit(f"static PyTypeObject *Element_typeof(ufbx_element_type type) {{")
    indent()

    emit("switch (type) {")
    indent()

    for typ in g_file.element_types:
        ps = py_structs.get(typ)
        if ps.ir.is_element and ps.ir.name != "ufbx_element":
            emit(f"case UFBX_ELEMENT_{ps.ir.short_name.upper()}: return &{ps.name}_Type;")
    emit("default: return NULL;")

    unindent()
    emit("}")

    unindent()
    emit("}")

    emit(f"static PyObject *Element_create(ufbx_element *elem, Context *ctx) {{")
    indent()

    emit_lines("""
        PyTypeObject *type = Element_typeof(elem->type);
        Element *obj = (Element*)PyObject_CallObject((PyObject*)type, NULL);
        if (!obj) return NULL;
        obj->ctx = (Context*)Py_NewRef(ctx);
        obj->data = elem;
        return (PyObject*)obj;
    """)

    unindent()
    emit("}")

class FunctionArgNotImplemented(NotImplementedError):
    pass

def func_arg(arg: ir.Argument) -> Optional[PythonArg]:
    name = arg.name
    if arg.kind == "stringPointer":
        return PythonArg(name, "str", "s#", f"&{name}, &{name}_len", f"{name}, (size_t){name}_len", f"""
            const char *{name};
            Py_ssize_t {name}_len;
        """)
    elif arg.kind == "stringLength":
        pass
    elif arg.kind == "arrayPointer":
        # TODO
        raise FunctionArgNotImplemented(f"{arg.kind}: {arg.type}")
    elif arg.kind == "arrayLength":
        pass
    elif arg.kind == "blobPointer":
        return PythonArg(name, "bytes", "z#", f"&{name}, &{name}_len", f"{name}, (size_t){name}_len", f"""
            const char *{name};
            Py_ssize_t {name}_len;
        """)
    elif arg.kind == "blobSize":
        pass
    elif arg.kind == "error":
        return PythonArg("", "", "", "", f"&error", f"""
            ufbx_error error;
        """, post=f"""
            if (error.type != UFBX_ERROR_NONE) {{
                return UfbxError_raise(&error);
            }}
        """)
    elif arg.kind == "panic":
        return PythonArg("", "", "", "", f"&panic", f"""
            ufbx_panic panic;
            panic.did_panic = false;
        """, post=f"""
            if (panic.did_panic) {{
                return Panic_raise(&panic);
            }}
        """)
    else:
        arg_type = g_file.types[arg.type]
        if arg_type.kind == "pointer":
            inner_type = g_file.types[arg_type.inner]
            if inner_type.kind == "struct":
                ps = py_structs[inner_type.key]
                if ps.ir.is_element or ps.name == "ufbx_element" or ps.is_emitted:
                    return PythonArg(name, ps.name, "O!", f"&{ps.name}_Type, &{name}", f"{name}->data", f"""
                        {ps.name} *{name};
                    """, ctx=f"{name}->ctx")
                elif ps.ir.is_input:
                    return PythonArg("", "", "", "", f"&{name}", f"""
                            {ps.ir.name} {name} = {{ 0 }};
                        """, input_type=ps.ir.name, input_name=name)
                elif ps.ir.is_pod:
                    pt = py_types[inner_type.key]
                    c_typ = pt.c_ufbx_name()
                    py_typ = pt.c_name()
                    obj_arg = f"{name}_obj"
                    return PythonArg(arg.name, py_typ, "O!", f"&{py_typ}_Type, &{name}_obj", f"&{name}", f"""
                            PyObject *{name}_obj;
                            {c_typ} {name};
                        """, pre=f"""
                            {name} = {py_typ}_to({obj_arg});
                        """)

            if inner_type.key in manual_to:
                py_typ, c_typ, to, cast = manual_to[inner_type.key]
                obj_arg = f"{name}_obj"
                return PythonArg(arg.name, py_typ, "O!", f"&{py_typ}_Type, &{name}_obj", f"&{name}", f"""
                        PyObject *{name}_obj;
                        {c_typ} {name};
                    """, pre=f"""
                        {name} = {to(obj_arg)};
                    """)

        if arg.type in primitive_fmt:
            typ = primitive_types[arg.type]
            fmt, ctyp, cast = primitive_fmt[arg.type]
            return PythonArg(arg.name, typ, fmt, f"&{name}", cast(name), f"""
                    {ctyp} {name};
                """)

        if arg.type in manual_to:
            py_typ, c_typ, to, cast = manual_to[arg.type]
            obj_arg = f"{name}_obj"
            return PythonArg(arg.name, py_typ, "O!", f"&{py_typ}_Type, &{name}_obj", cast(name), f"""
                    PyObject *{name}_obj;
                    {c_typ} {name};
                """, pre=f"""
                    {name} = {to(obj_arg)};
                """)

        if arg_type.kind == "enum":
            enum = g_file.enums[arg_type.key]
            pe = py_enums[arg_type.key]
            return PythonArg(arg.name, pe.name, "O!", f"&{pe.name}_Enum, &{name}", f"{name}", f"""
                    PyObject *{name}_obj;
                    {enum.name} {name};
                """, pre=f"""
                    {name} = {from_pyobject(arg_type, f"{name}_obj")};
                """)

        if arg_type.kind == "struct":
            ps = py_structs[arg_type.key]
            if ps.ir.is_pod:
                pt = py_types[arg_type.key]
                c_typ = pt.c_ufbx_name()
                py_typ = pt.c_name()
                obj_arg = f"{name}_obj"
                return PythonArg(arg.name, py_typ, "O!", f"&{py_typ}_Type, &{name}_obj", f"{name}", f"""
                        PyObject *{name}_obj;
                        {c_typ} {name};
                    """, pre=f"""
                        {name} = {py_typ}_to({obj_arg});
                    """)
            elif ps.ir.is_list:
                pt = py_types[arg_type.key]
                c_typ = pt.c_ufbx_name()
                py_typ = pt.c_name()
                obj_arg = f"{name}_obj"
                return PythonArg(arg.name, py_typ, "O!", f"&{py_typ}_Type, &{name}_obj", f"{name}_obj->data", f"""
                        {ps.name} *{name}_obj;
                    """)

        raise FunctionArgNotImplemented(f"{arg.kind}: {arg.type}")

def emit_func(pf: PythonFunc, method: Optional[PythonMethod] = None):
    if not pf.is_emitted: return

    args = pf.get_args(method)

    if not method:
        module_funcs.append(pf)

    ctx = None
    for arg in args:
        if arg.ctx:
            ctx = arg.ctx
            break

    name = f"mod_{pf.name}"
    if method:
        name = f"{method.struct.name}_{method.name}"

    emit()
    if pf.input_type:
        emit(f"static PyObject *{name}(PyObject *self, PyObject *args, PyObject *kwargs) {{")
    else:
        emit(f"static PyObject *{name}(PyObject *self, PyObject *args) {{")
    indent()

    fmt = ""
    ptr_list = []
    arg_list = []
    for arg in args:
        if arg.vars:
            emit_lines(arg.vars)
        fmt += arg.fmt
        ptr_list += [a.strip() for a in arg.ptr.split(",") if a.strip()]
        arg_list += [a.strip() for a in arg.arg.split(",") if a.strip()]

    if fmt:
        ptr_str = ", ".join(ptr_list)
        emit_lines(f"""
            if (!PyArg_ParseTuple(args, \"{fmt}\", {ptr_str})) {{
                return NULL;
            }}
        """)
    else:
        emit_lines(f"""
            if (!PyArg_ParseTuple(args, \"\")) {{
                return NULL;
            }}
        """)

    if ctx:
        emit_lines(f"""
            if (!{ctx}->ok) {{
                return Context_error({ctx});
            }}
        """)

    if pf.input_type:
        input_ps = py_structs[pf.input_type]
        emit_lines(f"""
            if (to_{input_ps.ir.short_name}(&{pf.input_name}, kwargs) < 0) {{
                return NULL;
            }}
        """)

    for arg in args:
        if arg.pre:
            emit_lines(arg.pre)

    ret_pt = None
    arg_str = ", ".join(arg_list)
    if pf.ir.return_type != "void":
        ret_pt = py_types[pf.ir.return_type]
        name = ret_pt.ir.key
        emit(f"{name} ret = {pf.ir.name}({arg_str});")
    else:
        emit(f"{pf.ir.name}({arg_str});")

    for arg in args:
        if arg.post:
            emit_lines(arg.post)

    if pf.ir.nullable_return:
        emit_lines(f"""
            if (!ret) {{
                return Py_NewRef(Py_None);
            }}
        """)

    if ret_pt:
        if pf.ir.alloc_type:
            create = create_funcs[pf.ir.alloc_type]
            emit_lines(f"""
                return {create}(ret);
            """)
        else:
            ret_extra, ret_ex = to_pyobject(ret_pt.ir, "ret", ctx)
            if ret_extra:
                emit_lines(ret_extra)
            emit_lines(f"""
                return {ret_ex};
            """)
    else:
        emit_lines(f"""
            return Py_NewRef(Py_None);
        """)

    unindent()
    emit("}")

def emit_module_types():

    # Enums types
    emit()
    emit("static ExternalType enum_types[] = {")
    indent()

    for pe in py_enums.values():
        emit(f"""{{ &{pe.name}_Enum, \"{pe.name}\" }},""")

    unindent()
    emit("};")

    # POD types
    emit()
    emit("static ExternalType pod_types[] = {")
    indent()

    for ps in py_structs.values():
        if ps.is_emitted_pod:
            emit(f"""{{ &{ps.name}_Type, \"{ps.name}\" }},""")

    unindent()
    emit("};")

    # Error types
    err_enum = g_file.enums["ufbx_error_type"]
    emit()
    emit("static ErrorType error_types[] = {")
    indent()
    for val_key in err_enum.values:
        if val_key == "UFBX_ERROR_NONE":
            emit("{ NULL },")
            continue
        value = g_file.enum_values[val_key]
        name = ir.to_pascal(value.short_name)
        name = f"{name}Error"
        emit(f"{{ \"ufbx.{name}\", \"{name}\" }},")
    unindent()
    emit("};")

    # Generated types
    emit()
    emit("static ModuleType generated_types[] = {")
    indent()

    for name in module_types:
        emit(f"{{ &{name}_Type, \"{name}\" }},")

    unindent()
    emit("};")

    # Methods
    emit()
    emit("static PyMethodDef mod_methods[] = {")
    indent()

    for pf in module_funcs:
        if pf.input_type:
            emit(f"{{ \"{pf.name}\", (PyCFunction)&mod_{pf.name}, METH_VARARGS|METH_KEYWORDS, NULL }},")
        else:
            emit(f"{{ \"{pf.name}\", &mod_{pf.name}, METH_VARARGS, NULL }},")
    emit(f"{{ NULL }},")

    unindent()
    emit("};")

def emit_gen_prefix():
    emit_lines("""
        from ._types import *
        from typing import NamedTuple
        from enum import IntEnum, IntFlag
    """)

def emit_gen_enum(pe: PythonEnum):
    base = "IntFlag" if pe.ir.flag else "IntEnum"

    emit()
    emit(f"class {pe.name}({base}):")
    indent()

    for value in pe.values:
        if pe.ir.flag:
            emit(f"{value.name} = 0x{value.ir.value:x}")
        else:
            emit(f"{value.name} = {value.ir.value}")

    unindent()

def emit_gen_pod_struct(ps: PythonStruct):
    if not ps.is_emitted_pod:
        return

    emit()
    emit_lines(f"""
        class {ps.name}(NamedTuple):
    """)
    indent()

    has_any = False
    if ps.fields:
        for pf in ps.fields:
            pt = py_types[pf.ir.type]
            emit_lines(f"""
                {pf.name}: {pt.pyi_name()}
            """)

        has_any = True

    if not has_any:
        emit("...")

    unindent()

def emit_gen_suffix():
    emit()
    emit_lines("""
        identity_transform = Transform(zero_vec3, identity_quat, Vec3(1, 1, 1))
        axes_right_handed_y_up = CoordinateAxes(CoordinateAxis.POSITIVE_X, CoordinateAxis.POSITIVE_Y, CoordinateAxis.POSITIVE_Z)
        axes_right_handed_z_up = CoordinateAxes(CoordinateAxis.POSITIVE_X, CoordinateAxis.POSITIVE_Z, CoordinateAxis.NEGATIVE_Y)
        axes_left_handed_y_up = CoordinateAxes(CoordinateAxis.POSITIVE_X, CoordinateAxis.POSITIVE_Y, CoordinateAxis.NEGATIVE_Z)
        axes_left_handed_z_up = CoordinateAxes(CoordinateAxis.POSITIVE_X, CoordinateAxis.POSITIVE_Z, CoordinateAxis.POSITIVE_Y)
    """)

def emit_pyi_prefix():
    emit_lines(f"""
        from typing import Any, Iterator, Optional, TypedDict, Tuple
        from typing_extensions import Unpack
        from ._generated import *
    """)

    emit()
    emit_lines(f"""
        class UfbxError(Exception):
            pass
    """)

    # Error types
    err_enum = g_file.enums["ufbx_error_type"]
    for val_key in err_enum.values:
        if val_key == "UFBX_ERROR_NONE":
            continue
        value = g_file.enum_values[val_key]
        name = ir.to_pascal(value.short_name)
        name = f"{name}Error"
        emit()
        emit_lines(f"""
            class {name}(UfbxError):
                pass
        """)

def emit_pyi_list(ps: PythonStruct):
    if not ps.ir.is_list:
        return
    if ps.ir.name in manual_types:
        return

    pyi_structs.add(ps.ir.name)

    data_field = ps.fields[0]
    ptr_type = py_types[data_field.ir.type]
    data_type = py_types[ptr_type.ir.inner]

    data_py = data_type.pyi_name()

    emit()
    emit(f"class {ps.name}:")
    indent()

    emit_lines(f"""
        def __len__(self) -> int: ...
        def __getitem__(self, index: int) -> {data_py}: ...
        def __iter__(self) -> Iterator[{data_py}]: ...
    """)

    unindent()

def emit_pyi_struct(ps: PythonStruct):
    if not ps.is_emitted:
        return

    pyi_structs.add(ps.ir.name)

    emit()
    emit(f"class {ps.name}:")
    indent()

    has_any = False
    if ps.fields:
        for pf in ps.fields:
            pt = py_types[pf.ir.type]
            emit_lines(f"""
                @property
                def {pf.name}(self) -> {pt.pyi_name()}: ...
            """)

        has_any = True

    for method in ps.methods:
        pf = py_funcs[method.ir.func]
        emit_pyi_func(pf, method=method)
        has_any = True

    if not has_any:
        emit("...")

    unindent()

def emit_pyi_input_struct(ps: PythonStruct):
    if not ps.ir.is_input:
        return

    pyi_structs.add(ps.ir.name)

    emit()
    emit(f"class {ps.name}(TypedDict, total=False):")
    indent()

    has_any = False
    for field in ps.fields:
        irt = g_file.types[field.ir.type]
        to_dst = from_pyobject(irt, "value")

        if to_dst:
            pyi_typ = py_types[field.ir.type].pyi_name()
            emit(f"{field.name}: {pyi_typ}")
            has_any = True

    if not has_any:
        emit("pass")

    unindent()

def emit_pyi_func(pf: PythonFunc, method: Optional[PythonMethod] = None):
    if not pf.is_emitted:
        return

    def format_args():
        args = pf.args[:]
        if method:
            del args[method.ir.self_index]
            yield "self"

        for arg in args:
            name = arg.name
            if not name:
                continue
            if name == "def":
                name = "default"
            yield f"{name}: {arg.typ}"
        if pf.input_type:
            ps = py_structs[pf.input_type]
            yield f"**kwargs: Unpack[{ps.name}]"

    ret_pt = None
    if pf.ir.return_type != "void":
        ret_pt = py_types[pf.ir.return_type]

    arg_str = ", ".join(format_args())
    ret_str = "None"

    if ret_pt:
        ret_str = ret_pt.pyi_name()

    if pf.ir.nullable_return:
        ret_str = f"Optional[{ret_str}]"

    name = pf.name
    if method:
        name = method.name

    emit()
    emit_lines(f"""
        def {name}({arg_str}) -> {ret_str}:
            ...
    """)

def main():
    global g_argv
    global g_file
    global g_outfile

    parser = argparse.ArgumentParser("generate_python.py")
    parser.add_argument("-i", help="Input ufbx_typed.json file")
    parser.add_argument("-o", help="Output path")
    argv = parser.parse_args()
    g_argv = argv

    src_path = os.path.dirname(os.path.realpath(__file__))

    input_file = argv.i
    if not input_file:
        input_file = os.path.join(src_path, "build", "ufbx_typed.json")

    output_path = argv.o
    if not output_path:
        output_path = os.path.join(src_path, "..", "ufbx")

    with open(input_file, "rt") as f:
        file = ir.from_json(ir.File, json.load(f))
        g_file = file

    if not os.path.exists(output_path):
        os.makedirs(output_path, exist_ok=True)

    with open(os.path.join(output_path, "generated.h"), "wt", encoding="utf-8") as f:
        g_outfile = f

        emit_prefix()

        for key, enum in file.enums.items():
            py_enums[key] = PythonEnum(enum)

        for key, struct in file.structs.items():
            py_structs[key] = PythonStruct(struct)

        for key, typ in file.types.items():
            py_types[key] = PythonType(typ)

        for key, func in file.functions.items():
            py_funcs[key] = PythonFunc(func)

        for ps in py_structs.values():
            ps.methods = [m for m in ps.methods if py_funcs[m.ir.func].is_emitted]

        emit()
        for pe in py_enums.values():
            emit_enum(pe)

        emit()
        for ps in py_structs.values():
            emit_pod_struct_forward(ps)

        emit()
        for ps in py_structs.values():
            emit_struct_forward(ps)

        emit_error_forward()

        for ps in py_structs.values():
            emit_list(ps)

        for ps in py_structs.values():
            emit_pod_struct(ps)

        for ps in py_structs.values():
            emit_struct(ps)

        for ps in py_structs.values():
            emit_input_struct(ps)

        for pf in py_funcs.values():
            emit_func(pf)

        for pf in py_structs.values():
            for method in pf.methods:
                pf = py_funcs[method.ir.func]
                emit_func(pf, method=method)

        emit_element()

        emit_module_types()

        emit()

    with open(os.path.join(output_path, "_generated.py"), "wt", encoding="utf-8") as f:
        g_outfile = f

        emit_gen_prefix()

        for pe in py_enums.values():
            emit_gen_enum(pe)

        for ps in py_structs.values():
            emit_gen_pod_struct(ps)

        emit_gen_suffix()

    with open(os.path.join(output_path, "_native.pyi"), "wt", encoding="utf-8") as f:
        g_outfile = f

        emit_pyi_prefix()

        for ps in py_structs.values():
            emit_pyi_list(ps)

        for ps in py_structs.values():
            emit_pyi_struct(ps)

        for ps in py_structs.values():
            emit_pyi_input_struct(ps)

        for pf in py_funcs.values():
            emit_pyi_func(pf)

if __name__ == "__main__":
    main()
