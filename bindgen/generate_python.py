import os
import argparse
import ufbx_ir as ir
import json
import re
from collections import namedtuple

g_file: ir.File = None
g_outfile = None
g_indent = 0

py_types: dict[str, "PythonType"] = { }
py_structs: dict[str, "PythonStruct"] = { }

module_types = []

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
    emit()

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

class PythonType:
    def __init__(self, ir_type: ir.Type):
        self.ir = ir_type

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

        for field in self.ir.fields:
            if not field.private and field.name:
                self.fields.append(PythonField(self, field))

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
}

pod_types = {
    "ufbx_vec2": "Vec2",
    "ufbx_vec3": "Vec3",
    "ufbx_vec4": "Vec4",
    "ufbx_quat": "Quat",
    "ufbx_transform": "Transform",
}

manual_types = { "ufbx_string", "ufbx_blob" }

pyobject_primtive = {
    "void": lambda _: "Py_None",
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
    "bool": lambda v: f"{v} ? Py_True : Py_False",
    "ufbx_real": lambda v: f"PyFloat_FromDouble({v})",
}

pyobject_manual = {
    "ufbx_vec2": lambda v: f"Vec2_from(&{v})",
    "ufbx_vec3": lambda v: f"Vec3_from(&{v})",
    "ufbx_vec4": lambda v: f"Vec4_from(&{v})",
    "ufbx_quat": lambda v: f"Quat_from(&{v})",
    "ufbx_transform": lambda v: f"Transform_from(&{v})",
    "ufbx_string": lambda v: f"String_from({v})",
    "ufbx_blob": lambda v: f"Blob_from({v})",
}

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

    return f"to_pyobject_todo(\"{irt.key}\")"

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
        static PyObject *{name}_subscript({name} *self, PyObject *key) {{
            if (!self->ctx->ok) return Context_error(self->ctx);
            if (PyLong_Check(key)) {{
                size_t count = self->data.count;
                Py_ssize_t index = PyLong_AsSsize_t(key);
                if (index == -1 && PyErr_Occurred()) return NULL;
                if (index < 0) index += (Py_ssize_t)count;
                if (index < 0 || (size_t)index >= count) {{
                    PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
                    return NULL;
                }}
                return {get_expr};
            }} else if (PySlice_Check(key)) {{
                return pyobject_todo("todo: slicing");
            }} else {{
                PyErr_SetString(PyExc_TypeError, "expected integer or slice");
                return NULL;
            }}
        }}
    """)

    # Type declaration
    emit()
    emit_lines(f"""
    static PyMappingMethods {ps.name}_Mapping = {{
        .mp_length = (lenfunc)&{name}_len,
        .mp_subscript = (binaryfunc)&{name}_subscript,
    }};

    static PyTypeObject {ps.name}_Type = {{
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "ufbx.{ps.name}",
        .tp_doc = PyDoc_STR("{ps.name}"),
        .tp_basicsize = sizeof({ps.name}),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT,
        .tp_new = PyType_GenericNew,
        .tp_as_mapping = &{ps.name}_Mapping,
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

def emit_struct(ps: PythonStruct):
    if ps.ir.is_pod or ps.ir.is_anonymous or ps.ir.is_list or ps.ir.is_input or ps.ir.is_callback or ps.ir.is_interface:
        return
    if ps.ir.name in manual_types:
        return

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

    # Type declaration
    emit()
    emit_lines(f"""
    static PyTypeObject {ps.name}_Type = {{
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "ufbx.{ps.name}",
        .tp_doc = PyDoc_STR("{ps.name}"),
        .tp_basicsize = sizeof({ps.name}),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT,
        .tp_new = PyType_GenericNew,
    """)
    indent()

    if getset:
        emit(f".tp_getset = {getset},")

    if ps.ir.is_element:
        emit(f".tp_base = &Element_Type,")

    unindent()
    emit("};")

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

def emit_module_types():
    emit()
    emit("static ModuleType generated_types[] = {")
    indent()

    for name in module_types:
        emit(f"{{ &{name}_Type, \"{name}\" }},")

    unindent()
    emit("};")

if __name__ == "__main__":

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

        for key, struct in file.structs.items():
            py_structs[key] = PythonStruct(struct)

        for key, typ in file.types.items():
            py_types[key] = PythonType(typ)

        for struct in file.structs.values():
            ps = PythonStruct(struct)
            emit_list(ps)

        for struct in file.structs.values():
            ps = PythonStruct(struct)
            emit_struct(ps)

        emit_element()

        emit_module_types()

        emit()
