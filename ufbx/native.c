
#include "generated.h"

static PyObject* Scene_create(ufbx_scene *scene)
{
    Context *ctx = (Context*)PyObject_CallObject((PyObject*)&Context_Type, NULL);
    if (!ctx) {
        return NULL;
    }

    Scene *obj = (Scene*)PyObject_CallObject((PyObject*)&Scene_Type, NULL);
    if (!obj) {
        Py_DECREF(ctx);
        return NULL;
    }

    ctx->name = PyUnicode_FromString("scene");
    ctx->scene = scene;
    ctx->num_elements = scene->elements.count;
    ctx->elements = (PyObject**)calloc(ctx->num_elements, sizeof(PyObject*));
    ctx->ok = true;

    obj->ctx = ctx;
    obj->data = scene;
    return (PyObject*)obj;
}

static PyObject *UfbxError_raise(ufbx_error *error)
{
    PyObject *err_typ = error_type_objs[error->type];
    if (error->info_length > 0) {
        PyErr_Format(err_typ, "%s: %s", error->description.data, error->info);
    } else {
        PyErr_Format(err_typ, "%s", error->description.data);
    }
}

int register_errors(PyObject *m)
{
    for (size_t i = 0; i < array_count(error_types); i++) {
        ErrorType et = error_types[i];
        PyObject *obj = PyErr_NewException(et.mod_name, UfbxError, NULL);
        if (PyModule_AddObject(m, et.name, Py_NewRef(obj)) < 0) {
            return -1;
        }
        error_type_objs[i] = obj;
    }
    return 0;
}

static int ufbx_module_exec(PyObject *m)
{
    if (UfbxError != NULL) {
        PyErr_SetString(PyExc_ImportError,
                        "cannot initialize ufbx more than once");
        return -1;
    }

    UfbxError = PyErr_NewException("ufbx.UfbxError", NULL, NULL);
    if (PyModule_AddObject(m, "UfbxError", Py_NewRef(UfbxError)) < 0) {
        return -1;
    }

    for (size_t i = 0; i < array_count(prelude_types); i++) {
        register_type(m, prelude_types[i].type, prelude_types[i].name);
    }

    register_enums(m, enum_types, array_count(enum_types));

    for (size_t i = 0; i < array_count(generated_types); i++) {
        register_type(m, generated_types[i].type, generated_types[i].name);
    }

    register_pod_types(m);
    register_errors(m);

    return 0;
}

static PyModuleDef_Slot ufbx_module_slots[] = {
    {Py_mod_exec, ufbx_module_exec},
    {0, NULL}
};

static struct PyModuleDef ufbx_module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "ufbx",
    .m_size = 0,  // non-negative
    .m_slots = ufbx_module_slots,
    .m_methods = mod_methods,
};

PyMODINIT_FUNC
PyInit_ufbx(void)
{
    return PyModuleDef_Init(&ufbx_module);
}
