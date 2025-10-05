#include "prelude.h"


typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_bool_list data;
} BoolList;

static PyObject *BoolList_len(BoolList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BoolList_subscript(BoolList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return self->data.data[index] ? Py_True : Py_False;
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BoolList_Mapping = {
    .mp_length = (lenfunc)&BoolList_len,
    .mp_subscript = (binaryfunc)&BoolList_subscript,
};

static PyTypeObject BoolList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BoolList",
    .tp_doc = PyDoc_STR("BoolList"),
    .tp_basicsize = sizeof(BoolList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BoolList_Mapping,
};

static PyObject *BoolList_from(ufbx_bool_list list, Context *ctx) {
    BoolList *obj = (BoolList*)PyObject_CallObject((PyObject*)&BoolList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_uint32_list data;
} Uint32List;

static PyObject *Uint32List_len(Uint32List *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *Uint32List_subscript(Uint32List *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return PyLong_FromUnsignedLong((unsigned long)self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods Uint32List_Mapping = {
    .mp_length = (lenfunc)&Uint32List_len,
    .mp_subscript = (binaryfunc)&Uint32List_subscript,
};

static PyTypeObject Uint32List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Uint32List",
    .tp_doc = PyDoc_STR("Uint32List"),
    .tp_basicsize = sizeof(Uint32List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &Uint32List_Mapping,
};

static PyObject *Uint32List_from(ufbx_uint32_list list, Context *ctx) {
    Uint32List *obj = (Uint32List*)PyObject_CallObject((PyObject*)&Uint32List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_real_list data;
} RealList;

static PyObject *RealList_len(RealList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *RealList_subscript(RealList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return PyFloat_FromDouble(self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods RealList_Mapping = {
    .mp_length = (lenfunc)&RealList_len,
    .mp_subscript = (binaryfunc)&RealList_subscript,
};

static PyTypeObject RealList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.RealList",
    .tp_doc = PyDoc_STR("RealList"),
    .tp_basicsize = sizeof(RealList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &RealList_Mapping,
};

static PyObject *RealList_from(ufbx_real_list list, Context *ctx) {
    RealList *obj = (RealList*)PyObject_CallObject((PyObject*)&RealList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_vec2_list data;
} Vec2List;

static PyObject *Vec2List_len(Vec2List *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *Vec2List_subscript(Vec2List *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Vec2_from(&self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods Vec2List_Mapping = {
    .mp_length = (lenfunc)&Vec2List_len,
    .mp_subscript = (binaryfunc)&Vec2List_subscript,
};

static PyTypeObject Vec2List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Vec2List",
    .tp_doc = PyDoc_STR("Vec2List"),
    .tp_basicsize = sizeof(Vec2List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &Vec2List_Mapping,
};

static PyObject *Vec2List_from(ufbx_vec2_list list, Context *ctx) {
    Vec2List *obj = (Vec2List*)PyObject_CallObject((PyObject*)&Vec2List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_vec3_list data;
} Vec3List;

static PyObject *Vec3List_len(Vec3List *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *Vec3List_subscript(Vec3List *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Vec3_from(&self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods Vec3List_Mapping = {
    .mp_length = (lenfunc)&Vec3List_len,
    .mp_subscript = (binaryfunc)&Vec3List_subscript,
};

static PyTypeObject Vec3List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Vec3List",
    .tp_doc = PyDoc_STR("Vec3List"),
    .tp_basicsize = sizeof(Vec3List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &Vec3List_Mapping,
};

static PyObject *Vec3List_from(ufbx_vec3_list list, Context *ctx) {
    Vec3List *obj = (Vec3List*)PyObject_CallObject((PyObject*)&Vec3List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_vec4_list data;
} Vec4List;

static PyObject *Vec4List_len(Vec4List *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *Vec4List_subscript(Vec4List *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Vec4_from(&self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods Vec4List_Mapping = {
    .mp_length = (lenfunc)&Vec4List_len,
    .mp_subscript = (binaryfunc)&Vec4List_subscript,
};

static PyTypeObject Vec4List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Vec4List",
    .tp_doc = PyDoc_STR("Vec4List"),
    .tp_basicsize = sizeof(Vec4List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &Vec4List_Mapping,
};

static PyObject *Vec4List_from(ufbx_vec4_list list, Context *ctx) {
    Vec4List *obj = (Vec4List*)PyObject_CallObject((PyObject*)&Vec4List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_string_list data;
} StringList;

static PyObject *StringList_len(StringList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *StringList_subscript(StringList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return String_from(self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods StringList_Mapping = {
    .mp_length = (lenfunc)&StringList_len,
    .mp_subscript = (binaryfunc)&StringList_subscript,
};

static PyTypeObject StringList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.StringList",
    .tp_doc = PyDoc_STR("StringList"),
    .tp_basicsize = sizeof(StringList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &StringList_Mapping,
};

static PyObject *StringList_from(ufbx_string_list list, Context *ctx) {
    StringList *obj = (StringList*)PyObject_CallObject((PyObject*)&StringList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_int32_list data;
} Int32List;

static PyObject *Int32List_len(Int32List *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *Int32List_subscript(Int32List *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return PyLong_FromLong((long)self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods Int32List_Mapping = {
    .mp_length = (lenfunc)&Int32List_len,
    .mp_subscript = (binaryfunc)&Int32List_subscript,
};

static PyTypeObject Int32List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Int32List",
    .tp_doc = PyDoc_STR("Int32List"),
    .tp_basicsize = sizeof(Int32List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &Int32List_Mapping,
};

static PyObject *Int32List_from(ufbx_int32_list list, Context *ctx) {
    Int32List *obj = (Int32List*)PyObject_CallObject((PyObject*)&Int32List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_int64_list data;
} Int64List;

static PyObject *Int64List_len(Int64List *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *Int64List_subscript(Int64List *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return PyLong_FromLongLong((long long)self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods Int64List_Mapping = {
    .mp_length = (lenfunc)&Int64List_len,
    .mp_subscript = (binaryfunc)&Int64List_subscript,
};

static PyTypeObject Int64List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Int64List",
    .tp_doc = PyDoc_STR("Int64List"),
    .tp_basicsize = sizeof(Int64List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &Int64List_Mapping,
};

static PyObject *Int64List_from(ufbx_int64_list list, Context *ctx) {
    Int64List *obj = (Int64List*)PyObject_CallObject((PyObject*)&Int64List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_float_list data;
} FloatList;

static PyObject *FloatList_len(FloatList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *FloatList_subscript(FloatList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return PyFloat_FromDouble(self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods FloatList_Mapping = {
    .mp_length = (lenfunc)&FloatList_len,
    .mp_subscript = (binaryfunc)&FloatList_subscript,
};

static PyTypeObject FloatList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.FloatList",
    .tp_doc = PyDoc_STR("FloatList"),
    .tp_basicsize = sizeof(FloatList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &FloatList_Mapping,
};

static PyObject *FloatList_from(ufbx_float_list list, Context *ctx) {
    FloatList *obj = (FloatList*)PyObject_CallObject((PyObject*)&FloatList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_double_list data;
} DoubleList;

static PyObject *DoubleList_len(DoubleList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *DoubleList_subscript(DoubleList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return PyFloat_FromDouble(self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods DoubleList_Mapping = {
    .mp_length = (lenfunc)&DoubleList_len,
    .mp_subscript = (binaryfunc)&DoubleList_subscript,
};

static PyTypeObject DoubleList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DoubleList",
    .tp_doc = PyDoc_STR("DoubleList"),
    .tp_basicsize = sizeof(DoubleList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &DoubleList_Mapping,
};

static PyObject *DoubleList_from(ufbx_double_list list, Context *ctx) {
    DoubleList *obj = (DoubleList*)PyObject_CallObject((PyObject*)&DoubleList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_blob_list data;
} BlobList;

static PyObject *BlobList_len(BlobList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BlobList_subscript(BlobList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Blob_from(self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BlobList_Mapping = {
    .mp_length = (lenfunc)&BlobList_len,
    .mp_subscript = (binaryfunc)&BlobList_subscript,
};

static PyTypeObject BlobList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlobList",
    .tp_doc = PyDoc_STR("BlobList"),
    .tp_basicsize = sizeof(BlobList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BlobList_Mapping,
};

static PyObject *BlobList_from(ufbx_blob_list list, Context *ctx) {
    BlobList *obj = (BlobList*)PyObject_CallObject((PyObject*)&BlobList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_dom_node_list data;
} DomNodeList;

static PyObject *DomNodeList_len(DomNodeList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *DomNodeList_subscript(DomNodeList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_dom_node*");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods DomNodeList_Mapping = {
    .mp_length = (lenfunc)&DomNodeList_len,
    .mp_subscript = (binaryfunc)&DomNodeList_subscript,
};

static PyTypeObject DomNodeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DomNodeList",
    .tp_doc = PyDoc_STR("DomNodeList"),
    .tp_basicsize = sizeof(DomNodeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &DomNodeList_Mapping,
};

static PyObject *DomNodeList_from(ufbx_dom_node_list list, Context *ctx) {
    DomNodeList *obj = (DomNodeList*)PyObject_CallObject((PyObject*)&DomNodeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_dom_value_list data;
} DomValueList;

static PyObject *DomValueList_len(DomValueList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *DomValueList_subscript(DomValueList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_dom_value");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods DomValueList_Mapping = {
    .mp_length = (lenfunc)&DomValueList_len,
    .mp_subscript = (binaryfunc)&DomValueList_subscript,
};

static PyTypeObject DomValueList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DomValueList",
    .tp_doc = PyDoc_STR("DomValueList"),
    .tp_basicsize = sizeof(DomValueList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &DomValueList_Mapping,
};

static PyObject *DomValueList_from(ufbx_dom_value_list list, Context *ctx) {
    DomValueList *obj = (DomValueList*)PyObject_CallObject((PyObject*)&DomValueList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_prop_list data;
} PropList;

static PyObject *PropList_len(PropList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *PropList_subscript(PropList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_prop");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods PropList_Mapping = {
    .mp_length = (lenfunc)&PropList_len,
    .mp_subscript = (binaryfunc)&PropList_subscript,
};

static PyTypeObject PropList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.PropList",
    .tp_doc = PyDoc_STR("PropList"),
    .tp_basicsize = sizeof(PropList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &PropList_Mapping,
};

static PyObject *PropList_from(ufbx_prop_list list, Context *ctx) {
    PropList *obj = (PropList*)PyObject_CallObject((PyObject*)&PropList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_element_list data;
} ElementList;

static PyObject *ElementList_len(ElementList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ElementList_subscript(ElementList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_element*");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ElementList_Mapping = {
    .mp_length = (lenfunc)&ElementList_len,
    .mp_subscript = (binaryfunc)&ElementList_subscript,
};

static PyTypeObject ElementList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ElementList",
    .tp_doc = PyDoc_STR("ElementList"),
    .tp_basicsize = sizeof(ElementList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ElementList_Mapping,
};

static PyObject *ElementList_from(ufbx_element_list list, Context *ctx) {
    ElementList *obj = (ElementList*)PyObject_CallObject((PyObject*)&ElementList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_unknown_list data;
} UnknownList;

static PyObject *UnknownList_len(UnknownList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *UnknownList_subscript(UnknownList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods UnknownList_Mapping = {
    .mp_length = (lenfunc)&UnknownList_len,
    .mp_subscript = (binaryfunc)&UnknownList_subscript,
};

static PyTypeObject UnknownList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.UnknownList",
    .tp_doc = PyDoc_STR("UnknownList"),
    .tp_basicsize = sizeof(UnknownList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &UnknownList_Mapping,
};

static PyObject *UnknownList_from(ufbx_unknown_list list, Context *ctx) {
    UnknownList *obj = (UnknownList*)PyObject_CallObject((PyObject*)&UnknownList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_node_list data;
} NodeList;

static PyObject *NodeList_len(NodeList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *NodeList_subscript(NodeList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods NodeList_Mapping = {
    .mp_length = (lenfunc)&NodeList_len,
    .mp_subscript = (binaryfunc)&NodeList_subscript,
};

static PyTypeObject NodeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NodeList",
    .tp_doc = PyDoc_STR("NodeList"),
    .tp_basicsize = sizeof(NodeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &NodeList_Mapping,
};

static PyObject *NodeList_from(ufbx_node_list list, Context *ctx) {
    NodeList *obj = (NodeList*)PyObject_CallObject((PyObject*)&NodeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_mesh_list data;
} MeshList;

static PyObject *MeshList_len(MeshList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *MeshList_subscript(MeshList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods MeshList_Mapping = {
    .mp_length = (lenfunc)&MeshList_len,
    .mp_subscript = (binaryfunc)&MeshList_subscript,
};

static PyTypeObject MeshList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MeshList",
    .tp_doc = PyDoc_STR("MeshList"),
    .tp_basicsize = sizeof(MeshList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &MeshList_Mapping,
};

static PyObject *MeshList_from(ufbx_mesh_list list, Context *ctx) {
    MeshList *obj = (MeshList*)PyObject_CallObject((PyObject*)&MeshList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_light_list data;
} LightList;

static PyObject *LightList_len(LightList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *LightList_subscript(LightList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods LightList_Mapping = {
    .mp_length = (lenfunc)&LightList_len,
    .mp_subscript = (binaryfunc)&LightList_subscript,
};

static PyTypeObject LightList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LightList",
    .tp_doc = PyDoc_STR("LightList"),
    .tp_basicsize = sizeof(LightList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &LightList_Mapping,
};

static PyObject *LightList_from(ufbx_light_list list, Context *ctx) {
    LightList *obj = (LightList*)PyObject_CallObject((PyObject*)&LightList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_camera_list data;
} CameraList;

static PyObject *CameraList_len(CameraList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *CameraList_subscript(CameraList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods CameraList_Mapping = {
    .mp_length = (lenfunc)&CameraList_len,
    .mp_subscript = (binaryfunc)&CameraList_subscript,
};

static PyTypeObject CameraList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CameraList",
    .tp_doc = PyDoc_STR("CameraList"),
    .tp_basicsize = sizeof(CameraList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &CameraList_Mapping,
};

static PyObject *CameraList_from(ufbx_camera_list list, Context *ctx) {
    CameraList *obj = (CameraList*)PyObject_CallObject((PyObject*)&CameraList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_bone_list data;
} BoneList;

static PyObject *BoneList_len(BoneList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BoneList_subscript(BoneList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BoneList_Mapping = {
    .mp_length = (lenfunc)&BoneList_len,
    .mp_subscript = (binaryfunc)&BoneList_subscript,
};

static PyTypeObject BoneList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BoneList",
    .tp_doc = PyDoc_STR("BoneList"),
    .tp_basicsize = sizeof(BoneList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BoneList_Mapping,
};

static PyObject *BoneList_from(ufbx_bone_list list, Context *ctx) {
    BoneList *obj = (BoneList*)PyObject_CallObject((PyObject*)&BoneList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_empty_list data;
} EmptyList;

static PyObject *EmptyList_len(EmptyList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *EmptyList_subscript(EmptyList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods EmptyList_Mapping = {
    .mp_length = (lenfunc)&EmptyList_len,
    .mp_subscript = (binaryfunc)&EmptyList_subscript,
};

static PyTypeObject EmptyList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.EmptyList",
    .tp_doc = PyDoc_STR("EmptyList"),
    .tp_basicsize = sizeof(EmptyList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &EmptyList_Mapping,
};

static PyObject *EmptyList_from(ufbx_empty_list list, Context *ctx) {
    EmptyList *obj = (EmptyList*)PyObject_CallObject((PyObject*)&EmptyList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_line_curve_list data;
} LineCurveList;

static PyObject *LineCurveList_len(LineCurveList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *LineCurveList_subscript(LineCurveList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods LineCurveList_Mapping = {
    .mp_length = (lenfunc)&LineCurveList_len,
    .mp_subscript = (binaryfunc)&LineCurveList_subscript,
};

static PyTypeObject LineCurveList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LineCurveList",
    .tp_doc = PyDoc_STR("LineCurveList"),
    .tp_basicsize = sizeof(LineCurveList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &LineCurveList_Mapping,
};

static PyObject *LineCurveList_from(ufbx_line_curve_list list, Context *ctx) {
    LineCurveList *obj = (LineCurveList*)PyObject_CallObject((PyObject*)&LineCurveList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_nurbs_curve_list data;
} NurbsCurveList;

static PyObject *NurbsCurveList_len(NurbsCurveList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *NurbsCurveList_subscript(NurbsCurveList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods NurbsCurveList_Mapping = {
    .mp_length = (lenfunc)&NurbsCurveList_len,
    .mp_subscript = (binaryfunc)&NurbsCurveList_subscript,
};

static PyTypeObject NurbsCurveList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsCurveList",
    .tp_doc = PyDoc_STR("NurbsCurveList"),
    .tp_basicsize = sizeof(NurbsCurveList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &NurbsCurveList_Mapping,
};

static PyObject *NurbsCurveList_from(ufbx_nurbs_curve_list list, Context *ctx) {
    NurbsCurveList *obj = (NurbsCurveList*)PyObject_CallObject((PyObject*)&NurbsCurveList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_nurbs_surface_list data;
} NurbsSurfaceList;

static PyObject *NurbsSurfaceList_len(NurbsSurfaceList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *NurbsSurfaceList_subscript(NurbsSurfaceList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods NurbsSurfaceList_Mapping = {
    .mp_length = (lenfunc)&NurbsSurfaceList_len,
    .mp_subscript = (binaryfunc)&NurbsSurfaceList_subscript,
};

static PyTypeObject NurbsSurfaceList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsSurfaceList",
    .tp_doc = PyDoc_STR("NurbsSurfaceList"),
    .tp_basicsize = sizeof(NurbsSurfaceList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &NurbsSurfaceList_Mapping,
};

static PyObject *NurbsSurfaceList_from(ufbx_nurbs_surface_list list, Context *ctx) {
    NurbsSurfaceList *obj = (NurbsSurfaceList*)PyObject_CallObject((PyObject*)&NurbsSurfaceList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_nurbs_trim_surface_list data;
} NurbsTrimSurfaceList;

static PyObject *NurbsTrimSurfaceList_len(NurbsTrimSurfaceList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *NurbsTrimSurfaceList_subscript(NurbsTrimSurfaceList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods NurbsTrimSurfaceList_Mapping = {
    .mp_length = (lenfunc)&NurbsTrimSurfaceList_len,
    .mp_subscript = (binaryfunc)&NurbsTrimSurfaceList_subscript,
};

static PyTypeObject NurbsTrimSurfaceList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsTrimSurfaceList",
    .tp_doc = PyDoc_STR("NurbsTrimSurfaceList"),
    .tp_basicsize = sizeof(NurbsTrimSurfaceList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &NurbsTrimSurfaceList_Mapping,
};

static PyObject *NurbsTrimSurfaceList_from(ufbx_nurbs_trim_surface_list list, Context *ctx) {
    NurbsTrimSurfaceList *obj = (NurbsTrimSurfaceList*)PyObject_CallObject((PyObject*)&NurbsTrimSurfaceList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_nurbs_trim_boundary_list data;
} NurbsTrimBoundaryList;

static PyObject *NurbsTrimBoundaryList_len(NurbsTrimBoundaryList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *NurbsTrimBoundaryList_subscript(NurbsTrimBoundaryList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods NurbsTrimBoundaryList_Mapping = {
    .mp_length = (lenfunc)&NurbsTrimBoundaryList_len,
    .mp_subscript = (binaryfunc)&NurbsTrimBoundaryList_subscript,
};

static PyTypeObject NurbsTrimBoundaryList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsTrimBoundaryList",
    .tp_doc = PyDoc_STR("NurbsTrimBoundaryList"),
    .tp_basicsize = sizeof(NurbsTrimBoundaryList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &NurbsTrimBoundaryList_Mapping,
};

static PyObject *NurbsTrimBoundaryList_from(ufbx_nurbs_trim_boundary_list list, Context *ctx) {
    NurbsTrimBoundaryList *obj = (NurbsTrimBoundaryList*)PyObject_CallObject((PyObject*)&NurbsTrimBoundaryList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_procedural_geometry_list data;
} ProceduralGeometryList;

static PyObject *ProceduralGeometryList_len(ProceduralGeometryList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ProceduralGeometryList_subscript(ProceduralGeometryList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ProceduralGeometryList_Mapping = {
    .mp_length = (lenfunc)&ProceduralGeometryList_len,
    .mp_subscript = (binaryfunc)&ProceduralGeometryList_subscript,
};

static PyTypeObject ProceduralGeometryList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ProceduralGeometryList",
    .tp_doc = PyDoc_STR("ProceduralGeometryList"),
    .tp_basicsize = sizeof(ProceduralGeometryList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ProceduralGeometryList_Mapping,
};

static PyObject *ProceduralGeometryList_from(ufbx_procedural_geometry_list list, Context *ctx) {
    ProceduralGeometryList *obj = (ProceduralGeometryList*)PyObject_CallObject((PyObject*)&ProceduralGeometryList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_stereo_camera_list data;
} StereoCameraList;

static PyObject *StereoCameraList_len(StereoCameraList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *StereoCameraList_subscript(StereoCameraList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods StereoCameraList_Mapping = {
    .mp_length = (lenfunc)&StereoCameraList_len,
    .mp_subscript = (binaryfunc)&StereoCameraList_subscript,
};

static PyTypeObject StereoCameraList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.StereoCameraList",
    .tp_doc = PyDoc_STR("StereoCameraList"),
    .tp_basicsize = sizeof(StereoCameraList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &StereoCameraList_Mapping,
};

static PyObject *StereoCameraList_from(ufbx_stereo_camera_list list, Context *ctx) {
    StereoCameraList *obj = (StereoCameraList*)PyObject_CallObject((PyObject*)&StereoCameraList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_camera_switcher_list data;
} CameraSwitcherList;

static PyObject *CameraSwitcherList_len(CameraSwitcherList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *CameraSwitcherList_subscript(CameraSwitcherList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods CameraSwitcherList_Mapping = {
    .mp_length = (lenfunc)&CameraSwitcherList_len,
    .mp_subscript = (binaryfunc)&CameraSwitcherList_subscript,
};

static PyTypeObject CameraSwitcherList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CameraSwitcherList",
    .tp_doc = PyDoc_STR("CameraSwitcherList"),
    .tp_basicsize = sizeof(CameraSwitcherList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &CameraSwitcherList_Mapping,
};

static PyObject *CameraSwitcherList_from(ufbx_camera_switcher_list list, Context *ctx) {
    CameraSwitcherList *obj = (CameraSwitcherList*)PyObject_CallObject((PyObject*)&CameraSwitcherList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_marker_list data;
} MarkerList;

static PyObject *MarkerList_len(MarkerList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *MarkerList_subscript(MarkerList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods MarkerList_Mapping = {
    .mp_length = (lenfunc)&MarkerList_len,
    .mp_subscript = (binaryfunc)&MarkerList_subscript,
};

static PyTypeObject MarkerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MarkerList",
    .tp_doc = PyDoc_STR("MarkerList"),
    .tp_basicsize = sizeof(MarkerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &MarkerList_Mapping,
};

static PyObject *MarkerList_from(ufbx_marker_list list, Context *ctx) {
    MarkerList *obj = (MarkerList*)PyObject_CallObject((PyObject*)&MarkerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_lod_group_list data;
} LodGroupList;

static PyObject *LodGroupList_len(LodGroupList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *LodGroupList_subscript(LodGroupList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods LodGroupList_Mapping = {
    .mp_length = (lenfunc)&LodGroupList_len,
    .mp_subscript = (binaryfunc)&LodGroupList_subscript,
};

static PyTypeObject LodGroupList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LodGroupList",
    .tp_doc = PyDoc_STR("LodGroupList"),
    .tp_basicsize = sizeof(LodGroupList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &LodGroupList_Mapping,
};

static PyObject *LodGroupList_from(ufbx_lod_group_list list, Context *ctx) {
    LodGroupList *obj = (LodGroupList*)PyObject_CallObject((PyObject*)&LodGroupList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_skin_deformer_list data;
} SkinDeformerList;

static PyObject *SkinDeformerList_len(SkinDeformerList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *SkinDeformerList_subscript(SkinDeformerList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods SkinDeformerList_Mapping = {
    .mp_length = (lenfunc)&SkinDeformerList_len,
    .mp_subscript = (binaryfunc)&SkinDeformerList_subscript,
};

static PyTypeObject SkinDeformerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SkinDeformerList",
    .tp_doc = PyDoc_STR("SkinDeformerList"),
    .tp_basicsize = sizeof(SkinDeformerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &SkinDeformerList_Mapping,
};

static PyObject *SkinDeformerList_from(ufbx_skin_deformer_list list, Context *ctx) {
    SkinDeformerList *obj = (SkinDeformerList*)PyObject_CallObject((PyObject*)&SkinDeformerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_skin_cluster_list data;
} SkinClusterList;

static PyObject *SkinClusterList_len(SkinClusterList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *SkinClusterList_subscript(SkinClusterList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods SkinClusterList_Mapping = {
    .mp_length = (lenfunc)&SkinClusterList_len,
    .mp_subscript = (binaryfunc)&SkinClusterList_subscript,
};

static PyTypeObject SkinClusterList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SkinClusterList",
    .tp_doc = PyDoc_STR("SkinClusterList"),
    .tp_basicsize = sizeof(SkinClusterList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &SkinClusterList_Mapping,
};

static PyObject *SkinClusterList_from(ufbx_skin_cluster_list list, Context *ctx) {
    SkinClusterList *obj = (SkinClusterList*)PyObject_CallObject((PyObject*)&SkinClusterList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_blend_deformer_list data;
} BlendDeformerList;

static PyObject *BlendDeformerList_len(BlendDeformerList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BlendDeformerList_subscript(BlendDeformerList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BlendDeformerList_Mapping = {
    .mp_length = (lenfunc)&BlendDeformerList_len,
    .mp_subscript = (binaryfunc)&BlendDeformerList_subscript,
};

static PyTypeObject BlendDeformerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendDeformerList",
    .tp_doc = PyDoc_STR("BlendDeformerList"),
    .tp_basicsize = sizeof(BlendDeformerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BlendDeformerList_Mapping,
};

static PyObject *BlendDeformerList_from(ufbx_blend_deformer_list list, Context *ctx) {
    BlendDeformerList *obj = (BlendDeformerList*)PyObject_CallObject((PyObject*)&BlendDeformerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_blend_channel_list data;
} BlendChannelList;

static PyObject *BlendChannelList_len(BlendChannelList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BlendChannelList_subscript(BlendChannelList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BlendChannelList_Mapping = {
    .mp_length = (lenfunc)&BlendChannelList_len,
    .mp_subscript = (binaryfunc)&BlendChannelList_subscript,
};

static PyTypeObject BlendChannelList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendChannelList",
    .tp_doc = PyDoc_STR("BlendChannelList"),
    .tp_basicsize = sizeof(BlendChannelList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BlendChannelList_Mapping,
};

static PyObject *BlendChannelList_from(ufbx_blend_channel_list list, Context *ctx) {
    BlendChannelList *obj = (BlendChannelList*)PyObject_CallObject((PyObject*)&BlendChannelList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_blend_shape_list data;
} BlendShapeList;

static PyObject *BlendShapeList_len(BlendShapeList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BlendShapeList_subscript(BlendShapeList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BlendShapeList_Mapping = {
    .mp_length = (lenfunc)&BlendShapeList_len,
    .mp_subscript = (binaryfunc)&BlendShapeList_subscript,
};

static PyTypeObject BlendShapeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendShapeList",
    .tp_doc = PyDoc_STR("BlendShapeList"),
    .tp_basicsize = sizeof(BlendShapeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BlendShapeList_Mapping,
};

static PyObject *BlendShapeList_from(ufbx_blend_shape_list list, Context *ctx) {
    BlendShapeList *obj = (BlendShapeList*)PyObject_CallObject((PyObject*)&BlendShapeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_cache_deformer_list data;
} CacheDeformerList;

static PyObject *CacheDeformerList_len(CacheDeformerList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *CacheDeformerList_subscript(CacheDeformerList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods CacheDeformerList_Mapping = {
    .mp_length = (lenfunc)&CacheDeformerList_len,
    .mp_subscript = (binaryfunc)&CacheDeformerList_subscript,
};

static PyTypeObject CacheDeformerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheDeformerList",
    .tp_doc = PyDoc_STR("CacheDeformerList"),
    .tp_basicsize = sizeof(CacheDeformerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &CacheDeformerList_Mapping,
};

static PyObject *CacheDeformerList_from(ufbx_cache_deformer_list list, Context *ctx) {
    CacheDeformerList *obj = (CacheDeformerList*)PyObject_CallObject((PyObject*)&CacheDeformerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_cache_file_list data;
} CacheFileList;

static PyObject *CacheFileList_len(CacheFileList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *CacheFileList_subscript(CacheFileList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods CacheFileList_Mapping = {
    .mp_length = (lenfunc)&CacheFileList_len,
    .mp_subscript = (binaryfunc)&CacheFileList_subscript,
};

static PyTypeObject CacheFileList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheFileList",
    .tp_doc = PyDoc_STR("CacheFileList"),
    .tp_basicsize = sizeof(CacheFileList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &CacheFileList_Mapping,
};

static PyObject *CacheFileList_from(ufbx_cache_file_list list, Context *ctx) {
    CacheFileList *obj = (CacheFileList*)PyObject_CallObject((PyObject*)&CacheFileList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_material_list data;
} MaterialList;

static PyObject *MaterialList_len(MaterialList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *MaterialList_subscript(MaterialList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods MaterialList_Mapping = {
    .mp_length = (lenfunc)&MaterialList_len,
    .mp_subscript = (binaryfunc)&MaterialList_subscript,
};

static PyTypeObject MaterialList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialList",
    .tp_doc = PyDoc_STR("MaterialList"),
    .tp_basicsize = sizeof(MaterialList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &MaterialList_Mapping,
};

static PyObject *MaterialList_from(ufbx_material_list list, Context *ctx) {
    MaterialList *obj = (MaterialList*)PyObject_CallObject((PyObject*)&MaterialList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_texture_list data;
} TextureList;

static PyObject *TextureList_len(TextureList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *TextureList_subscript(TextureList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods TextureList_Mapping = {
    .mp_length = (lenfunc)&TextureList_len,
    .mp_subscript = (binaryfunc)&TextureList_subscript,
};

static PyTypeObject TextureList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.TextureList",
    .tp_doc = PyDoc_STR("TextureList"),
    .tp_basicsize = sizeof(TextureList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &TextureList_Mapping,
};

static PyObject *TextureList_from(ufbx_texture_list list, Context *ctx) {
    TextureList *obj = (TextureList*)PyObject_CallObject((PyObject*)&TextureList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_video_list data;
} VideoList;

static PyObject *VideoList_len(VideoList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *VideoList_subscript(VideoList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods VideoList_Mapping = {
    .mp_length = (lenfunc)&VideoList_len,
    .mp_subscript = (binaryfunc)&VideoList_subscript,
};

static PyTypeObject VideoList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.VideoList",
    .tp_doc = PyDoc_STR("VideoList"),
    .tp_basicsize = sizeof(VideoList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &VideoList_Mapping,
};

static PyObject *VideoList_from(ufbx_video_list list, Context *ctx) {
    VideoList *obj = (VideoList*)PyObject_CallObject((PyObject*)&VideoList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_shader_list data;
} ShaderList;

static PyObject *ShaderList_len(ShaderList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ShaderList_subscript(ShaderList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ShaderList_Mapping = {
    .mp_length = (lenfunc)&ShaderList_len,
    .mp_subscript = (binaryfunc)&ShaderList_subscript,
};

static PyTypeObject ShaderList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderList",
    .tp_doc = PyDoc_STR("ShaderList"),
    .tp_basicsize = sizeof(ShaderList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ShaderList_Mapping,
};

static PyObject *ShaderList_from(ufbx_shader_list list, Context *ctx) {
    ShaderList *obj = (ShaderList*)PyObject_CallObject((PyObject*)&ShaderList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_shader_binding_list data;
} ShaderBindingList;

static PyObject *ShaderBindingList_len(ShaderBindingList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ShaderBindingList_subscript(ShaderBindingList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ShaderBindingList_Mapping = {
    .mp_length = (lenfunc)&ShaderBindingList_len,
    .mp_subscript = (binaryfunc)&ShaderBindingList_subscript,
};

static PyTypeObject ShaderBindingList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderBindingList",
    .tp_doc = PyDoc_STR("ShaderBindingList"),
    .tp_basicsize = sizeof(ShaderBindingList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ShaderBindingList_Mapping,
};

static PyObject *ShaderBindingList_from(ufbx_shader_binding_list list, Context *ctx) {
    ShaderBindingList *obj = (ShaderBindingList*)PyObject_CallObject((PyObject*)&ShaderBindingList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_anim_stack_list data;
} AnimStackList;

static PyObject *AnimStackList_len(AnimStackList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *AnimStackList_subscript(AnimStackList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods AnimStackList_Mapping = {
    .mp_length = (lenfunc)&AnimStackList_len,
    .mp_subscript = (binaryfunc)&AnimStackList_subscript,
};

static PyTypeObject AnimStackList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimStackList",
    .tp_doc = PyDoc_STR("AnimStackList"),
    .tp_basicsize = sizeof(AnimStackList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &AnimStackList_Mapping,
};

static PyObject *AnimStackList_from(ufbx_anim_stack_list list, Context *ctx) {
    AnimStackList *obj = (AnimStackList*)PyObject_CallObject((PyObject*)&AnimStackList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_anim_layer_list data;
} AnimLayerList;

static PyObject *AnimLayerList_len(AnimLayerList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *AnimLayerList_subscript(AnimLayerList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods AnimLayerList_Mapping = {
    .mp_length = (lenfunc)&AnimLayerList_len,
    .mp_subscript = (binaryfunc)&AnimLayerList_subscript,
};

static PyTypeObject AnimLayerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimLayerList",
    .tp_doc = PyDoc_STR("AnimLayerList"),
    .tp_basicsize = sizeof(AnimLayerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &AnimLayerList_Mapping,
};

static PyObject *AnimLayerList_from(ufbx_anim_layer_list list, Context *ctx) {
    AnimLayerList *obj = (AnimLayerList*)PyObject_CallObject((PyObject*)&AnimLayerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_anim_value_list data;
} AnimValueList;

static PyObject *AnimValueList_len(AnimValueList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *AnimValueList_subscript(AnimValueList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods AnimValueList_Mapping = {
    .mp_length = (lenfunc)&AnimValueList_len,
    .mp_subscript = (binaryfunc)&AnimValueList_subscript,
};

static PyTypeObject AnimValueList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimValueList",
    .tp_doc = PyDoc_STR("AnimValueList"),
    .tp_basicsize = sizeof(AnimValueList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &AnimValueList_Mapping,
};

static PyObject *AnimValueList_from(ufbx_anim_value_list list, Context *ctx) {
    AnimValueList *obj = (AnimValueList*)PyObject_CallObject((PyObject*)&AnimValueList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_anim_curve_list data;
} AnimCurveList;

static PyObject *AnimCurveList_len(AnimCurveList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *AnimCurveList_subscript(AnimCurveList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods AnimCurveList_Mapping = {
    .mp_length = (lenfunc)&AnimCurveList_len,
    .mp_subscript = (binaryfunc)&AnimCurveList_subscript,
};

static PyTypeObject AnimCurveList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimCurveList",
    .tp_doc = PyDoc_STR("AnimCurveList"),
    .tp_basicsize = sizeof(AnimCurveList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &AnimCurveList_Mapping,
};

static PyObject *AnimCurveList_from(ufbx_anim_curve_list list, Context *ctx) {
    AnimCurveList *obj = (AnimCurveList*)PyObject_CallObject((PyObject*)&AnimCurveList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_display_layer_list data;
} DisplayLayerList;

static PyObject *DisplayLayerList_len(DisplayLayerList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *DisplayLayerList_subscript(DisplayLayerList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods DisplayLayerList_Mapping = {
    .mp_length = (lenfunc)&DisplayLayerList_len,
    .mp_subscript = (binaryfunc)&DisplayLayerList_subscript,
};

static PyTypeObject DisplayLayerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DisplayLayerList",
    .tp_doc = PyDoc_STR("DisplayLayerList"),
    .tp_basicsize = sizeof(DisplayLayerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &DisplayLayerList_Mapping,
};

static PyObject *DisplayLayerList_from(ufbx_display_layer_list list, Context *ctx) {
    DisplayLayerList *obj = (DisplayLayerList*)PyObject_CallObject((PyObject*)&DisplayLayerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_selection_set_list data;
} SelectionSetList;

static PyObject *SelectionSetList_len(SelectionSetList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *SelectionSetList_subscript(SelectionSetList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods SelectionSetList_Mapping = {
    .mp_length = (lenfunc)&SelectionSetList_len,
    .mp_subscript = (binaryfunc)&SelectionSetList_subscript,
};

static PyTypeObject SelectionSetList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SelectionSetList",
    .tp_doc = PyDoc_STR("SelectionSetList"),
    .tp_basicsize = sizeof(SelectionSetList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &SelectionSetList_Mapping,
};

static PyObject *SelectionSetList_from(ufbx_selection_set_list list, Context *ctx) {
    SelectionSetList *obj = (SelectionSetList*)PyObject_CallObject((PyObject*)&SelectionSetList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_selection_node_list data;
} SelectionNodeList;

static PyObject *SelectionNodeList_len(SelectionNodeList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *SelectionNodeList_subscript(SelectionNodeList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods SelectionNodeList_Mapping = {
    .mp_length = (lenfunc)&SelectionNodeList_len,
    .mp_subscript = (binaryfunc)&SelectionNodeList_subscript,
};

static PyTypeObject SelectionNodeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SelectionNodeList",
    .tp_doc = PyDoc_STR("SelectionNodeList"),
    .tp_basicsize = sizeof(SelectionNodeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &SelectionNodeList_Mapping,
};

static PyObject *SelectionNodeList_from(ufbx_selection_node_list list, Context *ctx) {
    SelectionNodeList *obj = (SelectionNodeList*)PyObject_CallObject((PyObject*)&SelectionNodeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_character_list data;
} CharacterList;

static PyObject *CharacterList_len(CharacterList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *CharacterList_subscript(CharacterList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods CharacterList_Mapping = {
    .mp_length = (lenfunc)&CharacterList_len,
    .mp_subscript = (binaryfunc)&CharacterList_subscript,
};

static PyTypeObject CharacterList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CharacterList",
    .tp_doc = PyDoc_STR("CharacterList"),
    .tp_basicsize = sizeof(CharacterList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &CharacterList_Mapping,
};

static PyObject *CharacterList_from(ufbx_character_list list, Context *ctx) {
    CharacterList *obj = (CharacterList*)PyObject_CallObject((PyObject*)&CharacterList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_constraint_list data;
} ConstraintList;

static PyObject *ConstraintList_len(ConstraintList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ConstraintList_subscript(ConstraintList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ConstraintList_Mapping = {
    .mp_length = (lenfunc)&ConstraintList_len,
    .mp_subscript = (binaryfunc)&ConstraintList_subscript,
};

static PyTypeObject ConstraintList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstraintList",
    .tp_doc = PyDoc_STR("ConstraintList"),
    .tp_basicsize = sizeof(ConstraintList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ConstraintList_Mapping,
};

static PyObject *ConstraintList_from(ufbx_constraint_list list, Context *ctx) {
    ConstraintList *obj = (ConstraintList*)PyObject_CallObject((PyObject*)&ConstraintList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_audio_layer_list data;
} AudioLayerList;

static PyObject *AudioLayerList_len(AudioLayerList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *AudioLayerList_subscript(AudioLayerList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods AudioLayerList_Mapping = {
    .mp_length = (lenfunc)&AudioLayerList_len,
    .mp_subscript = (binaryfunc)&AudioLayerList_subscript,
};

static PyTypeObject AudioLayerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AudioLayerList",
    .tp_doc = PyDoc_STR("AudioLayerList"),
    .tp_basicsize = sizeof(AudioLayerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &AudioLayerList_Mapping,
};

static PyObject *AudioLayerList_from(ufbx_audio_layer_list list, Context *ctx) {
    AudioLayerList *obj = (AudioLayerList*)PyObject_CallObject((PyObject*)&AudioLayerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_audio_clip_list data;
} AudioClipList;

static PyObject *AudioClipList_len(AudioClipList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *AudioClipList_subscript(AudioClipList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods AudioClipList_Mapping = {
    .mp_length = (lenfunc)&AudioClipList_len,
    .mp_subscript = (binaryfunc)&AudioClipList_subscript,
};

static PyTypeObject AudioClipList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AudioClipList",
    .tp_doc = PyDoc_STR("AudioClipList"),
    .tp_basicsize = sizeof(AudioClipList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &AudioClipList_Mapping,
};

static PyObject *AudioClipList_from(ufbx_audio_clip_list list, Context *ctx) {
    AudioClipList *obj = (AudioClipList*)PyObject_CallObject((PyObject*)&AudioClipList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_pose_list data;
} PoseList;

static PyObject *PoseList_len(PoseList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *PoseList_subscript(PoseList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods PoseList_Mapping = {
    .mp_length = (lenfunc)&PoseList_len,
    .mp_subscript = (binaryfunc)&PoseList_subscript,
};

static PyTypeObject PoseList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.PoseList",
    .tp_doc = PyDoc_STR("PoseList"),
    .tp_basicsize = sizeof(PoseList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &PoseList_Mapping,
};

static PyObject *PoseList_from(ufbx_pose_list list, Context *ctx) {
    PoseList *obj = (PoseList*)PyObject_CallObject((PyObject*)&PoseList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_metadata_object_list data;
} MetadataObjectList;

static PyObject *MetadataObjectList_len(MetadataObjectList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *MetadataObjectList_subscript(MetadataObjectList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return Element_from(self->data.data[index], self->ctx);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods MetadataObjectList_Mapping = {
    .mp_length = (lenfunc)&MetadataObjectList_len,
    .mp_subscript = (binaryfunc)&MetadataObjectList_subscript,
};

static PyTypeObject MetadataObjectList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MetadataObjectList",
    .tp_doc = PyDoc_STR("MetadataObjectList"),
    .tp_basicsize = sizeof(MetadataObjectList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &MetadataObjectList_Mapping,
};

static PyObject *MetadataObjectList_from(ufbx_metadata_object_list list, Context *ctx) {
    MetadataObjectList *obj = (MetadataObjectList*)PyObject_CallObject((PyObject*)&MetadataObjectList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_connection_list data;
} ConnectionList;

static PyObject *ConnectionList_len(ConnectionList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ConnectionList_subscript(ConnectionList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_connection");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ConnectionList_Mapping = {
    .mp_length = (lenfunc)&ConnectionList_len,
    .mp_subscript = (binaryfunc)&ConnectionList_subscript,
};

static PyTypeObject ConnectionList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConnectionList",
    .tp_doc = PyDoc_STR("ConnectionList"),
    .tp_basicsize = sizeof(ConnectionList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ConnectionList_Mapping,
};

static PyObject *ConnectionList_from(ufbx_connection_list list, Context *ctx) {
    ConnectionList *obj = (ConnectionList*)PyObject_CallObject((PyObject*)&ConnectionList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_uv_set_list data;
} UvSetList;

static PyObject *UvSetList_len(UvSetList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *UvSetList_subscript(UvSetList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_uv_set");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods UvSetList_Mapping = {
    .mp_length = (lenfunc)&UvSetList_len,
    .mp_subscript = (binaryfunc)&UvSetList_subscript,
};

static PyTypeObject UvSetList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.UvSetList",
    .tp_doc = PyDoc_STR("UvSetList"),
    .tp_basicsize = sizeof(UvSetList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &UvSetList_Mapping,
};

static PyObject *UvSetList_from(ufbx_uv_set_list list, Context *ctx) {
    UvSetList *obj = (UvSetList*)PyObject_CallObject((PyObject*)&UvSetList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_color_set_list data;
} ColorSetList;

static PyObject *ColorSetList_len(ColorSetList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ColorSetList_subscript(ColorSetList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_color_set");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ColorSetList_Mapping = {
    .mp_length = (lenfunc)&ColorSetList_len,
    .mp_subscript = (binaryfunc)&ColorSetList_subscript,
};

static PyTypeObject ColorSetList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ColorSetList",
    .tp_doc = PyDoc_STR("ColorSetList"),
    .tp_basicsize = sizeof(ColorSetList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ColorSetList_Mapping,
};

static PyObject *ColorSetList_from(ufbx_color_set_list list, Context *ctx) {
    ColorSetList *obj = (ColorSetList*)PyObject_CallObject((PyObject*)&ColorSetList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_edge_list data;
} EdgeList;

static PyObject *EdgeList_len(EdgeList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *EdgeList_subscript(EdgeList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_edge");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods EdgeList_Mapping = {
    .mp_length = (lenfunc)&EdgeList_len,
    .mp_subscript = (binaryfunc)&EdgeList_subscript,
};

static PyTypeObject EdgeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.EdgeList",
    .tp_doc = PyDoc_STR("EdgeList"),
    .tp_basicsize = sizeof(EdgeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &EdgeList_Mapping,
};

static PyObject *EdgeList_from(ufbx_edge_list list, Context *ctx) {
    EdgeList *obj = (EdgeList*)PyObject_CallObject((PyObject*)&EdgeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_face_list data;
} FaceList;

static PyObject *FaceList_len(FaceList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *FaceList_subscript(FaceList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_face");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods FaceList_Mapping = {
    .mp_length = (lenfunc)&FaceList_len,
    .mp_subscript = (binaryfunc)&FaceList_subscript,
};

static PyTypeObject FaceList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.FaceList",
    .tp_doc = PyDoc_STR("FaceList"),
    .tp_basicsize = sizeof(FaceList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &FaceList_Mapping,
};

static PyObject *FaceList_from(ufbx_face_list list, Context *ctx) {
    FaceList *obj = (FaceList*)PyObject_CallObject((PyObject*)&FaceList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_mesh_part_list data;
} MeshPartList;

static PyObject *MeshPartList_len(MeshPartList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *MeshPartList_subscript(MeshPartList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_mesh_part");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods MeshPartList_Mapping = {
    .mp_length = (lenfunc)&MeshPartList_len,
    .mp_subscript = (binaryfunc)&MeshPartList_subscript,
};

static PyTypeObject MeshPartList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MeshPartList",
    .tp_doc = PyDoc_STR("MeshPartList"),
    .tp_basicsize = sizeof(MeshPartList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &MeshPartList_Mapping,
};

static PyObject *MeshPartList_from(ufbx_mesh_part_list list, Context *ctx) {
    MeshPartList *obj = (MeshPartList*)PyObject_CallObject((PyObject*)&MeshPartList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_face_group_list data;
} FaceGroupList;

static PyObject *FaceGroupList_len(FaceGroupList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *FaceGroupList_subscript(FaceGroupList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_face_group");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods FaceGroupList_Mapping = {
    .mp_length = (lenfunc)&FaceGroupList_len,
    .mp_subscript = (binaryfunc)&FaceGroupList_subscript,
};

static PyTypeObject FaceGroupList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.FaceGroupList",
    .tp_doc = PyDoc_STR("FaceGroupList"),
    .tp_basicsize = sizeof(FaceGroupList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &FaceGroupList_Mapping,
};

static PyObject *FaceGroupList_from(ufbx_face_group_list list, Context *ctx) {
    FaceGroupList *obj = (FaceGroupList*)PyObject_CallObject((PyObject*)&FaceGroupList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_subdivision_weight_range_list data;
} SubdivisionWeightRangeList;

static PyObject *SubdivisionWeightRangeList_len(SubdivisionWeightRangeList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *SubdivisionWeightRangeList_subscript(SubdivisionWeightRangeList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_subdivision_weight_range");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods SubdivisionWeightRangeList_Mapping = {
    .mp_length = (lenfunc)&SubdivisionWeightRangeList_len,
    .mp_subscript = (binaryfunc)&SubdivisionWeightRangeList_subscript,
};

static PyTypeObject SubdivisionWeightRangeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SubdivisionWeightRangeList",
    .tp_doc = PyDoc_STR("SubdivisionWeightRangeList"),
    .tp_basicsize = sizeof(SubdivisionWeightRangeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &SubdivisionWeightRangeList_Mapping,
};

static PyObject *SubdivisionWeightRangeList_from(ufbx_subdivision_weight_range_list list, Context *ctx) {
    SubdivisionWeightRangeList *obj = (SubdivisionWeightRangeList*)PyObject_CallObject((PyObject*)&SubdivisionWeightRangeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_subdivision_weight_list data;
} SubdivisionWeightList;

static PyObject *SubdivisionWeightList_len(SubdivisionWeightList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *SubdivisionWeightList_subscript(SubdivisionWeightList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_subdivision_weight");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods SubdivisionWeightList_Mapping = {
    .mp_length = (lenfunc)&SubdivisionWeightList_len,
    .mp_subscript = (binaryfunc)&SubdivisionWeightList_subscript,
};

static PyTypeObject SubdivisionWeightList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SubdivisionWeightList",
    .tp_doc = PyDoc_STR("SubdivisionWeightList"),
    .tp_basicsize = sizeof(SubdivisionWeightList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &SubdivisionWeightList_Mapping,
};

static PyObject *SubdivisionWeightList_from(ufbx_subdivision_weight_list list, Context *ctx) {
    SubdivisionWeightList *obj = (SubdivisionWeightList*)PyObject_CallObject((PyObject*)&SubdivisionWeightList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_line_segment_list data;
} LineSegmentList;

static PyObject *LineSegmentList_len(LineSegmentList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *LineSegmentList_subscript(LineSegmentList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_line_segment");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods LineSegmentList_Mapping = {
    .mp_length = (lenfunc)&LineSegmentList_len,
    .mp_subscript = (binaryfunc)&LineSegmentList_subscript,
};

static PyTypeObject LineSegmentList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LineSegmentList",
    .tp_doc = PyDoc_STR("LineSegmentList"),
    .tp_basicsize = sizeof(LineSegmentList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &LineSegmentList_Mapping,
};

static PyObject *LineSegmentList_from(ufbx_line_segment_list list, Context *ctx) {
    LineSegmentList *obj = (LineSegmentList*)PyObject_CallObject((PyObject*)&LineSegmentList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_lod_level_list data;
} LodLevelList;

static PyObject *LodLevelList_len(LodLevelList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *LodLevelList_subscript(LodLevelList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_lod_level");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods LodLevelList_Mapping = {
    .mp_length = (lenfunc)&LodLevelList_len,
    .mp_subscript = (binaryfunc)&LodLevelList_subscript,
};

static PyTypeObject LodLevelList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LodLevelList",
    .tp_doc = PyDoc_STR("LodLevelList"),
    .tp_basicsize = sizeof(LodLevelList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &LodLevelList_Mapping,
};

static PyObject *LodLevelList_from(ufbx_lod_level_list list, Context *ctx) {
    LodLevelList *obj = (LodLevelList*)PyObject_CallObject((PyObject*)&LodLevelList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_skin_vertex_list data;
} SkinVertexList;

static PyObject *SkinVertexList_len(SkinVertexList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *SkinVertexList_subscript(SkinVertexList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_skin_vertex");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods SkinVertexList_Mapping = {
    .mp_length = (lenfunc)&SkinVertexList_len,
    .mp_subscript = (binaryfunc)&SkinVertexList_subscript,
};

static PyTypeObject SkinVertexList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SkinVertexList",
    .tp_doc = PyDoc_STR("SkinVertexList"),
    .tp_basicsize = sizeof(SkinVertexList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &SkinVertexList_Mapping,
};

static PyObject *SkinVertexList_from(ufbx_skin_vertex_list list, Context *ctx) {
    SkinVertexList *obj = (SkinVertexList*)PyObject_CallObject((PyObject*)&SkinVertexList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_skin_weight_list data;
} SkinWeightList;

static PyObject *SkinWeightList_len(SkinWeightList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *SkinWeightList_subscript(SkinWeightList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_skin_weight");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods SkinWeightList_Mapping = {
    .mp_length = (lenfunc)&SkinWeightList_len,
    .mp_subscript = (binaryfunc)&SkinWeightList_subscript,
};

static PyTypeObject SkinWeightList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SkinWeightList",
    .tp_doc = PyDoc_STR("SkinWeightList"),
    .tp_basicsize = sizeof(SkinWeightList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &SkinWeightList_Mapping,
};

static PyObject *SkinWeightList_from(ufbx_skin_weight_list list, Context *ctx) {
    SkinWeightList *obj = (SkinWeightList*)PyObject_CallObject((PyObject*)&SkinWeightList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_blend_keyframe_list data;
} BlendKeyframeList;

static PyObject *BlendKeyframeList_len(BlendKeyframeList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BlendKeyframeList_subscript(BlendKeyframeList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_blend_keyframe");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BlendKeyframeList_Mapping = {
    .mp_length = (lenfunc)&BlendKeyframeList_len,
    .mp_subscript = (binaryfunc)&BlendKeyframeList_subscript,
};

static PyTypeObject BlendKeyframeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendKeyframeList",
    .tp_doc = PyDoc_STR("BlendKeyframeList"),
    .tp_basicsize = sizeof(BlendKeyframeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BlendKeyframeList_Mapping,
};

static PyObject *BlendKeyframeList_from(ufbx_blend_keyframe_list list, Context *ctx) {
    BlendKeyframeList *obj = (BlendKeyframeList*)PyObject_CallObject((PyObject*)&BlendKeyframeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_cache_frame_list data;
} CacheFrameList;

static PyObject *CacheFrameList_len(CacheFrameList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *CacheFrameList_subscript(CacheFrameList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_cache_frame");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods CacheFrameList_Mapping = {
    .mp_length = (lenfunc)&CacheFrameList_len,
    .mp_subscript = (binaryfunc)&CacheFrameList_subscript,
};

static PyTypeObject CacheFrameList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheFrameList",
    .tp_doc = PyDoc_STR("CacheFrameList"),
    .tp_basicsize = sizeof(CacheFrameList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &CacheFrameList_Mapping,
};

static PyObject *CacheFrameList_from(ufbx_cache_frame_list list, Context *ctx) {
    CacheFrameList *obj = (CacheFrameList*)PyObject_CallObject((PyObject*)&CacheFrameList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_cache_channel_list data;
} CacheChannelList;

static PyObject *CacheChannelList_len(CacheChannelList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *CacheChannelList_subscript(CacheChannelList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_cache_channel");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods CacheChannelList_Mapping = {
    .mp_length = (lenfunc)&CacheChannelList_len,
    .mp_subscript = (binaryfunc)&CacheChannelList_subscript,
};

static PyTypeObject CacheChannelList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheChannelList",
    .tp_doc = PyDoc_STR("CacheChannelList"),
    .tp_basicsize = sizeof(CacheChannelList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &CacheChannelList_Mapping,
};

static PyObject *CacheChannelList_from(ufbx_cache_channel_list list, Context *ctx) {
    CacheChannelList *obj = (CacheChannelList*)PyObject_CallObject((PyObject*)&CacheChannelList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_material_texture_list data;
} MaterialTextureList;

static PyObject *MaterialTextureList_len(MaterialTextureList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *MaterialTextureList_subscript(MaterialTextureList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_material_texture");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods MaterialTextureList_Mapping = {
    .mp_length = (lenfunc)&MaterialTextureList_len,
    .mp_subscript = (binaryfunc)&MaterialTextureList_subscript,
};

static PyTypeObject MaterialTextureList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialTextureList",
    .tp_doc = PyDoc_STR("MaterialTextureList"),
    .tp_basicsize = sizeof(MaterialTextureList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &MaterialTextureList_Mapping,
};

static PyObject *MaterialTextureList_from(ufbx_material_texture_list list, Context *ctx) {
    MaterialTextureList *obj = (MaterialTextureList*)PyObject_CallObject((PyObject*)&MaterialTextureList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_texture_layer_list data;
} TextureLayerList;

static PyObject *TextureLayerList_len(TextureLayerList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *TextureLayerList_subscript(TextureLayerList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_texture_layer");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods TextureLayerList_Mapping = {
    .mp_length = (lenfunc)&TextureLayerList_len,
    .mp_subscript = (binaryfunc)&TextureLayerList_subscript,
};

static PyTypeObject TextureLayerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.TextureLayerList",
    .tp_doc = PyDoc_STR("TextureLayerList"),
    .tp_basicsize = sizeof(TextureLayerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &TextureLayerList_Mapping,
};

static PyObject *TextureLayerList_from(ufbx_texture_layer_list list, Context *ctx) {
    TextureLayerList *obj = (TextureLayerList*)PyObject_CallObject((PyObject*)&TextureLayerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_shader_texture_input_list data;
} ShaderTextureInputList;

static PyObject *ShaderTextureInputList_len(ShaderTextureInputList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ShaderTextureInputList_subscript(ShaderTextureInputList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_shader_texture_input");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ShaderTextureInputList_Mapping = {
    .mp_length = (lenfunc)&ShaderTextureInputList_len,
    .mp_subscript = (binaryfunc)&ShaderTextureInputList_subscript,
};

static PyTypeObject ShaderTextureInputList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderTextureInputList",
    .tp_doc = PyDoc_STR("ShaderTextureInputList"),
    .tp_basicsize = sizeof(ShaderTextureInputList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ShaderTextureInputList_Mapping,
};

static PyObject *ShaderTextureInputList_from(ufbx_shader_texture_input_list list, Context *ctx) {
    ShaderTextureInputList *obj = (ShaderTextureInputList*)PyObject_CallObject((PyObject*)&ShaderTextureInputList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_texture_file_list data;
} TextureFileList;

static PyObject *TextureFileList_len(TextureFileList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *TextureFileList_subscript(TextureFileList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_texture_file");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods TextureFileList_Mapping = {
    .mp_length = (lenfunc)&TextureFileList_len,
    .mp_subscript = (binaryfunc)&TextureFileList_subscript,
};

static PyTypeObject TextureFileList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.TextureFileList",
    .tp_doc = PyDoc_STR("TextureFileList"),
    .tp_basicsize = sizeof(TextureFileList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &TextureFileList_Mapping,
};

static PyObject *TextureFileList_from(ufbx_texture_file_list list, Context *ctx) {
    TextureFileList *obj = (TextureFileList*)PyObject_CallObject((PyObject*)&TextureFileList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_shader_prop_binding_list data;
} ShaderPropBindingList;

static PyObject *ShaderPropBindingList_len(ShaderPropBindingList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ShaderPropBindingList_subscript(ShaderPropBindingList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_shader_prop_binding");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ShaderPropBindingList_Mapping = {
    .mp_length = (lenfunc)&ShaderPropBindingList_len,
    .mp_subscript = (binaryfunc)&ShaderPropBindingList_subscript,
};

static PyTypeObject ShaderPropBindingList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderPropBindingList",
    .tp_doc = PyDoc_STR("ShaderPropBindingList"),
    .tp_basicsize = sizeof(ShaderPropBindingList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ShaderPropBindingList_Mapping,
};

static PyObject *ShaderPropBindingList_from(ufbx_shader_prop_binding_list list, Context *ctx) {
    ShaderPropBindingList *obj = (ShaderPropBindingList*)PyObject_CallObject((PyObject*)&ShaderPropBindingList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_prop_override_list data;
} PropOverrideList;

static PyObject *PropOverrideList_len(PropOverrideList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *PropOverrideList_subscript(PropOverrideList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_prop_override");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods PropOverrideList_Mapping = {
    .mp_length = (lenfunc)&PropOverrideList_len,
    .mp_subscript = (binaryfunc)&PropOverrideList_subscript,
};

static PyTypeObject PropOverrideList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.PropOverrideList",
    .tp_doc = PyDoc_STR("PropOverrideList"),
    .tp_basicsize = sizeof(PropOverrideList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &PropOverrideList_Mapping,
};

static PyObject *PropOverrideList_from(ufbx_prop_override_list list, Context *ctx) {
    PropOverrideList *obj = (PropOverrideList*)PyObject_CallObject((PyObject*)&PropOverrideList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_transform_override_list data;
} TransformOverrideList;

static PyObject *TransformOverrideList_len(TransformOverrideList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *TransformOverrideList_subscript(TransformOverrideList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_transform_override");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods TransformOverrideList_Mapping = {
    .mp_length = (lenfunc)&TransformOverrideList_len,
    .mp_subscript = (binaryfunc)&TransformOverrideList_subscript,
};

static PyTypeObject TransformOverrideList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.TransformOverrideList",
    .tp_doc = PyDoc_STR("TransformOverrideList"),
    .tp_basicsize = sizeof(TransformOverrideList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &TransformOverrideList_Mapping,
};

static PyObject *TransformOverrideList_from(ufbx_transform_override_list list, Context *ctx) {
    TransformOverrideList *obj = (TransformOverrideList*)PyObject_CallObject((PyObject*)&TransformOverrideList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_anim_prop_list data;
} AnimPropList;

static PyObject *AnimPropList_len(AnimPropList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *AnimPropList_subscript(AnimPropList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_anim_prop");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods AnimPropList_Mapping = {
    .mp_length = (lenfunc)&AnimPropList_len,
    .mp_subscript = (binaryfunc)&AnimPropList_subscript,
};

static PyTypeObject AnimPropList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimPropList",
    .tp_doc = PyDoc_STR("AnimPropList"),
    .tp_basicsize = sizeof(AnimPropList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &AnimPropList_Mapping,
};

static PyObject *AnimPropList_from(ufbx_anim_prop_list list, Context *ctx) {
    AnimPropList *obj = (AnimPropList*)PyObject_CallObject((PyObject*)&AnimPropList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_keyframe_list data;
} KeyframeList;

static PyObject *KeyframeList_len(KeyframeList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *KeyframeList_subscript(KeyframeList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_keyframe");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods KeyframeList_Mapping = {
    .mp_length = (lenfunc)&KeyframeList_len,
    .mp_subscript = (binaryfunc)&KeyframeList_subscript,
};

static PyTypeObject KeyframeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.KeyframeList",
    .tp_doc = PyDoc_STR("KeyframeList"),
    .tp_basicsize = sizeof(KeyframeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &KeyframeList_Mapping,
};

static PyObject *KeyframeList_from(ufbx_keyframe_list list, Context *ctx) {
    KeyframeList *obj = (KeyframeList*)PyObject_CallObject((PyObject*)&KeyframeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_constraint_target_list data;
} ConstraintTargetList;

static PyObject *ConstraintTargetList_len(ConstraintTargetList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ConstraintTargetList_subscript(ConstraintTargetList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_constraint_target");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ConstraintTargetList_Mapping = {
    .mp_length = (lenfunc)&ConstraintTargetList_len,
    .mp_subscript = (binaryfunc)&ConstraintTargetList_subscript,
};

static PyTypeObject ConstraintTargetList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstraintTargetList",
    .tp_doc = PyDoc_STR("ConstraintTargetList"),
    .tp_basicsize = sizeof(ConstraintTargetList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ConstraintTargetList_Mapping,
};

static PyObject *ConstraintTargetList_from(ufbx_constraint_target_list list, Context *ctx) {
    ConstraintTargetList *obj = (ConstraintTargetList*)PyObject_CallObject((PyObject*)&ConstraintTargetList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_bone_pose_list data;
} BonePoseList;

static PyObject *BonePoseList_len(BonePoseList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BonePoseList_subscript(BonePoseList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_bone_pose");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BonePoseList_Mapping = {
    .mp_length = (lenfunc)&BonePoseList_len,
    .mp_subscript = (binaryfunc)&BonePoseList_subscript,
};

static PyTypeObject BonePoseList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BonePoseList",
    .tp_doc = PyDoc_STR("BonePoseList"),
    .tp_basicsize = sizeof(BonePoseList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BonePoseList_Mapping,
};

static PyObject *BonePoseList_from(ufbx_bone_pose_list list, Context *ctx) {
    BonePoseList *obj = (BonePoseList*)PyObject_CallObject((PyObject*)&BonePoseList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_name_element_list data;
} NameElementList;

static PyObject *NameElementList_len(NameElementList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *NameElementList_subscript(NameElementList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_name_element");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods NameElementList_Mapping = {
    .mp_length = (lenfunc)&NameElementList_len,
    .mp_subscript = (binaryfunc)&NameElementList_subscript,
};

static PyTypeObject NameElementList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NameElementList",
    .tp_doc = PyDoc_STR("NameElementList"),
    .tp_basicsize = sizeof(NameElementList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &NameElementList_Mapping,
};

static PyObject *NameElementList_from(ufbx_name_element_list list, Context *ctx) {
    NameElementList *obj = (NameElementList*)PyObject_CallObject((PyObject*)&NameElementList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_warning_list data;
} WarningList;

static PyObject *WarningList_len(WarningList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *WarningList_subscript(WarningList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_warning");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods WarningList_Mapping = {
    .mp_length = (lenfunc)&WarningList_len,
    .mp_subscript = (binaryfunc)&WarningList_subscript,
};

static PyTypeObject WarningList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.WarningList",
    .tp_doc = PyDoc_STR("WarningList"),
    .tp_basicsize = sizeof(WarningList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &WarningList_Mapping,
};

static PyObject *WarningList_from(ufbx_warning_list list, Context *ctx) {
    WarningList *obj = (WarningList*)PyObject_CallObject((PyObject*)&WarningList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_baked_vec3_list data;
} BakedVec3List;

static PyObject *BakedVec3List_len(BakedVec3List *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BakedVec3List_subscript(BakedVec3List *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_baked_vec3");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BakedVec3List_Mapping = {
    .mp_length = (lenfunc)&BakedVec3List_len,
    .mp_subscript = (binaryfunc)&BakedVec3List_subscript,
};

static PyTypeObject BakedVec3List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedVec3List",
    .tp_doc = PyDoc_STR("BakedVec3List"),
    .tp_basicsize = sizeof(BakedVec3List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BakedVec3List_Mapping,
};

static PyObject *BakedVec3List_from(ufbx_baked_vec3_list list, Context *ctx) {
    BakedVec3List *obj = (BakedVec3List*)PyObject_CallObject((PyObject*)&BakedVec3List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_baked_quat_list data;
} BakedQuatList;

static PyObject *BakedQuatList_len(BakedQuatList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BakedQuatList_subscript(BakedQuatList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_baked_quat");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BakedQuatList_Mapping = {
    .mp_length = (lenfunc)&BakedQuatList_len,
    .mp_subscript = (binaryfunc)&BakedQuatList_subscript,
};

static PyTypeObject BakedQuatList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedQuatList",
    .tp_doc = PyDoc_STR("BakedQuatList"),
    .tp_basicsize = sizeof(BakedQuatList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BakedQuatList_Mapping,
};

static PyObject *BakedQuatList_from(ufbx_baked_quat_list list, Context *ctx) {
    BakedQuatList *obj = (BakedQuatList*)PyObject_CallObject((PyObject*)&BakedQuatList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_baked_node_list data;
} BakedNodeList;

static PyObject *BakedNodeList_len(BakedNodeList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BakedNodeList_subscript(BakedNodeList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_baked_node");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BakedNodeList_Mapping = {
    .mp_length = (lenfunc)&BakedNodeList_len,
    .mp_subscript = (binaryfunc)&BakedNodeList_subscript,
};

static PyTypeObject BakedNodeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedNodeList",
    .tp_doc = PyDoc_STR("BakedNodeList"),
    .tp_basicsize = sizeof(BakedNodeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BakedNodeList_Mapping,
};

static PyObject *BakedNodeList_from(ufbx_baked_node_list list, Context *ctx) {
    BakedNodeList *obj = (BakedNodeList*)PyObject_CallObject((PyObject*)&BakedNodeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_baked_prop_list data;
} BakedPropList;

static PyObject *BakedPropList_len(BakedPropList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BakedPropList_subscript(BakedPropList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_baked_prop");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BakedPropList_Mapping = {
    .mp_length = (lenfunc)&BakedPropList_len,
    .mp_subscript = (binaryfunc)&BakedPropList_subscript,
};

static PyTypeObject BakedPropList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedPropList",
    .tp_doc = PyDoc_STR("BakedPropList"),
    .tp_basicsize = sizeof(BakedPropList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BakedPropList_Mapping,
};

static PyObject *BakedPropList_from(ufbx_baked_prop_list list, Context *ctx) {
    BakedPropList *obj = (BakedPropList*)PyObject_CallObject((PyObject*)&BakedPropList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_baked_element_list data;
} BakedElementList;

static PyObject *BakedElementList_len(BakedElementList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *BakedElementList_subscript(BakedElementList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_baked_element");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods BakedElementList_Mapping = {
    .mp_length = (lenfunc)&BakedElementList_len,
    .mp_subscript = (binaryfunc)&BakedElementList_subscript,
};

static PyTypeObject BakedElementList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedElementList",
    .tp_doc = PyDoc_STR("BakedElementList"),
    .tp_basicsize = sizeof(BakedElementList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &BakedElementList_Mapping,
};

static PyObject *BakedElementList_from(ufbx_baked_element_list list, Context *ctx) {
    BakedElementList *obj = (BakedElementList*)PyObject_CallObject((PyObject*)&BakedElementList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_const_uint32_list data;
} ConstUint32List;

static PyObject *ConstUint32List_len(ConstUint32List *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ConstUint32List_subscript(ConstUint32List *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return PyLong_FromUnsignedLong((unsigned long)self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ConstUint32List_Mapping = {
    .mp_length = (lenfunc)&ConstUint32List_len,
    .mp_subscript = (binaryfunc)&ConstUint32List_subscript,
};

static PyTypeObject ConstUint32List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstUint32List",
    .tp_doc = PyDoc_STR("ConstUint32List"),
    .tp_basicsize = sizeof(ConstUint32List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ConstUint32List_Mapping,
};

static PyObject *ConstUint32List_from(ufbx_const_uint32_list list, Context *ctx) {
    ConstUint32List *obj = (ConstUint32List*)PyObject_CallObject((PyObject*)&ConstUint32List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_const_real_list data;
} ConstRealList;

static PyObject *ConstRealList_len(ConstRealList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ConstRealList_subscript(ConstRealList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return PyFloat_FromDouble(self->data.data[index]);
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ConstRealList_Mapping = {
    .mp_length = (lenfunc)&ConstRealList_len,
    .mp_subscript = (binaryfunc)&ConstRealList_subscript,
};

static PyTypeObject ConstRealList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstRealList",
    .tp_doc = PyDoc_STR("ConstRealList"),
    .tp_basicsize = sizeof(ConstRealList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ConstRealList_Mapping,
};

static PyObject *ConstRealList_from(ufbx_const_real_list list, Context *ctx) {
    ConstRealList *obj = (ConstRealList*)PyObject_CallObject((PyObject*)&ConstRealList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_const_prop_override_desc_list data;
} ConstPropOverrideDescList;

static PyObject *ConstPropOverrideDescList_len(ConstPropOverrideDescList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ConstPropOverrideDescList_subscript(ConstPropOverrideDescList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_prop_override_desc");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ConstPropOverrideDescList_Mapping = {
    .mp_length = (lenfunc)&ConstPropOverrideDescList_len,
    .mp_subscript = (binaryfunc)&ConstPropOverrideDescList_subscript,
};

static PyTypeObject ConstPropOverrideDescList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstPropOverrideDescList",
    .tp_doc = PyDoc_STR("ConstPropOverrideDescList"),
    .tp_basicsize = sizeof(ConstPropOverrideDescList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ConstPropOverrideDescList_Mapping,
};

static PyObject *ConstPropOverrideDescList_from(ufbx_const_prop_override_desc_list list, Context *ctx) {
    ConstPropOverrideDescList *obj = (ConstPropOverrideDescList*)PyObject_CallObject((PyObject*)&ConstPropOverrideDescList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    PyObject *count;
    ufbx_const_transform_override_list data;
} ConstTransformOverrideList;

static PyObject *ConstTransformOverrideList_len(ConstTransformOverrideList *self, PyObject *key) {
    return Py_NewRef(self->count);
}

static PyObject *ConstTransformOverrideList_subscript(ConstTransformOverrideList *self, PyObject *key) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    if (PyLong_Check(key)) {
        size_t count = self->data.count;
        Py_ssize_t index = PyLong_AsSsize_t(key);
        if (index == -1 && PyErr_Occurred()) return NULL;
        if (index < 0) index += (Py_ssize_t)count;
        if (index < 0 || (size_t)index >= count) {
            PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
            return NULL;
        }
        return to_pyobject_todo("ufbx_transform_override");
    } else if (PySlice_Check(key)) {
        return pyobject_todo("todo: slicing");
    } else {
        PyErr_SetString(PyExc_TypeError, "expected integer or slice");
        return NULL;
    }
}

static PyMappingMethods ConstTransformOverrideList_Mapping = {
    .mp_length = (lenfunc)&ConstTransformOverrideList_len,
    .mp_subscript = (binaryfunc)&ConstTransformOverrideList_subscript,
};

static PyTypeObject ConstTransformOverrideList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstTransformOverrideList",
    .tp_doc = PyDoc_STR("ConstTransformOverrideList"),
    .tp_basicsize = sizeof(ConstTransformOverrideList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_as_mapping = &ConstTransformOverrideList_Mapping,
};

static PyObject *ConstTransformOverrideList_from(ufbx_const_transform_override_list list, Context *ctx) {
    ConstTransformOverrideList *obj = (ConstTransformOverrideList*)PyObject_CallObject((PyObject*)&ConstTransformOverrideList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->count = PyLong_FromSize_t(list.count);
    obj->data = list;
    return (PyObject*)obj;
}

#define SLOT_COUNT_VOID_LIST 2
enum {
    SLOT_VOID_LIST__DATA,
    SLOT_VOID_LIST__COUNT,
};

typedef struct {
    PyObject_HEAD
    ufbx_void_list *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_VOID_LIST];
} VoidList;

static PyObject *VoidList_get_data(VoidList *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VOID_LIST__DATA];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("void*");
    self->slots[SLOT_VOID_LIST__DATA] = slot;
    return Py_NewRef(slot);
}

static PyObject *VoidList_get_count(VoidList *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VOID_LIST__COUNT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->count);
    self->slots[SLOT_VOID_LIST__COUNT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef VoidList_getset[] = {
    { "data", (getter)VoidList_get_data, NULL, "data" },
    { "count", (getter)VoidList_get_count, NULL, "count" },
    { NULL },
};

static PyTypeObject VoidList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.VoidList",
    .tp_doc = PyDoc_STR("VoidList"),
    .tp_basicsize = sizeof(VoidList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = VoidList_getset,
};

#define SLOT_COUNT_DOM_VALUE 5
enum {
    SLOT_DOM_VALUE__TYPE,
    SLOT_DOM_VALUE__VALUE_STR,
    SLOT_DOM_VALUE__VALUE_BLOB,
    SLOT_DOM_VALUE__VALUE_INT,
    SLOT_DOM_VALUE__VALUE_FLOAT,
};

typedef struct {
    PyObject_HEAD
    ufbx_dom_value *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_DOM_VALUE];
} DomValue;

static PyObject *DomValue_get_type(DomValue *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DOM_VALUE__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_dom_value_type");
    self->slots[SLOT_DOM_VALUE__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *DomValue_get_value_str(DomValue *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DOM_VALUE__VALUE_STR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->value_str);
    self->slots[SLOT_DOM_VALUE__VALUE_STR] = slot;
    return Py_NewRef(slot);
}

static PyObject *DomValue_get_value_blob(DomValue *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DOM_VALUE__VALUE_BLOB];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->value_blob);
    self->slots[SLOT_DOM_VALUE__VALUE_BLOB] = slot;
    return Py_NewRef(slot);
}

static PyObject *DomValue_get_value_int(DomValue *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DOM_VALUE__VALUE_INT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromLongLong((long long)self->data->value_int);
    self->slots[SLOT_DOM_VALUE__VALUE_INT] = slot;
    return Py_NewRef(slot);
}

static PyObject *DomValue_get_value_float(DomValue *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DOM_VALUE__VALUE_FLOAT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->value_float);
    self->slots[SLOT_DOM_VALUE__VALUE_FLOAT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef DomValue_getset[] = {
    { "type", (getter)DomValue_get_type, NULL, "type" },
    { "value_str", (getter)DomValue_get_value_str, NULL, "value_str" },
    { "value_blob", (getter)DomValue_get_value_blob, NULL, "value_blob" },
    { "value_int", (getter)DomValue_get_value_int, NULL, "value_int" },
    { "value_float", (getter)DomValue_get_value_float, NULL, "value_float" },
    { NULL },
};

static PyTypeObject DomValue_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DomValue",
    .tp_doc = PyDoc_STR("DomValue"),
    .tp_basicsize = sizeof(DomValue),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = DomValue_getset,
};

#define SLOT_COUNT_DOM_NODE 3
enum {
    SLOT_DOM_NODE__NAME,
    SLOT_DOM_NODE__CHILDREN,
    SLOT_DOM_NODE__VALUES,
};

typedef struct {
    PyObject_HEAD
    ufbx_dom_node *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_DOM_NODE];
} DomNode;

static PyObject *DomNode_get_name(DomNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DOM_NODE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_DOM_NODE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *DomNode_get_children(DomNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DOM_NODE__CHILDREN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = DomNodeList_from(self->data->children, self->ctx);
    self->slots[SLOT_DOM_NODE__CHILDREN] = slot;
    return Py_NewRef(slot);
}

static PyObject *DomNode_get_values(DomNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DOM_NODE__VALUES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = DomValueList_from(self->data->values, self->ctx);
    self->slots[SLOT_DOM_NODE__VALUES] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef DomNode_getset[] = {
    { "name", (getter)DomNode_get_name, NULL, "name" },
    { "children", (getter)DomNode_get_children, NULL, "children" },
    { "values", (getter)DomNode_get_values, NULL, "values" },
    { NULL },
};

static PyTypeObject DomNode_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DomNode",
    .tp_doc = PyDoc_STR("DomNode"),
    .tp_basicsize = sizeof(DomNode),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = DomNode_getset,
};

#define SLOT_COUNT_PROP 6
enum {
    SLOT_PROP__NAME,
    SLOT_PROP__TYPE,
    SLOT_PROP__FLAGS,
    SLOT_PROP__VALUE_STR,
    SLOT_PROP__VALUE_BLOB,
    SLOT_PROP__VALUE_INT,
};

typedef struct {
    PyObject_HEAD
    ufbx_prop *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_PROP];
} Prop;

static PyObject *Prop_get_name(Prop *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_PROP__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Prop_get_type(Prop *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_prop_type");
    self->slots[SLOT_PROP__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Prop_get_flags(Prop *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP__FLAGS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_prop_flags");
    self->slots[SLOT_PROP__FLAGS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Prop_get_value_str(Prop *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP__VALUE_STR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->value_str);
    self->slots[SLOT_PROP__VALUE_STR] = slot;
    return Py_NewRef(slot);
}

static PyObject *Prop_get_value_blob(Prop *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP__VALUE_BLOB];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->value_blob);
    self->slots[SLOT_PROP__VALUE_BLOB] = slot;
    return Py_NewRef(slot);
}

static PyObject *Prop_get_value_int(Prop *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP__VALUE_INT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromLongLong((long long)self->data->value_int);
    self->slots[SLOT_PROP__VALUE_INT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Prop_getset[] = {
    { "name", (getter)Prop_get_name, NULL, "name" },
    { "type", (getter)Prop_get_type, NULL, "type" },
    { "flags", (getter)Prop_get_flags, NULL, "flags" },
    { "value_str", (getter)Prop_get_value_str, NULL, "value_str" },
    { "value_blob", (getter)Prop_get_value_blob, NULL, "value_blob" },
    { "value_int", (getter)Prop_get_value_int, NULL, "value_int" },
    { NULL },
};

static PyTypeObject Prop_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Prop",
    .tp_doc = PyDoc_STR("Prop"),
    .tp_basicsize = sizeof(Prop),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Prop_getset,
};

#define SLOT_COUNT_PROPS 3
enum {
    SLOT_PROPS__PROPS,
    SLOT_PROPS__NUM_ANIMATED,
    SLOT_PROPS__DEFAULTS,
};

typedef struct {
    PyObject_HEAD
    ufbx_props *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_PROPS];
} Props;

static PyObject *Props_get_props(Props *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROPS__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PropList_from(self->data->props, self->ctx);
    self->slots[SLOT_PROPS__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Props_get_num_animated(Props *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROPS__NUM_ANIMATED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_animated);
    self->slots[SLOT_PROPS__NUM_ANIMATED] = slot;
    return Py_NewRef(slot);
}

static PyObject *Props_get_defaults(Props *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROPS__DEFAULTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_props?*");
    self->slots[SLOT_PROPS__DEFAULTS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Props_getset[] = {
    { "props", (getter)Props_get_props, NULL, "props" },
    { "num_animated", (getter)Props_get_num_animated, NULL, "num_animated" },
    { "defaults", (getter)Props_get_defaults, NULL, "defaults" },
    { NULL },
};

static PyTypeObject Props_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Props",
    .tp_doc = PyDoc_STR("Props"),
    .tp_basicsize = sizeof(Props),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Props_getset,
};

#define SLOT_COUNT_CONNECTION 4
enum {
    SLOT_CONNECTION__SRC,
    SLOT_CONNECTION__DST,
    SLOT_CONNECTION__SRC_PROP,
    SLOT_CONNECTION__DST_PROP,
};

typedef struct {
    PyObject_HEAD
    ufbx_connection *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_CONNECTION];
} Connection;

static PyObject *Connection_get_src(Connection *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONNECTION__SRC];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_element*");
    self->slots[SLOT_CONNECTION__SRC] = slot;
    return Py_NewRef(slot);
}

static PyObject *Connection_get_dst(Connection *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONNECTION__DST];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_element*");
    self->slots[SLOT_CONNECTION__DST] = slot;
    return Py_NewRef(slot);
}

static PyObject *Connection_get_src_prop(Connection *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONNECTION__SRC_PROP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->src_prop);
    self->slots[SLOT_CONNECTION__SRC_PROP] = slot;
    return Py_NewRef(slot);
}

static PyObject *Connection_get_dst_prop(Connection *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONNECTION__DST_PROP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->dst_prop);
    self->slots[SLOT_CONNECTION__DST_PROP] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Connection_getset[] = {
    { "src", (getter)Connection_get_src, NULL, "src" },
    { "dst", (getter)Connection_get_dst, NULL, "dst" },
    { "src_prop", (getter)Connection_get_src_prop, NULL, "src_prop" },
    { "dst_prop", (getter)Connection_get_dst_prop, NULL, "dst_prop" },
    { NULL },
};

static PyTypeObject Connection_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Connection",
    .tp_doc = PyDoc_STR("Connection"),
    .tp_basicsize = sizeof(Connection),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Connection_getset,
};

#define SLOT_COUNT_ELEMENT 10
enum {
    SLOT_ELEMENT__NAME,
    SLOT_ELEMENT__PROPS,
    SLOT_ELEMENT__ELEMENT_ID,
    SLOT_ELEMENT__TYPED_ID,
    SLOT_ELEMENT__INSTANCES,
    SLOT_ELEMENT__TYPE,
    SLOT_ELEMENT__CONNECTIONS_SRC,
    SLOT_ELEMENT__CONNECTIONS_DST,
    SLOT_ELEMENT__DOM_NODE,
    SLOT_ELEMENT__SCENE,
};

typedef struct {
    PyObject_HEAD
    ufbx_element *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_ELEMENT];
} Element;

static PyObject *Element_get_name(Element *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ELEMENT__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_ELEMENT__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Element_get_props(Element *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ELEMENT__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_props");
    self->slots[SLOT_ELEMENT__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Element_get_element_id(Element *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ELEMENT__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_ELEMENT__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Element_get_typed_id(Element *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ELEMENT__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_ELEMENT__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Element_get_instances(Element *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ELEMENT__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_ELEMENT__INSTANCES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Element_get_type(Element *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ELEMENT__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_element_type");
    self->slots[SLOT_ELEMENT__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Element_get_connections_src(Element *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ELEMENT__CONNECTIONS_SRC];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ConnectionList_from(self->data->connections_src, self->ctx);
    self->slots[SLOT_ELEMENT__CONNECTIONS_SRC] = slot;
    return Py_NewRef(slot);
}

static PyObject *Element_get_connections_dst(Element *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ELEMENT__CONNECTIONS_DST];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ConnectionList_from(self->data->connections_dst, self->ctx);
    self->slots[SLOT_ELEMENT__CONNECTIONS_DST] = slot;
    return Py_NewRef(slot);
}

static PyObject *Element_get_dom_node(Element *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ELEMENT__DOM_NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_dom_node?*");
    self->slots[SLOT_ELEMENT__DOM_NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Element_get_scene(Element *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ELEMENT__SCENE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_scene*");
    self->slots[SLOT_ELEMENT__SCENE] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Element_getset[] = {
    { "name", (getter)Element_get_name, NULL, "name" },
    { "props", (getter)Element_get_props, NULL, "props" },
    { "element_id", (getter)Element_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Element_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)Element_get_instances, NULL, "instances" },
    { "type", (getter)Element_get_type, NULL, "type" },
    { "connections_src", (getter)Element_get_connections_src, NULL, "connections_src" },
    { "connections_dst", (getter)Element_get_connections_dst, NULL, "connections_dst" },
    { "dom_node", (getter)Element_get_dom_node, NULL, "dom_node" },
    { "scene", (getter)Element_get_scene, NULL, "scene" },
    { NULL },
};

static PyTypeObject Element_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Element",
    .tp_doc = PyDoc_STR("Element"),
    .tp_basicsize = sizeof(Element),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Element_getset,
};

#define SLOT_COUNT_UNKNOWN 3
enum {
    SLOT_UNKNOWN__TYPE,
    SLOT_UNKNOWN__SUPER_TYPE,
    SLOT_UNKNOWN__SUB_TYPE,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_unknown *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_UNKNOWN];
} Unknown;

static PyObject *Unknown_get_type(Unknown *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UNKNOWN__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->type);
    self->slots[SLOT_UNKNOWN__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Unknown_get_super_type(Unknown *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UNKNOWN__SUPER_TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->super_type);
    self->slots[SLOT_UNKNOWN__SUPER_TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Unknown_get_sub_type(Unknown *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UNKNOWN__SUB_TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->sub_type);
    self->slots[SLOT_UNKNOWN__SUB_TYPE] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Unknown_getset[] = {
    { "type", (getter)Unknown_get_type, NULL, "type" },
    { "super_type", (getter)Unknown_get_super_type, NULL, "super_type" },
    { "sub_type", (getter)Unknown_get_sub_type, NULL, "sub_type" },
    { NULL },
};

static PyTypeObject Unknown_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Unknown",
    .tp_doc = PyDoc_STR("Unknown"),
    .tp_basicsize = sizeof(Unknown),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Unknown_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_NODE 42
enum {
    SLOT_NODE__PARENT,
    SLOT_NODE__CHILDREN,
    SLOT_NODE__MESH,
    SLOT_NODE__LIGHT,
    SLOT_NODE__CAMERA,
    SLOT_NODE__BONE,
    SLOT_NODE__ATTRIB,
    SLOT_NODE__GEOMETRY_TRANSFORM_HELPER,
    SLOT_NODE__SCALE_HELPER,
    SLOT_NODE__ATTRIB_TYPE,
    SLOT_NODE__ALL_ATTRIBS,
    SLOT_NODE__INHERIT_MODE,
    SLOT_NODE__ORIGINAL_INHERIT_MODE,
    SLOT_NODE__LOCAL_TRANSFORM,
    SLOT_NODE__GEOMETRY_TRANSFORM,
    SLOT_NODE__INHERIT_SCALE,
    SLOT_NODE__INHERIT_SCALE_NODE,
    SLOT_NODE__ROTATION_ORDER,
    SLOT_NODE__EULER_ROTATION,
    SLOT_NODE__NODE_TO_PARENT,
    SLOT_NODE__NODE_TO_WORLD,
    SLOT_NODE__GEOMETRY_TO_NODE,
    SLOT_NODE__GEOMETRY_TO_WORLD,
    SLOT_NODE__UNSCALED_NODE_TO_WORLD,
    SLOT_NODE__ADJUST_PRE_TRANSLATION,
    SLOT_NODE__ADJUST_PRE_ROTATION,
    SLOT_NODE__ADJUST_PRE_SCALE,
    SLOT_NODE__ADJUST_POST_ROTATION,
    SLOT_NODE__ADJUST_POST_SCALE,
    SLOT_NODE__ADJUST_TRANSLATION_SCALE,
    SLOT_NODE__ADJUST_MIRROR_AXIS,
    SLOT_NODE__MATERIALS,
    SLOT_NODE__BIND_POSE,
    SLOT_NODE__VISIBLE,
    SLOT_NODE__IS_ROOT,
    SLOT_NODE__HAS_GEOMETRY_TRANSFORM,
    SLOT_NODE__HAS_ADJUST_TRANSFORM,
    SLOT_NODE__HAS_ROOT_ADJUST_TRANSFORM,
    SLOT_NODE__IS_GEOMETRY_TRANSFORM_HELPER,
    SLOT_NODE__IS_SCALE_HELPER,
    SLOT_NODE__IS_SCALE_COMPENSATE_PARENT,
    SLOT_NODE__NODE_DEPTH,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_node *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_NODE];
} Node;

static PyObject *Node_get_parent(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__PARENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->parent, self->ctx);
    self->slots[SLOT_NODE__PARENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_children(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__CHILDREN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->children, self->ctx);
    self->slots[SLOT_NODE__CHILDREN] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_mesh(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__MESH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->mesh, self->ctx);
    self->slots[SLOT_NODE__MESH] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_light(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__LIGHT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->light, self->ctx);
    self->slots[SLOT_NODE__LIGHT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_camera(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__CAMERA];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->camera, self->ctx);
    self->slots[SLOT_NODE__CAMERA] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_bone(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__BONE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->bone, self->ctx);
    self->slots[SLOT_NODE__BONE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_attrib(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ATTRIB];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_element?*");
    self->slots[SLOT_NODE__ATTRIB] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_geometry_transform_helper(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__GEOMETRY_TRANSFORM_HELPER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->geometry_transform_helper, self->ctx);
    self->slots[SLOT_NODE__GEOMETRY_TRANSFORM_HELPER] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_scale_helper(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__SCALE_HELPER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->scale_helper, self->ctx);
    self->slots[SLOT_NODE__SCALE_HELPER] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_attrib_type(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ATTRIB_TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_element_type");
    self->slots[SLOT_NODE__ATTRIB_TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_all_attribs(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ALL_ATTRIBS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ElementList_from(self->data->all_attribs, self->ctx);
    self->slots[SLOT_NODE__ALL_ATTRIBS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_inherit_mode(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__INHERIT_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_inherit_mode");
    self->slots[SLOT_NODE__INHERIT_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_original_inherit_mode(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ORIGINAL_INHERIT_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_inherit_mode");
    self->slots[SLOT_NODE__ORIGINAL_INHERIT_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_local_transform(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__LOCAL_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Transform_from(&self->data->local_transform);
    self->slots[SLOT_NODE__LOCAL_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_geometry_transform(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__GEOMETRY_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Transform_from(&self->data->geometry_transform);
    self->slots[SLOT_NODE__GEOMETRY_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_inherit_scale(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__INHERIT_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->inherit_scale);
    self->slots[SLOT_NODE__INHERIT_SCALE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_inherit_scale_node(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__INHERIT_SCALE_NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->inherit_scale_node, self->ctx);
    self->slots[SLOT_NODE__INHERIT_SCALE_NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_rotation_order(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ROTATION_ORDER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_rotation_order");
    self->slots[SLOT_NODE__ROTATION_ORDER] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_euler_rotation(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__EULER_ROTATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->euler_rotation);
    self->slots[SLOT_NODE__EULER_ROTATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_node_to_parent(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__NODE_TO_PARENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_NODE__NODE_TO_PARENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_node_to_world(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__NODE_TO_WORLD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_NODE__NODE_TO_WORLD] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_geometry_to_node(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__GEOMETRY_TO_NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_NODE__GEOMETRY_TO_NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_geometry_to_world(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__GEOMETRY_TO_WORLD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_NODE__GEOMETRY_TO_WORLD] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_unscaled_node_to_world(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__UNSCALED_NODE_TO_WORLD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_NODE__UNSCALED_NODE_TO_WORLD] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_adjust_pre_translation(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ADJUST_PRE_TRANSLATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->adjust_pre_translation);
    self->slots[SLOT_NODE__ADJUST_PRE_TRANSLATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_adjust_pre_rotation(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ADJUST_PRE_ROTATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Quat_from(&self->data->adjust_pre_rotation);
    self->slots[SLOT_NODE__ADJUST_PRE_ROTATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_adjust_pre_scale(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ADJUST_PRE_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->adjust_pre_scale);
    self->slots[SLOT_NODE__ADJUST_PRE_SCALE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_adjust_post_rotation(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ADJUST_POST_ROTATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Quat_from(&self->data->adjust_post_rotation);
    self->slots[SLOT_NODE__ADJUST_POST_ROTATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_adjust_post_scale(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ADJUST_POST_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->adjust_post_scale);
    self->slots[SLOT_NODE__ADJUST_POST_SCALE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_adjust_translation_scale(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ADJUST_TRANSLATION_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->adjust_translation_scale);
    self->slots[SLOT_NODE__ADJUST_TRANSLATION_SCALE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_adjust_mirror_axis(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ADJUST_MIRROR_AXIS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_mirror_axis");
    self->slots[SLOT_NODE__ADJUST_MIRROR_AXIS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_materials(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__MATERIALS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialList_from(self->data->materials, self->ctx);
    self->slots[SLOT_NODE__MATERIALS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_bind_pose(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__BIND_POSE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->bind_pose, self->ctx);
    self->slots[SLOT_NODE__BIND_POSE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_visible(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__VISIBLE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->visible ? Py_True : Py_False;
    self->slots[SLOT_NODE__VISIBLE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_is_root(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__IS_ROOT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->is_root ? Py_True : Py_False;
    self->slots[SLOT_NODE__IS_ROOT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_has_geometry_transform(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__HAS_GEOMETRY_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->has_geometry_transform ? Py_True : Py_False;
    self->slots[SLOT_NODE__HAS_GEOMETRY_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_has_adjust_transform(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__HAS_ADJUST_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->has_adjust_transform ? Py_True : Py_False;
    self->slots[SLOT_NODE__HAS_ADJUST_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_has_root_adjust_transform(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__HAS_ROOT_ADJUST_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->has_root_adjust_transform ? Py_True : Py_False;
    self->slots[SLOT_NODE__HAS_ROOT_ADJUST_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_is_geometry_transform_helper(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__IS_GEOMETRY_TRANSFORM_HELPER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->is_geometry_transform_helper ? Py_True : Py_False;
    self->slots[SLOT_NODE__IS_GEOMETRY_TRANSFORM_HELPER] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_is_scale_helper(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__IS_SCALE_HELPER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->is_scale_helper ? Py_True : Py_False;
    self->slots[SLOT_NODE__IS_SCALE_HELPER] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_is_scale_compensate_parent(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__IS_SCALE_COMPENSATE_PARENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->is_scale_compensate_parent ? Py_True : Py_False;
    self->slots[SLOT_NODE__IS_SCALE_COMPENSATE_PARENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_node_depth(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__NODE_DEPTH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->node_depth);
    self->slots[SLOT_NODE__NODE_DEPTH] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Node_getset[] = {
    { "parent", (getter)Node_get_parent, NULL, "parent" },
    { "children", (getter)Node_get_children, NULL, "children" },
    { "mesh", (getter)Node_get_mesh, NULL, "mesh" },
    { "light", (getter)Node_get_light, NULL, "light" },
    { "camera", (getter)Node_get_camera, NULL, "camera" },
    { "bone", (getter)Node_get_bone, NULL, "bone" },
    { "attrib", (getter)Node_get_attrib, NULL, "attrib" },
    { "geometry_transform_helper", (getter)Node_get_geometry_transform_helper, NULL, "geometry_transform_helper" },
    { "scale_helper", (getter)Node_get_scale_helper, NULL, "scale_helper" },
    { "attrib_type", (getter)Node_get_attrib_type, NULL, "attrib_type" },
    { "all_attribs", (getter)Node_get_all_attribs, NULL, "all_attribs" },
    { "inherit_mode", (getter)Node_get_inherit_mode, NULL, "inherit_mode" },
    { "original_inherit_mode", (getter)Node_get_original_inherit_mode, NULL, "original_inherit_mode" },
    { "local_transform", (getter)Node_get_local_transform, NULL, "local_transform" },
    { "geometry_transform", (getter)Node_get_geometry_transform, NULL, "geometry_transform" },
    { "inherit_scale", (getter)Node_get_inherit_scale, NULL, "inherit_scale" },
    { "inherit_scale_node", (getter)Node_get_inherit_scale_node, NULL, "inherit_scale_node" },
    { "rotation_order", (getter)Node_get_rotation_order, NULL, "rotation_order" },
    { "euler_rotation", (getter)Node_get_euler_rotation, NULL, "euler_rotation" },
    { "node_to_parent", (getter)Node_get_node_to_parent, NULL, "node_to_parent" },
    { "node_to_world", (getter)Node_get_node_to_world, NULL, "node_to_world" },
    { "geometry_to_node", (getter)Node_get_geometry_to_node, NULL, "geometry_to_node" },
    { "geometry_to_world", (getter)Node_get_geometry_to_world, NULL, "geometry_to_world" },
    { "unscaled_node_to_world", (getter)Node_get_unscaled_node_to_world, NULL, "unscaled_node_to_world" },
    { "adjust_pre_translation", (getter)Node_get_adjust_pre_translation, NULL, "adjust_pre_translation" },
    { "adjust_pre_rotation", (getter)Node_get_adjust_pre_rotation, NULL, "adjust_pre_rotation" },
    { "adjust_pre_scale", (getter)Node_get_adjust_pre_scale, NULL, "adjust_pre_scale" },
    { "adjust_post_rotation", (getter)Node_get_adjust_post_rotation, NULL, "adjust_post_rotation" },
    { "adjust_post_scale", (getter)Node_get_adjust_post_scale, NULL, "adjust_post_scale" },
    { "adjust_translation_scale", (getter)Node_get_adjust_translation_scale, NULL, "adjust_translation_scale" },
    { "adjust_mirror_axis", (getter)Node_get_adjust_mirror_axis, NULL, "adjust_mirror_axis" },
    { "materials", (getter)Node_get_materials, NULL, "materials" },
    { "bind_pose", (getter)Node_get_bind_pose, NULL, "bind_pose" },
    { "visible", (getter)Node_get_visible, NULL, "visible" },
    { "is_root", (getter)Node_get_is_root, NULL, "is_root" },
    { "has_geometry_transform", (getter)Node_get_has_geometry_transform, NULL, "has_geometry_transform" },
    { "has_adjust_transform", (getter)Node_get_has_adjust_transform, NULL, "has_adjust_transform" },
    { "has_root_adjust_transform", (getter)Node_get_has_root_adjust_transform, NULL, "has_root_adjust_transform" },
    { "is_geometry_transform_helper", (getter)Node_get_is_geometry_transform_helper, NULL, "is_geometry_transform_helper" },
    { "is_scale_helper", (getter)Node_get_is_scale_helper, NULL, "is_scale_helper" },
    { "is_scale_compensate_parent", (getter)Node_get_is_scale_compensate_parent, NULL, "is_scale_compensate_parent" },
    { "node_depth", (getter)Node_get_node_depth, NULL, "node_depth" },
    { NULL },
};

static PyTypeObject Node_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Node",
    .tp_doc = PyDoc_STR("Node"),
    .tp_basicsize = sizeof(Node),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Node_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_VERTEX_ATTRIB 6
enum {
    SLOT_VERTEX_ATTRIB__EXISTS,
    SLOT_VERTEX_ATTRIB__VALUES,
    SLOT_VERTEX_ATTRIB__INDICES,
    SLOT_VERTEX_ATTRIB__VALUE_REALS,
    SLOT_VERTEX_ATTRIB__UNIQUE_PER_VERTEX,
    SLOT_VERTEX_ATTRIB__VALUES_W,
};

typedef struct {
    PyObject_HEAD
    ufbx_vertex_attrib *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_VERTEX_ATTRIB];
} VertexAttrib;

static PyObject *VertexAttrib_get_exists(VertexAttrib *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_ATTRIB__EXISTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->exists ? Py_True : Py_False;
    self->slots[SLOT_VERTEX_ATTRIB__EXISTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexAttrib_get_values(VertexAttrib *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_ATTRIB__VALUES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_void_list");
    self->slots[SLOT_VERTEX_ATTRIB__VALUES] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexAttrib_get_indices(VertexAttrib *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_ATTRIB__INDICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->indices, self->ctx);
    self->slots[SLOT_VERTEX_ATTRIB__INDICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexAttrib_get_value_reals(VertexAttrib *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_ATTRIB__VALUE_REALS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->value_reals);
    self->slots[SLOT_VERTEX_ATTRIB__VALUE_REALS] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexAttrib_get_unique_per_vertex(VertexAttrib *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_ATTRIB__UNIQUE_PER_VERTEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->unique_per_vertex ? Py_True : Py_False;
    self->slots[SLOT_VERTEX_ATTRIB__UNIQUE_PER_VERTEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexAttrib_get_values_w(VertexAttrib *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_ATTRIB__VALUES_W];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->values_w, self->ctx);
    self->slots[SLOT_VERTEX_ATTRIB__VALUES_W] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef VertexAttrib_getset[] = {
    { "exists", (getter)VertexAttrib_get_exists, NULL, "exists" },
    { "values", (getter)VertexAttrib_get_values, NULL, "values" },
    { "indices", (getter)VertexAttrib_get_indices, NULL, "indices" },
    { "value_reals", (getter)VertexAttrib_get_value_reals, NULL, "value_reals" },
    { "unique_per_vertex", (getter)VertexAttrib_get_unique_per_vertex, NULL, "unique_per_vertex" },
    { "values_w", (getter)VertexAttrib_get_values_w, NULL, "values_w" },
    { NULL },
};

static PyTypeObject VertexAttrib_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.VertexAttrib",
    .tp_doc = PyDoc_STR("VertexAttrib"),
    .tp_basicsize = sizeof(VertexAttrib),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = VertexAttrib_getset,
};

#define SLOT_COUNT_VERTEX_REAL 6
enum {
    SLOT_VERTEX_REAL__EXISTS,
    SLOT_VERTEX_REAL__VALUES,
    SLOT_VERTEX_REAL__INDICES,
    SLOT_VERTEX_REAL__VALUE_REALS,
    SLOT_VERTEX_REAL__UNIQUE_PER_VERTEX,
    SLOT_VERTEX_REAL__VALUES_W,
};

typedef struct {
    PyObject_HEAD
    ufbx_vertex_real *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_VERTEX_REAL];
} VertexReal;

static PyObject *VertexReal_get_exists(VertexReal *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_REAL__EXISTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->exists ? Py_True : Py_False;
    self->slots[SLOT_VERTEX_REAL__EXISTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexReal_get_values(VertexReal *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_REAL__VALUES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->values, self->ctx);
    self->slots[SLOT_VERTEX_REAL__VALUES] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexReal_get_indices(VertexReal *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_REAL__INDICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->indices, self->ctx);
    self->slots[SLOT_VERTEX_REAL__INDICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexReal_get_value_reals(VertexReal *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_REAL__VALUE_REALS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->value_reals);
    self->slots[SLOT_VERTEX_REAL__VALUE_REALS] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexReal_get_unique_per_vertex(VertexReal *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_REAL__UNIQUE_PER_VERTEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->unique_per_vertex ? Py_True : Py_False;
    self->slots[SLOT_VERTEX_REAL__UNIQUE_PER_VERTEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexReal_get_values_w(VertexReal *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_REAL__VALUES_W];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->values_w, self->ctx);
    self->slots[SLOT_VERTEX_REAL__VALUES_W] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef VertexReal_getset[] = {
    { "exists", (getter)VertexReal_get_exists, NULL, "exists" },
    { "values", (getter)VertexReal_get_values, NULL, "values" },
    { "indices", (getter)VertexReal_get_indices, NULL, "indices" },
    { "value_reals", (getter)VertexReal_get_value_reals, NULL, "value_reals" },
    { "unique_per_vertex", (getter)VertexReal_get_unique_per_vertex, NULL, "unique_per_vertex" },
    { "values_w", (getter)VertexReal_get_values_w, NULL, "values_w" },
    { NULL },
};

static PyTypeObject VertexReal_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.VertexReal",
    .tp_doc = PyDoc_STR("VertexReal"),
    .tp_basicsize = sizeof(VertexReal),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = VertexReal_getset,
};

#define SLOT_COUNT_VERTEX_VEC2 6
enum {
    SLOT_VERTEX_VEC2__EXISTS,
    SLOT_VERTEX_VEC2__VALUES,
    SLOT_VERTEX_VEC2__INDICES,
    SLOT_VERTEX_VEC2__VALUE_REALS,
    SLOT_VERTEX_VEC2__UNIQUE_PER_VERTEX,
    SLOT_VERTEX_VEC2__VALUES_W,
};

typedef struct {
    PyObject_HEAD
    ufbx_vertex_vec2 *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_VERTEX_VEC2];
} VertexVec2;

static PyObject *VertexVec2_get_exists(VertexVec2 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC2__EXISTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->exists ? Py_True : Py_False;
    self->slots[SLOT_VERTEX_VEC2__EXISTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec2_get_values(VertexVec2 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC2__VALUES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec2List_from(self->data->values, self->ctx);
    self->slots[SLOT_VERTEX_VEC2__VALUES] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec2_get_indices(VertexVec2 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC2__INDICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->indices, self->ctx);
    self->slots[SLOT_VERTEX_VEC2__INDICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec2_get_value_reals(VertexVec2 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC2__VALUE_REALS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->value_reals);
    self->slots[SLOT_VERTEX_VEC2__VALUE_REALS] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec2_get_unique_per_vertex(VertexVec2 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC2__UNIQUE_PER_VERTEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->unique_per_vertex ? Py_True : Py_False;
    self->slots[SLOT_VERTEX_VEC2__UNIQUE_PER_VERTEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec2_get_values_w(VertexVec2 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC2__VALUES_W];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->values_w, self->ctx);
    self->slots[SLOT_VERTEX_VEC2__VALUES_W] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef VertexVec2_getset[] = {
    { "exists", (getter)VertexVec2_get_exists, NULL, "exists" },
    { "values", (getter)VertexVec2_get_values, NULL, "values" },
    { "indices", (getter)VertexVec2_get_indices, NULL, "indices" },
    { "value_reals", (getter)VertexVec2_get_value_reals, NULL, "value_reals" },
    { "unique_per_vertex", (getter)VertexVec2_get_unique_per_vertex, NULL, "unique_per_vertex" },
    { "values_w", (getter)VertexVec2_get_values_w, NULL, "values_w" },
    { NULL },
};

static PyTypeObject VertexVec2_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.VertexVec2",
    .tp_doc = PyDoc_STR("VertexVec2"),
    .tp_basicsize = sizeof(VertexVec2),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = VertexVec2_getset,
};

#define SLOT_COUNT_VERTEX_VEC3 6
enum {
    SLOT_VERTEX_VEC3__EXISTS,
    SLOT_VERTEX_VEC3__VALUES,
    SLOT_VERTEX_VEC3__INDICES,
    SLOT_VERTEX_VEC3__VALUE_REALS,
    SLOT_VERTEX_VEC3__UNIQUE_PER_VERTEX,
    SLOT_VERTEX_VEC3__VALUES_W,
};

typedef struct {
    PyObject_HEAD
    ufbx_vertex_vec3 *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_VERTEX_VEC3];
} VertexVec3;

static PyObject *VertexVec3_get_exists(VertexVec3 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC3__EXISTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->exists ? Py_True : Py_False;
    self->slots[SLOT_VERTEX_VEC3__EXISTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec3_get_values(VertexVec3 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC3__VALUES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3List_from(self->data->values, self->ctx);
    self->slots[SLOT_VERTEX_VEC3__VALUES] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec3_get_indices(VertexVec3 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC3__INDICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->indices, self->ctx);
    self->slots[SLOT_VERTEX_VEC3__INDICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec3_get_value_reals(VertexVec3 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC3__VALUE_REALS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->value_reals);
    self->slots[SLOT_VERTEX_VEC3__VALUE_REALS] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec3_get_unique_per_vertex(VertexVec3 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC3__UNIQUE_PER_VERTEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->unique_per_vertex ? Py_True : Py_False;
    self->slots[SLOT_VERTEX_VEC3__UNIQUE_PER_VERTEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec3_get_values_w(VertexVec3 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC3__VALUES_W];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->values_w, self->ctx);
    self->slots[SLOT_VERTEX_VEC3__VALUES_W] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef VertexVec3_getset[] = {
    { "exists", (getter)VertexVec3_get_exists, NULL, "exists" },
    { "values", (getter)VertexVec3_get_values, NULL, "values" },
    { "indices", (getter)VertexVec3_get_indices, NULL, "indices" },
    { "value_reals", (getter)VertexVec3_get_value_reals, NULL, "value_reals" },
    { "unique_per_vertex", (getter)VertexVec3_get_unique_per_vertex, NULL, "unique_per_vertex" },
    { "values_w", (getter)VertexVec3_get_values_w, NULL, "values_w" },
    { NULL },
};

static PyTypeObject VertexVec3_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.VertexVec3",
    .tp_doc = PyDoc_STR("VertexVec3"),
    .tp_basicsize = sizeof(VertexVec3),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = VertexVec3_getset,
};

#define SLOT_COUNT_VERTEX_VEC4 6
enum {
    SLOT_VERTEX_VEC4__EXISTS,
    SLOT_VERTEX_VEC4__VALUES,
    SLOT_VERTEX_VEC4__INDICES,
    SLOT_VERTEX_VEC4__VALUE_REALS,
    SLOT_VERTEX_VEC4__UNIQUE_PER_VERTEX,
    SLOT_VERTEX_VEC4__VALUES_W,
};

typedef struct {
    PyObject_HEAD
    ufbx_vertex_vec4 *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_VERTEX_VEC4];
} VertexVec4;

static PyObject *VertexVec4_get_exists(VertexVec4 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC4__EXISTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->exists ? Py_True : Py_False;
    self->slots[SLOT_VERTEX_VEC4__EXISTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec4_get_values(VertexVec4 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC4__VALUES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec4List_from(self->data->values, self->ctx);
    self->slots[SLOT_VERTEX_VEC4__VALUES] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec4_get_indices(VertexVec4 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC4__INDICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->indices, self->ctx);
    self->slots[SLOT_VERTEX_VEC4__INDICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec4_get_value_reals(VertexVec4 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC4__VALUE_REALS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->value_reals);
    self->slots[SLOT_VERTEX_VEC4__VALUE_REALS] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec4_get_unique_per_vertex(VertexVec4 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC4__UNIQUE_PER_VERTEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->unique_per_vertex ? Py_True : Py_False;
    self->slots[SLOT_VERTEX_VEC4__UNIQUE_PER_VERTEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexVec4_get_values_w(VertexVec4 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_VEC4__VALUES_W];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->values_w, self->ctx);
    self->slots[SLOT_VERTEX_VEC4__VALUES_W] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef VertexVec4_getset[] = {
    { "exists", (getter)VertexVec4_get_exists, NULL, "exists" },
    { "values", (getter)VertexVec4_get_values, NULL, "values" },
    { "indices", (getter)VertexVec4_get_indices, NULL, "indices" },
    { "value_reals", (getter)VertexVec4_get_value_reals, NULL, "value_reals" },
    { "unique_per_vertex", (getter)VertexVec4_get_unique_per_vertex, NULL, "unique_per_vertex" },
    { "values_w", (getter)VertexVec4_get_values_w, NULL, "values_w" },
    { NULL },
};

static PyTypeObject VertexVec4_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.VertexVec4",
    .tp_doc = PyDoc_STR("VertexVec4"),
    .tp_basicsize = sizeof(VertexVec4),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = VertexVec4_getset,
};

#define SLOT_COUNT_UV_SET 5
enum {
    SLOT_UV_SET__NAME,
    SLOT_UV_SET__INDEX,
    SLOT_UV_SET__VERTEX_UV,
    SLOT_UV_SET__VERTEX_TANGENT,
    SLOT_UV_SET__VERTEX_BITANGENT,
};

typedef struct {
    PyObject_HEAD
    ufbx_uv_set *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_UV_SET];
} UvSet;

static PyObject *UvSet_get_name(UvSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UV_SET__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_UV_SET__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *UvSet_get_index(UvSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UV_SET__INDEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->index);
    self->slots[SLOT_UV_SET__INDEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *UvSet_get_vertex_uv(UvSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UV_SET__VERTEX_UV];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec2");
    self->slots[SLOT_UV_SET__VERTEX_UV] = slot;
    return Py_NewRef(slot);
}

static PyObject *UvSet_get_vertex_tangent(UvSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UV_SET__VERTEX_TANGENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec3");
    self->slots[SLOT_UV_SET__VERTEX_TANGENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *UvSet_get_vertex_bitangent(UvSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UV_SET__VERTEX_BITANGENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec3");
    self->slots[SLOT_UV_SET__VERTEX_BITANGENT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef UvSet_getset[] = {
    { "name", (getter)UvSet_get_name, NULL, "name" },
    { "index", (getter)UvSet_get_index, NULL, "index" },
    { "vertex_uv", (getter)UvSet_get_vertex_uv, NULL, "vertex_uv" },
    { "vertex_tangent", (getter)UvSet_get_vertex_tangent, NULL, "vertex_tangent" },
    { "vertex_bitangent", (getter)UvSet_get_vertex_bitangent, NULL, "vertex_bitangent" },
    { NULL },
};

static PyTypeObject UvSet_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.UvSet",
    .tp_doc = PyDoc_STR("UvSet"),
    .tp_basicsize = sizeof(UvSet),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = UvSet_getset,
};

#define SLOT_COUNT_COLOR_SET 3
enum {
    SLOT_COLOR_SET__NAME,
    SLOT_COLOR_SET__INDEX,
    SLOT_COLOR_SET__VERTEX_COLOR,
};

typedef struct {
    PyObject_HEAD
    ufbx_color_set *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_COLOR_SET];
} ColorSet;

static PyObject *ColorSet_get_name(ColorSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_COLOR_SET__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_COLOR_SET__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *ColorSet_get_index(ColorSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_COLOR_SET__INDEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->index);
    self->slots[SLOT_COLOR_SET__INDEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *ColorSet_get_vertex_color(ColorSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_COLOR_SET__VERTEX_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec4");
    self->slots[SLOT_COLOR_SET__VERTEX_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef ColorSet_getset[] = {
    { "name", (getter)ColorSet_get_name, NULL, "name" },
    { "index", (getter)ColorSet_get_index, NULL, "index" },
    { "vertex_color", (getter)ColorSet_get_vertex_color, NULL, "vertex_color" },
    { NULL },
};

static PyTypeObject ColorSet_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ColorSet",
    .tp_doc = PyDoc_STR("ColorSet"),
    .tp_basicsize = sizeof(ColorSet),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = ColorSet_getset,
};

#define SLOT_COUNT_MESH_PART 7
enum {
    SLOT_MESH_PART__INDEX,
    SLOT_MESH_PART__NUM_FACES,
    SLOT_MESH_PART__NUM_TRIANGLES,
    SLOT_MESH_PART__NUM_EMPTY_FACES,
    SLOT_MESH_PART__NUM_POINT_FACES,
    SLOT_MESH_PART__NUM_LINE_FACES,
    SLOT_MESH_PART__FACE_INDICES,
};

typedef struct {
    PyObject_HEAD
    ufbx_mesh_part *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_MESH_PART];
} MeshPart;

static PyObject *MeshPart_get_index(MeshPart *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH_PART__INDEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->index);
    self->slots[SLOT_MESH_PART__INDEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *MeshPart_get_num_faces(MeshPart *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH_PART__NUM_FACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_faces);
    self->slots[SLOT_MESH_PART__NUM_FACES] = slot;
    return Py_NewRef(slot);
}

static PyObject *MeshPart_get_num_triangles(MeshPart *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH_PART__NUM_TRIANGLES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_triangles);
    self->slots[SLOT_MESH_PART__NUM_TRIANGLES] = slot;
    return Py_NewRef(slot);
}

static PyObject *MeshPart_get_num_empty_faces(MeshPart *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH_PART__NUM_EMPTY_FACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_empty_faces);
    self->slots[SLOT_MESH_PART__NUM_EMPTY_FACES] = slot;
    return Py_NewRef(slot);
}

static PyObject *MeshPart_get_num_point_faces(MeshPart *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH_PART__NUM_POINT_FACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_point_faces);
    self->slots[SLOT_MESH_PART__NUM_POINT_FACES] = slot;
    return Py_NewRef(slot);
}

static PyObject *MeshPart_get_num_line_faces(MeshPart *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH_PART__NUM_LINE_FACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_line_faces);
    self->slots[SLOT_MESH_PART__NUM_LINE_FACES] = slot;
    return Py_NewRef(slot);
}

static PyObject *MeshPart_get_face_indices(MeshPart *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH_PART__FACE_INDICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->face_indices, self->ctx);
    self->slots[SLOT_MESH_PART__FACE_INDICES] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef MeshPart_getset[] = {
    { "index", (getter)MeshPart_get_index, NULL, "index" },
    { "num_faces", (getter)MeshPart_get_num_faces, NULL, "num_faces" },
    { "num_triangles", (getter)MeshPart_get_num_triangles, NULL, "num_triangles" },
    { "num_empty_faces", (getter)MeshPart_get_num_empty_faces, NULL, "num_empty_faces" },
    { "num_point_faces", (getter)MeshPart_get_num_point_faces, NULL, "num_point_faces" },
    { "num_line_faces", (getter)MeshPart_get_num_line_faces, NULL, "num_line_faces" },
    { "face_indices", (getter)MeshPart_get_face_indices, NULL, "face_indices" },
    { NULL },
};

static PyTypeObject MeshPart_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MeshPart",
    .tp_doc = PyDoc_STR("MeshPart"),
    .tp_basicsize = sizeof(MeshPart),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = MeshPart_getset,
};

#define SLOT_COUNT_FACE_GROUP 2
enum {
    SLOT_FACE_GROUP__ID,
    SLOT_FACE_GROUP__NAME,
};

typedef struct {
    PyObject_HEAD
    ufbx_face_group *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_FACE_GROUP];
} FaceGroup;

static PyObject *FaceGroup_get_id(FaceGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_FACE_GROUP__ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromLong((long)self->data->id);
    self->slots[SLOT_FACE_GROUP__ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *FaceGroup_get_name(FaceGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_FACE_GROUP__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_FACE_GROUP__NAME] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef FaceGroup_getset[] = {
    { "id", (getter)FaceGroup_get_id, NULL, "id" },
    { "name", (getter)FaceGroup_get_name, NULL, "name" },
    { NULL },
};

static PyTypeObject FaceGroup_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.FaceGroup",
    .tp_doc = PyDoc_STR("FaceGroup"),
    .tp_basicsize = sizeof(FaceGroup),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = FaceGroup_getset,
};

#define SLOT_COUNT_SUBDIVISION_WEIGHT_RANGE 2
enum {
    SLOT_SUBDIVISION_WEIGHT_RANGE__WEIGHT_BEGIN,
    SLOT_SUBDIVISION_WEIGHT_RANGE__NUM_WEIGHTS,
};

typedef struct {
    PyObject_HEAD
    ufbx_subdivision_weight_range *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_SUBDIVISION_WEIGHT_RANGE];
} SubdivisionWeightRange;

static PyObject *SubdivisionWeightRange_get_weight_begin(SubdivisionWeightRange *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_WEIGHT_RANGE__WEIGHT_BEGIN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->weight_begin);
    self->slots[SLOT_SUBDIVISION_WEIGHT_RANGE__WEIGHT_BEGIN] = slot;
    return Py_NewRef(slot);
}

static PyObject *SubdivisionWeightRange_get_num_weights(SubdivisionWeightRange *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_WEIGHT_RANGE__NUM_WEIGHTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->num_weights);
    self->slots[SLOT_SUBDIVISION_WEIGHT_RANGE__NUM_WEIGHTS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef SubdivisionWeightRange_getset[] = {
    { "weight_begin", (getter)SubdivisionWeightRange_get_weight_begin, NULL, "weight_begin" },
    { "num_weights", (getter)SubdivisionWeightRange_get_num_weights, NULL, "num_weights" },
    { NULL },
};

static PyTypeObject SubdivisionWeightRange_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SubdivisionWeightRange",
    .tp_doc = PyDoc_STR("SubdivisionWeightRange"),
    .tp_basicsize = sizeof(SubdivisionWeightRange),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = SubdivisionWeightRange_getset,
};

#define SLOT_COUNT_SUBDIVISION_WEIGHT 2
enum {
    SLOT_SUBDIVISION_WEIGHT__WEIGHT,
    SLOT_SUBDIVISION_WEIGHT__INDEX,
};

typedef struct {
    PyObject_HEAD
    ufbx_subdivision_weight *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_SUBDIVISION_WEIGHT];
} SubdivisionWeight;

static PyObject *SubdivisionWeight_get_weight(SubdivisionWeight *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_WEIGHT__WEIGHT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->weight);
    self->slots[SLOT_SUBDIVISION_WEIGHT__WEIGHT] = slot;
    return Py_NewRef(slot);
}

static PyObject *SubdivisionWeight_get_index(SubdivisionWeight *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_WEIGHT__INDEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->index);
    self->slots[SLOT_SUBDIVISION_WEIGHT__INDEX] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef SubdivisionWeight_getset[] = {
    { "weight", (getter)SubdivisionWeight_get_weight, NULL, "weight" },
    { "index", (getter)SubdivisionWeight_get_index, NULL, "index" },
    { NULL },
};

static PyTypeObject SubdivisionWeight_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SubdivisionWeight",
    .tp_doc = PyDoc_STR("SubdivisionWeight"),
    .tp_basicsize = sizeof(SubdivisionWeight),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = SubdivisionWeight_getset,
};

#define SLOT_COUNT_SUBDIVISION_RESULT 8
enum {
    SLOT_SUBDIVISION_RESULT__RESULT_MEMORY_USED,
    SLOT_SUBDIVISION_RESULT__TEMP_MEMORY_USED,
    SLOT_SUBDIVISION_RESULT__RESULT_ALLOCS,
    SLOT_SUBDIVISION_RESULT__TEMP_ALLOCS,
    SLOT_SUBDIVISION_RESULT__SOURCE_VERTEX_RANGES,
    SLOT_SUBDIVISION_RESULT__SOURCE_VERTEX_WEIGHTS,
    SLOT_SUBDIVISION_RESULT__SKIN_CLUSTER_RANGES,
    SLOT_SUBDIVISION_RESULT__SKIN_CLUSTER_WEIGHTS,
};

typedef struct {
    PyObject_HEAD
    ufbx_subdivision_result *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_SUBDIVISION_RESULT];
} SubdivisionResult;

static PyObject *SubdivisionResult_get_result_memory_used(SubdivisionResult *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_RESULT__RESULT_MEMORY_USED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->result_memory_used);
    self->slots[SLOT_SUBDIVISION_RESULT__RESULT_MEMORY_USED] = slot;
    return Py_NewRef(slot);
}

static PyObject *SubdivisionResult_get_temp_memory_used(SubdivisionResult *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_RESULT__TEMP_MEMORY_USED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->temp_memory_used);
    self->slots[SLOT_SUBDIVISION_RESULT__TEMP_MEMORY_USED] = slot;
    return Py_NewRef(slot);
}

static PyObject *SubdivisionResult_get_result_allocs(SubdivisionResult *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_RESULT__RESULT_ALLOCS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->result_allocs);
    self->slots[SLOT_SUBDIVISION_RESULT__RESULT_ALLOCS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SubdivisionResult_get_temp_allocs(SubdivisionResult *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_RESULT__TEMP_ALLOCS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->temp_allocs);
    self->slots[SLOT_SUBDIVISION_RESULT__TEMP_ALLOCS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SubdivisionResult_get_source_vertex_ranges(SubdivisionResult *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_RESULT__SOURCE_VERTEX_RANGES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SubdivisionWeightRangeList_from(self->data->source_vertex_ranges, self->ctx);
    self->slots[SLOT_SUBDIVISION_RESULT__SOURCE_VERTEX_RANGES] = slot;
    return Py_NewRef(slot);
}

static PyObject *SubdivisionResult_get_source_vertex_weights(SubdivisionResult *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_RESULT__SOURCE_VERTEX_WEIGHTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SubdivisionWeightList_from(self->data->source_vertex_weights, self->ctx);
    self->slots[SLOT_SUBDIVISION_RESULT__SOURCE_VERTEX_WEIGHTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SubdivisionResult_get_skin_cluster_ranges(SubdivisionResult *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_RESULT__SKIN_CLUSTER_RANGES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SubdivisionWeightRangeList_from(self->data->skin_cluster_ranges, self->ctx);
    self->slots[SLOT_SUBDIVISION_RESULT__SKIN_CLUSTER_RANGES] = slot;
    return Py_NewRef(slot);
}

static PyObject *SubdivisionResult_get_skin_cluster_weights(SubdivisionResult *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SUBDIVISION_RESULT__SKIN_CLUSTER_WEIGHTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SubdivisionWeightList_from(self->data->skin_cluster_weights, self->ctx);
    self->slots[SLOT_SUBDIVISION_RESULT__SKIN_CLUSTER_WEIGHTS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef SubdivisionResult_getset[] = {
    { "result_memory_used", (getter)SubdivisionResult_get_result_memory_used, NULL, "result_memory_used" },
    { "temp_memory_used", (getter)SubdivisionResult_get_temp_memory_used, NULL, "temp_memory_used" },
    { "result_allocs", (getter)SubdivisionResult_get_result_allocs, NULL, "result_allocs" },
    { "temp_allocs", (getter)SubdivisionResult_get_temp_allocs, NULL, "temp_allocs" },
    { "source_vertex_ranges", (getter)SubdivisionResult_get_source_vertex_ranges, NULL, "source_vertex_ranges" },
    { "source_vertex_weights", (getter)SubdivisionResult_get_source_vertex_weights, NULL, "source_vertex_weights" },
    { "skin_cluster_ranges", (getter)SubdivisionResult_get_skin_cluster_ranges, NULL, "skin_cluster_ranges" },
    { "skin_cluster_weights", (getter)SubdivisionResult_get_skin_cluster_weights, NULL, "skin_cluster_weights" },
    { NULL },
};

static PyTypeObject SubdivisionResult_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SubdivisionResult",
    .tp_doc = PyDoc_STR("SubdivisionResult"),
    .tp_basicsize = sizeof(SubdivisionResult),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = SubdivisionResult_getset,
};

#define SLOT_COUNT_MESH 52
enum {
    SLOT_MESH__NUM_VERTICES,
    SLOT_MESH__NUM_INDICES,
    SLOT_MESH__NUM_FACES,
    SLOT_MESH__NUM_TRIANGLES,
    SLOT_MESH__NUM_EDGES,
    SLOT_MESH__MAX_FACE_TRIANGLES,
    SLOT_MESH__NUM_EMPTY_FACES,
    SLOT_MESH__NUM_POINT_FACES,
    SLOT_MESH__NUM_LINE_FACES,
    SLOT_MESH__FACES,
    SLOT_MESH__FACE_SMOOTHING,
    SLOT_MESH__FACE_MATERIAL,
    SLOT_MESH__FACE_GROUP,
    SLOT_MESH__FACE_HOLE,
    SLOT_MESH__EDGES,
    SLOT_MESH__EDGE_SMOOTHING,
    SLOT_MESH__EDGE_CREASE,
    SLOT_MESH__EDGE_VISIBILITY,
    SLOT_MESH__VERTEX_INDICES,
    SLOT_MESH__VERTICES,
    SLOT_MESH__VERTEX_FIRST_INDEX,
    SLOT_MESH__VERTEX_POSITION,
    SLOT_MESH__VERTEX_NORMAL,
    SLOT_MESH__VERTEX_UV,
    SLOT_MESH__VERTEX_TANGENT,
    SLOT_MESH__VERTEX_BITANGENT,
    SLOT_MESH__VERTEX_COLOR,
    SLOT_MESH__VERTEX_CREASE,
    SLOT_MESH__UV_SETS,
    SLOT_MESH__COLOR_SETS,
    SLOT_MESH__MATERIALS,
    SLOT_MESH__FACE_GROUPS,
    SLOT_MESH__MATERIAL_PARTS,
    SLOT_MESH__FACE_GROUP_PARTS,
    SLOT_MESH__MATERIAL_PART_USAGE_ORDER,
    SLOT_MESH__SKINNED_IS_LOCAL,
    SLOT_MESH__SKINNED_POSITION,
    SLOT_MESH__SKINNED_NORMAL,
    SLOT_MESH__SKIN_DEFORMERS,
    SLOT_MESH__BLEND_DEFORMERS,
    SLOT_MESH__CACHE_DEFORMERS,
    SLOT_MESH__ALL_DEFORMERS,
    SLOT_MESH__SUBDIVISION_PREVIEW_LEVELS,
    SLOT_MESH__SUBDIVISION_RENDER_LEVELS,
    SLOT_MESH__SUBDIVISION_DISPLAY_MODE,
    SLOT_MESH__SUBDIVISION_BOUNDARY,
    SLOT_MESH__SUBDIVISION_UV_BOUNDARY,
    SLOT_MESH__REVERSED_WINDING,
    SLOT_MESH__GENERATED_NORMALS,
    SLOT_MESH__SUBDIVISION_EVALUATED,
    SLOT_MESH__SUBDIVISION_RESULT,
    SLOT_MESH__FROM_TESSELLATED_NURBS,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_mesh *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_MESH];
} Mesh;

static PyObject *Mesh_get_num_vertices(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__NUM_VERTICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_vertices);
    self->slots[SLOT_MESH__NUM_VERTICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_num_indices(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__NUM_INDICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_indices);
    self->slots[SLOT_MESH__NUM_INDICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_num_faces(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__NUM_FACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_faces);
    self->slots[SLOT_MESH__NUM_FACES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_num_triangles(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__NUM_TRIANGLES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_triangles);
    self->slots[SLOT_MESH__NUM_TRIANGLES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_num_edges(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__NUM_EDGES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_edges);
    self->slots[SLOT_MESH__NUM_EDGES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_max_face_triangles(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__MAX_FACE_TRIANGLES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->max_face_triangles);
    self->slots[SLOT_MESH__MAX_FACE_TRIANGLES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_num_empty_faces(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__NUM_EMPTY_FACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_empty_faces);
    self->slots[SLOT_MESH__NUM_EMPTY_FACES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_num_point_faces(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__NUM_POINT_FACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_point_faces);
    self->slots[SLOT_MESH__NUM_POINT_FACES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_num_line_faces(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__NUM_LINE_FACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_line_faces);
    self->slots[SLOT_MESH__NUM_LINE_FACES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_faces(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__FACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = FaceList_from(self->data->faces, self->ctx);
    self->slots[SLOT_MESH__FACES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_face_smoothing(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__FACE_SMOOTHING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BoolList_from(self->data->face_smoothing, self->ctx);
    self->slots[SLOT_MESH__FACE_SMOOTHING] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_face_material(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__FACE_MATERIAL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->face_material, self->ctx);
    self->slots[SLOT_MESH__FACE_MATERIAL] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_face_group(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__FACE_GROUP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->face_group, self->ctx);
    self->slots[SLOT_MESH__FACE_GROUP] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_face_hole(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__FACE_HOLE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BoolList_from(self->data->face_hole, self->ctx);
    self->slots[SLOT_MESH__FACE_HOLE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_edges(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__EDGES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = EdgeList_from(self->data->edges, self->ctx);
    self->slots[SLOT_MESH__EDGES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_edge_smoothing(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__EDGE_SMOOTHING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BoolList_from(self->data->edge_smoothing, self->ctx);
    self->slots[SLOT_MESH__EDGE_SMOOTHING] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_edge_crease(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__EDGE_CREASE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->edge_crease, self->ctx);
    self->slots[SLOT_MESH__EDGE_CREASE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_edge_visibility(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__EDGE_VISIBILITY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BoolList_from(self->data->edge_visibility, self->ctx);
    self->slots[SLOT_MESH__EDGE_VISIBILITY] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_indices(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_INDICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->vertex_indices, self->ctx);
    self->slots[SLOT_MESH__VERTEX_INDICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertices(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3List_from(self->data->vertices, self->ctx);
    self->slots[SLOT_MESH__VERTICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_first_index(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_FIRST_INDEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->vertex_first_index, self->ctx);
    self->slots[SLOT_MESH__VERTEX_FIRST_INDEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_position(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_POSITION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec3");
    self->slots[SLOT_MESH__VERTEX_POSITION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_normal(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_NORMAL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec3");
    self->slots[SLOT_MESH__VERTEX_NORMAL] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_uv(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_UV];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec2");
    self->slots[SLOT_MESH__VERTEX_UV] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_tangent(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_TANGENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec3");
    self->slots[SLOT_MESH__VERTEX_TANGENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_bitangent(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_BITANGENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec3");
    self->slots[SLOT_MESH__VERTEX_BITANGENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_color(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec4");
    self->slots[SLOT_MESH__VERTEX_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_crease(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_CREASE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_real");
    self->slots[SLOT_MESH__VERTEX_CREASE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_uv_sets(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__UV_SETS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = UvSetList_from(self->data->uv_sets, self->ctx);
    self->slots[SLOT_MESH__UV_SETS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_color_sets(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__COLOR_SETS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ColorSetList_from(self->data->color_sets, self->ctx);
    self->slots[SLOT_MESH__COLOR_SETS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_materials(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__MATERIALS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialList_from(self->data->materials, self->ctx);
    self->slots[SLOT_MESH__MATERIALS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_face_groups(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__FACE_GROUPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = FaceGroupList_from(self->data->face_groups, self->ctx);
    self->slots[SLOT_MESH__FACE_GROUPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_material_parts(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__MATERIAL_PARTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MeshPartList_from(self->data->material_parts, self->ctx);
    self->slots[SLOT_MESH__MATERIAL_PARTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_face_group_parts(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__FACE_GROUP_PARTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MeshPartList_from(self->data->face_group_parts, self->ctx);
    self->slots[SLOT_MESH__FACE_GROUP_PARTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_material_part_usage_order(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__MATERIAL_PART_USAGE_ORDER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->material_part_usage_order, self->ctx);
    self->slots[SLOT_MESH__MATERIAL_PART_USAGE_ORDER] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_skinned_is_local(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SKINNED_IS_LOCAL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->skinned_is_local ? Py_True : Py_False;
    self->slots[SLOT_MESH__SKINNED_IS_LOCAL] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_skinned_position(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SKINNED_POSITION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec3");
    self->slots[SLOT_MESH__SKINNED_POSITION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_skinned_normal(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SKINNED_NORMAL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_vertex_vec3");
    self->slots[SLOT_MESH__SKINNED_NORMAL] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_skin_deformers(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SKIN_DEFORMERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SkinDeformerList_from(self->data->skin_deformers, self->ctx);
    self->slots[SLOT_MESH__SKIN_DEFORMERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_blend_deformers(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__BLEND_DEFORMERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BlendDeformerList_from(self->data->blend_deformers, self->ctx);
    self->slots[SLOT_MESH__BLEND_DEFORMERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_cache_deformers(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__CACHE_DEFORMERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = CacheDeformerList_from(self->data->cache_deformers, self->ctx);
    self->slots[SLOT_MESH__CACHE_DEFORMERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_all_deformers(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__ALL_DEFORMERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ElementList_from(self->data->all_deformers, self->ctx);
    self->slots[SLOT_MESH__ALL_DEFORMERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_subdivision_preview_levels(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SUBDIVISION_PREVIEW_LEVELS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->subdivision_preview_levels);
    self->slots[SLOT_MESH__SUBDIVISION_PREVIEW_LEVELS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_subdivision_render_levels(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SUBDIVISION_RENDER_LEVELS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->subdivision_render_levels);
    self->slots[SLOT_MESH__SUBDIVISION_RENDER_LEVELS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_subdivision_display_mode(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SUBDIVISION_DISPLAY_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_subdivision_display_mode");
    self->slots[SLOT_MESH__SUBDIVISION_DISPLAY_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_subdivision_boundary(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SUBDIVISION_BOUNDARY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_subdivision_boundary");
    self->slots[SLOT_MESH__SUBDIVISION_BOUNDARY] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_subdivision_uv_boundary(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SUBDIVISION_UV_BOUNDARY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_subdivision_boundary");
    self->slots[SLOT_MESH__SUBDIVISION_UV_BOUNDARY] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_reversed_winding(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__REVERSED_WINDING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->reversed_winding ? Py_True : Py_False;
    self->slots[SLOT_MESH__REVERSED_WINDING] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_generated_normals(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__GENERATED_NORMALS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->generated_normals ? Py_True : Py_False;
    self->slots[SLOT_MESH__GENERATED_NORMALS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_subdivision_evaluated(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SUBDIVISION_EVALUATED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->subdivision_evaluated ? Py_True : Py_False;
    self->slots[SLOT_MESH__SUBDIVISION_EVALUATED] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_subdivision_result(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SUBDIVISION_RESULT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_subdivision_result?*");
    self->slots[SLOT_MESH__SUBDIVISION_RESULT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_from_tessellated_nurbs(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__FROM_TESSELLATED_NURBS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->from_tessellated_nurbs ? Py_True : Py_False;
    self->slots[SLOT_MESH__FROM_TESSELLATED_NURBS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Mesh_getset[] = {
    { "num_vertices", (getter)Mesh_get_num_vertices, NULL, "num_vertices" },
    { "num_indices", (getter)Mesh_get_num_indices, NULL, "num_indices" },
    { "num_faces", (getter)Mesh_get_num_faces, NULL, "num_faces" },
    { "num_triangles", (getter)Mesh_get_num_triangles, NULL, "num_triangles" },
    { "num_edges", (getter)Mesh_get_num_edges, NULL, "num_edges" },
    { "max_face_triangles", (getter)Mesh_get_max_face_triangles, NULL, "max_face_triangles" },
    { "num_empty_faces", (getter)Mesh_get_num_empty_faces, NULL, "num_empty_faces" },
    { "num_point_faces", (getter)Mesh_get_num_point_faces, NULL, "num_point_faces" },
    { "num_line_faces", (getter)Mesh_get_num_line_faces, NULL, "num_line_faces" },
    { "faces", (getter)Mesh_get_faces, NULL, "faces" },
    { "face_smoothing", (getter)Mesh_get_face_smoothing, NULL, "face_smoothing" },
    { "face_material", (getter)Mesh_get_face_material, NULL, "face_material" },
    { "face_group", (getter)Mesh_get_face_group, NULL, "face_group" },
    { "face_hole", (getter)Mesh_get_face_hole, NULL, "face_hole" },
    { "edges", (getter)Mesh_get_edges, NULL, "edges" },
    { "edge_smoothing", (getter)Mesh_get_edge_smoothing, NULL, "edge_smoothing" },
    { "edge_crease", (getter)Mesh_get_edge_crease, NULL, "edge_crease" },
    { "edge_visibility", (getter)Mesh_get_edge_visibility, NULL, "edge_visibility" },
    { "vertex_indices", (getter)Mesh_get_vertex_indices, NULL, "vertex_indices" },
    { "vertices", (getter)Mesh_get_vertices, NULL, "vertices" },
    { "vertex_first_index", (getter)Mesh_get_vertex_first_index, NULL, "vertex_first_index" },
    { "vertex_position", (getter)Mesh_get_vertex_position, NULL, "vertex_position" },
    { "vertex_normal", (getter)Mesh_get_vertex_normal, NULL, "vertex_normal" },
    { "vertex_uv", (getter)Mesh_get_vertex_uv, NULL, "vertex_uv" },
    { "vertex_tangent", (getter)Mesh_get_vertex_tangent, NULL, "vertex_tangent" },
    { "vertex_bitangent", (getter)Mesh_get_vertex_bitangent, NULL, "vertex_bitangent" },
    { "vertex_color", (getter)Mesh_get_vertex_color, NULL, "vertex_color" },
    { "vertex_crease", (getter)Mesh_get_vertex_crease, NULL, "vertex_crease" },
    { "uv_sets", (getter)Mesh_get_uv_sets, NULL, "uv_sets" },
    { "color_sets", (getter)Mesh_get_color_sets, NULL, "color_sets" },
    { "materials", (getter)Mesh_get_materials, NULL, "materials" },
    { "face_groups", (getter)Mesh_get_face_groups, NULL, "face_groups" },
    { "material_parts", (getter)Mesh_get_material_parts, NULL, "material_parts" },
    { "face_group_parts", (getter)Mesh_get_face_group_parts, NULL, "face_group_parts" },
    { "material_part_usage_order", (getter)Mesh_get_material_part_usage_order, NULL, "material_part_usage_order" },
    { "skinned_is_local", (getter)Mesh_get_skinned_is_local, NULL, "skinned_is_local" },
    { "skinned_position", (getter)Mesh_get_skinned_position, NULL, "skinned_position" },
    { "skinned_normal", (getter)Mesh_get_skinned_normal, NULL, "skinned_normal" },
    { "skin_deformers", (getter)Mesh_get_skin_deformers, NULL, "skin_deformers" },
    { "blend_deformers", (getter)Mesh_get_blend_deformers, NULL, "blend_deformers" },
    { "cache_deformers", (getter)Mesh_get_cache_deformers, NULL, "cache_deformers" },
    { "all_deformers", (getter)Mesh_get_all_deformers, NULL, "all_deformers" },
    { "subdivision_preview_levels", (getter)Mesh_get_subdivision_preview_levels, NULL, "subdivision_preview_levels" },
    { "subdivision_render_levels", (getter)Mesh_get_subdivision_render_levels, NULL, "subdivision_render_levels" },
    { "subdivision_display_mode", (getter)Mesh_get_subdivision_display_mode, NULL, "subdivision_display_mode" },
    { "subdivision_boundary", (getter)Mesh_get_subdivision_boundary, NULL, "subdivision_boundary" },
    { "subdivision_uv_boundary", (getter)Mesh_get_subdivision_uv_boundary, NULL, "subdivision_uv_boundary" },
    { "reversed_winding", (getter)Mesh_get_reversed_winding, NULL, "reversed_winding" },
    { "generated_normals", (getter)Mesh_get_generated_normals, NULL, "generated_normals" },
    { "subdivision_evaluated", (getter)Mesh_get_subdivision_evaluated, NULL, "subdivision_evaluated" },
    { "subdivision_result", (getter)Mesh_get_subdivision_result, NULL, "subdivision_result" },
    { "from_tessellated_nurbs", (getter)Mesh_get_from_tessellated_nurbs, NULL, "from_tessellated_nurbs" },
    { NULL },
};

static PyTypeObject Mesh_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Mesh",
    .tp_doc = PyDoc_STR("Mesh"),
    .tp_basicsize = sizeof(Mesh),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Mesh_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_LIGHT 10
enum {
    SLOT_LIGHT__COLOR,
    SLOT_LIGHT__INTENSITY,
    SLOT_LIGHT__LOCAL_DIRECTION,
    SLOT_LIGHT__TYPE,
    SLOT_LIGHT__DECAY,
    SLOT_LIGHT__AREA_SHAPE,
    SLOT_LIGHT__INNER_ANGLE,
    SLOT_LIGHT__OUTER_ANGLE,
    SLOT_LIGHT__CAST_LIGHT,
    SLOT_LIGHT__CAST_SHADOWS,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_light *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_LIGHT];
} Light;

static PyObject *Light_get_color(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->color);
    self->slots[SLOT_LIGHT__COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_intensity(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__INTENSITY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->intensity);
    self->slots[SLOT_LIGHT__INTENSITY] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_local_direction(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__LOCAL_DIRECTION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->local_direction);
    self->slots[SLOT_LIGHT__LOCAL_DIRECTION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_type(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_light_type");
    self->slots[SLOT_LIGHT__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_decay(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__DECAY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_light_decay");
    self->slots[SLOT_LIGHT__DECAY] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_area_shape(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__AREA_SHAPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_light_area_shape");
    self->slots[SLOT_LIGHT__AREA_SHAPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_inner_angle(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__INNER_ANGLE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->inner_angle);
    self->slots[SLOT_LIGHT__INNER_ANGLE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_outer_angle(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__OUTER_ANGLE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->outer_angle);
    self->slots[SLOT_LIGHT__OUTER_ANGLE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_cast_light(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__CAST_LIGHT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->cast_light ? Py_True : Py_False;
    self->slots[SLOT_LIGHT__CAST_LIGHT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_cast_shadows(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__CAST_SHADOWS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->cast_shadows ? Py_True : Py_False;
    self->slots[SLOT_LIGHT__CAST_SHADOWS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Light_getset[] = {
    { "color", (getter)Light_get_color, NULL, "color" },
    { "intensity", (getter)Light_get_intensity, NULL, "intensity" },
    { "local_direction", (getter)Light_get_local_direction, NULL, "local_direction" },
    { "type", (getter)Light_get_type, NULL, "type" },
    { "decay", (getter)Light_get_decay, NULL, "decay" },
    { "area_shape", (getter)Light_get_area_shape, NULL, "area_shape" },
    { "inner_angle", (getter)Light_get_inner_angle, NULL, "inner_angle" },
    { "outer_angle", (getter)Light_get_outer_angle, NULL, "outer_angle" },
    { "cast_light", (getter)Light_get_cast_light, NULL, "cast_light" },
    { "cast_shadows", (getter)Light_get_cast_shadows, NULL, "cast_shadows" },
    { NULL },
};

static PyTypeObject Light_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Light",
    .tp_doc = PyDoc_STR("Light"),
    .tp_basicsize = sizeof(Light),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Light_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_CAMERA 20
enum {
    SLOT_CAMERA__PROJECTION_MODE,
    SLOT_CAMERA__RESOLUTION_IS_PIXELS,
    SLOT_CAMERA__RESOLUTION,
    SLOT_CAMERA__FIELD_OF_VIEW_DEG,
    SLOT_CAMERA__FIELD_OF_VIEW_TAN,
    SLOT_CAMERA__ORTHOGRAPHIC_EXTENT,
    SLOT_CAMERA__ORTHOGRAPHIC_SIZE,
    SLOT_CAMERA__PROJECTION_PLANE,
    SLOT_CAMERA__ASPECT_RATIO,
    SLOT_CAMERA__NEAR_PLANE,
    SLOT_CAMERA__FAR_PLANE,
    SLOT_CAMERA__PROJECTION_AXES,
    SLOT_CAMERA__ASPECT_MODE,
    SLOT_CAMERA__APERTURE_MODE,
    SLOT_CAMERA__GATE_FIT,
    SLOT_CAMERA__APERTURE_FORMAT,
    SLOT_CAMERA__FOCAL_LENGTH_MM,
    SLOT_CAMERA__FILM_SIZE_INCH,
    SLOT_CAMERA__APERTURE_SIZE_INCH,
    SLOT_CAMERA__SQUEEZE_RATIO,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_camera *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_CAMERA];
} Camera;

static PyObject *Camera_get_projection_mode(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__PROJECTION_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_projection_mode");
    self->slots[SLOT_CAMERA__PROJECTION_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_resolution_is_pixels(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__RESOLUTION_IS_PIXELS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->resolution_is_pixels ? Py_True : Py_False;
    self->slots[SLOT_CAMERA__RESOLUTION_IS_PIXELS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_resolution(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__RESOLUTION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec2_from(&self->data->resolution);
    self->slots[SLOT_CAMERA__RESOLUTION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_field_of_view_deg(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__FIELD_OF_VIEW_DEG];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec2_from(&self->data->field_of_view_deg);
    self->slots[SLOT_CAMERA__FIELD_OF_VIEW_DEG] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_field_of_view_tan(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__FIELD_OF_VIEW_TAN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec2_from(&self->data->field_of_view_tan);
    self->slots[SLOT_CAMERA__FIELD_OF_VIEW_TAN] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_orthographic_extent(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__ORTHOGRAPHIC_EXTENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->orthographic_extent);
    self->slots[SLOT_CAMERA__ORTHOGRAPHIC_EXTENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_orthographic_size(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__ORTHOGRAPHIC_SIZE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec2_from(&self->data->orthographic_size);
    self->slots[SLOT_CAMERA__ORTHOGRAPHIC_SIZE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_projection_plane(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__PROJECTION_PLANE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec2_from(&self->data->projection_plane);
    self->slots[SLOT_CAMERA__PROJECTION_PLANE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_aspect_ratio(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__ASPECT_RATIO];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->aspect_ratio);
    self->slots[SLOT_CAMERA__ASPECT_RATIO] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_near_plane(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__NEAR_PLANE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->near_plane);
    self->slots[SLOT_CAMERA__NEAR_PLANE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_far_plane(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__FAR_PLANE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->far_plane);
    self->slots[SLOT_CAMERA__FAR_PLANE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_projection_axes(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__PROJECTION_AXES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_coordinate_axes");
    self->slots[SLOT_CAMERA__PROJECTION_AXES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_aspect_mode(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__ASPECT_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_aspect_mode");
    self->slots[SLOT_CAMERA__ASPECT_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_aperture_mode(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__APERTURE_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_aperture_mode");
    self->slots[SLOT_CAMERA__APERTURE_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_gate_fit(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__GATE_FIT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_gate_fit");
    self->slots[SLOT_CAMERA__GATE_FIT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_aperture_format(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__APERTURE_FORMAT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_aperture_format");
    self->slots[SLOT_CAMERA__APERTURE_FORMAT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_focal_length_mm(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__FOCAL_LENGTH_MM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->focal_length_mm);
    self->slots[SLOT_CAMERA__FOCAL_LENGTH_MM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_film_size_inch(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__FILM_SIZE_INCH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec2_from(&self->data->film_size_inch);
    self->slots[SLOT_CAMERA__FILM_SIZE_INCH] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_aperture_size_inch(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__APERTURE_SIZE_INCH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec2_from(&self->data->aperture_size_inch);
    self->slots[SLOT_CAMERA__APERTURE_SIZE_INCH] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_squeeze_ratio(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__SQUEEZE_RATIO];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->squeeze_ratio);
    self->slots[SLOT_CAMERA__SQUEEZE_RATIO] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Camera_getset[] = {
    { "projection_mode", (getter)Camera_get_projection_mode, NULL, "projection_mode" },
    { "resolution_is_pixels", (getter)Camera_get_resolution_is_pixels, NULL, "resolution_is_pixels" },
    { "resolution", (getter)Camera_get_resolution, NULL, "resolution" },
    { "field_of_view_deg", (getter)Camera_get_field_of_view_deg, NULL, "field_of_view_deg" },
    { "field_of_view_tan", (getter)Camera_get_field_of_view_tan, NULL, "field_of_view_tan" },
    { "orthographic_extent", (getter)Camera_get_orthographic_extent, NULL, "orthographic_extent" },
    { "orthographic_size", (getter)Camera_get_orthographic_size, NULL, "orthographic_size" },
    { "projection_plane", (getter)Camera_get_projection_plane, NULL, "projection_plane" },
    { "aspect_ratio", (getter)Camera_get_aspect_ratio, NULL, "aspect_ratio" },
    { "near_plane", (getter)Camera_get_near_plane, NULL, "near_plane" },
    { "far_plane", (getter)Camera_get_far_plane, NULL, "far_plane" },
    { "projection_axes", (getter)Camera_get_projection_axes, NULL, "projection_axes" },
    { "aspect_mode", (getter)Camera_get_aspect_mode, NULL, "aspect_mode" },
    { "aperture_mode", (getter)Camera_get_aperture_mode, NULL, "aperture_mode" },
    { "gate_fit", (getter)Camera_get_gate_fit, NULL, "gate_fit" },
    { "aperture_format", (getter)Camera_get_aperture_format, NULL, "aperture_format" },
    { "focal_length_mm", (getter)Camera_get_focal_length_mm, NULL, "focal_length_mm" },
    { "film_size_inch", (getter)Camera_get_film_size_inch, NULL, "film_size_inch" },
    { "aperture_size_inch", (getter)Camera_get_aperture_size_inch, NULL, "aperture_size_inch" },
    { "squeeze_ratio", (getter)Camera_get_squeeze_ratio, NULL, "squeeze_ratio" },
    { NULL },
};

static PyTypeObject Camera_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Camera",
    .tp_doc = PyDoc_STR("Camera"),
    .tp_basicsize = sizeof(Camera),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Camera_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_BONE 3
enum {
    SLOT_BONE__RADIUS,
    SLOT_BONE__RELATIVE_LENGTH,
    SLOT_BONE__IS_ROOT,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_bone *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_BONE];
} Bone;

static PyObject *Bone_get_radius(Bone *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE__RADIUS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->radius);
    self->slots[SLOT_BONE__RADIUS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Bone_get_relative_length(Bone *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE__RELATIVE_LENGTH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->relative_length);
    self->slots[SLOT_BONE__RELATIVE_LENGTH] = slot;
    return Py_NewRef(slot);
}

static PyObject *Bone_get_is_root(Bone *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE__IS_ROOT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->is_root ? Py_True : Py_False;
    self->slots[SLOT_BONE__IS_ROOT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Bone_getset[] = {
    { "radius", (getter)Bone_get_radius, NULL, "radius" },
    { "relative_length", (getter)Bone_get_relative_length, NULL, "relative_length" },
    { "is_root", (getter)Bone_get_is_root, NULL, "is_root" },
    { NULL },
};

static PyTypeObject Bone_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Bone",
    .tp_doc = PyDoc_STR("Bone"),
    .tp_basicsize = sizeof(Bone),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Bone_getset,
    .tp_base = &Element_Type,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_empty *data;
            Context *ctx;
        };
    };
} Empty;

static PyTypeObject Empty_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Empty",
    .tp_doc = PyDoc_STR("Empty"),
    .tp_basicsize = sizeof(Empty),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_LINE_SEGMENT 2
enum {
    SLOT_LINE_SEGMENT__INDEX_BEGIN,
    SLOT_LINE_SEGMENT__NUM_INDICES,
};

typedef struct {
    PyObject_HEAD
    ufbx_line_segment *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_LINE_SEGMENT];
} LineSegment;

static PyObject *LineSegment_get_index_begin(LineSegment *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_SEGMENT__INDEX_BEGIN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->index_begin);
    self->slots[SLOT_LINE_SEGMENT__INDEX_BEGIN] = slot;
    return Py_NewRef(slot);
}

static PyObject *LineSegment_get_num_indices(LineSegment *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_SEGMENT__NUM_INDICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->num_indices);
    self->slots[SLOT_LINE_SEGMENT__NUM_INDICES] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef LineSegment_getset[] = {
    { "index_begin", (getter)LineSegment_get_index_begin, NULL, "index_begin" },
    { "num_indices", (getter)LineSegment_get_num_indices, NULL, "num_indices" },
    { NULL },
};

static PyTypeObject LineSegment_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LineSegment",
    .tp_doc = PyDoc_STR("LineSegment"),
    .tp_basicsize = sizeof(LineSegment),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = LineSegment_getset,
};

#define SLOT_COUNT_LINE_CURVE 5
enum {
    SLOT_LINE_CURVE__COLOR,
    SLOT_LINE_CURVE__CONTROL_POINTS,
    SLOT_LINE_CURVE__POINT_INDICES,
    SLOT_LINE_CURVE__SEGMENTS,
    SLOT_LINE_CURVE__FROM_TESSELLATED_NURBS,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_line_curve *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_LINE_CURVE];
} LineCurve;

static PyObject *LineCurve_get_color(LineCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_CURVE__COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->color);
    self->slots[SLOT_LINE_CURVE__COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *LineCurve_get_control_points(LineCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_CURVE__CONTROL_POINTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3List_from(self->data->control_points, self->ctx);
    self->slots[SLOT_LINE_CURVE__CONTROL_POINTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *LineCurve_get_point_indices(LineCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_CURVE__POINT_INDICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->point_indices, self->ctx);
    self->slots[SLOT_LINE_CURVE__POINT_INDICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *LineCurve_get_segments(LineCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_CURVE__SEGMENTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = LineSegmentList_from(self->data->segments, self->ctx);
    self->slots[SLOT_LINE_CURVE__SEGMENTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *LineCurve_get_from_tessellated_nurbs(LineCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_CURVE__FROM_TESSELLATED_NURBS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->from_tessellated_nurbs ? Py_True : Py_False;
    self->slots[SLOT_LINE_CURVE__FROM_TESSELLATED_NURBS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef LineCurve_getset[] = {
    { "color", (getter)LineCurve_get_color, NULL, "color" },
    { "control_points", (getter)LineCurve_get_control_points, NULL, "control_points" },
    { "point_indices", (getter)LineCurve_get_point_indices, NULL, "point_indices" },
    { "segments", (getter)LineCurve_get_segments, NULL, "segments" },
    { "from_tessellated_nurbs", (getter)LineCurve_get_from_tessellated_nurbs, NULL, "from_tessellated_nurbs" },
    { NULL },
};

static PyTypeObject LineCurve_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LineCurve",
    .tp_doc = PyDoc_STR("LineCurve"),
    .tp_basicsize = sizeof(LineCurve),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = LineCurve_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_NURBS_BASIS 9
enum {
    SLOT_NURBS_BASIS__ORDER,
    SLOT_NURBS_BASIS__TOPOLOGY,
    SLOT_NURBS_BASIS__KNOT_VECTOR,
    SLOT_NURBS_BASIS__T_MIN,
    SLOT_NURBS_BASIS__T_MAX,
    SLOT_NURBS_BASIS__SPANS,
    SLOT_NURBS_BASIS__IS_2D,
    SLOT_NURBS_BASIS__NUM_WRAP_CONTROL_POINTS,
    SLOT_NURBS_BASIS__VALID,
};

typedef struct {
    PyObject_HEAD
    ufbx_nurbs_basis *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_NURBS_BASIS];
} NurbsBasis;

static PyObject *NurbsBasis_get_order(NurbsBasis *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_BASIS__ORDER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->order);
    self->slots[SLOT_NURBS_BASIS__ORDER] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsBasis_get_topology(NurbsBasis *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_BASIS__TOPOLOGY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_nurbs_topology");
    self->slots[SLOT_NURBS_BASIS__TOPOLOGY] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsBasis_get_knot_vector(NurbsBasis *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_BASIS__KNOT_VECTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->knot_vector, self->ctx);
    self->slots[SLOT_NURBS_BASIS__KNOT_VECTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsBasis_get_t_min(NurbsBasis *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_BASIS__T_MIN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->t_min);
    self->slots[SLOT_NURBS_BASIS__T_MIN] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsBasis_get_t_max(NurbsBasis *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_BASIS__T_MAX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->t_max);
    self->slots[SLOT_NURBS_BASIS__T_MAX] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsBasis_get_spans(NurbsBasis *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_BASIS__SPANS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->spans, self->ctx);
    self->slots[SLOT_NURBS_BASIS__SPANS] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsBasis_get_is_2d(NurbsBasis *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_BASIS__IS_2D];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->is_2d ? Py_True : Py_False;
    self->slots[SLOT_NURBS_BASIS__IS_2D] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsBasis_get_num_wrap_control_points(NurbsBasis *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_BASIS__NUM_WRAP_CONTROL_POINTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_wrap_control_points);
    self->slots[SLOT_NURBS_BASIS__NUM_WRAP_CONTROL_POINTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsBasis_get_valid(NurbsBasis *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_BASIS__VALID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->valid ? Py_True : Py_False;
    self->slots[SLOT_NURBS_BASIS__VALID] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef NurbsBasis_getset[] = {
    { "order", (getter)NurbsBasis_get_order, NULL, "order" },
    { "topology", (getter)NurbsBasis_get_topology, NULL, "topology" },
    { "knot_vector", (getter)NurbsBasis_get_knot_vector, NULL, "knot_vector" },
    { "t_min", (getter)NurbsBasis_get_t_min, NULL, "t_min" },
    { "t_max", (getter)NurbsBasis_get_t_max, NULL, "t_max" },
    { "spans", (getter)NurbsBasis_get_spans, NULL, "spans" },
    { "is_2d", (getter)NurbsBasis_get_is_2d, NULL, "is_2d" },
    { "num_wrap_control_points", (getter)NurbsBasis_get_num_wrap_control_points, NULL, "num_wrap_control_points" },
    { "valid", (getter)NurbsBasis_get_valid, NULL, "valid" },
    { NULL },
};

static PyTypeObject NurbsBasis_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsBasis",
    .tp_doc = PyDoc_STR("NurbsBasis"),
    .tp_basicsize = sizeof(NurbsBasis),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = NurbsBasis_getset,
};

#define SLOT_COUNT_NURBS_CURVE 2
enum {
    SLOT_NURBS_CURVE__BASIS,
    SLOT_NURBS_CURVE__CONTROL_POINTS,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_nurbs_curve *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_NURBS_CURVE];
} NurbsCurve;

static PyObject *NurbsCurve_get_basis(NurbsCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_CURVE__BASIS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_nurbs_basis");
    self->slots[SLOT_NURBS_CURVE__BASIS] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsCurve_get_control_points(NurbsCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_CURVE__CONTROL_POINTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec4List_from(self->data->control_points, self->ctx);
    self->slots[SLOT_NURBS_CURVE__CONTROL_POINTS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef NurbsCurve_getset[] = {
    { "basis", (getter)NurbsCurve_get_basis, NULL, "basis" },
    { "control_points", (getter)NurbsCurve_get_control_points, NULL, "control_points" },
    { NULL },
};

static PyTypeObject NurbsCurve_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsCurve",
    .tp_doc = PyDoc_STR("NurbsCurve"),
    .tp_basicsize = sizeof(NurbsCurve),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = NurbsCurve_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_NURBS_SURFACE 9
enum {
    SLOT_NURBS_SURFACE__BASIS_U,
    SLOT_NURBS_SURFACE__BASIS_V,
    SLOT_NURBS_SURFACE__NUM_CONTROL_POINTS_U,
    SLOT_NURBS_SURFACE__NUM_CONTROL_POINTS_V,
    SLOT_NURBS_SURFACE__CONTROL_POINTS,
    SLOT_NURBS_SURFACE__SPAN_SUBDIVISION_U,
    SLOT_NURBS_SURFACE__SPAN_SUBDIVISION_V,
    SLOT_NURBS_SURFACE__FLIP_NORMALS,
    SLOT_NURBS_SURFACE__MATERIAL,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_nurbs_surface *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_NURBS_SURFACE];
} NurbsSurface;

static PyObject *NurbsSurface_get_basis_u(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__BASIS_U];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_nurbs_basis");
    self->slots[SLOT_NURBS_SURFACE__BASIS_U] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_basis_v(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__BASIS_V];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_nurbs_basis");
    self->slots[SLOT_NURBS_SURFACE__BASIS_V] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_num_control_points_u(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__NUM_CONTROL_POINTS_U];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_control_points_u);
    self->slots[SLOT_NURBS_SURFACE__NUM_CONTROL_POINTS_U] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_num_control_points_v(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__NUM_CONTROL_POINTS_V];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_control_points_v);
    self->slots[SLOT_NURBS_SURFACE__NUM_CONTROL_POINTS_V] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_control_points(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__CONTROL_POINTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec4List_from(self->data->control_points, self->ctx);
    self->slots[SLOT_NURBS_SURFACE__CONTROL_POINTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_span_subdivision_u(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__SPAN_SUBDIVISION_U];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->span_subdivision_u);
    self->slots[SLOT_NURBS_SURFACE__SPAN_SUBDIVISION_U] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_span_subdivision_v(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__SPAN_SUBDIVISION_V];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->span_subdivision_v);
    self->slots[SLOT_NURBS_SURFACE__SPAN_SUBDIVISION_V] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_flip_normals(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__FLIP_NORMALS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->flip_normals ? Py_True : Py_False;
    self->slots[SLOT_NURBS_SURFACE__FLIP_NORMALS] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_material(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__MATERIAL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->material, self->ctx);
    self->slots[SLOT_NURBS_SURFACE__MATERIAL] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef NurbsSurface_getset[] = {
    { "basis_u", (getter)NurbsSurface_get_basis_u, NULL, "basis_u" },
    { "basis_v", (getter)NurbsSurface_get_basis_v, NULL, "basis_v" },
    { "num_control_points_u", (getter)NurbsSurface_get_num_control_points_u, NULL, "num_control_points_u" },
    { "num_control_points_v", (getter)NurbsSurface_get_num_control_points_v, NULL, "num_control_points_v" },
    { "control_points", (getter)NurbsSurface_get_control_points, NULL, "control_points" },
    { "span_subdivision_u", (getter)NurbsSurface_get_span_subdivision_u, NULL, "span_subdivision_u" },
    { "span_subdivision_v", (getter)NurbsSurface_get_span_subdivision_v, NULL, "span_subdivision_v" },
    { "flip_normals", (getter)NurbsSurface_get_flip_normals, NULL, "flip_normals" },
    { "material", (getter)NurbsSurface_get_material, NULL, "material" },
    { NULL },
};

static PyTypeObject NurbsSurface_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsSurface",
    .tp_doc = PyDoc_STR("NurbsSurface"),
    .tp_basicsize = sizeof(NurbsSurface),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = NurbsSurface_getset,
    .tp_base = &Element_Type,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_nurbs_trim_surface *data;
            Context *ctx;
        };
    };
} NurbsTrimSurface;

static PyTypeObject NurbsTrimSurface_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsTrimSurface",
    .tp_doc = PyDoc_STR("NurbsTrimSurface"),
    .tp_basicsize = sizeof(NurbsTrimSurface),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_base = &Element_Type,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_nurbs_trim_boundary *data;
            Context *ctx;
        };
    };
} NurbsTrimBoundary;

static PyTypeObject NurbsTrimBoundary_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsTrimBoundary",
    .tp_doc = PyDoc_STR("NurbsTrimBoundary"),
    .tp_basicsize = sizeof(NurbsTrimBoundary),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_base = &Element_Type,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_procedural_geometry *data;
            Context *ctx;
        };
    };
} ProceduralGeometry;

static PyTypeObject ProceduralGeometry_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ProceduralGeometry",
    .tp_doc = PyDoc_STR("ProceduralGeometry"),
    .tp_basicsize = sizeof(ProceduralGeometry),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_STEREO_CAMERA 2
enum {
    SLOT_STEREO_CAMERA__LEFT,
    SLOT_STEREO_CAMERA__RIGHT,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_stereo_camera *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_STEREO_CAMERA];
} StereoCamera;

static PyObject *StereoCamera_get_left(StereoCamera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_STEREO_CAMERA__LEFT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->left, self->ctx);
    self->slots[SLOT_STEREO_CAMERA__LEFT] = slot;
    return Py_NewRef(slot);
}

static PyObject *StereoCamera_get_right(StereoCamera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_STEREO_CAMERA__RIGHT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->right, self->ctx);
    self->slots[SLOT_STEREO_CAMERA__RIGHT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef StereoCamera_getset[] = {
    { "left", (getter)StereoCamera_get_left, NULL, "left" },
    { "right", (getter)StereoCamera_get_right, NULL, "right" },
    { NULL },
};

static PyTypeObject StereoCamera_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.StereoCamera",
    .tp_doc = PyDoc_STR("StereoCamera"),
    .tp_basicsize = sizeof(StereoCamera),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = StereoCamera_getset,
    .tp_base = &Element_Type,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_camera_switcher *data;
            Context *ctx;
        };
    };
} CameraSwitcher;

static PyTypeObject CameraSwitcher_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CameraSwitcher",
    .tp_doc = PyDoc_STR("CameraSwitcher"),
    .tp_basicsize = sizeof(CameraSwitcher),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_MARKER 1
enum {
    SLOT_MARKER__TYPE,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_marker *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_MARKER];
} Marker;

static PyObject *Marker_get_type(Marker *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MARKER__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_marker_type");
    self->slots[SLOT_MARKER__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Marker_getset[] = {
    { "type", (getter)Marker_get_type, NULL, "type" },
    { NULL },
};

static PyTypeObject Marker_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Marker",
    .tp_doc = PyDoc_STR("Marker"),
    .tp_basicsize = sizeof(Marker),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Marker_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_LOD_GROUP 6
enum {
    SLOT_LOD_GROUP__RELATIVE_DISTANCES,
    SLOT_LOD_GROUP__LOD_LEVELS,
    SLOT_LOD_GROUP__IGNORE_PARENT_TRANSFORM,
    SLOT_LOD_GROUP__USE_DISTANCE_LIMIT,
    SLOT_LOD_GROUP__DISTANCE_LIMIT_MIN,
    SLOT_LOD_GROUP__DISTANCE_LIMIT_MAX,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_lod_group *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_LOD_GROUP];
} LodGroup;

static PyObject *LodGroup_get_relative_distances(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__RELATIVE_DISTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->relative_distances ? Py_True : Py_False;
    self->slots[SLOT_LOD_GROUP__RELATIVE_DISTANCES] = slot;
    return Py_NewRef(slot);
}

static PyObject *LodGroup_get_lod_levels(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__LOD_LEVELS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = LodLevelList_from(self->data->lod_levels, self->ctx);
    self->slots[SLOT_LOD_GROUP__LOD_LEVELS] = slot;
    return Py_NewRef(slot);
}

static PyObject *LodGroup_get_ignore_parent_transform(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__IGNORE_PARENT_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->ignore_parent_transform ? Py_True : Py_False;
    self->slots[SLOT_LOD_GROUP__IGNORE_PARENT_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *LodGroup_get_use_distance_limit(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__USE_DISTANCE_LIMIT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->use_distance_limit ? Py_True : Py_False;
    self->slots[SLOT_LOD_GROUP__USE_DISTANCE_LIMIT] = slot;
    return Py_NewRef(slot);
}

static PyObject *LodGroup_get_distance_limit_min(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__DISTANCE_LIMIT_MIN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->distance_limit_min);
    self->slots[SLOT_LOD_GROUP__DISTANCE_LIMIT_MIN] = slot;
    return Py_NewRef(slot);
}

static PyObject *LodGroup_get_distance_limit_max(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__DISTANCE_LIMIT_MAX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->distance_limit_max);
    self->slots[SLOT_LOD_GROUP__DISTANCE_LIMIT_MAX] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef LodGroup_getset[] = {
    { "relative_distances", (getter)LodGroup_get_relative_distances, NULL, "relative_distances" },
    { "lod_levels", (getter)LodGroup_get_lod_levels, NULL, "lod_levels" },
    { "ignore_parent_transform", (getter)LodGroup_get_ignore_parent_transform, NULL, "ignore_parent_transform" },
    { "use_distance_limit", (getter)LodGroup_get_use_distance_limit, NULL, "use_distance_limit" },
    { "distance_limit_min", (getter)LodGroup_get_distance_limit_min, NULL, "distance_limit_min" },
    { "distance_limit_max", (getter)LodGroup_get_distance_limit_max, NULL, "distance_limit_max" },
    { NULL },
};

static PyTypeObject LodGroup_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LodGroup",
    .tp_doc = PyDoc_STR("LodGroup"),
    .tp_basicsize = sizeof(LodGroup),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = LodGroup_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_SKIN_DEFORMER 8
enum {
    SLOT_SKIN_DEFORMER__SKINNING_METHOD,
    SLOT_SKIN_DEFORMER__CLUSTERS,
    SLOT_SKIN_DEFORMER__VERTICES,
    SLOT_SKIN_DEFORMER__WEIGHTS,
    SLOT_SKIN_DEFORMER__MAX_WEIGHTS_PER_VERTEX,
    SLOT_SKIN_DEFORMER__NUM_DQ_WEIGHTS,
    SLOT_SKIN_DEFORMER__DQ_VERTICES,
    SLOT_SKIN_DEFORMER__DQ_WEIGHTS,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_skin_deformer *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_SKIN_DEFORMER];
} SkinDeformer;

static PyObject *SkinDeformer_get_skinning_method(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__SKINNING_METHOD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_skinning_method");
    self->slots[SLOT_SKIN_DEFORMER__SKINNING_METHOD] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinDeformer_get_clusters(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__CLUSTERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SkinClusterList_from(self->data->clusters, self->ctx);
    self->slots[SLOT_SKIN_DEFORMER__CLUSTERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinDeformer_get_vertices(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__VERTICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SkinVertexList_from(self->data->vertices, self->ctx);
    self->slots[SLOT_SKIN_DEFORMER__VERTICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinDeformer_get_weights(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__WEIGHTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SkinWeightList_from(self->data->weights, self->ctx);
    self->slots[SLOT_SKIN_DEFORMER__WEIGHTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinDeformer_get_max_weights_per_vertex(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__MAX_WEIGHTS_PER_VERTEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->max_weights_per_vertex);
    self->slots[SLOT_SKIN_DEFORMER__MAX_WEIGHTS_PER_VERTEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinDeformer_get_num_dq_weights(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__NUM_DQ_WEIGHTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_dq_weights);
    self->slots[SLOT_SKIN_DEFORMER__NUM_DQ_WEIGHTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinDeformer_get_dq_vertices(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__DQ_VERTICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->dq_vertices, self->ctx);
    self->slots[SLOT_SKIN_DEFORMER__DQ_VERTICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinDeformer_get_dq_weights(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__DQ_WEIGHTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->dq_weights, self->ctx);
    self->slots[SLOT_SKIN_DEFORMER__DQ_WEIGHTS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef SkinDeformer_getset[] = {
    { "skinning_method", (getter)SkinDeformer_get_skinning_method, NULL, "skinning_method" },
    { "clusters", (getter)SkinDeformer_get_clusters, NULL, "clusters" },
    { "vertices", (getter)SkinDeformer_get_vertices, NULL, "vertices" },
    { "weights", (getter)SkinDeformer_get_weights, NULL, "weights" },
    { "max_weights_per_vertex", (getter)SkinDeformer_get_max_weights_per_vertex, NULL, "max_weights_per_vertex" },
    { "num_dq_weights", (getter)SkinDeformer_get_num_dq_weights, NULL, "num_dq_weights" },
    { "dq_vertices", (getter)SkinDeformer_get_dq_vertices, NULL, "dq_vertices" },
    { "dq_weights", (getter)SkinDeformer_get_dq_weights, NULL, "dq_weights" },
    { NULL },
};

static PyTypeObject SkinDeformer_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SkinDeformer",
    .tp_doc = PyDoc_STR("SkinDeformer"),
    .tp_basicsize = sizeof(SkinDeformer),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = SkinDeformer_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_SKIN_CLUSTER 9
enum {
    SLOT_SKIN_CLUSTER__BONE_NODE,
    SLOT_SKIN_CLUSTER__GEOMETRY_TO_BONE,
    SLOT_SKIN_CLUSTER__MESH_NODE_TO_BONE,
    SLOT_SKIN_CLUSTER__BIND_TO_WORLD,
    SLOT_SKIN_CLUSTER__GEOMETRY_TO_WORLD,
    SLOT_SKIN_CLUSTER__GEOMETRY_TO_WORLD_TRANSFORM,
    SLOT_SKIN_CLUSTER__NUM_WEIGHTS,
    SLOT_SKIN_CLUSTER__VERTICES,
    SLOT_SKIN_CLUSTER__WEIGHTS,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_skin_cluster *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_SKIN_CLUSTER];
} SkinCluster;

static PyObject *SkinCluster_get_bone_node(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__BONE_NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->bone_node, self->ctx);
    self->slots[SLOT_SKIN_CLUSTER__BONE_NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_geometry_to_bone(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__GEOMETRY_TO_BONE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_SKIN_CLUSTER__GEOMETRY_TO_BONE] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_mesh_node_to_bone(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__MESH_NODE_TO_BONE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_SKIN_CLUSTER__MESH_NODE_TO_BONE] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_bind_to_world(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__BIND_TO_WORLD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_SKIN_CLUSTER__BIND_TO_WORLD] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_geometry_to_world(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__GEOMETRY_TO_WORLD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_SKIN_CLUSTER__GEOMETRY_TO_WORLD] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_geometry_to_world_transform(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__GEOMETRY_TO_WORLD_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Transform_from(&self->data->geometry_to_world_transform);
    self->slots[SLOT_SKIN_CLUSTER__GEOMETRY_TO_WORLD_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_num_weights(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__NUM_WEIGHTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_weights);
    self->slots[SLOT_SKIN_CLUSTER__NUM_WEIGHTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_vertices(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__VERTICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->vertices, self->ctx);
    self->slots[SLOT_SKIN_CLUSTER__VERTICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_weights(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__WEIGHTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->weights, self->ctx);
    self->slots[SLOT_SKIN_CLUSTER__WEIGHTS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef SkinCluster_getset[] = {
    { "bone_node", (getter)SkinCluster_get_bone_node, NULL, "bone_node" },
    { "geometry_to_bone", (getter)SkinCluster_get_geometry_to_bone, NULL, "geometry_to_bone" },
    { "mesh_node_to_bone", (getter)SkinCluster_get_mesh_node_to_bone, NULL, "mesh_node_to_bone" },
    { "bind_to_world", (getter)SkinCluster_get_bind_to_world, NULL, "bind_to_world" },
    { "geometry_to_world", (getter)SkinCluster_get_geometry_to_world, NULL, "geometry_to_world" },
    { "geometry_to_world_transform", (getter)SkinCluster_get_geometry_to_world_transform, NULL, "geometry_to_world_transform" },
    { "num_weights", (getter)SkinCluster_get_num_weights, NULL, "num_weights" },
    { "vertices", (getter)SkinCluster_get_vertices, NULL, "vertices" },
    { "weights", (getter)SkinCluster_get_weights, NULL, "weights" },
    { NULL },
};

static PyTypeObject SkinCluster_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SkinCluster",
    .tp_doc = PyDoc_STR("SkinCluster"),
    .tp_basicsize = sizeof(SkinCluster),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = SkinCluster_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_BLEND_DEFORMER 1
enum {
    SLOT_BLEND_DEFORMER__CHANNELS,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_blend_deformer *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_BLEND_DEFORMER];
} BlendDeformer;

static PyObject *BlendDeformer_get_channels(BlendDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_DEFORMER__CHANNELS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BlendChannelList_from(self->data->channels, self->ctx);
    self->slots[SLOT_BLEND_DEFORMER__CHANNELS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BlendDeformer_getset[] = {
    { "channels", (getter)BlendDeformer_get_channels, NULL, "channels" },
    { NULL },
};

static PyTypeObject BlendDeformer_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendDeformer",
    .tp_doc = PyDoc_STR("BlendDeformer"),
    .tp_basicsize = sizeof(BlendDeformer),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BlendDeformer_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_BLEND_KEYFRAME 3
enum {
    SLOT_BLEND_KEYFRAME__SHAPE,
    SLOT_BLEND_KEYFRAME__TARGET_WEIGHT,
    SLOT_BLEND_KEYFRAME__EFFECTIVE_WEIGHT,
};

typedef struct {
    PyObject_HEAD
    ufbx_blend_keyframe *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_BLEND_KEYFRAME];
} BlendKeyframe;

static PyObject *BlendKeyframe_get_shape(BlendKeyframe *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_KEYFRAME__SHAPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->shape, self->ctx);
    self->slots[SLOT_BLEND_KEYFRAME__SHAPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendKeyframe_get_target_weight(BlendKeyframe *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_KEYFRAME__TARGET_WEIGHT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->target_weight);
    self->slots[SLOT_BLEND_KEYFRAME__TARGET_WEIGHT] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendKeyframe_get_effective_weight(BlendKeyframe *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_KEYFRAME__EFFECTIVE_WEIGHT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->effective_weight);
    self->slots[SLOT_BLEND_KEYFRAME__EFFECTIVE_WEIGHT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BlendKeyframe_getset[] = {
    { "shape", (getter)BlendKeyframe_get_shape, NULL, "shape" },
    { "target_weight", (getter)BlendKeyframe_get_target_weight, NULL, "target_weight" },
    { "effective_weight", (getter)BlendKeyframe_get_effective_weight, NULL, "effective_weight" },
    { NULL },
};

static PyTypeObject BlendKeyframe_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendKeyframe",
    .tp_doc = PyDoc_STR("BlendKeyframe"),
    .tp_basicsize = sizeof(BlendKeyframe),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BlendKeyframe_getset,
};

#define SLOT_COUNT_BLEND_CHANNEL 3
enum {
    SLOT_BLEND_CHANNEL__WEIGHT,
    SLOT_BLEND_CHANNEL__KEYFRAMES,
    SLOT_BLEND_CHANNEL__TARGET_SHAPE,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_blend_channel *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_BLEND_CHANNEL];
} BlendChannel;

static PyObject *BlendChannel_get_weight(BlendChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_CHANNEL__WEIGHT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->weight);
    self->slots[SLOT_BLEND_CHANNEL__WEIGHT] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendChannel_get_keyframes(BlendChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_CHANNEL__KEYFRAMES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BlendKeyframeList_from(self->data->keyframes, self->ctx);
    self->slots[SLOT_BLEND_CHANNEL__KEYFRAMES] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendChannel_get_target_shape(BlendChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_CHANNEL__TARGET_SHAPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->target_shape, self->ctx);
    self->slots[SLOT_BLEND_CHANNEL__TARGET_SHAPE] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BlendChannel_getset[] = {
    { "weight", (getter)BlendChannel_get_weight, NULL, "weight" },
    { "keyframes", (getter)BlendChannel_get_keyframes, NULL, "keyframes" },
    { "target_shape", (getter)BlendChannel_get_target_shape, NULL, "target_shape" },
    { NULL },
};

static PyTypeObject BlendChannel_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendChannel",
    .tp_doc = PyDoc_STR("BlendChannel"),
    .tp_basicsize = sizeof(BlendChannel),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BlendChannel_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_BLEND_SHAPE 5
enum {
    SLOT_BLEND_SHAPE__NUM_OFFSETS,
    SLOT_BLEND_SHAPE__OFFSET_VERTICES,
    SLOT_BLEND_SHAPE__POSITION_OFFSETS,
    SLOT_BLEND_SHAPE__NORMAL_OFFSETS,
    SLOT_BLEND_SHAPE__OFFSET_WEIGHTS,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_blend_shape *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_BLEND_SHAPE];
} BlendShape;

static PyObject *BlendShape_get_num_offsets(BlendShape *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_SHAPE__NUM_OFFSETS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_offsets);
    self->slots[SLOT_BLEND_SHAPE__NUM_OFFSETS] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendShape_get_offset_vertices(BlendShape *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_SHAPE__OFFSET_VERTICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->offset_vertices, self->ctx);
    self->slots[SLOT_BLEND_SHAPE__OFFSET_VERTICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendShape_get_position_offsets(BlendShape *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_SHAPE__POSITION_OFFSETS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3List_from(self->data->position_offsets, self->ctx);
    self->slots[SLOT_BLEND_SHAPE__POSITION_OFFSETS] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendShape_get_normal_offsets(BlendShape *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_SHAPE__NORMAL_OFFSETS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3List_from(self->data->normal_offsets, self->ctx);
    self->slots[SLOT_BLEND_SHAPE__NORMAL_OFFSETS] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendShape_get_offset_weights(BlendShape *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_SHAPE__OFFSET_WEIGHTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->offset_weights, self->ctx);
    self->slots[SLOT_BLEND_SHAPE__OFFSET_WEIGHTS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BlendShape_getset[] = {
    { "num_offsets", (getter)BlendShape_get_num_offsets, NULL, "num_offsets" },
    { "offset_vertices", (getter)BlendShape_get_offset_vertices, NULL, "offset_vertices" },
    { "position_offsets", (getter)BlendShape_get_position_offsets, NULL, "position_offsets" },
    { "normal_offsets", (getter)BlendShape_get_normal_offsets, NULL, "normal_offsets" },
    { "offset_weights", (getter)BlendShape_get_offset_weights, NULL, "offset_weights" },
    { NULL },
};

static PyTypeObject BlendShape_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendShape",
    .tp_doc = PyDoc_STR("BlendShape"),
    .tp_basicsize = sizeof(BlendShape),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BlendShape_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_CACHE_FRAME 12
enum {
    SLOT_CACHE_FRAME__CHANNEL,
    SLOT_CACHE_FRAME__TIME,
    SLOT_CACHE_FRAME__FILENAME,
    SLOT_CACHE_FRAME__FILE_FORMAT,
    SLOT_CACHE_FRAME__MIRROR_AXIS,
    SLOT_CACHE_FRAME__SCALE_FACTOR,
    SLOT_CACHE_FRAME__DATA_FORMAT,
    SLOT_CACHE_FRAME__DATA_ENCODING,
    SLOT_CACHE_FRAME__DATA_OFFSET,
    SLOT_CACHE_FRAME__DATA_COUNT,
    SLOT_CACHE_FRAME__DATA_ELEMENT_BYTES,
    SLOT_CACHE_FRAME__DATA_TOTAL_BYTES,
};

typedef struct {
    PyObject_HEAD
    ufbx_cache_frame *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_CACHE_FRAME];
} CacheFrame;

static PyObject *CacheFrame_get_channel(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__CHANNEL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->channel);
    self->slots[SLOT_CACHE_FRAME__CHANNEL] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_time(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__TIME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->time);
    self->slots[SLOT_CACHE_FRAME__TIME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_filename(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->filename);
    self->slots[SLOT_CACHE_FRAME__FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_file_format(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__FILE_FORMAT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_cache_file_format");
    self->slots[SLOT_CACHE_FRAME__FILE_FORMAT] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_mirror_axis(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__MIRROR_AXIS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_mirror_axis");
    self->slots[SLOT_CACHE_FRAME__MIRROR_AXIS] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_scale_factor(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__SCALE_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->scale_factor);
    self->slots[SLOT_CACHE_FRAME__SCALE_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_data_format(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__DATA_FORMAT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_cache_data_format");
    self->slots[SLOT_CACHE_FRAME__DATA_FORMAT] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_data_encoding(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__DATA_ENCODING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_cache_data_encoding");
    self->slots[SLOT_CACHE_FRAME__DATA_ENCODING] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_data_offset(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__DATA_OFFSET];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLongLong((unsigned long long)self->data->data_offset);
    self->slots[SLOT_CACHE_FRAME__DATA_OFFSET] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_data_count(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__DATA_COUNT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->data_count);
    self->slots[SLOT_CACHE_FRAME__DATA_COUNT] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_data_element_bytes(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__DATA_ELEMENT_BYTES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->data_element_bytes);
    self->slots[SLOT_CACHE_FRAME__DATA_ELEMENT_BYTES] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_data_total_bytes(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__DATA_TOTAL_BYTES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLongLong((unsigned long long)self->data->data_total_bytes);
    self->slots[SLOT_CACHE_FRAME__DATA_TOTAL_BYTES] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef CacheFrame_getset[] = {
    { "channel", (getter)CacheFrame_get_channel, NULL, "channel" },
    { "time", (getter)CacheFrame_get_time, NULL, "time" },
    { "filename", (getter)CacheFrame_get_filename, NULL, "filename" },
    { "file_format", (getter)CacheFrame_get_file_format, NULL, "file_format" },
    { "mirror_axis", (getter)CacheFrame_get_mirror_axis, NULL, "mirror_axis" },
    { "scale_factor", (getter)CacheFrame_get_scale_factor, NULL, "scale_factor" },
    { "data_format", (getter)CacheFrame_get_data_format, NULL, "data_format" },
    { "data_encoding", (getter)CacheFrame_get_data_encoding, NULL, "data_encoding" },
    { "data_offset", (getter)CacheFrame_get_data_offset, NULL, "data_offset" },
    { "data_count", (getter)CacheFrame_get_data_count, NULL, "data_count" },
    { "data_element_bytes", (getter)CacheFrame_get_data_element_bytes, NULL, "data_element_bytes" },
    { "data_total_bytes", (getter)CacheFrame_get_data_total_bytes, NULL, "data_total_bytes" },
    { NULL },
};

static PyTypeObject CacheFrame_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheFrame",
    .tp_doc = PyDoc_STR("CacheFrame"),
    .tp_basicsize = sizeof(CacheFrame),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = CacheFrame_getset,
};

#define SLOT_COUNT_CACHE_CHANNEL 6
enum {
    SLOT_CACHE_CHANNEL__NAME,
    SLOT_CACHE_CHANNEL__INTERPRETATION,
    SLOT_CACHE_CHANNEL__INTERPRETATION_NAME,
    SLOT_CACHE_CHANNEL__FRAMES,
    SLOT_CACHE_CHANNEL__MIRROR_AXIS,
    SLOT_CACHE_CHANNEL__SCALE_FACTOR,
};

typedef struct {
    PyObject_HEAD
    ufbx_cache_channel *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_CACHE_CHANNEL];
} CacheChannel;

static PyObject *CacheChannel_get_name(CacheChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_CHANNEL__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_CACHE_CHANNEL__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheChannel_get_interpretation(CacheChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_CHANNEL__INTERPRETATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_cache_interpretation");
    self->slots[SLOT_CACHE_CHANNEL__INTERPRETATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheChannel_get_interpretation_name(CacheChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_CHANNEL__INTERPRETATION_NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->interpretation_name);
    self->slots[SLOT_CACHE_CHANNEL__INTERPRETATION_NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheChannel_get_frames(CacheChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_CHANNEL__FRAMES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = CacheFrameList_from(self->data->frames, self->ctx);
    self->slots[SLOT_CACHE_CHANNEL__FRAMES] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheChannel_get_mirror_axis(CacheChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_CHANNEL__MIRROR_AXIS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_mirror_axis");
    self->slots[SLOT_CACHE_CHANNEL__MIRROR_AXIS] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheChannel_get_scale_factor(CacheChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_CHANNEL__SCALE_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->scale_factor);
    self->slots[SLOT_CACHE_CHANNEL__SCALE_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef CacheChannel_getset[] = {
    { "name", (getter)CacheChannel_get_name, NULL, "name" },
    { "interpretation", (getter)CacheChannel_get_interpretation, NULL, "interpretation" },
    { "interpretation_name", (getter)CacheChannel_get_interpretation_name, NULL, "interpretation_name" },
    { "frames", (getter)CacheChannel_get_frames, NULL, "frames" },
    { "mirror_axis", (getter)CacheChannel_get_mirror_axis, NULL, "mirror_axis" },
    { "scale_factor", (getter)CacheChannel_get_scale_factor, NULL, "scale_factor" },
    { NULL },
};

static PyTypeObject CacheChannel_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheChannel",
    .tp_doc = PyDoc_STR("CacheChannel"),
    .tp_basicsize = sizeof(CacheChannel),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = CacheChannel_getset,
};

#define SLOT_COUNT_GEOMETRY_CACHE 4
enum {
    SLOT_GEOMETRY_CACHE__ROOT_FILENAME,
    SLOT_GEOMETRY_CACHE__CHANNELS,
    SLOT_GEOMETRY_CACHE__FRAMES,
    SLOT_GEOMETRY_CACHE__EXTRA_INFO,
};

typedef struct {
    PyObject_HEAD
    ufbx_geometry_cache *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_GEOMETRY_CACHE];
} GeometryCache;

static PyObject *GeometryCache_get_root_filename(GeometryCache *self, void *closure) {
    PyObject *slot = self->slots[SLOT_GEOMETRY_CACHE__ROOT_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->root_filename);
    self->slots[SLOT_GEOMETRY_CACHE__ROOT_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *GeometryCache_get_channels(GeometryCache *self, void *closure) {
    PyObject *slot = self->slots[SLOT_GEOMETRY_CACHE__CHANNELS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = CacheChannelList_from(self->data->channels, self->ctx);
    self->slots[SLOT_GEOMETRY_CACHE__CHANNELS] = slot;
    return Py_NewRef(slot);
}

static PyObject *GeometryCache_get_frames(GeometryCache *self, void *closure) {
    PyObject *slot = self->slots[SLOT_GEOMETRY_CACHE__FRAMES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = CacheFrameList_from(self->data->frames, self->ctx);
    self->slots[SLOT_GEOMETRY_CACHE__FRAMES] = slot;
    return Py_NewRef(slot);
}

static PyObject *GeometryCache_get_extra_info(GeometryCache *self, void *closure) {
    PyObject *slot = self->slots[SLOT_GEOMETRY_CACHE__EXTRA_INFO];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = StringList_from(self->data->extra_info, self->ctx);
    self->slots[SLOT_GEOMETRY_CACHE__EXTRA_INFO] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef GeometryCache_getset[] = {
    { "root_filename", (getter)GeometryCache_get_root_filename, NULL, "root_filename" },
    { "channels", (getter)GeometryCache_get_channels, NULL, "channels" },
    { "frames", (getter)GeometryCache_get_frames, NULL, "frames" },
    { "extra_info", (getter)GeometryCache_get_extra_info, NULL, "extra_info" },
    { NULL },
};

static PyTypeObject GeometryCache_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.GeometryCache",
    .tp_doc = PyDoc_STR("GeometryCache"),
    .tp_basicsize = sizeof(GeometryCache),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = GeometryCache_getset,
};

#define SLOT_COUNT_CACHE_DEFORMER 4
enum {
    SLOT_CACHE_DEFORMER__CHANNEL,
    SLOT_CACHE_DEFORMER__FILE,
    SLOT_CACHE_DEFORMER__EXTERNAL_CACHE,
    SLOT_CACHE_DEFORMER__EXTERNAL_CHANNEL,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_cache_deformer *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_CACHE_DEFORMER];
} CacheDeformer;

static PyObject *CacheDeformer_get_channel(CacheDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_DEFORMER__CHANNEL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->channel);
    self->slots[SLOT_CACHE_DEFORMER__CHANNEL] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheDeformer_get_file(CacheDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_DEFORMER__FILE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->file, self->ctx);
    self->slots[SLOT_CACHE_DEFORMER__FILE] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheDeformer_get_external_cache(CacheDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_DEFORMER__EXTERNAL_CACHE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_geometry_cache?*");
    self->slots[SLOT_CACHE_DEFORMER__EXTERNAL_CACHE] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheDeformer_get_external_channel(CacheDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_DEFORMER__EXTERNAL_CHANNEL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_cache_channel?*");
    self->slots[SLOT_CACHE_DEFORMER__EXTERNAL_CHANNEL] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef CacheDeformer_getset[] = {
    { "channel", (getter)CacheDeformer_get_channel, NULL, "channel" },
    { "file", (getter)CacheDeformer_get_file, NULL, "file" },
    { "external_cache", (getter)CacheDeformer_get_external_cache, NULL, "external_cache" },
    { "external_channel", (getter)CacheDeformer_get_external_channel, NULL, "external_channel" },
    { NULL },
};

static PyTypeObject CacheDeformer_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheDeformer",
    .tp_doc = PyDoc_STR("CacheDeformer"),
    .tp_basicsize = sizeof(CacheDeformer),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = CacheDeformer_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_CACHE_FILE 8
enum {
    SLOT_CACHE_FILE__FILENAME,
    SLOT_CACHE_FILE__ABSOLUTE_FILENAME,
    SLOT_CACHE_FILE__RELATIVE_FILENAME,
    SLOT_CACHE_FILE__RAW_FILENAME,
    SLOT_CACHE_FILE__RAW_ABSOLUTE_FILENAME,
    SLOT_CACHE_FILE__RAW_RELATIVE_FILENAME,
    SLOT_CACHE_FILE__FORMAT,
    SLOT_CACHE_FILE__EXTERNAL_CACHE,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_cache_file *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_CACHE_FILE];
} CacheFile;

static PyObject *CacheFile_get_filename(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->filename);
    self->slots[SLOT_CACHE_FILE__FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFile_get_absolute_filename(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__ABSOLUTE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->absolute_filename);
    self->slots[SLOT_CACHE_FILE__ABSOLUTE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFile_get_relative_filename(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__RELATIVE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->relative_filename);
    self->slots[SLOT_CACHE_FILE__RELATIVE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFile_get_raw_filename(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__RAW_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_filename);
    self->slots[SLOT_CACHE_FILE__RAW_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFile_get_raw_absolute_filename(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__RAW_ABSOLUTE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_absolute_filename);
    self->slots[SLOT_CACHE_FILE__RAW_ABSOLUTE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFile_get_raw_relative_filename(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__RAW_RELATIVE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_relative_filename);
    self->slots[SLOT_CACHE_FILE__RAW_RELATIVE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFile_get_format(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__FORMAT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_cache_file_format");
    self->slots[SLOT_CACHE_FILE__FORMAT] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFile_get_external_cache(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__EXTERNAL_CACHE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_geometry_cache?*");
    self->slots[SLOT_CACHE_FILE__EXTERNAL_CACHE] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef CacheFile_getset[] = {
    { "filename", (getter)CacheFile_get_filename, NULL, "filename" },
    { "absolute_filename", (getter)CacheFile_get_absolute_filename, NULL, "absolute_filename" },
    { "relative_filename", (getter)CacheFile_get_relative_filename, NULL, "relative_filename" },
    { "raw_filename", (getter)CacheFile_get_raw_filename, NULL, "raw_filename" },
    { "raw_absolute_filename", (getter)CacheFile_get_raw_absolute_filename, NULL, "raw_absolute_filename" },
    { "raw_relative_filename", (getter)CacheFile_get_raw_relative_filename, NULL, "raw_relative_filename" },
    { "format", (getter)CacheFile_get_format, NULL, "format" },
    { "external_cache", (getter)CacheFile_get_external_cache, NULL, "external_cache" },
    { NULL },
};

static PyTypeObject CacheFile_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheFile",
    .tp_doc = PyDoc_STR("CacheFile"),
    .tp_basicsize = sizeof(CacheFile),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = CacheFile_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_MATERIAL_MAP 6
enum {
    SLOT_MATERIAL_MAP__VALUE_INT,
    SLOT_MATERIAL_MAP__TEXTURE,
    SLOT_MATERIAL_MAP__HAS_VALUE,
    SLOT_MATERIAL_MAP__TEXTURE_ENABLED,
    SLOT_MATERIAL_MAP__FEATURE_DISABLED,
    SLOT_MATERIAL_MAP__VALUE_COMPONENTS,
};

typedef struct {
    PyObject_HEAD
    ufbx_material_map *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_MATERIAL_MAP];
} MaterialMap;

static PyObject *MaterialMap_get_value_int(MaterialMap *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_MAP__VALUE_INT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromLongLong((long long)self->data->value_int);
    self->slots[SLOT_MATERIAL_MAP__VALUE_INT] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialMap_get_texture(MaterialMap *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_MAP__TEXTURE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->texture, self->ctx);
    self->slots[SLOT_MATERIAL_MAP__TEXTURE] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialMap_get_has_value(MaterialMap *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_MAP__HAS_VALUE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->has_value ? Py_True : Py_False;
    self->slots[SLOT_MATERIAL_MAP__HAS_VALUE] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialMap_get_texture_enabled(MaterialMap *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_MAP__TEXTURE_ENABLED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->texture_enabled ? Py_True : Py_False;
    self->slots[SLOT_MATERIAL_MAP__TEXTURE_ENABLED] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialMap_get_feature_disabled(MaterialMap *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_MAP__FEATURE_DISABLED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->feature_disabled ? Py_True : Py_False;
    self->slots[SLOT_MATERIAL_MAP__FEATURE_DISABLED] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialMap_get_value_components(MaterialMap *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_MAP__VALUE_COMPONENTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->value_components);
    self->slots[SLOT_MATERIAL_MAP__VALUE_COMPONENTS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef MaterialMap_getset[] = {
    { "value_int", (getter)MaterialMap_get_value_int, NULL, "value_int" },
    { "texture", (getter)MaterialMap_get_texture, NULL, "texture" },
    { "has_value", (getter)MaterialMap_get_has_value, NULL, "has_value" },
    { "texture_enabled", (getter)MaterialMap_get_texture_enabled, NULL, "texture_enabled" },
    { "feature_disabled", (getter)MaterialMap_get_feature_disabled, NULL, "feature_disabled" },
    { "value_components", (getter)MaterialMap_get_value_components, NULL, "value_components" },
    { NULL },
};

static PyTypeObject MaterialMap_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialMap",
    .tp_doc = PyDoc_STR("MaterialMap"),
    .tp_basicsize = sizeof(MaterialMap),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = MaterialMap_getset,
};

#define SLOT_COUNT_MATERIAL_FEATURE_INFO 2
enum {
    SLOT_MATERIAL_FEATURE_INFO__ENABLED,
    SLOT_MATERIAL_FEATURE_INFO__IS_EXPLICIT,
};

typedef struct {
    PyObject_HEAD
    ufbx_material_feature_info *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_MATERIAL_FEATURE_INFO];
} MaterialFeatureInfo;

static PyObject *MaterialFeatureInfo_get_enabled(MaterialFeatureInfo *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURE_INFO__ENABLED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->enabled ? Py_True : Py_False;
    self->slots[SLOT_MATERIAL_FEATURE_INFO__ENABLED] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatureInfo_get_is_explicit(MaterialFeatureInfo *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURE_INFO__IS_EXPLICIT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->is_explicit ? Py_True : Py_False;
    self->slots[SLOT_MATERIAL_FEATURE_INFO__IS_EXPLICIT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef MaterialFeatureInfo_getset[] = {
    { "enabled", (getter)MaterialFeatureInfo_get_enabled, NULL, "enabled" },
    { "is_explicit", (getter)MaterialFeatureInfo_get_is_explicit, NULL, "is_explicit" },
    { NULL },
};

static PyTypeObject MaterialFeatureInfo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialFeatureInfo",
    .tp_doc = PyDoc_STR("MaterialFeatureInfo"),
    .tp_basicsize = sizeof(MaterialFeatureInfo),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = MaterialFeatureInfo_getset,
};

#define SLOT_COUNT_MATERIAL_TEXTURE 3
enum {
    SLOT_MATERIAL_TEXTURE__MATERIAL_PROP,
    SLOT_MATERIAL_TEXTURE__SHADER_PROP,
    SLOT_MATERIAL_TEXTURE__TEXTURE,
};

typedef struct {
    PyObject_HEAD
    ufbx_material_texture *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_MATERIAL_TEXTURE];
} MaterialTexture;

static PyObject *MaterialTexture_get_material_prop(MaterialTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_TEXTURE__MATERIAL_PROP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->material_prop);
    self->slots[SLOT_MATERIAL_TEXTURE__MATERIAL_PROP] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialTexture_get_shader_prop(MaterialTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_TEXTURE__SHADER_PROP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->shader_prop);
    self->slots[SLOT_MATERIAL_TEXTURE__SHADER_PROP] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialTexture_get_texture(MaterialTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_TEXTURE__TEXTURE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->texture, self->ctx);
    self->slots[SLOT_MATERIAL_TEXTURE__TEXTURE] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef MaterialTexture_getset[] = {
    { "material_prop", (getter)MaterialTexture_get_material_prop, NULL, "material_prop" },
    { "shader_prop", (getter)MaterialTexture_get_shader_prop, NULL, "shader_prop" },
    { "texture", (getter)MaterialTexture_get_texture, NULL, "texture" },
    { NULL },
};

static PyTypeObject MaterialTexture_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialTexture",
    .tp_doc = PyDoc_STR("MaterialTexture"),
    .tp_basicsize = sizeof(MaterialTexture),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = MaterialTexture_getset,
};

typedef struct {
    PyObject_HEAD
    ufbx_material_fbx_maps *data;
    Context *ctx;
} MaterialFbxMaps;

static PyTypeObject MaterialFbxMaps_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialFbxMaps",
    .tp_doc = PyDoc_STR("MaterialFbxMaps"),
    .tp_basicsize = sizeof(MaterialFbxMaps),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
};

typedef struct {
    PyObject_HEAD
    ufbx_material_pbr_maps *data;
    Context *ctx;
} MaterialPbrMaps;

static PyTypeObject MaterialPbrMaps_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialPbrMaps",
    .tp_doc = PyDoc_STR("MaterialPbrMaps"),
    .tp_basicsize = sizeof(MaterialPbrMaps),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
};

typedef struct {
    PyObject_HEAD
    ufbx_material_features *data;
    Context *ctx;
} MaterialFeatures;

static PyTypeObject MaterialFeatures_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialFeatures",
    .tp_doc = PyDoc_STR("MaterialFeatures"),
    .tp_basicsize = sizeof(MaterialFeatures),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
};

#define SLOT_COUNT_MATERIAL 8
enum {
    SLOT_MATERIAL__FBX,
    SLOT_MATERIAL__PBR,
    SLOT_MATERIAL__FEATURES,
    SLOT_MATERIAL__SHADER_TYPE,
    SLOT_MATERIAL__SHADER,
    SLOT_MATERIAL__SHADING_MODEL_NAME,
    SLOT_MATERIAL__SHADER_PROP_PREFIX,
    SLOT_MATERIAL__TEXTURES,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_material *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_MATERIAL];
} Material;

static PyObject *Material_get_fbx(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__FBX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_material_fbx_maps");
    self->slots[SLOT_MATERIAL__FBX] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_pbr(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__PBR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_material_pbr_maps");
    self->slots[SLOT_MATERIAL__PBR] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_features(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__FEATURES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_material_features");
    self->slots[SLOT_MATERIAL__FEATURES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_shader_type(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__SHADER_TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_shader_type");
    self->slots[SLOT_MATERIAL__SHADER_TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_shader(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__SHADER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->shader, self->ctx);
    self->slots[SLOT_MATERIAL__SHADER] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_shading_model_name(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__SHADING_MODEL_NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->shading_model_name);
    self->slots[SLOT_MATERIAL__SHADING_MODEL_NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_shader_prop_prefix(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__SHADER_PROP_PREFIX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->shader_prop_prefix);
    self->slots[SLOT_MATERIAL__SHADER_PROP_PREFIX] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_textures(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__TEXTURES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialTextureList_from(self->data->textures, self->ctx);
    self->slots[SLOT_MATERIAL__TEXTURES] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Material_getset[] = {
    { "fbx", (getter)Material_get_fbx, NULL, "fbx" },
    { "pbr", (getter)Material_get_pbr, NULL, "pbr" },
    { "features", (getter)Material_get_features, NULL, "features" },
    { "shader_type", (getter)Material_get_shader_type, NULL, "shader_type" },
    { "shader", (getter)Material_get_shader, NULL, "shader" },
    { "shading_model_name", (getter)Material_get_shading_model_name, NULL, "shading_model_name" },
    { "shader_prop_prefix", (getter)Material_get_shader_prop_prefix, NULL, "shader_prop_prefix" },
    { "textures", (getter)Material_get_textures, NULL, "textures" },
    { NULL },
};

static PyTypeObject Material_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Material",
    .tp_doc = PyDoc_STR("Material"),
    .tp_basicsize = sizeof(Material),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Material_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_TEXTURE_LAYER 3
enum {
    SLOT_TEXTURE_LAYER__TEXTURE,
    SLOT_TEXTURE_LAYER__BLEND_MODE,
    SLOT_TEXTURE_LAYER__ALPHA,
};

typedef struct {
    PyObject_HEAD
    ufbx_texture_layer *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_TEXTURE_LAYER];
} TextureLayer;

static PyObject *TextureLayer_get_texture(TextureLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE_LAYER__TEXTURE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->texture, self->ctx);
    self->slots[SLOT_TEXTURE_LAYER__TEXTURE] = slot;
    return Py_NewRef(slot);
}

static PyObject *TextureLayer_get_blend_mode(TextureLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE_LAYER__BLEND_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_blend_mode");
    self->slots[SLOT_TEXTURE_LAYER__BLEND_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *TextureLayer_get_alpha(TextureLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE_LAYER__ALPHA];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->alpha);
    self->slots[SLOT_TEXTURE_LAYER__ALPHA] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef TextureLayer_getset[] = {
    { "texture", (getter)TextureLayer_get_texture, NULL, "texture" },
    { "blend_mode", (getter)TextureLayer_get_blend_mode, NULL, "blend_mode" },
    { "alpha", (getter)TextureLayer_get_alpha, NULL, "alpha" },
    { NULL },
};

static PyTypeObject TextureLayer_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.TextureLayer",
    .tp_doc = PyDoc_STR("TextureLayer"),
    .tp_basicsize = sizeof(TextureLayer),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = TextureLayer_getset,
};

#define SLOT_COUNT_SHADER_TEXTURE_INPUT 10
enum {
    SLOT_SHADER_TEXTURE_INPUT__NAME,
    SLOT_SHADER_TEXTURE_INPUT__VALUE_INT,
    SLOT_SHADER_TEXTURE_INPUT__VALUE_STR,
    SLOT_SHADER_TEXTURE_INPUT__VALUE_BLOB,
    SLOT_SHADER_TEXTURE_INPUT__TEXTURE,
    SLOT_SHADER_TEXTURE_INPUT__TEXTURE_OUTPUT_INDEX,
    SLOT_SHADER_TEXTURE_INPUT__TEXTURE_ENABLED,
    SLOT_SHADER_TEXTURE_INPUT__PROP,
    SLOT_SHADER_TEXTURE_INPUT__TEXTURE_PROP,
    SLOT_SHADER_TEXTURE_INPUT__TEXTURE_ENABLED_PROP,
};

typedef struct {
    PyObject_HEAD
    ufbx_shader_texture_input *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_SHADER_TEXTURE_INPUT];
} ShaderTextureInput;

static PyObject *ShaderTextureInput_get_name(ShaderTextureInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE_INPUT__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_SHADER_TEXTURE_INPUT__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTextureInput_get_value_int(ShaderTextureInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE_INPUT__VALUE_INT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromLongLong((long long)self->data->value_int);
    self->slots[SLOT_SHADER_TEXTURE_INPUT__VALUE_INT] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTextureInput_get_value_str(ShaderTextureInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE_INPUT__VALUE_STR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->value_str);
    self->slots[SLOT_SHADER_TEXTURE_INPUT__VALUE_STR] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTextureInput_get_value_blob(ShaderTextureInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE_INPUT__VALUE_BLOB];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->value_blob);
    self->slots[SLOT_SHADER_TEXTURE_INPUT__VALUE_BLOB] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTextureInput_get_texture(ShaderTextureInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE_INPUT__TEXTURE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->texture, self->ctx);
    self->slots[SLOT_SHADER_TEXTURE_INPUT__TEXTURE] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTextureInput_get_texture_output_index(ShaderTextureInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE_INPUT__TEXTURE_OUTPUT_INDEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromLongLong((long long)self->data->texture_output_index);
    self->slots[SLOT_SHADER_TEXTURE_INPUT__TEXTURE_OUTPUT_INDEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTextureInput_get_texture_enabled(ShaderTextureInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE_INPUT__TEXTURE_ENABLED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->texture_enabled ? Py_True : Py_False;
    self->slots[SLOT_SHADER_TEXTURE_INPUT__TEXTURE_ENABLED] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTextureInput_get_prop(ShaderTextureInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE_INPUT__PROP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_prop*");
    self->slots[SLOT_SHADER_TEXTURE_INPUT__PROP] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTextureInput_get_texture_prop(ShaderTextureInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE_INPUT__TEXTURE_PROP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_prop?*");
    self->slots[SLOT_SHADER_TEXTURE_INPUT__TEXTURE_PROP] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTextureInput_get_texture_enabled_prop(ShaderTextureInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE_INPUT__TEXTURE_ENABLED_PROP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_prop?*");
    self->slots[SLOT_SHADER_TEXTURE_INPUT__TEXTURE_ENABLED_PROP] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef ShaderTextureInput_getset[] = {
    { "name", (getter)ShaderTextureInput_get_name, NULL, "name" },
    { "value_int", (getter)ShaderTextureInput_get_value_int, NULL, "value_int" },
    { "value_str", (getter)ShaderTextureInput_get_value_str, NULL, "value_str" },
    { "value_blob", (getter)ShaderTextureInput_get_value_blob, NULL, "value_blob" },
    { "texture", (getter)ShaderTextureInput_get_texture, NULL, "texture" },
    { "texture_output_index", (getter)ShaderTextureInput_get_texture_output_index, NULL, "texture_output_index" },
    { "texture_enabled", (getter)ShaderTextureInput_get_texture_enabled, NULL, "texture_enabled" },
    { "prop", (getter)ShaderTextureInput_get_prop, NULL, "prop" },
    { "texture_prop", (getter)ShaderTextureInput_get_texture_prop, NULL, "texture_prop" },
    { "texture_enabled_prop", (getter)ShaderTextureInput_get_texture_enabled_prop, NULL, "texture_enabled_prop" },
    { NULL },
};

static PyTypeObject ShaderTextureInput_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderTextureInput",
    .tp_doc = PyDoc_STR("ShaderTextureInput"),
    .tp_basicsize = sizeof(ShaderTextureInput),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = ShaderTextureInput_getset,
};

#define SLOT_COUNT_SHADER_TEXTURE 9
enum {
    SLOT_SHADER_TEXTURE__TYPE,
    SLOT_SHADER_TEXTURE__SHADER_NAME,
    SLOT_SHADER_TEXTURE__SHADER_TYPE_ID,
    SLOT_SHADER_TEXTURE__INPUTS,
    SLOT_SHADER_TEXTURE__SHADER_SOURCE,
    SLOT_SHADER_TEXTURE__RAW_SHADER_SOURCE,
    SLOT_SHADER_TEXTURE__MAIN_TEXTURE,
    SLOT_SHADER_TEXTURE__MAIN_TEXTURE_OUTPUT_INDEX,
    SLOT_SHADER_TEXTURE__PROP_PREFIX,
};

typedef struct {
    PyObject_HEAD
    ufbx_shader_texture *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_SHADER_TEXTURE];
} ShaderTexture;

static PyObject *ShaderTexture_get_type(ShaderTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_shader_texture_type");
    self->slots[SLOT_SHADER_TEXTURE__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTexture_get_shader_name(ShaderTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE__SHADER_NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->shader_name);
    self->slots[SLOT_SHADER_TEXTURE__SHADER_NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTexture_get_shader_type_id(ShaderTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE__SHADER_TYPE_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLongLong((unsigned long long)self->data->shader_type_id);
    self->slots[SLOT_SHADER_TEXTURE__SHADER_TYPE_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTexture_get_inputs(ShaderTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE__INPUTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ShaderTextureInputList_from(self->data->inputs, self->ctx);
    self->slots[SLOT_SHADER_TEXTURE__INPUTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTexture_get_shader_source(ShaderTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE__SHADER_SOURCE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->shader_source);
    self->slots[SLOT_SHADER_TEXTURE__SHADER_SOURCE] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTexture_get_raw_shader_source(ShaderTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE__RAW_SHADER_SOURCE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_shader_source);
    self->slots[SLOT_SHADER_TEXTURE__RAW_SHADER_SOURCE] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTexture_get_main_texture(ShaderTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE__MAIN_TEXTURE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->main_texture, self->ctx);
    self->slots[SLOT_SHADER_TEXTURE__MAIN_TEXTURE] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTexture_get_main_texture_output_index(ShaderTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE__MAIN_TEXTURE_OUTPUT_INDEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromLongLong((long long)self->data->main_texture_output_index);
    self->slots[SLOT_SHADER_TEXTURE__MAIN_TEXTURE_OUTPUT_INDEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderTexture_get_prop_prefix(ShaderTexture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE__PROP_PREFIX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->prop_prefix);
    self->slots[SLOT_SHADER_TEXTURE__PROP_PREFIX] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef ShaderTexture_getset[] = {
    { "type", (getter)ShaderTexture_get_type, NULL, "type" },
    { "shader_name", (getter)ShaderTexture_get_shader_name, NULL, "shader_name" },
    { "shader_type_id", (getter)ShaderTexture_get_shader_type_id, NULL, "shader_type_id" },
    { "inputs", (getter)ShaderTexture_get_inputs, NULL, "inputs" },
    { "shader_source", (getter)ShaderTexture_get_shader_source, NULL, "shader_source" },
    { "raw_shader_source", (getter)ShaderTexture_get_raw_shader_source, NULL, "raw_shader_source" },
    { "main_texture", (getter)ShaderTexture_get_main_texture, NULL, "main_texture" },
    { "main_texture_output_index", (getter)ShaderTexture_get_main_texture_output_index, NULL, "main_texture_output_index" },
    { "prop_prefix", (getter)ShaderTexture_get_prop_prefix, NULL, "prop_prefix" },
    { NULL },
};

static PyTypeObject ShaderTexture_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderTexture",
    .tp_doc = PyDoc_STR("ShaderTexture"),
    .tp_basicsize = sizeof(ShaderTexture),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = ShaderTexture_getset,
};

#define SLOT_COUNT_TEXTURE_FILE 8
enum {
    SLOT_TEXTURE_FILE__INDEX,
    SLOT_TEXTURE_FILE__FILENAME,
    SLOT_TEXTURE_FILE__ABSOLUTE_FILENAME,
    SLOT_TEXTURE_FILE__RELATIVE_FILENAME,
    SLOT_TEXTURE_FILE__RAW_FILENAME,
    SLOT_TEXTURE_FILE__RAW_ABSOLUTE_FILENAME,
    SLOT_TEXTURE_FILE__RAW_RELATIVE_FILENAME,
    SLOT_TEXTURE_FILE__CONTENT,
};

typedef struct {
    PyObject_HEAD
    ufbx_texture_file *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_TEXTURE_FILE];
} TextureFile;

static PyObject *TextureFile_get_index(TextureFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE_FILE__INDEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->index);
    self->slots[SLOT_TEXTURE_FILE__INDEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *TextureFile_get_filename(TextureFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE_FILE__FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->filename);
    self->slots[SLOT_TEXTURE_FILE__FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *TextureFile_get_absolute_filename(TextureFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE_FILE__ABSOLUTE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->absolute_filename);
    self->slots[SLOT_TEXTURE_FILE__ABSOLUTE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *TextureFile_get_relative_filename(TextureFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE_FILE__RELATIVE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->relative_filename);
    self->slots[SLOT_TEXTURE_FILE__RELATIVE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *TextureFile_get_raw_filename(TextureFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE_FILE__RAW_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_filename);
    self->slots[SLOT_TEXTURE_FILE__RAW_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *TextureFile_get_raw_absolute_filename(TextureFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE_FILE__RAW_ABSOLUTE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_absolute_filename);
    self->slots[SLOT_TEXTURE_FILE__RAW_ABSOLUTE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *TextureFile_get_raw_relative_filename(TextureFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE_FILE__RAW_RELATIVE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_relative_filename);
    self->slots[SLOT_TEXTURE_FILE__RAW_RELATIVE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *TextureFile_get_content(TextureFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE_FILE__CONTENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->content);
    self->slots[SLOT_TEXTURE_FILE__CONTENT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef TextureFile_getset[] = {
    { "index", (getter)TextureFile_get_index, NULL, "index" },
    { "filename", (getter)TextureFile_get_filename, NULL, "filename" },
    { "absolute_filename", (getter)TextureFile_get_absolute_filename, NULL, "absolute_filename" },
    { "relative_filename", (getter)TextureFile_get_relative_filename, NULL, "relative_filename" },
    { "raw_filename", (getter)TextureFile_get_raw_filename, NULL, "raw_filename" },
    { "raw_absolute_filename", (getter)TextureFile_get_raw_absolute_filename, NULL, "raw_absolute_filename" },
    { "raw_relative_filename", (getter)TextureFile_get_raw_relative_filename, NULL, "raw_relative_filename" },
    { "content", (getter)TextureFile_get_content, NULL, "content" },
    { NULL },
};

static PyTypeObject TextureFile_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.TextureFile",
    .tp_doc = PyDoc_STR("TextureFile"),
    .tp_basicsize = sizeof(TextureFile),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = TextureFile_getset,
};

#define SLOT_COUNT_TEXTURE 21
enum {
    SLOT_TEXTURE__TYPE,
    SLOT_TEXTURE__FILENAME,
    SLOT_TEXTURE__ABSOLUTE_FILENAME,
    SLOT_TEXTURE__RELATIVE_FILENAME,
    SLOT_TEXTURE__RAW_FILENAME,
    SLOT_TEXTURE__RAW_ABSOLUTE_FILENAME,
    SLOT_TEXTURE__RAW_RELATIVE_FILENAME,
    SLOT_TEXTURE__CONTENT,
    SLOT_TEXTURE__VIDEO,
    SLOT_TEXTURE__FILE_INDEX,
    SLOT_TEXTURE__HAS_FILE,
    SLOT_TEXTURE__LAYERS,
    SLOT_TEXTURE__SHADER,
    SLOT_TEXTURE__FILE_TEXTURES,
    SLOT_TEXTURE__UV_SET,
    SLOT_TEXTURE__WRAP_U,
    SLOT_TEXTURE__WRAP_V,
    SLOT_TEXTURE__HAS_UV_TRANSFORM,
    SLOT_TEXTURE__UV_TRANSFORM,
    SLOT_TEXTURE__TEXTURE_TO_UV,
    SLOT_TEXTURE__UV_TO_TEXTURE,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_texture *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_TEXTURE];
} Texture;

static PyObject *Texture_get_type(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_texture_type");
    self->slots[SLOT_TEXTURE__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_filename(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->filename);
    self->slots[SLOT_TEXTURE__FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_absolute_filename(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__ABSOLUTE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->absolute_filename);
    self->slots[SLOT_TEXTURE__ABSOLUTE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_relative_filename(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__RELATIVE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->relative_filename);
    self->slots[SLOT_TEXTURE__RELATIVE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_raw_filename(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__RAW_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_filename);
    self->slots[SLOT_TEXTURE__RAW_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_raw_absolute_filename(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__RAW_ABSOLUTE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_absolute_filename);
    self->slots[SLOT_TEXTURE__RAW_ABSOLUTE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_raw_relative_filename(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__RAW_RELATIVE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_relative_filename);
    self->slots[SLOT_TEXTURE__RAW_RELATIVE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_content(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__CONTENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->content);
    self->slots[SLOT_TEXTURE__CONTENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_video(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__VIDEO];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->video, self->ctx);
    self->slots[SLOT_TEXTURE__VIDEO] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_file_index(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__FILE_INDEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->file_index);
    self->slots[SLOT_TEXTURE__FILE_INDEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_has_file(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__HAS_FILE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->has_file ? Py_True : Py_False;
    self->slots[SLOT_TEXTURE__HAS_FILE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_layers(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__LAYERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = TextureLayerList_from(self->data->layers, self->ctx);
    self->slots[SLOT_TEXTURE__LAYERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_shader(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__SHADER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_shader_texture?*");
    self->slots[SLOT_TEXTURE__SHADER] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_file_textures(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__FILE_TEXTURES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = TextureList_from(self->data->file_textures, self->ctx);
    self->slots[SLOT_TEXTURE__FILE_TEXTURES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_uv_set(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__UV_SET];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->uv_set);
    self->slots[SLOT_TEXTURE__UV_SET] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_wrap_u(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__WRAP_U];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_wrap_mode");
    self->slots[SLOT_TEXTURE__WRAP_U] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_wrap_v(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__WRAP_V];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_wrap_mode");
    self->slots[SLOT_TEXTURE__WRAP_V] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_has_uv_transform(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__HAS_UV_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->has_uv_transform ? Py_True : Py_False;
    self->slots[SLOT_TEXTURE__HAS_UV_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_uv_transform(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__UV_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Transform_from(&self->data->uv_transform);
    self->slots[SLOT_TEXTURE__UV_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_texture_to_uv(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__TEXTURE_TO_UV];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_TEXTURE__TEXTURE_TO_UV] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_uv_to_texture(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__UV_TO_TEXTURE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_TEXTURE__UV_TO_TEXTURE] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Texture_getset[] = {
    { "type", (getter)Texture_get_type, NULL, "type" },
    { "filename", (getter)Texture_get_filename, NULL, "filename" },
    { "absolute_filename", (getter)Texture_get_absolute_filename, NULL, "absolute_filename" },
    { "relative_filename", (getter)Texture_get_relative_filename, NULL, "relative_filename" },
    { "raw_filename", (getter)Texture_get_raw_filename, NULL, "raw_filename" },
    { "raw_absolute_filename", (getter)Texture_get_raw_absolute_filename, NULL, "raw_absolute_filename" },
    { "raw_relative_filename", (getter)Texture_get_raw_relative_filename, NULL, "raw_relative_filename" },
    { "content", (getter)Texture_get_content, NULL, "content" },
    { "video", (getter)Texture_get_video, NULL, "video" },
    { "file_index", (getter)Texture_get_file_index, NULL, "file_index" },
    { "has_file", (getter)Texture_get_has_file, NULL, "has_file" },
    { "layers", (getter)Texture_get_layers, NULL, "layers" },
    { "shader", (getter)Texture_get_shader, NULL, "shader" },
    { "file_textures", (getter)Texture_get_file_textures, NULL, "file_textures" },
    { "uv_set", (getter)Texture_get_uv_set, NULL, "uv_set" },
    { "wrap_u", (getter)Texture_get_wrap_u, NULL, "wrap_u" },
    { "wrap_v", (getter)Texture_get_wrap_v, NULL, "wrap_v" },
    { "has_uv_transform", (getter)Texture_get_has_uv_transform, NULL, "has_uv_transform" },
    { "uv_transform", (getter)Texture_get_uv_transform, NULL, "uv_transform" },
    { "texture_to_uv", (getter)Texture_get_texture_to_uv, NULL, "texture_to_uv" },
    { "uv_to_texture", (getter)Texture_get_uv_to_texture, NULL, "uv_to_texture" },
    { NULL },
};

static PyTypeObject Texture_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Texture",
    .tp_doc = PyDoc_STR("Texture"),
    .tp_basicsize = sizeof(Texture),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Texture_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_VIDEO 7
enum {
    SLOT_VIDEO__FILENAME,
    SLOT_VIDEO__ABSOLUTE_FILENAME,
    SLOT_VIDEO__RELATIVE_FILENAME,
    SLOT_VIDEO__RAW_FILENAME,
    SLOT_VIDEO__RAW_ABSOLUTE_FILENAME,
    SLOT_VIDEO__RAW_RELATIVE_FILENAME,
    SLOT_VIDEO__CONTENT,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_video *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_VIDEO];
} Video;

static PyObject *Video_get_filename(Video *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VIDEO__FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->filename);
    self->slots[SLOT_VIDEO__FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Video_get_absolute_filename(Video *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VIDEO__ABSOLUTE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->absolute_filename);
    self->slots[SLOT_VIDEO__ABSOLUTE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Video_get_relative_filename(Video *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VIDEO__RELATIVE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->relative_filename);
    self->slots[SLOT_VIDEO__RELATIVE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Video_get_raw_filename(Video *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VIDEO__RAW_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_filename);
    self->slots[SLOT_VIDEO__RAW_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Video_get_raw_absolute_filename(Video *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VIDEO__RAW_ABSOLUTE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_absolute_filename);
    self->slots[SLOT_VIDEO__RAW_ABSOLUTE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Video_get_raw_relative_filename(Video *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VIDEO__RAW_RELATIVE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_relative_filename);
    self->slots[SLOT_VIDEO__RAW_RELATIVE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Video_get_content(Video *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VIDEO__CONTENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->content);
    self->slots[SLOT_VIDEO__CONTENT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Video_getset[] = {
    { "filename", (getter)Video_get_filename, NULL, "filename" },
    { "absolute_filename", (getter)Video_get_absolute_filename, NULL, "absolute_filename" },
    { "relative_filename", (getter)Video_get_relative_filename, NULL, "relative_filename" },
    { "raw_filename", (getter)Video_get_raw_filename, NULL, "raw_filename" },
    { "raw_absolute_filename", (getter)Video_get_raw_absolute_filename, NULL, "raw_absolute_filename" },
    { "raw_relative_filename", (getter)Video_get_raw_relative_filename, NULL, "raw_relative_filename" },
    { "content", (getter)Video_get_content, NULL, "content" },
    { NULL },
};

static PyTypeObject Video_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Video",
    .tp_doc = PyDoc_STR("Video"),
    .tp_basicsize = sizeof(Video),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Video_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_SHADER 2
enum {
    SLOT_SHADER__TYPE,
    SLOT_SHADER__BINDINGS,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_shader *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_SHADER];
} Shader;

static PyObject *Shader_get_type(Shader *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_shader_type");
    self->slots[SLOT_SHADER__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Shader_get_bindings(Shader *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER__BINDINGS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ShaderBindingList_from(self->data->bindings, self->ctx);
    self->slots[SLOT_SHADER__BINDINGS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Shader_getset[] = {
    { "type", (getter)Shader_get_type, NULL, "type" },
    { "bindings", (getter)Shader_get_bindings, NULL, "bindings" },
    { NULL },
};

static PyTypeObject Shader_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Shader",
    .tp_doc = PyDoc_STR("Shader"),
    .tp_basicsize = sizeof(Shader),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Shader_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_SHADER_PROP_BINDING 2
enum {
    SLOT_SHADER_PROP_BINDING__SHADER_PROP,
    SLOT_SHADER_PROP_BINDING__MATERIAL_PROP,
};

typedef struct {
    PyObject_HEAD
    ufbx_shader_prop_binding *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_SHADER_PROP_BINDING];
} ShaderPropBinding;

static PyObject *ShaderPropBinding_get_shader_prop(ShaderPropBinding *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_PROP_BINDING__SHADER_PROP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->shader_prop);
    self->slots[SLOT_SHADER_PROP_BINDING__SHADER_PROP] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderPropBinding_get_material_prop(ShaderPropBinding *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_PROP_BINDING__MATERIAL_PROP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->material_prop);
    self->slots[SLOT_SHADER_PROP_BINDING__MATERIAL_PROP] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef ShaderPropBinding_getset[] = {
    { "shader_prop", (getter)ShaderPropBinding_get_shader_prop, NULL, "shader_prop" },
    { "material_prop", (getter)ShaderPropBinding_get_material_prop, NULL, "material_prop" },
    { NULL },
};

static PyTypeObject ShaderPropBinding_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderPropBinding",
    .tp_doc = PyDoc_STR("ShaderPropBinding"),
    .tp_basicsize = sizeof(ShaderPropBinding),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = ShaderPropBinding_getset,
};

#define SLOT_COUNT_SHADER_BINDING 1
enum {
    SLOT_SHADER_BINDING__PROP_BINDINGS,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_shader_binding *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_SHADER_BINDING];
} ShaderBinding;

static PyObject *ShaderBinding_get_prop_bindings(ShaderBinding *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_BINDING__PROP_BINDINGS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ShaderPropBindingList_from(self->data->prop_bindings, self->ctx);
    self->slots[SLOT_SHADER_BINDING__PROP_BINDINGS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef ShaderBinding_getset[] = {
    { "prop_bindings", (getter)ShaderBinding_get_prop_bindings, NULL, "prop_bindings" },
    { NULL },
};

static PyTypeObject ShaderBinding_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderBinding",
    .tp_doc = PyDoc_STR("ShaderBinding"),
    .tp_basicsize = sizeof(ShaderBinding),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = ShaderBinding_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_PROP_OVERRIDE 5
enum {
    SLOT_PROP_OVERRIDE__ELEMENT_ID,
    SLOT_PROP_OVERRIDE__PROP_NAME,
    SLOT_PROP_OVERRIDE__VALUE,
    SLOT_PROP_OVERRIDE__VALUE_STR,
    SLOT_PROP_OVERRIDE__VALUE_INT,
};

typedef struct {
    PyObject_HEAD
    ufbx_prop_override *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_PROP_OVERRIDE];
} PropOverride;

static PyObject *PropOverride_get_element_id(PropOverride *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP_OVERRIDE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_PROP_OVERRIDE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *PropOverride_get_prop_name(PropOverride *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP_OVERRIDE__PROP_NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->prop_name);
    self->slots[SLOT_PROP_OVERRIDE__PROP_NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *PropOverride_get_value(PropOverride *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP_OVERRIDE__VALUE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec4_from(&self->data->value);
    self->slots[SLOT_PROP_OVERRIDE__VALUE] = slot;
    return Py_NewRef(slot);
}

static PyObject *PropOverride_get_value_str(PropOverride *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP_OVERRIDE__VALUE_STR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->value_str);
    self->slots[SLOT_PROP_OVERRIDE__VALUE_STR] = slot;
    return Py_NewRef(slot);
}

static PyObject *PropOverride_get_value_int(PropOverride *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP_OVERRIDE__VALUE_INT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromLongLong((long long)self->data->value_int);
    self->slots[SLOT_PROP_OVERRIDE__VALUE_INT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef PropOverride_getset[] = {
    { "element_id", (getter)PropOverride_get_element_id, NULL, "element_id" },
    { "prop_name", (getter)PropOverride_get_prop_name, NULL, "prop_name" },
    { "value", (getter)PropOverride_get_value, NULL, "value" },
    { "value_str", (getter)PropOverride_get_value_str, NULL, "value_str" },
    { "value_int", (getter)PropOverride_get_value_int, NULL, "value_int" },
    { NULL },
};

static PyTypeObject PropOverride_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.PropOverride",
    .tp_doc = PyDoc_STR("PropOverride"),
    .tp_basicsize = sizeof(PropOverride),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = PropOverride_getset,
};

#define SLOT_COUNT_ANIM 8
enum {
    SLOT_ANIM__TIME_BEGIN,
    SLOT_ANIM__TIME_END,
    SLOT_ANIM__LAYERS,
    SLOT_ANIM__OVERRIDE_LAYER_WEIGHTS,
    SLOT_ANIM__PROP_OVERRIDES,
    SLOT_ANIM__TRANSFORM_OVERRIDES,
    SLOT_ANIM__IGNORE_CONNECTIONS,
    SLOT_ANIM__CUSTOM,
};

typedef struct {
    PyObject_HEAD
    ufbx_anim *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_ANIM];
} Anim;

static PyObject *Anim_get_time_begin(Anim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM__TIME_BEGIN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->time_begin);
    self->slots[SLOT_ANIM__TIME_BEGIN] = slot;
    return Py_NewRef(slot);
}

static PyObject *Anim_get_time_end(Anim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM__TIME_END];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->time_end);
    self->slots[SLOT_ANIM__TIME_END] = slot;
    return Py_NewRef(slot);
}

static PyObject *Anim_get_layers(Anim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM__LAYERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AnimLayerList_from(self->data->layers, self->ctx);
    self->slots[SLOT_ANIM__LAYERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Anim_get_override_layer_weights(Anim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM__OVERRIDE_LAYER_WEIGHTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = RealList_from(self->data->override_layer_weights, self->ctx);
    self->slots[SLOT_ANIM__OVERRIDE_LAYER_WEIGHTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Anim_get_prop_overrides(Anim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM__PROP_OVERRIDES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PropOverrideList_from(self->data->prop_overrides, self->ctx);
    self->slots[SLOT_ANIM__PROP_OVERRIDES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Anim_get_transform_overrides(Anim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM__TRANSFORM_OVERRIDES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = TransformOverrideList_from(self->data->transform_overrides, self->ctx);
    self->slots[SLOT_ANIM__TRANSFORM_OVERRIDES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Anim_get_ignore_connections(Anim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM__IGNORE_CONNECTIONS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->ignore_connections ? Py_True : Py_False;
    self->slots[SLOT_ANIM__IGNORE_CONNECTIONS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Anim_get_custom(Anim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM__CUSTOM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->custom ? Py_True : Py_False;
    self->slots[SLOT_ANIM__CUSTOM] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Anim_getset[] = {
    { "time_begin", (getter)Anim_get_time_begin, NULL, "time_begin" },
    { "time_end", (getter)Anim_get_time_end, NULL, "time_end" },
    { "layers", (getter)Anim_get_layers, NULL, "layers" },
    { "override_layer_weights", (getter)Anim_get_override_layer_weights, NULL, "override_layer_weights" },
    { "prop_overrides", (getter)Anim_get_prop_overrides, NULL, "prop_overrides" },
    { "transform_overrides", (getter)Anim_get_transform_overrides, NULL, "transform_overrides" },
    { "ignore_connections", (getter)Anim_get_ignore_connections, NULL, "ignore_connections" },
    { "custom", (getter)Anim_get_custom, NULL, "custom" },
    { NULL },
};

static PyTypeObject Anim_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Anim",
    .tp_doc = PyDoc_STR("Anim"),
    .tp_basicsize = sizeof(Anim),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Anim_getset,
};

#define SLOT_COUNT_ANIM_STACK 4
enum {
    SLOT_ANIM_STACK__TIME_BEGIN,
    SLOT_ANIM_STACK__TIME_END,
    SLOT_ANIM_STACK__LAYERS,
    SLOT_ANIM_STACK__ANIM,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_anim_stack *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_ANIM_STACK];
} AnimStack;

static PyObject *AnimStack_get_time_begin(AnimStack *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_STACK__TIME_BEGIN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->time_begin);
    self->slots[SLOT_ANIM_STACK__TIME_BEGIN] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimStack_get_time_end(AnimStack *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_STACK__TIME_END];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->time_end);
    self->slots[SLOT_ANIM_STACK__TIME_END] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimStack_get_layers(AnimStack *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_STACK__LAYERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AnimLayerList_from(self->data->layers, self->ctx);
    self->slots[SLOT_ANIM_STACK__LAYERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimStack_get_anim(AnimStack *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_STACK__ANIM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_anim*");
    self->slots[SLOT_ANIM_STACK__ANIM] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef AnimStack_getset[] = {
    { "time_begin", (getter)AnimStack_get_time_begin, NULL, "time_begin" },
    { "time_end", (getter)AnimStack_get_time_end, NULL, "time_end" },
    { "layers", (getter)AnimStack_get_layers, NULL, "layers" },
    { "anim", (getter)AnimStack_get_anim, NULL, "anim" },
    { NULL },
};

static PyTypeObject AnimStack_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimStack",
    .tp_doc = PyDoc_STR("AnimStack"),
    .tp_basicsize = sizeof(AnimStack),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = AnimStack_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_ANIM_PROP 3
enum {
    SLOT_ANIM_PROP__ELEMENT,
    SLOT_ANIM_PROP__PROP_NAME,
    SLOT_ANIM_PROP__ANIM_VALUE,
};

typedef struct {
    PyObject_HEAD
    ufbx_anim_prop *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_ANIM_PROP];
} AnimProp;

static PyObject *AnimProp_get_element(AnimProp *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_PROP__ELEMENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_element*");
    self->slots[SLOT_ANIM_PROP__ELEMENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimProp_get_prop_name(AnimProp *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_PROP__PROP_NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->prop_name);
    self->slots[SLOT_ANIM_PROP__PROP_NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimProp_get_anim_value(AnimProp *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_PROP__ANIM_VALUE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->anim_value, self->ctx);
    self->slots[SLOT_ANIM_PROP__ANIM_VALUE] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef AnimProp_getset[] = {
    { "element", (getter)AnimProp_get_element, NULL, "element" },
    { "prop_name", (getter)AnimProp_get_prop_name, NULL, "prop_name" },
    { "anim_value", (getter)AnimProp_get_anim_value, NULL, "anim_value" },
    { NULL },
};

static PyTypeObject AnimProp_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimProp",
    .tp_doc = PyDoc_STR("AnimProp"),
    .tp_basicsize = sizeof(AnimProp),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = AnimProp_getset,
};

#define SLOT_COUNT_ANIM_LAYER 9
enum {
    SLOT_ANIM_LAYER__WEIGHT,
    SLOT_ANIM_LAYER__WEIGHT_IS_ANIMATED,
    SLOT_ANIM_LAYER__BLENDED,
    SLOT_ANIM_LAYER__ADDITIVE,
    SLOT_ANIM_LAYER__COMPOSE_ROTATION,
    SLOT_ANIM_LAYER__COMPOSE_SCALE,
    SLOT_ANIM_LAYER__ANIM_VALUES,
    SLOT_ANIM_LAYER__ANIM_PROPS,
    SLOT_ANIM_LAYER__ANIM,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_anim_layer *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_ANIM_LAYER];
} AnimLayer;

static PyObject *AnimLayer_get_weight(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__WEIGHT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->weight);
    self->slots[SLOT_ANIM_LAYER__WEIGHT] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_weight_is_animated(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__WEIGHT_IS_ANIMATED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->weight_is_animated ? Py_True : Py_False;
    self->slots[SLOT_ANIM_LAYER__WEIGHT_IS_ANIMATED] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_blended(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__BLENDED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->blended ? Py_True : Py_False;
    self->slots[SLOT_ANIM_LAYER__BLENDED] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_additive(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__ADDITIVE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->additive ? Py_True : Py_False;
    self->slots[SLOT_ANIM_LAYER__ADDITIVE] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_compose_rotation(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__COMPOSE_ROTATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->compose_rotation ? Py_True : Py_False;
    self->slots[SLOT_ANIM_LAYER__COMPOSE_ROTATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_compose_scale(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__COMPOSE_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->compose_scale ? Py_True : Py_False;
    self->slots[SLOT_ANIM_LAYER__COMPOSE_SCALE] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_anim_values(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__ANIM_VALUES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AnimValueList_from(self->data->anim_values, self->ctx);
    self->slots[SLOT_ANIM_LAYER__ANIM_VALUES] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_anim_props(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__ANIM_PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AnimPropList_from(self->data->anim_props, self->ctx);
    self->slots[SLOT_ANIM_LAYER__ANIM_PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_anim(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__ANIM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_anim*");
    self->slots[SLOT_ANIM_LAYER__ANIM] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef AnimLayer_getset[] = {
    { "weight", (getter)AnimLayer_get_weight, NULL, "weight" },
    { "weight_is_animated", (getter)AnimLayer_get_weight_is_animated, NULL, "weight_is_animated" },
    { "blended", (getter)AnimLayer_get_blended, NULL, "blended" },
    { "additive", (getter)AnimLayer_get_additive, NULL, "additive" },
    { "compose_rotation", (getter)AnimLayer_get_compose_rotation, NULL, "compose_rotation" },
    { "compose_scale", (getter)AnimLayer_get_compose_scale, NULL, "compose_scale" },
    { "anim_values", (getter)AnimLayer_get_anim_values, NULL, "anim_values" },
    { "anim_props", (getter)AnimLayer_get_anim_props, NULL, "anim_props" },
    { "anim", (getter)AnimLayer_get_anim, NULL, "anim" },
    { NULL },
};

static PyTypeObject AnimLayer_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimLayer",
    .tp_doc = PyDoc_STR("AnimLayer"),
    .tp_basicsize = sizeof(AnimLayer),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = AnimLayer_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_ANIM_VALUE 2
enum {
    SLOT_ANIM_VALUE__DEFAULT_VALUE,
    SLOT_ANIM_VALUE__CURVES,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_anim_value *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_ANIM_VALUE];
} AnimValue;

static PyObject *AnimValue_get_default_value(AnimValue *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_VALUE__DEFAULT_VALUE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->default_value);
    self->slots[SLOT_ANIM_VALUE__DEFAULT_VALUE] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimValue_get_curves(AnimValue *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_VALUE__CURVES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_anim_curve?*[3]");
    self->slots[SLOT_ANIM_VALUE__CURVES] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef AnimValue_getset[] = {
    { "default_value", (getter)AnimValue_get_default_value, NULL, "default_value" },
    { "curves", (getter)AnimValue_get_curves, NULL, "curves" },
    { NULL },
};

static PyTypeObject AnimValue_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimValue",
    .tp_doc = PyDoc_STR("AnimValue"),
    .tp_basicsize = sizeof(AnimValue),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = AnimValue_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_EXTRAPOLATION 2
enum {
    SLOT_EXTRAPOLATION__MODE,
    SLOT_EXTRAPOLATION__REPEAT_COUNT,
};

typedef struct {
    PyObject_HEAD
    ufbx_extrapolation *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_EXTRAPOLATION];
} Extrapolation;

static PyObject *Extrapolation_get_mode(Extrapolation *self, void *closure) {
    PyObject *slot = self->slots[SLOT_EXTRAPOLATION__MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_extrapolation_mode");
    self->slots[SLOT_EXTRAPOLATION__MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Extrapolation_get_repeat_count(Extrapolation *self, void *closure) {
    PyObject *slot = self->slots[SLOT_EXTRAPOLATION__REPEAT_COUNT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromLong((long)self->data->repeat_count);
    self->slots[SLOT_EXTRAPOLATION__REPEAT_COUNT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Extrapolation_getset[] = {
    { "mode", (getter)Extrapolation_get_mode, NULL, "mode" },
    { "repeat_count", (getter)Extrapolation_get_repeat_count, NULL, "repeat_count" },
    { NULL },
};

static PyTypeObject Extrapolation_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Extrapolation",
    .tp_doc = PyDoc_STR("Extrapolation"),
    .tp_basicsize = sizeof(Extrapolation),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Extrapolation_getset,
};

#define SLOT_COUNT_ANIM_CURVE 7
enum {
    SLOT_ANIM_CURVE__KEYFRAMES,
    SLOT_ANIM_CURVE__PRE_EXTRAPOLATION,
    SLOT_ANIM_CURVE__POST_EXTRAPOLATION,
    SLOT_ANIM_CURVE__MIN_VALUE,
    SLOT_ANIM_CURVE__MAX_VALUE,
    SLOT_ANIM_CURVE__MIN_TIME,
    SLOT_ANIM_CURVE__MAX_TIME,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_anim_curve *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_ANIM_CURVE];
} AnimCurve;

static PyObject *AnimCurve_get_keyframes(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__KEYFRAMES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = KeyframeList_from(self->data->keyframes, self->ctx);
    self->slots[SLOT_ANIM_CURVE__KEYFRAMES] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimCurve_get_pre_extrapolation(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__PRE_EXTRAPOLATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_extrapolation");
    self->slots[SLOT_ANIM_CURVE__PRE_EXTRAPOLATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimCurve_get_post_extrapolation(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__POST_EXTRAPOLATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_extrapolation");
    self->slots[SLOT_ANIM_CURVE__POST_EXTRAPOLATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimCurve_get_min_value(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__MIN_VALUE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->min_value);
    self->slots[SLOT_ANIM_CURVE__MIN_VALUE] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimCurve_get_max_value(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__MAX_VALUE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->max_value);
    self->slots[SLOT_ANIM_CURVE__MAX_VALUE] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimCurve_get_min_time(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__MIN_TIME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->min_time);
    self->slots[SLOT_ANIM_CURVE__MIN_TIME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimCurve_get_max_time(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__MAX_TIME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->max_time);
    self->slots[SLOT_ANIM_CURVE__MAX_TIME] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef AnimCurve_getset[] = {
    { "keyframes", (getter)AnimCurve_get_keyframes, NULL, "keyframes" },
    { "pre_extrapolation", (getter)AnimCurve_get_pre_extrapolation, NULL, "pre_extrapolation" },
    { "post_extrapolation", (getter)AnimCurve_get_post_extrapolation, NULL, "post_extrapolation" },
    { "min_value", (getter)AnimCurve_get_min_value, NULL, "min_value" },
    { "max_value", (getter)AnimCurve_get_max_value, NULL, "max_value" },
    { "min_time", (getter)AnimCurve_get_min_time, NULL, "min_time" },
    { "max_time", (getter)AnimCurve_get_max_time, NULL, "max_time" },
    { NULL },
};

static PyTypeObject AnimCurve_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimCurve",
    .tp_doc = PyDoc_STR("AnimCurve"),
    .tp_basicsize = sizeof(AnimCurve),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = AnimCurve_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_DISPLAY_LAYER 4
enum {
    SLOT_DISPLAY_LAYER__NODES,
    SLOT_DISPLAY_LAYER__VISIBLE,
    SLOT_DISPLAY_LAYER__FROZEN,
    SLOT_DISPLAY_LAYER__UI_COLOR,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_display_layer *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_DISPLAY_LAYER];
} DisplayLayer;

static PyObject *DisplayLayer_get_nodes(DisplayLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DISPLAY_LAYER__NODES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->nodes, self->ctx);
    self->slots[SLOT_DISPLAY_LAYER__NODES] = slot;
    return Py_NewRef(slot);
}

static PyObject *DisplayLayer_get_visible(DisplayLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DISPLAY_LAYER__VISIBLE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->visible ? Py_True : Py_False;
    self->slots[SLOT_DISPLAY_LAYER__VISIBLE] = slot;
    return Py_NewRef(slot);
}

static PyObject *DisplayLayer_get_frozen(DisplayLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DISPLAY_LAYER__FROZEN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->frozen ? Py_True : Py_False;
    self->slots[SLOT_DISPLAY_LAYER__FROZEN] = slot;
    return Py_NewRef(slot);
}

static PyObject *DisplayLayer_get_ui_color(DisplayLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DISPLAY_LAYER__UI_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->ui_color);
    self->slots[SLOT_DISPLAY_LAYER__UI_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef DisplayLayer_getset[] = {
    { "nodes", (getter)DisplayLayer_get_nodes, NULL, "nodes" },
    { "visible", (getter)DisplayLayer_get_visible, NULL, "visible" },
    { "frozen", (getter)DisplayLayer_get_frozen, NULL, "frozen" },
    { "ui_color", (getter)DisplayLayer_get_ui_color, NULL, "ui_color" },
    { NULL },
};

static PyTypeObject DisplayLayer_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DisplayLayer",
    .tp_doc = PyDoc_STR("DisplayLayer"),
    .tp_basicsize = sizeof(DisplayLayer),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = DisplayLayer_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_SELECTION_SET 1
enum {
    SLOT_SELECTION_SET__NODES,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_selection_set *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_SELECTION_SET];
} SelectionSet;

static PyObject *SelectionSet_get_nodes(SelectionSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_SET__NODES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SelectionNodeList_from(self->data->nodes, self->ctx);
    self->slots[SLOT_SELECTION_SET__NODES] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef SelectionSet_getset[] = {
    { "nodes", (getter)SelectionSet_get_nodes, NULL, "nodes" },
    { NULL },
};

static PyTypeObject SelectionSet_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SelectionSet",
    .tp_doc = PyDoc_STR("SelectionSet"),
    .tp_basicsize = sizeof(SelectionSet),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = SelectionSet_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_SELECTION_NODE 6
enum {
    SLOT_SELECTION_NODE__TARGET_NODE,
    SLOT_SELECTION_NODE__TARGET_MESH,
    SLOT_SELECTION_NODE__INCLUDE_NODE,
    SLOT_SELECTION_NODE__VERTICES,
    SLOT_SELECTION_NODE__EDGES,
    SLOT_SELECTION_NODE__FACES,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_selection_node *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_SELECTION_NODE];
} SelectionNode;

static PyObject *SelectionNode_get_target_node(SelectionNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_NODE__TARGET_NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->target_node, self->ctx);
    self->slots[SLOT_SELECTION_NODE__TARGET_NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionNode_get_target_mesh(SelectionNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_NODE__TARGET_MESH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->target_mesh, self->ctx);
    self->slots[SLOT_SELECTION_NODE__TARGET_MESH] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionNode_get_include_node(SelectionNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_NODE__INCLUDE_NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->include_node ? Py_True : Py_False;
    self->slots[SLOT_SELECTION_NODE__INCLUDE_NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionNode_get_vertices(SelectionNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_NODE__VERTICES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->vertices, self->ctx);
    self->slots[SLOT_SELECTION_NODE__VERTICES] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionNode_get_edges(SelectionNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_NODE__EDGES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->edges, self->ctx);
    self->slots[SLOT_SELECTION_NODE__EDGES] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionNode_get_faces(SelectionNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_NODE__FACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Uint32List_from(self->data->faces, self->ctx);
    self->slots[SLOT_SELECTION_NODE__FACES] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef SelectionNode_getset[] = {
    { "target_node", (getter)SelectionNode_get_target_node, NULL, "target_node" },
    { "target_mesh", (getter)SelectionNode_get_target_mesh, NULL, "target_mesh" },
    { "include_node", (getter)SelectionNode_get_include_node, NULL, "include_node" },
    { "vertices", (getter)SelectionNode_get_vertices, NULL, "vertices" },
    { "edges", (getter)SelectionNode_get_edges, NULL, "edges" },
    { "faces", (getter)SelectionNode_get_faces, NULL, "faces" },
    { NULL },
};

static PyTypeObject SelectionNode_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SelectionNode",
    .tp_doc = PyDoc_STR("SelectionNode"),
    .tp_basicsize = sizeof(SelectionNode),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = SelectionNode_getset,
    .tp_base = &Element_Type,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_character *data;
            Context *ctx;
        };
    };
} Character;

static PyTypeObject Character_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Character",
    .tp_doc = PyDoc_STR("Character"),
    .tp_basicsize = sizeof(Character),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_CONSTRAINT_TARGET 3
enum {
    SLOT_CONSTRAINT_TARGET__NODE,
    SLOT_CONSTRAINT_TARGET__WEIGHT,
    SLOT_CONSTRAINT_TARGET__TRANSFORM,
};

typedef struct {
    PyObject_HEAD
    ufbx_constraint_target *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_CONSTRAINT_TARGET];
} ConstraintTarget;

static PyObject *ConstraintTarget_get_node(ConstraintTarget *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT_TARGET__NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->node, self->ctx);
    self->slots[SLOT_CONSTRAINT_TARGET__NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *ConstraintTarget_get_weight(ConstraintTarget *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT_TARGET__WEIGHT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->weight);
    self->slots[SLOT_CONSTRAINT_TARGET__WEIGHT] = slot;
    return Py_NewRef(slot);
}

static PyObject *ConstraintTarget_get_transform(ConstraintTarget *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT_TARGET__TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Transform_from(&self->data->transform);
    self->slots[SLOT_CONSTRAINT_TARGET__TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef ConstraintTarget_getset[] = {
    { "node", (getter)ConstraintTarget_get_node, NULL, "node" },
    { "weight", (getter)ConstraintTarget_get_weight, NULL, "weight" },
    { "transform", (getter)ConstraintTarget_get_transform, NULL, "transform" },
    { NULL },
};

static PyTypeObject ConstraintTarget_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstraintTarget",
    .tp_doc = PyDoc_STR("ConstraintTarget"),
    .tp_basicsize = sizeof(ConstraintTarget),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = ConstraintTarget_getset,
};

#define SLOT_COUNT_CONSTRAINT 17
enum {
    SLOT_CONSTRAINT__TYPE,
    SLOT_CONSTRAINT__TYPE_NAME,
    SLOT_CONSTRAINT__NODE,
    SLOT_CONSTRAINT__TARGETS,
    SLOT_CONSTRAINT__WEIGHT,
    SLOT_CONSTRAINT__ACTIVE,
    SLOT_CONSTRAINT__CONSTRAIN_TRANSLATION,
    SLOT_CONSTRAINT__CONSTRAIN_ROTATION,
    SLOT_CONSTRAINT__CONSTRAIN_SCALE,
    SLOT_CONSTRAINT__TRANSFORM_OFFSET,
    SLOT_CONSTRAINT__AIM_VECTOR,
    SLOT_CONSTRAINT__AIM_UP_TYPE,
    SLOT_CONSTRAINT__AIM_UP_NODE,
    SLOT_CONSTRAINT__AIM_UP_VECTOR,
    SLOT_CONSTRAINT__IK_EFFECTOR,
    SLOT_CONSTRAINT__IK_END_NODE,
    SLOT_CONSTRAINT__IK_POLE_VECTOR,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_constraint *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_CONSTRAINT];
} Constraint;

static PyObject *Constraint_get_type(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_constraint_type");
    self->slots[SLOT_CONSTRAINT__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_type_name(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__TYPE_NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->type_name);
    self->slots[SLOT_CONSTRAINT__TYPE_NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_node(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->node, self->ctx);
    self->slots[SLOT_CONSTRAINT__NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_targets(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__TARGETS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ConstraintTargetList_from(self->data->targets, self->ctx);
    self->slots[SLOT_CONSTRAINT__TARGETS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_weight(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__WEIGHT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->weight);
    self->slots[SLOT_CONSTRAINT__WEIGHT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_active(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__ACTIVE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->active ? Py_True : Py_False;
    self->slots[SLOT_CONSTRAINT__ACTIVE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_constrain_translation(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__CONSTRAIN_TRANSLATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("bool[3]");
    self->slots[SLOT_CONSTRAINT__CONSTRAIN_TRANSLATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_constrain_rotation(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__CONSTRAIN_ROTATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("bool[3]");
    self->slots[SLOT_CONSTRAINT__CONSTRAIN_ROTATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_constrain_scale(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__CONSTRAIN_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("bool[3]");
    self->slots[SLOT_CONSTRAINT__CONSTRAIN_SCALE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_transform_offset(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__TRANSFORM_OFFSET];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Transform_from(&self->data->transform_offset);
    self->slots[SLOT_CONSTRAINT__TRANSFORM_OFFSET] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_aim_vector(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__AIM_VECTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->aim_vector);
    self->slots[SLOT_CONSTRAINT__AIM_VECTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_aim_up_type(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__AIM_UP_TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_constraint_aim_up_type");
    self->slots[SLOT_CONSTRAINT__AIM_UP_TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_aim_up_node(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__AIM_UP_NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->aim_up_node, self->ctx);
    self->slots[SLOT_CONSTRAINT__AIM_UP_NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_aim_up_vector(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__AIM_UP_VECTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->aim_up_vector);
    self->slots[SLOT_CONSTRAINT__AIM_UP_VECTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_ik_effector(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__IK_EFFECTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->ik_effector, self->ctx);
    self->slots[SLOT_CONSTRAINT__IK_EFFECTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_ik_end_node(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__IK_END_NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->ik_end_node, self->ctx);
    self->slots[SLOT_CONSTRAINT__IK_END_NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_ik_pole_vector(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__IK_POLE_VECTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->ik_pole_vector);
    self->slots[SLOT_CONSTRAINT__IK_POLE_VECTOR] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Constraint_getset[] = {
    { "type", (getter)Constraint_get_type, NULL, "type" },
    { "type_name", (getter)Constraint_get_type_name, NULL, "type_name" },
    { "node", (getter)Constraint_get_node, NULL, "node" },
    { "targets", (getter)Constraint_get_targets, NULL, "targets" },
    { "weight", (getter)Constraint_get_weight, NULL, "weight" },
    { "active", (getter)Constraint_get_active, NULL, "active" },
    { "constrain_translation", (getter)Constraint_get_constrain_translation, NULL, "constrain_translation" },
    { "constrain_rotation", (getter)Constraint_get_constrain_rotation, NULL, "constrain_rotation" },
    { "constrain_scale", (getter)Constraint_get_constrain_scale, NULL, "constrain_scale" },
    { "transform_offset", (getter)Constraint_get_transform_offset, NULL, "transform_offset" },
    { "aim_vector", (getter)Constraint_get_aim_vector, NULL, "aim_vector" },
    { "aim_up_type", (getter)Constraint_get_aim_up_type, NULL, "aim_up_type" },
    { "aim_up_node", (getter)Constraint_get_aim_up_node, NULL, "aim_up_node" },
    { "aim_up_vector", (getter)Constraint_get_aim_up_vector, NULL, "aim_up_vector" },
    { "ik_effector", (getter)Constraint_get_ik_effector, NULL, "ik_effector" },
    { "ik_end_node", (getter)Constraint_get_ik_end_node, NULL, "ik_end_node" },
    { "ik_pole_vector", (getter)Constraint_get_ik_pole_vector, NULL, "ik_pole_vector" },
    { NULL },
};

static PyTypeObject Constraint_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Constraint",
    .tp_doc = PyDoc_STR("Constraint"),
    .tp_basicsize = sizeof(Constraint),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Constraint_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_AUDIO_LAYER 1
enum {
    SLOT_AUDIO_LAYER__CLIPS,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_audio_layer *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_AUDIO_LAYER];
} AudioLayer;

static PyObject *AudioLayer_get_clips(AudioLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_LAYER__CLIPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AudioClipList_from(self->data->clips, self->ctx);
    self->slots[SLOT_AUDIO_LAYER__CLIPS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef AudioLayer_getset[] = {
    { "clips", (getter)AudioLayer_get_clips, NULL, "clips" },
    { NULL },
};

static PyTypeObject AudioLayer_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AudioLayer",
    .tp_doc = PyDoc_STR("AudioLayer"),
    .tp_basicsize = sizeof(AudioLayer),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = AudioLayer_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_AUDIO_CLIP 7
enum {
    SLOT_AUDIO_CLIP__FILENAME,
    SLOT_AUDIO_CLIP__ABSOLUTE_FILENAME,
    SLOT_AUDIO_CLIP__RELATIVE_FILENAME,
    SLOT_AUDIO_CLIP__RAW_FILENAME,
    SLOT_AUDIO_CLIP__RAW_ABSOLUTE_FILENAME,
    SLOT_AUDIO_CLIP__RAW_RELATIVE_FILENAME,
    SLOT_AUDIO_CLIP__CONTENT,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_audio_clip *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_AUDIO_CLIP];
} AudioClip;

static PyObject *AudioClip_get_filename(AudioClip *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_CLIP__FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->filename);
    self->slots[SLOT_AUDIO_CLIP__FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioClip_get_absolute_filename(AudioClip *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_CLIP__ABSOLUTE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->absolute_filename);
    self->slots[SLOT_AUDIO_CLIP__ABSOLUTE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioClip_get_relative_filename(AudioClip *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_CLIP__RELATIVE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->relative_filename);
    self->slots[SLOT_AUDIO_CLIP__RELATIVE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioClip_get_raw_filename(AudioClip *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_CLIP__RAW_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_filename);
    self->slots[SLOT_AUDIO_CLIP__RAW_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioClip_get_raw_absolute_filename(AudioClip *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_CLIP__RAW_ABSOLUTE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_absolute_filename);
    self->slots[SLOT_AUDIO_CLIP__RAW_ABSOLUTE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioClip_get_raw_relative_filename(AudioClip *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_CLIP__RAW_RELATIVE_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_relative_filename);
    self->slots[SLOT_AUDIO_CLIP__RAW_RELATIVE_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioClip_get_content(AudioClip *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_CLIP__CONTENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->content);
    self->slots[SLOT_AUDIO_CLIP__CONTENT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef AudioClip_getset[] = {
    { "filename", (getter)AudioClip_get_filename, NULL, "filename" },
    { "absolute_filename", (getter)AudioClip_get_absolute_filename, NULL, "absolute_filename" },
    { "relative_filename", (getter)AudioClip_get_relative_filename, NULL, "relative_filename" },
    { "raw_filename", (getter)AudioClip_get_raw_filename, NULL, "raw_filename" },
    { "raw_absolute_filename", (getter)AudioClip_get_raw_absolute_filename, NULL, "raw_absolute_filename" },
    { "raw_relative_filename", (getter)AudioClip_get_raw_relative_filename, NULL, "raw_relative_filename" },
    { "content", (getter)AudioClip_get_content, NULL, "content" },
    { NULL },
};

static PyTypeObject AudioClip_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AudioClip",
    .tp_doc = PyDoc_STR("AudioClip"),
    .tp_basicsize = sizeof(AudioClip),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = AudioClip_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_BONE_POSE 3
enum {
    SLOT_BONE_POSE__BONE_NODE,
    SLOT_BONE_POSE__BONE_TO_WORLD,
    SLOT_BONE_POSE__BONE_TO_PARENT,
};

typedef struct {
    PyObject_HEAD
    ufbx_bone_pose *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_BONE_POSE];
} BonePose;

static PyObject *BonePose_get_bone_node(BonePose *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE_POSE__BONE_NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->bone_node, self->ctx);
    self->slots[SLOT_BONE_POSE__BONE_NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *BonePose_get_bone_to_world(BonePose *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE_POSE__BONE_TO_WORLD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_BONE_POSE__BONE_TO_WORLD] = slot;
    return Py_NewRef(slot);
}

static PyObject *BonePose_get_bone_to_parent(BonePose *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE_POSE__BONE_TO_PARENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_matrix");
    self->slots[SLOT_BONE_POSE__BONE_TO_PARENT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BonePose_getset[] = {
    { "bone_node", (getter)BonePose_get_bone_node, NULL, "bone_node" },
    { "bone_to_world", (getter)BonePose_get_bone_to_world, NULL, "bone_to_world" },
    { "bone_to_parent", (getter)BonePose_get_bone_to_parent, NULL, "bone_to_parent" },
    { NULL },
};

static PyTypeObject BonePose_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BonePose",
    .tp_doc = PyDoc_STR("BonePose"),
    .tp_basicsize = sizeof(BonePose),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BonePose_getset,
};

#define SLOT_COUNT_POSE 2
enum {
    SLOT_POSE__IS_BIND_POSE,
    SLOT_POSE__BONE_POSES,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_pose *data;
            Context *ctx;
        };
    };
    PyObject *slots[SLOT_COUNT_POSE];
} Pose;

static PyObject *Pose_get_is_bind_pose(Pose *self, void *closure) {
    PyObject *slot = self->slots[SLOT_POSE__IS_BIND_POSE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->is_bind_pose ? Py_True : Py_False;
    self->slots[SLOT_POSE__IS_BIND_POSE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Pose_get_bone_poses(Pose *self, void *closure) {
    PyObject *slot = self->slots[SLOT_POSE__BONE_POSES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BonePoseList_from(self->data->bone_poses, self->ctx);
    self->slots[SLOT_POSE__BONE_POSES] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Pose_getset[] = {
    { "is_bind_pose", (getter)Pose_get_is_bind_pose, NULL, "is_bind_pose" },
    { "bone_poses", (getter)Pose_get_bone_poses, NULL, "bone_poses" },
    { NULL },
};

static PyTypeObject Pose_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Pose",
    .tp_doc = PyDoc_STR("Pose"),
    .tp_basicsize = sizeof(Pose),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Pose_getset,
    .tp_base = &Element_Type,
};

typedef struct {
    union {
        Element elem;
        struct {
            PyObject_HEAD
            ufbx_metadata_object *data;
            Context *ctx;
        };
    };
} MetadataObject;

static PyTypeObject MetadataObject_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MetadataObject",
    .tp_doc = PyDoc_STR("MetadataObject"),
    .tp_basicsize = sizeof(MetadataObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_NAME_ELEMENT 3
enum {
    SLOT_NAME_ELEMENT__NAME,
    SLOT_NAME_ELEMENT__TYPE,
    SLOT_NAME_ELEMENT__ELEMENT,
};

typedef struct {
    PyObject_HEAD
    ufbx_name_element *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_NAME_ELEMENT];
} NameElement;

static PyObject *NameElement_get_name(NameElement *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NAME_ELEMENT__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_NAME_ELEMENT__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *NameElement_get_type(NameElement *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NAME_ELEMENT__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_element_type");
    self->slots[SLOT_NAME_ELEMENT__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *NameElement_get_element(NameElement *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NAME_ELEMENT__ELEMENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_element*");
    self->slots[SLOT_NAME_ELEMENT__ELEMENT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef NameElement_getset[] = {
    { "name", (getter)NameElement_get_name, NULL, "name" },
    { "type", (getter)NameElement_get_type, NULL, "type" },
    { "element", (getter)NameElement_get_element, NULL, "element" },
    { NULL },
};

static PyTypeObject NameElement_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NameElement",
    .tp_doc = PyDoc_STR("NameElement"),
    .tp_basicsize = sizeof(NameElement),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = NameElement_getset,
};

#define SLOT_COUNT_APPLICATION 3
enum {
    SLOT_APPLICATION__VENDOR,
    SLOT_APPLICATION__NAME,
    SLOT_APPLICATION__VERSION,
};

typedef struct {
    PyObject_HEAD
    ufbx_application *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_APPLICATION];
} Application;

static PyObject *Application_get_vendor(Application *self, void *closure) {
    PyObject *slot = self->slots[SLOT_APPLICATION__VENDOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->vendor);
    self->slots[SLOT_APPLICATION__VENDOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *Application_get_name(Application *self, void *closure) {
    PyObject *slot = self->slots[SLOT_APPLICATION__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_APPLICATION__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Application_get_version(Application *self, void *closure) {
    PyObject *slot = self->slots[SLOT_APPLICATION__VERSION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->version);
    self->slots[SLOT_APPLICATION__VERSION] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Application_getset[] = {
    { "vendor", (getter)Application_get_vendor, NULL, "vendor" },
    { "name", (getter)Application_get_name, NULL, "name" },
    { "version", (getter)Application_get_version, NULL, "version" },
    { NULL },
};

static PyTypeObject Application_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Application",
    .tp_doc = PyDoc_STR("Application"),
    .tp_basicsize = sizeof(Application),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Application_getset,
};

#define SLOT_COUNT_WARNING 4
enum {
    SLOT_WARNING__TYPE,
    SLOT_WARNING__DESCRIPTION,
    SLOT_WARNING__ELEMENT_ID,
    SLOT_WARNING__COUNT,
};

typedef struct {
    PyObject_HEAD
    ufbx_warning *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_WARNING];
} Warning;

static PyObject *Warning_get_type(Warning *self, void *closure) {
    PyObject *slot = self->slots[SLOT_WARNING__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_warning_type");
    self->slots[SLOT_WARNING__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Warning_get_description(Warning *self, void *closure) {
    PyObject *slot = self->slots[SLOT_WARNING__DESCRIPTION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->description);
    self->slots[SLOT_WARNING__DESCRIPTION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Warning_get_element_id(Warning *self, void *closure) {
    PyObject *slot = self->slots[SLOT_WARNING__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_WARNING__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Warning_get_count(Warning *self, void *closure) {
    PyObject *slot = self->slots[SLOT_WARNING__COUNT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->count);
    self->slots[SLOT_WARNING__COUNT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Warning_getset[] = {
    { "type", (getter)Warning_get_type, NULL, "type" },
    { "description", (getter)Warning_get_description, NULL, "description" },
    { "element_id", (getter)Warning_get_element_id, NULL, "element_id" },
    { "count", (getter)Warning_get_count, NULL, "count" },
    { NULL },
};

static PyTypeObject Warning_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Warning",
    .tp_doc = PyDoc_STR("Warning"),
    .tp_basicsize = sizeof(Warning),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Warning_getset,
};

#define SLOT_COUNT_THUMBNAIL 5
enum {
    SLOT_THUMBNAIL__PROPS,
    SLOT_THUMBNAIL__WIDTH,
    SLOT_THUMBNAIL__HEIGHT,
    SLOT_THUMBNAIL__FORMAT,
    SLOT_THUMBNAIL__DATA,
};

typedef struct {
    PyObject_HEAD
    ufbx_thumbnail *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_THUMBNAIL];
} Thumbnail;

static PyObject *Thumbnail_get_props(Thumbnail *self, void *closure) {
    PyObject *slot = self->slots[SLOT_THUMBNAIL__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_props");
    self->slots[SLOT_THUMBNAIL__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Thumbnail_get_width(Thumbnail *self, void *closure) {
    PyObject *slot = self->slots[SLOT_THUMBNAIL__WIDTH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->width);
    self->slots[SLOT_THUMBNAIL__WIDTH] = slot;
    return Py_NewRef(slot);
}

static PyObject *Thumbnail_get_height(Thumbnail *self, void *closure) {
    PyObject *slot = self->slots[SLOT_THUMBNAIL__HEIGHT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->height);
    self->slots[SLOT_THUMBNAIL__HEIGHT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Thumbnail_get_format(Thumbnail *self, void *closure) {
    PyObject *slot = self->slots[SLOT_THUMBNAIL__FORMAT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_thumbnail_format");
    self->slots[SLOT_THUMBNAIL__FORMAT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Thumbnail_get_data(Thumbnail *self, void *closure) {
    PyObject *slot = self->slots[SLOT_THUMBNAIL__DATA];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->data);
    self->slots[SLOT_THUMBNAIL__DATA] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Thumbnail_getset[] = {
    { "props", (getter)Thumbnail_get_props, NULL, "props" },
    { "width", (getter)Thumbnail_get_width, NULL, "width" },
    { "height", (getter)Thumbnail_get_height, NULL, "height" },
    { "format", (getter)Thumbnail_get_format, NULL, "format" },
    { "data", (getter)Thumbnail_get_data, NULL, "data" },
    { NULL },
};

static PyTypeObject Thumbnail_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Thumbnail",
    .tp_doc = PyDoc_STR("Thumbnail"),
    .tp_basicsize = sizeof(Thumbnail),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Thumbnail_getset,
};

#define SLOT_COUNT_METADATA 46
enum {
    SLOT_METADATA__WARNINGS,
    SLOT_METADATA__ASCII,
    SLOT_METADATA__VERSION,
    SLOT_METADATA__FILE_FORMAT,
    SLOT_METADATA__MAY_CONTAIN_NO_INDEX,
    SLOT_METADATA__MAY_CONTAIN_MISSING_VERTEX_POSITION,
    SLOT_METADATA__MAY_CONTAIN_BROKEN_ELEMENTS,
    SLOT_METADATA__IS_UNSAFE,
    SLOT_METADATA__HAS_WARNING,
    SLOT_METADATA__CREATOR,
    SLOT_METADATA__BIG_ENDIAN,
    SLOT_METADATA__FILENAME,
    SLOT_METADATA__RELATIVE_ROOT,
    SLOT_METADATA__RAW_FILENAME,
    SLOT_METADATA__RAW_RELATIVE_ROOT,
    SLOT_METADATA__EXPORTER,
    SLOT_METADATA__EXPORTER_VERSION,
    SLOT_METADATA__SCENE_PROPS,
    SLOT_METADATA__ORIGINAL_APPLICATION,
    SLOT_METADATA__LATEST_APPLICATION,
    SLOT_METADATA__THUMBNAIL,
    SLOT_METADATA__GEOMETRY_IGNORED,
    SLOT_METADATA__ANIMATION_IGNORED,
    SLOT_METADATA__EMBEDDED_IGNORED,
    SLOT_METADATA__MAX_FACE_TRIANGLES,
    SLOT_METADATA__RESULT_MEMORY_USED,
    SLOT_METADATA__TEMP_MEMORY_USED,
    SLOT_METADATA__RESULT_ALLOCS,
    SLOT_METADATA__TEMP_ALLOCS,
    SLOT_METADATA__ELEMENT_BUFFER_SIZE,
    SLOT_METADATA__NUM_SHADER_TEXTURES,
    SLOT_METADATA__BONE_PROP_SIZE_UNIT,
    SLOT_METADATA__BONE_PROP_LIMB_LENGTH_RELATIVE,
    SLOT_METADATA__ORTHO_SIZE_UNIT,
    SLOT_METADATA__KTIME_SECOND,
    SLOT_METADATA__ORIGINAL_FILE_PATH,
    SLOT_METADATA__RAW_ORIGINAL_FILE_PATH,
    SLOT_METADATA__SPACE_CONVERSION,
    SLOT_METADATA__GEOMETRY_TRANSFORM_HANDLING,
    SLOT_METADATA__INHERIT_MODE_HANDLING,
    SLOT_METADATA__PIVOT_HANDLING,
    SLOT_METADATA__HANDEDNESS_CONVERSION_AXIS,
    SLOT_METADATA__ROOT_ROTATION,
    SLOT_METADATA__ROOT_SCALE,
    SLOT_METADATA__MIRROR_AXIS,
    SLOT_METADATA__GEOMETRY_SCALE,
};

typedef struct {
    PyObject_HEAD
    ufbx_metadata *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_METADATA];
} Metadata;

static PyObject *Metadata_get_warnings(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__WARNINGS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = WarningList_from(self->data->warnings, self->ctx);
    self->slots[SLOT_METADATA__WARNINGS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_ascii(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__ASCII];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->ascii ? Py_True : Py_False;
    self->slots[SLOT_METADATA__ASCII] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_version(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__VERSION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->version);
    self->slots[SLOT_METADATA__VERSION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_file_format(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__FILE_FORMAT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_file_format");
    self->slots[SLOT_METADATA__FILE_FORMAT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_may_contain_no_index(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__MAY_CONTAIN_NO_INDEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->may_contain_no_index ? Py_True : Py_False;
    self->slots[SLOT_METADATA__MAY_CONTAIN_NO_INDEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_may_contain_missing_vertex_position(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__MAY_CONTAIN_MISSING_VERTEX_POSITION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->may_contain_missing_vertex_position ? Py_True : Py_False;
    self->slots[SLOT_METADATA__MAY_CONTAIN_MISSING_VERTEX_POSITION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_may_contain_broken_elements(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__MAY_CONTAIN_BROKEN_ELEMENTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->may_contain_broken_elements ? Py_True : Py_False;
    self->slots[SLOT_METADATA__MAY_CONTAIN_BROKEN_ELEMENTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_is_unsafe(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__IS_UNSAFE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->is_unsafe ? Py_True : Py_False;
    self->slots[SLOT_METADATA__IS_UNSAFE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_has_warning(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__HAS_WARNING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("bool[15]");
    self->slots[SLOT_METADATA__HAS_WARNING] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_creator(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__CREATOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->creator);
    self->slots[SLOT_METADATA__CREATOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_big_endian(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__BIG_ENDIAN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->big_endian ? Py_True : Py_False;
    self->slots[SLOT_METADATA__BIG_ENDIAN] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_filename(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->filename);
    self->slots[SLOT_METADATA__FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_relative_root(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__RELATIVE_ROOT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->relative_root);
    self->slots[SLOT_METADATA__RELATIVE_ROOT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_raw_filename(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__RAW_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_filename);
    self->slots[SLOT_METADATA__RAW_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_raw_relative_root(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__RAW_RELATIVE_ROOT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_relative_root);
    self->slots[SLOT_METADATA__RAW_RELATIVE_ROOT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_exporter(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__EXPORTER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_exporter");
    self->slots[SLOT_METADATA__EXPORTER] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_exporter_version(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__EXPORTER_VERSION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->exporter_version);
    self->slots[SLOT_METADATA__EXPORTER_VERSION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_scene_props(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__SCENE_PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_props");
    self->slots[SLOT_METADATA__SCENE_PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_original_application(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__ORIGINAL_APPLICATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_application");
    self->slots[SLOT_METADATA__ORIGINAL_APPLICATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_latest_application(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__LATEST_APPLICATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_application");
    self->slots[SLOT_METADATA__LATEST_APPLICATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_thumbnail(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__THUMBNAIL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_thumbnail");
    self->slots[SLOT_METADATA__THUMBNAIL] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_geometry_ignored(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__GEOMETRY_IGNORED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->geometry_ignored ? Py_True : Py_False;
    self->slots[SLOT_METADATA__GEOMETRY_IGNORED] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_animation_ignored(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__ANIMATION_IGNORED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->animation_ignored ? Py_True : Py_False;
    self->slots[SLOT_METADATA__ANIMATION_IGNORED] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_embedded_ignored(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__EMBEDDED_IGNORED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->embedded_ignored ? Py_True : Py_False;
    self->slots[SLOT_METADATA__EMBEDDED_IGNORED] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_max_face_triangles(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__MAX_FACE_TRIANGLES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->max_face_triangles);
    self->slots[SLOT_METADATA__MAX_FACE_TRIANGLES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_result_memory_used(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__RESULT_MEMORY_USED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->result_memory_used);
    self->slots[SLOT_METADATA__RESULT_MEMORY_USED] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_temp_memory_used(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__TEMP_MEMORY_USED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->temp_memory_used);
    self->slots[SLOT_METADATA__TEMP_MEMORY_USED] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_result_allocs(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__RESULT_ALLOCS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->result_allocs);
    self->slots[SLOT_METADATA__RESULT_ALLOCS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_temp_allocs(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__TEMP_ALLOCS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->temp_allocs);
    self->slots[SLOT_METADATA__TEMP_ALLOCS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_element_buffer_size(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__ELEMENT_BUFFER_SIZE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->element_buffer_size);
    self->slots[SLOT_METADATA__ELEMENT_BUFFER_SIZE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_num_shader_textures(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__NUM_SHADER_TEXTURES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->num_shader_textures);
    self->slots[SLOT_METADATA__NUM_SHADER_TEXTURES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_bone_prop_size_unit(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__BONE_PROP_SIZE_UNIT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->bone_prop_size_unit);
    self->slots[SLOT_METADATA__BONE_PROP_SIZE_UNIT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_bone_prop_limb_length_relative(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__BONE_PROP_LIMB_LENGTH_RELATIVE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->bone_prop_limb_length_relative ? Py_True : Py_False;
    self->slots[SLOT_METADATA__BONE_PROP_LIMB_LENGTH_RELATIVE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_ortho_size_unit(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__ORTHO_SIZE_UNIT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->ortho_size_unit);
    self->slots[SLOT_METADATA__ORTHO_SIZE_UNIT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_ktime_second(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__KTIME_SECOND];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromLongLong((long long)self->data->ktime_second);
    self->slots[SLOT_METADATA__KTIME_SECOND] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_original_file_path(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__ORIGINAL_FILE_PATH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->original_file_path);
    self->slots[SLOT_METADATA__ORIGINAL_FILE_PATH] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_raw_original_file_path(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__RAW_ORIGINAL_FILE_PATH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->raw_original_file_path);
    self->slots[SLOT_METADATA__RAW_ORIGINAL_FILE_PATH] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_space_conversion(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__SPACE_CONVERSION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_space_conversion");
    self->slots[SLOT_METADATA__SPACE_CONVERSION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_geometry_transform_handling(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__GEOMETRY_TRANSFORM_HANDLING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_geometry_transform_handling");
    self->slots[SLOT_METADATA__GEOMETRY_TRANSFORM_HANDLING] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_inherit_mode_handling(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__INHERIT_MODE_HANDLING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_inherit_mode_handling");
    self->slots[SLOT_METADATA__INHERIT_MODE_HANDLING] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_pivot_handling(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__PIVOT_HANDLING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_pivot_handling");
    self->slots[SLOT_METADATA__PIVOT_HANDLING] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_handedness_conversion_axis(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__HANDEDNESS_CONVERSION_AXIS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_mirror_axis");
    self->slots[SLOT_METADATA__HANDEDNESS_CONVERSION_AXIS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_root_rotation(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__ROOT_ROTATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Quat_from(&self->data->root_rotation);
    self->slots[SLOT_METADATA__ROOT_ROTATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_root_scale(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__ROOT_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->root_scale);
    self->slots[SLOT_METADATA__ROOT_SCALE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_mirror_axis(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__MIRROR_AXIS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_mirror_axis");
    self->slots[SLOT_METADATA__MIRROR_AXIS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_geometry_scale(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__GEOMETRY_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->geometry_scale);
    self->slots[SLOT_METADATA__GEOMETRY_SCALE] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Metadata_getset[] = {
    { "warnings", (getter)Metadata_get_warnings, NULL, "warnings" },
    { "ascii", (getter)Metadata_get_ascii, NULL, "ascii" },
    { "version", (getter)Metadata_get_version, NULL, "version" },
    { "file_format", (getter)Metadata_get_file_format, NULL, "file_format" },
    { "may_contain_no_index", (getter)Metadata_get_may_contain_no_index, NULL, "may_contain_no_index" },
    { "may_contain_missing_vertex_position", (getter)Metadata_get_may_contain_missing_vertex_position, NULL, "may_contain_missing_vertex_position" },
    { "may_contain_broken_elements", (getter)Metadata_get_may_contain_broken_elements, NULL, "may_contain_broken_elements" },
    { "is_unsafe", (getter)Metadata_get_is_unsafe, NULL, "is_unsafe" },
    { "has_warning", (getter)Metadata_get_has_warning, NULL, "has_warning" },
    { "creator", (getter)Metadata_get_creator, NULL, "creator" },
    { "big_endian", (getter)Metadata_get_big_endian, NULL, "big_endian" },
    { "filename", (getter)Metadata_get_filename, NULL, "filename" },
    { "relative_root", (getter)Metadata_get_relative_root, NULL, "relative_root" },
    { "raw_filename", (getter)Metadata_get_raw_filename, NULL, "raw_filename" },
    { "raw_relative_root", (getter)Metadata_get_raw_relative_root, NULL, "raw_relative_root" },
    { "exporter", (getter)Metadata_get_exporter, NULL, "exporter" },
    { "exporter_version", (getter)Metadata_get_exporter_version, NULL, "exporter_version" },
    { "scene_props", (getter)Metadata_get_scene_props, NULL, "scene_props" },
    { "original_application", (getter)Metadata_get_original_application, NULL, "original_application" },
    { "latest_application", (getter)Metadata_get_latest_application, NULL, "latest_application" },
    { "thumbnail", (getter)Metadata_get_thumbnail, NULL, "thumbnail" },
    { "geometry_ignored", (getter)Metadata_get_geometry_ignored, NULL, "geometry_ignored" },
    { "animation_ignored", (getter)Metadata_get_animation_ignored, NULL, "animation_ignored" },
    { "embedded_ignored", (getter)Metadata_get_embedded_ignored, NULL, "embedded_ignored" },
    { "max_face_triangles", (getter)Metadata_get_max_face_triangles, NULL, "max_face_triangles" },
    { "result_memory_used", (getter)Metadata_get_result_memory_used, NULL, "result_memory_used" },
    { "temp_memory_used", (getter)Metadata_get_temp_memory_used, NULL, "temp_memory_used" },
    { "result_allocs", (getter)Metadata_get_result_allocs, NULL, "result_allocs" },
    { "temp_allocs", (getter)Metadata_get_temp_allocs, NULL, "temp_allocs" },
    { "element_buffer_size", (getter)Metadata_get_element_buffer_size, NULL, "element_buffer_size" },
    { "num_shader_textures", (getter)Metadata_get_num_shader_textures, NULL, "num_shader_textures" },
    { "bone_prop_size_unit", (getter)Metadata_get_bone_prop_size_unit, NULL, "bone_prop_size_unit" },
    { "bone_prop_limb_length_relative", (getter)Metadata_get_bone_prop_limb_length_relative, NULL, "bone_prop_limb_length_relative" },
    { "ortho_size_unit", (getter)Metadata_get_ortho_size_unit, NULL, "ortho_size_unit" },
    { "ktime_second", (getter)Metadata_get_ktime_second, NULL, "ktime_second" },
    { "original_file_path", (getter)Metadata_get_original_file_path, NULL, "original_file_path" },
    { "raw_original_file_path", (getter)Metadata_get_raw_original_file_path, NULL, "raw_original_file_path" },
    { "space_conversion", (getter)Metadata_get_space_conversion, NULL, "space_conversion" },
    { "geometry_transform_handling", (getter)Metadata_get_geometry_transform_handling, NULL, "geometry_transform_handling" },
    { "inherit_mode_handling", (getter)Metadata_get_inherit_mode_handling, NULL, "inherit_mode_handling" },
    { "pivot_handling", (getter)Metadata_get_pivot_handling, NULL, "pivot_handling" },
    { "handedness_conversion_axis", (getter)Metadata_get_handedness_conversion_axis, NULL, "handedness_conversion_axis" },
    { "root_rotation", (getter)Metadata_get_root_rotation, NULL, "root_rotation" },
    { "root_scale", (getter)Metadata_get_root_scale, NULL, "root_scale" },
    { "mirror_axis", (getter)Metadata_get_mirror_axis, NULL, "mirror_axis" },
    { "geometry_scale", (getter)Metadata_get_geometry_scale, NULL, "geometry_scale" },
    { NULL },
};

static PyTypeObject Metadata_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Metadata",
    .tp_doc = PyDoc_STR("Metadata"),
    .tp_basicsize = sizeof(Metadata),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Metadata_getset,
};

#define SLOT_COUNT_SCENE_SETTINGS 11
enum {
    SLOT_SCENE_SETTINGS__PROPS,
    SLOT_SCENE_SETTINGS__AXES,
    SLOT_SCENE_SETTINGS__UNIT_METERS,
    SLOT_SCENE_SETTINGS__FRAMES_PER_SECOND,
    SLOT_SCENE_SETTINGS__AMBIENT_COLOR,
    SLOT_SCENE_SETTINGS__DEFAULT_CAMERA,
    SLOT_SCENE_SETTINGS__TIME_MODE,
    SLOT_SCENE_SETTINGS__TIME_PROTOCOL,
    SLOT_SCENE_SETTINGS__SNAP_MODE,
    SLOT_SCENE_SETTINGS__ORIGINAL_AXIS_UP,
    SLOT_SCENE_SETTINGS__ORIGINAL_UNIT_METERS,
};

typedef struct {
    PyObject_HEAD
    ufbx_scene_settings *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_SCENE_SETTINGS];
} SceneSettings;

static PyObject *SceneSettings_get_props(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_props");
    self->slots[SLOT_SCENE_SETTINGS__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_axes(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__AXES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_coordinate_axes");
    self->slots[SLOT_SCENE_SETTINGS__AXES] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_unit_meters(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__UNIT_METERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->unit_meters);
    self->slots[SLOT_SCENE_SETTINGS__UNIT_METERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_frames_per_second(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__FRAMES_PER_SECOND];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->frames_per_second);
    self->slots[SLOT_SCENE_SETTINGS__FRAMES_PER_SECOND] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_ambient_color(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__AMBIENT_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->ambient_color);
    self->slots[SLOT_SCENE_SETTINGS__AMBIENT_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_default_camera(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__DEFAULT_CAMERA];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->default_camera);
    self->slots[SLOT_SCENE_SETTINGS__DEFAULT_CAMERA] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_time_mode(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__TIME_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_time_mode");
    self->slots[SLOT_SCENE_SETTINGS__TIME_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_time_protocol(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__TIME_PROTOCOL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_time_protocol");
    self->slots[SLOT_SCENE_SETTINGS__TIME_PROTOCOL] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_snap_mode(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__SNAP_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_snap_mode");
    self->slots[SLOT_SCENE_SETTINGS__SNAP_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_original_axis_up(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__ORIGINAL_AXIS_UP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_coordinate_axis");
    self->slots[SLOT_SCENE_SETTINGS__ORIGINAL_AXIS_UP] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_original_unit_meters(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__ORIGINAL_UNIT_METERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->original_unit_meters);
    self->slots[SLOT_SCENE_SETTINGS__ORIGINAL_UNIT_METERS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef SceneSettings_getset[] = {
    { "props", (getter)SceneSettings_get_props, NULL, "props" },
    { "axes", (getter)SceneSettings_get_axes, NULL, "axes" },
    { "unit_meters", (getter)SceneSettings_get_unit_meters, NULL, "unit_meters" },
    { "frames_per_second", (getter)SceneSettings_get_frames_per_second, NULL, "frames_per_second" },
    { "ambient_color", (getter)SceneSettings_get_ambient_color, NULL, "ambient_color" },
    { "default_camera", (getter)SceneSettings_get_default_camera, NULL, "default_camera" },
    { "time_mode", (getter)SceneSettings_get_time_mode, NULL, "time_mode" },
    { "time_protocol", (getter)SceneSettings_get_time_protocol, NULL, "time_protocol" },
    { "snap_mode", (getter)SceneSettings_get_snap_mode, NULL, "snap_mode" },
    { "original_axis_up", (getter)SceneSettings_get_original_axis_up, NULL, "original_axis_up" },
    { "original_unit_meters", (getter)SceneSettings_get_original_unit_meters, NULL, "original_unit_meters" },
    { NULL },
};

static PyTypeObject SceneSettings_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SceneSettings",
    .tp_doc = PyDoc_STR("SceneSettings"),
    .tp_basicsize = sizeof(SceneSettings),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = SceneSettings_getset,
};

#define SLOT_COUNT_SCENE 10
enum {
    SLOT_SCENE__METADATA,
    SLOT_SCENE__SETTINGS,
    SLOT_SCENE__ROOT_NODE,
    SLOT_SCENE__ANIM,
    SLOT_SCENE__TEXTURE_FILES,
    SLOT_SCENE__ELEMENTS,
    SLOT_SCENE__CONNECTIONS_SRC,
    SLOT_SCENE__CONNECTIONS_DST,
    SLOT_SCENE__ELEMENTS_BY_NAME,
    SLOT_SCENE__DOM_ROOT,
};

typedef struct {
    PyObject_HEAD
    ufbx_scene *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_SCENE];
} Scene;

static PyObject *Scene_get_metadata(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__METADATA];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_metadata");
    self->slots[SLOT_SCENE__METADATA] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_settings(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__SETTINGS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_scene_settings");
    self->slots[SLOT_SCENE__SETTINGS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_root_node(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__ROOT_NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Element_from(self->data->root_node, self->ctx);
    self->slots[SLOT_SCENE__ROOT_NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_anim(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__ANIM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_anim*");
    self->slots[SLOT_SCENE__ANIM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_texture_files(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__TEXTURE_FILES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = TextureFileList_from(self->data->texture_files, self->ctx);
    self->slots[SLOT_SCENE__TEXTURE_FILES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_elements(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__ELEMENTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ElementList_from(self->data->elements, self->ctx);
    self->slots[SLOT_SCENE__ELEMENTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_connections_src(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__CONNECTIONS_SRC];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ConnectionList_from(self->data->connections_src, self->ctx);
    self->slots[SLOT_SCENE__CONNECTIONS_SRC] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_connections_dst(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__CONNECTIONS_DST];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ConnectionList_from(self->data->connections_dst, self->ctx);
    self->slots[SLOT_SCENE__CONNECTIONS_DST] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_elements_by_name(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__ELEMENTS_BY_NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NameElementList_from(self->data->elements_by_name, self->ctx);
    self->slots[SLOT_SCENE__ELEMENTS_BY_NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_dom_root(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__DOM_ROOT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_dom_node?*");
    self->slots[SLOT_SCENE__DOM_ROOT] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Scene_getset[] = {
    { "metadata", (getter)Scene_get_metadata, NULL, "metadata" },
    { "settings", (getter)Scene_get_settings, NULL, "settings" },
    { "root_node", (getter)Scene_get_root_node, NULL, "root_node" },
    { "anim", (getter)Scene_get_anim, NULL, "anim" },
    { "texture_files", (getter)Scene_get_texture_files, NULL, "texture_files" },
    { "elements", (getter)Scene_get_elements, NULL, "elements" },
    { "connections_src", (getter)Scene_get_connections_src, NULL, "connections_src" },
    { "connections_dst", (getter)Scene_get_connections_dst, NULL, "connections_dst" },
    { "elements_by_name", (getter)Scene_get_elements_by_name, NULL, "elements_by_name" },
    { "dom_root", (getter)Scene_get_dom_root, NULL, "dom_root" },
    { NULL },
};

static PyTypeObject Scene_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Scene",
    .tp_doc = PyDoc_STR("Scene"),
    .tp_basicsize = sizeof(Scene),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Scene_getset,
};

#define SLOT_COUNT_VERTEX_STREAM 3
enum {
    SLOT_VERTEX_STREAM__DATA,
    SLOT_VERTEX_STREAM__VERTEX_COUNT,
    SLOT_VERTEX_STREAM__VERTEX_SIZE,
};

typedef struct {
    PyObject_HEAD
    ufbx_vertex_stream *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_VERTEX_STREAM];
} VertexStream;

static PyObject *VertexStream_get_data(VertexStream *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_STREAM__DATA];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("void*");
    self->slots[SLOT_VERTEX_STREAM__DATA] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexStream_get_vertex_count(VertexStream *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_STREAM__VERTEX_COUNT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->vertex_count);
    self->slots[SLOT_VERTEX_STREAM__VERTEX_COUNT] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexStream_get_vertex_size(VertexStream *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_STREAM__VERTEX_SIZE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->vertex_size);
    self->slots[SLOT_VERTEX_STREAM__VERTEX_SIZE] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef VertexStream_getset[] = {
    { "data", (getter)VertexStream_get_data, NULL, "data" },
    { "vertex_count", (getter)VertexStream_get_vertex_count, NULL, "vertex_count" },
    { "vertex_size", (getter)VertexStream_get_vertex_size, NULL, "vertex_size" },
    { NULL },
};

static PyTypeObject VertexStream_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.VertexStream",
    .tp_doc = PyDoc_STR("VertexStream"),
    .tp_basicsize = sizeof(VertexStream),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = VertexStream_getset,
};

#define SLOT_COUNT_OPEN_FILE_INFO 3
enum {
    SLOT_OPEN_FILE_INFO__CONTEXT,
    SLOT_OPEN_FILE_INFO__TYPE,
    SLOT_OPEN_FILE_INFO__ORIGINAL_FILENAME,
};

typedef struct {
    PyObject_HEAD
    ufbx_open_file_info *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_OPEN_FILE_INFO];
} OpenFileInfo;

static PyObject *OpenFileInfo_get_context(OpenFileInfo *self, void *closure) {
    PyObject *slot = self->slots[SLOT_OPEN_FILE_INFO__CONTEXT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_open_file_context");
    self->slots[SLOT_OPEN_FILE_INFO__CONTEXT] = slot;
    return Py_NewRef(slot);
}

static PyObject *OpenFileInfo_get_type(OpenFileInfo *self, void *closure) {
    PyObject *slot = self->slots[SLOT_OPEN_FILE_INFO__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_open_file_type");
    self->slots[SLOT_OPEN_FILE_INFO__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *OpenFileInfo_get_original_filename(OpenFileInfo *self, void *closure) {
    PyObject *slot = self->slots[SLOT_OPEN_FILE_INFO__ORIGINAL_FILENAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Blob_from(self->data->original_filename);
    self->slots[SLOT_OPEN_FILE_INFO__ORIGINAL_FILENAME] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef OpenFileInfo_getset[] = {
    { "context", (getter)OpenFileInfo_get_context, NULL, "context" },
    { "type", (getter)OpenFileInfo_get_type, NULL, "type" },
    { "original_filename", (getter)OpenFileInfo_get_original_filename, NULL, "original_filename" },
    { NULL },
};

static PyTypeObject OpenFileInfo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.OpenFileInfo",
    .tp_doc = PyDoc_STR("OpenFileInfo"),
    .tp_basicsize = sizeof(OpenFileInfo),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = OpenFileInfo_getset,
};

#define SLOT_COUNT_OPEN_FILE_OPTS 2
enum {
    SLOT_OPEN_FILE_OPTS__ALLOCATOR,
    SLOT_OPEN_FILE_OPTS__FILENAME_NULL_TERMINATED,
};

typedef struct {
    PyObject_HEAD
    ufbx_open_file_opts *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_OPEN_FILE_OPTS];
} OpenFileOpts;

static PyObject *OpenFileOpts_get_allocator(OpenFileOpts *self, void *closure) {
    PyObject *slot = self->slots[SLOT_OPEN_FILE_OPTS__ALLOCATOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_allocator_opts");
    self->slots[SLOT_OPEN_FILE_OPTS__ALLOCATOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *OpenFileOpts_get_filename_null_terminated(OpenFileOpts *self, void *closure) {
    PyObject *slot = self->slots[SLOT_OPEN_FILE_OPTS__FILENAME_NULL_TERMINATED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("bool unsafe");
    self->slots[SLOT_OPEN_FILE_OPTS__FILENAME_NULL_TERMINATED] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef OpenFileOpts_getset[] = {
    { "allocator", (getter)OpenFileOpts_get_allocator, NULL, "allocator" },
    { "filename_null_terminated", (getter)OpenFileOpts_get_filename_null_terminated, NULL, "filename_null_terminated" },
    { NULL },
};

static PyTypeObject OpenFileOpts_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.OpenFileOpts",
    .tp_doc = PyDoc_STR("OpenFileOpts"),
    .tp_basicsize = sizeof(OpenFileOpts),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = OpenFileOpts_getset,
};

#define SLOT_COUNT_ERROR_FRAME 3
enum {
    SLOT_ERROR_FRAME__SOURCE_LINE,
    SLOT_ERROR_FRAME__FUNCTION,
    SLOT_ERROR_FRAME__DESCRIPTION,
};

typedef struct {
    PyObject_HEAD
    ufbx_error_frame *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_ERROR_FRAME];
} ErrorFrame;

static PyObject *ErrorFrame_get_source_line(ErrorFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ERROR_FRAME__SOURCE_LINE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->source_line);
    self->slots[SLOT_ERROR_FRAME__SOURCE_LINE] = slot;
    return Py_NewRef(slot);
}

static PyObject *ErrorFrame_get_function(ErrorFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ERROR_FRAME__FUNCTION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->function);
    self->slots[SLOT_ERROR_FRAME__FUNCTION] = slot;
    return Py_NewRef(slot);
}

static PyObject *ErrorFrame_get_description(ErrorFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ERROR_FRAME__DESCRIPTION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->description);
    self->slots[SLOT_ERROR_FRAME__DESCRIPTION] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef ErrorFrame_getset[] = {
    { "source_line", (getter)ErrorFrame_get_source_line, NULL, "source_line" },
    { "function", (getter)ErrorFrame_get_function, NULL, "function" },
    { "description", (getter)ErrorFrame_get_description, NULL, "description" },
    { NULL },
};

static PyTypeObject ErrorFrame_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ErrorFrame",
    .tp_doc = PyDoc_STR("ErrorFrame"),
    .tp_basicsize = sizeof(ErrorFrame),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = ErrorFrame_getset,
};

#define SLOT_COUNT_ERROR 6
enum {
    SLOT_ERROR__TYPE,
    SLOT_ERROR__DESCRIPTION,
    SLOT_ERROR__STACK_SIZE,
    SLOT_ERROR__STACK,
    SLOT_ERROR__INFO_LENGTH,
    SLOT_ERROR__INFO,
};

typedef struct {
    PyObject_HEAD
    ufbx_error *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_ERROR];
} Error;

static PyObject *Error_get_type(Error *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ERROR__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_error_type");
    self->slots[SLOT_ERROR__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Error_get_description(Error *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ERROR__DESCRIPTION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->description);
    self->slots[SLOT_ERROR__DESCRIPTION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Error_get_stack_size(Error *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ERROR__STACK_SIZE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->stack_size);
    self->slots[SLOT_ERROR__STACK_SIZE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Error_get_stack(Error *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ERROR__STACK];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_error_frame[8]");
    self->slots[SLOT_ERROR__STACK] = slot;
    return Py_NewRef(slot);
}

static PyObject *Error_get_info_length(Error *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ERROR__INFO_LENGTH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->info_length);
    self->slots[SLOT_ERROR__INFO_LENGTH] = slot;
    return Py_NewRef(slot);
}

static PyObject *Error_get_info(Error *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ERROR__INFO];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("char[256]");
    self->slots[SLOT_ERROR__INFO] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Error_getset[] = {
    { "type", (getter)Error_get_type, NULL, "type" },
    { "description", (getter)Error_get_description, NULL, "description" },
    { "stack_size", (getter)Error_get_stack_size, NULL, "stack_size" },
    { "stack", (getter)Error_get_stack, NULL, "stack" },
    { "info_length", (getter)Error_get_info_length, NULL, "info_length" },
    { "info", (getter)Error_get_info, NULL, "info" },
    { NULL },
};

static PyTypeObject Error_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Error",
    .tp_doc = PyDoc_STR("Error"),
    .tp_basicsize = sizeof(Error),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Error_getset,
};

#define SLOT_COUNT_PROGRESS 2
enum {
    SLOT_PROGRESS__BYTES_READ,
    SLOT_PROGRESS__BYTES_TOTAL,
};

typedef struct {
    PyObject_HEAD
    ufbx_progress *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_PROGRESS];
} Progress;

static PyObject *Progress_get_bytes_read(Progress *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROGRESS__BYTES_READ];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLongLong((unsigned long long)self->data->bytes_read);
    self->slots[SLOT_PROGRESS__BYTES_READ] = slot;
    return Py_NewRef(slot);
}

static PyObject *Progress_get_bytes_total(Progress *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROGRESS__BYTES_TOTAL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLongLong((unsigned long long)self->data->bytes_total);
    self->slots[SLOT_PROGRESS__BYTES_TOTAL] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Progress_getset[] = {
    { "bytes_read", (getter)Progress_get_bytes_read, NULL, "bytes_read" },
    { "bytes_total", (getter)Progress_get_bytes_total, NULL, "bytes_total" },
    { NULL },
};

static PyTypeObject Progress_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Progress",
    .tp_doc = PyDoc_STR("Progress"),
    .tp_basicsize = sizeof(Progress),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Progress_getset,
};

#define SLOT_COUNT_INFLATE_INPUT 14
enum {
    SLOT_INFLATE_INPUT__TOTAL_SIZE,
    SLOT_INFLATE_INPUT__DATA,
    SLOT_INFLATE_INPUT__DATA_SIZE,
    SLOT_INFLATE_INPUT__BUFFER,
    SLOT_INFLATE_INPUT__BUFFER_SIZE,
    SLOT_INFLATE_INPUT__READ_FN,
    SLOT_INFLATE_INPUT__READ_USER,
    SLOT_INFLATE_INPUT__PROGRESS_CB,
    SLOT_INFLATE_INPUT__PROGRESS_INTERVAL_HINT,
    SLOT_INFLATE_INPUT__PROGRESS_SIZE_BEFORE,
    SLOT_INFLATE_INPUT__PROGRESS_SIZE_AFTER,
    SLOT_INFLATE_INPUT__NO_HEADER,
    SLOT_INFLATE_INPUT__NO_CHECKSUM,
    SLOT_INFLATE_INPUT__INTERNAL_FAST_BITS,
};

typedef struct {
    PyObject_HEAD
    ufbx_inflate_input *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_INFLATE_INPUT];
} InflateInput;

static PyObject *InflateInput_get_total_size(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__TOTAL_SIZE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->total_size);
    self->slots[SLOT_INFLATE_INPUT__TOTAL_SIZE] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_data(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__DATA];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("void const*");
    self->slots[SLOT_INFLATE_INPUT__DATA] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_data_size(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__DATA_SIZE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->data_size);
    self->slots[SLOT_INFLATE_INPUT__DATA_SIZE] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_buffer(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__BUFFER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("void*");
    self->slots[SLOT_INFLATE_INPUT__BUFFER] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_buffer_size(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__BUFFER_SIZE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->buffer_size);
    self->slots[SLOT_INFLATE_INPUT__BUFFER_SIZE] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_read_fn(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__READ_FN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_read_fn*");
    self->slots[SLOT_INFLATE_INPUT__READ_FN] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_read_user(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__READ_USER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("void*");
    self->slots[SLOT_INFLATE_INPUT__READ_USER] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_progress_cb(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__PROGRESS_CB];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_progress_cb");
    self->slots[SLOT_INFLATE_INPUT__PROGRESS_CB] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_progress_interval_hint(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__PROGRESS_INTERVAL_HINT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLongLong((unsigned long long)self->data->progress_interval_hint);
    self->slots[SLOT_INFLATE_INPUT__PROGRESS_INTERVAL_HINT] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_progress_size_before(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__PROGRESS_SIZE_BEFORE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLongLong((unsigned long long)self->data->progress_size_before);
    self->slots[SLOT_INFLATE_INPUT__PROGRESS_SIZE_BEFORE] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_progress_size_after(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__PROGRESS_SIZE_AFTER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLongLong((unsigned long long)self->data->progress_size_after);
    self->slots[SLOT_INFLATE_INPUT__PROGRESS_SIZE_AFTER] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_no_header(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__NO_HEADER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->no_header ? Py_True : Py_False;
    self->slots[SLOT_INFLATE_INPUT__NO_HEADER] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_no_checksum(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__NO_CHECKSUM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->no_checksum ? Py_True : Py_False;
    self->slots[SLOT_INFLATE_INPUT__NO_CHECKSUM] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_internal_fast_bits(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__INTERNAL_FAST_BITS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->internal_fast_bits);
    self->slots[SLOT_INFLATE_INPUT__INTERNAL_FAST_BITS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef InflateInput_getset[] = {
    { "total_size", (getter)InflateInput_get_total_size, NULL, "total_size" },
    { "data", (getter)InflateInput_get_data, NULL, "data" },
    { "data_size", (getter)InflateInput_get_data_size, NULL, "data_size" },
    { "buffer", (getter)InflateInput_get_buffer, NULL, "buffer" },
    { "buffer_size", (getter)InflateInput_get_buffer_size, NULL, "buffer_size" },
    { "read_fn", (getter)InflateInput_get_read_fn, NULL, "read_fn" },
    { "read_user", (getter)InflateInput_get_read_user, NULL, "read_user" },
    { "progress_cb", (getter)InflateInput_get_progress_cb, NULL, "progress_cb" },
    { "progress_interval_hint", (getter)InflateInput_get_progress_interval_hint, NULL, "progress_interval_hint" },
    { "progress_size_before", (getter)InflateInput_get_progress_size_before, NULL, "progress_size_before" },
    { "progress_size_after", (getter)InflateInput_get_progress_size_after, NULL, "progress_size_after" },
    { "no_header", (getter)InflateInput_get_no_header, NULL, "no_header" },
    { "no_checksum", (getter)InflateInput_get_no_checksum, NULL, "no_checksum" },
    { "internal_fast_bits", (getter)InflateInput_get_internal_fast_bits, NULL, "internal_fast_bits" },
    { NULL },
};

static PyTypeObject InflateInput_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.InflateInput",
    .tp_doc = PyDoc_STR("InflateInput"),
    .tp_basicsize = sizeof(InflateInput),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = InflateInput_getset,
};

#define SLOT_COUNT_INFLATE_RETAIN 2
enum {
    SLOT_INFLATE_RETAIN__INITIALIZED,
    SLOT_INFLATE_RETAIN__DATA,
};

typedef struct {
    PyObject_HEAD
    ufbx_inflate_retain *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_INFLATE_RETAIN];
} InflateRetain;

static PyObject *InflateRetain_get_initialized(InflateRetain *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_RETAIN__INITIALIZED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->initialized ? Py_True : Py_False;
    self->slots[SLOT_INFLATE_RETAIN__INITIALIZED] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateRetain_get_data(InflateRetain *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_RETAIN__DATA];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("uint64_t[1024]");
    self->slots[SLOT_INFLATE_RETAIN__DATA] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef InflateRetain_getset[] = {
    { "initialized", (getter)InflateRetain_get_initialized, NULL, "initialized" },
    { "data", (getter)InflateRetain_get_data, NULL, "data" },
    { NULL },
};

static PyTypeObject InflateRetain_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.InflateRetain",
    .tp_doc = PyDoc_STR("InflateRetain"),
    .tp_basicsize = sizeof(InflateRetain),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = InflateRetain_getset,
};

#define SLOT_COUNT_BAKED_VEC3 3
enum {
    SLOT_BAKED_VEC3__TIME,
    SLOT_BAKED_VEC3__VALUE,
    SLOT_BAKED_VEC3__FLAGS,
};

typedef struct {
    PyObject_HEAD
    ufbx_baked_vec3 *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_BAKED_VEC3];
} BakedVec3;

static PyObject *BakedVec3_get_time(BakedVec3 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_VEC3__TIME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->time);
    self->slots[SLOT_BAKED_VEC3__TIME] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedVec3_get_value(BakedVec3 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_VEC3__VALUE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec3_from(&self->data->value);
    self->slots[SLOT_BAKED_VEC3__VALUE] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedVec3_get_flags(BakedVec3 *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_VEC3__FLAGS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_baked_key_flags");
    self->slots[SLOT_BAKED_VEC3__FLAGS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BakedVec3_getset[] = {
    { "time", (getter)BakedVec3_get_time, NULL, "time" },
    { "value", (getter)BakedVec3_get_value, NULL, "value" },
    { "flags", (getter)BakedVec3_get_flags, NULL, "flags" },
    { NULL },
};

static PyTypeObject BakedVec3_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedVec3",
    .tp_doc = PyDoc_STR("BakedVec3"),
    .tp_basicsize = sizeof(BakedVec3),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BakedVec3_getset,
};

#define SLOT_COUNT_BAKED_QUAT 3
enum {
    SLOT_BAKED_QUAT__TIME,
    SLOT_BAKED_QUAT__VALUE,
    SLOT_BAKED_QUAT__FLAGS,
};

typedef struct {
    PyObject_HEAD
    ufbx_baked_quat *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_BAKED_QUAT];
} BakedQuat;

static PyObject *BakedQuat_get_time(BakedQuat *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_QUAT__TIME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->time);
    self->slots[SLOT_BAKED_QUAT__TIME] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedQuat_get_value(BakedQuat *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_QUAT__VALUE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Quat_from(&self->data->value);
    self->slots[SLOT_BAKED_QUAT__VALUE] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedQuat_get_flags(BakedQuat *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_QUAT__FLAGS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_baked_key_flags");
    self->slots[SLOT_BAKED_QUAT__FLAGS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BakedQuat_getset[] = {
    { "time", (getter)BakedQuat_get_time, NULL, "time" },
    { "value", (getter)BakedQuat_get_value, NULL, "value" },
    { "flags", (getter)BakedQuat_get_flags, NULL, "flags" },
    { NULL },
};

static PyTypeObject BakedQuat_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedQuat",
    .tp_doc = PyDoc_STR("BakedQuat"),
    .tp_basicsize = sizeof(BakedQuat),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BakedQuat_getset,
};

#define SLOT_COUNT_BAKED_NODE 8
enum {
    SLOT_BAKED_NODE__TYPED_ID,
    SLOT_BAKED_NODE__ELEMENT_ID,
    SLOT_BAKED_NODE__CONSTANT_TRANSLATION,
    SLOT_BAKED_NODE__CONSTANT_ROTATION,
    SLOT_BAKED_NODE__CONSTANT_SCALE,
    SLOT_BAKED_NODE__TRANSLATION_KEYS,
    SLOT_BAKED_NODE__ROTATION_KEYS,
    SLOT_BAKED_NODE__SCALE_KEYS,
};

typedef struct {
    PyObject_HEAD
    ufbx_baked_node *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_BAKED_NODE];
} BakedNode;

static PyObject *BakedNode_get_typed_id(BakedNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_NODE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_BAKED_NODE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedNode_get_element_id(BakedNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_NODE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_BAKED_NODE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedNode_get_constant_translation(BakedNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_NODE__CONSTANT_TRANSLATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->constant_translation ? Py_True : Py_False;
    self->slots[SLOT_BAKED_NODE__CONSTANT_TRANSLATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedNode_get_constant_rotation(BakedNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_NODE__CONSTANT_ROTATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->constant_rotation ? Py_True : Py_False;
    self->slots[SLOT_BAKED_NODE__CONSTANT_ROTATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedNode_get_constant_scale(BakedNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_NODE__CONSTANT_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->constant_scale ? Py_True : Py_False;
    self->slots[SLOT_BAKED_NODE__CONSTANT_SCALE] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedNode_get_translation_keys(BakedNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_NODE__TRANSLATION_KEYS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BakedVec3List_from(self->data->translation_keys, self->ctx);
    self->slots[SLOT_BAKED_NODE__TRANSLATION_KEYS] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedNode_get_rotation_keys(BakedNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_NODE__ROTATION_KEYS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BakedQuatList_from(self->data->rotation_keys, self->ctx);
    self->slots[SLOT_BAKED_NODE__ROTATION_KEYS] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedNode_get_scale_keys(BakedNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_NODE__SCALE_KEYS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BakedVec3List_from(self->data->scale_keys, self->ctx);
    self->slots[SLOT_BAKED_NODE__SCALE_KEYS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BakedNode_getset[] = {
    { "typed_id", (getter)BakedNode_get_typed_id, NULL, "typed_id" },
    { "element_id", (getter)BakedNode_get_element_id, NULL, "element_id" },
    { "constant_translation", (getter)BakedNode_get_constant_translation, NULL, "constant_translation" },
    { "constant_rotation", (getter)BakedNode_get_constant_rotation, NULL, "constant_rotation" },
    { "constant_scale", (getter)BakedNode_get_constant_scale, NULL, "constant_scale" },
    { "translation_keys", (getter)BakedNode_get_translation_keys, NULL, "translation_keys" },
    { "rotation_keys", (getter)BakedNode_get_rotation_keys, NULL, "rotation_keys" },
    { "scale_keys", (getter)BakedNode_get_scale_keys, NULL, "scale_keys" },
    { NULL },
};

static PyTypeObject BakedNode_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedNode",
    .tp_doc = PyDoc_STR("BakedNode"),
    .tp_basicsize = sizeof(BakedNode),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BakedNode_getset,
};

#define SLOT_COUNT_BAKED_PROP 3
enum {
    SLOT_BAKED_PROP__NAME,
    SLOT_BAKED_PROP__CONSTANT_VALUE,
    SLOT_BAKED_PROP__KEYS,
};

typedef struct {
    PyObject_HEAD
    ufbx_baked_prop *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_BAKED_PROP];
} BakedProp;

static PyObject *BakedProp_get_name(BakedProp *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_PROP__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_BAKED_PROP__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedProp_get_constant_value(BakedProp *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_PROP__CONSTANT_VALUE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->constant_value ? Py_True : Py_False;
    self->slots[SLOT_BAKED_PROP__CONSTANT_VALUE] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedProp_get_keys(BakedProp *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_PROP__KEYS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BakedVec3List_from(self->data->keys, self->ctx);
    self->slots[SLOT_BAKED_PROP__KEYS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BakedProp_getset[] = {
    { "name", (getter)BakedProp_get_name, NULL, "name" },
    { "constant_value", (getter)BakedProp_get_constant_value, NULL, "constant_value" },
    { "keys", (getter)BakedProp_get_keys, NULL, "keys" },
    { NULL },
};

static PyTypeObject BakedProp_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedProp",
    .tp_doc = PyDoc_STR("BakedProp"),
    .tp_basicsize = sizeof(BakedProp),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BakedProp_getset,
};

#define SLOT_COUNT_BAKED_ELEMENT 2
enum {
    SLOT_BAKED_ELEMENT__ELEMENT_ID,
    SLOT_BAKED_ELEMENT__PROPS,
};

typedef struct {
    PyObject_HEAD
    ufbx_baked_element *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_BAKED_ELEMENT];
} BakedElement;

static PyObject *BakedElement_get_element_id(BakedElement *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ELEMENT__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_BAKED_ELEMENT__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedElement_get_props(BakedElement *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ELEMENT__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BakedPropList_from(self->data->props, self->ctx);
    self->slots[SLOT_BAKED_ELEMENT__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BakedElement_getset[] = {
    { "element_id", (getter)BakedElement_get_element_id, NULL, "element_id" },
    { "props", (getter)BakedElement_get_props, NULL, "props" },
    { NULL },
};

static PyTypeObject BakedElement_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedElement",
    .tp_doc = PyDoc_STR("BakedElement"),
    .tp_basicsize = sizeof(BakedElement),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BakedElement_getset,
};

#define SLOT_COUNT_BAKED_ANIM_METADATA 4
enum {
    SLOT_BAKED_ANIM_METADATA__RESULT_MEMORY_USED,
    SLOT_BAKED_ANIM_METADATA__TEMP_MEMORY_USED,
    SLOT_BAKED_ANIM_METADATA__RESULT_ALLOCS,
    SLOT_BAKED_ANIM_METADATA__TEMP_ALLOCS,
};

typedef struct {
    PyObject_HEAD
    ufbx_baked_anim_metadata *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_BAKED_ANIM_METADATA];
} BakedAnimMetadata;

static PyObject *BakedAnimMetadata_get_result_memory_used(BakedAnimMetadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM_METADATA__RESULT_MEMORY_USED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->result_memory_used);
    self->slots[SLOT_BAKED_ANIM_METADATA__RESULT_MEMORY_USED] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedAnimMetadata_get_temp_memory_used(BakedAnimMetadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM_METADATA__TEMP_MEMORY_USED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->temp_memory_used);
    self->slots[SLOT_BAKED_ANIM_METADATA__TEMP_MEMORY_USED] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedAnimMetadata_get_result_allocs(BakedAnimMetadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM_METADATA__RESULT_ALLOCS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->result_allocs);
    self->slots[SLOT_BAKED_ANIM_METADATA__RESULT_ALLOCS] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedAnimMetadata_get_temp_allocs(BakedAnimMetadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM_METADATA__TEMP_ALLOCS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->temp_allocs);
    self->slots[SLOT_BAKED_ANIM_METADATA__TEMP_ALLOCS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BakedAnimMetadata_getset[] = {
    { "result_memory_used", (getter)BakedAnimMetadata_get_result_memory_used, NULL, "result_memory_used" },
    { "temp_memory_used", (getter)BakedAnimMetadata_get_temp_memory_used, NULL, "temp_memory_used" },
    { "result_allocs", (getter)BakedAnimMetadata_get_result_allocs, NULL, "result_allocs" },
    { "temp_allocs", (getter)BakedAnimMetadata_get_temp_allocs, NULL, "temp_allocs" },
    { NULL },
};

static PyTypeObject BakedAnimMetadata_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedAnimMetadata",
    .tp_doc = PyDoc_STR("BakedAnimMetadata"),
    .tp_basicsize = sizeof(BakedAnimMetadata),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BakedAnimMetadata_getset,
};

#define SLOT_COUNT_BAKED_ANIM 8
enum {
    SLOT_BAKED_ANIM__NODES,
    SLOT_BAKED_ANIM__ELEMENTS,
    SLOT_BAKED_ANIM__PLAYBACK_TIME_BEGIN,
    SLOT_BAKED_ANIM__PLAYBACK_TIME_END,
    SLOT_BAKED_ANIM__PLAYBACK_DURATION,
    SLOT_BAKED_ANIM__KEY_TIME_MIN,
    SLOT_BAKED_ANIM__KEY_TIME_MAX,
    SLOT_BAKED_ANIM__METADATA,
};

typedef struct {
    PyObject_HEAD
    ufbx_baked_anim *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_BAKED_ANIM];
} BakedAnim;

static PyObject *BakedAnim_get_nodes(BakedAnim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM__NODES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BakedNodeList_from(self->data->nodes, self->ctx);
    self->slots[SLOT_BAKED_ANIM__NODES] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedAnim_get_elements(BakedAnim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM__ELEMENTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BakedElementList_from(self->data->elements, self->ctx);
    self->slots[SLOT_BAKED_ANIM__ELEMENTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedAnim_get_playback_time_begin(BakedAnim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM__PLAYBACK_TIME_BEGIN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->playback_time_begin);
    self->slots[SLOT_BAKED_ANIM__PLAYBACK_TIME_BEGIN] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedAnim_get_playback_time_end(BakedAnim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM__PLAYBACK_TIME_END];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->playback_time_end);
    self->slots[SLOT_BAKED_ANIM__PLAYBACK_TIME_END] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedAnim_get_playback_duration(BakedAnim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM__PLAYBACK_DURATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->playback_duration);
    self->slots[SLOT_BAKED_ANIM__PLAYBACK_DURATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedAnim_get_key_time_min(BakedAnim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM__KEY_TIME_MIN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->key_time_min);
    self->slots[SLOT_BAKED_ANIM__KEY_TIME_MIN] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedAnim_get_key_time_max(BakedAnim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM__KEY_TIME_MAX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyFloat_FromDouble(self->data->key_time_max);
    self->slots[SLOT_BAKED_ANIM__KEY_TIME_MAX] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedAnim_get_metadata(BakedAnim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_ANIM__METADATA];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("ufbx_baked_anim_metadata");
    self->slots[SLOT_BAKED_ANIM__METADATA] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef BakedAnim_getset[] = {
    { "nodes", (getter)BakedAnim_get_nodes, NULL, "nodes" },
    { "elements", (getter)BakedAnim_get_elements, NULL, "elements" },
    { "playback_time_begin", (getter)BakedAnim_get_playback_time_begin, NULL, "playback_time_begin" },
    { "playback_time_end", (getter)BakedAnim_get_playback_time_end, NULL, "playback_time_end" },
    { "playback_duration", (getter)BakedAnim_get_playback_duration, NULL, "playback_duration" },
    { "key_time_min", (getter)BakedAnim_get_key_time_min, NULL, "key_time_min" },
    { "key_time_max", (getter)BakedAnim_get_key_time_max, NULL, "key_time_max" },
    { "metadata", (getter)BakedAnim_get_metadata, NULL, "metadata" },
    { NULL },
};

static PyTypeObject BakedAnim_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedAnim",
    .tp_doc = PyDoc_STR("BakedAnim"),
    .tp_basicsize = sizeof(BakedAnim),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = BakedAnim_getset,
};

#define SLOT_COUNT_THREAD_POOL_INFO 1
enum {
    SLOT_THREAD_POOL_INFO__MAX_CONCURRENT_TASKS,
};

typedef struct {
    PyObject_HEAD
    ufbx_thread_pool_info *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_THREAD_POOL_INFO];
} ThreadPoolInfo;

static PyObject *ThreadPoolInfo_get_max_concurrent_tasks(ThreadPoolInfo *self, void *closure) {
    PyObject *slot = self->slots[SLOT_THREAD_POOL_INFO__MAX_CONCURRENT_TASKS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->max_concurrent_tasks);
    self->slots[SLOT_THREAD_POOL_INFO__MAX_CONCURRENT_TASKS] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef ThreadPoolInfo_getset[] = {
    { "max_concurrent_tasks", (getter)ThreadPoolInfo_get_max_concurrent_tasks, NULL, "max_concurrent_tasks" },
    { NULL },
};

static PyTypeObject ThreadPoolInfo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ThreadPoolInfo",
    .tp_doc = PyDoc_STR("ThreadPoolInfo"),
    .tp_basicsize = sizeof(ThreadPoolInfo),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = ThreadPoolInfo_getset,
};

#define SLOT_COUNT_PANIC 3
enum {
    SLOT_PANIC__DID_PANIC,
    SLOT_PANIC__MESSAGE_LENGTH,
    SLOT_PANIC__MESSAGE,
};

typedef struct {
    PyObject_HEAD
    ufbx_panic *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_PANIC];
} Panic;

static PyObject *Panic_get_did_panic(Panic *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PANIC__DID_PANIC];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = self->data->did_panic ? Py_True : Py_False;
    self->slots[SLOT_PANIC__DID_PANIC] = slot;
    return Py_NewRef(slot);
}

static PyObject *Panic_get_message_length(Panic *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PANIC__MESSAGE_LENGTH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromSize_t(self->data->message_length);
    self->slots[SLOT_PANIC__MESSAGE_LENGTH] = slot;
    return Py_NewRef(slot);
}

static PyObject *Panic_get_message(Panic *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PANIC__MESSAGE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = to_pyobject_todo("char[128]");
    self->slots[SLOT_PANIC__MESSAGE] = slot;
    return Py_NewRef(slot);
}

static PyGetSetDef Panic_getset[] = {
    { "did_panic", (getter)Panic_get_did_panic, NULL, "did_panic" },
    { "message_length", (getter)Panic_get_message_length, NULL, "message_length" },
    { "message", (getter)Panic_get_message, NULL, "message" },
    { NULL },
};

static PyTypeObject Panic_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Panic",
    .tp_doc = PyDoc_STR("Panic"),
    .tp_basicsize = sizeof(Panic),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_getset = Panic_getset,
};

static PyTypeObject *Element_typeof(ufbx_element_type type) {
    switch (type) {
        case UFBX_ELEMENT_UNKNOWN: return &Unknown_Type;
        case UFBX_ELEMENT_NODE: return &Node_Type;
        case UFBX_ELEMENT_MESH: return &Mesh_Type;
        case UFBX_ELEMENT_LIGHT: return &Light_Type;
        case UFBX_ELEMENT_CAMERA: return &Camera_Type;
        case UFBX_ELEMENT_BONE: return &Bone_Type;
        case UFBX_ELEMENT_EMPTY: return &Empty_Type;
        case UFBX_ELEMENT_LINE_CURVE: return &LineCurve_Type;
        case UFBX_ELEMENT_NURBS_CURVE: return &NurbsCurve_Type;
        case UFBX_ELEMENT_NURBS_SURFACE: return &NurbsSurface_Type;
        case UFBX_ELEMENT_NURBS_TRIM_SURFACE: return &NurbsTrimSurface_Type;
        case UFBX_ELEMENT_NURBS_TRIM_BOUNDARY: return &NurbsTrimBoundary_Type;
        case UFBX_ELEMENT_PROCEDURAL_GEOMETRY: return &ProceduralGeometry_Type;
        case UFBX_ELEMENT_STEREO_CAMERA: return &StereoCamera_Type;
        case UFBX_ELEMENT_CAMERA_SWITCHER: return &CameraSwitcher_Type;
        case UFBX_ELEMENT_MARKER: return &Marker_Type;
        case UFBX_ELEMENT_LOD_GROUP: return &LodGroup_Type;
        case UFBX_ELEMENT_SKIN_DEFORMER: return &SkinDeformer_Type;
        case UFBX_ELEMENT_SKIN_CLUSTER: return &SkinCluster_Type;
        case UFBX_ELEMENT_BLEND_DEFORMER: return &BlendDeformer_Type;
        case UFBX_ELEMENT_BLEND_CHANNEL: return &BlendChannel_Type;
        case UFBX_ELEMENT_BLEND_SHAPE: return &BlendShape_Type;
        case UFBX_ELEMENT_CACHE_DEFORMER: return &CacheDeformer_Type;
        case UFBX_ELEMENT_CACHE_FILE: return &CacheFile_Type;
        case UFBX_ELEMENT_MATERIAL: return &Material_Type;
        case UFBX_ELEMENT_TEXTURE: return &Texture_Type;
        case UFBX_ELEMENT_VIDEO: return &Video_Type;
        case UFBX_ELEMENT_SHADER: return &Shader_Type;
        case UFBX_ELEMENT_SHADER_BINDING: return &ShaderBinding_Type;
        case UFBX_ELEMENT_ANIM_STACK: return &AnimStack_Type;
        case UFBX_ELEMENT_ANIM_LAYER: return &AnimLayer_Type;
        case UFBX_ELEMENT_ANIM_VALUE: return &AnimValue_Type;
        case UFBX_ELEMENT_ANIM_CURVE: return &AnimCurve_Type;
        case UFBX_ELEMENT_DISPLAY_LAYER: return &DisplayLayer_Type;
        case UFBX_ELEMENT_SELECTION_SET: return &SelectionSet_Type;
        case UFBX_ELEMENT_SELECTION_NODE: return &SelectionNode_Type;
        case UFBX_ELEMENT_CHARACTER: return &Character_Type;
        case UFBX_ELEMENT_CONSTRAINT: return &Constraint_Type;
        case UFBX_ELEMENT_AUDIO_LAYER: return &AudioLayer_Type;
        case UFBX_ELEMENT_AUDIO_CLIP: return &AudioClip_Type;
        case UFBX_ELEMENT_POSE: return &Pose_Type;
        case UFBX_ELEMENT_METADATA_OBJECT: return &MetadataObject_Type;
        default: return NULL;
    }
}
static PyObject *Element_create(ufbx_element *elem, Context *ctx) {
    PyTypeObject *type = Element_typeof(elem->type);
    Element *obj = (Element*)PyObject_CallObject((PyObject*)type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = elem;
    return (PyObject*)obj;
}

static ModuleType generated_types[] = {
    { &BoolList_Type, "BoolList" },
    { &Uint32List_Type, "Uint32List" },
    { &RealList_Type, "RealList" },
    { &Vec2List_Type, "Vec2List" },
    { &Vec3List_Type, "Vec3List" },
    { &Vec4List_Type, "Vec4List" },
    { &StringList_Type, "StringList" },
    { &Int32List_Type, "Int32List" },
    { &Int64List_Type, "Int64List" },
    { &FloatList_Type, "FloatList" },
    { &DoubleList_Type, "DoubleList" },
    { &BlobList_Type, "BlobList" },
    { &DomNodeList_Type, "DomNodeList" },
    { &DomValueList_Type, "DomValueList" },
    { &PropList_Type, "PropList" },
    { &ElementList_Type, "ElementList" },
    { &UnknownList_Type, "UnknownList" },
    { &NodeList_Type, "NodeList" },
    { &MeshList_Type, "MeshList" },
    { &LightList_Type, "LightList" },
    { &CameraList_Type, "CameraList" },
    { &BoneList_Type, "BoneList" },
    { &EmptyList_Type, "EmptyList" },
    { &LineCurveList_Type, "LineCurveList" },
    { &NurbsCurveList_Type, "NurbsCurveList" },
    { &NurbsSurfaceList_Type, "NurbsSurfaceList" },
    { &NurbsTrimSurfaceList_Type, "NurbsTrimSurfaceList" },
    { &NurbsTrimBoundaryList_Type, "NurbsTrimBoundaryList" },
    { &ProceduralGeometryList_Type, "ProceduralGeometryList" },
    { &StereoCameraList_Type, "StereoCameraList" },
    { &CameraSwitcherList_Type, "CameraSwitcherList" },
    { &MarkerList_Type, "MarkerList" },
    { &LodGroupList_Type, "LodGroupList" },
    { &SkinDeformerList_Type, "SkinDeformerList" },
    { &SkinClusterList_Type, "SkinClusterList" },
    { &BlendDeformerList_Type, "BlendDeformerList" },
    { &BlendChannelList_Type, "BlendChannelList" },
    { &BlendShapeList_Type, "BlendShapeList" },
    { &CacheDeformerList_Type, "CacheDeformerList" },
    { &CacheFileList_Type, "CacheFileList" },
    { &MaterialList_Type, "MaterialList" },
    { &TextureList_Type, "TextureList" },
    { &VideoList_Type, "VideoList" },
    { &ShaderList_Type, "ShaderList" },
    { &ShaderBindingList_Type, "ShaderBindingList" },
    { &AnimStackList_Type, "AnimStackList" },
    { &AnimLayerList_Type, "AnimLayerList" },
    { &AnimValueList_Type, "AnimValueList" },
    { &AnimCurveList_Type, "AnimCurveList" },
    { &DisplayLayerList_Type, "DisplayLayerList" },
    { &SelectionSetList_Type, "SelectionSetList" },
    { &SelectionNodeList_Type, "SelectionNodeList" },
    { &CharacterList_Type, "CharacterList" },
    { &ConstraintList_Type, "ConstraintList" },
    { &AudioLayerList_Type, "AudioLayerList" },
    { &AudioClipList_Type, "AudioClipList" },
    { &PoseList_Type, "PoseList" },
    { &MetadataObjectList_Type, "MetadataObjectList" },
    { &ConnectionList_Type, "ConnectionList" },
    { &UvSetList_Type, "UvSetList" },
    { &ColorSetList_Type, "ColorSetList" },
    { &EdgeList_Type, "EdgeList" },
    { &FaceList_Type, "FaceList" },
    { &MeshPartList_Type, "MeshPartList" },
    { &FaceGroupList_Type, "FaceGroupList" },
    { &SubdivisionWeightRangeList_Type, "SubdivisionWeightRangeList" },
    { &SubdivisionWeightList_Type, "SubdivisionWeightList" },
    { &LineSegmentList_Type, "LineSegmentList" },
    { &LodLevelList_Type, "LodLevelList" },
    { &SkinVertexList_Type, "SkinVertexList" },
    { &SkinWeightList_Type, "SkinWeightList" },
    { &BlendKeyframeList_Type, "BlendKeyframeList" },
    { &CacheFrameList_Type, "CacheFrameList" },
    { &CacheChannelList_Type, "CacheChannelList" },
    { &MaterialTextureList_Type, "MaterialTextureList" },
    { &TextureLayerList_Type, "TextureLayerList" },
    { &ShaderTextureInputList_Type, "ShaderTextureInputList" },
    { &TextureFileList_Type, "TextureFileList" },
    { &ShaderPropBindingList_Type, "ShaderPropBindingList" },
    { &PropOverrideList_Type, "PropOverrideList" },
    { &TransformOverrideList_Type, "TransformOverrideList" },
    { &AnimPropList_Type, "AnimPropList" },
    { &KeyframeList_Type, "KeyframeList" },
    { &ConstraintTargetList_Type, "ConstraintTargetList" },
    { &BonePoseList_Type, "BonePoseList" },
    { &NameElementList_Type, "NameElementList" },
    { &WarningList_Type, "WarningList" },
    { &BakedVec3List_Type, "BakedVec3List" },
    { &BakedQuatList_Type, "BakedQuatList" },
    { &BakedNodeList_Type, "BakedNodeList" },
    { &BakedPropList_Type, "BakedPropList" },
    { &BakedElementList_Type, "BakedElementList" },
    { &ConstUint32List_Type, "ConstUint32List" },
    { &ConstRealList_Type, "ConstRealList" },
    { &ConstPropOverrideDescList_Type, "ConstPropOverrideDescList" },
    { &ConstTransformOverrideList_Type, "ConstTransformOverrideList" },
    { &VoidList_Type, "VoidList" },
    { &DomValue_Type, "DomValue" },
    { &DomNode_Type, "DomNode" },
    { &Prop_Type, "Prop" },
    { &Props_Type, "Props" },
    { &Connection_Type, "Connection" },
    { &Element_Type, "Element" },
    { &Unknown_Type, "Unknown" },
    { &Node_Type, "Node" },
    { &VertexAttrib_Type, "VertexAttrib" },
    { &VertexReal_Type, "VertexReal" },
    { &VertexVec2_Type, "VertexVec2" },
    { &VertexVec3_Type, "VertexVec3" },
    { &VertexVec4_Type, "VertexVec4" },
    { &UvSet_Type, "UvSet" },
    { &ColorSet_Type, "ColorSet" },
    { &MeshPart_Type, "MeshPart" },
    { &FaceGroup_Type, "FaceGroup" },
    { &SubdivisionWeightRange_Type, "SubdivisionWeightRange" },
    { &SubdivisionWeight_Type, "SubdivisionWeight" },
    { &SubdivisionResult_Type, "SubdivisionResult" },
    { &Mesh_Type, "Mesh" },
    { &Light_Type, "Light" },
    { &Camera_Type, "Camera" },
    { &Bone_Type, "Bone" },
    { &Empty_Type, "Empty" },
    { &LineSegment_Type, "LineSegment" },
    { &LineCurve_Type, "LineCurve" },
    { &NurbsBasis_Type, "NurbsBasis" },
    { &NurbsCurve_Type, "NurbsCurve" },
    { &NurbsSurface_Type, "NurbsSurface" },
    { &NurbsTrimSurface_Type, "NurbsTrimSurface" },
    { &NurbsTrimBoundary_Type, "NurbsTrimBoundary" },
    { &ProceduralGeometry_Type, "ProceduralGeometry" },
    { &StereoCamera_Type, "StereoCamera" },
    { &CameraSwitcher_Type, "CameraSwitcher" },
    { &Marker_Type, "Marker" },
    { &LodGroup_Type, "LodGroup" },
    { &SkinDeformer_Type, "SkinDeformer" },
    { &SkinCluster_Type, "SkinCluster" },
    { &BlendDeformer_Type, "BlendDeformer" },
    { &BlendKeyframe_Type, "BlendKeyframe" },
    { &BlendChannel_Type, "BlendChannel" },
    { &BlendShape_Type, "BlendShape" },
    { &CacheFrame_Type, "CacheFrame" },
    { &CacheChannel_Type, "CacheChannel" },
    { &GeometryCache_Type, "GeometryCache" },
    { &CacheDeformer_Type, "CacheDeformer" },
    { &CacheFile_Type, "CacheFile" },
    { &MaterialMap_Type, "MaterialMap" },
    { &MaterialFeatureInfo_Type, "MaterialFeatureInfo" },
    { &MaterialTexture_Type, "MaterialTexture" },
    { &MaterialFbxMaps_Type, "MaterialFbxMaps" },
    { &MaterialPbrMaps_Type, "MaterialPbrMaps" },
    { &MaterialFeatures_Type, "MaterialFeatures" },
    { &Material_Type, "Material" },
    { &TextureLayer_Type, "TextureLayer" },
    { &ShaderTextureInput_Type, "ShaderTextureInput" },
    { &ShaderTexture_Type, "ShaderTexture" },
    { &TextureFile_Type, "TextureFile" },
    { &Texture_Type, "Texture" },
    { &Video_Type, "Video" },
    { &Shader_Type, "Shader" },
    { &ShaderPropBinding_Type, "ShaderPropBinding" },
    { &ShaderBinding_Type, "ShaderBinding" },
    { &PropOverride_Type, "PropOverride" },
    { &Anim_Type, "Anim" },
    { &AnimStack_Type, "AnimStack" },
    { &AnimProp_Type, "AnimProp" },
    { &AnimLayer_Type, "AnimLayer" },
    { &AnimValue_Type, "AnimValue" },
    { &Extrapolation_Type, "Extrapolation" },
    { &AnimCurve_Type, "AnimCurve" },
    { &DisplayLayer_Type, "DisplayLayer" },
    { &SelectionSet_Type, "SelectionSet" },
    { &SelectionNode_Type, "SelectionNode" },
    { &Character_Type, "Character" },
    { &ConstraintTarget_Type, "ConstraintTarget" },
    { &Constraint_Type, "Constraint" },
    { &AudioLayer_Type, "AudioLayer" },
    { &AudioClip_Type, "AudioClip" },
    { &BonePose_Type, "BonePose" },
    { &Pose_Type, "Pose" },
    { &MetadataObject_Type, "MetadataObject" },
    { &NameElement_Type, "NameElement" },
    { &Application_Type, "Application" },
    { &Warning_Type, "Warning" },
    { &Thumbnail_Type, "Thumbnail" },
    { &Metadata_Type, "Metadata" },
    { &SceneSettings_Type, "SceneSettings" },
    { &Scene_Type, "Scene" },
    { &VertexStream_Type, "VertexStream" },
    { &OpenFileInfo_Type, "OpenFileInfo" },
    { &OpenFileOpts_Type, "OpenFileOpts" },
    { &ErrorFrame_Type, "ErrorFrame" },
    { &Error_Type, "Error" },
    { &Progress_Type, "Progress" },
    { &InflateInput_Type, "InflateInput" },
    { &InflateRetain_Type, "InflateRetain" },
    { &BakedVec3_Type, "BakedVec3" },
    { &BakedQuat_Type, "BakedQuat" },
    { &BakedNode_Type, "BakedNode" },
    { &BakedProp_Type, "BakedProp" },
    { &BakedElement_Type, "BakedElement" },
    { &BakedAnimMetadata_Type, "BakedAnimMetadata" },
    { &BakedAnim_Type, "BakedAnim" },
    { &ThreadPoolInfo_Type, "ThreadPoolInfo" },
    { &Panic_Type, "Panic" },
};

