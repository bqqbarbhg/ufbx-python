
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

    ctx->name = PyUnicode_FromString("Scene");
    ctx->scene = scene;
    ctx->num_elements = scene->elements.count;
    ctx->elements = (PyObject**)calloc(ctx->num_elements, sizeof(PyObject*));
    ctx->ok = true;

    obj->ctx = ctx;
    obj->data = scene;
    return (PyObject*)obj;
}

static PyObject* Anim_create(ufbx_anim *anim)
{
    Context *ctx = (Context*)PyObject_CallObject((PyObject*)&Context_Type, NULL);
    if (!ctx) {
        return NULL;
    }

    Anim *obj = (Anim*)PyObject_CallObject((PyObject*)&Anim_Type, NULL);
    if (!obj) {
        Py_DECREF(ctx);
        return NULL;
    }

    ctx->name = PyUnicode_FromString("Anim");
    ctx->anim = anim;
    ctx->ok = true;

    obj->ctx = ctx;
    obj->data = anim;
    return (PyObject*)obj;
}

static PyObject* BakedAnim_create(ufbx_baked_anim *baked)
{
    Context *ctx = (Context*)PyObject_CallObject((PyObject*)&Context_Type, NULL);
    if (!ctx) {
        return NULL;
    }

    BakedAnim *obj = (BakedAnim*)PyObject_CallObject((PyObject*)&BakedAnim_Type, NULL);
    if (!obj) {
        Py_DECREF(ctx);
        return NULL;
    }

    ctx->name = PyUnicode_FromString("BakedAnim");
    ctx->baked = baked;
    ctx->ok = true;

    obj->ctx = ctx;
    obj->data = baked;
    return (PyObject*)obj;
}

static PyObject* GeometryCache_create(ufbx_geometry_cache *cache)
{
    Context *ctx = (Context*)PyObject_CallObject((PyObject*)&Context_Type, NULL);
    if (!ctx) {
        return NULL;
    }

    GeometryCache *obj = (GeometryCache*)PyObject_CallObject((PyObject*)&GeometryCache_Type, NULL);
    if (!obj) {
        Py_DECREF(ctx);
        return NULL;
    }

    ctx->name = PyUnicode_FromString("GeometryCache");
    ctx->cache = cache;
    ctx->ok = true;

    obj->ctx = ctx;
    obj->data = cache;
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
    return NULL;
}

static PyObject *Panic_raise(ufbx_panic *panic)
{
    PyErr_Format(PyExc_RuntimeError, "%s", panic->message);
    return NULL;
}

int register_errors(PyObject *m)
{
    for (size_t i = 0; i < array_count(error_types); i++) {
        ErrorType et = error_types[i];
        if (!et.name) continue;

        PyObject *obj = PyErr_NewException(et.mod_name, UfbxError, NULL);
        if (PyModule_AddObject(m, et.name, Py_NewRef(obj)) < 0) {
            return -1;
        }
        error_type_objs[i] = obj;
    }
    return 0;
}

#ifndef GENERATED_IMPORT_LEVEL
#define GENERATED_IMPORT_LEVEL 1
#endif GENERATED_IMPORT_LEVEL

static int load_types(PyObject *m)
{
    PyObject *globals = PyModule_GetDict(m);
    if (!globals) return -1;

    PyObject *mod_types = PyImport_ImportModuleLevel("_generated", globals, NULL, NULL, GENERATED_IMPORT_LEVEL);
    PyErr_Print();
    if (!mod_types) return -1;


    load_external_types(mod_types, prelude_ext_types, array_count(prelude_ext_types));
    load_external_types(mod_types, enum_types, array_count(enum_types));
    load_external_types(mod_types, pod_types, array_count(pod_types));

    Py_XDECREF(mod_types);

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

    UseAfterFreeError = PyErr_NewException("ufbx.UseAfterFreeError", NULL, NULL);
    if (PyModule_AddObject(m, "UseAfterFreeError", Py_NewRef(UseAfterFreeError)) < 0) {
        return -1;
    }

    BufferReferenceError = PyErr_NewException("ufbx.BufferReferenceError", NULL, NULL);
    if (PyModule_AddObject(m, "BufferReferenceError", Py_NewRef(BufferReferenceError)) < 0) {
        return -1;
    }

    for (size_t i = 0; i < array_count(prelude_types); i++) {
        register_type(m, prelude_types[i].type, prelude_types[i].name);
    }

    for (size_t i = 0; i < array_count(generated_types); i++) {
        register_type(m, generated_types[i].type, generated_types[i].name);
    }

    register_errors(m);
    load_types(m);

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

#ifndef MODULE_NAME
#define MODULE_NAME PyInit__native
#endif

PyMODINIT_FUNC MODULE_NAME(void)
{
    return PyModuleDef_Init(&ufbx_module);
}
