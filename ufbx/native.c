
#include "generated.h"

static PyObject *ufbx_load_scene(PyObject *self, PyObject *args)
{
    const char *path;
    Py_ssize_t path_len;
    if (!PyArg_ParseTuple(args, "s#", &path, &path_len)) return NULL;

    ufbx_error error;
    ufbx_scene *scene = ufbx_load_file_len(path, path_len, NULL, &error);
    if (!scene) {
        PyErr_Format(PyExc_RuntimeError, "Failed to load: %s", error.description.data);
        return NULL;
    }

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

static int ufbx_module_exec(PyObject *m)
{
    for (size_t i = 0; i < array_count(prelude_types); i++) {
        register_type(m, prelude_types[i].type, prelude_types[i].name);
    }

    for (size_t i = 0; i < array_count(generated_types); i++) {
        register_type(m, generated_types[i].type, generated_types[i].name);
    }

    register_pod_types(m);

    return 0;
}

static PyModuleDef_Slot ufbx_module_slots[] = {
    {Py_mod_exec, ufbx_module_exec},
    {0, NULL}
};

static PyMethodDef ufbx_methods[] = {
    { "load_scene", &ufbx_load_scene, METH_VARARGS, "Load scene"},
    { NULL },
};

static struct PyModuleDef ufbx_module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "ufbx",
    .m_size = 0,  // non-negative
    .m_slots = ufbx_module_slots,
    .m_methods = ufbx_methods,
};

PyMODINIT_FUNC
PyInit_ufbx(void)
{
    return PyModuleDef_Init(&ufbx_module);
}
