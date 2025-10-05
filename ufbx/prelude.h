#include "ufbx.h"

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#define array_count(arr) (sizeof(arr) / sizeof(*(arr)))

static PyObject *UfbxError = NULL;

#if PY_MINOR_VERSION < 10
static PyObject *_Py_NewRef(PyObject *obj)
{
	Py_XINCREF(obj);
	return obj;
}

#define Py_NewRef(obj) _Py_NewRef((PyObject*)(obj))
#endif

typedef struct {
	PyObject_HEAD
	bool ok;
	PyObject *name;

	ufbx_scene *scene;
	ufbx_anim *anim;

    size_t num_elements;
	PyObject **elements;
} Context;

static int Context_traverse(Context *self, visitproc visit, void *arg)
{
	Py_VISIT(self->name);
	for (size_t i = 0; i < self->num_elements; i++) {
		Py_VISIT(self->elements[i]);
	}
	return 0;
}

static int Context_clear(Context *self)
{
	Py_CLEAR(self->name);
	for (size_t i = 0; i < self->num_elements; i++) {
		Py_CLEAR(self->elements[i]);
	}
	return 0;
}

static void Context_dealloc(Context *self)
{
	Py_XDECREF(self->name);
	for (size_t i = 0; i < self->num_elements; i++) {
		Py_XDECREF(self->elements[i]);
	}

	ufbx_free_scene(self->scene);
	ufbx_free_anim(self->anim);

	free(self->elements);

	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyTypeObject Context_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Context",
    .tp_doc = PyDoc_STR("Context"),
    .tp_basicsize = sizeof(Context),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
	.tp_dealloc = (destructor)&Context_dealloc,
	.tp_traverse = (traverseproc)&Context_traverse,
	.tp_clear = (inquiry)&Context_clear,
};

static PyObject *Element_create(ufbx_element *elem, Context *ctx);

static PyObject *UfbxError_raise(ufbx_error *error);
static PyObject *Panic_raise(ufbx_panic *panic);

static PyObject *Context_error(Context *ctx)
{
	// TODO: Proper error type
	PyErr_Format(PyExc_RuntimeError, "context freed: %U", ctx->name);
	return NULL;
}

static PyTypeObject *Vec2_Type;
static PyTypeObject *Vec3_Type;
static PyTypeObject *Vec4_Type;
static PyTypeObject *Quat_Type;
static PyTypeObject *Transform_Type;

static PyObject* Vec2_from(const ufbx_vec2 *v)
{
	PyObject *r = PyStructSequence_New(Vec2_Type);
	if (!r) return NULL;
	PyStructSequence_SetItem(r, 0, PyFloat_FromDouble(v->x));
	PyStructSequence_SetItem(r, 1, PyFloat_FromDouble(v->y));
	return r;
}

static PyObject* Vec3_from(const ufbx_vec3 *v)
{
	PyObject *r = PyStructSequence_New(Vec3_Type);
	if (!r) return NULL;
	PyStructSequence_SetItem(r, 0, PyFloat_FromDouble(v->x));
	PyStructSequence_SetItem(r, 1, PyFloat_FromDouble(v->y));
	PyStructSequence_SetItem(r, 2, PyFloat_FromDouble(v->z));
	return r;
}

static PyObject* Vec4_from(const ufbx_vec4 *v)
{
	PyObject *r = PyStructSequence_New(Vec3_Type);
	if (!r) return NULL;
	PyStructSequence_SetItem(r, 0, PyFloat_FromDouble(v->x));
	PyStructSequence_SetItem(r, 1, PyFloat_FromDouble(v->y));
	PyStructSequence_SetItem(r, 2, PyFloat_FromDouble(v->z));
	PyStructSequence_SetItem(r, 3, PyFloat_FromDouble(v->w));
	return r;
}

static PyObject* Quat_from(const ufbx_quat *v)
{
	PyObject *r = PyStructSequence_New(Quat_Type);
	if (!r) return NULL;
	PyStructSequence_SetItem(r, 0, PyFloat_FromDouble(v->x));
	PyStructSequence_SetItem(r, 1, PyFloat_FromDouble(v->y));
	PyStructSequence_SetItem(r, 2, PyFloat_FromDouble(v->z));
	PyStructSequence_SetItem(r, 3, PyFloat_FromDouble(v->w));
	return r;
}

static PyObject* Transform_from(const ufbx_transform *v)
{
	PyObject *r = PyStructSequence_New(Transform_Type);
	if (!r) return NULL;
	PyStructSequence_SetItem(r, 0, Vec3_from(&v->translation));
	PyStructSequence_SetItem(r, 1, Quat_from(&v->rotation));
	PyStructSequence_SetItem(r, 2, Vec3_from(&v->scale));
	return r;
}

static PyObject* Matrix_from(const ufbx_matrix *v)
{
	PyObject *r = PyTuple_New(4);
	if (!r) return NULL;
	PyTuple_SetItem(r, 0, Vec3_from(&v->cols[0]));
	PyTuple_SetItem(r, 1, Vec3_from(&v->cols[1]));
	PyTuple_SetItem(r, 2, Vec3_from(&v->cols[2]));
	PyTuple_SetItem(r, 3, Vec3_from(&v->cols[3]));
	return r;
}

static ufbx_vec2 Vec2_to(PyObject *v)
{
	ufbx_vec2 r;
	r.x = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 0));
	r.y = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 1));
	return r;
}

static ufbx_vec3 Vec3_to(PyObject *v)
{
	ufbx_vec3 r;
	r.x = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 0));
	r.y = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 1));
	r.z = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 2));
	return r;
}

static ufbx_vec4 Vec4_to(PyObject *v)
{
	ufbx_vec4 r;
	r.x = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 0));
	r.y = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 1));
	r.z = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 2));
	r.w = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 3));
	return r;
}

static ufbx_quat Quat_to(PyObject *v)
{
	ufbx_quat r;
	r.x = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 0));
	r.y = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 1));
	r.z = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 2));
	r.w = (ufbx_real)PyFloat_AsDouble(PyStructSequence_GetItem(v, 3));
	return r;
}

static ufbx_transform Transform_to(PyObject *v)
{
	ufbx_transform r;
	r.translation = Vec3_to(PyStructSequence_GetItem(v, 0));
	r.rotation = Quat_to(PyStructSequence_GetItem(v, 1));
	r.scale = Vec3_to(PyStructSequence_GetItem(v, 2));
	return r;
}

static ufbx_matrix Matrix_to(PyObject *v)
{
	ufbx_matrix r;
	r.cols[0] = Vec3_to(PyTuple_GetItem(v, 0));
	r.cols[1] = Vec3_to(PyTuple_GetItem(v, 1));
	r.cols[2] = Vec3_to(PyTuple_GetItem(v, 2));
	r.cols[3] = Vec3_to(PyTuple_GetItem(v, 3));
	return r;
}

static PyObject* String_from(ufbx_string v)
{
    return PyUnicode_FromStringAndSize(v.data, (Py_ssize_t)v.length);
}

static PyObject* Blob_from(ufbx_blob v)
{
    return PyBytes_FromStringAndSize((const char *)v.data, (Py_ssize_t)v.size);
}

static PyObject* Element_from(void *p_elem, Context *ctx)
{
	if (!p_elem) return Py_NewRef(Py_None);
    if (!ctx->ok) return Context_error(ctx);

    ufbx_element *elem = (ufbx_element*)p_elem;
    PyObject **p_existing = &ctx->elements[elem->element_id];
    if (*p_existing) return *p_existing;

    PyObject *obj = Element_create(elem, ctx);
    *p_existing = obj;
    return obj;
}

static PyObject* Scene_create(ufbx_scene *scene);
static PyObject* Anim_create(ufbx_anim *anim);

static PyObject* to_pyobject_todo(const char *type)
{
    PyErr_Format(PyExc_NotImplementedError, "PyObject todo: %s", type);
    return NULL;
}

static PyObject* pyobject_todo(const char *message)
{
    PyErr_Format(PyExc_NotImplementedError, "todo: %s", message);
    return NULL;
}

typedef struct {
	int32_t value;
	const char *name;
} EnumValue;

typedef struct {
	PyObject **p_type;
	const char *name;
	const EnumValue *values;
	size_t num_values;
	bool is_flag;
} EnumType;

typedef struct {
	PyTypeObject *type;
	const char *name;
} ModuleType;

typedef struct {
	const char *mod_name;
	const char *name;
} ErrorType;

static ModuleType prelude_types[] = {
	{ &Context_Type, "Context" },
};

static bool register_type(PyObject *m, PyTypeObject *type, const char *name)
{
	if (PyType_Ready(type) < 0) {
		return false;
	}
	if (name) {
		if (PyModule_AddObject(m, name, Py_NewRef(type)) < 0) {
			return false;
		}
	}
	return true;
}

static void register_pod_types(PyObject *m)
{
	{
		PyStructSequence_Field fields[] = {
			{ "x", "X component" },
			{ "y", "Y component" },
			{ NULL },
		};
		PyStructSequence_Desc desc = {
			"ufbx.Vec2", "2-dimensional vector", fields, (int)array_count(fields) - 1,
		};
		Vec2_Type = PyStructSequence_NewType(&desc);
		register_type(m, Vec2_Type, "Vec2");
	}

	{
		PyStructSequence_Field fields[] = {
			{ "x", "X component" },
			{ "y", "Y component" },
			{ "z", "Z component" },
			{ NULL },
		};
		PyStructSequence_Desc desc = {
			"ufbx.Vec3", "3-dimensional vector", fields, (int)array_count(fields) - 1,
		};
		Vec3_Type = PyStructSequence_NewType(&desc);
		register_type(m, Vec3_Type, "Vec3");
	}

	{
		PyStructSequence_Field fields[] = {
			{ "x", "X component" },
			{ "y", "Y component" },
			{ "z", "Z component" },
			{ "w", "W component" },
			{ NULL },
		};
		PyStructSequence_Desc desc = {
			"ufbx.Vec4", "4-dimensional vector", fields, (int)array_count(fields) - 1,
		};
		Vec4_Type = PyStructSequence_NewType(&desc);
		register_type(m, Vec4_Type, "Vec4");
	}

	{
		PyStructSequence_Field fields[] = {
			{ "x", "X component" },
			{ "y", "Y component" },
			{ "z", "Z component" },
			{ "w", "W component" },
			{ NULL },
		};
		PyStructSequence_Desc desc = {
			"ufbx.Quat", "Quaternion", fields, (int)array_count(fields) - 1,
		};
		Quat_Type = PyStructSequence_NewType(&desc);
		register_type(m, Quat_Type, "Quat");
	}

	{
		PyStructSequence_Field fields[] = {
			{ "translation", "Translationj" },
			{ "rotation", "Rotation" },
			{ "scale", "Scale" },
			{ NULL },
		};
		PyStructSequence_Desc desc = {
			"ufbx.Transform", "Transform", fields, (int)array_count(fields) - 1,
		};
		Transform_Type = PyStructSequence_NewType(&desc);
		register_type(m, Transform_Type, "Transform");
	}

}

static bool register_enums(PyObject *m, const EnumType *enums, size_t num_enums)
{
	PyObject *enum_module = PyImport_ImportModule("enum");
	if (!enum_module) return false;

	for (size_t enum_ix = 0; enum_ix < num_enums; enum_ix++) {
		EnumType et = enums[enum_ix];
		const char *type = et.is_flag ? "IntFlag" : "IntEnum";

		PyObject* values = PyDict_New();
		for (size_t value_ix = 0; value_ix < et.num_values; value_ix++) {
			EnumValue ev = et.values[value_ix];
			PyDict_SetItemString(values, ev.name, PyLong_FromLong(ev.value));
		}

		PyObject *enum_obj = PyObject_CallMethod(enum_module, type, "sO", et.name, values);
		Py_XDECREF(values);

		*et.p_type = Py_NewRef(enum_obj);
		if (PyModule_AddObject(m, et.name, enum_obj) < 0) {
			return false;
		}
	}

	Py_DECREF(enum_module);
	return true;
}
