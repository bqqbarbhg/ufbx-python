import os
import argparse
import ufbx_ir as ir
import json
import re
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
class PyhtonArg:
    name: str
    typ: str
    fmt: str
    ptr: str
    arg: str
    vars: str
    ctx: Optional[str] = None
    post: Optional[str] = None
    input_type: Optional[str] = None

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
    "ufbx_transform": "Transform",
    "ufbx_matrix": "Matrix",
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

        inner = self.ir
        while inner.inner:
            inner = g_file.types[inner.inner]

        if inner.kind == "struct":
            ps = py_structs[inner.key]
            if ps.is_emitted or ps.ir.is_list:
                if inner.key in pyi_structs:
                    return ps.name
                else:
                    return f"\"{ps.name}\""

        return "Any"

    def c_name(self) -> str:
        c_name = c_types.get(self.ir.key)
        if c_name:
            return c_name

        if self.ir.kind == "struct":
            return py_structs[self.ir.key].name
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

        do_from = True
        if not do_emit:
            do_from = False
        if self.ir.name == "ufbx_element":
            do_from = False
        if self.ir.is_element:
            do_from = False
        self.has_from = do_from

        for field in self.ir.fields:
            if not field.private and field.name:
                self.fields.append(PythonField(self, field))

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

        args = []
        try:
            args = [func_arg(arg) for arg in self.ir.arguments]
        except FunctionArgNotImplemented:
            # TODO
            self.is_emitted = False
        args = [arg for arg in args if arg]
        self.args = args

        for arg in args:
            if arg.input_type:
                assert not input_type
                input_type = arg.input_type
        self.input_type = input_type

manual_types = { "ufbx_string", "ufbx_blob" }

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

pyobject_manual = {
    "ufbx_vec2": lambda v: f"Vec2_from(&{v})",
    "ufbx_vec3": lambda v: f"Vec3_from(&{v})",
    "ufbx_vec4": lambda v: f"Vec4_from(&{v})",
    "ufbx_quat": lambda v: f"Quat_from(&{v})",
    "ufbx_transform": lambda v: f"Transform_from(&{v})",
    "ufbx_matrix": lambda v: f"Matrix_from(&{v})",
    "ufbx_string": lambda v: f"String_from({v})",
    "ufbx_blob": lambda v: f"Blob_from({v})",
}

return_manual = {
    "ufbx_scene*": lambda v: f"Scene_create({v})",
}

unsupported_funcs = {
    "ufbx_inflate",
}

def cbool(b):
    return "true" if b else "false"

def to_pyobject(irt: ir.Type, expr: str, ctx: str):
    prim = pyobject_primtive.get(irt.key)
    if prim:
        return prim(expr)

    pod = pyobject_manual.get(irt.key)
    if pod:
        return pod(expr)

    if irt.kind == "pointer":
        inner = g_file.types[irt.inner]
        if inner.kind == "struct":
            ist = g_file.structs[inner.key]
            if ist.is_element:
                return f"Element_from({expr}, {ctx})"
    elif irt.kind == "struct":
        irs = g_file.structs[irt.key]
        if irs.is_list:
            ps = py_structs[irs.name]
            return f"{ps.name}_from({expr}, {ctx})"

        ps = py_structs.get(irs.name)
        if ps and ps.has_from:
            return f"{ps.name}_from(&{expr}, {ctx})"
    elif irt.kind == "enum":
        pe = py_enums[irt.key]
        return f"PyObject_CallFunction({pe.name}_Enum, \"i\", (int){expr})"

    return f"to_pyobject_todo(\"{irt.key}\")"

def emit_error_forward():
    err_enum = g_file.enums["ufbx_error_type"]
    emit()
    emit(f"static PyObject *error_type_objs[{len(err_enum.values)}];")

def emit_getter(ps: PythonStruct, pf: PythonField):
    emit()
    emit(f"static PyObject *{ps.name}_get_{pf.lower}({ps.name} *self, void *closure) {{")
    indent()

    field_type = g_file.types[pf.ir.type]
    value = to_pyobject(field_type, f"self->data->{pf.ir.name}", "self->ctx")

    emit_lines(f"""
        PyObject *slot = self->slots[{pf.slot}];
        if (slot) return Py_NewRef(slot);
        if (!self->ctx->ok) return Context_error(self->ctx);
        slot = {value};
        self->slots[{pf.slot}] = slot;
        return Py_NewRef(slot);
    """)

    unindent()
    emit("}")

def emit_enum(pe: PythonEnum):
    emit()
    emit(f"static PyObject *{pe.name}_Enum;")
    emit(f"static const EnumValue {pe.name}_values[] = {{")
    indent()
    for pv in pe.values:
        emit(f"{{ {pv.ir.name}, \"{pv.name}\" }},")
    unindent()
    emit("};")

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
            PyObject *count;
            {ps.ir.name} data;
        }} {name};
    """)

    # Mapping
    emit()
    emit_lines(f"""
        static PyObject *{name}_len({name} *self, PyObject *key) {{
            return Py_NewRef(self->count);
        }}
    """)

    # Getter
    get_arg = "self->data.data[index]"
    get_expr = to_pyobject(data_type.ir, get_arg, "self->ctx")
    emit()
    emit_lines(f"""
        static PyObject *{name}_item({name} *self, Py_ssize_t index) {{
            if (!self->ctx->ok) return Context_error(self->ctx);
            size_t count = self->data.count;
            if (index < 0 || (size_t)index >= count) {{
                PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
                return NULL;
            }}
            return {get_expr};
        }}
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
        .tp_flags = Py_TPFLAGS_DEFAULT,
        .tp_new = PyType_GenericNew,
        .tp_as_sequence = &{ps.name}_Sequence,
    }};
    """)

    # Create helper
    emit()
    emit_lines(f"""
    static PyObject *{ps.name}_from({ps.ir.name} list, Context *ctx) {{
        {ps.name} *obj = ({ps.name}*)PyObject_CallObject((PyObject*)&{ps.name}_Type, NULL);
        if (!obj) return NULL;
        obj->ctx = (Context*)Py_NewRef(ctx);
        obj->count = PyLong_FromSize_t(list.count);
        obj->data = list;
        return (PyObject*)obj;
    }}
    """)

def emit_struct_forward(ps: PythonStruct):
    if not ps.is_emitted:
        return False

    if ps.has_from:
        emit(f"static PyObject *{ps.name}_from({ps.ir.name} *data, Context *ctx);")

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

def func_arg(arg: ir.Argument) -> Optional[PyhtonArg]:
    name = arg.name
    if arg.kind == "stringPointer":
        return PyhtonArg(name, "str", "s#", f"&{name}, &{name}_len", f"{name}, (size_t){name}_len", f"""
            const char *{name};
            Py_ssize_t {name}_len;
        """)
    elif arg.kind == "stringLength":
        pass
    elif arg.kind == "arrayPointer":
        # TODO
        raise FunctionArgNotImplemented()
    elif arg.kind == "arrayLength":
        pass
    elif arg.kind == "blobPointer":
        return PyhtonArg(name, "bytes", "z#", f"&{name}, &{name}_len", f"{name}, (size_t){name}_len", f"""
            const char *{name};
            Py_ssize_t {name}_len;
        """)
    elif arg.kind == "blobSize":
        pass
    elif arg.kind == "error":
        # TODO
        return PyhtonArg("", "", "", "", f"&error", f"""
            ufbx_error error;
        """, post=f"""
            if (error.type != UFBX_ERROR_NONE) {{
                return UfbxError_raise(&error);
            }}
        """)
    elif arg.kind == "panic":
        pass
    else:
        arg_type = g_file.types[arg.type]
        if arg_type.kind == "pointer":
            inner_type = g_file.types[arg_type.inner]
            if inner_type.kind == "struct":
                ps = py_structs[inner_type.key]
                if ps.ir.is_element or ps.name == "ufbx_element" or ps.is_emitted:
                    return PyhtonArg(name, ps.name, "O!", f"&{ps.name}_Type, &{name}", f"{name}->data", f"""
                        {ps.name} *{name};
                    """, ctx=f"{name}->ctx")
                elif ps.ir.is_input:
                    return PyhtonArg("", "", "", "", f"&{name}", f"""
                            {ps.ir.name} {name} = {{ 0 }};
                        """, input_type=ps.ir.name)

        raise FunctionArgNotImplemented()

def emit_func(pf: PythonFunc):
    if not pf.is_emitted: return

    args = pf.args

    module_funcs.append(pf)

    ctx = None
    for arg in args:
        if arg.ctx:
            ctx = arg.ctx
            break

    emit()
    if pf.input_type:
        emit(f"static PyObject *mod_{pf.name}(PyObject *self, PyObject *args, PyObject *kwargs) {{")
    else:
        emit(f"static PyObject *mod_{pf.name}(PyObject *self, PyObject *args) {{")
    indent()

    fmt = ""
    ptr_list = []
    arg_list = []
    for arg in args:
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
        manual = return_manual.get(ret_pt.ir.key)
        if manual:
            ret_ex = manual("ret")
            emit_lines(f"""
                return {ret_ex};
            """)
        else:
            ret_ex = to_pyobject(ret_pt.ir, "ret", ctx)
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
    emit("static EnumType enum_types[] = {")
    indent()

    for pe in py_enums.values():
        emit(f"""{{ &{pe.name}_Enum, \"{pe.name}\", {pe.name}_values, array_count({pe.name}_values), {cbool(pe.ir.flag)} }},""")

    unindent()
    emit("};")

    # Error types
    err_enum = g_file.enums["ufbx_error_type"]
    emit()
    emit("static ErrorType error_types[] = {")
    indent()
    for val_key in err_enum.values:
        if val_key == "UFBX_ERROR_NONE":
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

def emit_pyi_prefix():
    emit_lines(f"""
        from typing import Any, Union, Iterator, Tuple, NamedTuple, Optional
    """)

    emit()
    emit_lines(f"""
        class Vec2(NamedTuple):
            x: float
            y: float

        class Vec3(NamedTuple):
            x: float
            y: float
            z: float

        class Vec4(NamedTuple):
            x: float
            y: float
            z: float
            w: float

        class Quat(NamedTuple):
            x: float
            y: float
            z: float
            w: float

        class Transform(NamedTuple):
            translation: Vec3
            rotation: Quat
            scale: Vec3

        Matrix = Tuple[Vec3, Vec3, Vec3, Vec3]
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

    if not has_any:
        emit("...")

    unindent()

def emit_pyi_func(pf: PythonFunc):
    if not pf.is_emitted:
        return

    def format_args():
        for arg in pf.args:
            if not arg.name:
                continue
            yield f"{arg.name}: {arg.typ}"

    ret_pt = None
    if pf.ir.return_type != "void":
        ret_pt = py_types[pf.ir.return_type]

    arg_str = ", ".join(format_args())
    ret_str = "None"

    if ret_pt:
        ret_str = ret_pt.pyi_name()

    if pf.ir.nullable_return:
        ret_str = f"Optional[{ret_str}]"

    emit()
    emit_lines(f"""
        def {pf.name}({arg_str}) -> {ret_str}:
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

        for pe in py_enums.values():
            emit_enum(pe)

        emit()
        for ps in py_structs.values():
            emit_struct_forward(ps)

        emit_error_forward()

        for ps in py_structs.values():
            emit_list(ps)

        for ps in py_structs.values():
            emit_struct(ps)

        for pf in py_funcs.values():
            emit_func(pf)

        emit_element()

        emit_module_types()

        emit()

    with open(os.path.join(output_path, "ufbx.pyi"), "wt", encoding="utf-8") as f:
        g_outfile = f

        emit_pyi_prefix()

        for ps in py_structs.values():
            emit_pyi_list(ps)

        for ps in py_structs.values():
            emit_pyi_struct(ps)

        for pf in py_funcs.values():
            emit_pyi_func(pf)

if __name__ == "__main__":
    main()
