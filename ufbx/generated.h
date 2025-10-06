#include "prelude.h"

static PyObject *RotationOrder_Enum;
static PyObject *DomValueType_Enum;
static PyObject *PropType_Enum;
static PyObject *PropFlags_Enum;
static PyObject *ElementType_Enum;
static PyObject *InheritMode_Enum;
static PyObject *MirrorAxis_Enum;
static PyObject *SubdivisionDisplayMode_Enum;
static PyObject *SubdivisionBoundary_Enum;
static PyObject *LightType_Enum;
static PyObject *LightDecay_Enum;
static PyObject *LightAreaShape_Enum;
static PyObject *ProjectionMode_Enum;
static PyObject *AspectMode_Enum;
static PyObject *ApertureMode_Enum;
static PyObject *GateFit_Enum;
static PyObject *ApertureFormat_Enum;
static PyObject *CoordinateAxis_Enum;
static PyObject *NurbsTopology_Enum;
static PyObject *MarkerType_Enum;
static PyObject *LodDisplay_Enum;
static PyObject *SkinningMethod_Enum;
static PyObject *CacheFileFormat_Enum;
static PyObject *CacheDataFormat_Enum;
static PyObject *CacheDataEncoding_Enum;
static PyObject *CacheInterpretation_Enum;
static PyObject *ShaderType_Enum;
static PyObject *MaterialFbxMap_Enum;
static PyObject *MaterialPbrMap_Enum;
static PyObject *MaterialFeature_Enum;
static PyObject *TextureType_Enum;
static PyObject *BlendMode_Enum;
static PyObject *WrapMode_Enum;
static PyObject *ShaderTextureType_Enum;
static PyObject *Interpolation_Enum;
static PyObject *ExtrapolationMode_Enum;
static PyObject *ConstraintType_Enum;
static PyObject *ConstraintAimUpType_Enum;
static PyObject *ConstraintIkPoleType_Enum;
static PyObject *Exporter_Enum;
static PyObject *FileFormat_Enum;
static PyObject *WarningType_Enum;
static PyObject *ThumbnailFormat_Enum;
static PyObject *SpaceConversion_Enum;
static PyObject *GeometryTransformHandling_Enum;
static PyObject *InheritModeHandling_Enum;
static PyObject *PivotHandling_Enum;
static PyObject *TimeMode_Enum;
static PyObject *TimeProtocol_Enum;
static PyObject *SnapMode_Enum;
static PyObject *TopoFlags_Enum;
static PyObject *OpenFileType_Enum;
static PyObject *ErrorType_Enum;
static PyObject *ProgressResult_Enum;
static PyObject *IndexErrorHandling_Enum;
static PyObject *UnicodeErrorHandling_Enum;
static PyObject *BakedKeyFlags_Enum;
static PyObject *EvaluateFlags_Enum;
static PyObject *BakeStepHandling_Enum;
static PyObject *TransformFlags_Enum;

static PyObject *Transform_from(const ufbx_transform *v);
static ufbx_transform Transform_to(PyObject *v);
static PyObject *Edge_from(const ufbx_edge *v);
static ufbx_edge Edge_to(PyObject *v);
static PyObject *Face_from(const ufbx_face *v);
static ufbx_face Face_to(PyObject *v);
static PyObject *CoordinateAxes_from(const ufbx_coordinate_axes *v);
static ufbx_coordinate_axes CoordinateAxes_to(PyObject *v);
static PyObject *LodLevel_from(const ufbx_lod_level *v);
static ufbx_lod_level LodLevel_to(PyObject *v);
static PyObject *SkinVertex_from(const ufbx_skin_vertex *v);
static ufbx_skin_vertex SkinVertex_to(PyObject *v);
static PyObject *SkinWeight_from(const ufbx_skin_weight *v);
static ufbx_skin_weight SkinWeight_to(PyObject *v);
static PyObject *TransformOverride_from(const ufbx_transform_override *v);
static ufbx_transform_override TransformOverride_to(PyObject *v);
static PyObject *Tangent_from(const ufbx_tangent *v);
static ufbx_tangent Tangent_to(PyObject *v);
static PyObject *Keyframe_from(const ufbx_keyframe *v);
static ufbx_keyframe Keyframe_to(PyObject *v);
static PyObject *CurvePoint_from(const ufbx_curve_point *v);
static ufbx_curve_point CurvePoint_to(PyObject *v);
static PyObject *SurfacePoint_from(const ufbx_surface_point *v);
static ufbx_surface_point SurfacePoint_to(PyObject *v);
static PyObject *TopoEdge_from(const ufbx_topo_edge *v);
static ufbx_topo_edge TopoEdge_to(PyObject *v);

static PyObject *VoidList_from(ufbx_void_list *data, Context *ctx);
static PyObject *DomValue_from(ufbx_dom_value *data, Context *ctx);
static PyObject *DomNode_from(ufbx_dom_node *data, Context *ctx);
static PyObject *Prop_from(ufbx_prop *data, Context *ctx);
static PyObject *Props_from(ufbx_props *data, Context *ctx);
static PyObject *Connection_from(ufbx_connection *data, Context *ctx);
static PyObject *VertexAttrib_from(ufbx_vertex_attrib *data, Context *ctx);
static PyObject *VertexReal_from(ufbx_vertex_real *data, Context *ctx);
static PyObject *VertexVec2_from(ufbx_vertex_vec2 *data, Context *ctx);
static PyObject *VertexVec3_from(ufbx_vertex_vec3 *data, Context *ctx);
static PyObject *VertexVec4_from(ufbx_vertex_vec4 *data, Context *ctx);
static PyObject *UvSet_from(ufbx_uv_set *data, Context *ctx);
static PyObject *ColorSet_from(ufbx_color_set *data, Context *ctx);
static PyObject *MeshPart_from(ufbx_mesh_part *data, Context *ctx);
static PyObject *FaceGroup_from(ufbx_face_group *data, Context *ctx);
static PyObject *SubdivisionWeightRange_from(ufbx_subdivision_weight_range *data, Context *ctx);
static PyObject *SubdivisionWeight_from(ufbx_subdivision_weight *data, Context *ctx);
static PyObject *SubdivisionResult_from(ufbx_subdivision_result *data, Context *ctx);
static PyObject *LineSegment_from(ufbx_line_segment *data, Context *ctx);
static PyObject *NurbsBasis_from(ufbx_nurbs_basis *data, Context *ctx);
static PyObject *BlendKeyframe_from(ufbx_blend_keyframe *data, Context *ctx);
static PyObject *CacheFrame_from(ufbx_cache_frame *data, Context *ctx);
static PyObject *CacheChannel_from(ufbx_cache_channel *data, Context *ctx);
static PyObject *GeometryCache_from(ufbx_geometry_cache *data, Context *ctx);
static PyObject *MaterialMap_from(ufbx_material_map *data, Context *ctx);
static PyObject *MaterialFeatureInfo_from(ufbx_material_feature_info *data, Context *ctx);
static PyObject *MaterialTexture_from(ufbx_material_texture *data, Context *ctx);
static PyObject *MaterialFbxMaps_from(ufbx_material_fbx_maps *data, Context *ctx);
static PyObject *MaterialPbrMaps_from(ufbx_material_pbr_maps *data, Context *ctx);
static PyObject *MaterialFeatures_from(ufbx_material_features *data, Context *ctx);
static PyObject *TextureLayer_from(ufbx_texture_layer *data, Context *ctx);
static PyObject *ShaderTextureInput_from(ufbx_shader_texture_input *data, Context *ctx);
static PyObject *ShaderTexture_from(ufbx_shader_texture *data, Context *ctx);
static PyObject *TextureFile_from(ufbx_texture_file *data, Context *ctx);
static PyObject *ShaderPropBinding_from(ufbx_shader_prop_binding *data, Context *ctx);
static PyObject *PropOverride_from(ufbx_prop_override *data, Context *ctx);
static PyObject *Anim_from(ufbx_anim *data, Context *ctx);
static PyObject *AnimProp_from(ufbx_anim_prop *data, Context *ctx);
static PyObject *Extrapolation_from(ufbx_extrapolation *data, Context *ctx);
static PyObject *ConstraintTarget_from(ufbx_constraint_target *data, Context *ctx);
static PyObject *BonePose_from(ufbx_bone_pose *data, Context *ctx);
static PyObject *NameElement_from(ufbx_name_element *data, Context *ctx);
static PyObject *Application_from(ufbx_application *data, Context *ctx);
static PyObject *Warning_from(ufbx_warning *data, Context *ctx);
static PyObject *Thumbnail_from(ufbx_thumbnail *data, Context *ctx);
static PyObject *Metadata_from(ufbx_metadata *data, Context *ctx);
static PyObject *SceneSettings_from(ufbx_scene_settings *data, Context *ctx);
static PyObject *Scene_from(ufbx_scene *data, Context *ctx);
static PyObject *VertexStream_from(ufbx_vertex_stream *data, Context *ctx);
static PyObject *OpenFileInfo_from(ufbx_open_file_info *data, Context *ctx);
static PyObject *OpenFileOpts_from(ufbx_open_file_opts *data, Context *ctx);
static PyObject *ErrorFrame_from(ufbx_error_frame *data, Context *ctx);
static PyObject *Error_from(ufbx_error *data, Context *ctx);
static PyObject *Progress_from(ufbx_progress *data, Context *ctx);
static PyObject *InflateInput_from(ufbx_inflate_input *data, Context *ctx);
static PyObject *InflateRetain_from(ufbx_inflate_retain *data, Context *ctx);
static PyObject *BakedVec3_from(ufbx_baked_vec3 *data, Context *ctx);
static PyObject *BakedQuat_from(ufbx_baked_quat *data, Context *ctx);
static PyObject *BakedNode_from(ufbx_baked_node *data, Context *ctx);
static PyObject *BakedProp_from(ufbx_baked_prop *data, Context *ctx);
static PyObject *BakedElement_from(ufbx_baked_element *data, Context *ctx);
static PyObject *BakedAnimMetadata_from(ufbx_baked_anim_metadata *data, Context *ctx);
static PyObject *BakedAnim_from(ufbx_baked_anim *data, Context *ctx);
static PyObject *ThreadPoolInfo_from(ufbx_thread_pool_info *data, Context *ctx);
static PyObject *Panic_from(ufbx_panic *data, Context *ctx);

static PyObject *error_type_objs[24];

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_bool_list data;
} BoolList;

static Py_ssize_t BoolList_len(BoolList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BoolList_item(BoolList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Py_NewRef(self->data.data[index] ? Py_True : Py_False);
}

static int BoolList_traverse(BoolList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BoolList_clear(BoolList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BoolList_dealloc(BoolList *self) {
    PyObject_GC_UnTrack(self);
    BoolList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BoolList_Sequence = {
    .sq_length = (lenfunc)&BoolList_len,
    .sq_item = (ssizeargfunc)&BoolList_item,
};

static PyTypeObject BoolList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BoolList",
    .tp_doc = PyDoc_STR("BoolList"),
    .tp_basicsize = sizeof(BoolList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BoolList_Sequence,
    .tp_dealloc = (destructor)&BoolList_dealloc,
    .tp_traverse = (traverseproc)&BoolList_traverse,
    .tp_clear = (inquiry)&BoolList_clear,
};

static PyObject *BoolList_from(ufbx_bool_list list, Context *ctx) {
    BoolList *obj = (BoolList*)PyObject_CallObject((PyObject*)&BoolList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_uint32_list data;
} Uint32List;

static Py_ssize_t Uint32List_len(Uint32List *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *Uint32List_item(Uint32List *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return PyLong_FromUnsignedLong((unsigned long)self->data.data[index]);
}

static int Uint32List_traverse(Uint32List *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int Uint32List_clear(Uint32List *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void Uint32List_dealloc(Uint32List *self) {
    PyObject_GC_UnTrack(self);
    Uint32List_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods Uint32List_Sequence = {
    .sq_length = (lenfunc)&Uint32List_len,
    .sq_item = (ssizeargfunc)&Uint32List_item,
};

static PyTypeObject Uint32List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Uint32List",
    .tp_doc = PyDoc_STR("Uint32List"),
    .tp_basicsize = sizeof(Uint32List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &Uint32List_Sequence,
    .tp_dealloc = (destructor)&Uint32List_dealloc,
    .tp_traverse = (traverseproc)&Uint32List_traverse,
    .tp_clear = (inquiry)&Uint32List_clear,
};

static PyObject *Uint32List_from(ufbx_uint32_list list, Context *ctx) {
    Uint32List *obj = (Uint32List*)PyObject_CallObject((PyObject*)&Uint32List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_real_list data;
} RealList;

static Py_ssize_t RealList_len(RealList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *RealList_item(RealList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return PyFloat_FromDouble(self->data.data[index]);
}

static int RealList_traverse(RealList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int RealList_clear(RealList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void RealList_dealloc(RealList *self) {
    PyObject_GC_UnTrack(self);
    RealList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods RealList_Sequence = {
    .sq_length = (lenfunc)&RealList_len,
    .sq_item = (ssizeargfunc)&RealList_item,
};

static PyTypeObject RealList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.RealList",
    .tp_doc = PyDoc_STR("RealList"),
    .tp_basicsize = sizeof(RealList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &RealList_Sequence,
    .tp_dealloc = (destructor)&RealList_dealloc,
    .tp_traverse = (traverseproc)&RealList_traverse,
    .tp_clear = (inquiry)&RealList_clear,
};

static PyObject *RealList_from(ufbx_real_list list, Context *ctx) {
    RealList *obj = (RealList*)PyObject_CallObject((PyObject*)&RealList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_vec2_list data;
} Vec2List;

static Py_ssize_t Vec2List_len(Vec2List *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *Vec2List_item(Vec2List *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Vec2_from(&self->data.data[index]);
}

static int Vec2List_traverse(Vec2List *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int Vec2List_clear(Vec2List *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void Vec2List_dealloc(Vec2List *self) {
    PyObject_GC_UnTrack(self);
    Vec2List_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods Vec2List_Sequence = {
    .sq_length = (lenfunc)&Vec2List_len,
    .sq_item = (ssizeargfunc)&Vec2List_item,
};

static PyTypeObject Vec2List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Vec2List",
    .tp_doc = PyDoc_STR("Vec2List"),
    .tp_basicsize = sizeof(Vec2List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &Vec2List_Sequence,
    .tp_dealloc = (destructor)&Vec2List_dealloc,
    .tp_traverse = (traverseproc)&Vec2List_traverse,
    .tp_clear = (inquiry)&Vec2List_clear,
};

static PyObject *Vec2List_from(ufbx_vec2_list list, Context *ctx) {
    Vec2List *obj = (Vec2List*)PyObject_CallObject((PyObject*)&Vec2List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_vec3_list data;
} Vec3List;

static Py_ssize_t Vec3List_len(Vec3List *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *Vec3List_item(Vec3List *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Vec3_from(&self->data.data[index]);
}

static int Vec3List_traverse(Vec3List *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int Vec3List_clear(Vec3List *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void Vec3List_dealloc(Vec3List *self) {
    PyObject_GC_UnTrack(self);
    Vec3List_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods Vec3List_Sequence = {
    .sq_length = (lenfunc)&Vec3List_len,
    .sq_item = (ssizeargfunc)&Vec3List_item,
};

static PyTypeObject Vec3List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Vec3List",
    .tp_doc = PyDoc_STR("Vec3List"),
    .tp_basicsize = sizeof(Vec3List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &Vec3List_Sequence,
    .tp_dealloc = (destructor)&Vec3List_dealloc,
    .tp_traverse = (traverseproc)&Vec3List_traverse,
    .tp_clear = (inquiry)&Vec3List_clear,
};

static PyObject *Vec3List_from(ufbx_vec3_list list, Context *ctx) {
    Vec3List *obj = (Vec3List*)PyObject_CallObject((PyObject*)&Vec3List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_vec4_list data;
} Vec4List;

static Py_ssize_t Vec4List_len(Vec4List *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *Vec4List_item(Vec4List *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Vec4_from(&self->data.data[index]);
}

static int Vec4List_traverse(Vec4List *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int Vec4List_clear(Vec4List *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void Vec4List_dealloc(Vec4List *self) {
    PyObject_GC_UnTrack(self);
    Vec4List_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods Vec4List_Sequence = {
    .sq_length = (lenfunc)&Vec4List_len,
    .sq_item = (ssizeargfunc)&Vec4List_item,
};

static PyTypeObject Vec4List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Vec4List",
    .tp_doc = PyDoc_STR("Vec4List"),
    .tp_basicsize = sizeof(Vec4List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &Vec4List_Sequence,
    .tp_dealloc = (destructor)&Vec4List_dealloc,
    .tp_traverse = (traverseproc)&Vec4List_traverse,
    .tp_clear = (inquiry)&Vec4List_clear,
};

static PyObject *Vec4List_from(ufbx_vec4_list list, Context *ctx) {
    Vec4List *obj = (Vec4List*)PyObject_CallObject((PyObject*)&Vec4List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_string_list data;
} StringList;

static Py_ssize_t StringList_len(StringList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *StringList_item(StringList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return String_from(self->data.data[index]);
}

static int StringList_traverse(StringList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int StringList_clear(StringList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void StringList_dealloc(StringList *self) {
    PyObject_GC_UnTrack(self);
    StringList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods StringList_Sequence = {
    .sq_length = (lenfunc)&StringList_len,
    .sq_item = (ssizeargfunc)&StringList_item,
};

static PyTypeObject StringList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.StringList",
    .tp_doc = PyDoc_STR("StringList"),
    .tp_basicsize = sizeof(StringList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &StringList_Sequence,
    .tp_dealloc = (destructor)&StringList_dealloc,
    .tp_traverse = (traverseproc)&StringList_traverse,
    .tp_clear = (inquiry)&StringList_clear,
};

static PyObject *StringList_from(ufbx_string_list list, Context *ctx) {
    StringList *obj = (StringList*)PyObject_CallObject((PyObject*)&StringList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_int32_list data;
} Int32List;

static Py_ssize_t Int32List_len(Int32List *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *Int32List_item(Int32List *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return PyLong_FromLong((long)self->data.data[index]);
}

static int Int32List_traverse(Int32List *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int Int32List_clear(Int32List *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void Int32List_dealloc(Int32List *self) {
    PyObject_GC_UnTrack(self);
    Int32List_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods Int32List_Sequence = {
    .sq_length = (lenfunc)&Int32List_len,
    .sq_item = (ssizeargfunc)&Int32List_item,
};

static PyTypeObject Int32List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Int32List",
    .tp_doc = PyDoc_STR("Int32List"),
    .tp_basicsize = sizeof(Int32List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &Int32List_Sequence,
    .tp_dealloc = (destructor)&Int32List_dealloc,
    .tp_traverse = (traverseproc)&Int32List_traverse,
    .tp_clear = (inquiry)&Int32List_clear,
};

static PyObject *Int32List_from(ufbx_int32_list list, Context *ctx) {
    Int32List *obj = (Int32List*)PyObject_CallObject((PyObject*)&Int32List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_int64_list data;
} Int64List;

static Py_ssize_t Int64List_len(Int64List *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *Int64List_item(Int64List *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return PyLong_FromLongLong((long long)self->data.data[index]);
}

static int Int64List_traverse(Int64List *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int Int64List_clear(Int64List *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void Int64List_dealloc(Int64List *self) {
    PyObject_GC_UnTrack(self);
    Int64List_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods Int64List_Sequence = {
    .sq_length = (lenfunc)&Int64List_len,
    .sq_item = (ssizeargfunc)&Int64List_item,
};

static PyTypeObject Int64List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Int64List",
    .tp_doc = PyDoc_STR("Int64List"),
    .tp_basicsize = sizeof(Int64List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &Int64List_Sequence,
    .tp_dealloc = (destructor)&Int64List_dealloc,
    .tp_traverse = (traverseproc)&Int64List_traverse,
    .tp_clear = (inquiry)&Int64List_clear,
};

static PyObject *Int64List_from(ufbx_int64_list list, Context *ctx) {
    Int64List *obj = (Int64List*)PyObject_CallObject((PyObject*)&Int64List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_float_list data;
} FloatList;

static Py_ssize_t FloatList_len(FloatList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *FloatList_item(FloatList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return PyFloat_FromDouble(self->data.data[index]);
}

static int FloatList_traverse(FloatList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int FloatList_clear(FloatList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void FloatList_dealloc(FloatList *self) {
    PyObject_GC_UnTrack(self);
    FloatList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods FloatList_Sequence = {
    .sq_length = (lenfunc)&FloatList_len,
    .sq_item = (ssizeargfunc)&FloatList_item,
};

static PyTypeObject FloatList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.FloatList",
    .tp_doc = PyDoc_STR("FloatList"),
    .tp_basicsize = sizeof(FloatList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &FloatList_Sequence,
    .tp_dealloc = (destructor)&FloatList_dealloc,
    .tp_traverse = (traverseproc)&FloatList_traverse,
    .tp_clear = (inquiry)&FloatList_clear,
};

static PyObject *FloatList_from(ufbx_float_list list, Context *ctx) {
    FloatList *obj = (FloatList*)PyObject_CallObject((PyObject*)&FloatList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_double_list data;
} DoubleList;

static Py_ssize_t DoubleList_len(DoubleList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *DoubleList_item(DoubleList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return PyFloat_FromDouble(self->data.data[index]);
}

static int DoubleList_traverse(DoubleList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int DoubleList_clear(DoubleList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void DoubleList_dealloc(DoubleList *self) {
    PyObject_GC_UnTrack(self);
    DoubleList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods DoubleList_Sequence = {
    .sq_length = (lenfunc)&DoubleList_len,
    .sq_item = (ssizeargfunc)&DoubleList_item,
};

static PyTypeObject DoubleList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DoubleList",
    .tp_doc = PyDoc_STR("DoubleList"),
    .tp_basicsize = sizeof(DoubleList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &DoubleList_Sequence,
    .tp_dealloc = (destructor)&DoubleList_dealloc,
    .tp_traverse = (traverseproc)&DoubleList_traverse,
    .tp_clear = (inquiry)&DoubleList_clear,
};

static PyObject *DoubleList_from(ufbx_double_list list, Context *ctx) {
    DoubleList *obj = (DoubleList*)PyObject_CallObject((PyObject*)&DoubleList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_blob_list data;
} BlobList;

static Py_ssize_t BlobList_len(BlobList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BlobList_item(BlobList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Blob_from(self->data.data[index]);
}

static int BlobList_traverse(BlobList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BlobList_clear(BlobList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BlobList_dealloc(BlobList *self) {
    PyObject_GC_UnTrack(self);
    BlobList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BlobList_Sequence = {
    .sq_length = (lenfunc)&BlobList_len,
    .sq_item = (ssizeargfunc)&BlobList_item,
};

static PyTypeObject BlobList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlobList",
    .tp_doc = PyDoc_STR("BlobList"),
    .tp_basicsize = sizeof(BlobList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BlobList_Sequence,
    .tp_dealloc = (destructor)&BlobList_dealloc,
    .tp_traverse = (traverseproc)&BlobList_traverse,
    .tp_clear = (inquiry)&BlobList_clear,
};

static PyObject *BlobList_from(ufbx_blob_list list, Context *ctx) {
    BlobList *obj = (BlobList*)PyObject_CallObject((PyObject*)&BlobList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_dom_node_list data;
} DomNodeList;

static Py_ssize_t DomNodeList_len(DomNodeList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *DomNodeList_item(DomNodeList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return to_pyobject_todo("ufbx_dom_node*");
}

static int DomNodeList_traverse(DomNodeList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int DomNodeList_clear(DomNodeList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void DomNodeList_dealloc(DomNodeList *self) {
    PyObject_GC_UnTrack(self);
    DomNodeList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods DomNodeList_Sequence = {
    .sq_length = (lenfunc)&DomNodeList_len,
    .sq_item = (ssizeargfunc)&DomNodeList_item,
};

static PyTypeObject DomNodeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DomNodeList",
    .tp_doc = PyDoc_STR("DomNodeList"),
    .tp_basicsize = sizeof(DomNodeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &DomNodeList_Sequence,
    .tp_dealloc = (destructor)&DomNodeList_dealloc,
    .tp_traverse = (traverseproc)&DomNodeList_traverse,
    .tp_clear = (inquiry)&DomNodeList_clear,
};

static PyObject *DomNodeList_from(ufbx_dom_node_list list, Context *ctx) {
    DomNodeList *obj = (DomNodeList*)PyObject_CallObject((PyObject*)&DomNodeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_dom_value_list data;
} DomValueList;

static Py_ssize_t DomValueList_len(DomValueList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *DomValueList_item(DomValueList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return DomValue_from(&self->data.data[index], self->ctx);
}

static int DomValueList_traverse(DomValueList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int DomValueList_clear(DomValueList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void DomValueList_dealloc(DomValueList *self) {
    PyObject_GC_UnTrack(self);
    DomValueList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods DomValueList_Sequence = {
    .sq_length = (lenfunc)&DomValueList_len,
    .sq_item = (ssizeargfunc)&DomValueList_item,
};

static PyTypeObject DomValueList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DomValueList",
    .tp_doc = PyDoc_STR("DomValueList"),
    .tp_basicsize = sizeof(DomValueList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &DomValueList_Sequence,
    .tp_dealloc = (destructor)&DomValueList_dealloc,
    .tp_traverse = (traverseproc)&DomValueList_traverse,
    .tp_clear = (inquiry)&DomValueList_clear,
};

static PyObject *DomValueList_from(ufbx_dom_value_list list, Context *ctx) {
    DomValueList *obj = (DomValueList*)PyObject_CallObject((PyObject*)&DomValueList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_prop_list data;
} PropList;

static Py_ssize_t PropList_len(PropList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *PropList_item(PropList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Prop_from(&self->data.data[index], self->ctx);
}

static int PropList_traverse(PropList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int PropList_clear(PropList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void PropList_dealloc(PropList *self) {
    PyObject_GC_UnTrack(self);
    PropList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods PropList_Sequence = {
    .sq_length = (lenfunc)&PropList_len,
    .sq_item = (ssizeargfunc)&PropList_item,
};

static PyTypeObject PropList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.PropList",
    .tp_doc = PyDoc_STR("PropList"),
    .tp_basicsize = sizeof(PropList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &PropList_Sequence,
    .tp_dealloc = (destructor)&PropList_dealloc,
    .tp_traverse = (traverseproc)&PropList_traverse,
    .tp_clear = (inquiry)&PropList_clear,
};

static PyObject *PropList_from(ufbx_prop_list list, Context *ctx) {
    PropList *obj = (PropList*)PyObject_CallObject((PyObject*)&PropList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_element_list data;
} ElementList;

static Py_ssize_t ElementList_len(ElementList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ElementList_item(ElementList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return to_pyobject_todo("ufbx_element*");
}

static int ElementList_traverse(ElementList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ElementList_clear(ElementList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ElementList_dealloc(ElementList *self) {
    PyObject_GC_UnTrack(self);
    ElementList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ElementList_Sequence = {
    .sq_length = (lenfunc)&ElementList_len,
    .sq_item = (ssizeargfunc)&ElementList_item,
};

static PyTypeObject ElementList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ElementList",
    .tp_doc = PyDoc_STR("ElementList"),
    .tp_basicsize = sizeof(ElementList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ElementList_Sequence,
    .tp_dealloc = (destructor)&ElementList_dealloc,
    .tp_traverse = (traverseproc)&ElementList_traverse,
    .tp_clear = (inquiry)&ElementList_clear,
};

static PyObject *ElementList_from(ufbx_element_list list, Context *ctx) {
    ElementList *obj = (ElementList*)PyObject_CallObject((PyObject*)&ElementList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_unknown_list data;
} UnknownList;

static Py_ssize_t UnknownList_len(UnknownList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *UnknownList_item(UnknownList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int UnknownList_traverse(UnknownList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int UnknownList_clear(UnknownList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void UnknownList_dealloc(UnknownList *self) {
    PyObject_GC_UnTrack(self);
    UnknownList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods UnknownList_Sequence = {
    .sq_length = (lenfunc)&UnknownList_len,
    .sq_item = (ssizeargfunc)&UnknownList_item,
};

static PyTypeObject UnknownList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.UnknownList",
    .tp_doc = PyDoc_STR("UnknownList"),
    .tp_basicsize = sizeof(UnknownList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &UnknownList_Sequence,
    .tp_dealloc = (destructor)&UnknownList_dealloc,
    .tp_traverse = (traverseproc)&UnknownList_traverse,
    .tp_clear = (inquiry)&UnknownList_clear,
};

static PyObject *UnknownList_from(ufbx_unknown_list list, Context *ctx) {
    UnknownList *obj = (UnknownList*)PyObject_CallObject((PyObject*)&UnknownList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_node_list data;
} NodeList;

static Py_ssize_t NodeList_len(NodeList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *NodeList_item(NodeList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int NodeList_traverse(NodeList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int NodeList_clear(NodeList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void NodeList_dealloc(NodeList *self) {
    PyObject_GC_UnTrack(self);
    NodeList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods NodeList_Sequence = {
    .sq_length = (lenfunc)&NodeList_len,
    .sq_item = (ssizeargfunc)&NodeList_item,
};

static PyTypeObject NodeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NodeList",
    .tp_doc = PyDoc_STR("NodeList"),
    .tp_basicsize = sizeof(NodeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &NodeList_Sequence,
    .tp_dealloc = (destructor)&NodeList_dealloc,
    .tp_traverse = (traverseproc)&NodeList_traverse,
    .tp_clear = (inquiry)&NodeList_clear,
};

static PyObject *NodeList_from(ufbx_node_list list, Context *ctx) {
    NodeList *obj = (NodeList*)PyObject_CallObject((PyObject*)&NodeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_mesh_list data;
} MeshList;

static Py_ssize_t MeshList_len(MeshList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *MeshList_item(MeshList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int MeshList_traverse(MeshList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int MeshList_clear(MeshList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void MeshList_dealloc(MeshList *self) {
    PyObject_GC_UnTrack(self);
    MeshList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods MeshList_Sequence = {
    .sq_length = (lenfunc)&MeshList_len,
    .sq_item = (ssizeargfunc)&MeshList_item,
};

static PyTypeObject MeshList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MeshList",
    .tp_doc = PyDoc_STR("MeshList"),
    .tp_basicsize = sizeof(MeshList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &MeshList_Sequence,
    .tp_dealloc = (destructor)&MeshList_dealloc,
    .tp_traverse = (traverseproc)&MeshList_traverse,
    .tp_clear = (inquiry)&MeshList_clear,
};

static PyObject *MeshList_from(ufbx_mesh_list list, Context *ctx) {
    MeshList *obj = (MeshList*)PyObject_CallObject((PyObject*)&MeshList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_light_list data;
} LightList;

static Py_ssize_t LightList_len(LightList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *LightList_item(LightList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int LightList_traverse(LightList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int LightList_clear(LightList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void LightList_dealloc(LightList *self) {
    PyObject_GC_UnTrack(self);
    LightList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods LightList_Sequence = {
    .sq_length = (lenfunc)&LightList_len,
    .sq_item = (ssizeargfunc)&LightList_item,
};

static PyTypeObject LightList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LightList",
    .tp_doc = PyDoc_STR("LightList"),
    .tp_basicsize = sizeof(LightList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &LightList_Sequence,
    .tp_dealloc = (destructor)&LightList_dealloc,
    .tp_traverse = (traverseproc)&LightList_traverse,
    .tp_clear = (inquiry)&LightList_clear,
};

static PyObject *LightList_from(ufbx_light_list list, Context *ctx) {
    LightList *obj = (LightList*)PyObject_CallObject((PyObject*)&LightList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_camera_list data;
} CameraList;

static Py_ssize_t CameraList_len(CameraList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *CameraList_item(CameraList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int CameraList_traverse(CameraList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int CameraList_clear(CameraList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void CameraList_dealloc(CameraList *self) {
    PyObject_GC_UnTrack(self);
    CameraList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods CameraList_Sequence = {
    .sq_length = (lenfunc)&CameraList_len,
    .sq_item = (ssizeargfunc)&CameraList_item,
};

static PyTypeObject CameraList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CameraList",
    .tp_doc = PyDoc_STR("CameraList"),
    .tp_basicsize = sizeof(CameraList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &CameraList_Sequence,
    .tp_dealloc = (destructor)&CameraList_dealloc,
    .tp_traverse = (traverseproc)&CameraList_traverse,
    .tp_clear = (inquiry)&CameraList_clear,
};

static PyObject *CameraList_from(ufbx_camera_list list, Context *ctx) {
    CameraList *obj = (CameraList*)PyObject_CallObject((PyObject*)&CameraList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_bone_list data;
} BoneList;

static Py_ssize_t BoneList_len(BoneList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BoneList_item(BoneList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int BoneList_traverse(BoneList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BoneList_clear(BoneList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BoneList_dealloc(BoneList *self) {
    PyObject_GC_UnTrack(self);
    BoneList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BoneList_Sequence = {
    .sq_length = (lenfunc)&BoneList_len,
    .sq_item = (ssizeargfunc)&BoneList_item,
};

static PyTypeObject BoneList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BoneList",
    .tp_doc = PyDoc_STR("BoneList"),
    .tp_basicsize = sizeof(BoneList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BoneList_Sequence,
    .tp_dealloc = (destructor)&BoneList_dealloc,
    .tp_traverse = (traverseproc)&BoneList_traverse,
    .tp_clear = (inquiry)&BoneList_clear,
};

static PyObject *BoneList_from(ufbx_bone_list list, Context *ctx) {
    BoneList *obj = (BoneList*)PyObject_CallObject((PyObject*)&BoneList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_empty_list data;
} EmptyList;

static Py_ssize_t EmptyList_len(EmptyList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *EmptyList_item(EmptyList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int EmptyList_traverse(EmptyList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int EmptyList_clear(EmptyList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void EmptyList_dealloc(EmptyList *self) {
    PyObject_GC_UnTrack(self);
    EmptyList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods EmptyList_Sequence = {
    .sq_length = (lenfunc)&EmptyList_len,
    .sq_item = (ssizeargfunc)&EmptyList_item,
};

static PyTypeObject EmptyList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.EmptyList",
    .tp_doc = PyDoc_STR("EmptyList"),
    .tp_basicsize = sizeof(EmptyList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &EmptyList_Sequence,
    .tp_dealloc = (destructor)&EmptyList_dealloc,
    .tp_traverse = (traverseproc)&EmptyList_traverse,
    .tp_clear = (inquiry)&EmptyList_clear,
};

static PyObject *EmptyList_from(ufbx_empty_list list, Context *ctx) {
    EmptyList *obj = (EmptyList*)PyObject_CallObject((PyObject*)&EmptyList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_line_curve_list data;
} LineCurveList;

static Py_ssize_t LineCurveList_len(LineCurveList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *LineCurveList_item(LineCurveList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int LineCurveList_traverse(LineCurveList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int LineCurveList_clear(LineCurveList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void LineCurveList_dealloc(LineCurveList *self) {
    PyObject_GC_UnTrack(self);
    LineCurveList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods LineCurveList_Sequence = {
    .sq_length = (lenfunc)&LineCurveList_len,
    .sq_item = (ssizeargfunc)&LineCurveList_item,
};

static PyTypeObject LineCurveList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LineCurveList",
    .tp_doc = PyDoc_STR("LineCurveList"),
    .tp_basicsize = sizeof(LineCurveList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &LineCurveList_Sequence,
    .tp_dealloc = (destructor)&LineCurveList_dealloc,
    .tp_traverse = (traverseproc)&LineCurveList_traverse,
    .tp_clear = (inquiry)&LineCurveList_clear,
};

static PyObject *LineCurveList_from(ufbx_line_curve_list list, Context *ctx) {
    LineCurveList *obj = (LineCurveList*)PyObject_CallObject((PyObject*)&LineCurveList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_nurbs_curve_list data;
} NurbsCurveList;

static Py_ssize_t NurbsCurveList_len(NurbsCurveList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *NurbsCurveList_item(NurbsCurveList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int NurbsCurveList_traverse(NurbsCurveList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int NurbsCurveList_clear(NurbsCurveList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void NurbsCurveList_dealloc(NurbsCurveList *self) {
    PyObject_GC_UnTrack(self);
    NurbsCurveList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods NurbsCurveList_Sequence = {
    .sq_length = (lenfunc)&NurbsCurveList_len,
    .sq_item = (ssizeargfunc)&NurbsCurveList_item,
};

static PyTypeObject NurbsCurveList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsCurveList",
    .tp_doc = PyDoc_STR("NurbsCurveList"),
    .tp_basicsize = sizeof(NurbsCurveList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &NurbsCurveList_Sequence,
    .tp_dealloc = (destructor)&NurbsCurveList_dealloc,
    .tp_traverse = (traverseproc)&NurbsCurveList_traverse,
    .tp_clear = (inquiry)&NurbsCurveList_clear,
};

static PyObject *NurbsCurveList_from(ufbx_nurbs_curve_list list, Context *ctx) {
    NurbsCurveList *obj = (NurbsCurveList*)PyObject_CallObject((PyObject*)&NurbsCurveList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_nurbs_surface_list data;
} NurbsSurfaceList;

static Py_ssize_t NurbsSurfaceList_len(NurbsSurfaceList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *NurbsSurfaceList_item(NurbsSurfaceList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int NurbsSurfaceList_traverse(NurbsSurfaceList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int NurbsSurfaceList_clear(NurbsSurfaceList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void NurbsSurfaceList_dealloc(NurbsSurfaceList *self) {
    PyObject_GC_UnTrack(self);
    NurbsSurfaceList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods NurbsSurfaceList_Sequence = {
    .sq_length = (lenfunc)&NurbsSurfaceList_len,
    .sq_item = (ssizeargfunc)&NurbsSurfaceList_item,
};

static PyTypeObject NurbsSurfaceList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsSurfaceList",
    .tp_doc = PyDoc_STR("NurbsSurfaceList"),
    .tp_basicsize = sizeof(NurbsSurfaceList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &NurbsSurfaceList_Sequence,
    .tp_dealloc = (destructor)&NurbsSurfaceList_dealloc,
    .tp_traverse = (traverseproc)&NurbsSurfaceList_traverse,
    .tp_clear = (inquiry)&NurbsSurfaceList_clear,
};

static PyObject *NurbsSurfaceList_from(ufbx_nurbs_surface_list list, Context *ctx) {
    NurbsSurfaceList *obj = (NurbsSurfaceList*)PyObject_CallObject((PyObject*)&NurbsSurfaceList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_nurbs_trim_surface_list data;
} NurbsTrimSurfaceList;

static Py_ssize_t NurbsTrimSurfaceList_len(NurbsTrimSurfaceList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *NurbsTrimSurfaceList_item(NurbsTrimSurfaceList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int NurbsTrimSurfaceList_traverse(NurbsTrimSurfaceList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int NurbsTrimSurfaceList_clear(NurbsTrimSurfaceList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void NurbsTrimSurfaceList_dealloc(NurbsTrimSurfaceList *self) {
    PyObject_GC_UnTrack(self);
    NurbsTrimSurfaceList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods NurbsTrimSurfaceList_Sequence = {
    .sq_length = (lenfunc)&NurbsTrimSurfaceList_len,
    .sq_item = (ssizeargfunc)&NurbsTrimSurfaceList_item,
};

static PyTypeObject NurbsTrimSurfaceList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsTrimSurfaceList",
    .tp_doc = PyDoc_STR("NurbsTrimSurfaceList"),
    .tp_basicsize = sizeof(NurbsTrimSurfaceList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &NurbsTrimSurfaceList_Sequence,
    .tp_dealloc = (destructor)&NurbsTrimSurfaceList_dealloc,
    .tp_traverse = (traverseproc)&NurbsTrimSurfaceList_traverse,
    .tp_clear = (inquiry)&NurbsTrimSurfaceList_clear,
};

static PyObject *NurbsTrimSurfaceList_from(ufbx_nurbs_trim_surface_list list, Context *ctx) {
    NurbsTrimSurfaceList *obj = (NurbsTrimSurfaceList*)PyObject_CallObject((PyObject*)&NurbsTrimSurfaceList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_nurbs_trim_boundary_list data;
} NurbsTrimBoundaryList;

static Py_ssize_t NurbsTrimBoundaryList_len(NurbsTrimBoundaryList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *NurbsTrimBoundaryList_item(NurbsTrimBoundaryList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int NurbsTrimBoundaryList_traverse(NurbsTrimBoundaryList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int NurbsTrimBoundaryList_clear(NurbsTrimBoundaryList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void NurbsTrimBoundaryList_dealloc(NurbsTrimBoundaryList *self) {
    PyObject_GC_UnTrack(self);
    NurbsTrimBoundaryList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods NurbsTrimBoundaryList_Sequence = {
    .sq_length = (lenfunc)&NurbsTrimBoundaryList_len,
    .sq_item = (ssizeargfunc)&NurbsTrimBoundaryList_item,
};

static PyTypeObject NurbsTrimBoundaryList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsTrimBoundaryList",
    .tp_doc = PyDoc_STR("NurbsTrimBoundaryList"),
    .tp_basicsize = sizeof(NurbsTrimBoundaryList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &NurbsTrimBoundaryList_Sequence,
    .tp_dealloc = (destructor)&NurbsTrimBoundaryList_dealloc,
    .tp_traverse = (traverseproc)&NurbsTrimBoundaryList_traverse,
    .tp_clear = (inquiry)&NurbsTrimBoundaryList_clear,
};

static PyObject *NurbsTrimBoundaryList_from(ufbx_nurbs_trim_boundary_list list, Context *ctx) {
    NurbsTrimBoundaryList *obj = (NurbsTrimBoundaryList*)PyObject_CallObject((PyObject*)&NurbsTrimBoundaryList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_procedural_geometry_list data;
} ProceduralGeometryList;

static Py_ssize_t ProceduralGeometryList_len(ProceduralGeometryList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ProceduralGeometryList_item(ProceduralGeometryList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int ProceduralGeometryList_traverse(ProceduralGeometryList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ProceduralGeometryList_clear(ProceduralGeometryList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ProceduralGeometryList_dealloc(ProceduralGeometryList *self) {
    PyObject_GC_UnTrack(self);
    ProceduralGeometryList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ProceduralGeometryList_Sequence = {
    .sq_length = (lenfunc)&ProceduralGeometryList_len,
    .sq_item = (ssizeargfunc)&ProceduralGeometryList_item,
};

static PyTypeObject ProceduralGeometryList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ProceduralGeometryList",
    .tp_doc = PyDoc_STR("ProceduralGeometryList"),
    .tp_basicsize = sizeof(ProceduralGeometryList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ProceduralGeometryList_Sequence,
    .tp_dealloc = (destructor)&ProceduralGeometryList_dealloc,
    .tp_traverse = (traverseproc)&ProceduralGeometryList_traverse,
    .tp_clear = (inquiry)&ProceduralGeometryList_clear,
};

static PyObject *ProceduralGeometryList_from(ufbx_procedural_geometry_list list, Context *ctx) {
    ProceduralGeometryList *obj = (ProceduralGeometryList*)PyObject_CallObject((PyObject*)&ProceduralGeometryList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_stereo_camera_list data;
} StereoCameraList;

static Py_ssize_t StereoCameraList_len(StereoCameraList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *StereoCameraList_item(StereoCameraList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int StereoCameraList_traverse(StereoCameraList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int StereoCameraList_clear(StereoCameraList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void StereoCameraList_dealloc(StereoCameraList *self) {
    PyObject_GC_UnTrack(self);
    StereoCameraList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods StereoCameraList_Sequence = {
    .sq_length = (lenfunc)&StereoCameraList_len,
    .sq_item = (ssizeargfunc)&StereoCameraList_item,
};

static PyTypeObject StereoCameraList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.StereoCameraList",
    .tp_doc = PyDoc_STR("StereoCameraList"),
    .tp_basicsize = sizeof(StereoCameraList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &StereoCameraList_Sequence,
    .tp_dealloc = (destructor)&StereoCameraList_dealloc,
    .tp_traverse = (traverseproc)&StereoCameraList_traverse,
    .tp_clear = (inquiry)&StereoCameraList_clear,
};

static PyObject *StereoCameraList_from(ufbx_stereo_camera_list list, Context *ctx) {
    StereoCameraList *obj = (StereoCameraList*)PyObject_CallObject((PyObject*)&StereoCameraList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_camera_switcher_list data;
} CameraSwitcherList;

static Py_ssize_t CameraSwitcherList_len(CameraSwitcherList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *CameraSwitcherList_item(CameraSwitcherList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int CameraSwitcherList_traverse(CameraSwitcherList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int CameraSwitcherList_clear(CameraSwitcherList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void CameraSwitcherList_dealloc(CameraSwitcherList *self) {
    PyObject_GC_UnTrack(self);
    CameraSwitcherList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods CameraSwitcherList_Sequence = {
    .sq_length = (lenfunc)&CameraSwitcherList_len,
    .sq_item = (ssizeargfunc)&CameraSwitcherList_item,
};

static PyTypeObject CameraSwitcherList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CameraSwitcherList",
    .tp_doc = PyDoc_STR("CameraSwitcherList"),
    .tp_basicsize = sizeof(CameraSwitcherList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &CameraSwitcherList_Sequence,
    .tp_dealloc = (destructor)&CameraSwitcherList_dealloc,
    .tp_traverse = (traverseproc)&CameraSwitcherList_traverse,
    .tp_clear = (inquiry)&CameraSwitcherList_clear,
};

static PyObject *CameraSwitcherList_from(ufbx_camera_switcher_list list, Context *ctx) {
    CameraSwitcherList *obj = (CameraSwitcherList*)PyObject_CallObject((PyObject*)&CameraSwitcherList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_marker_list data;
} MarkerList;

static Py_ssize_t MarkerList_len(MarkerList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *MarkerList_item(MarkerList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int MarkerList_traverse(MarkerList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int MarkerList_clear(MarkerList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void MarkerList_dealloc(MarkerList *self) {
    PyObject_GC_UnTrack(self);
    MarkerList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods MarkerList_Sequence = {
    .sq_length = (lenfunc)&MarkerList_len,
    .sq_item = (ssizeargfunc)&MarkerList_item,
};

static PyTypeObject MarkerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MarkerList",
    .tp_doc = PyDoc_STR("MarkerList"),
    .tp_basicsize = sizeof(MarkerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &MarkerList_Sequence,
    .tp_dealloc = (destructor)&MarkerList_dealloc,
    .tp_traverse = (traverseproc)&MarkerList_traverse,
    .tp_clear = (inquiry)&MarkerList_clear,
};

static PyObject *MarkerList_from(ufbx_marker_list list, Context *ctx) {
    MarkerList *obj = (MarkerList*)PyObject_CallObject((PyObject*)&MarkerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_lod_group_list data;
} LodGroupList;

static Py_ssize_t LodGroupList_len(LodGroupList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *LodGroupList_item(LodGroupList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int LodGroupList_traverse(LodGroupList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int LodGroupList_clear(LodGroupList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void LodGroupList_dealloc(LodGroupList *self) {
    PyObject_GC_UnTrack(self);
    LodGroupList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods LodGroupList_Sequence = {
    .sq_length = (lenfunc)&LodGroupList_len,
    .sq_item = (ssizeargfunc)&LodGroupList_item,
};

static PyTypeObject LodGroupList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LodGroupList",
    .tp_doc = PyDoc_STR("LodGroupList"),
    .tp_basicsize = sizeof(LodGroupList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &LodGroupList_Sequence,
    .tp_dealloc = (destructor)&LodGroupList_dealloc,
    .tp_traverse = (traverseproc)&LodGroupList_traverse,
    .tp_clear = (inquiry)&LodGroupList_clear,
};

static PyObject *LodGroupList_from(ufbx_lod_group_list list, Context *ctx) {
    LodGroupList *obj = (LodGroupList*)PyObject_CallObject((PyObject*)&LodGroupList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_skin_deformer_list data;
} SkinDeformerList;

static Py_ssize_t SkinDeformerList_len(SkinDeformerList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *SkinDeformerList_item(SkinDeformerList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int SkinDeformerList_traverse(SkinDeformerList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int SkinDeformerList_clear(SkinDeformerList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void SkinDeformerList_dealloc(SkinDeformerList *self) {
    PyObject_GC_UnTrack(self);
    SkinDeformerList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods SkinDeformerList_Sequence = {
    .sq_length = (lenfunc)&SkinDeformerList_len,
    .sq_item = (ssizeargfunc)&SkinDeformerList_item,
};

static PyTypeObject SkinDeformerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SkinDeformerList",
    .tp_doc = PyDoc_STR("SkinDeformerList"),
    .tp_basicsize = sizeof(SkinDeformerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &SkinDeformerList_Sequence,
    .tp_dealloc = (destructor)&SkinDeformerList_dealloc,
    .tp_traverse = (traverseproc)&SkinDeformerList_traverse,
    .tp_clear = (inquiry)&SkinDeformerList_clear,
};

static PyObject *SkinDeformerList_from(ufbx_skin_deformer_list list, Context *ctx) {
    SkinDeformerList *obj = (SkinDeformerList*)PyObject_CallObject((PyObject*)&SkinDeformerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_skin_cluster_list data;
} SkinClusterList;

static Py_ssize_t SkinClusterList_len(SkinClusterList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *SkinClusterList_item(SkinClusterList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int SkinClusterList_traverse(SkinClusterList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int SkinClusterList_clear(SkinClusterList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void SkinClusterList_dealloc(SkinClusterList *self) {
    PyObject_GC_UnTrack(self);
    SkinClusterList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods SkinClusterList_Sequence = {
    .sq_length = (lenfunc)&SkinClusterList_len,
    .sq_item = (ssizeargfunc)&SkinClusterList_item,
};

static PyTypeObject SkinClusterList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SkinClusterList",
    .tp_doc = PyDoc_STR("SkinClusterList"),
    .tp_basicsize = sizeof(SkinClusterList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &SkinClusterList_Sequence,
    .tp_dealloc = (destructor)&SkinClusterList_dealloc,
    .tp_traverse = (traverseproc)&SkinClusterList_traverse,
    .tp_clear = (inquiry)&SkinClusterList_clear,
};

static PyObject *SkinClusterList_from(ufbx_skin_cluster_list list, Context *ctx) {
    SkinClusterList *obj = (SkinClusterList*)PyObject_CallObject((PyObject*)&SkinClusterList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_blend_deformer_list data;
} BlendDeformerList;

static Py_ssize_t BlendDeformerList_len(BlendDeformerList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BlendDeformerList_item(BlendDeformerList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int BlendDeformerList_traverse(BlendDeformerList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BlendDeformerList_clear(BlendDeformerList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BlendDeformerList_dealloc(BlendDeformerList *self) {
    PyObject_GC_UnTrack(self);
    BlendDeformerList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BlendDeformerList_Sequence = {
    .sq_length = (lenfunc)&BlendDeformerList_len,
    .sq_item = (ssizeargfunc)&BlendDeformerList_item,
};

static PyTypeObject BlendDeformerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendDeformerList",
    .tp_doc = PyDoc_STR("BlendDeformerList"),
    .tp_basicsize = sizeof(BlendDeformerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BlendDeformerList_Sequence,
    .tp_dealloc = (destructor)&BlendDeformerList_dealloc,
    .tp_traverse = (traverseproc)&BlendDeformerList_traverse,
    .tp_clear = (inquiry)&BlendDeformerList_clear,
};

static PyObject *BlendDeformerList_from(ufbx_blend_deformer_list list, Context *ctx) {
    BlendDeformerList *obj = (BlendDeformerList*)PyObject_CallObject((PyObject*)&BlendDeformerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_blend_channel_list data;
} BlendChannelList;

static Py_ssize_t BlendChannelList_len(BlendChannelList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BlendChannelList_item(BlendChannelList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int BlendChannelList_traverse(BlendChannelList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BlendChannelList_clear(BlendChannelList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BlendChannelList_dealloc(BlendChannelList *self) {
    PyObject_GC_UnTrack(self);
    BlendChannelList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BlendChannelList_Sequence = {
    .sq_length = (lenfunc)&BlendChannelList_len,
    .sq_item = (ssizeargfunc)&BlendChannelList_item,
};

static PyTypeObject BlendChannelList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendChannelList",
    .tp_doc = PyDoc_STR("BlendChannelList"),
    .tp_basicsize = sizeof(BlendChannelList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BlendChannelList_Sequence,
    .tp_dealloc = (destructor)&BlendChannelList_dealloc,
    .tp_traverse = (traverseproc)&BlendChannelList_traverse,
    .tp_clear = (inquiry)&BlendChannelList_clear,
};

static PyObject *BlendChannelList_from(ufbx_blend_channel_list list, Context *ctx) {
    BlendChannelList *obj = (BlendChannelList*)PyObject_CallObject((PyObject*)&BlendChannelList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_blend_shape_list data;
} BlendShapeList;

static Py_ssize_t BlendShapeList_len(BlendShapeList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BlendShapeList_item(BlendShapeList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int BlendShapeList_traverse(BlendShapeList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BlendShapeList_clear(BlendShapeList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BlendShapeList_dealloc(BlendShapeList *self) {
    PyObject_GC_UnTrack(self);
    BlendShapeList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BlendShapeList_Sequence = {
    .sq_length = (lenfunc)&BlendShapeList_len,
    .sq_item = (ssizeargfunc)&BlendShapeList_item,
};

static PyTypeObject BlendShapeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendShapeList",
    .tp_doc = PyDoc_STR("BlendShapeList"),
    .tp_basicsize = sizeof(BlendShapeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BlendShapeList_Sequence,
    .tp_dealloc = (destructor)&BlendShapeList_dealloc,
    .tp_traverse = (traverseproc)&BlendShapeList_traverse,
    .tp_clear = (inquiry)&BlendShapeList_clear,
};

static PyObject *BlendShapeList_from(ufbx_blend_shape_list list, Context *ctx) {
    BlendShapeList *obj = (BlendShapeList*)PyObject_CallObject((PyObject*)&BlendShapeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_cache_deformer_list data;
} CacheDeformerList;

static Py_ssize_t CacheDeformerList_len(CacheDeformerList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *CacheDeformerList_item(CacheDeformerList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int CacheDeformerList_traverse(CacheDeformerList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int CacheDeformerList_clear(CacheDeformerList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void CacheDeformerList_dealloc(CacheDeformerList *self) {
    PyObject_GC_UnTrack(self);
    CacheDeformerList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods CacheDeformerList_Sequence = {
    .sq_length = (lenfunc)&CacheDeformerList_len,
    .sq_item = (ssizeargfunc)&CacheDeformerList_item,
};

static PyTypeObject CacheDeformerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheDeformerList",
    .tp_doc = PyDoc_STR("CacheDeformerList"),
    .tp_basicsize = sizeof(CacheDeformerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &CacheDeformerList_Sequence,
    .tp_dealloc = (destructor)&CacheDeformerList_dealloc,
    .tp_traverse = (traverseproc)&CacheDeformerList_traverse,
    .tp_clear = (inquiry)&CacheDeformerList_clear,
};

static PyObject *CacheDeformerList_from(ufbx_cache_deformer_list list, Context *ctx) {
    CacheDeformerList *obj = (CacheDeformerList*)PyObject_CallObject((PyObject*)&CacheDeformerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_cache_file_list data;
} CacheFileList;

static Py_ssize_t CacheFileList_len(CacheFileList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *CacheFileList_item(CacheFileList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int CacheFileList_traverse(CacheFileList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int CacheFileList_clear(CacheFileList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void CacheFileList_dealloc(CacheFileList *self) {
    PyObject_GC_UnTrack(self);
    CacheFileList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods CacheFileList_Sequence = {
    .sq_length = (lenfunc)&CacheFileList_len,
    .sq_item = (ssizeargfunc)&CacheFileList_item,
};

static PyTypeObject CacheFileList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheFileList",
    .tp_doc = PyDoc_STR("CacheFileList"),
    .tp_basicsize = sizeof(CacheFileList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &CacheFileList_Sequence,
    .tp_dealloc = (destructor)&CacheFileList_dealloc,
    .tp_traverse = (traverseproc)&CacheFileList_traverse,
    .tp_clear = (inquiry)&CacheFileList_clear,
};

static PyObject *CacheFileList_from(ufbx_cache_file_list list, Context *ctx) {
    CacheFileList *obj = (CacheFileList*)PyObject_CallObject((PyObject*)&CacheFileList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_material_list data;
} MaterialList;

static Py_ssize_t MaterialList_len(MaterialList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *MaterialList_item(MaterialList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int MaterialList_traverse(MaterialList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int MaterialList_clear(MaterialList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void MaterialList_dealloc(MaterialList *self) {
    PyObject_GC_UnTrack(self);
    MaterialList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods MaterialList_Sequence = {
    .sq_length = (lenfunc)&MaterialList_len,
    .sq_item = (ssizeargfunc)&MaterialList_item,
};

static PyTypeObject MaterialList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialList",
    .tp_doc = PyDoc_STR("MaterialList"),
    .tp_basicsize = sizeof(MaterialList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &MaterialList_Sequence,
    .tp_dealloc = (destructor)&MaterialList_dealloc,
    .tp_traverse = (traverseproc)&MaterialList_traverse,
    .tp_clear = (inquiry)&MaterialList_clear,
};

static PyObject *MaterialList_from(ufbx_material_list list, Context *ctx) {
    MaterialList *obj = (MaterialList*)PyObject_CallObject((PyObject*)&MaterialList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_texture_list data;
} TextureList;

static Py_ssize_t TextureList_len(TextureList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *TextureList_item(TextureList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int TextureList_traverse(TextureList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int TextureList_clear(TextureList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void TextureList_dealloc(TextureList *self) {
    PyObject_GC_UnTrack(self);
    TextureList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods TextureList_Sequence = {
    .sq_length = (lenfunc)&TextureList_len,
    .sq_item = (ssizeargfunc)&TextureList_item,
};

static PyTypeObject TextureList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.TextureList",
    .tp_doc = PyDoc_STR("TextureList"),
    .tp_basicsize = sizeof(TextureList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &TextureList_Sequence,
    .tp_dealloc = (destructor)&TextureList_dealloc,
    .tp_traverse = (traverseproc)&TextureList_traverse,
    .tp_clear = (inquiry)&TextureList_clear,
};

static PyObject *TextureList_from(ufbx_texture_list list, Context *ctx) {
    TextureList *obj = (TextureList*)PyObject_CallObject((PyObject*)&TextureList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_video_list data;
} VideoList;

static Py_ssize_t VideoList_len(VideoList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *VideoList_item(VideoList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int VideoList_traverse(VideoList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int VideoList_clear(VideoList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void VideoList_dealloc(VideoList *self) {
    PyObject_GC_UnTrack(self);
    VideoList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods VideoList_Sequence = {
    .sq_length = (lenfunc)&VideoList_len,
    .sq_item = (ssizeargfunc)&VideoList_item,
};

static PyTypeObject VideoList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.VideoList",
    .tp_doc = PyDoc_STR("VideoList"),
    .tp_basicsize = sizeof(VideoList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &VideoList_Sequence,
    .tp_dealloc = (destructor)&VideoList_dealloc,
    .tp_traverse = (traverseproc)&VideoList_traverse,
    .tp_clear = (inquiry)&VideoList_clear,
};

static PyObject *VideoList_from(ufbx_video_list list, Context *ctx) {
    VideoList *obj = (VideoList*)PyObject_CallObject((PyObject*)&VideoList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_shader_list data;
} ShaderList;

static Py_ssize_t ShaderList_len(ShaderList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ShaderList_item(ShaderList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int ShaderList_traverse(ShaderList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ShaderList_clear(ShaderList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ShaderList_dealloc(ShaderList *self) {
    PyObject_GC_UnTrack(self);
    ShaderList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ShaderList_Sequence = {
    .sq_length = (lenfunc)&ShaderList_len,
    .sq_item = (ssizeargfunc)&ShaderList_item,
};

static PyTypeObject ShaderList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderList",
    .tp_doc = PyDoc_STR("ShaderList"),
    .tp_basicsize = sizeof(ShaderList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ShaderList_Sequence,
    .tp_dealloc = (destructor)&ShaderList_dealloc,
    .tp_traverse = (traverseproc)&ShaderList_traverse,
    .tp_clear = (inquiry)&ShaderList_clear,
};

static PyObject *ShaderList_from(ufbx_shader_list list, Context *ctx) {
    ShaderList *obj = (ShaderList*)PyObject_CallObject((PyObject*)&ShaderList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_shader_binding_list data;
} ShaderBindingList;

static Py_ssize_t ShaderBindingList_len(ShaderBindingList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ShaderBindingList_item(ShaderBindingList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int ShaderBindingList_traverse(ShaderBindingList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ShaderBindingList_clear(ShaderBindingList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ShaderBindingList_dealloc(ShaderBindingList *self) {
    PyObject_GC_UnTrack(self);
    ShaderBindingList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ShaderBindingList_Sequence = {
    .sq_length = (lenfunc)&ShaderBindingList_len,
    .sq_item = (ssizeargfunc)&ShaderBindingList_item,
};

static PyTypeObject ShaderBindingList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderBindingList",
    .tp_doc = PyDoc_STR("ShaderBindingList"),
    .tp_basicsize = sizeof(ShaderBindingList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ShaderBindingList_Sequence,
    .tp_dealloc = (destructor)&ShaderBindingList_dealloc,
    .tp_traverse = (traverseproc)&ShaderBindingList_traverse,
    .tp_clear = (inquiry)&ShaderBindingList_clear,
};

static PyObject *ShaderBindingList_from(ufbx_shader_binding_list list, Context *ctx) {
    ShaderBindingList *obj = (ShaderBindingList*)PyObject_CallObject((PyObject*)&ShaderBindingList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_anim_stack_list data;
} AnimStackList;

static Py_ssize_t AnimStackList_len(AnimStackList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *AnimStackList_item(AnimStackList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int AnimStackList_traverse(AnimStackList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int AnimStackList_clear(AnimStackList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void AnimStackList_dealloc(AnimStackList *self) {
    PyObject_GC_UnTrack(self);
    AnimStackList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods AnimStackList_Sequence = {
    .sq_length = (lenfunc)&AnimStackList_len,
    .sq_item = (ssizeargfunc)&AnimStackList_item,
};

static PyTypeObject AnimStackList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimStackList",
    .tp_doc = PyDoc_STR("AnimStackList"),
    .tp_basicsize = sizeof(AnimStackList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &AnimStackList_Sequence,
    .tp_dealloc = (destructor)&AnimStackList_dealloc,
    .tp_traverse = (traverseproc)&AnimStackList_traverse,
    .tp_clear = (inquiry)&AnimStackList_clear,
};

static PyObject *AnimStackList_from(ufbx_anim_stack_list list, Context *ctx) {
    AnimStackList *obj = (AnimStackList*)PyObject_CallObject((PyObject*)&AnimStackList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_anim_layer_list data;
} AnimLayerList;

static Py_ssize_t AnimLayerList_len(AnimLayerList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *AnimLayerList_item(AnimLayerList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int AnimLayerList_traverse(AnimLayerList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int AnimLayerList_clear(AnimLayerList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void AnimLayerList_dealloc(AnimLayerList *self) {
    PyObject_GC_UnTrack(self);
    AnimLayerList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods AnimLayerList_Sequence = {
    .sq_length = (lenfunc)&AnimLayerList_len,
    .sq_item = (ssizeargfunc)&AnimLayerList_item,
};

static PyTypeObject AnimLayerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimLayerList",
    .tp_doc = PyDoc_STR("AnimLayerList"),
    .tp_basicsize = sizeof(AnimLayerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &AnimLayerList_Sequence,
    .tp_dealloc = (destructor)&AnimLayerList_dealloc,
    .tp_traverse = (traverseproc)&AnimLayerList_traverse,
    .tp_clear = (inquiry)&AnimLayerList_clear,
};

static PyObject *AnimLayerList_from(ufbx_anim_layer_list list, Context *ctx) {
    AnimLayerList *obj = (AnimLayerList*)PyObject_CallObject((PyObject*)&AnimLayerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_anim_value_list data;
} AnimValueList;

static Py_ssize_t AnimValueList_len(AnimValueList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *AnimValueList_item(AnimValueList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int AnimValueList_traverse(AnimValueList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int AnimValueList_clear(AnimValueList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void AnimValueList_dealloc(AnimValueList *self) {
    PyObject_GC_UnTrack(self);
    AnimValueList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods AnimValueList_Sequence = {
    .sq_length = (lenfunc)&AnimValueList_len,
    .sq_item = (ssizeargfunc)&AnimValueList_item,
};

static PyTypeObject AnimValueList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimValueList",
    .tp_doc = PyDoc_STR("AnimValueList"),
    .tp_basicsize = sizeof(AnimValueList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &AnimValueList_Sequence,
    .tp_dealloc = (destructor)&AnimValueList_dealloc,
    .tp_traverse = (traverseproc)&AnimValueList_traverse,
    .tp_clear = (inquiry)&AnimValueList_clear,
};

static PyObject *AnimValueList_from(ufbx_anim_value_list list, Context *ctx) {
    AnimValueList *obj = (AnimValueList*)PyObject_CallObject((PyObject*)&AnimValueList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_anim_curve_list data;
} AnimCurveList;

static Py_ssize_t AnimCurveList_len(AnimCurveList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *AnimCurveList_item(AnimCurveList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int AnimCurveList_traverse(AnimCurveList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int AnimCurveList_clear(AnimCurveList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void AnimCurveList_dealloc(AnimCurveList *self) {
    PyObject_GC_UnTrack(self);
    AnimCurveList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods AnimCurveList_Sequence = {
    .sq_length = (lenfunc)&AnimCurveList_len,
    .sq_item = (ssizeargfunc)&AnimCurveList_item,
};

static PyTypeObject AnimCurveList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimCurveList",
    .tp_doc = PyDoc_STR("AnimCurveList"),
    .tp_basicsize = sizeof(AnimCurveList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &AnimCurveList_Sequence,
    .tp_dealloc = (destructor)&AnimCurveList_dealloc,
    .tp_traverse = (traverseproc)&AnimCurveList_traverse,
    .tp_clear = (inquiry)&AnimCurveList_clear,
};

static PyObject *AnimCurveList_from(ufbx_anim_curve_list list, Context *ctx) {
    AnimCurveList *obj = (AnimCurveList*)PyObject_CallObject((PyObject*)&AnimCurveList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_display_layer_list data;
} DisplayLayerList;

static Py_ssize_t DisplayLayerList_len(DisplayLayerList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *DisplayLayerList_item(DisplayLayerList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int DisplayLayerList_traverse(DisplayLayerList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int DisplayLayerList_clear(DisplayLayerList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void DisplayLayerList_dealloc(DisplayLayerList *self) {
    PyObject_GC_UnTrack(self);
    DisplayLayerList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods DisplayLayerList_Sequence = {
    .sq_length = (lenfunc)&DisplayLayerList_len,
    .sq_item = (ssizeargfunc)&DisplayLayerList_item,
};

static PyTypeObject DisplayLayerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DisplayLayerList",
    .tp_doc = PyDoc_STR("DisplayLayerList"),
    .tp_basicsize = sizeof(DisplayLayerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &DisplayLayerList_Sequence,
    .tp_dealloc = (destructor)&DisplayLayerList_dealloc,
    .tp_traverse = (traverseproc)&DisplayLayerList_traverse,
    .tp_clear = (inquiry)&DisplayLayerList_clear,
};

static PyObject *DisplayLayerList_from(ufbx_display_layer_list list, Context *ctx) {
    DisplayLayerList *obj = (DisplayLayerList*)PyObject_CallObject((PyObject*)&DisplayLayerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_selection_set_list data;
} SelectionSetList;

static Py_ssize_t SelectionSetList_len(SelectionSetList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *SelectionSetList_item(SelectionSetList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int SelectionSetList_traverse(SelectionSetList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int SelectionSetList_clear(SelectionSetList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void SelectionSetList_dealloc(SelectionSetList *self) {
    PyObject_GC_UnTrack(self);
    SelectionSetList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods SelectionSetList_Sequence = {
    .sq_length = (lenfunc)&SelectionSetList_len,
    .sq_item = (ssizeargfunc)&SelectionSetList_item,
};

static PyTypeObject SelectionSetList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SelectionSetList",
    .tp_doc = PyDoc_STR("SelectionSetList"),
    .tp_basicsize = sizeof(SelectionSetList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &SelectionSetList_Sequence,
    .tp_dealloc = (destructor)&SelectionSetList_dealloc,
    .tp_traverse = (traverseproc)&SelectionSetList_traverse,
    .tp_clear = (inquiry)&SelectionSetList_clear,
};

static PyObject *SelectionSetList_from(ufbx_selection_set_list list, Context *ctx) {
    SelectionSetList *obj = (SelectionSetList*)PyObject_CallObject((PyObject*)&SelectionSetList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_selection_node_list data;
} SelectionNodeList;

static Py_ssize_t SelectionNodeList_len(SelectionNodeList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *SelectionNodeList_item(SelectionNodeList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int SelectionNodeList_traverse(SelectionNodeList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int SelectionNodeList_clear(SelectionNodeList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void SelectionNodeList_dealloc(SelectionNodeList *self) {
    PyObject_GC_UnTrack(self);
    SelectionNodeList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods SelectionNodeList_Sequence = {
    .sq_length = (lenfunc)&SelectionNodeList_len,
    .sq_item = (ssizeargfunc)&SelectionNodeList_item,
};

static PyTypeObject SelectionNodeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SelectionNodeList",
    .tp_doc = PyDoc_STR("SelectionNodeList"),
    .tp_basicsize = sizeof(SelectionNodeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &SelectionNodeList_Sequence,
    .tp_dealloc = (destructor)&SelectionNodeList_dealloc,
    .tp_traverse = (traverseproc)&SelectionNodeList_traverse,
    .tp_clear = (inquiry)&SelectionNodeList_clear,
};

static PyObject *SelectionNodeList_from(ufbx_selection_node_list list, Context *ctx) {
    SelectionNodeList *obj = (SelectionNodeList*)PyObject_CallObject((PyObject*)&SelectionNodeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_character_list data;
} CharacterList;

static Py_ssize_t CharacterList_len(CharacterList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *CharacterList_item(CharacterList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int CharacterList_traverse(CharacterList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int CharacterList_clear(CharacterList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void CharacterList_dealloc(CharacterList *self) {
    PyObject_GC_UnTrack(self);
    CharacterList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods CharacterList_Sequence = {
    .sq_length = (lenfunc)&CharacterList_len,
    .sq_item = (ssizeargfunc)&CharacterList_item,
};

static PyTypeObject CharacterList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CharacterList",
    .tp_doc = PyDoc_STR("CharacterList"),
    .tp_basicsize = sizeof(CharacterList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &CharacterList_Sequence,
    .tp_dealloc = (destructor)&CharacterList_dealloc,
    .tp_traverse = (traverseproc)&CharacterList_traverse,
    .tp_clear = (inquiry)&CharacterList_clear,
};

static PyObject *CharacterList_from(ufbx_character_list list, Context *ctx) {
    CharacterList *obj = (CharacterList*)PyObject_CallObject((PyObject*)&CharacterList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_constraint_list data;
} ConstraintList;

static Py_ssize_t ConstraintList_len(ConstraintList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ConstraintList_item(ConstraintList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int ConstraintList_traverse(ConstraintList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ConstraintList_clear(ConstraintList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ConstraintList_dealloc(ConstraintList *self) {
    PyObject_GC_UnTrack(self);
    ConstraintList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ConstraintList_Sequence = {
    .sq_length = (lenfunc)&ConstraintList_len,
    .sq_item = (ssizeargfunc)&ConstraintList_item,
};

static PyTypeObject ConstraintList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstraintList",
    .tp_doc = PyDoc_STR("ConstraintList"),
    .tp_basicsize = sizeof(ConstraintList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ConstraintList_Sequence,
    .tp_dealloc = (destructor)&ConstraintList_dealloc,
    .tp_traverse = (traverseproc)&ConstraintList_traverse,
    .tp_clear = (inquiry)&ConstraintList_clear,
};

static PyObject *ConstraintList_from(ufbx_constraint_list list, Context *ctx) {
    ConstraintList *obj = (ConstraintList*)PyObject_CallObject((PyObject*)&ConstraintList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_audio_layer_list data;
} AudioLayerList;

static Py_ssize_t AudioLayerList_len(AudioLayerList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *AudioLayerList_item(AudioLayerList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int AudioLayerList_traverse(AudioLayerList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int AudioLayerList_clear(AudioLayerList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void AudioLayerList_dealloc(AudioLayerList *self) {
    PyObject_GC_UnTrack(self);
    AudioLayerList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods AudioLayerList_Sequence = {
    .sq_length = (lenfunc)&AudioLayerList_len,
    .sq_item = (ssizeargfunc)&AudioLayerList_item,
};

static PyTypeObject AudioLayerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AudioLayerList",
    .tp_doc = PyDoc_STR("AudioLayerList"),
    .tp_basicsize = sizeof(AudioLayerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &AudioLayerList_Sequence,
    .tp_dealloc = (destructor)&AudioLayerList_dealloc,
    .tp_traverse = (traverseproc)&AudioLayerList_traverse,
    .tp_clear = (inquiry)&AudioLayerList_clear,
};

static PyObject *AudioLayerList_from(ufbx_audio_layer_list list, Context *ctx) {
    AudioLayerList *obj = (AudioLayerList*)PyObject_CallObject((PyObject*)&AudioLayerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_audio_clip_list data;
} AudioClipList;

static Py_ssize_t AudioClipList_len(AudioClipList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *AudioClipList_item(AudioClipList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int AudioClipList_traverse(AudioClipList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int AudioClipList_clear(AudioClipList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void AudioClipList_dealloc(AudioClipList *self) {
    PyObject_GC_UnTrack(self);
    AudioClipList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods AudioClipList_Sequence = {
    .sq_length = (lenfunc)&AudioClipList_len,
    .sq_item = (ssizeargfunc)&AudioClipList_item,
};

static PyTypeObject AudioClipList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AudioClipList",
    .tp_doc = PyDoc_STR("AudioClipList"),
    .tp_basicsize = sizeof(AudioClipList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &AudioClipList_Sequence,
    .tp_dealloc = (destructor)&AudioClipList_dealloc,
    .tp_traverse = (traverseproc)&AudioClipList_traverse,
    .tp_clear = (inquiry)&AudioClipList_clear,
};

static PyObject *AudioClipList_from(ufbx_audio_clip_list list, Context *ctx) {
    AudioClipList *obj = (AudioClipList*)PyObject_CallObject((PyObject*)&AudioClipList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_pose_list data;
} PoseList;

static Py_ssize_t PoseList_len(PoseList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *PoseList_item(PoseList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int PoseList_traverse(PoseList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int PoseList_clear(PoseList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void PoseList_dealloc(PoseList *self) {
    PyObject_GC_UnTrack(self);
    PoseList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods PoseList_Sequence = {
    .sq_length = (lenfunc)&PoseList_len,
    .sq_item = (ssizeargfunc)&PoseList_item,
};

static PyTypeObject PoseList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.PoseList",
    .tp_doc = PyDoc_STR("PoseList"),
    .tp_basicsize = sizeof(PoseList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &PoseList_Sequence,
    .tp_dealloc = (destructor)&PoseList_dealloc,
    .tp_traverse = (traverseproc)&PoseList_traverse,
    .tp_clear = (inquiry)&PoseList_clear,
};

static PyObject *PoseList_from(ufbx_pose_list list, Context *ctx) {
    PoseList *obj = (PoseList*)PyObject_CallObject((PyObject*)&PoseList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_metadata_object_list data;
} MetadataObjectList;

static Py_ssize_t MetadataObjectList_len(MetadataObjectList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *MetadataObjectList_item(MetadataObjectList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Element_from(self->data.data[index], self->ctx);
}

static int MetadataObjectList_traverse(MetadataObjectList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int MetadataObjectList_clear(MetadataObjectList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void MetadataObjectList_dealloc(MetadataObjectList *self) {
    PyObject_GC_UnTrack(self);
    MetadataObjectList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods MetadataObjectList_Sequence = {
    .sq_length = (lenfunc)&MetadataObjectList_len,
    .sq_item = (ssizeargfunc)&MetadataObjectList_item,
};

static PyTypeObject MetadataObjectList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MetadataObjectList",
    .tp_doc = PyDoc_STR("MetadataObjectList"),
    .tp_basicsize = sizeof(MetadataObjectList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &MetadataObjectList_Sequence,
    .tp_dealloc = (destructor)&MetadataObjectList_dealloc,
    .tp_traverse = (traverseproc)&MetadataObjectList_traverse,
    .tp_clear = (inquiry)&MetadataObjectList_clear,
};

static PyObject *MetadataObjectList_from(ufbx_metadata_object_list list, Context *ctx) {
    MetadataObjectList *obj = (MetadataObjectList*)PyObject_CallObject((PyObject*)&MetadataObjectList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_connection_list data;
} ConnectionList;

static Py_ssize_t ConnectionList_len(ConnectionList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ConnectionList_item(ConnectionList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Connection_from(&self->data.data[index], self->ctx);
}

static int ConnectionList_traverse(ConnectionList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ConnectionList_clear(ConnectionList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ConnectionList_dealloc(ConnectionList *self) {
    PyObject_GC_UnTrack(self);
    ConnectionList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ConnectionList_Sequence = {
    .sq_length = (lenfunc)&ConnectionList_len,
    .sq_item = (ssizeargfunc)&ConnectionList_item,
};

static PyTypeObject ConnectionList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConnectionList",
    .tp_doc = PyDoc_STR("ConnectionList"),
    .tp_basicsize = sizeof(ConnectionList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ConnectionList_Sequence,
    .tp_dealloc = (destructor)&ConnectionList_dealloc,
    .tp_traverse = (traverseproc)&ConnectionList_traverse,
    .tp_clear = (inquiry)&ConnectionList_clear,
};

static PyObject *ConnectionList_from(ufbx_connection_list list, Context *ctx) {
    ConnectionList *obj = (ConnectionList*)PyObject_CallObject((PyObject*)&ConnectionList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_uv_set_list data;
} UvSetList;

static Py_ssize_t UvSetList_len(UvSetList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *UvSetList_item(UvSetList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return UvSet_from(&self->data.data[index], self->ctx);
}

static int UvSetList_traverse(UvSetList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int UvSetList_clear(UvSetList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void UvSetList_dealloc(UvSetList *self) {
    PyObject_GC_UnTrack(self);
    UvSetList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods UvSetList_Sequence = {
    .sq_length = (lenfunc)&UvSetList_len,
    .sq_item = (ssizeargfunc)&UvSetList_item,
};

static PyTypeObject UvSetList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.UvSetList",
    .tp_doc = PyDoc_STR("UvSetList"),
    .tp_basicsize = sizeof(UvSetList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &UvSetList_Sequence,
    .tp_dealloc = (destructor)&UvSetList_dealloc,
    .tp_traverse = (traverseproc)&UvSetList_traverse,
    .tp_clear = (inquiry)&UvSetList_clear,
};

static PyObject *UvSetList_from(ufbx_uv_set_list list, Context *ctx) {
    UvSetList *obj = (UvSetList*)PyObject_CallObject((PyObject*)&UvSetList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_color_set_list data;
} ColorSetList;

static Py_ssize_t ColorSetList_len(ColorSetList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ColorSetList_item(ColorSetList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return ColorSet_from(&self->data.data[index], self->ctx);
}

static int ColorSetList_traverse(ColorSetList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ColorSetList_clear(ColorSetList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ColorSetList_dealloc(ColorSetList *self) {
    PyObject_GC_UnTrack(self);
    ColorSetList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ColorSetList_Sequence = {
    .sq_length = (lenfunc)&ColorSetList_len,
    .sq_item = (ssizeargfunc)&ColorSetList_item,
};

static PyTypeObject ColorSetList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ColorSetList",
    .tp_doc = PyDoc_STR("ColorSetList"),
    .tp_basicsize = sizeof(ColorSetList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ColorSetList_Sequence,
    .tp_dealloc = (destructor)&ColorSetList_dealloc,
    .tp_traverse = (traverseproc)&ColorSetList_traverse,
    .tp_clear = (inquiry)&ColorSetList_clear,
};

static PyObject *ColorSetList_from(ufbx_color_set_list list, Context *ctx) {
    ColorSetList *obj = (ColorSetList*)PyObject_CallObject((PyObject*)&ColorSetList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_edge_list data;
} EdgeList;

static Py_ssize_t EdgeList_len(EdgeList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *EdgeList_item(EdgeList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Edge_from(&self->data.data[index]);
}

static int EdgeList_traverse(EdgeList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int EdgeList_clear(EdgeList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void EdgeList_dealloc(EdgeList *self) {
    PyObject_GC_UnTrack(self);
    EdgeList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods EdgeList_Sequence = {
    .sq_length = (lenfunc)&EdgeList_len,
    .sq_item = (ssizeargfunc)&EdgeList_item,
};

static PyTypeObject EdgeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.EdgeList",
    .tp_doc = PyDoc_STR("EdgeList"),
    .tp_basicsize = sizeof(EdgeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &EdgeList_Sequence,
    .tp_dealloc = (destructor)&EdgeList_dealloc,
    .tp_traverse = (traverseproc)&EdgeList_traverse,
    .tp_clear = (inquiry)&EdgeList_clear,
};

static PyObject *EdgeList_from(ufbx_edge_list list, Context *ctx) {
    EdgeList *obj = (EdgeList*)PyObject_CallObject((PyObject*)&EdgeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_face_list data;
} FaceList;

static Py_ssize_t FaceList_len(FaceList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *FaceList_item(FaceList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Face_from(&self->data.data[index]);
}

static int FaceList_traverse(FaceList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int FaceList_clear(FaceList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void FaceList_dealloc(FaceList *self) {
    PyObject_GC_UnTrack(self);
    FaceList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods FaceList_Sequence = {
    .sq_length = (lenfunc)&FaceList_len,
    .sq_item = (ssizeargfunc)&FaceList_item,
};

static PyTypeObject FaceList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.FaceList",
    .tp_doc = PyDoc_STR("FaceList"),
    .tp_basicsize = sizeof(FaceList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &FaceList_Sequence,
    .tp_dealloc = (destructor)&FaceList_dealloc,
    .tp_traverse = (traverseproc)&FaceList_traverse,
    .tp_clear = (inquiry)&FaceList_clear,
};

static PyObject *FaceList_from(ufbx_face_list list, Context *ctx) {
    FaceList *obj = (FaceList*)PyObject_CallObject((PyObject*)&FaceList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_mesh_part_list data;
} MeshPartList;

static Py_ssize_t MeshPartList_len(MeshPartList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *MeshPartList_item(MeshPartList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return MeshPart_from(&self->data.data[index], self->ctx);
}

static int MeshPartList_traverse(MeshPartList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int MeshPartList_clear(MeshPartList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void MeshPartList_dealloc(MeshPartList *self) {
    PyObject_GC_UnTrack(self);
    MeshPartList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods MeshPartList_Sequence = {
    .sq_length = (lenfunc)&MeshPartList_len,
    .sq_item = (ssizeargfunc)&MeshPartList_item,
};

static PyTypeObject MeshPartList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MeshPartList",
    .tp_doc = PyDoc_STR("MeshPartList"),
    .tp_basicsize = sizeof(MeshPartList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &MeshPartList_Sequence,
    .tp_dealloc = (destructor)&MeshPartList_dealloc,
    .tp_traverse = (traverseproc)&MeshPartList_traverse,
    .tp_clear = (inquiry)&MeshPartList_clear,
};

static PyObject *MeshPartList_from(ufbx_mesh_part_list list, Context *ctx) {
    MeshPartList *obj = (MeshPartList*)PyObject_CallObject((PyObject*)&MeshPartList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_face_group_list data;
} FaceGroupList;

static Py_ssize_t FaceGroupList_len(FaceGroupList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *FaceGroupList_item(FaceGroupList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return FaceGroup_from(&self->data.data[index], self->ctx);
}

static int FaceGroupList_traverse(FaceGroupList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int FaceGroupList_clear(FaceGroupList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void FaceGroupList_dealloc(FaceGroupList *self) {
    PyObject_GC_UnTrack(self);
    FaceGroupList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods FaceGroupList_Sequence = {
    .sq_length = (lenfunc)&FaceGroupList_len,
    .sq_item = (ssizeargfunc)&FaceGroupList_item,
};

static PyTypeObject FaceGroupList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.FaceGroupList",
    .tp_doc = PyDoc_STR("FaceGroupList"),
    .tp_basicsize = sizeof(FaceGroupList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &FaceGroupList_Sequence,
    .tp_dealloc = (destructor)&FaceGroupList_dealloc,
    .tp_traverse = (traverseproc)&FaceGroupList_traverse,
    .tp_clear = (inquiry)&FaceGroupList_clear,
};

static PyObject *FaceGroupList_from(ufbx_face_group_list list, Context *ctx) {
    FaceGroupList *obj = (FaceGroupList*)PyObject_CallObject((PyObject*)&FaceGroupList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_subdivision_weight_range_list data;
} SubdivisionWeightRangeList;

static Py_ssize_t SubdivisionWeightRangeList_len(SubdivisionWeightRangeList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *SubdivisionWeightRangeList_item(SubdivisionWeightRangeList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return SubdivisionWeightRange_from(&self->data.data[index], self->ctx);
}

static int SubdivisionWeightRangeList_traverse(SubdivisionWeightRangeList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int SubdivisionWeightRangeList_clear(SubdivisionWeightRangeList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void SubdivisionWeightRangeList_dealloc(SubdivisionWeightRangeList *self) {
    PyObject_GC_UnTrack(self);
    SubdivisionWeightRangeList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods SubdivisionWeightRangeList_Sequence = {
    .sq_length = (lenfunc)&SubdivisionWeightRangeList_len,
    .sq_item = (ssizeargfunc)&SubdivisionWeightRangeList_item,
};

static PyTypeObject SubdivisionWeightRangeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SubdivisionWeightRangeList",
    .tp_doc = PyDoc_STR("SubdivisionWeightRangeList"),
    .tp_basicsize = sizeof(SubdivisionWeightRangeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &SubdivisionWeightRangeList_Sequence,
    .tp_dealloc = (destructor)&SubdivisionWeightRangeList_dealloc,
    .tp_traverse = (traverseproc)&SubdivisionWeightRangeList_traverse,
    .tp_clear = (inquiry)&SubdivisionWeightRangeList_clear,
};

static PyObject *SubdivisionWeightRangeList_from(ufbx_subdivision_weight_range_list list, Context *ctx) {
    SubdivisionWeightRangeList *obj = (SubdivisionWeightRangeList*)PyObject_CallObject((PyObject*)&SubdivisionWeightRangeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_subdivision_weight_list data;
} SubdivisionWeightList;

static Py_ssize_t SubdivisionWeightList_len(SubdivisionWeightList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *SubdivisionWeightList_item(SubdivisionWeightList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return SubdivisionWeight_from(&self->data.data[index], self->ctx);
}

static int SubdivisionWeightList_traverse(SubdivisionWeightList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int SubdivisionWeightList_clear(SubdivisionWeightList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void SubdivisionWeightList_dealloc(SubdivisionWeightList *self) {
    PyObject_GC_UnTrack(self);
    SubdivisionWeightList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods SubdivisionWeightList_Sequence = {
    .sq_length = (lenfunc)&SubdivisionWeightList_len,
    .sq_item = (ssizeargfunc)&SubdivisionWeightList_item,
};

static PyTypeObject SubdivisionWeightList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SubdivisionWeightList",
    .tp_doc = PyDoc_STR("SubdivisionWeightList"),
    .tp_basicsize = sizeof(SubdivisionWeightList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &SubdivisionWeightList_Sequence,
    .tp_dealloc = (destructor)&SubdivisionWeightList_dealloc,
    .tp_traverse = (traverseproc)&SubdivisionWeightList_traverse,
    .tp_clear = (inquiry)&SubdivisionWeightList_clear,
};

static PyObject *SubdivisionWeightList_from(ufbx_subdivision_weight_list list, Context *ctx) {
    SubdivisionWeightList *obj = (SubdivisionWeightList*)PyObject_CallObject((PyObject*)&SubdivisionWeightList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_line_segment_list data;
} LineSegmentList;

static Py_ssize_t LineSegmentList_len(LineSegmentList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *LineSegmentList_item(LineSegmentList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return LineSegment_from(&self->data.data[index], self->ctx);
}

static int LineSegmentList_traverse(LineSegmentList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int LineSegmentList_clear(LineSegmentList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void LineSegmentList_dealloc(LineSegmentList *self) {
    PyObject_GC_UnTrack(self);
    LineSegmentList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods LineSegmentList_Sequence = {
    .sq_length = (lenfunc)&LineSegmentList_len,
    .sq_item = (ssizeargfunc)&LineSegmentList_item,
};

static PyTypeObject LineSegmentList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LineSegmentList",
    .tp_doc = PyDoc_STR("LineSegmentList"),
    .tp_basicsize = sizeof(LineSegmentList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &LineSegmentList_Sequence,
    .tp_dealloc = (destructor)&LineSegmentList_dealloc,
    .tp_traverse = (traverseproc)&LineSegmentList_traverse,
    .tp_clear = (inquiry)&LineSegmentList_clear,
};

static PyObject *LineSegmentList_from(ufbx_line_segment_list list, Context *ctx) {
    LineSegmentList *obj = (LineSegmentList*)PyObject_CallObject((PyObject*)&LineSegmentList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_lod_level_list data;
} LodLevelList;

static Py_ssize_t LodLevelList_len(LodLevelList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *LodLevelList_item(LodLevelList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return LodLevel_from(&self->data.data[index]);
}

static int LodLevelList_traverse(LodLevelList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int LodLevelList_clear(LodLevelList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void LodLevelList_dealloc(LodLevelList *self) {
    PyObject_GC_UnTrack(self);
    LodLevelList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods LodLevelList_Sequence = {
    .sq_length = (lenfunc)&LodLevelList_len,
    .sq_item = (ssizeargfunc)&LodLevelList_item,
};

static PyTypeObject LodLevelList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.LodLevelList",
    .tp_doc = PyDoc_STR("LodLevelList"),
    .tp_basicsize = sizeof(LodLevelList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &LodLevelList_Sequence,
    .tp_dealloc = (destructor)&LodLevelList_dealloc,
    .tp_traverse = (traverseproc)&LodLevelList_traverse,
    .tp_clear = (inquiry)&LodLevelList_clear,
};

static PyObject *LodLevelList_from(ufbx_lod_level_list list, Context *ctx) {
    LodLevelList *obj = (LodLevelList*)PyObject_CallObject((PyObject*)&LodLevelList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_skin_vertex_list data;
} SkinVertexList;

static Py_ssize_t SkinVertexList_len(SkinVertexList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *SkinVertexList_item(SkinVertexList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return SkinVertex_from(&self->data.data[index]);
}

static int SkinVertexList_traverse(SkinVertexList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int SkinVertexList_clear(SkinVertexList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void SkinVertexList_dealloc(SkinVertexList *self) {
    PyObject_GC_UnTrack(self);
    SkinVertexList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods SkinVertexList_Sequence = {
    .sq_length = (lenfunc)&SkinVertexList_len,
    .sq_item = (ssizeargfunc)&SkinVertexList_item,
};

static PyTypeObject SkinVertexList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SkinVertexList",
    .tp_doc = PyDoc_STR("SkinVertexList"),
    .tp_basicsize = sizeof(SkinVertexList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &SkinVertexList_Sequence,
    .tp_dealloc = (destructor)&SkinVertexList_dealloc,
    .tp_traverse = (traverseproc)&SkinVertexList_traverse,
    .tp_clear = (inquiry)&SkinVertexList_clear,
};

static PyObject *SkinVertexList_from(ufbx_skin_vertex_list list, Context *ctx) {
    SkinVertexList *obj = (SkinVertexList*)PyObject_CallObject((PyObject*)&SkinVertexList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_skin_weight_list data;
} SkinWeightList;

static Py_ssize_t SkinWeightList_len(SkinWeightList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *SkinWeightList_item(SkinWeightList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return SkinWeight_from(&self->data.data[index]);
}

static int SkinWeightList_traverse(SkinWeightList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int SkinWeightList_clear(SkinWeightList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void SkinWeightList_dealloc(SkinWeightList *self) {
    PyObject_GC_UnTrack(self);
    SkinWeightList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods SkinWeightList_Sequence = {
    .sq_length = (lenfunc)&SkinWeightList_len,
    .sq_item = (ssizeargfunc)&SkinWeightList_item,
};

static PyTypeObject SkinWeightList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SkinWeightList",
    .tp_doc = PyDoc_STR("SkinWeightList"),
    .tp_basicsize = sizeof(SkinWeightList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &SkinWeightList_Sequence,
    .tp_dealloc = (destructor)&SkinWeightList_dealloc,
    .tp_traverse = (traverseproc)&SkinWeightList_traverse,
    .tp_clear = (inquiry)&SkinWeightList_clear,
};

static PyObject *SkinWeightList_from(ufbx_skin_weight_list list, Context *ctx) {
    SkinWeightList *obj = (SkinWeightList*)PyObject_CallObject((PyObject*)&SkinWeightList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_blend_keyframe_list data;
} BlendKeyframeList;

static Py_ssize_t BlendKeyframeList_len(BlendKeyframeList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BlendKeyframeList_item(BlendKeyframeList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return BlendKeyframe_from(&self->data.data[index], self->ctx);
}

static int BlendKeyframeList_traverse(BlendKeyframeList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BlendKeyframeList_clear(BlendKeyframeList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BlendKeyframeList_dealloc(BlendKeyframeList *self) {
    PyObject_GC_UnTrack(self);
    BlendKeyframeList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BlendKeyframeList_Sequence = {
    .sq_length = (lenfunc)&BlendKeyframeList_len,
    .sq_item = (ssizeargfunc)&BlendKeyframeList_item,
};

static PyTypeObject BlendKeyframeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendKeyframeList",
    .tp_doc = PyDoc_STR("BlendKeyframeList"),
    .tp_basicsize = sizeof(BlendKeyframeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BlendKeyframeList_Sequence,
    .tp_dealloc = (destructor)&BlendKeyframeList_dealloc,
    .tp_traverse = (traverseproc)&BlendKeyframeList_traverse,
    .tp_clear = (inquiry)&BlendKeyframeList_clear,
};

static PyObject *BlendKeyframeList_from(ufbx_blend_keyframe_list list, Context *ctx) {
    BlendKeyframeList *obj = (BlendKeyframeList*)PyObject_CallObject((PyObject*)&BlendKeyframeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_cache_frame_list data;
} CacheFrameList;

static Py_ssize_t CacheFrameList_len(CacheFrameList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *CacheFrameList_item(CacheFrameList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return CacheFrame_from(&self->data.data[index], self->ctx);
}

static int CacheFrameList_traverse(CacheFrameList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int CacheFrameList_clear(CacheFrameList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void CacheFrameList_dealloc(CacheFrameList *self) {
    PyObject_GC_UnTrack(self);
    CacheFrameList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods CacheFrameList_Sequence = {
    .sq_length = (lenfunc)&CacheFrameList_len,
    .sq_item = (ssizeargfunc)&CacheFrameList_item,
};

static PyTypeObject CacheFrameList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheFrameList",
    .tp_doc = PyDoc_STR("CacheFrameList"),
    .tp_basicsize = sizeof(CacheFrameList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &CacheFrameList_Sequence,
    .tp_dealloc = (destructor)&CacheFrameList_dealloc,
    .tp_traverse = (traverseproc)&CacheFrameList_traverse,
    .tp_clear = (inquiry)&CacheFrameList_clear,
};

static PyObject *CacheFrameList_from(ufbx_cache_frame_list list, Context *ctx) {
    CacheFrameList *obj = (CacheFrameList*)PyObject_CallObject((PyObject*)&CacheFrameList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_cache_channel_list data;
} CacheChannelList;

static Py_ssize_t CacheChannelList_len(CacheChannelList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *CacheChannelList_item(CacheChannelList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return CacheChannel_from(&self->data.data[index], self->ctx);
}

static int CacheChannelList_traverse(CacheChannelList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int CacheChannelList_clear(CacheChannelList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void CacheChannelList_dealloc(CacheChannelList *self) {
    PyObject_GC_UnTrack(self);
    CacheChannelList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods CacheChannelList_Sequence = {
    .sq_length = (lenfunc)&CacheChannelList_len,
    .sq_item = (ssizeargfunc)&CacheChannelList_item,
};

static PyTypeObject CacheChannelList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CacheChannelList",
    .tp_doc = PyDoc_STR("CacheChannelList"),
    .tp_basicsize = sizeof(CacheChannelList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &CacheChannelList_Sequence,
    .tp_dealloc = (destructor)&CacheChannelList_dealloc,
    .tp_traverse = (traverseproc)&CacheChannelList_traverse,
    .tp_clear = (inquiry)&CacheChannelList_clear,
};

static PyObject *CacheChannelList_from(ufbx_cache_channel_list list, Context *ctx) {
    CacheChannelList *obj = (CacheChannelList*)PyObject_CallObject((PyObject*)&CacheChannelList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_material_texture_list data;
} MaterialTextureList;

static Py_ssize_t MaterialTextureList_len(MaterialTextureList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *MaterialTextureList_item(MaterialTextureList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return MaterialTexture_from(&self->data.data[index], self->ctx);
}

static int MaterialTextureList_traverse(MaterialTextureList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int MaterialTextureList_clear(MaterialTextureList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void MaterialTextureList_dealloc(MaterialTextureList *self) {
    PyObject_GC_UnTrack(self);
    MaterialTextureList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods MaterialTextureList_Sequence = {
    .sq_length = (lenfunc)&MaterialTextureList_len,
    .sq_item = (ssizeargfunc)&MaterialTextureList_item,
};

static PyTypeObject MaterialTextureList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialTextureList",
    .tp_doc = PyDoc_STR("MaterialTextureList"),
    .tp_basicsize = sizeof(MaterialTextureList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &MaterialTextureList_Sequence,
    .tp_dealloc = (destructor)&MaterialTextureList_dealloc,
    .tp_traverse = (traverseproc)&MaterialTextureList_traverse,
    .tp_clear = (inquiry)&MaterialTextureList_clear,
};

static PyObject *MaterialTextureList_from(ufbx_material_texture_list list, Context *ctx) {
    MaterialTextureList *obj = (MaterialTextureList*)PyObject_CallObject((PyObject*)&MaterialTextureList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_texture_layer_list data;
} TextureLayerList;

static Py_ssize_t TextureLayerList_len(TextureLayerList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *TextureLayerList_item(TextureLayerList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return TextureLayer_from(&self->data.data[index], self->ctx);
}

static int TextureLayerList_traverse(TextureLayerList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int TextureLayerList_clear(TextureLayerList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void TextureLayerList_dealloc(TextureLayerList *self) {
    PyObject_GC_UnTrack(self);
    TextureLayerList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods TextureLayerList_Sequence = {
    .sq_length = (lenfunc)&TextureLayerList_len,
    .sq_item = (ssizeargfunc)&TextureLayerList_item,
};

static PyTypeObject TextureLayerList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.TextureLayerList",
    .tp_doc = PyDoc_STR("TextureLayerList"),
    .tp_basicsize = sizeof(TextureLayerList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &TextureLayerList_Sequence,
    .tp_dealloc = (destructor)&TextureLayerList_dealloc,
    .tp_traverse = (traverseproc)&TextureLayerList_traverse,
    .tp_clear = (inquiry)&TextureLayerList_clear,
};

static PyObject *TextureLayerList_from(ufbx_texture_layer_list list, Context *ctx) {
    TextureLayerList *obj = (TextureLayerList*)PyObject_CallObject((PyObject*)&TextureLayerList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_shader_texture_input_list data;
} ShaderTextureInputList;

static Py_ssize_t ShaderTextureInputList_len(ShaderTextureInputList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ShaderTextureInputList_item(ShaderTextureInputList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return ShaderTextureInput_from(&self->data.data[index], self->ctx);
}

static int ShaderTextureInputList_traverse(ShaderTextureInputList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ShaderTextureInputList_clear(ShaderTextureInputList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ShaderTextureInputList_dealloc(ShaderTextureInputList *self) {
    PyObject_GC_UnTrack(self);
    ShaderTextureInputList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ShaderTextureInputList_Sequence = {
    .sq_length = (lenfunc)&ShaderTextureInputList_len,
    .sq_item = (ssizeargfunc)&ShaderTextureInputList_item,
};

static PyTypeObject ShaderTextureInputList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderTextureInputList",
    .tp_doc = PyDoc_STR("ShaderTextureInputList"),
    .tp_basicsize = sizeof(ShaderTextureInputList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ShaderTextureInputList_Sequence,
    .tp_dealloc = (destructor)&ShaderTextureInputList_dealloc,
    .tp_traverse = (traverseproc)&ShaderTextureInputList_traverse,
    .tp_clear = (inquiry)&ShaderTextureInputList_clear,
};

static PyObject *ShaderTextureInputList_from(ufbx_shader_texture_input_list list, Context *ctx) {
    ShaderTextureInputList *obj = (ShaderTextureInputList*)PyObject_CallObject((PyObject*)&ShaderTextureInputList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_texture_file_list data;
} TextureFileList;

static Py_ssize_t TextureFileList_len(TextureFileList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *TextureFileList_item(TextureFileList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return TextureFile_from(&self->data.data[index], self->ctx);
}

static int TextureFileList_traverse(TextureFileList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int TextureFileList_clear(TextureFileList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void TextureFileList_dealloc(TextureFileList *self) {
    PyObject_GC_UnTrack(self);
    TextureFileList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods TextureFileList_Sequence = {
    .sq_length = (lenfunc)&TextureFileList_len,
    .sq_item = (ssizeargfunc)&TextureFileList_item,
};

static PyTypeObject TextureFileList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.TextureFileList",
    .tp_doc = PyDoc_STR("TextureFileList"),
    .tp_basicsize = sizeof(TextureFileList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &TextureFileList_Sequence,
    .tp_dealloc = (destructor)&TextureFileList_dealloc,
    .tp_traverse = (traverseproc)&TextureFileList_traverse,
    .tp_clear = (inquiry)&TextureFileList_clear,
};

static PyObject *TextureFileList_from(ufbx_texture_file_list list, Context *ctx) {
    TextureFileList *obj = (TextureFileList*)PyObject_CallObject((PyObject*)&TextureFileList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_shader_prop_binding_list data;
} ShaderPropBindingList;

static Py_ssize_t ShaderPropBindingList_len(ShaderPropBindingList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ShaderPropBindingList_item(ShaderPropBindingList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return ShaderPropBinding_from(&self->data.data[index], self->ctx);
}

static int ShaderPropBindingList_traverse(ShaderPropBindingList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ShaderPropBindingList_clear(ShaderPropBindingList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ShaderPropBindingList_dealloc(ShaderPropBindingList *self) {
    PyObject_GC_UnTrack(self);
    ShaderPropBindingList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ShaderPropBindingList_Sequence = {
    .sq_length = (lenfunc)&ShaderPropBindingList_len,
    .sq_item = (ssizeargfunc)&ShaderPropBindingList_item,
};

static PyTypeObject ShaderPropBindingList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderPropBindingList",
    .tp_doc = PyDoc_STR("ShaderPropBindingList"),
    .tp_basicsize = sizeof(ShaderPropBindingList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ShaderPropBindingList_Sequence,
    .tp_dealloc = (destructor)&ShaderPropBindingList_dealloc,
    .tp_traverse = (traverseproc)&ShaderPropBindingList_traverse,
    .tp_clear = (inquiry)&ShaderPropBindingList_clear,
};

static PyObject *ShaderPropBindingList_from(ufbx_shader_prop_binding_list list, Context *ctx) {
    ShaderPropBindingList *obj = (ShaderPropBindingList*)PyObject_CallObject((PyObject*)&ShaderPropBindingList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_prop_override_list data;
} PropOverrideList;

static Py_ssize_t PropOverrideList_len(PropOverrideList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *PropOverrideList_item(PropOverrideList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return PropOverride_from(&self->data.data[index], self->ctx);
}

static int PropOverrideList_traverse(PropOverrideList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int PropOverrideList_clear(PropOverrideList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void PropOverrideList_dealloc(PropOverrideList *self) {
    PyObject_GC_UnTrack(self);
    PropOverrideList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods PropOverrideList_Sequence = {
    .sq_length = (lenfunc)&PropOverrideList_len,
    .sq_item = (ssizeargfunc)&PropOverrideList_item,
};

static PyTypeObject PropOverrideList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.PropOverrideList",
    .tp_doc = PyDoc_STR("PropOverrideList"),
    .tp_basicsize = sizeof(PropOverrideList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &PropOverrideList_Sequence,
    .tp_dealloc = (destructor)&PropOverrideList_dealloc,
    .tp_traverse = (traverseproc)&PropOverrideList_traverse,
    .tp_clear = (inquiry)&PropOverrideList_clear,
};

static PyObject *PropOverrideList_from(ufbx_prop_override_list list, Context *ctx) {
    PropOverrideList *obj = (PropOverrideList*)PyObject_CallObject((PyObject*)&PropOverrideList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_transform_override_list data;
} TransformOverrideList;

static Py_ssize_t TransformOverrideList_len(TransformOverrideList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *TransformOverrideList_item(TransformOverrideList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return TransformOverride_from(&self->data.data[index]);
}

static int TransformOverrideList_traverse(TransformOverrideList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int TransformOverrideList_clear(TransformOverrideList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void TransformOverrideList_dealloc(TransformOverrideList *self) {
    PyObject_GC_UnTrack(self);
    TransformOverrideList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods TransformOverrideList_Sequence = {
    .sq_length = (lenfunc)&TransformOverrideList_len,
    .sq_item = (ssizeargfunc)&TransformOverrideList_item,
};

static PyTypeObject TransformOverrideList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.TransformOverrideList",
    .tp_doc = PyDoc_STR("TransformOverrideList"),
    .tp_basicsize = sizeof(TransformOverrideList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &TransformOverrideList_Sequence,
    .tp_dealloc = (destructor)&TransformOverrideList_dealloc,
    .tp_traverse = (traverseproc)&TransformOverrideList_traverse,
    .tp_clear = (inquiry)&TransformOverrideList_clear,
};

static PyObject *TransformOverrideList_from(ufbx_transform_override_list list, Context *ctx) {
    TransformOverrideList *obj = (TransformOverrideList*)PyObject_CallObject((PyObject*)&TransformOverrideList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_anim_prop_list data;
} AnimPropList;

static Py_ssize_t AnimPropList_len(AnimPropList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *AnimPropList_item(AnimPropList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return AnimProp_from(&self->data.data[index], self->ctx);
}

static int AnimPropList_traverse(AnimPropList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int AnimPropList_clear(AnimPropList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void AnimPropList_dealloc(AnimPropList *self) {
    PyObject_GC_UnTrack(self);
    AnimPropList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods AnimPropList_Sequence = {
    .sq_length = (lenfunc)&AnimPropList_len,
    .sq_item = (ssizeargfunc)&AnimPropList_item,
};

static PyTypeObject AnimPropList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimPropList",
    .tp_doc = PyDoc_STR("AnimPropList"),
    .tp_basicsize = sizeof(AnimPropList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &AnimPropList_Sequence,
    .tp_dealloc = (destructor)&AnimPropList_dealloc,
    .tp_traverse = (traverseproc)&AnimPropList_traverse,
    .tp_clear = (inquiry)&AnimPropList_clear,
};

static PyObject *AnimPropList_from(ufbx_anim_prop_list list, Context *ctx) {
    AnimPropList *obj = (AnimPropList*)PyObject_CallObject((PyObject*)&AnimPropList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_keyframe_list data;
} KeyframeList;

static Py_ssize_t KeyframeList_len(KeyframeList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *KeyframeList_item(KeyframeList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Keyframe_from(&self->data.data[index]);
}

static int KeyframeList_traverse(KeyframeList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int KeyframeList_clear(KeyframeList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void KeyframeList_dealloc(KeyframeList *self) {
    PyObject_GC_UnTrack(self);
    KeyframeList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods KeyframeList_Sequence = {
    .sq_length = (lenfunc)&KeyframeList_len,
    .sq_item = (ssizeargfunc)&KeyframeList_item,
};

static PyTypeObject KeyframeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.KeyframeList",
    .tp_doc = PyDoc_STR("KeyframeList"),
    .tp_basicsize = sizeof(KeyframeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &KeyframeList_Sequence,
    .tp_dealloc = (destructor)&KeyframeList_dealloc,
    .tp_traverse = (traverseproc)&KeyframeList_traverse,
    .tp_clear = (inquiry)&KeyframeList_clear,
};

static PyObject *KeyframeList_from(ufbx_keyframe_list list, Context *ctx) {
    KeyframeList *obj = (KeyframeList*)PyObject_CallObject((PyObject*)&KeyframeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_constraint_target_list data;
} ConstraintTargetList;

static Py_ssize_t ConstraintTargetList_len(ConstraintTargetList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ConstraintTargetList_item(ConstraintTargetList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return ConstraintTarget_from(&self->data.data[index], self->ctx);
}

static int ConstraintTargetList_traverse(ConstraintTargetList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ConstraintTargetList_clear(ConstraintTargetList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ConstraintTargetList_dealloc(ConstraintTargetList *self) {
    PyObject_GC_UnTrack(self);
    ConstraintTargetList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ConstraintTargetList_Sequence = {
    .sq_length = (lenfunc)&ConstraintTargetList_len,
    .sq_item = (ssizeargfunc)&ConstraintTargetList_item,
};

static PyTypeObject ConstraintTargetList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstraintTargetList",
    .tp_doc = PyDoc_STR("ConstraintTargetList"),
    .tp_basicsize = sizeof(ConstraintTargetList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ConstraintTargetList_Sequence,
    .tp_dealloc = (destructor)&ConstraintTargetList_dealloc,
    .tp_traverse = (traverseproc)&ConstraintTargetList_traverse,
    .tp_clear = (inquiry)&ConstraintTargetList_clear,
};

static PyObject *ConstraintTargetList_from(ufbx_constraint_target_list list, Context *ctx) {
    ConstraintTargetList *obj = (ConstraintTargetList*)PyObject_CallObject((PyObject*)&ConstraintTargetList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_bone_pose_list data;
} BonePoseList;

static Py_ssize_t BonePoseList_len(BonePoseList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BonePoseList_item(BonePoseList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return BonePose_from(&self->data.data[index], self->ctx);
}

static int BonePoseList_traverse(BonePoseList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BonePoseList_clear(BonePoseList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BonePoseList_dealloc(BonePoseList *self) {
    PyObject_GC_UnTrack(self);
    BonePoseList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BonePoseList_Sequence = {
    .sq_length = (lenfunc)&BonePoseList_len,
    .sq_item = (ssizeargfunc)&BonePoseList_item,
};

static PyTypeObject BonePoseList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BonePoseList",
    .tp_doc = PyDoc_STR("BonePoseList"),
    .tp_basicsize = sizeof(BonePoseList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BonePoseList_Sequence,
    .tp_dealloc = (destructor)&BonePoseList_dealloc,
    .tp_traverse = (traverseproc)&BonePoseList_traverse,
    .tp_clear = (inquiry)&BonePoseList_clear,
};

static PyObject *BonePoseList_from(ufbx_bone_pose_list list, Context *ctx) {
    BonePoseList *obj = (BonePoseList*)PyObject_CallObject((PyObject*)&BonePoseList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_name_element_list data;
} NameElementList;

static Py_ssize_t NameElementList_len(NameElementList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *NameElementList_item(NameElementList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return NameElement_from(&self->data.data[index], self->ctx);
}

static int NameElementList_traverse(NameElementList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int NameElementList_clear(NameElementList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void NameElementList_dealloc(NameElementList *self) {
    PyObject_GC_UnTrack(self);
    NameElementList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods NameElementList_Sequence = {
    .sq_length = (lenfunc)&NameElementList_len,
    .sq_item = (ssizeargfunc)&NameElementList_item,
};

static PyTypeObject NameElementList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NameElementList",
    .tp_doc = PyDoc_STR("NameElementList"),
    .tp_basicsize = sizeof(NameElementList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &NameElementList_Sequence,
    .tp_dealloc = (destructor)&NameElementList_dealloc,
    .tp_traverse = (traverseproc)&NameElementList_traverse,
    .tp_clear = (inquiry)&NameElementList_clear,
};

static PyObject *NameElementList_from(ufbx_name_element_list list, Context *ctx) {
    NameElementList *obj = (NameElementList*)PyObject_CallObject((PyObject*)&NameElementList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_warning_list data;
} WarningList;

static Py_ssize_t WarningList_len(WarningList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *WarningList_item(WarningList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return Warning_from(&self->data.data[index], self->ctx);
}

static int WarningList_traverse(WarningList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int WarningList_clear(WarningList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void WarningList_dealloc(WarningList *self) {
    PyObject_GC_UnTrack(self);
    WarningList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods WarningList_Sequence = {
    .sq_length = (lenfunc)&WarningList_len,
    .sq_item = (ssizeargfunc)&WarningList_item,
};

static PyTypeObject WarningList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.WarningList",
    .tp_doc = PyDoc_STR("WarningList"),
    .tp_basicsize = sizeof(WarningList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &WarningList_Sequence,
    .tp_dealloc = (destructor)&WarningList_dealloc,
    .tp_traverse = (traverseproc)&WarningList_traverse,
    .tp_clear = (inquiry)&WarningList_clear,
};

static PyObject *WarningList_from(ufbx_warning_list list, Context *ctx) {
    WarningList *obj = (WarningList*)PyObject_CallObject((PyObject*)&WarningList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_baked_vec3_list data;
} BakedVec3List;

static Py_ssize_t BakedVec3List_len(BakedVec3List *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BakedVec3List_item(BakedVec3List *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return BakedVec3_from(&self->data.data[index], self->ctx);
}

static int BakedVec3List_traverse(BakedVec3List *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BakedVec3List_clear(BakedVec3List *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BakedVec3List_dealloc(BakedVec3List *self) {
    PyObject_GC_UnTrack(self);
    BakedVec3List_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BakedVec3List_Sequence = {
    .sq_length = (lenfunc)&BakedVec3List_len,
    .sq_item = (ssizeargfunc)&BakedVec3List_item,
};

static PyTypeObject BakedVec3List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedVec3List",
    .tp_doc = PyDoc_STR("BakedVec3List"),
    .tp_basicsize = sizeof(BakedVec3List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BakedVec3List_Sequence,
    .tp_dealloc = (destructor)&BakedVec3List_dealloc,
    .tp_traverse = (traverseproc)&BakedVec3List_traverse,
    .tp_clear = (inquiry)&BakedVec3List_clear,
};

static PyObject *BakedVec3List_from(ufbx_baked_vec3_list list, Context *ctx) {
    BakedVec3List *obj = (BakedVec3List*)PyObject_CallObject((PyObject*)&BakedVec3List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_baked_quat_list data;
} BakedQuatList;

static Py_ssize_t BakedQuatList_len(BakedQuatList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BakedQuatList_item(BakedQuatList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return BakedQuat_from(&self->data.data[index], self->ctx);
}

static int BakedQuatList_traverse(BakedQuatList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BakedQuatList_clear(BakedQuatList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BakedQuatList_dealloc(BakedQuatList *self) {
    PyObject_GC_UnTrack(self);
    BakedQuatList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BakedQuatList_Sequence = {
    .sq_length = (lenfunc)&BakedQuatList_len,
    .sq_item = (ssizeargfunc)&BakedQuatList_item,
};

static PyTypeObject BakedQuatList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedQuatList",
    .tp_doc = PyDoc_STR("BakedQuatList"),
    .tp_basicsize = sizeof(BakedQuatList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BakedQuatList_Sequence,
    .tp_dealloc = (destructor)&BakedQuatList_dealloc,
    .tp_traverse = (traverseproc)&BakedQuatList_traverse,
    .tp_clear = (inquiry)&BakedQuatList_clear,
};

static PyObject *BakedQuatList_from(ufbx_baked_quat_list list, Context *ctx) {
    BakedQuatList *obj = (BakedQuatList*)PyObject_CallObject((PyObject*)&BakedQuatList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_baked_node_list data;
} BakedNodeList;

static Py_ssize_t BakedNodeList_len(BakedNodeList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BakedNodeList_item(BakedNodeList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return BakedNode_from(&self->data.data[index], self->ctx);
}

static int BakedNodeList_traverse(BakedNodeList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BakedNodeList_clear(BakedNodeList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BakedNodeList_dealloc(BakedNodeList *self) {
    PyObject_GC_UnTrack(self);
    BakedNodeList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BakedNodeList_Sequence = {
    .sq_length = (lenfunc)&BakedNodeList_len,
    .sq_item = (ssizeargfunc)&BakedNodeList_item,
};

static PyTypeObject BakedNodeList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedNodeList",
    .tp_doc = PyDoc_STR("BakedNodeList"),
    .tp_basicsize = sizeof(BakedNodeList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BakedNodeList_Sequence,
    .tp_dealloc = (destructor)&BakedNodeList_dealloc,
    .tp_traverse = (traverseproc)&BakedNodeList_traverse,
    .tp_clear = (inquiry)&BakedNodeList_clear,
};

static PyObject *BakedNodeList_from(ufbx_baked_node_list list, Context *ctx) {
    BakedNodeList *obj = (BakedNodeList*)PyObject_CallObject((PyObject*)&BakedNodeList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_baked_prop_list data;
} BakedPropList;

static Py_ssize_t BakedPropList_len(BakedPropList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BakedPropList_item(BakedPropList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return BakedProp_from(&self->data.data[index], self->ctx);
}

static int BakedPropList_traverse(BakedPropList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BakedPropList_clear(BakedPropList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BakedPropList_dealloc(BakedPropList *self) {
    PyObject_GC_UnTrack(self);
    BakedPropList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BakedPropList_Sequence = {
    .sq_length = (lenfunc)&BakedPropList_len,
    .sq_item = (ssizeargfunc)&BakedPropList_item,
};

static PyTypeObject BakedPropList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedPropList",
    .tp_doc = PyDoc_STR("BakedPropList"),
    .tp_basicsize = sizeof(BakedPropList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BakedPropList_Sequence,
    .tp_dealloc = (destructor)&BakedPropList_dealloc,
    .tp_traverse = (traverseproc)&BakedPropList_traverse,
    .tp_clear = (inquiry)&BakedPropList_clear,
};

static PyObject *BakedPropList_from(ufbx_baked_prop_list list, Context *ctx) {
    BakedPropList *obj = (BakedPropList*)PyObject_CallObject((PyObject*)&BakedPropList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_baked_element_list data;
} BakedElementList;

static Py_ssize_t BakedElementList_len(BakedElementList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *BakedElementList_item(BakedElementList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return BakedElement_from(&self->data.data[index], self->ctx);
}

static int BakedElementList_traverse(BakedElementList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int BakedElementList_clear(BakedElementList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void BakedElementList_dealloc(BakedElementList *self) {
    PyObject_GC_UnTrack(self);
    BakedElementList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods BakedElementList_Sequence = {
    .sq_length = (lenfunc)&BakedElementList_len,
    .sq_item = (ssizeargfunc)&BakedElementList_item,
};

static PyTypeObject BakedElementList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BakedElementList",
    .tp_doc = PyDoc_STR("BakedElementList"),
    .tp_basicsize = sizeof(BakedElementList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &BakedElementList_Sequence,
    .tp_dealloc = (destructor)&BakedElementList_dealloc,
    .tp_traverse = (traverseproc)&BakedElementList_traverse,
    .tp_clear = (inquiry)&BakedElementList_clear,
};

static PyObject *BakedElementList_from(ufbx_baked_element_list list, Context *ctx) {
    BakedElementList *obj = (BakedElementList*)PyObject_CallObject((PyObject*)&BakedElementList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_const_uint32_list data;
} ConstUint32List;

static Py_ssize_t ConstUint32List_len(ConstUint32List *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ConstUint32List_item(ConstUint32List *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return PyLong_FromUnsignedLong((unsigned long)self->data.data[index]);
}

static int ConstUint32List_traverse(ConstUint32List *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ConstUint32List_clear(ConstUint32List *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ConstUint32List_dealloc(ConstUint32List *self) {
    PyObject_GC_UnTrack(self);
    ConstUint32List_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ConstUint32List_Sequence = {
    .sq_length = (lenfunc)&ConstUint32List_len,
    .sq_item = (ssizeargfunc)&ConstUint32List_item,
};

static PyTypeObject ConstUint32List_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstUint32List",
    .tp_doc = PyDoc_STR("ConstUint32List"),
    .tp_basicsize = sizeof(ConstUint32List),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ConstUint32List_Sequence,
    .tp_dealloc = (destructor)&ConstUint32List_dealloc,
    .tp_traverse = (traverseproc)&ConstUint32List_traverse,
    .tp_clear = (inquiry)&ConstUint32List_clear,
};

static PyObject *ConstUint32List_from(ufbx_const_uint32_list list, Context *ctx) {
    ConstUint32List *obj = (ConstUint32List*)PyObject_CallObject((PyObject*)&ConstUint32List_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_const_real_list data;
} ConstRealList;

static Py_ssize_t ConstRealList_len(ConstRealList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ConstRealList_item(ConstRealList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return PyFloat_FromDouble(self->data.data[index]);
}

static int ConstRealList_traverse(ConstRealList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ConstRealList_clear(ConstRealList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ConstRealList_dealloc(ConstRealList *self) {
    PyObject_GC_UnTrack(self);
    ConstRealList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ConstRealList_Sequence = {
    .sq_length = (lenfunc)&ConstRealList_len,
    .sq_item = (ssizeargfunc)&ConstRealList_item,
};

static PyTypeObject ConstRealList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstRealList",
    .tp_doc = PyDoc_STR("ConstRealList"),
    .tp_basicsize = sizeof(ConstRealList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ConstRealList_Sequence,
    .tp_dealloc = (destructor)&ConstRealList_dealloc,
    .tp_traverse = (traverseproc)&ConstRealList_traverse,
    .tp_clear = (inquiry)&ConstRealList_clear,
};

static PyObject *ConstRealList_from(ufbx_const_real_list list, Context *ctx) {
    ConstRealList *obj = (ConstRealList*)PyObject_CallObject((PyObject*)&ConstRealList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_const_prop_override_desc_list data;
} ConstPropOverrideDescList;

static Py_ssize_t ConstPropOverrideDescList_len(ConstPropOverrideDescList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ConstPropOverrideDescList_item(ConstPropOverrideDescList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return to_pyobject_todo("ufbx_prop_override_desc");
}

static int ConstPropOverrideDescList_traverse(ConstPropOverrideDescList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ConstPropOverrideDescList_clear(ConstPropOverrideDescList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ConstPropOverrideDescList_dealloc(ConstPropOverrideDescList *self) {
    PyObject_GC_UnTrack(self);
    ConstPropOverrideDescList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ConstPropOverrideDescList_Sequence = {
    .sq_length = (lenfunc)&ConstPropOverrideDescList_len,
    .sq_item = (ssizeargfunc)&ConstPropOverrideDescList_item,
};

static PyTypeObject ConstPropOverrideDescList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstPropOverrideDescList",
    .tp_doc = PyDoc_STR("ConstPropOverrideDescList"),
    .tp_basicsize = sizeof(ConstPropOverrideDescList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ConstPropOverrideDescList_Sequence,
    .tp_dealloc = (destructor)&ConstPropOverrideDescList_dealloc,
    .tp_traverse = (traverseproc)&ConstPropOverrideDescList_traverse,
    .tp_clear = (inquiry)&ConstPropOverrideDescList_clear,
};

static PyObject *ConstPropOverrideDescList_from(ufbx_const_prop_override_desc_list list, Context *ctx) {
    ConstPropOverrideDescList *obj = (ConstPropOverrideDescList*)PyObject_CallObject((PyObject*)&ConstPropOverrideDescList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

typedef struct {
    PyObject_HEAD
    Context *ctx;
    ufbx_const_transform_override_list data;
} ConstTransformOverrideList;

static Py_ssize_t ConstTransformOverrideList_len(ConstTransformOverrideList *self, PyObject *key) {
    return (Py_ssize_t)self->data.count;
}

static PyObject *ConstTransformOverrideList_item(ConstTransformOverrideList *self, Py_ssize_t index) {
    if (!self->ctx->ok) return Context_error(self->ctx);
    size_t count = self->data.count;
    if (index < 0 || (size_t)index >= count) {
        PyErr_Format(PyExc_IndexError, "index (%zd) out of bounds (%zu)", index, count);
        return NULL;
    }
    return TransformOverride_from(&self->data.data[index]);
}

static int ConstTransformOverrideList_traverse(ConstTransformOverrideList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    return 0;
}

static int ConstTransformOverrideList_clear(ConstTransformOverrideList *self) {
    Py_CLEAR(self->ctx);
    return 0;
}

void ConstTransformOverrideList_dealloc(ConstTransformOverrideList *self) {
    PyObject_GC_UnTrack(self);
    ConstTransformOverrideList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PySequenceMethods ConstTransformOverrideList_Sequence = {
    .sq_length = (lenfunc)&ConstTransformOverrideList_len,
    .sq_item = (ssizeargfunc)&ConstTransformOverrideList_item,
};

static PyTypeObject ConstTransformOverrideList_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ConstTransformOverrideList",
    .tp_doc = PyDoc_STR("ConstTransformOverrideList"),
    .tp_basicsize = sizeof(ConstTransformOverrideList),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_as_sequence = &ConstTransformOverrideList_Sequence,
    .tp_dealloc = (destructor)&ConstTransformOverrideList_dealloc,
    .tp_traverse = (traverseproc)&ConstTransformOverrideList_traverse,
    .tp_clear = (inquiry)&ConstTransformOverrideList_clear,
};

static PyObject *ConstTransformOverrideList_from(ufbx_const_transform_override_list list, Context *ctx) {
    ConstTransformOverrideList *obj = (ConstTransformOverrideList*)PyObject_CallObject((PyObject*)&ConstTransformOverrideList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = list;
    return (PyObject*)obj;
}

static PyObject *Transform_Type;

static PyObject *Transform_from(const ufbx_transform *v) {
    PyObject *r = PyTuple_New(3);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, Vec3_from(&v->translation));
    PyTuple_SetItem(r, 1, Quat_from(&v->rotation));
    PyTuple_SetItem(r, 2, Vec3_from(&v->scale));
    PyObject *result = PyObject_CallObject(Transform_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_transform Transform_to(PyObject *v) {
    ufbx_transform r;
    r.translation = Vec3_to(PyTuple_GetItem(v, 0));
    r.rotation = Quat_to(PyTuple_GetItem(v, 1));
    r.scale = Vec3_to(PyTuple_GetItem(v, 2));
    return r;
}

static PyObject *Edge_Type;

static PyObject *Edge_from(const ufbx_edge *v) {
    PyObject *r = PyTuple_New(2);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, PyLong_FromUnsignedLong((unsigned long)v->a));
    PyTuple_SetItem(r, 1, PyLong_FromUnsignedLong((unsigned long)v->b));
    PyObject *result = PyObject_CallObject(Edge_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_edge Edge_to(PyObject *v) {
    ufbx_edge r;
    r.a = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 0));
    r.b = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 1));
    return r;
}

static PyObject *Face_Type;

static PyObject *Face_from(const ufbx_face *v) {
    PyObject *r = PyTuple_New(2);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, PyLong_FromUnsignedLong((unsigned long)v->index_begin));
    PyTuple_SetItem(r, 1, PyLong_FromUnsignedLong((unsigned long)v->num_indices));
    PyObject *result = PyObject_CallObject(Face_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_face Face_to(PyObject *v) {
    ufbx_face r;
    r.index_begin = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 0));
    r.num_indices = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 1));
    return r;
}

static PyObject *CoordinateAxes_Type;

static PyObject *CoordinateAxes_from(const ufbx_coordinate_axes *v) {
    PyObject *r = PyTuple_New(3);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, PyObject_CallFunction(CoordinateAxis_Enum, "i", (int)v->right));
    PyTuple_SetItem(r, 1, PyObject_CallFunction(CoordinateAxis_Enum, "i", (int)v->up));
    PyTuple_SetItem(r, 2, PyObject_CallFunction(CoordinateAxis_Enum, "i", (int)v->front));
    PyObject *result = PyObject_CallObject(CoordinateAxes_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_coordinate_axes CoordinateAxes_to(PyObject *v) {
    ufbx_coordinate_axes r;
    r.right = (ufbx_coordinate_axis)PyLong_AsLong(PyTuple_GetItem(v, 0));
    r.up = (ufbx_coordinate_axis)PyLong_AsLong(PyTuple_GetItem(v, 1));
    r.front = (ufbx_coordinate_axis)PyLong_AsLong(PyTuple_GetItem(v, 2));
    return r;
}

static PyObject *LodLevel_Type;

static PyObject *LodLevel_from(const ufbx_lod_level *v) {
    PyObject *r = PyTuple_New(2);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, PyFloat_FromDouble(v->distance));
    PyTuple_SetItem(r, 1, PyObject_CallFunction(LodDisplay_Enum, "i", (int)v->display));
    PyObject *result = PyObject_CallObject(LodLevel_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_lod_level LodLevel_to(PyObject *v) {
    ufbx_lod_level r;
    r.distance = (ufbx_real)PyFloat_AsDouble(PyTuple_GetItem(v, 0));
    r.display = (ufbx_lod_display)PyLong_AsLong(PyTuple_GetItem(v, 1));
    return r;
}

static PyObject *SkinVertex_Type;

static PyObject *SkinVertex_from(const ufbx_skin_vertex *v) {
    PyObject *r = PyTuple_New(3);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, PyLong_FromUnsignedLong((unsigned long)v->weight_begin));
    PyTuple_SetItem(r, 1, PyLong_FromUnsignedLong((unsigned long)v->num_weights));
    PyTuple_SetItem(r, 2, PyFloat_FromDouble(v->dq_weight));
    PyObject *result = PyObject_CallObject(SkinVertex_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_skin_vertex SkinVertex_to(PyObject *v) {
    ufbx_skin_vertex r;
    r.weight_begin = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 0));
    r.num_weights = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 1));
    r.dq_weight = (ufbx_real)PyFloat_AsDouble(PyTuple_GetItem(v, 2));
    return r;
}

static PyObject *SkinWeight_Type;

static PyObject *SkinWeight_from(const ufbx_skin_weight *v) {
    PyObject *r = PyTuple_New(2);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, PyLong_FromUnsignedLong((unsigned long)v->cluster_index));
    PyTuple_SetItem(r, 1, PyFloat_FromDouble(v->weight));
    PyObject *result = PyObject_CallObject(SkinWeight_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_skin_weight SkinWeight_to(PyObject *v) {
    ufbx_skin_weight r;
    r.cluster_index = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 0));
    r.weight = (ufbx_real)PyFloat_AsDouble(PyTuple_GetItem(v, 1));
    return r;
}

static PyObject *TransformOverride_Type;

static PyObject *TransformOverride_from(const ufbx_transform_override *v) {
    PyObject *r = PyTuple_New(2);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, PyLong_FromUnsignedLong((unsigned long)v->node_id));
    PyTuple_SetItem(r, 1, Transform_from(&v->transform));
    PyObject *result = PyObject_CallObject(TransformOverride_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_transform_override TransformOverride_to(PyObject *v) {
    ufbx_transform_override r;
    r.node_id = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 0));
    r.transform = Transform_to(PyTuple_GetItem(v, 1));
    return r;
}

static PyObject *Tangent_Type;

static PyObject *Tangent_from(const ufbx_tangent *v) {
    PyObject *r = PyTuple_New(2);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, PyFloat_FromDouble(v->dx));
    PyTuple_SetItem(r, 1, PyFloat_FromDouble(v->dy));
    PyObject *result = PyObject_CallObject(Tangent_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_tangent Tangent_to(PyObject *v) {
    ufbx_tangent r;
    r.dx = (float)PyFloat_AsDouble(PyTuple_GetItem(v, 0));
    r.dy = (float)PyFloat_AsDouble(PyTuple_GetItem(v, 1));
    return r;
}

static PyObject *Keyframe_Type;

static PyObject *Keyframe_from(const ufbx_keyframe *v) {
    PyObject *r = PyTuple_New(5);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, PyFloat_FromDouble(v->time));
    PyTuple_SetItem(r, 1, PyFloat_FromDouble(v->value));
    PyTuple_SetItem(r, 2, PyObject_CallFunction(Interpolation_Enum, "i", (int)v->interpolation));
    PyTuple_SetItem(r, 3, Tangent_from(&v->left));
    PyTuple_SetItem(r, 4, Tangent_from(&v->right));
    PyObject *result = PyObject_CallObject(Keyframe_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_keyframe Keyframe_to(PyObject *v) {
    ufbx_keyframe r;
    r.time = PyFloat_AsDouble(PyTuple_GetItem(v, 0));
    r.value = (ufbx_real)PyFloat_AsDouble(PyTuple_GetItem(v, 1));
    r.interpolation = (ufbx_interpolation)PyLong_AsLong(PyTuple_GetItem(v, 2));
    r.left = Tangent_to(PyTuple_GetItem(v, 3));
    r.right = Tangent_to(PyTuple_GetItem(v, 4));
    return r;
}

static PyObject *CurvePoint_Type;

static PyObject *CurvePoint_from(const ufbx_curve_point *v) {
    PyObject *r = PyTuple_New(3);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, Py_NewRef(v->valid ? Py_True : Py_False));
    PyTuple_SetItem(r, 1, Vec3_from(&v->position));
    PyTuple_SetItem(r, 2, Vec3_from(&v->derivative));
    PyObject *result = PyObject_CallObject(CurvePoint_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_curve_point CurvePoint_to(PyObject *v) {
    ufbx_curve_point r;
    r.valid = PyObject_IsTrue(PyTuple_GetItem(v, 0));
    r.position = Vec3_to(PyTuple_GetItem(v, 1));
    r.derivative = Vec3_to(PyTuple_GetItem(v, 2));
    return r;
}

static PyObject *SurfacePoint_Type;

static PyObject *SurfacePoint_from(const ufbx_surface_point *v) {
    PyObject *r = PyTuple_New(4);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, Py_NewRef(v->valid ? Py_True : Py_False));
    PyTuple_SetItem(r, 1, Vec3_from(&v->position));
    PyTuple_SetItem(r, 2, Vec3_from(&v->derivative_u));
    PyTuple_SetItem(r, 3, Vec3_from(&v->derivative_v));
    PyObject *result = PyObject_CallObject(SurfacePoint_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_surface_point SurfacePoint_to(PyObject *v) {
    ufbx_surface_point r;
    r.valid = PyObject_IsTrue(PyTuple_GetItem(v, 0));
    r.position = Vec3_to(PyTuple_GetItem(v, 1));
    r.derivative_u = Vec3_to(PyTuple_GetItem(v, 2));
    r.derivative_v = Vec3_to(PyTuple_GetItem(v, 3));
    return r;
}

static PyObject *TopoEdge_Type;

static PyObject *TopoEdge_from(const ufbx_topo_edge *v) {
    PyObject *r = PyTuple_New(7);
    if (!r) return NULL;
    PyTuple_SetItem(r, 0, PyLong_FromUnsignedLong((unsigned long)v->index));
    PyTuple_SetItem(r, 1, PyLong_FromUnsignedLong((unsigned long)v->next));
    PyTuple_SetItem(r, 2, PyLong_FromUnsignedLong((unsigned long)v->prev));
    PyTuple_SetItem(r, 3, PyLong_FromUnsignedLong((unsigned long)v->twin));
    PyTuple_SetItem(r, 4, PyLong_FromUnsignedLong((unsigned long)v->face));
    PyTuple_SetItem(r, 5, PyLong_FromUnsignedLong((unsigned long)v->edge));
    PyTuple_SetItem(r, 6, PyObject_CallFunction(TopoFlags_Enum, "i", (int)v->flags));
    PyObject *result = PyObject_CallObject(TopoEdge_Type, r);
    Py_XDECREF(r);
    return result;
}

static ufbx_topo_edge TopoEdge_to(PyObject *v) {
    ufbx_topo_edge r;
    r.index = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 0));
    r.next = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 1));
    r.prev = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 2));
    r.twin = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 3));
    r.face = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 4));
    r.edge = (uint32_t)PyLong_AsUnsignedLong(PyTuple_GetItem(v, 5));
    r.flags = (ufbx_topo_flags)PyLong_AsLong(PyTuple_GetItem(v, 6));
    return r;
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

static int VoidList_traverse(VoidList *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VOID_LIST; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int VoidList_clear(VoidList *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VOID_LIST; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void VoidList_dealloc(VoidList *self) {
    PyObject_GC_UnTrack(self);
    VoidList_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&VoidList_dealloc,
    .tp_traverse = (traverseproc)&VoidList_traverse,
    .tp_clear = (inquiry)&VoidList_clear,
    .tp_getset = VoidList_getset,
};

static PyObject *VoidList_from(ufbx_void_list *data, Context *ctx) {
    VoidList *obj = (VoidList*)PyObject_CallObject((PyObject*)&VoidList_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = PyObject_CallFunction(DomValueType_Enum, "i", (int)self->data->type);
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

static int DomValue_traverse(DomValue *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_DOM_VALUE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int DomValue_clear(DomValue *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_DOM_VALUE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void DomValue_dealloc(DomValue *self) {
    PyObject_GC_UnTrack(self);
    DomValue_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&DomValue_dealloc,
    .tp_traverse = (traverseproc)&DomValue_traverse,
    .tp_clear = (inquiry)&DomValue_clear,
    .tp_getset = DomValue_getset,
};

static PyObject *DomValue_from(ufbx_dom_value *data, Context *ctx) {
    DomValue *obj = (DomValue*)PyObject_CallObject((PyObject*)&DomValue_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int DomNode_traverse(DomNode *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_DOM_NODE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int DomNode_clear(DomNode *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_DOM_NODE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void DomNode_dealloc(DomNode *self) {
    PyObject_GC_UnTrack(self);
    DomNode_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef DomNode_getset[] = {
    { "name", (getter)DomNode_get_name, NULL, "name" },
    { "children", (getter)DomNode_get_children, NULL, "children" },
    { "values", (getter)DomNode_get_values, NULL, "values" },
    { NULL },
};

static PyObject *DomNode_find(PyObject *self, PyObject *args);
static PyObject *DomNode_is_array(PyObject *self, PyObject *args);
static PyObject *DomNode_array_size(PyObject *self, PyObject *args);
static PyObject *DomNode_as_int32_list(PyObject *self, PyObject *args);
static PyObject *DomNode_as_int64_list(PyObject *self, PyObject *args);
static PyObject *DomNode_as_float_list(PyObject *self, PyObject *args);
static PyObject *DomNode_as_double_list(PyObject *self, PyObject *args);
static PyObject *DomNode_as_real_list(PyObject *self, PyObject *args);
static PyObject *DomNode_as_blob_list(PyObject *self, PyObject *args);

static PyMethodDef DomNode_methods[] = {
    { "find", &DomNode_find, METH_VARARGS, NULL },
    { "is_array", &DomNode_is_array, METH_VARARGS, NULL },
    { "array_size", &DomNode_array_size, METH_VARARGS, NULL },
    { "as_int32_list", &DomNode_as_int32_list, METH_VARARGS, NULL },
    { "as_int64_list", &DomNode_as_int64_list, METH_VARARGS, NULL },
    { "as_float_list", &DomNode_as_float_list, METH_VARARGS, NULL },
    { "as_double_list", &DomNode_as_double_list, METH_VARARGS, NULL },
    { "as_real_list", &DomNode_as_real_list, METH_VARARGS, NULL },
    { "as_blob_list", &DomNode_as_blob_list, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject DomNode_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.DomNode",
    .tp_doc = PyDoc_STR("DomNode"),
    .tp_basicsize = sizeof(DomNode),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&DomNode_dealloc,
    .tp_traverse = (traverseproc)&DomNode_traverse,
    .tp_clear = (inquiry)&DomNode_clear,
    .tp_getset = DomNode_getset,
    .tp_methods = DomNode_methods,
};

static PyObject *DomNode_from(ufbx_dom_node *data, Context *ctx) {
    DomNode *obj = (DomNode*)PyObject_CallObject((PyObject*)&DomNode_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_PROP 7
enum {
    SLOT_PROP__NAME,
    SLOT_PROP__TYPE,
    SLOT_PROP__FLAGS,
    SLOT_PROP__VALUE_STR,
    SLOT_PROP__VALUE_BLOB,
    SLOT_PROP__VALUE_INT,
    SLOT_PROP__VALUE_VEC4,
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
    slot = PyObject_CallFunction(PropType_Enum, "i", (int)self->data->type);
    self->slots[SLOT_PROP__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Prop_get_flags(Prop *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP__FLAGS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(PropFlags_Enum, "i", (int)self->data->flags);
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

static PyObject *Prop_get_value_vec4(Prop *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROP__VALUE_VEC4];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec4_from(&self->data->value_vec4);
    self->slots[SLOT_PROP__VALUE_VEC4] = slot;
    return Py_NewRef(slot);
}

static int Prop_traverse(Prop *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_PROP; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Prop_clear(Prop *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_PROP; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Prop_dealloc(Prop *self) {
    PyObject_GC_UnTrack(self);
    Prop_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Prop_getset[] = {
    { "name", (getter)Prop_get_name, NULL, "name" },
    { "type", (getter)Prop_get_type, NULL, "type" },
    { "flags", (getter)Prop_get_flags, NULL, "flags" },
    { "value_str", (getter)Prop_get_value_str, NULL, "value_str" },
    { "value_blob", (getter)Prop_get_value_blob, NULL, "value_blob" },
    { "value_int", (getter)Prop_get_value_int, NULL, "value_int" },
    { "value_vec4", (getter)Prop_get_value_vec4, NULL, "value_vec4" },
    { NULL },
};

static PyTypeObject Prop_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Prop",
    .tp_doc = PyDoc_STR("Prop"),
    .tp_basicsize = sizeof(Prop),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Prop_dealloc,
    .tp_traverse = (traverseproc)&Prop_traverse,
    .tp_clear = (inquiry)&Prop_clear,
    .tp_getset = Prop_getset,
};

static PyObject *Prop_from(ufbx_prop *data, Context *ctx) {
    Prop *obj = (Prop*)PyObject_CallObject((PyObject*)&Prop_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int Props_traverse(Props *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_PROPS; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Props_clear(Props *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_PROPS; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Props_dealloc(Props *self) {
    PyObject_GC_UnTrack(self);
    Props_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Props_getset[] = {
    { "props", (getter)Props_get_props, NULL, "props" },
    { "num_animated", (getter)Props_get_num_animated, NULL, "num_animated" },
    { "defaults", (getter)Props_get_defaults, NULL, "defaults" },
    { NULL },
};

static PyObject *Props_find_prop(PyObject *self, PyObject *args);
static PyObject *Props_find_real(PyObject *self, PyObject *args);
static PyObject *Props_find_vec3(PyObject *self, PyObject *args);
static PyObject *Props_find_int(PyObject *self, PyObject *args);
static PyObject *Props_find_bool(PyObject *self, PyObject *args);

static PyMethodDef Props_methods[] = {
    { "find_prop", &Props_find_prop, METH_VARARGS, NULL },
    { "find_real", &Props_find_real, METH_VARARGS, NULL },
    { "find_vec3", &Props_find_vec3, METH_VARARGS, NULL },
    { "find_int", &Props_find_int, METH_VARARGS, NULL },
    { "find_bool", &Props_find_bool, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject Props_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Props",
    .tp_doc = PyDoc_STR("Props"),
    .tp_basicsize = sizeof(Props),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Props_dealloc,
    .tp_traverse = (traverseproc)&Props_traverse,
    .tp_clear = (inquiry)&Props_clear,
    .tp_getset = Props_getset,
    .tp_methods = Props_methods,
};

static PyObject *Props_from(ufbx_props *data, Context *ctx) {
    Props *obj = (Props*)PyObject_CallObject((PyObject*)&Props_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int Connection_traverse(Connection *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_CONNECTION; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Connection_clear(Connection *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_CONNECTION; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Connection_dealloc(Connection *self) {
    PyObject_GC_UnTrack(self);
    Connection_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Connection_dealloc,
    .tp_traverse = (traverseproc)&Connection_traverse,
    .tp_clear = (inquiry)&Connection_clear,
    .tp_getset = Connection_getset,
};

static PyObject *Connection_from(ufbx_connection *data, Context *ctx) {
    Connection *obj = (Connection*)PyObject_CallObject((PyObject*)&Connection_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Props_from(&self->data->props, self->ctx);
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
    slot = PyObject_CallFunction(ElementType_Enum, "i", (int)self->data->type);
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

static int Element_traverse(Element *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_ELEMENT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Element_clear(Element *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_ELEMENT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Element_dealloc(Element *self) {
    PyObject_GC_UnTrack(self);
    Element_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC|Py_TPFLAGS_BASETYPE,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Element_dealloc,
    .tp_traverse = (traverseproc)&Element_traverse,
    .tp_clear = (inquiry)&Element_clear,
    .tp_getset = Element_getset,
};

#define SLOT_COUNT_UNKNOWN 7
enum {
    SLOT_UNKNOWN__NAME,
    SLOT_UNKNOWN__PROPS,
    SLOT_UNKNOWN__ELEMENT_ID,
    SLOT_UNKNOWN__TYPED_ID,
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

static PyObject *Unknown_get_name(Unknown *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UNKNOWN__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_UNKNOWN__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Unknown_get_props(Unknown *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UNKNOWN__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_UNKNOWN__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Unknown_get_element_id(Unknown *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UNKNOWN__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_UNKNOWN__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Unknown_get_typed_id(Unknown *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UNKNOWN__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_UNKNOWN__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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

static int Unknown_traverse(Unknown *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_UNKNOWN; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Unknown_clear(Unknown *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_UNKNOWN; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Unknown_dealloc(Unknown *self) {
    PyObject_GC_UnTrack(self);
    Unknown_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Unknown_getset[] = {
    { "name", (getter)Unknown_get_name, NULL, "name" },
    { "props", (getter)Unknown_get_props, NULL, "props" },
    { "element_id", (getter)Unknown_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Unknown_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Unknown_dealloc,
    .tp_traverse = (traverseproc)&Unknown_traverse,
    .tp_clear = (inquiry)&Unknown_clear,
    .tp_getset = Unknown_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_NODE 46
enum {
    SLOT_NODE__NAME,
    SLOT_NODE__PROPS,
    SLOT_NODE__ELEMENT_ID,
    SLOT_NODE__TYPED_ID,
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

static PyObject *Node_get_name(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_NODE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_props(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_NODE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_element_id(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_NODE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_typed_id(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_NODE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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
    slot = PyObject_CallFunction(ElementType_Enum, "i", (int)self->data->attrib_type);
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
    slot = PyObject_CallFunction(InheritMode_Enum, "i", (int)self->data->inherit_mode);
    self->slots[SLOT_NODE__INHERIT_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_original_inherit_mode(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__ORIGINAL_INHERIT_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(InheritMode_Enum, "i", (int)self->data->original_inherit_mode);
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
    slot = PyObject_CallFunction(RotationOrder_Enum, "i", (int)self->data->rotation_order);
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
    slot = Matrix_from(&self->data->node_to_parent);
    self->slots[SLOT_NODE__NODE_TO_PARENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_node_to_world(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__NODE_TO_WORLD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Matrix_from(&self->data->node_to_world);
    self->slots[SLOT_NODE__NODE_TO_WORLD] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_geometry_to_node(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__GEOMETRY_TO_NODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Matrix_from(&self->data->geometry_to_node);
    self->slots[SLOT_NODE__GEOMETRY_TO_NODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_geometry_to_world(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__GEOMETRY_TO_WORLD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Matrix_from(&self->data->geometry_to_world);
    self->slots[SLOT_NODE__GEOMETRY_TO_WORLD] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_unscaled_node_to_world(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__UNSCALED_NODE_TO_WORLD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Matrix_from(&self->data->unscaled_node_to_world);
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
    slot = PyObject_CallFunction(MirrorAxis_Enum, "i", (int)self->data->adjust_mirror_axis);
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
    slot = Py_NewRef(self->data->visible ? Py_True : Py_False);
    self->slots[SLOT_NODE__VISIBLE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_is_root(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__IS_ROOT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->is_root ? Py_True : Py_False);
    self->slots[SLOT_NODE__IS_ROOT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_has_geometry_transform(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__HAS_GEOMETRY_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->has_geometry_transform ? Py_True : Py_False);
    self->slots[SLOT_NODE__HAS_GEOMETRY_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_has_adjust_transform(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__HAS_ADJUST_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->has_adjust_transform ? Py_True : Py_False);
    self->slots[SLOT_NODE__HAS_ADJUST_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_has_root_adjust_transform(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__HAS_ROOT_ADJUST_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->has_root_adjust_transform ? Py_True : Py_False);
    self->slots[SLOT_NODE__HAS_ROOT_ADJUST_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_is_geometry_transform_helper(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__IS_GEOMETRY_TRANSFORM_HELPER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->is_geometry_transform_helper ? Py_True : Py_False);
    self->slots[SLOT_NODE__IS_GEOMETRY_TRANSFORM_HELPER] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_is_scale_helper(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__IS_SCALE_HELPER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->is_scale_helper ? Py_True : Py_False);
    self->slots[SLOT_NODE__IS_SCALE_HELPER] = slot;
    return Py_NewRef(slot);
}

static PyObject *Node_get_is_scale_compensate_parent(Node *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NODE__IS_SCALE_COMPENSATE_PARENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->is_scale_compensate_parent ? Py_True : Py_False);
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

static int Node_traverse(Node *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_NODE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Node_clear(Node *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_NODE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Node_dealloc(Node *self) {
    PyObject_GC_UnTrack(self);
    Node_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Node_getset[] = {
    { "name", (getter)Node_get_name, NULL, "name" },
    { "props", (getter)Node_get_props, NULL, "props" },
    { "element_id", (getter)Node_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Node_get_typed_id, NULL, "typed_id" },
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

static PyObject *Node_get_compatible_matrix_for_normals(PyObject *self, PyObject *args);
static PyObject *Node_evaluate_transform(PyObject *self, PyObject *args);

static PyMethodDef Node_methods[] = {
    { "get_compatible_matrix_for_normals", &Node_get_compatible_matrix_for_normals, METH_VARARGS, NULL },
    { "evaluate_transform", &Node_evaluate_transform, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject Node_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Node",
    .tp_doc = PyDoc_STR("Node"),
    .tp_basicsize = sizeof(Node),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Node_dealloc,
    .tp_traverse = (traverseproc)&Node_traverse,
    .tp_clear = (inquiry)&Node_clear,
    .tp_getset = Node_getset,
    .tp_base = &Element_Type,
    .tp_methods = Node_methods,
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
    slot = Py_NewRef(self->data->exists ? Py_True : Py_False);
    self->slots[SLOT_VERTEX_ATTRIB__EXISTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *VertexAttrib_get_values(VertexAttrib *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VERTEX_ATTRIB__VALUES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VoidList_from(&self->data->values, self->ctx);
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
    slot = Py_NewRef(self->data->unique_per_vertex ? Py_True : Py_False);
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

static int VertexAttrib_traverse(VertexAttrib *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_ATTRIB; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int VertexAttrib_clear(VertexAttrib *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_ATTRIB; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void VertexAttrib_dealloc(VertexAttrib *self) {
    PyObject_GC_UnTrack(self);
    VertexAttrib_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&VertexAttrib_dealloc,
    .tp_traverse = (traverseproc)&VertexAttrib_traverse,
    .tp_clear = (inquiry)&VertexAttrib_clear,
    .tp_getset = VertexAttrib_getset,
};

static PyObject *VertexAttrib_from(ufbx_vertex_attrib *data, Context *ctx) {
    VertexAttrib *obj = (VertexAttrib*)PyObject_CallObject((PyObject*)&VertexAttrib_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->exists ? Py_True : Py_False);
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
    slot = Py_NewRef(self->data->unique_per_vertex ? Py_True : Py_False);
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

static int VertexReal_traverse(VertexReal *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_REAL; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int VertexReal_clear(VertexReal *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_REAL; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void VertexReal_dealloc(VertexReal *self) {
    PyObject_GC_UnTrack(self);
    VertexReal_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&VertexReal_dealloc,
    .tp_traverse = (traverseproc)&VertexReal_traverse,
    .tp_clear = (inquiry)&VertexReal_clear,
    .tp_getset = VertexReal_getset,
};

static PyObject *VertexReal_from(ufbx_vertex_real *data, Context *ctx) {
    VertexReal *obj = (VertexReal*)PyObject_CallObject((PyObject*)&VertexReal_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->exists ? Py_True : Py_False);
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
    slot = Py_NewRef(self->data->unique_per_vertex ? Py_True : Py_False);
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

static int VertexVec2_traverse(VertexVec2 *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_VEC2; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int VertexVec2_clear(VertexVec2 *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_VEC2; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void VertexVec2_dealloc(VertexVec2 *self) {
    PyObject_GC_UnTrack(self);
    VertexVec2_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&VertexVec2_dealloc,
    .tp_traverse = (traverseproc)&VertexVec2_traverse,
    .tp_clear = (inquiry)&VertexVec2_clear,
    .tp_getset = VertexVec2_getset,
};

static PyObject *VertexVec2_from(ufbx_vertex_vec2 *data, Context *ctx) {
    VertexVec2 *obj = (VertexVec2*)PyObject_CallObject((PyObject*)&VertexVec2_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->exists ? Py_True : Py_False);
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
    slot = Py_NewRef(self->data->unique_per_vertex ? Py_True : Py_False);
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

static int VertexVec3_traverse(VertexVec3 *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_VEC3; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int VertexVec3_clear(VertexVec3 *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_VEC3; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void VertexVec3_dealloc(VertexVec3 *self) {
    PyObject_GC_UnTrack(self);
    VertexVec3_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&VertexVec3_dealloc,
    .tp_traverse = (traverseproc)&VertexVec3_traverse,
    .tp_clear = (inquiry)&VertexVec3_clear,
    .tp_getset = VertexVec3_getset,
};

static PyObject *VertexVec3_from(ufbx_vertex_vec3 *data, Context *ctx) {
    VertexVec3 *obj = (VertexVec3*)PyObject_CallObject((PyObject*)&VertexVec3_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->exists ? Py_True : Py_False);
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
    slot = Py_NewRef(self->data->unique_per_vertex ? Py_True : Py_False);
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

static int VertexVec4_traverse(VertexVec4 *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_VEC4; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int VertexVec4_clear(VertexVec4 *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_VEC4; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void VertexVec4_dealloc(VertexVec4 *self) {
    PyObject_GC_UnTrack(self);
    VertexVec4_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&VertexVec4_dealloc,
    .tp_traverse = (traverseproc)&VertexVec4_traverse,
    .tp_clear = (inquiry)&VertexVec4_clear,
    .tp_getset = VertexVec4_getset,
};

static PyObject *VertexVec4_from(ufbx_vertex_vec4 *data, Context *ctx) {
    VertexVec4 *obj = (VertexVec4*)PyObject_CallObject((PyObject*)&VertexVec4_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = VertexVec2_from(&self->data->vertex_uv, self->ctx);
    self->slots[SLOT_UV_SET__VERTEX_UV] = slot;
    return Py_NewRef(slot);
}

static PyObject *UvSet_get_vertex_tangent(UvSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UV_SET__VERTEX_TANGENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VertexVec3_from(&self->data->vertex_tangent, self->ctx);
    self->slots[SLOT_UV_SET__VERTEX_TANGENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *UvSet_get_vertex_bitangent(UvSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_UV_SET__VERTEX_BITANGENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VertexVec3_from(&self->data->vertex_bitangent, self->ctx);
    self->slots[SLOT_UV_SET__VERTEX_BITANGENT] = slot;
    return Py_NewRef(slot);
}

static int UvSet_traverse(UvSet *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_UV_SET; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int UvSet_clear(UvSet *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_UV_SET; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void UvSet_dealloc(UvSet *self) {
    PyObject_GC_UnTrack(self);
    UvSet_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&UvSet_dealloc,
    .tp_traverse = (traverseproc)&UvSet_traverse,
    .tp_clear = (inquiry)&UvSet_clear,
    .tp_getset = UvSet_getset,
};

static PyObject *UvSet_from(ufbx_uv_set *data, Context *ctx) {
    UvSet *obj = (UvSet*)PyObject_CallObject((PyObject*)&UvSet_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = VertexVec4_from(&self->data->vertex_color, self->ctx);
    self->slots[SLOT_COLOR_SET__VERTEX_COLOR] = slot;
    return Py_NewRef(slot);
}

static int ColorSet_traverse(ColorSet *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_COLOR_SET; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int ColorSet_clear(ColorSet *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_COLOR_SET; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void ColorSet_dealloc(ColorSet *self) {
    PyObject_GC_UnTrack(self);
    ColorSet_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&ColorSet_dealloc,
    .tp_traverse = (traverseproc)&ColorSet_traverse,
    .tp_clear = (inquiry)&ColorSet_clear,
    .tp_getset = ColorSet_getset,
};

static PyObject *ColorSet_from(ufbx_color_set *data, Context *ctx) {
    ColorSet *obj = (ColorSet*)PyObject_CallObject((PyObject*)&ColorSet_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int MeshPart_traverse(MeshPart *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MESH_PART; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int MeshPart_clear(MeshPart *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MESH_PART; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void MeshPart_dealloc(MeshPart *self) {
    PyObject_GC_UnTrack(self);
    MeshPart_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&MeshPart_dealloc,
    .tp_traverse = (traverseproc)&MeshPart_traverse,
    .tp_clear = (inquiry)&MeshPart_clear,
    .tp_getset = MeshPart_getset,
};

static PyObject *MeshPart_from(ufbx_mesh_part *data, Context *ctx) {
    MeshPart *obj = (MeshPart*)PyObject_CallObject((PyObject*)&MeshPart_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int FaceGroup_traverse(FaceGroup *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_FACE_GROUP; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int FaceGroup_clear(FaceGroup *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_FACE_GROUP; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void FaceGroup_dealloc(FaceGroup *self) {
    PyObject_GC_UnTrack(self);
    FaceGroup_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&FaceGroup_dealloc,
    .tp_traverse = (traverseproc)&FaceGroup_traverse,
    .tp_clear = (inquiry)&FaceGroup_clear,
    .tp_getset = FaceGroup_getset,
};

static PyObject *FaceGroup_from(ufbx_face_group *data, Context *ctx) {
    FaceGroup *obj = (FaceGroup*)PyObject_CallObject((PyObject*)&FaceGroup_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int SubdivisionWeightRange_traverse(SubdivisionWeightRange *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SUBDIVISION_WEIGHT_RANGE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int SubdivisionWeightRange_clear(SubdivisionWeightRange *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SUBDIVISION_WEIGHT_RANGE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void SubdivisionWeightRange_dealloc(SubdivisionWeightRange *self) {
    PyObject_GC_UnTrack(self);
    SubdivisionWeightRange_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&SubdivisionWeightRange_dealloc,
    .tp_traverse = (traverseproc)&SubdivisionWeightRange_traverse,
    .tp_clear = (inquiry)&SubdivisionWeightRange_clear,
    .tp_getset = SubdivisionWeightRange_getset,
};

static PyObject *SubdivisionWeightRange_from(ufbx_subdivision_weight_range *data, Context *ctx) {
    SubdivisionWeightRange *obj = (SubdivisionWeightRange*)PyObject_CallObject((PyObject*)&SubdivisionWeightRange_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int SubdivisionWeight_traverse(SubdivisionWeight *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SUBDIVISION_WEIGHT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int SubdivisionWeight_clear(SubdivisionWeight *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SUBDIVISION_WEIGHT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void SubdivisionWeight_dealloc(SubdivisionWeight *self) {
    PyObject_GC_UnTrack(self);
    SubdivisionWeight_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&SubdivisionWeight_dealloc,
    .tp_traverse = (traverseproc)&SubdivisionWeight_traverse,
    .tp_clear = (inquiry)&SubdivisionWeight_clear,
    .tp_getset = SubdivisionWeight_getset,
};

static PyObject *SubdivisionWeight_from(ufbx_subdivision_weight *data, Context *ctx) {
    SubdivisionWeight *obj = (SubdivisionWeight*)PyObject_CallObject((PyObject*)&SubdivisionWeight_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int SubdivisionResult_traverse(SubdivisionResult *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SUBDIVISION_RESULT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int SubdivisionResult_clear(SubdivisionResult *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SUBDIVISION_RESULT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void SubdivisionResult_dealloc(SubdivisionResult *self) {
    PyObject_GC_UnTrack(self);
    SubdivisionResult_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&SubdivisionResult_dealloc,
    .tp_traverse = (traverseproc)&SubdivisionResult_traverse,
    .tp_clear = (inquiry)&SubdivisionResult_clear,
    .tp_getset = SubdivisionResult_getset,
};

static PyObject *SubdivisionResult_from(ufbx_subdivision_result *data, Context *ctx) {
    SubdivisionResult *obj = (SubdivisionResult*)PyObject_CallObject((PyObject*)&SubdivisionResult_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_MESH 57
enum {
    SLOT_MESH__NAME,
    SLOT_MESH__PROPS,
    SLOT_MESH__ELEMENT_ID,
    SLOT_MESH__TYPED_ID,
    SLOT_MESH__INSTANCES,
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

static PyObject *Mesh_get_name(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_MESH__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_props(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_MESH__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_element_id(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_MESH__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_typed_id(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_MESH__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_instances(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_MESH__INSTANCES] = slot;
    return Py_NewRef(slot);
}

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
    slot = VertexVec3_from(&self->data->vertex_position, self->ctx);
    self->slots[SLOT_MESH__VERTEX_POSITION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_normal(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_NORMAL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VertexVec3_from(&self->data->vertex_normal, self->ctx);
    self->slots[SLOT_MESH__VERTEX_NORMAL] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_uv(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_UV];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VertexVec2_from(&self->data->vertex_uv, self->ctx);
    self->slots[SLOT_MESH__VERTEX_UV] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_tangent(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_TANGENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VertexVec3_from(&self->data->vertex_tangent, self->ctx);
    self->slots[SLOT_MESH__VERTEX_TANGENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_bitangent(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_BITANGENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VertexVec3_from(&self->data->vertex_bitangent, self->ctx);
    self->slots[SLOT_MESH__VERTEX_BITANGENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_color(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VertexVec4_from(&self->data->vertex_color, self->ctx);
    self->slots[SLOT_MESH__VERTEX_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_vertex_crease(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__VERTEX_CREASE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VertexReal_from(&self->data->vertex_crease, self->ctx);
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
    slot = Py_NewRef(self->data->skinned_is_local ? Py_True : Py_False);
    self->slots[SLOT_MESH__SKINNED_IS_LOCAL] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_skinned_position(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SKINNED_POSITION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VertexVec3_from(&self->data->skinned_position, self->ctx);
    self->slots[SLOT_MESH__SKINNED_POSITION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_skinned_normal(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SKINNED_NORMAL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VertexVec3_from(&self->data->skinned_normal, self->ctx);
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
    slot = PyObject_CallFunction(SubdivisionDisplayMode_Enum, "i", (int)self->data->subdivision_display_mode);
    self->slots[SLOT_MESH__SUBDIVISION_DISPLAY_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_subdivision_boundary(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SUBDIVISION_BOUNDARY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(SubdivisionBoundary_Enum, "i", (int)self->data->subdivision_boundary);
    self->slots[SLOT_MESH__SUBDIVISION_BOUNDARY] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_subdivision_uv_boundary(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SUBDIVISION_UV_BOUNDARY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(SubdivisionBoundary_Enum, "i", (int)self->data->subdivision_uv_boundary);
    self->slots[SLOT_MESH__SUBDIVISION_UV_BOUNDARY] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_reversed_winding(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__REVERSED_WINDING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->reversed_winding ? Py_True : Py_False);
    self->slots[SLOT_MESH__REVERSED_WINDING] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_generated_normals(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__GENERATED_NORMALS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->generated_normals ? Py_True : Py_False);
    self->slots[SLOT_MESH__GENERATED_NORMALS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Mesh_get_subdivision_evaluated(Mesh *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MESH__SUBDIVISION_EVALUATED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->subdivision_evaluated ? Py_True : Py_False);
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
    slot = Py_NewRef(self->data->from_tessellated_nurbs ? Py_True : Py_False);
    self->slots[SLOT_MESH__FROM_TESSELLATED_NURBS] = slot;
    return Py_NewRef(slot);
}

static int Mesh_traverse(Mesh *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_MESH; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Mesh_clear(Mesh *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_MESH; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Mesh_dealloc(Mesh *self) {
    PyObject_GC_UnTrack(self);
    Mesh_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Mesh_getset[] = {
    { "name", (getter)Mesh_get_name, NULL, "name" },
    { "props", (getter)Mesh_get_props, NULL, "props" },
    { "element_id", (getter)Mesh_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Mesh_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)Mesh_get_instances, NULL, "instances" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Mesh_dealloc,
    .tp_traverse = (traverseproc)&Mesh_traverse,
    .tp_clear = (inquiry)&Mesh_clear,
    .tp_getset = Mesh_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_LIGHT 15
enum {
    SLOT_LIGHT__NAME,
    SLOT_LIGHT__PROPS,
    SLOT_LIGHT__ELEMENT_ID,
    SLOT_LIGHT__TYPED_ID,
    SLOT_LIGHT__INSTANCES,
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

static PyObject *Light_get_name(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_LIGHT__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_props(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_LIGHT__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_element_id(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_LIGHT__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_typed_id(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_LIGHT__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_instances(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_LIGHT__INSTANCES] = slot;
    return Py_NewRef(slot);
}

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
    slot = PyObject_CallFunction(LightType_Enum, "i", (int)self->data->type);
    self->slots[SLOT_LIGHT__TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_decay(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__DECAY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(LightDecay_Enum, "i", (int)self->data->decay);
    self->slots[SLOT_LIGHT__DECAY] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_area_shape(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__AREA_SHAPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(LightAreaShape_Enum, "i", (int)self->data->area_shape);
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
    slot = Py_NewRef(self->data->cast_light ? Py_True : Py_False);
    self->slots[SLOT_LIGHT__CAST_LIGHT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Light_get_cast_shadows(Light *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LIGHT__CAST_SHADOWS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->cast_shadows ? Py_True : Py_False);
    self->slots[SLOT_LIGHT__CAST_SHADOWS] = slot;
    return Py_NewRef(slot);
}

static int Light_traverse(Light *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_LIGHT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Light_clear(Light *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_LIGHT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Light_dealloc(Light *self) {
    PyObject_GC_UnTrack(self);
    Light_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Light_getset[] = {
    { "name", (getter)Light_get_name, NULL, "name" },
    { "props", (getter)Light_get_props, NULL, "props" },
    { "element_id", (getter)Light_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Light_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)Light_get_instances, NULL, "instances" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Light_dealloc,
    .tp_traverse = (traverseproc)&Light_traverse,
    .tp_clear = (inquiry)&Light_clear,
    .tp_getset = Light_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_CAMERA 25
enum {
    SLOT_CAMERA__NAME,
    SLOT_CAMERA__PROPS,
    SLOT_CAMERA__ELEMENT_ID,
    SLOT_CAMERA__TYPED_ID,
    SLOT_CAMERA__INSTANCES,
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

static PyObject *Camera_get_name(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_CAMERA__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_props(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_CAMERA__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_element_id(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_CAMERA__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_typed_id(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_CAMERA__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_instances(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_CAMERA__INSTANCES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_projection_mode(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__PROJECTION_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(ProjectionMode_Enum, "i", (int)self->data->projection_mode);
    self->slots[SLOT_CAMERA__PROJECTION_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_resolution_is_pixels(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__RESOLUTION_IS_PIXELS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->resolution_is_pixels ? Py_True : Py_False);
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
    slot = CoordinateAxes_from(&self->data->projection_axes);
    self->slots[SLOT_CAMERA__PROJECTION_AXES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_aspect_mode(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__ASPECT_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(AspectMode_Enum, "i", (int)self->data->aspect_mode);
    self->slots[SLOT_CAMERA__ASPECT_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_aperture_mode(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__APERTURE_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(ApertureMode_Enum, "i", (int)self->data->aperture_mode);
    self->slots[SLOT_CAMERA__APERTURE_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_gate_fit(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__GATE_FIT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(GateFit_Enum, "i", (int)self->data->gate_fit);
    self->slots[SLOT_CAMERA__GATE_FIT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Camera_get_aperture_format(Camera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA__APERTURE_FORMAT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(ApertureFormat_Enum, "i", (int)self->data->aperture_format);
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

static int Camera_traverse(Camera *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CAMERA; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Camera_clear(Camera *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CAMERA; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Camera_dealloc(Camera *self) {
    PyObject_GC_UnTrack(self);
    Camera_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Camera_getset[] = {
    { "name", (getter)Camera_get_name, NULL, "name" },
    { "props", (getter)Camera_get_props, NULL, "props" },
    { "element_id", (getter)Camera_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Camera_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)Camera_get_instances, NULL, "instances" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Camera_dealloc,
    .tp_traverse = (traverseproc)&Camera_traverse,
    .tp_clear = (inquiry)&Camera_clear,
    .tp_getset = Camera_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_BONE 8
enum {
    SLOT_BONE__NAME,
    SLOT_BONE__PROPS,
    SLOT_BONE__ELEMENT_ID,
    SLOT_BONE__TYPED_ID,
    SLOT_BONE__INSTANCES,
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

static PyObject *Bone_get_name(Bone *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_BONE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Bone_get_props(Bone *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_BONE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Bone_get_element_id(Bone *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_BONE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Bone_get_typed_id(Bone *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_BONE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Bone_get_instances(Bone *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_BONE__INSTANCES] = slot;
    return Py_NewRef(slot);
}

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
    slot = Py_NewRef(self->data->is_root ? Py_True : Py_False);
    self->slots[SLOT_BONE__IS_ROOT] = slot;
    return Py_NewRef(slot);
}

static int Bone_traverse(Bone *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_BONE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Bone_clear(Bone *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_BONE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Bone_dealloc(Bone *self) {
    PyObject_GC_UnTrack(self);
    Bone_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Bone_getset[] = {
    { "name", (getter)Bone_get_name, NULL, "name" },
    { "props", (getter)Bone_get_props, NULL, "props" },
    { "element_id", (getter)Bone_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Bone_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)Bone_get_instances, NULL, "instances" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Bone_dealloc,
    .tp_traverse = (traverseproc)&Bone_traverse,
    .tp_clear = (inquiry)&Bone_clear,
    .tp_getset = Bone_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_EMPTY 5
enum {
    SLOT_EMPTY__NAME,
    SLOT_EMPTY__PROPS,
    SLOT_EMPTY__ELEMENT_ID,
    SLOT_EMPTY__TYPED_ID,
    SLOT_EMPTY__INSTANCES,
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
    PyObject *slots[SLOT_COUNT_EMPTY];
} Empty;

static PyObject *Empty_get_name(Empty *self, void *closure) {
    PyObject *slot = self->slots[SLOT_EMPTY__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_EMPTY__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Empty_get_props(Empty *self, void *closure) {
    PyObject *slot = self->slots[SLOT_EMPTY__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_EMPTY__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Empty_get_element_id(Empty *self, void *closure) {
    PyObject *slot = self->slots[SLOT_EMPTY__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_EMPTY__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Empty_get_typed_id(Empty *self, void *closure) {
    PyObject *slot = self->slots[SLOT_EMPTY__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_EMPTY__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Empty_get_instances(Empty *self, void *closure) {
    PyObject *slot = self->slots[SLOT_EMPTY__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_EMPTY__INSTANCES] = slot;
    return Py_NewRef(slot);
}

static int Empty_traverse(Empty *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_EMPTY; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Empty_clear(Empty *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_EMPTY; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Empty_dealloc(Empty *self) {
    PyObject_GC_UnTrack(self);
    Empty_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Empty_getset[] = {
    { "name", (getter)Empty_get_name, NULL, "name" },
    { "props", (getter)Empty_get_props, NULL, "props" },
    { "element_id", (getter)Empty_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Empty_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)Empty_get_instances, NULL, "instances" },
    { NULL },
};

static PyTypeObject Empty_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Empty",
    .tp_doc = PyDoc_STR("Empty"),
    .tp_basicsize = sizeof(Empty),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Empty_dealloc,
    .tp_traverse = (traverseproc)&Empty_traverse,
    .tp_clear = (inquiry)&Empty_clear,
    .tp_getset = Empty_getset,
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

static int LineSegment_traverse(LineSegment *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_LINE_SEGMENT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int LineSegment_clear(LineSegment *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_LINE_SEGMENT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void LineSegment_dealloc(LineSegment *self) {
    PyObject_GC_UnTrack(self);
    LineSegment_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&LineSegment_dealloc,
    .tp_traverse = (traverseproc)&LineSegment_traverse,
    .tp_clear = (inquiry)&LineSegment_clear,
    .tp_getset = LineSegment_getset,
};

static PyObject *LineSegment_from(ufbx_line_segment *data, Context *ctx) {
    LineSegment *obj = (LineSegment*)PyObject_CallObject((PyObject*)&LineSegment_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_LINE_CURVE 10
enum {
    SLOT_LINE_CURVE__NAME,
    SLOT_LINE_CURVE__PROPS,
    SLOT_LINE_CURVE__ELEMENT_ID,
    SLOT_LINE_CURVE__TYPED_ID,
    SLOT_LINE_CURVE__INSTANCES,
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

static PyObject *LineCurve_get_name(LineCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_CURVE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_LINE_CURVE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *LineCurve_get_props(LineCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_CURVE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_LINE_CURVE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *LineCurve_get_element_id(LineCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_CURVE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_LINE_CURVE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *LineCurve_get_typed_id(LineCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_CURVE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_LINE_CURVE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *LineCurve_get_instances(LineCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LINE_CURVE__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_LINE_CURVE__INSTANCES] = slot;
    return Py_NewRef(slot);
}

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
    slot = Py_NewRef(self->data->from_tessellated_nurbs ? Py_True : Py_False);
    self->slots[SLOT_LINE_CURVE__FROM_TESSELLATED_NURBS] = slot;
    return Py_NewRef(slot);
}

static int LineCurve_traverse(LineCurve *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_LINE_CURVE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int LineCurve_clear(LineCurve *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_LINE_CURVE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void LineCurve_dealloc(LineCurve *self) {
    PyObject_GC_UnTrack(self);
    LineCurve_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef LineCurve_getset[] = {
    { "name", (getter)LineCurve_get_name, NULL, "name" },
    { "props", (getter)LineCurve_get_props, NULL, "props" },
    { "element_id", (getter)LineCurve_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)LineCurve_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)LineCurve_get_instances, NULL, "instances" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&LineCurve_dealloc,
    .tp_traverse = (traverseproc)&LineCurve_traverse,
    .tp_clear = (inquiry)&LineCurve_clear,
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
    slot = PyObject_CallFunction(NurbsTopology_Enum, "i", (int)self->data->topology);
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
    slot = Py_NewRef(self->data->is_2d ? Py_True : Py_False);
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
    slot = Py_NewRef(self->data->valid ? Py_True : Py_False);
    self->slots[SLOT_NURBS_BASIS__VALID] = slot;
    return Py_NewRef(slot);
}

static int NurbsBasis_traverse(NurbsBasis *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_NURBS_BASIS; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int NurbsBasis_clear(NurbsBasis *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_NURBS_BASIS; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void NurbsBasis_dealloc(NurbsBasis *self) {
    PyObject_GC_UnTrack(self);
    NurbsBasis_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&NurbsBasis_dealloc,
    .tp_traverse = (traverseproc)&NurbsBasis_traverse,
    .tp_clear = (inquiry)&NurbsBasis_clear,
    .tp_getset = NurbsBasis_getset,
};

static PyObject *NurbsBasis_from(ufbx_nurbs_basis *data, Context *ctx) {
    NurbsBasis *obj = (NurbsBasis*)PyObject_CallObject((PyObject*)&NurbsBasis_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_NURBS_CURVE 7
enum {
    SLOT_NURBS_CURVE__NAME,
    SLOT_NURBS_CURVE__PROPS,
    SLOT_NURBS_CURVE__ELEMENT_ID,
    SLOT_NURBS_CURVE__TYPED_ID,
    SLOT_NURBS_CURVE__INSTANCES,
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

static PyObject *NurbsCurve_get_name(NurbsCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_CURVE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_NURBS_CURVE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsCurve_get_props(NurbsCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_CURVE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_NURBS_CURVE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsCurve_get_element_id(NurbsCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_CURVE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_NURBS_CURVE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsCurve_get_typed_id(NurbsCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_CURVE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_NURBS_CURVE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsCurve_get_instances(NurbsCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_CURVE__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_NURBS_CURVE__INSTANCES] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsCurve_get_basis(NurbsCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_CURVE__BASIS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NurbsBasis_from(&self->data->basis, self->ctx);
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

static int NurbsCurve_traverse(NurbsCurve *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_NURBS_CURVE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int NurbsCurve_clear(NurbsCurve *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_NURBS_CURVE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void NurbsCurve_dealloc(NurbsCurve *self) {
    PyObject_GC_UnTrack(self);
    NurbsCurve_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef NurbsCurve_getset[] = {
    { "name", (getter)NurbsCurve_get_name, NULL, "name" },
    { "props", (getter)NurbsCurve_get_props, NULL, "props" },
    { "element_id", (getter)NurbsCurve_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)NurbsCurve_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)NurbsCurve_get_instances, NULL, "instances" },
    { "basis", (getter)NurbsCurve_get_basis, NULL, "basis" },
    { "control_points", (getter)NurbsCurve_get_control_points, NULL, "control_points" },
    { NULL },
};

static PyObject *NurbsCurve_evaluate(PyObject *self, PyObject *args);

static PyMethodDef NurbsCurve_methods[] = {
    { "evaluate", &NurbsCurve_evaluate, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject NurbsCurve_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsCurve",
    .tp_doc = PyDoc_STR("NurbsCurve"),
    .tp_basicsize = sizeof(NurbsCurve),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&NurbsCurve_dealloc,
    .tp_traverse = (traverseproc)&NurbsCurve_traverse,
    .tp_clear = (inquiry)&NurbsCurve_clear,
    .tp_getset = NurbsCurve_getset,
    .tp_base = &Element_Type,
    .tp_methods = NurbsCurve_methods,
};

#define SLOT_COUNT_NURBS_SURFACE 14
enum {
    SLOT_NURBS_SURFACE__NAME,
    SLOT_NURBS_SURFACE__PROPS,
    SLOT_NURBS_SURFACE__ELEMENT_ID,
    SLOT_NURBS_SURFACE__TYPED_ID,
    SLOT_NURBS_SURFACE__INSTANCES,
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

static PyObject *NurbsSurface_get_name(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_NURBS_SURFACE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_props(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_NURBS_SURFACE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_element_id(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_NURBS_SURFACE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_typed_id(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_NURBS_SURFACE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_instances(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_NURBS_SURFACE__INSTANCES] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_basis_u(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__BASIS_U];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NurbsBasis_from(&self->data->basis_u, self->ctx);
    self->slots[SLOT_NURBS_SURFACE__BASIS_U] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsSurface_get_basis_v(NurbsSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_SURFACE__BASIS_V];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NurbsBasis_from(&self->data->basis_v, self->ctx);
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
    slot = Py_NewRef(self->data->flip_normals ? Py_True : Py_False);
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

static int NurbsSurface_traverse(NurbsSurface *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_NURBS_SURFACE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int NurbsSurface_clear(NurbsSurface *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_NURBS_SURFACE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void NurbsSurface_dealloc(NurbsSurface *self) {
    PyObject_GC_UnTrack(self);
    NurbsSurface_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef NurbsSurface_getset[] = {
    { "name", (getter)NurbsSurface_get_name, NULL, "name" },
    { "props", (getter)NurbsSurface_get_props, NULL, "props" },
    { "element_id", (getter)NurbsSurface_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)NurbsSurface_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)NurbsSurface_get_instances, NULL, "instances" },
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

static PyObject *NurbsSurface_evaluate(PyObject *self, PyObject *args);

static PyMethodDef NurbsSurface_methods[] = {
    { "evaluate", &NurbsSurface_evaluate, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject NurbsSurface_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsSurface",
    .tp_doc = PyDoc_STR("NurbsSurface"),
    .tp_basicsize = sizeof(NurbsSurface),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&NurbsSurface_dealloc,
    .tp_traverse = (traverseproc)&NurbsSurface_traverse,
    .tp_clear = (inquiry)&NurbsSurface_clear,
    .tp_getset = NurbsSurface_getset,
    .tp_base = &Element_Type,
    .tp_methods = NurbsSurface_methods,
};

#define SLOT_COUNT_NURBS_TRIM_SURFACE 5
enum {
    SLOT_NURBS_TRIM_SURFACE__NAME,
    SLOT_NURBS_TRIM_SURFACE__PROPS,
    SLOT_NURBS_TRIM_SURFACE__ELEMENT_ID,
    SLOT_NURBS_TRIM_SURFACE__TYPED_ID,
    SLOT_NURBS_TRIM_SURFACE__INSTANCES,
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
    PyObject *slots[SLOT_COUNT_NURBS_TRIM_SURFACE];
} NurbsTrimSurface;

static PyObject *NurbsTrimSurface_get_name(NurbsTrimSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_TRIM_SURFACE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_NURBS_TRIM_SURFACE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsTrimSurface_get_props(NurbsTrimSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_TRIM_SURFACE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_NURBS_TRIM_SURFACE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsTrimSurface_get_element_id(NurbsTrimSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_TRIM_SURFACE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_NURBS_TRIM_SURFACE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsTrimSurface_get_typed_id(NurbsTrimSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_TRIM_SURFACE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_NURBS_TRIM_SURFACE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsTrimSurface_get_instances(NurbsTrimSurface *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_TRIM_SURFACE__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_NURBS_TRIM_SURFACE__INSTANCES] = slot;
    return Py_NewRef(slot);
}

static int NurbsTrimSurface_traverse(NurbsTrimSurface *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_NURBS_TRIM_SURFACE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int NurbsTrimSurface_clear(NurbsTrimSurface *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_NURBS_TRIM_SURFACE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void NurbsTrimSurface_dealloc(NurbsTrimSurface *self) {
    PyObject_GC_UnTrack(self);
    NurbsTrimSurface_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef NurbsTrimSurface_getset[] = {
    { "name", (getter)NurbsTrimSurface_get_name, NULL, "name" },
    { "props", (getter)NurbsTrimSurface_get_props, NULL, "props" },
    { "element_id", (getter)NurbsTrimSurface_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)NurbsTrimSurface_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)NurbsTrimSurface_get_instances, NULL, "instances" },
    { NULL },
};

static PyTypeObject NurbsTrimSurface_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsTrimSurface",
    .tp_doc = PyDoc_STR("NurbsTrimSurface"),
    .tp_basicsize = sizeof(NurbsTrimSurface),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&NurbsTrimSurface_dealloc,
    .tp_traverse = (traverseproc)&NurbsTrimSurface_traverse,
    .tp_clear = (inquiry)&NurbsTrimSurface_clear,
    .tp_getset = NurbsTrimSurface_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_NURBS_TRIM_BOUNDARY 5
enum {
    SLOT_NURBS_TRIM_BOUNDARY__NAME,
    SLOT_NURBS_TRIM_BOUNDARY__PROPS,
    SLOT_NURBS_TRIM_BOUNDARY__ELEMENT_ID,
    SLOT_NURBS_TRIM_BOUNDARY__TYPED_ID,
    SLOT_NURBS_TRIM_BOUNDARY__INSTANCES,
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
    PyObject *slots[SLOT_COUNT_NURBS_TRIM_BOUNDARY];
} NurbsTrimBoundary;

static PyObject *NurbsTrimBoundary_get_name(NurbsTrimBoundary *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_TRIM_BOUNDARY__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_NURBS_TRIM_BOUNDARY__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsTrimBoundary_get_props(NurbsTrimBoundary *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_TRIM_BOUNDARY__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_NURBS_TRIM_BOUNDARY__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsTrimBoundary_get_element_id(NurbsTrimBoundary *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_TRIM_BOUNDARY__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_NURBS_TRIM_BOUNDARY__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsTrimBoundary_get_typed_id(NurbsTrimBoundary *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_TRIM_BOUNDARY__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_NURBS_TRIM_BOUNDARY__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *NurbsTrimBoundary_get_instances(NurbsTrimBoundary *self, void *closure) {
    PyObject *slot = self->slots[SLOT_NURBS_TRIM_BOUNDARY__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_NURBS_TRIM_BOUNDARY__INSTANCES] = slot;
    return Py_NewRef(slot);
}

static int NurbsTrimBoundary_traverse(NurbsTrimBoundary *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_NURBS_TRIM_BOUNDARY; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int NurbsTrimBoundary_clear(NurbsTrimBoundary *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_NURBS_TRIM_BOUNDARY; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void NurbsTrimBoundary_dealloc(NurbsTrimBoundary *self) {
    PyObject_GC_UnTrack(self);
    NurbsTrimBoundary_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef NurbsTrimBoundary_getset[] = {
    { "name", (getter)NurbsTrimBoundary_get_name, NULL, "name" },
    { "props", (getter)NurbsTrimBoundary_get_props, NULL, "props" },
    { "element_id", (getter)NurbsTrimBoundary_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)NurbsTrimBoundary_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)NurbsTrimBoundary_get_instances, NULL, "instances" },
    { NULL },
};

static PyTypeObject NurbsTrimBoundary_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.NurbsTrimBoundary",
    .tp_doc = PyDoc_STR("NurbsTrimBoundary"),
    .tp_basicsize = sizeof(NurbsTrimBoundary),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&NurbsTrimBoundary_dealloc,
    .tp_traverse = (traverseproc)&NurbsTrimBoundary_traverse,
    .tp_clear = (inquiry)&NurbsTrimBoundary_clear,
    .tp_getset = NurbsTrimBoundary_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_PROCEDURAL_GEOMETRY 5
enum {
    SLOT_PROCEDURAL_GEOMETRY__NAME,
    SLOT_PROCEDURAL_GEOMETRY__PROPS,
    SLOT_PROCEDURAL_GEOMETRY__ELEMENT_ID,
    SLOT_PROCEDURAL_GEOMETRY__TYPED_ID,
    SLOT_PROCEDURAL_GEOMETRY__INSTANCES,
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
    PyObject *slots[SLOT_COUNT_PROCEDURAL_GEOMETRY];
} ProceduralGeometry;

static PyObject *ProceduralGeometry_get_name(ProceduralGeometry *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROCEDURAL_GEOMETRY__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_PROCEDURAL_GEOMETRY__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *ProceduralGeometry_get_props(ProceduralGeometry *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROCEDURAL_GEOMETRY__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_PROCEDURAL_GEOMETRY__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *ProceduralGeometry_get_element_id(ProceduralGeometry *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROCEDURAL_GEOMETRY__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_PROCEDURAL_GEOMETRY__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *ProceduralGeometry_get_typed_id(ProceduralGeometry *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROCEDURAL_GEOMETRY__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_PROCEDURAL_GEOMETRY__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *ProceduralGeometry_get_instances(ProceduralGeometry *self, void *closure) {
    PyObject *slot = self->slots[SLOT_PROCEDURAL_GEOMETRY__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_PROCEDURAL_GEOMETRY__INSTANCES] = slot;
    return Py_NewRef(slot);
}

static int ProceduralGeometry_traverse(ProceduralGeometry *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_PROCEDURAL_GEOMETRY; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int ProceduralGeometry_clear(ProceduralGeometry *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_PROCEDURAL_GEOMETRY; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void ProceduralGeometry_dealloc(ProceduralGeometry *self) {
    PyObject_GC_UnTrack(self);
    ProceduralGeometry_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef ProceduralGeometry_getset[] = {
    { "name", (getter)ProceduralGeometry_get_name, NULL, "name" },
    { "props", (getter)ProceduralGeometry_get_props, NULL, "props" },
    { "element_id", (getter)ProceduralGeometry_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)ProceduralGeometry_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)ProceduralGeometry_get_instances, NULL, "instances" },
    { NULL },
};

static PyTypeObject ProceduralGeometry_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ProceduralGeometry",
    .tp_doc = PyDoc_STR("ProceduralGeometry"),
    .tp_basicsize = sizeof(ProceduralGeometry),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&ProceduralGeometry_dealloc,
    .tp_traverse = (traverseproc)&ProceduralGeometry_traverse,
    .tp_clear = (inquiry)&ProceduralGeometry_clear,
    .tp_getset = ProceduralGeometry_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_STEREO_CAMERA 7
enum {
    SLOT_STEREO_CAMERA__NAME,
    SLOT_STEREO_CAMERA__PROPS,
    SLOT_STEREO_CAMERA__ELEMENT_ID,
    SLOT_STEREO_CAMERA__TYPED_ID,
    SLOT_STEREO_CAMERA__INSTANCES,
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

static PyObject *StereoCamera_get_name(StereoCamera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_STEREO_CAMERA__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_STEREO_CAMERA__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *StereoCamera_get_props(StereoCamera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_STEREO_CAMERA__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_STEREO_CAMERA__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *StereoCamera_get_element_id(StereoCamera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_STEREO_CAMERA__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_STEREO_CAMERA__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *StereoCamera_get_typed_id(StereoCamera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_STEREO_CAMERA__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_STEREO_CAMERA__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *StereoCamera_get_instances(StereoCamera *self, void *closure) {
    PyObject *slot = self->slots[SLOT_STEREO_CAMERA__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_STEREO_CAMERA__INSTANCES] = slot;
    return Py_NewRef(slot);
}

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

static int StereoCamera_traverse(StereoCamera *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_STEREO_CAMERA; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int StereoCamera_clear(StereoCamera *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_STEREO_CAMERA; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void StereoCamera_dealloc(StereoCamera *self) {
    PyObject_GC_UnTrack(self);
    StereoCamera_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef StereoCamera_getset[] = {
    { "name", (getter)StereoCamera_get_name, NULL, "name" },
    { "props", (getter)StereoCamera_get_props, NULL, "props" },
    { "element_id", (getter)StereoCamera_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)StereoCamera_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)StereoCamera_get_instances, NULL, "instances" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&StereoCamera_dealloc,
    .tp_traverse = (traverseproc)&StereoCamera_traverse,
    .tp_clear = (inquiry)&StereoCamera_clear,
    .tp_getset = StereoCamera_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_CAMERA_SWITCHER 5
enum {
    SLOT_CAMERA_SWITCHER__NAME,
    SLOT_CAMERA_SWITCHER__PROPS,
    SLOT_CAMERA_SWITCHER__ELEMENT_ID,
    SLOT_CAMERA_SWITCHER__TYPED_ID,
    SLOT_CAMERA_SWITCHER__INSTANCES,
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
    PyObject *slots[SLOT_COUNT_CAMERA_SWITCHER];
} CameraSwitcher;

static PyObject *CameraSwitcher_get_name(CameraSwitcher *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA_SWITCHER__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_CAMERA_SWITCHER__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CameraSwitcher_get_props(CameraSwitcher *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA_SWITCHER__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_CAMERA_SWITCHER__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *CameraSwitcher_get_element_id(CameraSwitcher *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA_SWITCHER__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_CAMERA_SWITCHER__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *CameraSwitcher_get_typed_id(CameraSwitcher *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA_SWITCHER__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_CAMERA_SWITCHER__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *CameraSwitcher_get_instances(CameraSwitcher *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CAMERA_SWITCHER__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_CAMERA_SWITCHER__INSTANCES] = slot;
    return Py_NewRef(slot);
}

static int CameraSwitcher_traverse(CameraSwitcher *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CAMERA_SWITCHER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int CameraSwitcher_clear(CameraSwitcher *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CAMERA_SWITCHER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void CameraSwitcher_dealloc(CameraSwitcher *self) {
    PyObject_GC_UnTrack(self);
    CameraSwitcher_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef CameraSwitcher_getset[] = {
    { "name", (getter)CameraSwitcher_get_name, NULL, "name" },
    { "props", (getter)CameraSwitcher_get_props, NULL, "props" },
    { "element_id", (getter)CameraSwitcher_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)CameraSwitcher_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)CameraSwitcher_get_instances, NULL, "instances" },
    { NULL },
};

static PyTypeObject CameraSwitcher_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.CameraSwitcher",
    .tp_doc = PyDoc_STR("CameraSwitcher"),
    .tp_basicsize = sizeof(CameraSwitcher),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&CameraSwitcher_dealloc,
    .tp_traverse = (traverseproc)&CameraSwitcher_traverse,
    .tp_clear = (inquiry)&CameraSwitcher_clear,
    .tp_getset = CameraSwitcher_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_MARKER 6
enum {
    SLOT_MARKER__NAME,
    SLOT_MARKER__PROPS,
    SLOT_MARKER__ELEMENT_ID,
    SLOT_MARKER__TYPED_ID,
    SLOT_MARKER__INSTANCES,
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

static PyObject *Marker_get_name(Marker *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MARKER__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_MARKER__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Marker_get_props(Marker *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MARKER__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_MARKER__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Marker_get_element_id(Marker *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MARKER__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_MARKER__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Marker_get_typed_id(Marker *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MARKER__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_MARKER__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Marker_get_instances(Marker *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MARKER__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_MARKER__INSTANCES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Marker_get_type(Marker *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MARKER__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(MarkerType_Enum, "i", (int)self->data->type);
    self->slots[SLOT_MARKER__TYPE] = slot;
    return Py_NewRef(slot);
}

static int Marker_traverse(Marker *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_MARKER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Marker_clear(Marker *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_MARKER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Marker_dealloc(Marker *self) {
    PyObject_GC_UnTrack(self);
    Marker_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Marker_getset[] = {
    { "name", (getter)Marker_get_name, NULL, "name" },
    { "props", (getter)Marker_get_props, NULL, "props" },
    { "element_id", (getter)Marker_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Marker_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)Marker_get_instances, NULL, "instances" },
    { "type", (getter)Marker_get_type, NULL, "type" },
    { NULL },
};

static PyTypeObject Marker_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Marker",
    .tp_doc = PyDoc_STR("Marker"),
    .tp_basicsize = sizeof(Marker),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Marker_dealloc,
    .tp_traverse = (traverseproc)&Marker_traverse,
    .tp_clear = (inquiry)&Marker_clear,
    .tp_getset = Marker_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_LOD_GROUP 11
enum {
    SLOT_LOD_GROUP__NAME,
    SLOT_LOD_GROUP__PROPS,
    SLOT_LOD_GROUP__ELEMENT_ID,
    SLOT_LOD_GROUP__TYPED_ID,
    SLOT_LOD_GROUP__INSTANCES,
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

static PyObject *LodGroup_get_name(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_LOD_GROUP__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *LodGroup_get_props(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_LOD_GROUP__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *LodGroup_get_element_id(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_LOD_GROUP__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *LodGroup_get_typed_id(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_LOD_GROUP__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *LodGroup_get_instances(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__INSTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->instances, self->ctx);
    self->slots[SLOT_LOD_GROUP__INSTANCES] = slot;
    return Py_NewRef(slot);
}

static PyObject *LodGroup_get_relative_distances(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__RELATIVE_DISTANCES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->relative_distances ? Py_True : Py_False);
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
    slot = Py_NewRef(self->data->ignore_parent_transform ? Py_True : Py_False);
    self->slots[SLOT_LOD_GROUP__IGNORE_PARENT_TRANSFORM] = slot;
    return Py_NewRef(slot);
}

static PyObject *LodGroup_get_use_distance_limit(LodGroup *self, void *closure) {
    PyObject *slot = self->slots[SLOT_LOD_GROUP__USE_DISTANCE_LIMIT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->use_distance_limit ? Py_True : Py_False);
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

static int LodGroup_traverse(LodGroup *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_LOD_GROUP; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int LodGroup_clear(LodGroup *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_LOD_GROUP; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void LodGroup_dealloc(LodGroup *self) {
    PyObject_GC_UnTrack(self);
    LodGroup_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef LodGroup_getset[] = {
    { "name", (getter)LodGroup_get_name, NULL, "name" },
    { "props", (getter)LodGroup_get_props, NULL, "props" },
    { "element_id", (getter)LodGroup_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)LodGroup_get_typed_id, NULL, "typed_id" },
    { "instances", (getter)LodGroup_get_instances, NULL, "instances" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&LodGroup_dealloc,
    .tp_traverse = (traverseproc)&LodGroup_traverse,
    .tp_clear = (inquiry)&LodGroup_clear,
    .tp_getset = LodGroup_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_SKIN_DEFORMER 12
enum {
    SLOT_SKIN_DEFORMER__NAME,
    SLOT_SKIN_DEFORMER__PROPS,
    SLOT_SKIN_DEFORMER__ELEMENT_ID,
    SLOT_SKIN_DEFORMER__TYPED_ID,
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

static PyObject *SkinDeformer_get_name(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_SKIN_DEFORMER__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinDeformer_get_props(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_SKIN_DEFORMER__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinDeformer_get_element_id(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_SKIN_DEFORMER__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinDeformer_get_typed_id(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_SKIN_DEFORMER__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinDeformer_get_skinning_method(SkinDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_DEFORMER__SKINNING_METHOD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(SkinningMethod_Enum, "i", (int)self->data->skinning_method);
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

static int SkinDeformer_traverse(SkinDeformer *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SKIN_DEFORMER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int SkinDeformer_clear(SkinDeformer *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SKIN_DEFORMER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void SkinDeformer_dealloc(SkinDeformer *self) {
    PyObject_GC_UnTrack(self);
    SkinDeformer_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef SkinDeformer_getset[] = {
    { "name", (getter)SkinDeformer_get_name, NULL, "name" },
    { "props", (getter)SkinDeformer_get_props, NULL, "props" },
    { "element_id", (getter)SkinDeformer_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)SkinDeformer_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&SkinDeformer_dealloc,
    .tp_traverse = (traverseproc)&SkinDeformer_traverse,
    .tp_clear = (inquiry)&SkinDeformer_clear,
    .tp_getset = SkinDeformer_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_SKIN_CLUSTER 13
enum {
    SLOT_SKIN_CLUSTER__NAME,
    SLOT_SKIN_CLUSTER__PROPS,
    SLOT_SKIN_CLUSTER__ELEMENT_ID,
    SLOT_SKIN_CLUSTER__TYPED_ID,
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

static PyObject *SkinCluster_get_name(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_SKIN_CLUSTER__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_props(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_SKIN_CLUSTER__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_element_id(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_SKIN_CLUSTER__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_typed_id(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_SKIN_CLUSTER__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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
    slot = Matrix_from(&self->data->geometry_to_bone);
    self->slots[SLOT_SKIN_CLUSTER__GEOMETRY_TO_BONE] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_mesh_node_to_bone(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__MESH_NODE_TO_BONE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Matrix_from(&self->data->mesh_node_to_bone);
    self->slots[SLOT_SKIN_CLUSTER__MESH_NODE_TO_BONE] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_bind_to_world(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__BIND_TO_WORLD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Matrix_from(&self->data->bind_to_world);
    self->slots[SLOT_SKIN_CLUSTER__BIND_TO_WORLD] = slot;
    return Py_NewRef(slot);
}

static PyObject *SkinCluster_get_geometry_to_world(SkinCluster *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SKIN_CLUSTER__GEOMETRY_TO_WORLD];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Matrix_from(&self->data->geometry_to_world);
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

static int SkinCluster_traverse(SkinCluster *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SKIN_CLUSTER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int SkinCluster_clear(SkinCluster *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SKIN_CLUSTER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void SkinCluster_dealloc(SkinCluster *self) {
    PyObject_GC_UnTrack(self);
    SkinCluster_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef SkinCluster_getset[] = {
    { "name", (getter)SkinCluster_get_name, NULL, "name" },
    { "props", (getter)SkinCluster_get_props, NULL, "props" },
    { "element_id", (getter)SkinCluster_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)SkinCluster_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&SkinCluster_dealloc,
    .tp_traverse = (traverseproc)&SkinCluster_traverse,
    .tp_clear = (inquiry)&SkinCluster_clear,
    .tp_getset = SkinCluster_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_BLEND_DEFORMER 5
enum {
    SLOT_BLEND_DEFORMER__NAME,
    SLOT_BLEND_DEFORMER__PROPS,
    SLOT_BLEND_DEFORMER__ELEMENT_ID,
    SLOT_BLEND_DEFORMER__TYPED_ID,
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

static PyObject *BlendDeformer_get_name(BlendDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_DEFORMER__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_BLEND_DEFORMER__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendDeformer_get_props(BlendDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_DEFORMER__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_BLEND_DEFORMER__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendDeformer_get_element_id(BlendDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_DEFORMER__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_BLEND_DEFORMER__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendDeformer_get_typed_id(BlendDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_DEFORMER__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_BLEND_DEFORMER__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendDeformer_get_channels(BlendDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_DEFORMER__CHANNELS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BlendChannelList_from(self->data->channels, self->ctx);
    self->slots[SLOT_BLEND_DEFORMER__CHANNELS] = slot;
    return Py_NewRef(slot);
}

static int BlendDeformer_traverse(BlendDeformer *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_BLEND_DEFORMER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BlendDeformer_clear(BlendDeformer *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_BLEND_DEFORMER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BlendDeformer_dealloc(BlendDeformer *self) {
    PyObject_GC_UnTrack(self);
    BlendDeformer_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef BlendDeformer_getset[] = {
    { "name", (getter)BlendDeformer_get_name, NULL, "name" },
    { "props", (getter)BlendDeformer_get_props, NULL, "props" },
    { "element_id", (getter)BlendDeformer_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)BlendDeformer_get_typed_id, NULL, "typed_id" },
    { "channels", (getter)BlendDeformer_get_channels, NULL, "channels" },
    { NULL },
};

static PyObject *BlendDeformer_get_vertex_offset(PyObject *self, PyObject *args);

static PyMethodDef BlendDeformer_methods[] = {
    { "get_vertex_offset", &BlendDeformer_get_vertex_offset, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject BlendDeformer_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendDeformer",
    .tp_doc = PyDoc_STR("BlendDeformer"),
    .tp_basicsize = sizeof(BlendDeformer),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BlendDeformer_dealloc,
    .tp_traverse = (traverseproc)&BlendDeformer_traverse,
    .tp_clear = (inquiry)&BlendDeformer_clear,
    .tp_getset = BlendDeformer_getset,
    .tp_base = &Element_Type,
    .tp_methods = BlendDeformer_methods,
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

static int BlendKeyframe_traverse(BlendKeyframe *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BLEND_KEYFRAME; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BlendKeyframe_clear(BlendKeyframe *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BLEND_KEYFRAME; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BlendKeyframe_dealloc(BlendKeyframe *self) {
    PyObject_GC_UnTrack(self);
    BlendKeyframe_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BlendKeyframe_dealloc,
    .tp_traverse = (traverseproc)&BlendKeyframe_traverse,
    .tp_clear = (inquiry)&BlendKeyframe_clear,
    .tp_getset = BlendKeyframe_getset,
};

static PyObject *BlendKeyframe_from(ufbx_blend_keyframe *data, Context *ctx) {
    BlendKeyframe *obj = (BlendKeyframe*)PyObject_CallObject((PyObject*)&BlendKeyframe_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_BLEND_CHANNEL 7
enum {
    SLOT_BLEND_CHANNEL__NAME,
    SLOT_BLEND_CHANNEL__PROPS,
    SLOT_BLEND_CHANNEL__ELEMENT_ID,
    SLOT_BLEND_CHANNEL__TYPED_ID,
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

static PyObject *BlendChannel_get_name(BlendChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_CHANNEL__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_BLEND_CHANNEL__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendChannel_get_props(BlendChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_CHANNEL__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_BLEND_CHANNEL__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendChannel_get_element_id(BlendChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_CHANNEL__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_BLEND_CHANNEL__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendChannel_get_typed_id(BlendChannel *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_CHANNEL__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_BLEND_CHANNEL__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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

static int BlendChannel_traverse(BlendChannel *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_BLEND_CHANNEL; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BlendChannel_clear(BlendChannel *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_BLEND_CHANNEL; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BlendChannel_dealloc(BlendChannel *self) {
    PyObject_GC_UnTrack(self);
    BlendChannel_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef BlendChannel_getset[] = {
    { "name", (getter)BlendChannel_get_name, NULL, "name" },
    { "props", (getter)BlendChannel_get_props, NULL, "props" },
    { "element_id", (getter)BlendChannel_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)BlendChannel_get_typed_id, NULL, "typed_id" },
    { "weight", (getter)BlendChannel_get_weight, NULL, "weight" },
    { "keyframes", (getter)BlendChannel_get_keyframes, NULL, "keyframes" },
    { "target_shape", (getter)BlendChannel_get_target_shape, NULL, "target_shape" },
    { NULL },
};

static PyObject *BlendChannel_evaluate_blend_weight(PyObject *self, PyObject *args);

static PyMethodDef BlendChannel_methods[] = {
    { "evaluate_blend_weight", &BlendChannel_evaluate_blend_weight, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject BlendChannel_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendChannel",
    .tp_doc = PyDoc_STR("BlendChannel"),
    .tp_basicsize = sizeof(BlendChannel),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BlendChannel_dealloc,
    .tp_traverse = (traverseproc)&BlendChannel_traverse,
    .tp_clear = (inquiry)&BlendChannel_clear,
    .tp_getset = BlendChannel_getset,
    .tp_base = &Element_Type,
    .tp_methods = BlendChannel_methods,
};

#define SLOT_COUNT_BLEND_SHAPE 9
enum {
    SLOT_BLEND_SHAPE__NAME,
    SLOT_BLEND_SHAPE__PROPS,
    SLOT_BLEND_SHAPE__ELEMENT_ID,
    SLOT_BLEND_SHAPE__TYPED_ID,
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

static PyObject *BlendShape_get_name(BlendShape *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_SHAPE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_BLEND_SHAPE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendShape_get_props(BlendShape *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_SHAPE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_BLEND_SHAPE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendShape_get_element_id(BlendShape *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_SHAPE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_BLEND_SHAPE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *BlendShape_get_typed_id(BlendShape *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BLEND_SHAPE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_BLEND_SHAPE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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

static int BlendShape_traverse(BlendShape *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_BLEND_SHAPE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BlendShape_clear(BlendShape *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_BLEND_SHAPE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BlendShape_dealloc(BlendShape *self) {
    PyObject_GC_UnTrack(self);
    BlendShape_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef BlendShape_getset[] = {
    { "name", (getter)BlendShape_get_name, NULL, "name" },
    { "props", (getter)BlendShape_get_props, NULL, "props" },
    { "element_id", (getter)BlendShape_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)BlendShape_get_typed_id, NULL, "typed_id" },
    { "num_offsets", (getter)BlendShape_get_num_offsets, NULL, "num_offsets" },
    { "offset_vertices", (getter)BlendShape_get_offset_vertices, NULL, "offset_vertices" },
    { "position_offsets", (getter)BlendShape_get_position_offsets, NULL, "position_offsets" },
    { "normal_offsets", (getter)BlendShape_get_normal_offsets, NULL, "normal_offsets" },
    { "offset_weights", (getter)BlendShape_get_offset_weights, NULL, "offset_weights" },
    { NULL },
};

static PyObject *BlendShape_get_vertex_offset(PyObject *self, PyObject *args);

static PyMethodDef BlendShape_methods[] = {
    { "get_vertex_offset", &BlendShape_get_vertex_offset, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject BlendShape_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.BlendShape",
    .tp_doc = PyDoc_STR("BlendShape"),
    .tp_basicsize = sizeof(BlendShape),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BlendShape_dealloc,
    .tp_traverse = (traverseproc)&BlendShape_traverse,
    .tp_clear = (inquiry)&BlendShape_clear,
    .tp_getset = BlendShape_getset,
    .tp_base = &Element_Type,
    .tp_methods = BlendShape_methods,
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
    slot = PyObject_CallFunction(CacheFileFormat_Enum, "i", (int)self->data->file_format);
    self->slots[SLOT_CACHE_FRAME__FILE_FORMAT] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_mirror_axis(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__MIRROR_AXIS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(MirrorAxis_Enum, "i", (int)self->data->mirror_axis);
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
    slot = PyObject_CallFunction(CacheDataFormat_Enum, "i", (int)self->data->data_format);
    self->slots[SLOT_CACHE_FRAME__DATA_FORMAT] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFrame_get_data_encoding(CacheFrame *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FRAME__DATA_ENCODING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(CacheDataEncoding_Enum, "i", (int)self->data->data_encoding);
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

static int CacheFrame_traverse(CacheFrame *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_CACHE_FRAME; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int CacheFrame_clear(CacheFrame *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_CACHE_FRAME; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void CacheFrame_dealloc(CacheFrame *self) {
    PyObject_GC_UnTrack(self);
    CacheFrame_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&CacheFrame_dealloc,
    .tp_traverse = (traverseproc)&CacheFrame_traverse,
    .tp_clear = (inquiry)&CacheFrame_clear,
    .tp_getset = CacheFrame_getset,
};

static PyObject *CacheFrame_from(ufbx_cache_frame *data, Context *ctx) {
    CacheFrame *obj = (CacheFrame*)PyObject_CallObject((PyObject*)&CacheFrame_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = PyObject_CallFunction(CacheInterpretation_Enum, "i", (int)self->data->interpretation);
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
    slot = PyObject_CallFunction(MirrorAxis_Enum, "i", (int)self->data->mirror_axis);
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

static int CacheChannel_traverse(CacheChannel *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_CACHE_CHANNEL; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int CacheChannel_clear(CacheChannel *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_CACHE_CHANNEL; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void CacheChannel_dealloc(CacheChannel *self) {
    PyObject_GC_UnTrack(self);
    CacheChannel_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&CacheChannel_dealloc,
    .tp_traverse = (traverseproc)&CacheChannel_traverse,
    .tp_clear = (inquiry)&CacheChannel_clear,
    .tp_getset = CacheChannel_getset,
};

static PyObject *CacheChannel_from(ufbx_cache_channel *data, Context *ctx) {
    CacheChannel *obj = (CacheChannel*)PyObject_CallObject((PyObject*)&CacheChannel_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int GeometryCache_traverse(GeometryCache *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_GEOMETRY_CACHE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int GeometryCache_clear(GeometryCache *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_GEOMETRY_CACHE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void GeometryCache_dealloc(GeometryCache *self) {
    PyObject_GC_UnTrack(self);
    GeometryCache_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&GeometryCache_dealloc,
    .tp_traverse = (traverseproc)&GeometryCache_traverse,
    .tp_clear = (inquiry)&GeometryCache_clear,
    .tp_getset = GeometryCache_getset,
};

static PyObject *GeometryCache_from(ufbx_geometry_cache *data, Context *ctx) {
    GeometryCache *obj = (GeometryCache*)PyObject_CallObject((PyObject*)&GeometryCache_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_CACHE_DEFORMER 8
enum {
    SLOT_CACHE_DEFORMER__NAME,
    SLOT_CACHE_DEFORMER__PROPS,
    SLOT_CACHE_DEFORMER__ELEMENT_ID,
    SLOT_CACHE_DEFORMER__TYPED_ID,
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

static PyObject *CacheDeformer_get_name(CacheDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_DEFORMER__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_CACHE_DEFORMER__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheDeformer_get_props(CacheDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_DEFORMER__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_CACHE_DEFORMER__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheDeformer_get_element_id(CacheDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_DEFORMER__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_CACHE_DEFORMER__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheDeformer_get_typed_id(CacheDeformer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_DEFORMER__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_CACHE_DEFORMER__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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

static int CacheDeformer_traverse(CacheDeformer *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CACHE_DEFORMER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int CacheDeformer_clear(CacheDeformer *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CACHE_DEFORMER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void CacheDeformer_dealloc(CacheDeformer *self) {
    PyObject_GC_UnTrack(self);
    CacheDeformer_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef CacheDeformer_getset[] = {
    { "name", (getter)CacheDeformer_get_name, NULL, "name" },
    { "props", (getter)CacheDeformer_get_props, NULL, "props" },
    { "element_id", (getter)CacheDeformer_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)CacheDeformer_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&CacheDeformer_dealloc,
    .tp_traverse = (traverseproc)&CacheDeformer_traverse,
    .tp_clear = (inquiry)&CacheDeformer_clear,
    .tp_getset = CacheDeformer_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_CACHE_FILE 12
enum {
    SLOT_CACHE_FILE__NAME,
    SLOT_CACHE_FILE__PROPS,
    SLOT_CACHE_FILE__ELEMENT_ID,
    SLOT_CACHE_FILE__TYPED_ID,
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

static PyObject *CacheFile_get_name(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_CACHE_FILE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFile_get_props(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_CACHE_FILE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFile_get_element_id(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_CACHE_FILE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *CacheFile_get_typed_id(CacheFile *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CACHE_FILE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_CACHE_FILE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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
    slot = PyObject_CallFunction(CacheFileFormat_Enum, "i", (int)self->data->format);
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

static int CacheFile_traverse(CacheFile *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CACHE_FILE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int CacheFile_clear(CacheFile *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CACHE_FILE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void CacheFile_dealloc(CacheFile *self) {
    PyObject_GC_UnTrack(self);
    CacheFile_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef CacheFile_getset[] = {
    { "name", (getter)CacheFile_get_name, NULL, "name" },
    { "props", (getter)CacheFile_get_props, NULL, "props" },
    { "element_id", (getter)CacheFile_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)CacheFile_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&CacheFile_dealloc,
    .tp_traverse = (traverseproc)&CacheFile_traverse,
    .tp_clear = (inquiry)&CacheFile_clear,
    .tp_getset = CacheFile_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_MATERIAL_MAP 7
enum {
    SLOT_MATERIAL_MAP__VALUE_VEC4,
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

static PyObject *MaterialMap_get_value_vec4(MaterialMap *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_MAP__VALUE_VEC4];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec4_from(&self->data->value_vec4);
    self->slots[SLOT_MATERIAL_MAP__VALUE_VEC4] = slot;
    return Py_NewRef(slot);
}

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
    slot = Py_NewRef(self->data->has_value ? Py_True : Py_False);
    self->slots[SLOT_MATERIAL_MAP__HAS_VALUE] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialMap_get_texture_enabled(MaterialMap *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_MAP__TEXTURE_ENABLED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->texture_enabled ? Py_True : Py_False);
    self->slots[SLOT_MATERIAL_MAP__TEXTURE_ENABLED] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialMap_get_feature_disabled(MaterialMap *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_MAP__FEATURE_DISABLED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->feature_disabled ? Py_True : Py_False);
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

static int MaterialMap_traverse(MaterialMap *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_MAP; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int MaterialMap_clear(MaterialMap *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_MAP; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void MaterialMap_dealloc(MaterialMap *self) {
    PyObject_GC_UnTrack(self);
    MaterialMap_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef MaterialMap_getset[] = {
    { "value_vec4", (getter)MaterialMap_get_value_vec4, NULL, "value_vec4" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&MaterialMap_dealloc,
    .tp_traverse = (traverseproc)&MaterialMap_traverse,
    .tp_clear = (inquiry)&MaterialMap_clear,
    .tp_getset = MaterialMap_getset,
};

static PyObject *MaterialMap_from(ufbx_material_map *data, Context *ctx) {
    MaterialMap *obj = (MaterialMap*)PyObject_CallObject((PyObject*)&MaterialMap_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->enabled ? Py_True : Py_False);
    self->slots[SLOT_MATERIAL_FEATURE_INFO__ENABLED] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatureInfo_get_is_explicit(MaterialFeatureInfo *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURE_INFO__IS_EXPLICIT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->is_explicit ? Py_True : Py_False);
    self->slots[SLOT_MATERIAL_FEATURE_INFO__IS_EXPLICIT] = slot;
    return Py_NewRef(slot);
}

static int MaterialFeatureInfo_traverse(MaterialFeatureInfo *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_FEATURE_INFO; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int MaterialFeatureInfo_clear(MaterialFeatureInfo *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_FEATURE_INFO; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void MaterialFeatureInfo_dealloc(MaterialFeatureInfo *self) {
    PyObject_GC_UnTrack(self);
    MaterialFeatureInfo_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&MaterialFeatureInfo_dealloc,
    .tp_traverse = (traverseproc)&MaterialFeatureInfo_traverse,
    .tp_clear = (inquiry)&MaterialFeatureInfo_clear,
    .tp_getset = MaterialFeatureInfo_getset,
};

static PyObject *MaterialFeatureInfo_from(ufbx_material_feature_info *data, Context *ctx) {
    MaterialFeatureInfo *obj = (MaterialFeatureInfo*)PyObject_CallObject((PyObject*)&MaterialFeatureInfo_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int MaterialTexture_traverse(MaterialTexture *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_TEXTURE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int MaterialTexture_clear(MaterialTexture *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_TEXTURE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void MaterialTexture_dealloc(MaterialTexture *self) {
    PyObject_GC_UnTrack(self);
    MaterialTexture_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&MaterialTexture_dealloc,
    .tp_traverse = (traverseproc)&MaterialTexture_traverse,
    .tp_clear = (inquiry)&MaterialTexture_clear,
    .tp_getset = MaterialTexture_getset,
};

static PyObject *MaterialTexture_from(ufbx_material_texture *data, Context *ctx) {
    MaterialTexture *obj = (MaterialTexture*)PyObject_CallObject((PyObject*)&MaterialTexture_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_MATERIAL_FBX_MAPS 20
enum {
    SLOT_MATERIAL_FBX_MAPS__DIFFUSE_FACTOR,
    SLOT_MATERIAL_FBX_MAPS__DIFFUSE_COLOR,
    SLOT_MATERIAL_FBX_MAPS__SPECULAR_FACTOR,
    SLOT_MATERIAL_FBX_MAPS__SPECULAR_COLOR,
    SLOT_MATERIAL_FBX_MAPS__SPECULAR_EXPONENT,
    SLOT_MATERIAL_FBX_MAPS__REFLECTION_FACTOR,
    SLOT_MATERIAL_FBX_MAPS__REFLECTION_COLOR,
    SLOT_MATERIAL_FBX_MAPS__TRANSPARENCY_FACTOR,
    SLOT_MATERIAL_FBX_MAPS__TRANSPARENCY_COLOR,
    SLOT_MATERIAL_FBX_MAPS__EMISSION_FACTOR,
    SLOT_MATERIAL_FBX_MAPS__EMISSION_COLOR,
    SLOT_MATERIAL_FBX_MAPS__AMBIENT_FACTOR,
    SLOT_MATERIAL_FBX_MAPS__AMBIENT_COLOR,
    SLOT_MATERIAL_FBX_MAPS__NORMAL_MAP,
    SLOT_MATERIAL_FBX_MAPS__BUMP,
    SLOT_MATERIAL_FBX_MAPS__BUMP_FACTOR,
    SLOT_MATERIAL_FBX_MAPS__DISPLACEMENT_FACTOR,
    SLOT_MATERIAL_FBX_MAPS__DISPLACEMENT,
    SLOT_MATERIAL_FBX_MAPS__VECTOR_DISPLACEMENT_FACTOR,
    SLOT_MATERIAL_FBX_MAPS__VECTOR_DISPLACEMENT,
};

typedef struct {
    PyObject_HEAD
    ufbx_material_fbx_maps *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_MATERIAL_FBX_MAPS];
} MaterialFbxMaps;

static PyObject *MaterialFbxMaps_get_diffuse_factor(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__DIFFUSE_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->diffuse_factor, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__DIFFUSE_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_diffuse_color(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__DIFFUSE_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->diffuse_color, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__DIFFUSE_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_specular_factor(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__SPECULAR_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->specular_factor, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__SPECULAR_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_specular_color(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__SPECULAR_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->specular_color, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__SPECULAR_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_specular_exponent(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__SPECULAR_EXPONENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->specular_exponent, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__SPECULAR_EXPONENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_reflection_factor(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__REFLECTION_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->reflection_factor, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__REFLECTION_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_reflection_color(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__REFLECTION_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->reflection_color, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__REFLECTION_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_transparency_factor(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__TRANSPARENCY_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transparency_factor, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__TRANSPARENCY_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_transparency_color(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__TRANSPARENCY_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transparency_color, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__TRANSPARENCY_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_emission_factor(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__EMISSION_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->emission_factor, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__EMISSION_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_emission_color(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__EMISSION_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->emission_color, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__EMISSION_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_ambient_factor(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__AMBIENT_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->ambient_factor, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__AMBIENT_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_ambient_color(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__AMBIENT_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->ambient_color, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__AMBIENT_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_normal_map(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__NORMAL_MAP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->normal_map, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__NORMAL_MAP] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_bump(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__BUMP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->bump, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__BUMP] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_bump_factor(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__BUMP_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->bump_factor, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__BUMP_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_displacement_factor(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__DISPLACEMENT_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->displacement_factor, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__DISPLACEMENT_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_displacement(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__DISPLACEMENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->displacement, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__DISPLACEMENT] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_vector_displacement_factor(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__VECTOR_DISPLACEMENT_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->vector_displacement_factor, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__VECTOR_DISPLACEMENT_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFbxMaps_get_vector_displacement(MaterialFbxMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FBX_MAPS__VECTOR_DISPLACEMENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->vector_displacement, self->ctx);
    self->slots[SLOT_MATERIAL_FBX_MAPS__VECTOR_DISPLACEMENT] = slot;
    return Py_NewRef(slot);
}

static int MaterialFbxMaps_traverse(MaterialFbxMaps *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_FBX_MAPS; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int MaterialFbxMaps_clear(MaterialFbxMaps *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_FBX_MAPS; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void MaterialFbxMaps_dealloc(MaterialFbxMaps *self) {
    PyObject_GC_UnTrack(self);
    MaterialFbxMaps_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef MaterialFbxMaps_getset[] = {
    { "diffuse_factor", (getter)MaterialFbxMaps_get_diffuse_factor, NULL, "diffuse_factor" },
    { "diffuse_color", (getter)MaterialFbxMaps_get_diffuse_color, NULL, "diffuse_color" },
    { "specular_factor", (getter)MaterialFbxMaps_get_specular_factor, NULL, "specular_factor" },
    { "specular_color", (getter)MaterialFbxMaps_get_specular_color, NULL, "specular_color" },
    { "specular_exponent", (getter)MaterialFbxMaps_get_specular_exponent, NULL, "specular_exponent" },
    { "reflection_factor", (getter)MaterialFbxMaps_get_reflection_factor, NULL, "reflection_factor" },
    { "reflection_color", (getter)MaterialFbxMaps_get_reflection_color, NULL, "reflection_color" },
    { "transparency_factor", (getter)MaterialFbxMaps_get_transparency_factor, NULL, "transparency_factor" },
    { "transparency_color", (getter)MaterialFbxMaps_get_transparency_color, NULL, "transparency_color" },
    { "emission_factor", (getter)MaterialFbxMaps_get_emission_factor, NULL, "emission_factor" },
    { "emission_color", (getter)MaterialFbxMaps_get_emission_color, NULL, "emission_color" },
    { "ambient_factor", (getter)MaterialFbxMaps_get_ambient_factor, NULL, "ambient_factor" },
    { "ambient_color", (getter)MaterialFbxMaps_get_ambient_color, NULL, "ambient_color" },
    { "normal_map", (getter)MaterialFbxMaps_get_normal_map, NULL, "normal_map" },
    { "bump", (getter)MaterialFbxMaps_get_bump, NULL, "bump" },
    { "bump_factor", (getter)MaterialFbxMaps_get_bump_factor, NULL, "bump_factor" },
    { "displacement_factor", (getter)MaterialFbxMaps_get_displacement_factor, NULL, "displacement_factor" },
    { "displacement", (getter)MaterialFbxMaps_get_displacement, NULL, "displacement" },
    { "vector_displacement_factor", (getter)MaterialFbxMaps_get_vector_displacement_factor, NULL, "vector_displacement_factor" },
    { "vector_displacement", (getter)MaterialFbxMaps_get_vector_displacement, NULL, "vector_displacement" },
    { NULL },
};

static PyTypeObject MaterialFbxMaps_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialFbxMaps",
    .tp_doc = PyDoc_STR("MaterialFbxMaps"),
    .tp_basicsize = sizeof(MaterialFbxMaps),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&MaterialFbxMaps_dealloc,
    .tp_traverse = (traverseproc)&MaterialFbxMaps_traverse,
    .tp_clear = (inquiry)&MaterialFbxMaps_clear,
    .tp_getset = MaterialFbxMaps_getset,
};

static PyObject *MaterialFbxMaps_from(ufbx_material_fbx_maps *data, Context *ctx) {
    MaterialFbxMaps *obj = (MaterialFbxMaps*)PyObject_CallObject((PyObject*)&MaterialFbxMaps_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_MATERIAL_PBR_MAPS 56
enum {
    SLOT_MATERIAL_PBR_MAPS__BASE_FACTOR,
    SLOT_MATERIAL_PBR_MAPS__BASE_COLOR,
    SLOT_MATERIAL_PBR_MAPS__ROUGHNESS,
    SLOT_MATERIAL_PBR_MAPS__METALNESS,
    SLOT_MATERIAL_PBR_MAPS__DIFFUSE_ROUGHNESS,
    SLOT_MATERIAL_PBR_MAPS__SPECULAR_FACTOR,
    SLOT_MATERIAL_PBR_MAPS__SPECULAR_COLOR,
    SLOT_MATERIAL_PBR_MAPS__SPECULAR_IOR,
    SLOT_MATERIAL_PBR_MAPS__SPECULAR_ANISOTROPY,
    SLOT_MATERIAL_PBR_MAPS__SPECULAR_ROTATION,
    SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_FACTOR,
    SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_COLOR,
    SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_DEPTH,
    SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_SCATTER,
    SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_SCATTER_ANISOTROPY,
    SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_DISPERSION,
    SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_ROUGHNESS,
    SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_EXTRA_ROUGHNESS,
    SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_PRIORITY,
    SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_ENABLE_IN_AOV,
    SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_FACTOR,
    SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_COLOR,
    SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_RADIUS,
    SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_SCALE,
    SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_ANISOTROPY,
    SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_TINT_COLOR,
    SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_TYPE,
    SLOT_MATERIAL_PBR_MAPS__SHEEN_FACTOR,
    SLOT_MATERIAL_PBR_MAPS__SHEEN_COLOR,
    SLOT_MATERIAL_PBR_MAPS__SHEEN_ROUGHNESS,
    SLOT_MATERIAL_PBR_MAPS__COAT_FACTOR,
    SLOT_MATERIAL_PBR_MAPS__COAT_COLOR,
    SLOT_MATERIAL_PBR_MAPS__COAT_ROUGHNESS,
    SLOT_MATERIAL_PBR_MAPS__COAT_IOR,
    SLOT_MATERIAL_PBR_MAPS__COAT_ANISOTROPY,
    SLOT_MATERIAL_PBR_MAPS__COAT_ROTATION,
    SLOT_MATERIAL_PBR_MAPS__COAT_NORMAL,
    SLOT_MATERIAL_PBR_MAPS__COAT_AFFECT_BASE_COLOR,
    SLOT_MATERIAL_PBR_MAPS__COAT_AFFECT_BASE_ROUGHNESS,
    SLOT_MATERIAL_PBR_MAPS__THIN_FILM_FACTOR,
    SLOT_MATERIAL_PBR_MAPS__THIN_FILM_THICKNESS,
    SLOT_MATERIAL_PBR_MAPS__THIN_FILM_IOR,
    SLOT_MATERIAL_PBR_MAPS__EMISSION_FACTOR,
    SLOT_MATERIAL_PBR_MAPS__EMISSION_COLOR,
    SLOT_MATERIAL_PBR_MAPS__OPACITY,
    SLOT_MATERIAL_PBR_MAPS__INDIRECT_DIFFUSE,
    SLOT_MATERIAL_PBR_MAPS__INDIRECT_SPECULAR,
    SLOT_MATERIAL_PBR_MAPS__NORMAL_MAP,
    SLOT_MATERIAL_PBR_MAPS__TANGENT_MAP,
    SLOT_MATERIAL_PBR_MAPS__DISPLACEMENT_MAP,
    SLOT_MATERIAL_PBR_MAPS__MATTE_FACTOR,
    SLOT_MATERIAL_PBR_MAPS__MATTE_COLOR,
    SLOT_MATERIAL_PBR_MAPS__AMBIENT_OCCLUSION,
    SLOT_MATERIAL_PBR_MAPS__GLOSSINESS,
    SLOT_MATERIAL_PBR_MAPS__COAT_GLOSSINESS,
    SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_GLOSSINESS,
};

typedef struct {
    PyObject_HEAD
    ufbx_material_pbr_maps *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_MATERIAL_PBR_MAPS];
} MaterialPbrMaps;

static PyObject *MaterialPbrMaps_get_base_factor(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__BASE_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->base_factor, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__BASE_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_base_color(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__BASE_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->base_color, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__BASE_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_roughness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__ROUGHNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->roughness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__ROUGHNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_metalness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__METALNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->metalness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__METALNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_diffuse_roughness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__DIFFUSE_ROUGHNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->diffuse_roughness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__DIFFUSE_ROUGHNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_specular_factor(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SPECULAR_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->specular_factor, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SPECULAR_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_specular_color(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SPECULAR_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->specular_color, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SPECULAR_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_specular_ior(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SPECULAR_IOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->specular_ior, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SPECULAR_IOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_specular_anisotropy(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SPECULAR_ANISOTROPY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->specular_anisotropy, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SPECULAR_ANISOTROPY] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_specular_rotation(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SPECULAR_ROTATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->specular_rotation, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SPECULAR_ROTATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_transmission_factor(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transmission_factor, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_transmission_color(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transmission_color, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_transmission_depth(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_DEPTH];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transmission_depth, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_DEPTH] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_transmission_scatter(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_SCATTER];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transmission_scatter, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_SCATTER] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_transmission_scatter_anisotropy(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_SCATTER_ANISOTROPY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transmission_scatter_anisotropy, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_SCATTER_ANISOTROPY] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_transmission_dispersion(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_DISPERSION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transmission_dispersion, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_DISPERSION] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_transmission_roughness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_ROUGHNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transmission_roughness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_ROUGHNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_transmission_extra_roughness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_EXTRA_ROUGHNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transmission_extra_roughness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_EXTRA_ROUGHNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_transmission_priority(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_PRIORITY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transmission_priority, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_PRIORITY] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_transmission_enable_in_aov(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_ENABLE_IN_AOV];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transmission_enable_in_aov, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_ENABLE_IN_AOV] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_subsurface_factor(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->subsurface_factor, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_subsurface_color(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->subsurface_color, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_subsurface_radius(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_RADIUS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->subsurface_radius, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_RADIUS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_subsurface_scale(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->subsurface_scale, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_SCALE] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_subsurface_anisotropy(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_ANISOTROPY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->subsurface_anisotropy, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_ANISOTROPY] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_subsurface_tint_color(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_TINT_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->subsurface_tint_color, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_TINT_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_subsurface_type(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->subsurface_type, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SUBSURFACE_TYPE] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_sheen_factor(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SHEEN_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->sheen_factor, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SHEEN_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_sheen_color(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SHEEN_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->sheen_color, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SHEEN_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_sheen_roughness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__SHEEN_ROUGHNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->sheen_roughness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__SHEEN_ROUGHNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_coat_factor(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->coat_factor, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_coat_color(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->coat_color, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_coat_roughness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_ROUGHNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->coat_roughness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_ROUGHNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_coat_ior(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_IOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->coat_ior, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_IOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_coat_anisotropy(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_ANISOTROPY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->coat_anisotropy, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_ANISOTROPY] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_coat_rotation(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_ROTATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->coat_rotation, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_ROTATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_coat_normal(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_NORMAL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->coat_normal, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_NORMAL] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_coat_affect_base_color(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_AFFECT_BASE_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->coat_affect_base_color, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_AFFECT_BASE_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_coat_affect_base_roughness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_AFFECT_BASE_ROUGHNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->coat_affect_base_roughness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_AFFECT_BASE_ROUGHNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_thin_film_factor(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__THIN_FILM_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->thin_film_factor, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__THIN_FILM_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_thin_film_thickness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__THIN_FILM_THICKNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->thin_film_thickness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__THIN_FILM_THICKNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_thin_film_ior(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__THIN_FILM_IOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->thin_film_ior, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__THIN_FILM_IOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_emission_factor(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__EMISSION_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->emission_factor, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__EMISSION_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_emission_color(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__EMISSION_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->emission_color, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__EMISSION_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_opacity(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__OPACITY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->opacity, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__OPACITY] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_indirect_diffuse(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__INDIRECT_DIFFUSE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->indirect_diffuse, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__INDIRECT_DIFFUSE] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_indirect_specular(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__INDIRECT_SPECULAR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->indirect_specular, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__INDIRECT_SPECULAR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_normal_map(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__NORMAL_MAP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->normal_map, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__NORMAL_MAP] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_tangent_map(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TANGENT_MAP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->tangent_map, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TANGENT_MAP] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_displacement_map(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__DISPLACEMENT_MAP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->displacement_map, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__DISPLACEMENT_MAP] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_matte_factor(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__MATTE_FACTOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->matte_factor, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__MATTE_FACTOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_matte_color(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__MATTE_COLOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->matte_color, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__MATTE_COLOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_ambient_occlusion(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__AMBIENT_OCCLUSION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->ambient_occlusion, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__AMBIENT_OCCLUSION] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_glossiness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__GLOSSINESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->glossiness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__GLOSSINESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_coat_glossiness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_GLOSSINESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->coat_glossiness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__COAT_GLOSSINESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialPbrMaps_get_transmission_glossiness(MaterialPbrMaps *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_GLOSSINESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialMap_from(&self->data->transmission_glossiness, self->ctx);
    self->slots[SLOT_MATERIAL_PBR_MAPS__TRANSMISSION_GLOSSINESS] = slot;
    return Py_NewRef(slot);
}

static int MaterialPbrMaps_traverse(MaterialPbrMaps *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_PBR_MAPS; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int MaterialPbrMaps_clear(MaterialPbrMaps *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_PBR_MAPS; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void MaterialPbrMaps_dealloc(MaterialPbrMaps *self) {
    PyObject_GC_UnTrack(self);
    MaterialPbrMaps_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef MaterialPbrMaps_getset[] = {
    { "base_factor", (getter)MaterialPbrMaps_get_base_factor, NULL, "base_factor" },
    { "base_color", (getter)MaterialPbrMaps_get_base_color, NULL, "base_color" },
    { "roughness", (getter)MaterialPbrMaps_get_roughness, NULL, "roughness" },
    { "metalness", (getter)MaterialPbrMaps_get_metalness, NULL, "metalness" },
    { "diffuse_roughness", (getter)MaterialPbrMaps_get_diffuse_roughness, NULL, "diffuse_roughness" },
    { "specular_factor", (getter)MaterialPbrMaps_get_specular_factor, NULL, "specular_factor" },
    { "specular_color", (getter)MaterialPbrMaps_get_specular_color, NULL, "specular_color" },
    { "specular_ior", (getter)MaterialPbrMaps_get_specular_ior, NULL, "specular_ior" },
    { "specular_anisotropy", (getter)MaterialPbrMaps_get_specular_anisotropy, NULL, "specular_anisotropy" },
    { "specular_rotation", (getter)MaterialPbrMaps_get_specular_rotation, NULL, "specular_rotation" },
    { "transmission_factor", (getter)MaterialPbrMaps_get_transmission_factor, NULL, "transmission_factor" },
    { "transmission_color", (getter)MaterialPbrMaps_get_transmission_color, NULL, "transmission_color" },
    { "transmission_depth", (getter)MaterialPbrMaps_get_transmission_depth, NULL, "transmission_depth" },
    { "transmission_scatter", (getter)MaterialPbrMaps_get_transmission_scatter, NULL, "transmission_scatter" },
    { "transmission_scatter_anisotropy", (getter)MaterialPbrMaps_get_transmission_scatter_anisotropy, NULL, "transmission_scatter_anisotropy" },
    { "transmission_dispersion", (getter)MaterialPbrMaps_get_transmission_dispersion, NULL, "transmission_dispersion" },
    { "transmission_roughness", (getter)MaterialPbrMaps_get_transmission_roughness, NULL, "transmission_roughness" },
    { "transmission_extra_roughness", (getter)MaterialPbrMaps_get_transmission_extra_roughness, NULL, "transmission_extra_roughness" },
    { "transmission_priority", (getter)MaterialPbrMaps_get_transmission_priority, NULL, "transmission_priority" },
    { "transmission_enable_in_aov", (getter)MaterialPbrMaps_get_transmission_enable_in_aov, NULL, "transmission_enable_in_aov" },
    { "subsurface_factor", (getter)MaterialPbrMaps_get_subsurface_factor, NULL, "subsurface_factor" },
    { "subsurface_color", (getter)MaterialPbrMaps_get_subsurface_color, NULL, "subsurface_color" },
    { "subsurface_radius", (getter)MaterialPbrMaps_get_subsurface_radius, NULL, "subsurface_radius" },
    { "subsurface_scale", (getter)MaterialPbrMaps_get_subsurface_scale, NULL, "subsurface_scale" },
    { "subsurface_anisotropy", (getter)MaterialPbrMaps_get_subsurface_anisotropy, NULL, "subsurface_anisotropy" },
    { "subsurface_tint_color", (getter)MaterialPbrMaps_get_subsurface_tint_color, NULL, "subsurface_tint_color" },
    { "subsurface_type", (getter)MaterialPbrMaps_get_subsurface_type, NULL, "subsurface_type" },
    { "sheen_factor", (getter)MaterialPbrMaps_get_sheen_factor, NULL, "sheen_factor" },
    { "sheen_color", (getter)MaterialPbrMaps_get_sheen_color, NULL, "sheen_color" },
    { "sheen_roughness", (getter)MaterialPbrMaps_get_sheen_roughness, NULL, "sheen_roughness" },
    { "coat_factor", (getter)MaterialPbrMaps_get_coat_factor, NULL, "coat_factor" },
    { "coat_color", (getter)MaterialPbrMaps_get_coat_color, NULL, "coat_color" },
    { "coat_roughness", (getter)MaterialPbrMaps_get_coat_roughness, NULL, "coat_roughness" },
    { "coat_ior", (getter)MaterialPbrMaps_get_coat_ior, NULL, "coat_ior" },
    { "coat_anisotropy", (getter)MaterialPbrMaps_get_coat_anisotropy, NULL, "coat_anisotropy" },
    { "coat_rotation", (getter)MaterialPbrMaps_get_coat_rotation, NULL, "coat_rotation" },
    { "coat_normal", (getter)MaterialPbrMaps_get_coat_normal, NULL, "coat_normal" },
    { "coat_affect_base_color", (getter)MaterialPbrMaps_get_coat_affect_base_color, NULL, "coat_affect_base_color" },
    { "coat_affect_base_roughness", (getter)MaterialPbrMaps_get_coat_affect_base_roughness, NULL, "coat_affect_base_roughness" },
    { "thin_film_factor", (getter)MaterialPbrMaps_get_thin_film_factor, NULL, "thin_film_factor" },
    { "thin_film_thickness", (getter)MaterialPbrMaps_get_thin_film_thickness, NULL, "thin_film_thickness" },
    { "thin_film_ior", (getter)MaterialPbrMaps_get_thin_film_ior, NULL, "thin_film_ior" },
    { "emission_factor", (getter)MaterialPbrMaps_get_emission_factor, NULL, "emission_factor" },
    { "emission_color", (getter)MaterialPbrMaps_get_emission_color, NULL, "emission_color" },
    { "opacity", (getter)MaterialPbrMaps_get_opacity, NULL, "opacity" },
    { "indirect_diffuse", (getter)MaterialPbrMaps_get_indirect_diffuse, NULL, "indirect_diffuse" },
    { "indirect_specular", (getter)MaterialPbrMaps_get_indirect_specular, NULL, "indirect_specular" },
    { "normal_map", (getter)MaterialPbrMaps_get_normal_map, NULL, "normal_map" },
    { "tangent_map", (getter)MaterialPbrMaps_get_tangent_map, NULL, "tangent_map" },
    { "displacement_map", (getter)MaterialPbrMaps_get_displacement_map, NULL, "displacement_map" },
    { "matte_factor", (getter)MaterialPbrMaps_get_matte_factor, NULL, "matte_factor" },
    { "matte_color", (getter)MaterialPbrMaps_get_matte_color, NULL, "matte_color" },
    { "ambient_occlusion", (getter)MaterialPbrMaps_get_ambient_occlusion, NULL, "ambient_occlusion" },
    { "glossiness", (getter)MaterialPbrMaps_get_glossiness, NULL, "glossiness" },
    { "coat_glossiness", (getter)MaterialPbrMaps_get_coat_glossiness, NULL, "coat_glossiness" },
    { "transmission_glossiness", (getter)MaterialPbrMaps_get_transmission_glossiness, NULL, "transmission_glossiness" },
    { NULL },
};

static PyTypeObject MaterialPbrMaps_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialPbrMaps",
    .tp_doc = PyDoc_STR("MaterialPbrMaps"),
    .tp_basicsize = sizeof(MaterialPbrMaps),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&MaterialPbrMaps_dealloc,
    .tp_traverse = (traverseproc)&MaterialPbrMaps_traverse,
    .tp_clear = (inquiry)&MaterialPbrMaps_clear,
    .tp_getset = MaterialPbrMaps_getset,
};

static PyObject *MaterialPbrMaps_from(ufbx_material_pbr_maps *data, Context *ctx) {
    MaterialPbrMaps *obj = (MaterialPbrMaps*)PyObject_CallObject((PyObject*)&MaterialPbrMaps_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_MATERIAL_FEATURES 23
enum {
    SLOT_MATERIAL_FEATURES__PBR,
    SLOT_MATERIAL_FEATURES__METALNESS,
    SLOT_MATERIAL_FEATURES__DIFFUSE,
    SLOT_MATERIAL_FEATURES__SPECULAR,
    SLOT_MATERIAL_FEATURES__EMISSION,
    SLOT_MATERIAL_FEATURES__TRANSMISSION,
    SLOT_MATERIAL_FEATURES__COAT,
    SLOT_MATERIAL_FEATURES__SHEEN,
    SLOT_MATERIAL_FEATURES__OPACITY,
    SLOT_MATERIAL_FEATURES__AMBIENT_OCCLUSION,
    SLOT_MATERIAL_FEATURES__MATTE,
    SLOT_MATERIAL_FEATURES__UNLIT,
    SLOT_MATERIAL_FEATURES__IOR,
    SLOT_MATERIAL_FEATURES__DIFFUSE_ROUGHNESS,
    SLOT_MATERIAL_FEATURES__TRANSMISSION_ROUGHNESS,
    SLOT_MATERIAL_FEATURES__THIN_WALLED,
    SLOT_MATERIAL_FEATURES__CAUSTICS,
    SLOT_MATERIAL_FEATURES__EXIT_TO_BACKGROUND,
    SLOT_MATERIAL_FEATURES__INTERNAL_REFLECTIONS,
    SLOT_MATERIAL_FEATURES__DOUBLE_SIDED,
    SLOT_MATERIAL_FEATURES__ROUGHNESS_AS_GLOSSINESS,
    SLOT_MATERIAL_FEATURES__COAT_ROUGHNESS_AS_GLOSSINESS,
    SLOT_MATERIAL_FEATURES__TRANSMISSION_ROUGHNESS_AS_GLOSSINESS,
};

typedef struct {
    PyObject_HEAD
    ufbx_material_features *data;
    Context *ctx;
    PyObject *slots[SLOT_COUNT_MATERIAL_FEATURES];
} MaterialFeatures;

static PyObject *MaterialFeatures_get_pbr(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__PBR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->pbr, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__PBR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_metalness(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__METALNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->metalness, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__METALNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_diffuse(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__DIFFUSE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->diffuse, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__DIFFUSE] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_specular(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__SPECULAR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->specular, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__SPECULAR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_emission(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__EMISSION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->emission, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__EMISSION] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_transmission(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__TRANSMISSION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->transmission, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__TRANSMISSION] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_coat(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__COAT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->coat, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__COAT] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_sheen(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__SHEEN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->sheen, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__SHEEN] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_opacity(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__OPACITY];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->opacity, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__OPACITY] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_ambient_occlusion(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__AMBIENT_OCCLUSION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->ambient_occlusion, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__AMBIENT_OCCLUSION] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_matte(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__MATTE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->matte, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__MATTE] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_unlit(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__UNLIT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->unlit, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__UNLIT] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_ior(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__IOR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->ior, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__IOR] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_diffuse_roughness(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__DIFFUSE_ROUGHNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->diffuse_roughness, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__DIFFUSE_ROUGHNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_transmission_roughness(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__TRANSMISSION_ROUGHNESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->transmission_roughness, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__TRANSMISSION_ROUGHNESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_thin_walled(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__THIN_WALLED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->thin_walled, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__THIN_WALLED] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_caustics(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__CAUSTICS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->caustics, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__CAUSTICS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_exit_to_background(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__EXIT_TO_BACKGROUND];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->exit_to_background, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__EXIT_TO_BACKGROUND] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_internal_reflections(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__INTERNAL_REFLECTIONS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->internal_reflections, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__INTERNAL_REFLECTIONS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_double_sided(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__DOUBLE_SIDED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->double_sided, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__DOUBLE_SIDED] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_roughness_as_glossiness(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__ROUGHNESS_AS_GLOSSINESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->roughness_as_glossiness, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__ROUGHNESS_AS_GLOSSINESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_coat_roughness_as_glossiness(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__COAT_ROUGHNESS_AS_GLOSSINESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->coat_roughness_as_glossiness, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__COAT_ROUGHNESS_AS_GLOSSINESS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MaterialFeatures_get_transmission_roughness_as_glossiness(MaterialFeatures *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL_FEATURES__TRANSMISSION_ROUGHNESS_AS_GLOSSINESS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatureInfo_from(&self->data->transmission_roughness_as_glossiness, self->ctx);
    self->slots[SLOT_MATERIAL_FEATURES__TRANSMISSION_ROUGHNESS_AS_GLOSSINESS] = slot;
    return Py_NewRef(slot);
}

static int MaterialFeatures_traverse(MaterialFeatures *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_FEATURES; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int MaterialFeatures_clear(MaterialFeatures *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL_FEATURES; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void MaterialFeatures_dealloc(MaterialFeatures *self) {
    PyObject_GC_UnTrack(self);
    MaterialFeatures_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef MaterialFeatures_getset[] = {
    { "pbr", (getter)MaterialFeatures_get_pbr, NULL, "pbr" },
    { "metalness", (getter)MaterialFeatures_get_metalness, NULL, "metalness" },
    { "diffuse", (getter)MaterialFeatures_get_diffuse, NULL, "diffuse" },
    { "specular", (getter)MaterialFeatures_get_specular, NULL, "specular" },
    { "emission", (getter)MaterialFeatures_get_emission, NULL, "emission" },
    { "transmission", (getter)MaterialFeatures_get_transmission, NULL, "transmission" },
    { "coat", (getter)MaterialFeatures_get_coat, NULL, "coat" },
    { "sheen", (getter)MaterialFeatures_get_sheen, NULL, "sheen" },
    { "opacity", (getter)MaterialFeatures_get_opacity, NULL, "opacity" },
    { "ambient_occlusion", (getter)MaterialFeatures_get_ambient_occlusion, NULL, "ambient_occlusion" },
    { "matte", (getter)MaterialFeatures_get_matte, NULL, "matte" },
    { "unlit", (getter)MaterialFeatures_get_unlit, NULL, "unlit" },
    { "ior", (getter)MaterialFeatures_get_ior, NULL, "ior" },
    { "diffuse_roughness", (getter)MaterialFeatures_get_diffuse_roughness, NULL, "diffuse_roughness" },
    { "transmission_roughness", (getter)MaterialFeatures_get_transmission_roughness, NULL, "transmission_roughness" },
    { "thin_walled", (getter)MaterialFeatures_get_thin_walled, NULL, "thin_walled" },
    { "caustics", (getter)MaterialFeatures_get_caustics, NULL, "caustics" },
    { "exit_to_background", (getter)MaterialFeatures_get_exit_to_background, NULL, "exit_to_background" },
    { "internal_reflections", (getter)MaterialFeatures_get_internal_reflections, NULL, "internal_reflections" },
    { "double_sided", (getter)MaterialFeatures_get_double_sided, NULL, "double_sided" },
    { "roughness_as_glossiness", (getter)MaterialFeatures_get_roughness_as_glossiness, NULL, "roughness_as_glossiness" },
    { "coat_roughness_as_glossiness", (getter)MaterialFeatures_get_coat_roughness_as_glossiness, NULL, "coat_roughness_as_glossiness" },
    { "transmission_roughness_as_glossiness", (getter)MaterialFeatures_get_transmission_roughness_as_glossiness, NULL, "transmission_roughness_as_glossiness" },
    { NULL },
};

static PyTypeObject MaterialFeatures_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MaterialFeatures",
    .tp_doc = PyDoc_STR("MaterialFeatures"),
    .tp_basicsize = sizeof(MaterialFeatures),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&MaterialFeatures_dealloc,
    .tp_traverse = (traverseproc)&MaterialFeatures_traverse,
    .tp_clear = (inquiry)&MaterialFeatures_clear,
    .tp_getset = MaterialFeatures_getset,
};

static PyObject *MaterialFeatures_from(ufbx_material_features *data, Context *ctx) {
    MaterialFeatures *obj = (MaterialFeatures*)PyObject_CallObject((PyObject*)&MaterialFeatures_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_MATERIAL 12
enum {
    SLOT_MATERIAL__NAME,
    SLOT_MATERIAL__PROPS,
    SLOT_MATERIAL__ELEMENT_ID,
    SLOT_MATERIAL__TYPED_ID,
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

static PyObject *Material_get_name(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_MATERIAL__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_props(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_MATERIAL__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_element_id(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_MATERIAL__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_typed_id(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_MATERIAL__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_fbx(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__FBX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFbxMaps_from(&self->data->fbx, self->ctx);
    self->slots[SLOT_MATERIAL__FBX] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_pbr(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__PBR];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialPbrMaps_from(&self->data->pbr, self->ctx);
    self->slots[SLOT_MATERIAL__PBR] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_features(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__FEATURES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialFeatures_from(&self->data->features, self->ctx);
    self->slots[SLOT_MATERIAL__FEATURES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Material_get_shader_type(Material *self, void *closure) {
    PyObject *slot = self->slots[SLOT_MATERIAL__SHADER_TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(ShaderType_Enum, "i", (int)self->data->shader_type);
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

static int Material_traverse(Material *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Material_clear(Material *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_MATERIAL; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Material_dealloc(Material *self) {
    PyObject_GC_UnTrack(self);
    Material_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Material_getset[] = {
    { "name", (getter)Material_get_name, NULL, "name" },
    { "props", (getter)Material_get_props, NULL, "props" },
    { "element_id", (getter)Material_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Material_get_typed_id, NULL, "typed_id" },
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

static PyObject *Material_find_prop_texture(PyObject *self, PyObject *args);

static PyMethodDef Material_methods[] = {
    { "find_prop_texture", &Material_find_prop_texture, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject Material_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Material",
    .tp_doc = PyDoc_STR("Material"),
    .tp_basicsize = sizeof(Material),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Material_dealloc,
    .tp_traverse = (traverseproc)&Material_traverse,
    .tp_clear = (inquiry)&Material_clear,
    .tp_getset = Material_getset,
    .tp_base = &Element_Type,
    .tp_methods = Material_methods,
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
    slot = PyObject_CallFunction(BlendMode_Enum, "i", (int)self->data->blend_mode);
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

static int TextureLayer_traverse(TextureLayer *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_TEXTURE_LAYER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int TextureLayer_clear(TextureLayer *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_TEXTURE_LAYER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void TextureLayer_dealloc(TextureLayer *self) {
    PyObject_GC_UnTrack(self);
    TextureLayer_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&TextureLayer_dealloc,
    .tp_traverse = (traverseproc)&TextureLayer_traverse,
    .tp_clear = (inquiry)&TextureLayer_clear,
    .tp_getset = TextureLayer_getset,
};

static PyObject *TextureLayer_from(ufbx_texture_layer *data, Context *ctx) {
    TextureLayer *obj = (TextureLayer*)PyObject_CallObject((PyObject*)&TextureLayer_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_SHADER_TEXTURE_INPUT 11
enum {
    SLOT_SHADER_TEXTURE_INPUT__NAME,
    SLOT_SHADER_TEXTURE_INPUT__VALUE_VEC4,
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

static PyObject *ShaderTextureInput_get_value_vec4(ShaderTextureInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_TEXTURE_INPUT__VALUE_VEC4];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Vec4_from(&self->data->value_vec4);
    self->slots[SLOT_SHADER_TEXTURE_INPUT__VALUE_VEC4] = slot;
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
    slot = Py_NewRef(self->data->texture_enabled ? Py_True : Py_False);
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

static int ShaderTextureInput_traverse(ShaderTextureInput *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SHADER_TEXTURE_INPUT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int ShaderTextureInput_clear(ShaderTextureInput *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SHADER_TEXTURE_INPUT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void ShaderTextureInput_dealloc(ShaderTextureInput *self) {
    PyObject_GC_UnTrack(self);
    ShaderTextureInput_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef ShaderTextureInput_getset[] = {
    { "name", (getter)ShaderTextureInput_get_name, NULL, "name" },
    { "value_vec4", (getter)ShaderTextureInput_get_value_vec4, NULL, "value_vec4" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&ShaderTextureInput_dealloc,
    .tp_traverse = (traverseproc)&ShaderTextureInput_traverse,
    .tp_clear = (inquiry)&ShaderTextureInput_clear,
    .tp_getset = ShaderTextureInput_getset,
};

static PyObject *ShaderTextureInput_from(ufbx_shader_texture_input *data, Context *ctx) {
    ShaderTextureInput *obj = (ShaderTextureInput*)PyObject_CallObject((PyObject*)&ShaderTextureInput_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = PyObject_CallFunction(ShaderTextureType_Enum, "i", (int)self->data->type);
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

static int ShaderTexture_traverse(ShaderTexture *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SHADER_TEXTURE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int ShaderTexture_clear(ShaderTexture *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SHADER_TEXTURE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void ShaderTexture_dealloc(ShaderTexture *self) {
    PyObject_GC_UnTrack(self);
    ShaderTexture_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&ShaderTexture_dealloc,
    .tp_traverse = (traverseproc)&ShaderTexture_traverse,
    .tp_clear = (inquiry)&ShaderTexture_clear,
    .tp_getset = ShaderTexture_getset,
};

static PyObject *ShaderTexture_from(ufbx_shader_texture *data, Context *ctx) {
    ShaderTexture *obj = (ShaderTexture*)PyObject_CallObject((PyObject*)&ShaderTexture_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int TextureFile_traverse(TextureFile *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_TEXTURE_FILE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int TextureFile_clear(TextureFile *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_TEXTURE_FILE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void TextureFile_dealloc(TextureFile *self) {
    PyObject_GC_UnTrack(self);
    TextureFile_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&TextureFile_dealloc,
    .tp_traverse = (traverseproc)&TextureFile_traverse,
    .tp_clear = (inquiry)&TextureFile_clear,
    .tp_getset = TextureFile_getset,
};

static PyObject *TextureFile_from(ufbx_texture_file *data, Context *ctx) {
    TextureFile *obj = (TextureFile*)PyObject_CallObject((PyObject*)&TextureFile_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_TEXTURE 25
enum {
    SLOT_TEXTURE__NAME,
    SLOT_TEXTURE__PROPS,
    SLOT_TEXTURE__ELEMENT_ID,
    SLOT_TEXTURE__TYPED_ID,
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

static PyObject *Texture_get_name(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_TEXTURE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_props(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_TEXTURE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_element_id(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_TEXTURE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_typed_id(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_TEXTURE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_type(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(TextureType_Enum, "i", (int)self->data->type);
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
    slot = Py_NewRef(self->data->has_file ? Py_True : Py_False);
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
    slot = PyObject_CallFunction(WrapMode_Enum, "i", (int)self->data->wrap_u);
    self->slots[SLOT_TEXTURE__WRAP_U] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_wrap_v(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__WRAP_V];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(WrapMode_Enum, "i", (int)self->data->wrap_v);
    self->slots[SLOT_TEXTURE__WRAP_V] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_has_uv_transform(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__HAS_UV_TRANSFORM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->has_uv_transform ? Py_True : Py_False);
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
    slot = Matrix_from(&self->data->texture_to_uv);
    self->slots[SLOT_TEXTURE__TEXTURE_TO_UV] = slot;
    return Py_NewRef(slot);
}

static PyObject *Texture_get_uv_to_texture(Texture *self, void *closure) {
    PyObject *slot = self->slots[SLOT_TEXTURE__UV_TO_TEXTURE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Matrix_from(&self->data->uv_to_texture);
    self->slots[SLOT_TEXTURE__UV_TO_TEXTURE] = slot;
    return Py_NewRef(slot);
}

static int Texture_traverse(Texture *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_TEXTURE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Texture_clear(Texture *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_TEXTURE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Texture_dealloc(Texture *self) {
    PyObject_GC_UnTrack(self);
    Texture_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Texture_getset[] = {
    { "name", (getter)Texture_get_name, NULL, "name" },
    { "props", (getter)Texture_get_props, NULL, "props" },
    { "element_id", (getter)Texture_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Texture_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Texture_dealloc,
    .tp_traverse = (traverseproc)&Texture_traverse,
    .tp_clear = (inquiry)&Texture_clear,
    .tp_getset = Texture_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_VIDEO 11
enum {
    SLOT_VIDEO__NAME,
    SLOT_VIDEO__PROPS,
    SLOT_VIDEO__ELEMENT_ID,
    SLOT_VIDEO__TYPED_ID,
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

static PyObject *Video_get_name(Video *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VIDEO__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_VIDEO__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Video_get_props(Video *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VIDEO__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_VIDEO__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Video_get_element_id(Video *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VIDEO__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_VIDEO__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Video_get_typed_id(Video *self, void *closure) {
    PyObject *slot = self->slots[SLOT_VIDEO__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_VIDEO__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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

static int Video_traverse(Video *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_VIDEO; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Video_clear(Video *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_VIDEO; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Video_dealloc(Video *self) {
    PyObject_GC_UnTrack(self);
    Video_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Video_getset[] = {
    { "name", (getter)Video_get_name, NULL, "name" },
    { "props", (getter)Video_get_props, NULL, "props" },
    { "element_id", (getter)Video_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Video_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Video_dealloc,
    .tp_traverse = (traverseproc)&Video_traverse,
    .tp_clear = (inquiry)&Video_clear,
    .tp_getset = Video_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_SHADER 6
enum {
    SLOT_SHADER__NAME,
    SLOT_SHADER__PROPS,
    SLOT_SHADER__ELEMENT_ID,
    SLOT_SHADER__TYPED_ID,
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

static PyObject *Shader_get_name(Shader *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_SHADER__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Shader_get_props(Shader *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_SHADER__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Shader_get_element_id(Shader *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_SHADER__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Shader_get_typed_id(Shader *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_SHADER__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Shader_get_type(Shader *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(ShaderType_Enum, "i", (int)self->data->type);
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

static int Shader_traverse(Shader *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SHADER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Shader_clear(Shader *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SHADER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Shader_dealloc(Shader *self) {
    PyObject_GC_UnTrack(self);
    Shader_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Shader_getset[] = {
    { "name", (getter)Shader_get_name, NULL, "name" },
    { "props", (getter)Shader_get_props, NULL, "props" },
    { "element_id", (getter)Shader_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Shader_get_typed_id, NULL, "typed_id" },
    { "type", (getter)Shader_get_type, NULL, "type" },
    { "bindings", (getter)Shader_get_bindings, NULL, "bindings" },
    { NULL },
};

static PyObject *Shader_find_shader_prop(PyObject *self, PyObject *args);

static PyMethodDef Shader_methods[] = {
    { "find_shader_prop", &Shader_find_shader_prop, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject Shader_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Shader",
    .tp_doc = PyDoc_STR("Shader"),
    .tp_basicsize = sizeof(Shader),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Shader_dealloc,
    .tp_traverse = (traverseproc)&Shader_traverse,
    .tp_clear = (inquiry)&Shader_clear,
    .tp_getset = Shader_getset,
    .tp_base = &Element_Type,
    .tp_methods = Shader_methods,
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

static int ShaderPropBinding_traverse(ShaderPropBinding *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SHADER_PROP_BINDING; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int ShaderPropBinding_clear(ShaderPropBinding *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SHADER_PROP_BINDING; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void ShaderPropBinding_dealloc(ShaderPropBinding *self) {
    PyObject_GC_UnTrack(self);
    ShaderPropBinding_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&ShaderPropBinding_dealloc,
    .tp_traverse = (traverseproc)&ShaderPropBinding_traverse,
    .tp_clear = (inquiry)&ShaderPropBinding_clear,
    .tp_getset = ShaderPropBinding_getset,
};

static PyObject *ShaderPropBinding_from(ufbx_shader_prop_binding *data, Context *ctx) {
    ShaderPropBinding *obj = (ShaderPropBinding*)PyObject_CallObject((PyObject*)&ShaderPropBinding_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_SHADER_BINDING 5
enum {
    SLOT_SHADER_BINDING__NAME,
    SLOT_SHADER_BINDING__PROPS,
    SLOT_SHADER_BINDING__ELEMENT_ID,
    SLOT_SHADER_BINDING__TYPED_ID,
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

static PyObject *ShaderBinding_get_name(ShaderBinding *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_BINDING__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_SHADER_BINDING__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderBinding_get_props(ShaderBinding *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_BINDING__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_SHADER_BINDING__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderBinding_get_element_id(ShaderBinding *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_BINDING__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_SHADER_BINDING__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderBinding_get_typed_id(ShaderBinding *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_BINDING__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_SHADER_BINDING__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *ShaderBinding_get_prop_bindings(ShaderBinding *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SHADER_BINDING__PROP_BINDINGS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ShaderPropBindingList_from(self->data->prop_bindings, self->ctx);
    self->slots[SLOT_SHADER_BINDING__PROP_BINDINGS] = slot;
    return Py_NewRef(slot);
}

static int ShaderBinding_traverse(ShaderBinding *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SHADER_BINDING; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int ShaderBinding_clear(ShaderBinding *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SHADER_BINDING; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void ShaderBinding_dealloc(ShaderBinding *self) {
    PyObject_GC_UnTrack(self);
    ShaderBinding_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef ShaderBinding_getset[] = {
    { "name", (getter)ShaderBinding_get_name, NULL, "name" },
    { "props", (getter)ShaderBinding_get_props, NULL, "props" },
    { "element_id", (getter)ShaderBinding_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)ShaderBinding_get_typed_id, NULL, "typed_id" },
    { "prop_bindings", (getter)ShaderBinding_get_prop_bindings, NULL, "prop_bindings" },
    { NULL },
};

static PyTypeObject ShaderBinding_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.ShaderBinding",
    .tp_doc = PyDoc_STR("ShaderBinding"),
    .tp_basicsize = sizeof(ShaderBinding),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&ShaderBinding_dealloc,
    .tp_traverse = (traverseproc)&ShaderBinding_traverse,
    .tp_clear = (inquiry)&ShaderBinding_clear,
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

static int PropOverride_traverse(PropOverride *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_PROP_OVERRIDE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int PropOverride_clear(PropOverride *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_PROP_OVERRIDE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void PropOverride_dealloc(PropOverride *self) {
    PyObject_GC_UnTrack(self);
    PropOverride_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&PropOverride_dealloc,
    .tp_traverse = (traverseproc)&PropOverride_traverse,
    .tp_clear = (inquiry)&PropOverride_clear,
    .tp_getset = PropOverride_getset,
};

static PyObject *PropOverride_from(ufbx_prop_override *data, Context *ctx) {
    PropOverride *obj = (PropOverride*)PyObject_CallObject((PyObject*)&PropOverride_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->ignore_connections ? Py_True : Py_False);
    self->slots[SLOT_ANIM__IGNORE_CONNECTIONS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Anim_get_custom(Anim *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM__CUSTOM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->custom ? Py_True : Py_False);
    self->slots[SLOT_ANIM__CUSTOM] = slot;
    return Py_NewRef(slot);
}

static int Anim_traverse(Anim *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_ANIM; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Anim_clear(Anim *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_ANIM; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Anim_dealloc(Anim *self) {
    PyObject_GC_UnTrack(self);
    Anim_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Anim_dealloc,
    .tp_traverse = (traverseproc)&Anim_traverse,
    .tp_clear = (inquiry)&Anim_clear,
    .tp_getset = Anim_getset,
};

static PyObject *Anim_from(ufbx_anim *data, Context *ctx) {
    Anim *obj = (Anim*)PyObject_CallObject((PyObject*)&Anim_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_ANIM_STACK 8
enum {
    SLOT_ANIM_STACK__NAME,
    SLOT_ANIM_STACK__PROPS,
    SLOT_ANIM_STACK__ELEMENT_ID,
    SLOT_ANIM_STACK__TYPED_ID,
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

static PyObject *AnimStack_get_name(AnimStack *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_STACK__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_ANIM_STACK__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimStack_get_props(AnimStack *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_STACK__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_ANIM_STACK__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimStack_get_element_id(AnimStack *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_STACK__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_ANIM_STACK__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimStack_get_typed_id(AnimStack *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_STACK__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_ANIM_STACK__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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

static int AnimStack_traverse(AnimStack *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_ANIM_STACK; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int AnimStack_clear(AnimStack *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_ANIM_STACK; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void AnimStack_dealloc(AnimStack *self) {
    PyObject_GC_UnTrack(self);
    AnimStack_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef AnimStack_getset[] = {
    { "name", (getter)AnimStack_get_name, NULL, "name" },
    { "props", (getter)AnimStack_get_props, NULL, "props" },
    { "element_id", (getter)AnimStack_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)AnimStack_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&AnimStack_dealloc,
    .tp_traverse = (traverseproc)&AnimStack_traverse,
    .tp_clear = (inquiry)&AnimStack_clear,
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

static int AnimProp_traverse(AnimProp *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_ANIM_PROP; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int AnimProp_clear(AnimProp *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_ANIM_PROP; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void AnimProp_dealloc(AnimProp *self) {
    PyObject_GC_UnTrack(self);
    AnimProp_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&AnimProp_dealloc,
    .tp_traverse = (traverseproc)&AnimProp_traverse,
    .tp_clear = (inquiry)&AnimProp_clear,
    .tp_getset = AnimProp_getset,
};

static PyObject *AnimProp_from(ufbx_anim_prop *data, Context *ctx) {
    AnimProp *obj = (AnimProp*)PyObject_CallObject((PyObject*)&AnimProp_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_ANIM_LAYER 13
enum {
    SLOT_ANIM_LAYER__NAME,
    SLOT_ANIM_LAYER__PROPS,
    SLOT_ANIM_LAYER__ELEMENT_ID,
    SLOT_ANIM_LAYER__TYPED_ID,
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

static PyObject *AnimLayer_get_name(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_ANIM_LAYER__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_props(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_ANIM_LAYER__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_element_id(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_ANIM_LAYER__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_typed_id(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_ANIM_LAYER__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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
    slot = Py_NewRef(self->data->weight_is_animated ? Py_True : Py_False);
    self->slots[SLOT_ANIM_LAYER__WEIGHT_IS_ANIMATED] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_blended(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__BLENDED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->blended ? Py_True : Py_False);
    self->slots[SLOT_ANIM_LAYER__BLENDED] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_additive(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__ADDITIVE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->additive ? Py_True : Py_False);
    self->slots[SLOT_ANIM_LAYER__ADDITIVE] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_compose_rotation(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__COMPOSE_ROTATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->compose_rotation ? Py_True : Py_False);
    self->slots[SLOT_ANIM_LAYER__COMPOSE_ROTATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimLayer_get_compose_scale(AnimLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_LAYER__COMPOSE_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->compose_scale ? Py_True : Py_False);
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

static int AnimLayer_traverse(AnimLayer *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_ANIM_LAYER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int AnimLayer_clear(AnimLayer *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_ANIM_LAYER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void AnimLayer_dealloc(AnimLayer *self) {
    PyObject_GC_UnTrack(self);
    AnimLayer_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef AnimLayer_getset[] = {
    { "name", (getter)AnimLayer_get_name, NULL, "name" },
    { "props", (getter)AnimLayer_get_props, NULL, "props" },
    { "element_id", (getter)AnimLayer_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)AnimLayer_get_typed_id, NULL, "typed_id" },
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

static PyObject *AnimLayer_find_anim_prop(PyObject *self, PyObject *args);
static PyObject *AnimLayer_find_anim_props(PyObject *self, PyObject *args);

static PyMethodDef AnimLayer_methods[] = {
    { "find_anim_prop", &AnimLayer_find_anim_prop, METH_VARARGS, NULL },
    { "find_anim_props", &AnimLayer_find_anim_props, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject AnimLayer_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimLayer",
    .tp_doc = PyDoc_STR("AnimLayer"),
    .tp_basicsize = sizeof(AnimLayer),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&AnimLayer_dealloc,
    .tp_traverse = (traverseproc)&AnimLayer_traverse,
    .tp_clear = (inquiry)&AnimLayer_clear,
    .tp_getset = AnimLayer_getset,
    .tp_base = &Element_Type,
    .tp_methods = AnimLayer_methods,
};

#define SLOT_COUNT_ANIM_VALUE 6
enum {
    SLOT_ANIM_VALUE__NAME,
    SLOT_ANIM_VALUE__PROPS,
    SLOT_ANIM_VALUE__ELEMENT_ID,
    SLOT_ANIM_VALUE__TYPED_ID,
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

static PyObject *AnimValue_get_name(AnimValue *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_VALUE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_ANIM_VALUE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimValue_get_props(AnimValue *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_VALUE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_ANIM_VALUE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimValue_get_element_id(AnimValue *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_VALUE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_ANIM_VALUE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimValue_get_typed_id(AnimValue *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_VALUE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_ANIM_VALUE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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

static int AnimValue_traverse(AnimValue *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_ANIM_VALUE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int AnimValue_clear(AnimValue *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_ANIM_VALUE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void AnimValue_dealloc(AnimValue *self) {
    PyObject_GC_UnTrack(self);
    AnimValue_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef AnimValue_getset[] = {
    { "name", (getter)AnimValue_get_name, NULL, "name" },
    { "props", (getter)AnimValue_get_props, NULL, "props" },
    { "element_id", (getter)AnimValue_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)AnimValue_get_typed_id, NULL, "typed_id" },
    { "default_value", (getter)AnimValue_get_default_value, NULL, "default_value" },
    { "curves", (getter)AnimValue_get_curves, NULL, "curves" },
    { NULL },
};

static PyObject *AnimValue_evaluate_real(PyObject *self, PyObject *args);
static PyObject *AnimValue_evaluate_vec3(PyObject *self, PyObject *args);

static PyMethodDef AnimValue_methods[] = {
    { "evaluate_real", &AnimValue_evaluate_real, METH_VARARGS, NULL },
    { "evaluate_vec3", &AnimValue_evaluate_vec3, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject AnimValue_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimValue",
    .tp_doc = PyDoc_STR("AnimValue"),
    .tp_basicsize = sizeof(AnimValue),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&AnimValue_dealloc,
    .tp_traverse = (traverseproc)&AnimValue_traverse,
    .tp_clear = (inquiry)&AnimValue_clear,
    .tp_getset = AnimValue_getset,
    .tp_base = &Element_Type,
    .tp_methods = AnimValue_methods,
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
    slot = PyObject_CallFunction(ExtrapolationMode_Enum, "i", (int)self->data->mode);
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

static int Extrapolation_traverse(Extrapolation *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_EXTRAPOLATION; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Extrapolation_clear(Extrapolation *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_EXTRAPOLATION; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Extrapolation_dealloc(Extrapolation *self) {
    PyObject_GC_UnTrack(self);
    Extrapolation_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Extrapolation_dealloc,
    .tp_traverse = (traverseproc)&Extrapolation_traverse,
    .tp_clear = (inquiry)&Extrapolation_clear,
    .tp_getset = Extrapolation_getset,
};

static PyObject *Extrapolation_from(ufbx_extrapolation *data, Context *ctx) {
    Extrapolation *obj = (Extrapolation*)PyObject_CallObject((PyObject*)&Extrapolation_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_ANIM_CURVE 11
enum {
    SLOT_ANIM_CURVE__NAME,
    SLOT_ANIM_CURVE__PROPS,
    SLOT_ANIM_CURVE__ELEMENT_ID,
    SLOT_ANIM_CURVE__TYPED_ID,
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

static PyObject *AnimCurve_get_name(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_ANIM_CURVE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimCurve_get_props(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_ANIM_CURVE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimCurve_get_element_id(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_ANIM_CURVE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimCurve_get_typed_id(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_ANIM_CURVE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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
    slot = Extrapolation_from(&self->data->pre_extrapolation, self->ctx);
    self->slots[SLOT_ANIM_CURVE__PRE_EXTRAPOLATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *AnimCurve_get_post_extrapolation(AnimCurve *self, void *closure) {
    PyObject *slot = self->slots[SLOT_ANIM_CURVE__POST_EXTRAPOLATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Extrapolation_from(&self->data->post_extrapolation, self->ctx);
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

static int AnimCurve_traverse(AnimCurve *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_ANIM_CURVE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int AnimCurve_clear(AnimCurve *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_ANIM_CURVE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void AnimCurve_dealloc(AnimCurve *self) {
    PyObject_GC_UnTrack(self);
    AnimCurve_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef AnimCurve_getset[] = {
    { "name", (getter)AnimCurve_get_name, NULL, "name" },
    { "props", (getter)AnimCurve_get_props, NULL, "props" },
    { "element_id", (getter)AnimCurve_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)AnimCurve_get_typed_id, NULL, "typed_id" },
    { "keyframes", (getter)AnimCurve_get_keyframes, NULL, "keyframes" },
    { "pre_extrapolation", (getter)AnimCurve_get_pre_extrapolation, NULL, "pre_extrapolation" },
    { "post_extrapolation", (getter)AnimCurve_get_post_extrapolation, NULL, "post_extrapolation" },
    { "min_value", (getter)AnimCurve_get_min_value, NULL, "min_value" },
    { "max_value", (getter)AnimCurve_get_max_value, NULL, "max_value" },
    { "min_time", (getter)AnimCurve_get_min_time, NULL, "min_time" },
    { "max_time", (getter)AnimCurve_get_max_time, NULL, "max_time" },
    { NULL },
};

static PyObject *AnimCurve_evaluate(PyObject *self, PyObject *args);

static PyMethodDef AnimCurve_methods[] = {
    { "evaluate", &AnimCurve_evaluate, METH_VARARGS, NULL },
    { NULL },
};

static PyTypeObject AnimCurve_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AnimCurve",
    .tp_doc = PyDoc_STR("AnimCurve"),
    .tp_basicsize = sizeof(AnimCurve),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&AnimCurve_dealloc,
    .tp_traverse = (traverseproc)&AnimCurve_traverse,
    .tp_clear = (inquiry)&AnimCurve_clear,
    .tp_getset = AnimCurve_getset,
    .tp_base = &Element_Type,
    .tp_methods = AnimCurve_methods,
};

#define SLOT_COUNT_DISPLAY_LAYER 8
enum {
    SLOT_DISPLAY_LAYER__NAME,
    SLOT_DISPLAY_LAYER__PROPS,
    SLOT_DISPLAY_LAYER__ELEMENT_ID,
    SLOT_DISPLAY_LAYER__TYPED_ID,
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

static PyObject *DisplayLayer_get_name(DisplayLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DISPLAY_LAYER__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_DISPLAY_LAYER__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *DisplayLayer_get_props(DisplayLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DISPLAY_LAYER__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_DISPLAY_LAYER__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *DisplayLayer_get_element_id(DisplayLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DISPLAY_LAYER__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_DISPLAY_LAYER__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *DisplayLayer_get_typed_id(DisplayLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DISPLAY_LAYER__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_DISPLAY_LAYER__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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
    slot = Py_NewRef(self->data->visible ? Py_True : Py_False);
    self->slots[SLOT_DISPLAY_LAYER__VISIBLE] = slot;
    return Py_NewRef(slot);
}

static PyObject *DisplayLayer_get_frozen(DisplayLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_DISPLAY_LAYER__FROZEN];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->frozen ? Py_True : Py_False);
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

static int DisplayLayer_traverse(DisplayLayer *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_DISPLAY_LAYER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int DisplayLayer_clear(DisplayLayer *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_DISPLAY_LAYER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void DisplayLayer_dealloc(DisplayLayer *self) {
    PyObject_GC_UnTrack(self);
    DisplayLayer_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef DisplayLayer_getset[] = {
    { "name", (getter)DisplayLayer_get_name, NULL, "name" },
    { "props", (getter)DisplayLayer_get_props, NULL, "props" },
    { "element_id", (getter)DisplayLayer_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)DisplayLayer_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&DisplayLayer_dealloc,
    .tp_traverse = (traverseproc)&DisplayLayer_traverse,
    .tp_clear = (inquiry)&DisplayLayer_clear,
    .tp_getset = DisplayLayer_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_SELECTION_SET 5
enum {
    SLOT_SELECTION_SET__NAME,
    SLOT_SELECTION_SET__PROPS,
    SLOT_SELECTION_SET__ELEMENT_ID,
    SLOT_SELECTION_SET__TYPED_ID,
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

static PyObject *SelectionSet_get_name(SelectionSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_SET__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_SELECTION_SET__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionSet_get_props(SelectionSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_SET__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_SELECTION_SET__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionSet_get_element_id(SelectionSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_SET__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_SELECTION_SET__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionSet_get_typed_id(SelectionSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_SET__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_SELECTION_SET__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionSet_get_nodes(SelectionSet *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_SET__NODES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SelectionNodeList_from(self->data->nodes, self->ctx);
    self->slots[SLOT_SELECTION_SET__NODES] = slot;
    return Py_NewRef(slot);
}

static int SelectionSet_traverse(SelectionSet *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SELECTION_SET; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int SelectionSet_clear(SelectionSet *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SELECTION_SET; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void SelectionSet_dealloc(SelectionSet *self) {
    PyObject_GC_UnTrack(self);
    SelectionSet_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef SelectionSet_getset[] = {
    { "name", (getter)SelectionSet_get_name, NULL, "name" },
    { "props", (getter)SelectionSet_get_props, NULL, "props" },
    { "element_id", (getter)SelectionSet_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)SelectionSet_get_typed_id, NULL, "typed_id" },
    { "nodes", (getter)SelectionSet_get_nodes, NULL, "nodes" },
    { NULL },
};

static PyTypeObject SelectionSet_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.SelectionSet",
    .tp_doc = PyDoc_STR("SelectionSet"),
    .tp_basicsize = sizeof(SelectionSet),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&SelectionSet_dealloc,
    .tp_traverse = (traverseproc)&SelectionSet_traverse,
    .tp_clear = (inquiry)&SelectionSet_clear,
    .tp_getset = SelectionSet_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_SELECTION_NODE 10
enum {
    SLOT_SELECTION_NODE__NAME,
    SLOT_SELECTION_NODE__PROPS,
    SLOT_SELECTION_NODE__ELEMENT_ID,
    SLOT_SELECTION_NODE__TYPED_ID,
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

static PyObject *SelectionNode_get_name(SelectionNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_NODE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_SELECTION_NODE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionNode_get_props(SelectionNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_NODE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_SELECTION_NODE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionNode_get_element_id(SelectionNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_NODE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_SELECTION_NODE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *SelectionNode_get_typed_id(SelectionNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SELECTION_NODE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_SELECTION_NODE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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
    slot = Py_NewRef(self->data->include_node ? Py_True : Py_False);
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

static int SelectionNode_traverse(SelectionNode *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SELECTION_NODE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int SelectionNode_clear(SelectionNode *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_SELECTION_NODE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void SelectionNode_dealloc(SelectionNode *self) {
    PyObject_GC_UnTrack(self);
    SelectionNode_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef SelectionNode_getset[] = {
    { "name", (getter)SelectionNode_get_name, NULL, "name" },
    { "props", (getter)SelectionNode_get_props, NULL, "props" },
    { "element_id", (getter)SelectionNode_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)SelectionNode_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&SelectionNode_dealloc,
    .tp_traverse = (traverseproc)&SelectionNode_traverse,
    .tp_clear = (inquiry)&SelectionNode_clear,
    .tp_getset = SelectionNode_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_CHARACTER 4
enum {
    SLOT_CHARACTER__NAME,
    SLOT_CHARACTER__PROPS,
    SLOT_CHARACTER__ELEMENT_ID,
    SLOT_CHARACTER__TYPED_ID,
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
    PyObject *slots[SLOT_COUNT_CHARACTER];
} Character;

static PyObject *Character_get_name(Character *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CHARACTER__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_CHARACTER__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Character_get_props(Character *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CHARACTER__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_CHARACTER__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Character_get_element_id(Character *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CHARACTER__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_CHARACTER__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Character_get_typed_id(Character *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CHARACTER__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_CHARACTER__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static int Character_traverse(Character *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CHARACTER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Character_clear(Character *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CHARACTER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Character_dealloc(Character *self) {
    PyObject_GC_UnTrack(self);
    Character_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Character_getset[] = {
    { "name", (getter)Character_get_name, NULL, "name" },
    { "props", (getter)Character_get_props, NULL, "props" },
    { "element_id", (getter)Character_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Character_get_typed_id, NULL, "typed_id" },
    { NULL },
};

static PyTypeObject Character_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Character",
    .tp_doc = PyDoc_STR("Character"),
    .tp_basicsize = sizeof(Character),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Character_dealloc,
    .tp_traverse = (traverseproc)&Character_traverse,
    .tp_clear = (inquiry)&Character_clear,
    .tp_getset = Character_getset,
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

static int ConstraintTarget_traverse(ConstraintTarget *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_CONSTRAINT_TARGET; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int ConstraintTarget_clear(ConstraintTarget *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_CONSTRAINT_TARGET; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void ConstraintTarget_dealloc(ConstraintTarget *self) {
    PyObject_GC_UnTrack(self);
    ConstraintTarget_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&ConstraintTarget_dealloc,
    .tp_traverse = (traverseproc)&ConstraintTarget_traverse,
    .tp_clear = (inquiry)&ConstraintTarget_clear,
    .tp_getset = ConstraintTarget_getset,
};

static PyObject *ConstraintTarget_from(ufbx_constraint_target *data, Context *ctx) {
    ConstraintTarget *obj = (ConstraintTarget*)PyObject_CallObject((PyObject*)&ConstraintTarget_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_CONSTRAINT 21
enum {
    SLOT_CONSTRAINT__NAME,
    SLOT_CONSTRAINT__PROPS,
    SLOT_CONSTRAINT__ELEMENT_ID,
    SLOT_CONSTRAINT__TYPED_ID,
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

static PyObject *Constraint_get_name(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_CONSTRAINT__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_props(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_CONSTRAINT__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_element_id(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_CONSTRAINT__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_typed_id(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_CONSTRAINT__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Constraint_get_type(Constraint *self, void *closure) {
    PyObject *slot = self->slots[SLOT_CONSTRAINT__TYPE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(ConstraintType_Enum, "i", (int)self->data->type);
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
    slot = Py_NewRef(self->data->active ? Py_True : Py_False);
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
    slot = PyObject_CallFunction(ConstraintAimUpType_Enum, "i", (int)self->data->aim_up_type);
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

static int Constraint_traverse(Constraint *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CONSTRAINT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Constraint_clear(Constraint *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_CONSTRAINT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Constraint_dealloc(Constraint *self) {
    PyObject_GC_UnTrack(self);
    Constraint_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Constraint_getset[] = {
    { "name", (getter)Constraint_get_name, NULL, "name" },
    { "props", (getter)Constraint_get_props, NULL, "props" },
    { "element_id", (getter)Constraint_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Constraint_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Constraint_dealloc,
    .tp_traverse = (traverseproc)&Constraint_traverse,
    .tp_clear = (inquiry)&Constraint_clear,
    .tp_getset = Constraint_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_AUDIO_LAYER 5
enum {
    SLOT_AUDIO_LAYER__NAME,
    SLOT_AUDIO_LAYER__PROPS,
    SLOT_AUDIO_LAYER__ELEMENT_ID,
    SLOT_AUDIO_LAYER__TYPED_ID,
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

static PyObject *AudioLayer_get_name(AudioLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_LAYER__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_AUDIO_LAYER__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioLayer_get_props(AudioLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_LAYER__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_AUDIO_LAYER__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioLayer_get_element_id(AudioLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_LAYER__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_AUDIO_LAYER__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioLayer_get_typed_id(AudioLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_LAYER__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_AUDIO_LAYER__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioLayer_get_clips(AudioLayer *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_LAYER__CLIPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AudioClipList_from(self->data->clips, self->ctx);
    self->slots[SLOT_AUDIO_LAYER__CLIPS] = slot;
    return Py_NewRef(slot);
}

static int AudioLayer_traverse(AudioLayer *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_AUDIO_LAYER; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int AudioLayer_clear(AudioLayer *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_AUDIO_LAYER; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void AudioLayer_dealloc(AudioLayer *self) {
    PyObject_GC_UnTrack(self);
    AudioLayer_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef AudioLayer_getset[] = {
    { "name", (getter)AudioLayer_get_name, NULL, "name" },
    { "props", (getter)AudioLayer_get_props, NULL, "props" },
    { "element_id", (getter)AudioLayer_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)AudioLayer_get_typed_id, NULL, "typed_id" },
    { "clips", (getter)AudioLayer_get_clips, NULL, "clips" },
    { NULL },
};

static PyTypeObject AudioLayer_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.AudioLayer",
    .tp_doc = PyDoc_STR("AudioLayer"),
    .tp_basicsize = sizeof(AudioLayer),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&AudioLayer_dealloc,
    .tp_traverse = (traverseproc)&AudioLayer_traverse,
    .tp_clear = (inquiry)&AudioLayer_clear,
    .tp_getset = AudioLayer_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_AUDIO_CLIP 11
enum {
    SLOT_AUDIO_CLIP__NAME,
    SLOT_AUDIO_CLIP__PROPS,
    SLOT_AUDIO_CLIP__ELEMENT_ID,
    SLOT_AUDIO_CLIP__TYPED_ID,
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

static PyObject *AudioClip_get_name(AudioClip *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_CLIP__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_AUDIO_CLIP__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioClip_get_props(AudioClip *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_CLIP__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_AUDIO_CLIP__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioClip_get_element_id(AudioClip *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_CLIP__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_AUDIO_CLIP__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *AudioClip_get_typed_id(AudioClip *self, void *closure) {
    PyObject *slot = self->slots[SLOT_AUDIO_CLIP__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_AUDIO_CLIP__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

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

static int AudioClip_traverse(AudioClip *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_AUDIO_CLIP; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int AudioClip_clear(AudioClip *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_AUDIO_CLIP; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void AudioClip_dealloc(AudioClip *self) {
    PyObject_GC_UnTrack(self);
    AudioClip_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef AudioClip_getset[] = {
    { "name", (getter)AudioClip_get_name, NULL, "name" },
    { "props", (getter)AudioClip_get_props, NULL, "props" },
    { "element_id", (getter)AudioClip_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)AudioClip_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&AudioClip_dealloc,
    .tp_traverse = (traverseproc)&AudioClip_traverse,
    .tp_clear = (inquiry)&AudioClip_clear,
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
    slot = Matrix_from(&self->data->bone_to_world);
    self->slots[SLOT_BONE_POSE__BONE_TO_WORLD] = slot;
    return Py_NewRef(slot);
}

static PyObject *BonePose_get_bone_to_parent(BonePose *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BONE_POSE__BONE_TO_PARENT];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Matrix_from(&self->data->bone_to_parent);
    self->slots[SLOT_BONE_POSE__BONE_TO_PARENT] = slot;
    return Py_NewRef(slot);
}

static int BonePose_traverse(BonePose *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BONE_POSE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BonePose_clear(BonePose *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BONE_POSE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BonePose_dealloc(BonePose *self) {
    PyObject_GC_UnTrack(self);
    BonePose_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BonePose_dealloc,
    .tp_traverse = (traverseproc)&BonePose_traverse,
    .tp_clear = (inquiry)&BonePose_clear,
    .tp_getset = BonePose_getset,
};

static PyObject *BonePose_from(ufbx_bone_pose *data, Context *ctx) {
    BonePose *obj = (BonePose*)PyObject_CallObject((PyObject*)&BonePose_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_POSE 6
enum {
    SLOT_POSE__NAME,
    SLOT_POSE__PROPS,
    SLOT_POSE__ELEMENT_ID,
    SLOT_POSE__TYPED_ID,
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

static PyObject *Pose_get_name(Pose *self, void *closure) {
    PyObject *slot = self->slots[SLOT_POSE__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_POSE__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *Pose_get_props(Pose *self, void *closure) {
    PyObject *slot = self->slots[SLOT_POSE__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_POSE__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Pose_get_element_id(Pose *self, void *closure) {
    PyObject *slot = self->slots[SLOT_POSE__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_POSE__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Pose_get_typed_id(Pose *self, void *closure) {
    PyObject *slot = self->slots[SLOT_POSE__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_POSE__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *Pose_get_is_bind_pose(Pose *self, void *closure) {
    PyObject *slot = self->slots[SLOT_POSE__IS_BIND_POSE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->is_bind_pose ? Py_True : Py_False);
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

static int Pose_traverse(Pose *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_POSE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Pose_clear(Pose *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_POSE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Pose_dealloc(Pose *self) {
    PyObject_GC_UnTrack(self);
    Pose_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Pose_getset[] = {
    { "name", (getter)Pose_get_name, NULL, "name" },
    { "props", (getter)Pose_get_props, NULL, "props" },
    { "element_id", (getter)Pose_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)Pose_get_typed_id, NULL, "typed_id" },
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Pose_dealloc,
    .tp_traverse = (traverseproc)&Pose_traverse,
    .tp_clear = (inquiry)&Pose_clear,
    .tp_getset = Pose_getset,
    .tp_base = &Element_Type,
};

#define SLOT_COUNT_METADATA_OBJECT 4
enum {
    SLOT_METADATA_OBJECT__NAME,
    SLOT_METADATA_OBJECT__PROPS,
    SLOT_METADATA_OBJECT__ELEMENT_ID,
    SLOT_METADATA_OBJECT__TYPED_ID,
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
    PyObject *slots[SLOT_COUNT_METADATA_OBJECT];
} MetadataObject;

static PyObject *MetadataObject_get_name(MetadataObject *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA_OBJECT__NAME];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = String_from(self->data->name);
    self->slots[SLOT_METADATA_OBJECT__NAME] = slot;
    return Py_NewRef(slot);
}

static PyObject *MetadataObject_get_props(MetadataObject *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA_OBJECT__PROPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_METADATA_OBJECT__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *MetadataObject_get_element_id(MetadataObject *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA_OBJECT__ELEMENT_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->element_id);
    self->slots[SLOT_METADATA_OBJECT__ELEMENT_ID] = slot;
    return Py_NewRef(slot);
}

static PyObject *MetadataObject_get_typed_id(MetadataObject *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA_OBJECT__TYPED_ID];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyLong_FromUnsignedLong((unsigned long)self->data->typed_id);
    self->slots[SLOT_METADATA_OBJECT__TYPED_ID] = slot;
    return Py_NewRef(slot);
}

static int MetadataObject_traverse(MetadataObject *self, visitproc visit, void *arg) {
    if (Element_traverse((Element*)self, visit, arg) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_METADATA_OBJECT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int MetadataObject_clear(MetadataObject *self) {
    if (Element_clear((Element*)self) < 0) return -1;
    for (size_t i = 0; i < SLOT_COUNT_METADATA_OBJECT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void MetadataObject_dealloc(MetadataObject *self) {
    PyObject_GC_UnTrack(self);
    MetadataObject_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef MetadataObject_getset[] = {
    { "name", (getter)MetadataObject_get_name, NULL, "name" },
    { "props", (getter)MetadataObject_get_props, NULL, "props" },
    { "element_id", (getter)MetadataObject_get_element_id, NULL, "element_id" },
    { "typed_id", (getter)MetadataObject_get_typed_id, NULL, "typed_id" },
    { NULL },
};

static PyTypeObject MetadataObject_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.MetadataObject",
    .tp_doc = PyDoc_STR("MetadataObject"),
    .tp_basicsize = sizeof(MetadataObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&MetadataObject_dealloc,
    .tp_traverse = (traverseproc)&MetadataObject_traverse,
    .tp_clear = (inquiry)&MetadataObject_clear,
    .tp_getset = MetadataObject_getset,
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
    slot = PyObject_CallFunction(ElementType_Enum, "i", (int)self->data->type);
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

static int NameElement_traverse(NameElement *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_NAME_ELEMENT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int NameElement_clear(NameElement *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_NAME_ELEMENT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void NameElement_dealloc(NameElement *self) {
    PyObject_GC_UnTrack(self);
    NameElement_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&NameElement_dealloc,
    .tp_traverse = (traverseproc)&NameElement_traverse,
    .tp_clear = (inquiry)&NameElement_clear,
    .tp_getset = NameElement_getset,
};

static PyObject *NameElement_from(ufbx_name_element *data, Context *ctx) {
    NameElement *obj = (NameElement*)PyObject_CallObject((PyObject*)&NameElement_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int Application_traverse(Application *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_APPLICATION; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Application_clear(Application *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_APPLICATION; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Application_dealloc(Application *self) {
    PyObject_GC_UnTrack(self);
    Application_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Application_dealloc,
    .tp_traverse = (traverseproc)&Application_traverse,
    .tp_clear = (inquiry)&Application_clear,
    .tp_getset = Application_getset,
};

static PyObject *Application_from(ufbx_application *data, Context *ctx) {
    Application *obj = (Application*)PyObject_CallObject((PyObject*)&Application_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = PyObject_CallFunction(WarningType_Enum, "i", (int)self->data->type);
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

static int Warning_traverse(Warning *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_WARNING; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Warning_clear(Warning *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_WARNING; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Warning_dealloc(Warning *self) {
    PyObject_GC_UnTrack(self);
    Warning_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Warning_dealloc,
    .tp_traverse = (traverseproc)&Warning_traverse,
    .tp_clear = (inquiry)&Warning_clear,
    .tp_getset = Warning_getset,
};

static PyObject *Warning_from(ufbx_warning *data, Context *ctx) {
    Warning *obj = (Warning*)PyObject_CallObject((PyObject*)&Warning_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Props_from(&self->data->props, self->ctx);
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
    slot = PyObject_CallFunction(ThumbnailFormat_Enum, "i", (int)self->data->format);
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

static int Thumbnail_traverse(Thumbnail *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_THUMBNAIL; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Thumbnail_clear(Thumbnail *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_THUMBNAIL; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Thumbnail_dealloc(Thumbnail *self) {
    PyObject_GC_UnTrack(self);
    Thumbnail_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Thumbnail_dealloc,
    .tp_traverse = (traverseproc)&Thumbnail_traverse,
    .tp_clear = (inquiry)&Thumbnail_clear,
    .tp_getset = Thumbnail_getset,
};

static PyObject *Thumbnail_from(ufbx_thumbnail *data, Context *ctx) {
    Thumbnail *obj = (Thumbnail*)PyObject_CallObject((PyObject*)&Thumbnail_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->ascii ? Py_True : Py_False);
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
    slot = PyObject_CallFunction(FileFormat_Enum, "i", (int)self->data->file_format);
    self->slots[SLOT_METADATA__FILE_FORMAT] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_may_contain_no_index(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__MAY_CONTAIN_NO_INDEX];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->may_contain_no_index ? Py_True : Py_False);
    self->slots[SLOT_METADATA__MAY_CONTAIN_NO_INDEX] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_may_contain_missing_vertex_position(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__MAY_CONTAIN_MISSING_VERTEX_POSITION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->may_contain_missing_vertex_position ? Py_True : Py_False);
    self->slots[SLOT_METADATA__MAY_CONTAIN_MISSING_VERTEX_POSITION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_may_contain_broken_elements(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__MAY_CONTAIN_BROKEN_ELEMENTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->may_contain_broken_elements ? Py_True : Py_False);
    self->slots[SLOT_METADATA__MAY_CONTAIN_BROKEN_ELEMENTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_is_unsafe(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__IS_UNSAFE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->is_unsafe ? Py_True : Py_False);
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
    slot = Py_NewRef(self->data->big_endian ? Py_True : Py_False);
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
    slot = PyObject_CallFunction(Exporter_Enum, "i", (int)self->data->exporter);
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
    slot = Props_from(&self->data->scene_props, self->ctx);
    self->slots[SLOT_METADATA__SCENE_PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_original_application(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__ORIGINAL_APPLICATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Application_from(&self->data->original_application, self->ctx);
    self->slots[SLOT_METADATA__ORIGINAL_APPLICATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_latest_application(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__LATEST_APPLICATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Application_from(&self->data->latest_application, self->ctx);
    self->slots[SLOT_METADATA__LATEST_APPLICATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_thumbnail(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__THUMBNAIL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Thumbnail_from(&self->data->thumbnail, self->ctx);
    self->slots[SLOT_METADATA__THUMBNAIL] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_geometry_ignored(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__GEOMETRY_IGNORED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->geometry_ignored ? Py_True : Py_False);
    self->slots[SLOT_METADATA__GEOMETRY_IGNORED] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_animation_ignored(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__ANIMATION_IGNORED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->animation_ignored ? Py_True : Py_False);
    self->slots[SLOT_METADATA__ANIMATION_IGNORED] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_embedded_ignored(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__EMBEDDED_IGNORED];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->embedded_ignored ? Py_True : Py_False);
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
    slot = Py_NewRef(self->data->bone_prop_limb_length_relative ? Py_True : Py_False);
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
    slot = PyObject_CallFunction(SpaceConversion_Enum, "i", (int)self->data->space_conversion);
    self->slots[SLOT_METADATA__SPACE_CONVERSION] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_geometry_transform_handling(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__GEOMETRY_TRANSFORM_HANDLING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(GeometryTransformHandling_Enum, "i", (int)self->data->geometry_transform_handling);
    self->slots[SLOT_METADATA__GEOMETRY_TRANSFORM_HANDLING] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_inherit_mode_handling(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__INHERIT_MODE_HANDLING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(InheritModeHandling_Enum, "i", (int)self->data->inherit_mode_handling);
    self->slots[SLOT_METADATA__INHERIT_MODE_HANDLING] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_pivot_handling(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__PIVOT_HANDLING];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(PivotHandling_Enum, "i", (int)self->data->pivot_handling);
    self->slots[SLOT_METADATA__PIVOT_HANDLING] = slot;
    return Py_NewRef(slot);
}

static PyObject *Metadata_get_handedness_conversion_axis(Metadata *self, void *closure) {
    PyObject *slot = self->slots[SLOT_METADATA__HANDEDNESS_CONVERSION_AXIS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(MirrorAxis_Enum, "i", (int)self->data->handedness_conversion_axis);
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
    slot = PyObject_CallFunction(MirrorAxis_Enum, "i", (int)self->data->mirror_axis);
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

static int Metadata_traverse(Metadata *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_METADATA; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Metadata_clear(Metadata *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_METADATA; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Metadata_dealloc(Metadata *self) {
    PyObject_GC_UnTrack(self);
    Metadata_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Metadata_dealloc,
    .tp_traverse = (traverseproc)&Metadata_traverse,
    .tp_clear = (inquiry)&Metadata_clear,
    .tp_getset = Metadata_getset,
};

static PyObject *Metadata_from(ufbx_metadata *data, Context *ctx) {
    Metadata *obj = (Metadata*)PyObject_CallObject((PyObject*)&Metadata_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Props_from(&self->data->props, self->ctx);
    self->slots[SLOT_SCENE_SETTINGS__PROPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_axes(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__AXES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = CoordinateAxes_from(&self->data->axes);
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
    slot = PyObject_CallFunction(TimeMode_Enum, "i", (int)self->data->time_mode);
    self->slots[SLOT_SCENE_SETTINGS__TIME_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_time_protocol(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__TIME_PROTOCOL];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(TimeProtocol_Enum, "i", (int)self->data->time_protocol);
    self->slots[SLOT_SCENE_SETTINGS__TIME_PROTOCOL] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_snap_mode(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__SNAP_MODE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(SnapMode_Enum, "i", (int)self->data->snap_mode);
    self->slots[SLOT_SCENE_SETTINGS__SNAP_MODE] = slot;
    return Py_NewRef(slot);
}

static PyObject *SceneSettings_get_original_axis_up(SceneSettings *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE_SETTINGS__ORIGINAL_AXIS_UP];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PyObject_CallFunction(CoordinateAxis_Enum, "i", (int)self->data->original_axis_up);
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

static int SceneSettings_traverse(SceneSettings *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SCENE_SETTINGS; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int SceneSettings_clear(SceneSettings *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SCENE_SETTINGS; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void SceneSettings_dealloc(SceneSettings *self) {
    PyObject_GC_UnTrack(self);
    SceneSettings_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&SceneSettings_dealloc,
    .tp_traverse = (traverseproc)&SceneSettings_traverse,
    .tp_clear = (inquiry)&SceneSettings_clear,
    .tp_getset = SceneSettings_getset,
};

static PyObject *SceneSettings_from(ufbx_scene_settings *data, Context *ctx) {
    SceneSettings *obj = (SceneSettings*)PyObject_CallObject((PyObject*)&SceneSettings_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

#define SLOT_COUNT_SCENE 52
enum {
    SLOT_SCENE__METADATA,
    SLOT_SCENE__SETTINGS,
    SLOT_SCENE__ROOT_NODE,
    SLOT_SCENE__ANIM,
    SLOT_SCENE__UNKNOWNS,
    SLOT_SCENE__NODES,
    SLOT_SCENE__MESHES,
    SLOT_SCENE__LIGHTS,
    SLOT_SCENE__CAMERAS,
    SLOT_SCENE__BONES,
    SLOT_SCENE__EMPTIES,
    SLOT_SCENE__LINE_CURVES,
    SLOT_SCENE__NURBS_CURVES,
    SLOT_SCENE__NURBS_SURFACES,
    SLOT_SCENE__NURBS_TRIM_SURFACES,
    SLOT_SCENE__NURBS_TRIM_BOUNDARIES,
    SLOT_SCENE__PROCEDURAL_GEOMETRIES,
    SLOT_SCENE__STEREO_CAMERAS,
    SLOT_SCENE__CAMERA_SWITCHERS,
    SLOT_SCENE__MARKERS,
    SLOT_SCENE__LOD_GROUPS,
    SLOT_SCENE__SKIN_DEFORMERS,
    SLOT_SCENE__SKIN_CLUSTERS,
    SLOT_SCENE__BLEND_DEFORMERS,
    SLOT_SCENE__BLEND_CHANNELS,
    SLOT_SCENE__BLEND_SHAPES,
    SLOT_SCENE__CACHE_DEFORMERS,
    SLOT_SCENE__CACHE_FILES,
    SLOT_SCENE__MATERIALS,
    SLOT_SCENE__TEXTURES,
    SLOT_SCENE__VIDEOS,
    SLOT_SCENE__SHADERS,
    SLOT_SCENE__SHADER_BINDINGS,
    SLOT_SCENE__ANIM_STACKS,
    SLOT_SCENE__ANIM_LAYERS,
    SLOT_SCENE__ANIM_VALUES,
    SLOT_SCENE__ANIM_CURVES,
    SLOT_SCENE__DISPLAY_LAYERS,
    SLOT_SCENE__SELECTION_SETS,
    SLOT_SCENE__SELECTION_NODES,
    SLOT_SCENE__CHARACTERS,
    SLOT_SCENE__CONSTRAINTS,
    SLOT_SCENE__AUDIO_LAYERS,
    SLOT_SCENE__AUDIO_CLIPS,
    SLOT_SCENE__POSES,
    SLOT_SCENE__METADATA_OBJECTS,
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
    slot = Metadata_from(&self->data->metadata, self->ctx);
    self->slots[SLOT_SCENE__METADATA] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_settings(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__SETTINGS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SceneSettings_from(&self->data->settings, self->ctx);
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

static PyObject *Scene_get_unknowns(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__UNKNOWNS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = UnknownList_from(self->data->unknowns, self->ctx);
    self->slots[SLOT_SCENE__UNKNOWNS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_nodes(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__NODES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NodeList_from(self->data->nodes, self->ctx);
    self->slots[SLOT_SCENE__NODES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_meshes(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__MESHES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MeshList_from(self->data->meshes, self->ctx);
    self->slots[SLOT_SCENE__MESHES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_lights(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__LIGHTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = LightList_from(self->data->lights, self->ctx);
    self->slots[SLOT_SCENE__LIGHTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_cameras(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__CAMERAS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = CameraList_from(self->data->cameras, self->ctx);
    self->slots[SLOT_SCENE__CAMERAS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_bones(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__BONES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BoneList_from(self->data->bones, self->ctx);
    self->slots[SLOT_SCENE__BONES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_empties(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__EMPTIES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = EmptyList_from(self->data->empties, self->ctx);
    self->slots[SLOT_SCENE__EMPTIES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_line_curves(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__LINE_CURVES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = LineCurveList_from(self->data->line_curves, self->ctx);
    self->slots[SLOT_SCENE__LINE_CURVES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_nurbs_curves(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__NURBS_CURVES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NurbsCurveList_from(self->data->nurbs_curves, self->ctx);
    self->slots[SLOT_SCENE__NURBS_CURVES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_nurbs_surfaces(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__NURBS_SURFACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NurbsSurfaceList_from(self->data->nurbs_surfaces, self->ctx);
    self->slots[SLOT_SCENE__NURBS_SURFACES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_nurbs_trim_surfaces(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__NURBS_TRIM_SURFACES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NurbsTrimSurfaceList_from(self->data->nurbs_trim_surfaces, self->ctx);
    self->slots[SLOT_SCENE__NURBS_TRIM_SURFACES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_nurbs_trim_boundaries(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__NURBS_TRIM_BOUNDARIES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = NurbsTrimBoundaryList_from(self->data->nurbs_trim_boundaries, self->ctx);
    self->slots[SLOT_SCENE__NURBS_TRIM_BOUNDARIES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_procedural_geometries(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__PROCEDURAL_GEOMETRIES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ProceduralGeometryList_from(self->data->procedural_geometries, self->ctx);
    self->slots[SLOT_SCENE__PROCEDURAL_GEOMETRIES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_stereo_cameras(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__STEREO_CAMERAS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = StereoCameraList_from(self->data->stereo_cameras, self->ctx);
    self->slots[SLOT_SCENE__STEREO_CAMERAS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_camera_switchers(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__CAMERA_SWITCHERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = CameraSwitcherList_from(self->data->camera_switchers, self->ctx);
    self->slots[SLOT_SCENE__CAMERA_SWITCHERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_markers(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__MARKERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MarkerList_from(self->data->markers, self->ctx);
    self->slots[SLOT_SCENE__MARKERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_lod_groups(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__LOD_GROUPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = LodGroupList_from(self->data->lod_groups, self->ctx);
    self->slots[SLOT_SCENE__LOD_GROUPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_skin_deformers(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__SKIN_DEFORMERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SkinDeformerList_from(self->data->skin_deformers, self->ctx);
    self->slots[SLOT_SCENE__SKIN_DEFORMERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_skin_clusters(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__SKIN_CLUSTERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SkinClusterList_from(self->data->skin_clusters, self->ctx);
    self->slots[SLOT_SCENE__SKIN_CLUSTERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_blend_deformers(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__BLEND_DEFORMERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BlendDeformerList_from(self->data->blend_deformers, self->ctx);
    self->slots[SLOT_SCENE__BLEND_DEFORMERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_blend_channels(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__BLEND_CHANNELS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BlendChannelList_from(self->data->blend_channels, self->ctx);
    self->slots[SLOT_SCENE__BLEND_CHANNELS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_blend_shapes(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__BLEND_SHAPES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = BlendShapeList_from(self->data->blend_shapes, self->ctx);
    self->slots[SLOT_SCENE__BLEND_SHAPES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_cache_deformers(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__CACHE_DEFORMERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = CacheDeformerList_from(self->data->cache_deformers, self->ctx);
    self->slots[SLOT_SCENE__CACHE_DEFORMERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_cache_files(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__CACHE_FILES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = CacheFileList_from(self->data->cache_files, self->ctx);
    self->slots[SLOT_SCENE__CACHE_FILES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_materials(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__MATERIALS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MaterialList_from(self->data->materials, self->ctx);
    self->slots[SLOT_SCENE__MATERIALS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_textures(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__TEXTURES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = TextureList_from(self->data->textures, self->ctx);
    self->slots[SLOT_SCENE__TEXTURES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_videos(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__VIDEOS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = VideoList_from(self->data->videos, self->ctx);
    self->slots[SLOT_SCENE__VIDEOS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_shaders(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__SHADERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ShaderList_from(self->data->shaders, self->ctx);
    self->slots[SLOT_SCENE__SHADERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_shader_bindings(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__SHADER_BINDINGS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ShaderBindingList_from(self->data->shader_bindings, self->ctx);
    self->slots[SLOT_SCENE__SHADER_BINDINGS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_anim_stacks(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__ANIM_STACKS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AnimStackList_from(self->data->anim_stacks, self->ctx);
    self->slots[SLOT_SCENE__ANIM_STACKS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_anim_layers(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__ANIM_LAYERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AnimLayerList_from(self->data->anim_layers, self->ctx);
    self->slots[SLOT_SCENE__ANIM_LAYERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_anim_values(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__ANIM_VALUES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AnimValueList_from(self->data->anim_values, self->ctx);
    self->slots[SLOT_SCENE__ANIM_VALUES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_anim_curves(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__ANIM_CURVES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AnimCurveList_from(self->data->anim_curves, self->ctx);
    self->slots[SLOT_SCENE__ANIM_CURVES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_display_layers(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__DISPLAY_LAYERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = DisplayLayerList_from(self->data->display_layers, self->ctx);
    self->slots[SLOT_SCENE__DISPLAY_LAYERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_selection_sets(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__SELECTION_SETS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SelectionSetList_from(self->data->selection_sets, self->ctx);
    self->slots[SLOT_SCENE__SELECTION_SETS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_selection_nodes(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__SELECTION_NODES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = SelectionNodeList_from(self->data->selection_nodes, self->ctx);
    self->slots[SLOT_SCENE__SELECTION_NODES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_characters(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__CHARACTERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = CharacterList_from(self->data->characters, self->ctx);
    self->slots[SLOT_SCENE__CHARACTERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_constraints(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__CONSTRAINTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = ConstraintList_from(self->data->constraints, self->ctx);
    self->slots[SLOT_SCENE__CONSTRAINTS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_audio_layers(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__AUDIO_LAYERS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AudioLayerList_from(self->data->audio_layers, self->ctx);
    self->slots[SLOT_SCENE__AUDIO_LAYERS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_audio_clips(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__AUDIO_CLIPS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = AudioClipList_from(self->data->audio_clips, self->ctx);
    self->slots[SLOT_SCENE__AUDIO_CLIPS] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_poses(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__POSES];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = PoseList_from(self->data->poses, self->ctx);
    self->slots[SLOT_SCENE__POSES] = slot;
    return Py_NewRef(slot);
}

static PyObject *Scene_get_metadata_objects(Scene *self, void *closure) {
    PyObject *slot = self->slots[SLOT_SCENE__METADATA_OBJECTS];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = MetadataObjectList_from(self->data->metadata_objects, self->ctx);
    self->slots[SLOT_SCENE__METADATA_OBJECTS] = slot;
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

static int Scene_traverse(Scene *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SCENE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Scene_clear(Scene *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_SCENE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Scene_dealloc(Scene *self) {
    PyObject_GC_UnTrack(self);
    Scene_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyGetSetDef Scene_getset[] = {
    { "metadata", (getter)Scene_get_metadata, NULL, "metadata" },
    { "settings", (getter)Scene_get_settings, NULL, "settings" },
    { "root_node", (getter)Scene_get_root_node, NULL, "root_node" },
    { "anim", (getter)Scene_get_anim, NULL, "anim" },
    { "unknowns", (getter)Scene_get_unknowns, NULL, "unknowns" },
    { "nodes", (getter)Scene_get_nodes, NULL, "nodes" },
    { "meshes", (getter)Scene_get_meshes, NULL, "meshes" },
    { "lights", (getter)Scene_get_lights, NULL, "lights" },
    { "cameras", (getter)Scene_get_cameras, NULL, "cameras" },
    { "bones", (getter)Scene_get_bones, NULL, "bones" },
    { "empties", (getter)Scene_get_empties, NULL, "empties" },
    { "line_curves", (getter)Scene_get_line_curves, NULL, "line_curves" },
    { "nurbs_curves", (getter)Scene_get_nurbs_curves, NULL, "nurbs_curves" },
    { "nurbs_surfaces", (getter)Scene_get_nurbs_surfaces, NULL, "nurbs_surfaces" },
    { "nurbs_trim_surfaces", (getter)Scene_get_nurbs_trim_surfaces, NULL, "nurbs_trim_surfaces" },
    { "nurbs_trim_boundaries", (getter)Scene_get_nurbs_trim_boundaries, NULL, "nurbs_trim_boundaries" },
    { "procedural_geometries", (getter)Scene_get_procedural_geometries, NULL, "procedural_geometries" },
    { "stereo_cameras", (getter)Scene_get_stereo_cameras, NULL, "stereo_cameras" },
    { "camera_switchers", (getter)Scene_get_camera_switchers, NULL, "camera_switchers" },
    { "markers", (getter)Scene_get_markers, NULL, "markers" },
    { "lod_groups", (getter)Scene_get_lod_groups, NULL, "lod_groups" },
    { "skin_deformers", (getter)Scene_get_skin_deformers, NULL, "skin_deformers" },
    { "skin_clusters", (getter)Scene_get_skin_clusters, NULL, "skin_clusters" },
    { "blend_deformers", (getter)Scene_get_blend_deformers, NULL, "blend_deformers" },
    { "blend_channels", (getter)Scene_get_blend_channels, NULL, "blend_channels" },
    { "blend_shapes", (getter)Scene_get_blend_shapes, NULL, "blend_shapes" },
    { "cache_deformers", (getter)Scene_get_cache_deformers, NULL, "cache_deformers" },
    { "cache_files", (getter)Scene_get_cache_files, NULL, "cache_files" },
    { "materials", (getter)Scene_get_materials, NULL, "materials" },
    { "textures", (getter)Scene_get_textures, NULL, "textures" },
    { "videos", (getter)Scene_get_videos, NULL, "videos" },
    { "shaders", (getter)Scene_get_shaders, NULL, "shaders" },
    { "shader_bindings", (getter)Scene_get_shader_bindings, NULL, "shader_bindings" },
    { "anim_stacks", (getter)Scene_get_anim_stacks, NULL, "anim_stacks" },
    { "anim_layers", (getter)Scene_get_anim_layers, NULL, "anim_layers" },
    { "anim_values", (getter)Scene_get_anim_values, NULL, "anim_values" },
    { "anim_curves", (getter)Scene_get_anim_curves, NULL, "anim_curves" },
    { "display_layers", (getter)Scene_get_display_layers, NULL, "display_layers" },
    { "selection_sets", (getter)Scene_get_selection_sets, NULL, "selection_sets" },
    { "selection_nodes", (getter)Scene_get_selection_nodes, NULL, "selection_nodes" },
    { "characters", (getter)Scene_get_characters, NULL, "characters" },
    { "constraints", (getter)Scene_get_constraints, NULL, "constraints" },
    { "audio_layers", (getter)Scene_get_audio_layers, NULL, "audio_layers" },
    { "audio_clips", (getter)Scene_get_audio_clips, NULL, "audio_clips" },
    { "poses", (getter)Scene_get_poses, NULL, "poses" },
    { "metadata_objects", (getter)Scene_get_metadata_objects, NULL, "metadata_objects" },
    { "texture_files", (getter)Scene_get_texture_files, NULL, "texture_files" },
    { "elements", (getter)Scene_get_elements, NULL, "elements" },
    { "connections_src", (getter)Scene_get_connections_src, NULL, "connections_src" },
    { "connections_dst", (getter)Scene_get_connections_dst, NULL, "connections_dst" },
    { "elements_by_name", (getter)Scene_get_elements_by_name, NULL, "elements_by_name" },
    { "dom_root", (getter)Scene_get_dom_root, NULL, "dom_root" },
    { NULL },
};

static PyObject *Scene_find_node(PyObject *self, PyObject *args);
static PyObject *Scene_find_anim_stack(PyObject *self, PyObject *args);
static PyObject *Scene_evaluate(PyObject *self, PyObject *args, PyObject *kwargs);

static PyMethodDef Scene_methods[] = {
    { "find_node", &Scene_find_node, METH_VARARGS, NULL },
    { "find_anim_stack", &Scene_find_anim_stack, METH_VARARGS, NULL },
    { "evaluate", (PyCFunction)&Scene_evaluate, METH_VARARGS|METH_KEYWORDS, NULL },
    { NULL },
};

static PyTypeObject Scene_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ufbx.Scene",
    .tp_doc = PyDoc_STR("Scene"),
    .tp_basicsize = sizeof(Scene),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Scene_dealloc,
    .tp_traverse = (traverseproc)&Scene_traverse,
    .tp_clear = (inquiry)&Scene_clear,
    .tp_getset = Scene_getset,
    .tp_methods = Scene_methods,
};

static PyObject *Scene_from(ufbx_scene *data, Context *ctx) {
    Scene *obj = (Scene*)PyObject_CallObject((PyObject*)&Scene_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int VertexStream_traverse(VertexStream *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_STREAM; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int VertexStream_clear(VertexStream *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_VERTEX_STREAM; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void VertexStream_dealloc(VertexStream *self) {
    PyObject_GC_UnTrack(self);
    VertexStream_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&VertexStream_dealloc,
    .tp_traverse = (traverseproc)&VertexStream_traverse,
    .tp_clear = (inquiry)&VertexStream_clear,
    .tp_getset = VertexStream_getset,
};

static PyObject *VertexStream_from(ufbx_vertex_stream *data, Context *ctx) {
    VertexStream *obj = (VertexStream*)PyObject_CallObject((PyObject*)&VertexStream_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = PyObject_CallFunction(OpenFileType_Enum, "i", (int)self->data->type);
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

static int OpenFileInfo_traverse(OpenFileInfo *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_OPEN_FILE_INFO; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int OpenFileInfo_clear(OpenFileInfo *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_OPEN_FILE_INFO; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void OpenFileInfo_dealloc(OpenFileInfo *self) {
    PyObject_GC_UnTrack(self);
    OpenFileInfo_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&OpenFileInfo_dealloc,
    .tp_traverse = (traverseproc)&OpenFileInfo_traverse,
    .tp_clear = (inquiry)&OpenFileInfo_clear,
    .tp_getset = OpenFileInfo_getset,
};

static PyObject *OpenFileInfo_from(ufbx_open_file_info *data, Context *ctx) {
    OpenFileInfo *obj = (OpenFileInfo*)PyObject_CallObject((PyObject*)&OpenFileInfo_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int OpenFileOpts_traverse(OpenFileOpts *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_OPEN_FILE_OPTS; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int OpenFileOpts_clear(OpenFileOpts *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_OPEN_FILE_OPTS; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void OpenFileOpts_dealloc(OpenFileOpts *self) {
    PyObject_GC_UnTrack(self);
    OpenFileOpts_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&OpenFileOpts_dealloc,
    .tp_traverse = (traverseproc)&OpenFileOpts_traverse,
    .tp_clear = (inquiry)&OpenFileOpts_clear,
    .tp_getset = OpenFileOpts_getset,
};

static PyObject *OpenFileOpts_from(ufbx_open_file_opts *data, Context *ctx) {
    OpenFileOpts *obj = (OpenFileOpts*)PyObject_CallObject((PyObject*)&OpenFileOpts_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int ErrorFrame_traverse(ErrorFrame *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_ERROR_FRAME; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int ErrorFrame_clear(ErrorFrame *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_ERROR_FRAME; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void ErrorFrame_dealloc(ErrorFrame *self) {
    PyObject_GC_UnTrack(self);
    ErrorFrame_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&ErrorFrame_dealloc,
    .tp_traverse = (traverseproc)&ErrorFrame_traverse,
    .tp_clear = (inquiry)&ErrorFrame_clear,
    .tp_getset = ErrorFrame_getset,
};

static PyObject *ErrorFrame_from(ufbx_error_frame *data, Context *ctx) {
    ErrorFrame *obj = (ErrorFrame*)PyObject_CallObject((PyObject*)&ErrorFrame_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = PyObject_CallFunction(ErrorType_Enum, "i", (int)self->data->type);
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

static int Error_traverse(Error *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_ERROR; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Error_clear(Error *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_ERROR; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Error_dealloc(Error *self) {
    PyObject_GC_UnTrack(self);
    Error_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Error_dealloc,
    .tp_traverse = (traverseproc)&Error_traverse,
    .tp_clear = (inquiry)&Error_clear,
    .tp_getset = Error_getset,
};

static PyObject *Error_from(ufbx_error *data, Context *ctx) {
    Error *obj = (Error*)PyObject_CallObject((PyObject*)&Error_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int Progress_traverse(Progress *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_PROGRESS; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Progress_clear(Progress *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_PROGRESS; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Progress_dealloc(Progress *self) {
    PyObject_GC_UnTrack(self);
    Progress_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Progress_dealloc,
    .tp_traverse = (traverseproc)&Progress_traverse,
    .tp_clear = (inquiry)&Progress_clear,
    .tp_getset = Progress_getset,
};

static PyObject *Progress_from(ufbx_progress *data, Context *ctx) {
    Progress *obj = (Progress*)PyObject_CallObject((PyObject*)&Progress_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->no_header ? Py_True : Py_False);
    self->slots[SLOT_INFLATE_INPUT__NO_HEADER] = slot;
    return Py_NewRef(slot);
}

static PyObject *InflateInput_get_no_checksum(InflateInput *self, void *closure) {
    PyObject *slot = self->slots[SLOT_INFLATE_INPUT__NO_CHECKSUM];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->no_checksum ? Py_True : Py_False);
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

static int InflateInput_traverse(InflateInput *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_INFLATE_INPUT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int InflateInput_clear(InflateInput *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_INFLATE_INPUT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void InflateInput_dealloc(InflateInput *self) {
    PyObject_GC_UnTrack(self);
    InflateInput_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&InflateInput_dealloc,
    .tp_traverse = (traverseproc)&InflateInput_traverse,
    .tp_clear = (inquiry)&InflateInput_clear,
    .tp_getset = InflateInput_getset,
};

static PyObject *InflateInput_from(ufbx_inflate_input *data, Context *ctx) {
    InflateInput *obj = (InflateInput*)PyObject_CallObject((PyObject*)&InflateInput_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->initialized ? Py_True : Py_False);
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

static int InflateRetain_traverse(InflateRetain *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_INFLATE_RETAIN; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int InflateRetain_clear(InflateRetain *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_INFLATE_RETAIN; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void InflateRetain_dealloc(InflateRetain *self) {
    PyObject_GC_UnTrack(self);
    InflateRetain_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&InflateRetain_dealloc,
    .tp_traverse = (traverseproc)&InflateRetain_traverse,
    .tp_clear = (inquiry)&InflateRetain_clear,
    .tp_getset = InflateRetain_getset,
};

static PyObject *InflateRetain_from(ufbx_inflate_retain *data, Context *ctx) {
    InflateRetain *obj = (InflateRetain*)PyObject_CallObject((PyObject*)&InflateRetain_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = PyObject_CallFunction(BakedKeyFlags_Enum, "i", (int)self->data->flags);
    self->slots[SLOT_BAKED_VEC3__FLAGS] = slot;
    return Py_NewRef(slot);
}

static int BakedVec3_traverse(BakedVec3 *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_VEC3; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BakedVec3_clear(BakedVec3 *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_VEC3; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BakedVec3_dealloc(BakedVec3 *self) {
    PyObject_GC_UnTrack(self);
    BakedVec3_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BakedVec3_dealloc,
    .tp_traverse = (traverseproc)&BakedVec3_traverse,
    .tp_clear = (inquiry)&BakedVec3_clear,
    .tp_getset = BakedVec3_getset,
};

static PyObject *BakedVec3_from(ufbx_baked_vec3 *data, Context *ctx) {
    BakedVec3 *obj = (BakedVec3*)PyObject_CallObject((PyObject*)&BakedVec3_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = PyObject_CallFunction(BakedKeyFlags_Enum, "i", (int)self->data->flags);
    self->slots[SLOT_BAKED_QUAT__FLAGS] = slot;
    return Py_NewRef(slot);
}

static int BakedQuat_traverse(BakedQuat *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_QUAT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BakedQuat_clear(BakedQuat *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_QUAT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BakedQuat_dealloc(BakedQuat *self) {
    PyObject_GC_UnTrack(self);
    BakedQuat_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BakedQuat_dealloc,
    .tp_traverse = (traverseproc)&BakedQuat_traverse,
    .tp_clear = (inquiry)&BakedQuat_clear,
    .tp_getset = BakedQuat_getset,
};

static PyObject *BakedQuat_from(ufbx_baked_quat *data, Context *ctx) {
    BakedQuat *obj = (BakedQuat*)PyObject_CallObject((PyObject*)&BakedQuat_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->constant_translation ? Py_True : Py_False);
    self->slots[SLOT_BAKED_NODE__CONSTANT_TRANSLATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedNode_get_constant_rotation(BakedNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_NODE__CONSTANT_ROTATION];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->constant_rotation ? Py_True : Py_False);
    self->slots[SLOT_BAKED_NODE__CONSTANT_ROTATION] = slot;
    return Py_NewRef(slot);
}

static PyObject *BakedNode_get_constant_scale(BakedNode *self, void *closure) {
    PyObject *slot = self->slots[SLOT_BAKED_NODE__CONSTANT_SCALE];
    if (slot) return Py_NewRef(slot);
    if (!self->ctx->ok) return Context_error(self->ctx);
    slot = Py_NewRef(self->data->constant_scale ? Py_True : Py_False);
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

static int BakedNode_traverse(BakedNode *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_NODE; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BakedNode_clear(BakedNode *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_NODE; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BakedNode_dealloc(BakedNode *self) {
    PyObject_GC_UnTrack(self);
    BakedNode_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BakedNode_dealloc,
    .tp_traverse = (traverseproc)&BakedNode_traverse,
    .tp_clear = (inquiry)&BakedNode_clear,
    .tp_getset = BakedNode_getset,
};

static PyObject *BakedNode_from(ufbx_baked_node *data, Context *ctx) {
    BakedNode *obj = (BakedNode*)PyObject_CallObject((PyObject*)&BakedNode_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->constant_value ? Py_True : Py_False);
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

static int BakedProp_traverse(BakedProp *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_PROP; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BakedProp_clear(BakedProp *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_PROP; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BakedProp_dealloc(BakedProp *self) {
    PyObject_GC_UnTrack(self);
    BakedProp_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BakedProp_dealloc,
    .tp_traverse = (traverseproc)&BakedProp_traverse,
    .tp_clear = (inquiry)&BakedProp_clear,
    .tp_getset = BakedProp_getset,
};

static PyObject *BakedProp_from(ufbx_baked_prop *data, Context *ctx) {
    BakedProp *obj = (BakedProp*)PyObject_CallObject((PyObject*)&BakedProp_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int BakedElement_traverse(BakedElement *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_ELEMENT; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BakedElement_clear(BakedElement *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_ELEMENT; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BakedElement_dealloc(BakedElement *self) {
    PyObject_GC_UnTrack(self);
    BakedElement_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BakedElement_dealloc,
    .tp_traverse = (traverseproc)&BakedElement_traverse,
    .tp_clear = (inquiry)&BakedElement_clear,
    .tp_getset = BakedElement_getset,
};

static PyObject *BakedElement_from(ufbx_baked_element *data, Context *ctx) {
    BakedElement *obj = (BakedElement*)PyObject_CallObject((PyObject*)&BakedElement_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int BakedAnimMetadata_traverse(BakedAnimMetadata *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_ANIM_METADATA; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BakedAnimMetadata_clear(BakedAnimMetadata *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_ANIM_METADATA; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BakedAnimMetadata_dealloc(BakedAnimMetadata *self) {
    PyObject_GC_UnTrack(self);
    BakedAnimMetadata_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BakedAnimMetadata_dealloc,
    .tp_traverse = (traverseproc)&BakedAnimMetadata_traverse,
    .tp_clear = (inquiry)&BakedAnimMetadata_clear,
    .tp_getset = BakedAnimMetadata_getset,
};

static PyObject *BakedAnimMetadata_from(ufbx_baked_anim_metadata *data, Context *ctx) {
    BakedAnimMetadata *obj = (BakedAnimMetadata*)PyObject_CallObject((PyObject*)&BakedAnimMetadata_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = BakedAnimMetadata_from(&self->data->metadata, self->ctx);
    self->slots[SLOT_BAKED_ANIM__METADATA] = slot;
    return Py_NewRef(slot);
}

static int BakedAnim_traverse(BakedAnim *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_ANIM; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int BakedAnim_clear(BakedAnim *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_BAKED_ANIM; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void BakedAnim_dealloc(BakedAnim *self) {
    PyObject_GC_UnTrack(self);
    BakedAnim_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&BakedAnim_dealloc,
    .tp_traverse = (traverseproc)&BakedAnim_traverse,
    .tp_clear = (inquiry)&BakedAnim_clear,
    .tp_getset = BakedAnim_getset,
};

static PyObject *BakedAnim_from(ufbx_baked_anim *data, Context *ctx) {
    BakedAnim *obj = (BakedAnim*)PyObject_CallObject((PyObject*)&BakedAnim_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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

static int ThreadPoolInfo_traverse(ThreadPoolInfo *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_THREAD_POOL_INFO; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int ThreadPoolInfo_clear(ThreadPoolInfo *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_THREAD_POOL_INFO; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void ThreadPoolInfo_dealloc(ThreadPoolInfo *self) {
    PyObject_GC_UnTrack(self);
    ThreadPoolInfo_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&ThreadPoolInfo_dealloc,
    .tp_traverse = (traverseproc)&ThreadPoolInfo_traverse,
    .tp_clear = (inquiry)&ThreadPoolInfo_clear,
    .tp_getset = ThreadPoolInfo_getset,
};

static PyObject *ThreadPoolInfo_from(ufbx_thread_pool_info *data, Context *ctx) {
    ThreadPoolInfo *obj = (ThreadPoolInfo*)PyObject_CallObject((PyObject*)&ThreadPoolInfo_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

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
    slot = Py_NewRef(self->data->did_panic ? Py_True : Py_False);
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

static int Panic_traverse(Panic *self, visitproc visit, void *arg) {
    Py_VISIT(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_PANIC; i++) {
        Py_VISIT(self->slots[i]);
    }
    return 0;
}

static int Panic_clear(Panic *self) {
    Py_CLEAR(self->ctx);
    for (size_t i = 0; i < SLOT_COUNT_PANIC; i++) {
        Py_CLEAR(self->slots[i]);
    }
    return 0;
}

void Panic_dealloc(Panic *self) {
    PyObject_GC_UnTrack(self);
    Panic_clear(self);
    Py_TYPE(self)->tp_free((PyObject *) self);
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
    .tp_flags = Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,
    .tp_new = PyType_GenericNew,
    .tp_dealloc = (destructor)&Panic_dealloc,
    .tp_traverse = (traverseproc)&Panic_traverse,
    .tp_clear = (inquiry)&Panic_clear,
    .tp_getset = Panic_getset,
};

static PyObject *Panic_from(ufbx_panic *data, Context *ctx) {
    Panic *obj = (Panic*)PyObject_CallObject((PyObject*)&Panic_Type, NULL);
    if (!obj) return NULL;
    obj->ctx = (Context*)Py_NewRef(ctx);
    obj->data = data;
    return (PyObject*)obj;
}

static int to_allocator_opts(ufbx_allocator_opts *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "memory_limit");
    if (value) {
        dst->memory_limit = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "allocation_limit");
    if (value) {
        dst->allocation_limit = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "huge_threshold");
    if (value) {
        dst->huge_threshold = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "max_chunk_size");
    if (value) {
        dst->max_chunk_size = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static int to_open_memory_opts(ufbx_open_memory_opts *dst, PyObject *src) {
    if (!src) return 0;
    return 0;
}

static int to_thread_opts(ufbx_thread_opts *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "num_tasks");
    if (value) {
        dst->num_tasks = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "memory_limit");
    if (value) {
        dst->memory_limit = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static int to_load_opts(ufbx_load_opts *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "ignore_geometry");
    if (value) {
        dst->ignore_geometry = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "ignore_animation");
    if (value) {
        dst->ignore_animation = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "ignore_embedded");
    if (value) {
        dst->ignore_embedded = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "ignore_all_content");
    if (value) {
        dst->ignore_all_content = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "evaluate_skinning");
    if (value) {
        dst->evaluate_skinning = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "evaluate_caches");
    if (value) {
        dst->evaluate_caches = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "load_external_files");
    if (value) {
        dst->load_external_files = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "ignore_missing_external_files");
    if (value) {
        dst->ignore_missing_external_files = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "skip_skin_vertices");
    if (value) {
        dst->skip_skin_vertices = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "skip_mesh_parts");
    if (value) {
        dst->skip_mesh_parts = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "clean_skin_weights");
    if (value) {
        dst->clean_skin_weights = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "use_blender_pbr_material");
    if (value) {
        dst->use_blender_pbr_material = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "disable_quirks");
    if (value) {
        dst->disable_quirks = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "strict");
    if (value) {
        dst->strict = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "force_single_thread_ascii_parsing");
    if (value) {
        dst->force_single_thread_ascii_parsing = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "index_error_handling");
    if (value) {
        dst->index_error_handling = (ufbx_index_error_handling)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "connect_broken_elements");
    if (value) {
        dst->connect_broken_elements = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "allow_nodes_out_of_root");
    if (value) {
        dst->allow_nodes_out_of_root = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "allow_missing_vertex_position");
    if (value) {
        dst->allow_missing_vertex_position = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "allow_empty_faces");
    if (value) {
        dst->allow_empty_faces = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "generate_missing_normals");
    if (value) {
        dst->generate_missing_normals = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "open_main_file_with_default");
    if (value) {
        dst->open_main_file_with_default = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "path_separator");
    if (value) {
        dst->path_separator = (char)PyLong_AsUnsignedLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "node_depth_limit");
    if (value) {
        dst->node_depth_limit = (uint32_t)PyLong_AsUnsignedLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "file_size_estimate");
    if (value) {
        dst->file_size_estimate = (uint64_t)PyLong_AsUnsignedLongLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "read_buffer_size");
    if (value) {
        dst->read_buffer_size = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "progress_interval_hint");
    if (value) {
        dst->progress_interval_hint = (uint64_t)PyLong_AsUnsignedLongLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "geometry_transform_handling");
    if (value) {
        dst->geometry_transform_handling = (ufbx_geometry_transform_handling)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "inherit_mode_handling");
    if (value) {
        dst->inherit_mode_handling = (ufbx_inherit_mode_handling)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "space_conversion");
    if (value) {
        dst->space_conversion = (ufbx_space_conversion)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "pivot_handling");
    if (value) {
        dst->pivot_handling = (ufbx_pivot_handling)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "pivot_handling_retain_empties");
    if (value) {
        dst->pivot_handling_retain_empties = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "handedness_conversion_axis");
    if (value) {
        dst->handedness_conversion_axis = (ufbx_mirror_axis)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "handedness_conversion_retain_winding");
    if (value) {
        dst->handedness_conversion_retain_winding = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "reverse_winding");
    if (value) {
        dst->reverse_winding = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "target_axes");
    if (value) {
        dst->target_axes = CoordinateAxes_to(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "target_unit_meters");
    if (value) {
        dst->target_unit_meters = (ufbx_real)PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "target_camera_axes");
    if (value) {
        dst->target_camera_axes = CoordinateAxes_to(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "target_light_axes");
    if (value) {
        dst->target_light_axes = CoordinateAxes_to(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "normalize_normals");
    if (value) {
        dst->normalize_normals = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "normalize_tangents");
    if (value) {
        dst->normalize_tangents = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "use_root_transform");
    if (value) {
        dst->use_root_transform = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "root_transform");
    if (value) {
        dst->root_transform = Transform_to(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "key_clamp_threshold");
    if (value) {
        dst->key_clamp_threshold = PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "unicode_error_handling");
    if (value) {
        dst->unicode_error_handling = (ufbx_unicode_error_handling)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "retain_vertex_attrib_w");
    if (value) {
        dst->retain_vertex_attrib_w = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "retain_dom");
    if (value) {
        dst->retain_dom = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "file_format");
    if (value) {
        dst->file_format = (ufbx_file_format)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "file_format_lookahead");
    if (value) {
        dst->file_format_lookahead = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "no_format_from_content");
    if (value) {
        dst->no_format_from_content = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "no_format_from_extension");
    if (value) {
        dst->no_format_from_extension = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "obj_search_mtl_by_filename");
    if (value) {
        dst->obj_search_mtl_by_filename = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "obj_merge_objects");
    if (value) {
        dst->obj_merge_objects = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "obj_merge_groups");
    if (value) {
        dst->obj_merge_groups = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "obj_split_groups");
    if (value) {
        dst->obj_split_groups = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "obj_unit_meters");
    if (value) {
        dst->obj_unit_meters = (ufbx_real)PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "obj_axes");
    if (value) {
        dst->obj_axes = CoordinateAxes_to(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static int to_evaluate_opts(ufbx_evaluate_opts *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "evaluate_skinning");
    if (value) {
        dst->evaluate_skinning = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "evaluate_caches");
    if (value) {
        dst->evaluate_caches = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "evaluate_flags");
    if (value) {
        dst->evaluate_flags = (uint32_t)PyLong_AsUnsignedLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "load_external_files");
    if (value) {
        dst->load_external_files = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static int to_prop_override_desc(ufbx_prop_override_desc *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "element_id");
    if (value) {
        dst->element_id = (uint32_t)PyLong_AsUnsignedLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "value");
    if (value) {
        dst->value = Vec4_to(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "value_int");
    if (value) {
        dst->value_int = (int64_t)PyLong_AsLongLong(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static int to_anim_opts(ufbx_anim_opts *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "ignore_connections");
    if (value) {
        dst->ignore_connections = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static int to_bake_opts(ufbx_bake_opts *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "trim_start_time");
    if (value) {
        dst->trim_start_time = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "resample_rate");
    if (value) {
        dst->resample_rate = PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "minimum_sample_rate");
    if (value) {
        dst->minimum_sample_rate = PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "maximum_sample_rate");
    if (value) {
        dst->maximum_sample_rate = PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "bake_transform_props");
    if (value) {
        dst->bake_transform_props = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "skip_node_transforms");
    if (value) {
        dst->skip_node_transforms = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "no_resample_rotation");
    if (value) {
        dst->no_resample_rotation = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "ignore_layer_weight_animation");
    if (value) {
        dst->ignore_layer_weight_animation = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "max_keyframe_segments");
    if (value) {
        dst->max_keyframe_segments = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "step_handling");
    if (value) {
        dst->step_handling = (ufbx_bake_step_handling)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "step_custom_duration");
    if (value) {
        dst->step_custom_duration = PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "step_custom_epsilon");
    if (value) {
        dst->step_custom_epsilon = PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "evaluate_flags");
    if (value) {
        dst->evaluate_flags = (uint32_t)PyLong_AsUnsignedLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "key_reduction_enabled");
    if (value) {
        dst->key_reduction_enabled = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "key_reduction_rotation");
    if (value) {
        dst->key_reduction_rotation = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "key_reduction_threshold");
    if (value) {
        dst->key_reduction_threshold = PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "key_reduction_passes");
    if (value) {
        dst->key_reduction_passes = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static int to_tessellate_curve_opts(ufbx_tessellate_curve_opts *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "span_subdivision");
    if (value) {
        dst->span_subdivision = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static int to_tessellate_surface_opts(ufbx_tessellate_surface_opts *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "span_subdivision_u");
    if (value) {
        dst->span_subdivision_u = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "span_subdivision_v");
    if (value) {
        dst->span_subdivision_v = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "skip_mesh_parts");
    if (value) {
        dst->skip_mesh_parts = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static int to_subdivide_opts(ufbx_subdivide_opts *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "boundary");
    if (value) {
        dst->boundary = (ufbx_subdivision_boundary)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "uv_boundary");
    if (value) {
        dst->uv_boundary = (ufbx_subdivision_boundary)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "ignore_normals");
    if (value) {
        dst->ignore_normals = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "interpolate_normals");
    if (value) {
        dst->interpolate_normals = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "interpolate_tangents");
    if (value) {
        dst->interpolate_tangents = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "evaluate_source_vertices");
    if (value) {
        dst->evaluate_source_vertices = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "max_source_vertices");
    if (value) {
        dst->max_source_vertices = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "evaluate_skin_weights");
    if (value) {
        dst->evaluate_skin_weights = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "max_skin_weights");
    if (value) {
        dst->max_skin_weights = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "skin_deformer_index");
    if (value) {
        dst->skin_deformer_index = PyLong_AsSize_t(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static int to_geometry_cache_opts(ufbx_geometry_cache_opts *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "frames_per_second");
    if (value) {
        dst->frames_per_second = PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "mirror_axis");
    if (value) {
        dst->mirror_axis = (ufbx_mirror_axis)PyLong_AsLong(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "use_scale_factor");
    if (value) {
        dst->use_scale_factor = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "scale_factor");
    if (value) {
        dst->scale_factor = (ufbx_real)PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static int to_geometry_cache_data_opts(ufbx_geometry_cache_data_opts *dst, PyObject *src) {
    if (!src) return 0;
    PyObject *value;
    value = PyDict_GetItemString(src, "additive");
    if (value) {
        dst->additive = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "use_weight");
    if (value) {
        dst->use_weight = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "weight");
    if (value) {
        dst->weight = (ufbx_real)PyFloat_AsDouble(value);
        if (PyErr_Occurred()) return -1;
    }
    value = PyDict_GetItemString(src, "ignore_transform");
    if (value) {
        dst->ignore_transform = PyObject_IsTrue(value);
        if (PyErr_Occurred()) return -1;
    }
    return 0;
}

static PyObject *mod_is_thread_safe(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, "")) {
        return NULL;
    }
    bool ret = ufbx_is_thread_safe();
    return Py_NewRef(ret ? Py_True : Py_False);
}

static PyObject *mod_load_memory(PyObject *self, PyObject *args, PyObject *kwargs) {
    const char *data;
    Py_ssize_t data_len;
    ufbx_load_opts opts = { 0 };
    ufbx_error error;
    if (!PyArg_ParseTuple(args, "z#", &data, &data_len)) {
        return NULL;
    }
    if (to_load_opts(&opts, kwargs) < 0) {
        return NULL;
    }
    ufbx_scene* ret = ufbx_load_memory(data, (size_t)data_len, &opts, &error);
    if (error.type != UFBX_ERROR_NONE) {
        return UfbxError_raise(&error);
    }
    return Scene_create(ret);
}

static PyObject *mod_load_file(PyObject *self, PyObject *args, PyObject *kwargs) {
    const char *filename;
    Py_ssize_t filename_len;
    ufbx_load_opts opts = { 0 };
    ufbx_error error;
    if (!PyArg_ParseTuple(args, "s#", &filename, &filename_len)) {
        return NULL;
    }
    if (to_load_opts(&opts, kwargs) < 0) {
        return NULL;
    }
    ufbx_scene* ret = ufbx_load_file_len(filename, (size_t)filename_len, &opts, &error);
    if (error.type != UFBX_ERROR_NONE) {
        return UfbxError_raise(&error);
    }
    return Scene_create(ret);
}

static PyObject *mod_find_prop(PyObject *self, PyObject *args) {
    Props *props;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "O!s#", &Props_Type, &props, &name, &name_len)) {
        return NULL;
    }
    if (!props->ctx->ok) {
        return Context_error(props->ctx);
    }
    ufbx_prop* ret = ufbx_find_prop_len(props->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_prop*");
}

static PyObject *mod_find_real(PyObject *self, PyObject *args) {
    Props *props;
    const char *name;
    Py_ssize_t name_len;
    double def;
    if (!PyArg_ParseTuple(args, "O!s#d", &Props_Type, &props, &name, &name_len, &def)) {
        return NULL;
    }
    if (!props->ctx->ok) {
        return Context_error(props->ctx);
    }
    ufbx_real ret = ufbx_find_real_len(props->data, name, (size_t)name_len, (ufbx_real)def);
    return PyFloat_FromDouble(ret);
}

static PyObject *mod_find_vec3(PyObject *self, PyObject *args) {
    Props *props;
    const char *name;
    Py_ssize_t name_len;
    PyObject *def_obj;
    ufbx_vec3 def;
    if (!PyArg_ParseTuple(args, "O!s#O!", &Props_Type, &props, &name, &name_len, &Vec3_Type, &def_obj)) {
        return NULL;
    }
    if (!props->ctx->ok) {
        return Context_error(props->ctx);
    }
    def = Vec3_to(def_obj);
    ufbx_vec3 ret = ufbx_find_vec3_len(props->data, name, (size_t)name_len, def);
    return Vec3_from(&ret);
}

static PyObject *mod_find_int(PyObject *self, PyObject *args) {
    Props *props;
    const char *name;
    Py_ssize_t name_len;
    long long def;
    if (!PyArg_ParseTuple(args, "O!s#L", &Props_Type, &props, &name, &name_len, &def)) {
        return NULL;
    }
    if (!props->ctx->ok) {
        return Context_error(props->ctx);
    }
    int64_t ret = ufbx_find_int_len(props->data, name, (size_t)name_len, (int64_t)def);
    return PyLong_FromLongLong((long long)ret);
}

static PyObject *mod_find_bool(PyObject *self, PyObject *args) {
    Props *props;
    const char *name;
    Py_ssize_t name_len;
    int def;
    if (!PyArg_ParseTuple(args, "O!s#p", &Props_Type, &props, &name, &name_len, &def)) {
        return NULL;
    }
    if (!props->ctx->ok) {
        return Context_error(props->ctx);
    }
    bool ret = ufbx_find_bool_len(props->data, name, (size_t)name_len, def != 0);
    return Py_NewRef(ret ? Py_True : Py_False);
}

static PyObject *mod_find_node(PyObject *self, PyObject *args) {
    Scene *scene;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "O!s#", &Scene_Type, &scene, &name, &name_len)) {
        return NULL;
    }
    if (!scene->ctx->ok) {
        return Context_error(scene->ctx);
    }
    ufbx_node* ret = ufbx_find_node_len(scene->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, scene->ctx);
}

static PyObject *mod_find_anim_stack(PyObject *self, PyObject *args) {
    Scene *scene;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "O!s#", &Scene_Type, &scene, &name, &name_len)) {
        return NULL;
    }
    if (!scene->ctx->ok) {
        return Context_error(scene->ctx);
    }
    ufbx_anim_stack* ret = ufbx_find_anim_stack_len(scene->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, scene->ctx);
}

static PyObject *mod_find_material(PyObject *self, PyObject *args) {
    Scene *scene;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "O!s#", &Scene_Type, &scene, &name, &name_len)) {
        return NULL;
    }
    if (!scene->ctx->ok) {
        return Context_error(scene->ctx);
    }
    ufbx_material* ret = ufbx_find_material_len(scene->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, scene->ctx);
}

static PyObject *mod_find_anim_prop(PyObject *self, PyObject *args) {
    AnimLayer *layer;
    Element *element;
    const char *prop;
    Py_ssize_t prop_len;
    if (!PyArg_ParseTuple(args, "O!O!s#", &AnimLayer_Type, &layer, &Element_Type, &element, &prop, &prop_len)) {
        return NULL;
    }
    if (!layer->ctx->ok) {
        return Context_error(layer->ctx);
    }
    ufbx_anim_prop* ret = ufbx_find_anim_prop_len(layer->data, element->data, prop, (size_t)prop_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_anim_prop*");
}

static PyObject *mod_find_anim_props(PyObject *self, PyObject *args) {
    AnimLayer *layer;
    Element *element;
    if (!PyArg_ParseTuple(args, "O!O!", &AnimLayer_Type, &layer, &Element_Type, &element)) {
        return NULL;
    }
    if (!layer->ctx->ok) {
        return Context_error(layer->ctx);
    }
    ufbx_anim_prop_list ret = ufbx_find_anim_props(layer->data, element->data);
    return AnimPropList_from(ret, layer->ctx);
}

static PyObject *mod_get_compatible_matrix_for_normals(PyObject *self, PyObject *args) {
    Node *node;
    if (!PyArg_ParseTuple(args, "O!", &Node_Type, &node)) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_matrix ret = ufbx_get_compatible_matrix_for_normals(node->data);
    return Matrix_from(&ret);
}

static PyObject *mod_evaluate_curve(PyObject *self, PyObject *args) {
    AnimCurve *curve;
    double time;
    double default_value;
    if (!PyArg_ParseTuple(args, "O!dd", &AnimCurve_Type, &curve, &time, &default_value)) {
        return NULL;
    }
    if (!curve->ctx->ok) {
        return Context_error(curve->ctx);
    }
    ufbx_real ret = ufbx_evaluate_curve(curve->data, time, (ufbx_real)default_value);
    return PyFloat_FromDouble(ret);
}

static PyObject *mod_evaluate_curve_flags(PyObject *self, PyObject *args) {
    AnimCurve *curve;
    double time;
    double default_value;
    unsigned int flags;
    if (!PyArg_ParseTuple(args, "O!ddI", &AnimCurve_Type, &curve, &time, &default_value, &flags)) {
        return NULL;
    }
    if (!curve->ctx->ok) {
        return Context_error(curve->ctx);
    }
    ufbx_real ret = ufbx_evaluate_curve_flags(curve->data, time, (ufbx_real)default_value, (uint32_t)flags);
    return PyFloat_FromDouble(ret);
}

static PyObject *mod_evaluate_anim_value_real(PyObject *self, PyObject *args) {
    AnimValue *anim_value;
    double time;
    if (!PyArg_ParseTuple(args, "O!d", &AnimValue_Type, &anim_value, &time)) {
        return NULL;
    }
    if (!anim_value->ctx->ok) {
        return Context_error(anim_value->ctx);
    }
    ufbx_real ret = ufbx_evaluate_anim_value_real(anim_value->data, time);
    return PyFloat_FromDouble(ret);
}

static PyObject *mod_evaluate_anim_value_vec3(PyObject *self, PyObject *args) {
    AnimValue *anim_value;
    double time;
    if (!PyArg_ParseTuple(args, "O!d", &AnimValue_Type, &anim_value, &time)) {
        return NULL;
    }
    if (!anim_value->ctx->ok) {
        return Context_error(anim_value->ctx);
    }
    ufbx_vec3 ret = ufbx_evaluate_anim_value_vec3(anim_value->data, time);
    return Vec3_from(&ret);
}

static PyObject *mod_evaluate_anim_value_real_flags(PyObject *self, PyObject *args) {
    AnimValue *anim_value;
    double time;
    unsigned int flags;
    if (!PyArg_ParseTuple(args, "O!dI", &AnimValue_Type, &anim_value, &time, &flags)) {
        return NULL;
    }
    if (!anim_value->ctx->ok) {
        return Context_error(anim_value->ctx);
    }
    ufbx_real ret = ufbx_evaluate_anim_value_real_flags(anim_value->data, time, (uint32_t)flags);
    return PyFloat_FromDouble(ret);
}

static PyObject *mod_evaluate_anim_value_vec3_flags(PyObject *self, PyObject *args) {
    AnimValue *anim_value;
    double time;
    unsigned int flags;
    if (!PyArg_ParseTuple(args, "O!dI", &AnimValue_Type, &anim_value, &time, &flags)) {
        return NULL;
    }
    if (!anim_value->ctx->ok) {
        return Context_error(anim_value->ctx);
    }
    ufbx_vec3 ret = ufbx_evaluate_anim_value_vec3_flags(anim_value->data, time, (uint32_t)flags);
    return Vec3_from(&ret);
}

static PyObject *mod_evaluate_props_flags(PyObject *self, PyObject *args) {
    Anim *anim;
    Element *element;
    double time;
    Prop *buffer;
    Py_ssize_t buffer_size;
    unsigned int flags;
    if (!PyArg_ParseTuple(args, "O!O!dO!nI", &Anim_Type, &anim, &Element_Type, &element, &time, &Prop_Type, &buffer, &buffer_size, &flags)) {
        return NULL;
    }
    if (!anim->ctx->ok) {
        return Context_error(anim->ctx);
    }
    ufbx_props ret = ufbx_evaluate_props_flags(anim->data, element->data, time, buffer->data, (size_t)buffer_size, (uint32_t)flags);
    return Props_from(&ret, anim->ctx);
}

static PyObject *mod_evaluate_transform(PyObject *self, PyObject *args) {
    Anim *anim;
    Node *node;
    double time;
    if (!PyArg_ParseTuple(args, "O!O!d", &Anim_Type, &anim, &Node_Type, &node, &time)) {
        return NULL;
    }
    if (!anim->ctx->ok) {
        return Context_error(anim->ctx);
    }
    ufbx_transform ret = ufbx_evaluate_transform(anim->data, node->data, time);
    return Transform_from(&ret);
}

static PyObject *mod_evaluate_transform_flags(PyObject *self, PyObject *args) {
    Anim *anim;
    Node *node;
    double time;
    unsigned int flags;
    if (!PyArg_ParseTuple(args, "O!O!dI", &Anim_Type, &anim, &Node_Type, &node, &time, &flags)) {
        return NULL;
    }
    if (!anim->ctx->ok) {
        return Context_error(anim->ctx);
    }
    ufbx_transform ret = ufbx_evaluate_transform_flags(anim->data, node->data, time, (uint32_t)flags);
    return Transform_from(&ret);
}

static PyObject *mod_evaluate_blend_weight(PyObject *self, PyObject *args) {
    Anim *anim;
    BlendChannel *channel;
    double time;
    if (!PyArg_ParseTuple(args, "O!O!d", &Anim_Type, &anim, &BlendChannel_Type, &channel, &time)) {
        return NULL;
    }
    if (!anim->ctx->ok) {
        return Context_error(anim->ctx);
    }
    ufbx_real ret = ufbx_evaluate_blend_weight(anim->data, channel->data, time);
    return PyFloat_FromDouble(ret);
}

static PyObject *mod_evaluate_blend_weight_flags(PyObject *self, PyObject *args) {
    Anim *anim;
    BlendChannel *channel;
    double time;
    unsigned int flags;
    if (!PyArg_ParseTuple(args, "O!O!dI", &Anim_Type, &anim, &BlendChannel_Type, &channel, &time, &flags)) {
        return NULL;
    }
    if (!anim->ctx->ok) {
        return Context_error(anim->ctx);
    }
    ufbx_real ret = ufbx_evaluate_blend_weight_flags(anim->data, channel->data, time, (uint32_t)flags);
    return PyFloat_FromDouble(ret);
}

static PyObject *mod_evaluate_scene(PyObject *self, PyObject *args, PyObject *kwargs) {
    Scene *scene;
    Anim *anim;
    double time;
    ufbx_evaluate_opts opts = { 0 };
    ufbx_error error;
    if (!PyArg_ParseTuple(args, "O!O!d", &Scene_Type, &scene, &Anim_Type, &anim, &time)) {
        return NULL;
    }
    if (!scene->ctx->ok) {
        return Context_error(scene->ctx);
    }
    if (to_evaluate_opts(&opts, kwargs) < 0) {
        return NULL;
    }
    ufbx_scene* ret = ufbx_evaluate_scene(scene->data, anim->data, time, &opts, &error);
    if (error.type != UFBX_ERROR_NONE) {
        return UfbxError_raise(&error);
    }
    return Scene_create(ret);
}

static PyObject *mod_create_anim(PyObject *self, PyObject *args, PyObject *kwargs) {
    Scene *scene;
    ufbx_anim_opts opts = { 0 };
    ufbx_error error;
    if (!PyArg_ParseTuple(args, "O!", &Scene_Type, &scene)) {
        return NULL;
    }
    if (!scene->ctx->ok) {
        return Context_error(scene->ctx);
    }
    if (to_anim_opts(&opts, kwargs) < 0) {
        return NULL;
    }
    ufbx_anim* ret = ufbx_create_anim(scene->data, &opts, &error);
    if (error.type != UFBX_ERROR_NONE) {
        return UfbxError_raise(&error);
    }
    return Anim_create(ret);
}

static PyObject *mod_bake_anim(PyObject *self, PyObject *args, PyObject *kwargs) {
    Scene *scene;
    Anim *anim;
    ufbx_bake_opts opts = { 0 };
    ufbx_error error;
    if (!PyArg_ParseTuple(args, "O!O!", &Scene_Type, &scene, &Anim_Type, &anim)) {
        return NULL;
    }
    if (!scene->ctx->ok) {
        return Context_error(scene->ctx);
    }
    if (to_bake_opts(&opts, kwargs) < 0) {
        return NULL;
    }
    ufbx_baked_anim* ret = ufbx_bake_anim(scene->data, anim->data, &opts, &error);
    if (error.type != UFBX_ERROR_NONE) {
        return UfbxError_raise(&error);
    }
    return to_pyobject_todo("ufbx_baked_anim*");
}

static PyObject *mod_find_baked_node_by_typed_id(PyObject *self, PyObject *args) {
    BakedAnim *bake;
    unsigned int typed_id;
    if (!PyArg_ParseTuple(args, "O!I", &BakedAnim_Type, &bake, &typed_id)) {
        return NULL;
    }
    if (!bake->ctx->ok) {
        return Context_error(bake->ctx);
    }
    ufbx_baked_node* ret = ufbx_find_baked_node_by_typed_id(bake->data, (uint32_t)typed_id);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_baked_node*");
}

static PyObject *mod_find_baked_node(PyObject *self, PyObject *args) {
    BakedAnim *bake;
    Node *node;
    if (!PyArg_ParseTuple(args, "O!O!", &BakedAnim_Type, &bake, &Node_Type, &node)) {
        return NULL;
    }
    if (!bake->ctx->ok) {
        return Context_error(bake->ctx);
    }
    ufbx_baked_node* ret = ufbx_find_baked_node(bake->data, node->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_baked_node*");
}

static PyObject *mod_find_baked_element_by_element_id(PyObject *self, PyObject *args) {
    BakedAnim *bake;
    unsigned int element_id;
    if (!PyArg_ParseTuple(args, "O!I", &BakedAnim_Type, &bake, &element_id)) {
        return NULL;
    }
    if (!bake->ctx->ok) {
        return Context_error(bake->ctx);
    }
    ufbx_baked_element* ret = ufbx_find_baked_element_by_element_id(bake->data, (uint32_t)element_id);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_baked_element*");
}

static PyObject *mod_find_baked_element(PyObject *self, PyObject *args) {
    BakedAnim *bake;
    Element *element;
    if (!PyArg_ParseTuple(args, "O!O!", &BakedAnim_Type, &bake, &Element_Type, &element)) {
        return NULL;
    }
    if (!bake->ctx->ok) {
        return Context_error(bake->ctx);
    }
    ufbx_baked_element* ret = ufbx_find_baked_element(bake->data, element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_baked_element*");
}

static PyObject *mod_get_bone_pose(PyObject *self, PyObject *args) {
    Pose *pose;
    Node *node;
    if (!PyArg_ParseTuple(args, "O!O!", &Pose_Type, &pose, &Node_Type, &node)) {
        return NULL;
    }
    if (!pose->ctx->ok) {
        return Context_error(pose->ctx);
    }
    ufbx_bone_pose* ret = ufbx_get_bone_pose(pose->data, node->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_bone_pose*");
}

static PyObject *mod_find_prop_texture(PyObject *self, PyObject *args) {
    Material *material;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "O!s#", &Material_Type, &material, &name, &name_len)) {
        return NULL;
    }
    if (!material->ctx->ok) {
        return Context_error(material->ctx);
    }
    ufbx_texture* ret = ufbx_find_prop_texture_len(material->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, material->ctx);
}

static PyObject *mod_find_shader_prop(PyObject *self, PyObject *args) {
    Shader *shader;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "O!s#", &Shader_Type, &shader, &name, &name_len)) {
        return NULL;
    }
    if (!shader->ctx->ok) {
        return Context_error(shader->ctx);
    }
    ufbx_string ret = ufbx_find_shader_prop_len(shader->data, name, (size_t)name_len);
    return String_from(ret);
}

static PyObject *mod_find_shader_prop_bindings(PyObject *self, PyObject *args) {
    Shader *shader;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "O!s#", &Shader_Type, &shader, &name, &name_len)) {
        return NULL;
    }
    if (!shader->ctx->ok) {
        return Context_error(shader->ctx);
    }
    ufbx_shader_prop_binding_list ret = ufbx_find_shader_prop_bindings_len(shader->data, name, (size_t)name_len);
    return ShaderPropBindingList_from(ret, shader->ctx);
}

static PyObject *mod_find_shader_texture_input(PyObject *self, PyObject *args) {
    ShaderTexture *shader;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "O!s#", &ShaderTexture_Type, &shader, &name, &name_len)) {
        return NULL;
    }
    if (!shader->ctx->ok) {
        return Context_error(shader->ctx);
    }
    ufbx_shader_texture_input* ret = ufbx_find_shader_texture_input_len(shader->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_shader_texture_input*");
}

static PyObject *mod_vec3_normalize(PyObject *self, PyObject *args) {
    PyObject *v_obj;
    ufbx_vec3 v;
    if (!PyArg_ParseTuple(args, "O!", &Vec3_Type, &v_obj)) {
        return NULL;
    }
    v = Vec3_to(v_obj);
    ufbx_vec3 ret = ufbx_vec3_normalize(v);
    return Vec3_from(&ret);
}

static PyObject *mod_quat_dot(PyObject *self, PyObject *args) {
    PyObject *a_obj;
    ufbx_quat a;
    PyObject *b_obj;
    ufbx_quat b;
    if (!PyArg_ParseTuple(args, "O!O!", &Quat_Type, &a_obj, &Quat_Type, &b_obj)) {
        return NULL;
    }
    a = Quat_to(a_obj);
    b = Quat_to(b_obj);
    ufbx_real ret = ufbx_quat_dot(a, b);
    return PyFloat_FromDouble(ret);
}

static PyObject *mod_quat_mul(PyObject *self, PyObject *args) {
    PyObject *a_obj;
    ufbx_quat a;
    PyObject *b_obj;
    ufbx_quat b;
    if (!PyArg_ParseTuple(args, "O!O!", &Quat_Type, &a_obj, &Quat_Type, &b_obj)) {
        return NULL;
    }
    a = Quat_to(a_obj);
    b = Quat_to(b_obj);
    ufbx_quat ret = ufbx_quat_mul(a, b);
    return Quat_from(&ret);
}

static PyObject *mod_quat_normalize(PyObject *self, PyObject *args) {
    PyObject *q_obj;
    ufbx_quat q;
    if (!PyArg_ParseTuple(args, "O!", &Quat_Type, &q_obj)) {
        return NULL;
    }
    q = Quat_to(q_obj);
    ufbx_quat ret = ufbx_quat_normalize(q);
    return Quat_from(&ret);
}

static PyObject *mod_quat_fix_antipodal(PyObject *self, PyObject *args) {
    PyObject *q_obj;
    ufbx_quat q;
    PyObject *reference_obj;
    ufbx_quat reference;
    if (!PyArg_ParseTuple(args, "O!O!", &Quat_Type, &q_obj, &Quat_Type, &reference_obj)) {
        return NULL;
    }
    q = Quat_to(q_obj);
    reference = Quat_to(reference_obj);
    ufbx_quat ret = ufbx_quat_fix_antipodal(q, reference);
    return Quat_from(&ret);
}

static PyObject *mod_quat_slerp(PyObject *self, PyObject *args) {
    PyObject *a_obj;
    ufbx_quat a;
    PyObject *b_obj;
    ufbx_quat b;
    double t;
    if (!PyArg_ParseTuple(args, "O!O!d", &Quat_Type, &a_obj, &Quat_Type, &b_obj, &t)) {
        return NULL;
    }
    a = Quat_to(a_obj);
    b = Quat_to(b_obj);
    ufbx_quat ret = ufbx_quat_slerp(a, b, (ufbx_real)t);
    return Quat_from(&ret);
}

static PyObject *mod_quat_rotate_vec3(PyObject *self, PyObject *args) {
    PyObject *q_obj;
    ufbx_quat q;
    PyObject *v_obj;
    ufbx_vec3 v;
    if (!PyArg_ParseTuple(args, "O!O!", &Quat_Type, &q_obj, &Vec3_Type, &v_obj)) {
        return NULL;
    }
    q = Quat_to(q_obj);
    v = Vec3_to(v_obj);
    ufbx_vec3 ret = ufbx_quat_rotate_vec3(q, v);
    return Vec3_from(&ret);
}

static PyObject *mod_get_blend_shape_offset_index(PyObject *self, PyObject *args) {
    BlendShape *shape;
    Py_ssize_t vertex;
    if (!PyArg_ParseTuple(args, "O!n", &BlendShape_Type, &shape, &vertex)) {
        return NULL;
    }
    if (!shape->ctx->ok) {
        return Context_error(shape->ctx);
    }
    uint32_t ret = ufbx_get_blend_shape_offset_index(shape->data, (size_t)vertex);
    return PyLong_FromUnsignedLong((unsigned long)ret);
}

static PyObject *mod_get_blend_shape_vertex_offset(PyObject *self, PyObject *args) {
    BlendShape *shape;
    Py_ssize_t vertex;
    if (!PyArg_ParseTuple(args, "O!n", &BlendShape_Type, &shape, &vertex)) {
        return NULL;
    }
    if (!shape->ctx->ok) {
        return Context_error(shape->ctx);
    }
    ufbx_vec3 ret = ufbx_get_blend_shape_vertex_offset(shape->data, (size_t)vertex);
    return Vec3_from(&ret);
}

static PyObject *mod_get_blend_vertex_offset(PyObject *self, PyObject *args) {
    BlendDeformer *blend;
    Py_ssize_t vertex;
    if (!PyArg_ParseTuple(args, "O!n", &BlendDeformer_Type, &blend, &vertex)) {
        return NULL;
    }
    if (!blend->ctx->ok) {
        return Context_error(blend->ctx);
    }
    ufbx_vec3 ret = ufbx_get_blend_vertex_offset(blend->data, (size_t)vertex);
    return Vec3_from(&ret);
}

static PyObject *mod_evaluate_nurbs_curve(PyObject *self, PyObject *args) {
    NurbsCurve *curve;
    double u;
    if (!PyArg_ParseTuple(args, "O!d", &NurbsCurve_Type, &curve, &u)) {
        return NULL;
    }
    if (!curve->ctx->ok) {
        return Context_error(curve->ctx);
    }
    ufbx_curve_point ret = ufbx_evaluate_nurbs_curve(curve->data, (ufbx_real)u);
    return CurvePoint_from(&ret);
}

static PyObject *mod_evaluate_nurbs_surface(PyObject *self, PyObject *args) {
    NurbsSurface *surface;
    double u;
    double v;
    if (!PyArg_ParseTuple(args, "O!dd", &NurbsSurface_Type, &surface, &u, &v)) {
        return NULL;
    }
    if (!surface->ctx->ok) {
        return Context_error(surface->ctx);
    }
    ufbx_surface_point ret = ufbx_evaluate_nurbs_surface(surface->data, (ufbx_real)u, (ufbx_real)v);
    return SurfacePoint_from(&ret);
}

static PyObject *mod_find_face_index(PyObject *self, PyObject *args) {
    Mesh *mesh;
    Py_ssize_t index;
    if (!PyArg_ParseTuple(args, "O!n", &Mesh_Type, &mesh, &index)) {
        return NULL;
    }
    if (!mesh->ctx->ok) {
        return Context_error(mesh->ctx);
    }
    uint32_t ret = ufbx_find_face_index(mesh->data, (size_t)index);
    return PyLong_FromUnsignedLong((unsigned long)ret);
}

static PyObject *mod_dom_find(PyObject *self, PyObject *args) {
    DomNode *parent;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "O!s#", &DomNode_Type, &parent, &name, &name_len)) {
        return NULL;
    }
    if (!parent->ctx->ok) {
        return Context_error(parent->ctx);
    }
    ufbx_dom_node* ret = ufbx_dom_find_len(parent->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_dom_node*");
}

static PyObject *mod_get_vertex_real(PyObject *self, PyObject *args) {
    ufbx_panic panic;
    panic.did_panic = false;
    VertexReal *v;
    Py_ssize_t index;
    if (!PyArg_ParseTuple(args, "O!n", &VertexReal_Type, &v, &index)) {
        return NULL;
    }
    if (!v->ctx->ok) {
        return Context_error(v->ctx);
    }
    ufbx_real ret = ufbx_catch_get_vertex_real(&panic, v->data, (size_t)index);
    if (panic.did_panic) {
        return Panic_raise(&panic);
    }
    return PyFloat_FromDouble(ret);
}

static PyObject *mod_get_vertex_vec2(PyObject *self, PyObject *args) {
    ufbx_panic panic;
    panic.did_panic = false;
    VertexVec2 *v;
    Py_ssize_t index;
    if (!PyArg_ParseTuple(args, "O!n", &VertexVec2_Type, &v, &index)) {
        return NULL;
    }
    if (!v->ctx->ok) {
        return Context_error(v->ctx);
    }
    ufbx_vec2 ret = ufbx_catch_get_vertex_vec2(&panic, v->data, (size_t)index);
    if (panic.did_panic) {
        return Panic_raise(&panic);
    }
    return Vec2_from(&ret);
}

static PyObject *mod_get_vertex_vec3(PyObject *self, PyObject *args) {
    ufbx_panic panic;
    panic.did_panic = false;
    VertexVec3 *v;
    Py_ssize_t index;
    if (!PyArg_ParseTuple(args, "O!n", &VertexVec3_Type, &v, &index)) {
        return NULL;
    }
    if (!v->ctx->ok) {
        return Context_error(v->ctx);
    }
    ufbx_vec3 ret = ufbx_catch_get_vertex_vec3(&panic, v->data, (size_t)index);
    if (panic.did_panic) {
        return Panic_raise(&panic);
    }
    return Vec3_from(&ret);
}

static PyObject *mod_get_vertex_vec4(PyObject *self, PyObject *args) {
    ufbx_panic panic;
    panic.did_panic = false;
    VertexVec4 *v;
    Py_ssize_t index;
    if (!PyArg_ParseTuple(args, "O!n", &VertexVec4_Type, &v, &index)) {
        return NULL;
    }
    if (!v->ctx->ok) {
        return Context_error(v->ctx);
    }
    ufbx_vec4 ret = ufbx_catch_get_vertex_vec4(&panic, v->data, (size_t)index);
    if (panic.did_panic) {
        return Panic_raise(&panic);
    }
    return Vec4_from(&ret);
}

static PyObject *mod_get_vertex_w_vec3(PyObject *self, PyObject *args) {
    ufbx_panic panic;
    panic.did_panic = false;
    VertexVec3 *v;
    Py_ssize_t index;
    if (!PyArg_ParseTuple(args, "O!n", &VertexVec3_Type, &v, &index)) {
        return NULL;
    }
    if (!v->ctx->ok) {
        return Context_error(v->ctx);
    }
    ufbx_real ret = ufbx_catch_get_vertex_w_vec3(&panic, v->data, (size_t)index);
    if (panic.did_panic) {
        return Panic_raise(&panic);
    }
    return PyFloat_FromDouble(ret);
}

static PyObject *mod_as_unknown(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_unknown* ret = ufbx_as_unknown(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_node(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_node* ret = ufbx_as_node(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_mesh(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_mesh* ret = ufbx_as_mesh(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_light(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_light* ret = ufbx_as_light(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_camera(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_camera* ret = ufbx_as_camera(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_bone(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_bone* ret = ufbx_as_bone(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_empty(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_empty* ret = ufbx_as_empty(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_line_curve(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_line_curve* ret = ufbx_as_line_curve(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_nurbs_curve(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_nurbs_curve* ret = ufbx_as_nurbs_curve(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_nurbs_surface(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_nurbs_surface* ret = ufbx_as_nurbs_surface(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_nurbs_trim_surface(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_nurbs_trim_surface* ret = ufbx_as_nurbs_trim_surface(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_nurbs_trim_boundary(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_nurbs_trim_boundary* ret = ufbx_as_nurbs_trim_boundary(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_procedural_geometry(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_procedural_geometry* ret = ufbx_as_procedural_geometry(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_stereo_camera(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_stereo_camera* ret = ufbx_as_stereo_camera(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_camera_switcher(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_camera_switcher* ret = ufbx_as_camera_switcher(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_marker(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_marker* ret = ufbx_as_marker(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_lod_group(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_lod_group* ret = ufbx_as_lod_group(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_skin_deformer(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_skin_deformer* ret = ufbx_as_skin_deformer(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_skin_cluster(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_skin_cluster* ret = ufbx_as_skin_cluster(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_blend_deformer(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_blend_deformer* ret = ufbx_as_blend_deformer(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_blend_channel(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_blend_channel* ret = ufbx_as_blend_channel(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_blend_shape(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_blend_shape* ret = ufbx_as_blend_shape(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_cache_deformer(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_cache_deformer* ret = ufbx_as_cache_deformer(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_cache_file(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_cache_file* ret = ufbx_as_cache_file(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_material(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_material* ret = ufbx_as_material(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_texture(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_texture* ret = ufbx_as_texture(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_video(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_video* ret = ufbx_as_video(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_shader(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_shader* ret = ufbx_as_shader(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_shader_binding(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_shader_binding* ret = ufbx_as_shader_binding(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_anim_stack(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_anim_stack* ret = ufbx_as_anim_stack(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_anim_layer(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_anim_layer* ret = ufbx_as_anim_layer(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_anim_value(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_anim_value* ret = ufbx_as_anim_value(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_anim_curve(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_anim_curve* ret = ufbx_as_anim_curve(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_display_layer(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_display_layer* ret = ufbx_as_display_layer(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_selection_set(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_selection_set* ret = ufbx_as_selection_set(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_selection_node(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_selection_node* ret = ufbx_as_selection_node(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_character(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_character* ret = ufbx_as_character(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_constraint(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_constraint* ret = ufbx_as_constraint(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_audio_layer(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_audio_layer* ret = ufbx_as_audio_layer(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_audio_clip(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_audio_clip* ret = ufbx_as_audio_clip(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_pose(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_pose* ret = ufbx_as_pose(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_as_metadata_object(PyObject *self, PyObject *args) {
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!element->ctx->ok) {
        return Context_error(element->ctx);
    }
    ufbx_metadata_object* ret = ufbx_as_metadata_object(element->data);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, element->ctx);
}

static PyObject *mod_dom_is_array(PyObject *self, PyObject *args) {
    DomNode *node;
    if (!PyArg_ParseTuple(args, "O!", &DomNode_Type, &node)) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    bool ret = ufbx_dom_is_array(node->data);
    return Py_NewRef(ret ? Py_True : Py_False);
}

static PyObject *mod_dom_array_size(PyObject *self, PyObject *args) {
    DomNode *node;
    if (!PyArg_ParseTuple(args, "O!", &DomNode_Type, &node)) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    size_t ret = ufbx_dom_array_size(node->data);
    return PyLong_FromSize_t(ret);
}

static PyObject *mod_dom_as_int32_list(PyObject *self, PyObject *args) {
    DomNode *node;
    if (!PyArg_ParseTuple(args, "O!", &DomNode_Type, &node)) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_int32_list ret = ufbx_dom_as_int32_list(node->data);
    return Int32List_from(ret, node->ctx);
}

static PyObject *mod_dom_as_int64_list(PyObject *self, PyObject *args) {
    DomNode *node;
    if (!PyArg_ParseTuple(args, "O!", &DomNode_Type, &node)) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_int64_list ret = ufbx_dom_as_int64_list(node->data);
    return Int64List_from(ret, node->ctx);
}

static PyObject *mod_dom_as_float_list(PyObject *self, PyObject *args) {
    DomNode *node;
    if (!PyArg_ParseTuple(args, "O!", &DomNode_Type, &node)) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_float_list ret = ufbx_dom_as_float_list(node->data);
    return FloatList_from(ret, node->ctx);
}

static PyObject *mod_dom_as_double_list(PyObject *self, PyObject *args) {
    DomNode *node;
    if (!PyArg_ParseTuple(args, "O!", &DomNode_Type, &node)) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_double_list ret = ufbx_dom_as_double_list(node->data);
    return DoubleList_from(ret, node->ctx);
}

static PyObject *mod_dom_as_real_list(PyObject *self, PyObject *args) {
    DomNode *node;
    if (!PyArg_ParseTuple(args, "O!", &DomNode_Type, &node)) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_real_list ret = ufbx_dom_as_real_list(node->data);
    return RealList_from(ret, node->ctx);
}

static PyObject *mod_dom_as_blob_list(PyObject *self, PyObject *args) {
    DomNode *node;
    if (!PyArg_ParseTuple(args, "O!", &DomNode_Type, &node)) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_blob_list ret = ufbx_dom_as_blob_list(node->data);
    return BlobList_from(ret, node->ctx);
}

static PyObject *DomNode_find(PyObject *self, PyObject *args) {
    DomNode *parent = (DomNode*)self;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "s#", &name, &name_len)) {
        return NULL;
    }
    if (!parent->ctx->ok) {
        return Context_error(parent->ctx);
    }
    ufbx_dom_node* ret = ufbx_dom_find_len(parent->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_dom_node*");
}

static PyObject *DomNode_is_array(PyObject *self, PyObject *args) {
    DomNode *node = (DomNode*)self;
    if (!PyArg_ParseTuple(args, "")) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    bool ret = ufbx_dom_is_array(node->data);
    return Py_NewRef(ret ? Py_True : Py_False);
}

static PyObject *DomNode_array_size(PyObject *self, PyObject *args) {
    DomNode *node = (DomNode*)self;
    if (!PyArg_ParseTuple(args, "")) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    size_t ret = ufbx_dom_array_size(node->data);
    return PyLong_FromSize_t(ret);
}

static PyObject *DomNode_as_int32_list(PyObject *self, PyObject *args) {
    DomNode *node = (DomNode*)self;
    if (!PyArg_ParseTuple(args, "")) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_int32_list ret = ufbx_dom_as_int32_list(node->data);
    return Int32List_from(ret, node->ctx);
}

static PyObject *DomNode_as_int64_list(PyObject *self, PyObject *args) {
    DomNode *node = (DomNode*)self;
    if (!PyArg_ParseTuple(args, "")) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_int64_list ret = ufbx_dom_as_int64_list(node->data);
    return Int64List_from(ret, node->ctx);
}

static PyObject *DomNode_as_float_list(PyObject *self, PyObject *args) {
    DomNode *node = (DomNode*)self;
    if (!PyArg_ParseTuple(args, "")) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_float_list ret = ufbx_dom_as_float_list(node->data);
    return FloatList_from(ret, node->ctx);
}

static PyObject *DomNode_as_double_list(PyObject *self, PyObject *args) {
    DomNode *node = (DomNode*)self;
    if (!PyArg_ParseTuple(args, "")) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_double_list ret = ufbx_dom_as_double_list(node->data);
    return DoubleList_from(ret, node->ctx);
}

static PyObject *DomNode_as_real_list(PyObject *self, PyObject *args) {
    DomNode *node = (DomNode*)self;
    if (!PyArg_ParseTuple(args, "")) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_real_list ret = ufbx_dom_as_real_list(node->data);
    return RealList_from(ret, node->ctx);
}

static PyObject *DomNode_as_blob_list(PyObject *self, PyObject *args) {
    DomNode *node = (DomNode*)self;
    if (!PyArg_ParseTuple(args, "")) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_blob_list ret = ufbx_dom_as_blob_list(node->data);
    return BlobList_from(ret, node->ctx);
}

static PyObject *Props_find_prop(PyObject *self, PyObject *args) {
    Props *props = (Props*)self;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "s#", &name, &name_len)) {
        return NULL;
    }
    if (!props->ctx->ok) {
        return Context_error(props->ctx);
    }
    ufbx_prop* ret = ufbx_find_prop_len(props->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_prop*");
}

static PyObject *Props_find_real(PyObject *self, PyObject *args) {
    Props *props = (Props*)self;
    const char *name;
    Py_ssize_t name_len;
    double def;
    if (!PyArg_ParseTuple(args, "s#d", &name, &name_len, &def)) {
        return NULL;
    }
    if (!props->ctx->ok) {
        return Context_error(props->ctx);
    }
    ufbx_real ret = ufbx_find_real_len(props->data, name, (size_t)name_len, (ufbx_real)def);
    return PyFloat_FromDouble(ret);
}

static PyObject *Props_find_vec3(PyObject *self, PyObject *args) {
    Props *props = (Props*)self;
    const char *name;
    Py_ssize_t name_len;
    PyObject *def_obj;
    ufbx_vec3 def;
    if (!PyArg_ParseTuple(args, "s#O!", &name, &name_len, &Vec3_Type, &def_obj)) {
        return NULL;
    }
    if (!props->ctx->ok) {
        return Context_error(props->ctx);
    }
    def = Vec3_to(def_obj);
    ufbx_vec3 ret = ufbx_find_vec3_len(props->data, name, (size_t)name_len, def);
    return Vec3_from(&ret);
}

static PyObject *Props_find_int(PyObject *self, PyObject *args) {
    Props *props = (Props*)self;
    const char *name;
    Py_ssize_t name_len;
    long long def;
    if (!PyArg_ParseTuple(args, "s#L", &name, &name_len, &def)) {
        return NULL;
    }
    if (!props->ctx->ok) {
        return Context_error(props->ctx);
    }
    int64_t ret = ufbx_find_int_len(props->data, name, (size_t)name_len, (int64_t)def);
    return PyLong_FromLongLong((long long)ret);
}

static PyObject *Props_find_bool(PyObject *self, PyObject *args) {
    Props *props = (Props*)self;
    const char *name;
    Py_ssize_t name_len;
    int def;
    if (!PyArg_ParseTuple(args, "s#p", &name, &name_len, &def)) {
        return NULL;
    }
    if (!props->ctx->ok) {
        return Context_error(props->ctx);
    }
    bool ret = ufbx_find_bool_len(props->data, name, (size_t)name_len, def != 0);
    return Py_NewRef(ret ? Py_True : Py_False);
}

static PyObject *Node_get_compatible_matrix_for_normals(PyObject *self, PyObject *args) {
    Node *node = (Node*)self;
    if (!PyArg_ParseTuple(args, "")) {
        return NULL;
    }
    if (!node->ctx->ok) {
        return Context_error(node->ctx);
    }
    ufbx_matrix ret = ufbx_get_compatible_matrix_for_normals(node->data);
    return Matrix_from(&ret);
}

static PyObject *Node_evaluate_transform(PyObject *self, PyObject *args) {
    Anim *anim;
    Node *node = (Node*)self;
    double time;
    if (!PyArg_ParseTuple(args, "O!d", &Anim_Type, &anim, &time)) {
        return NULL;
    }
    if (!anim->ctx->ok) {
        return Context_error(anim->ctx);
    }
    ufbx_transform ret = ufbx_evaluate_transform(anim->data, node->data, time);
    return Transform_from(&ret);
}

static PyObject *NurbsCurve_evaluate(PyObject *self, PyObject *args) {
    NurbsCurve *curve = (NurbsCurve*)self;
    double u;
    if (!PyArg_ParseTuple(args, "d", &u)) {
        return NULL;
    }
    if (!curve->ctx->ok) {
        return Context_error(curve->ctx);
    }
    ufbx_curve_point ret = ufbx_evaluate_nurbs_curve(curve->data, (ufbx_real)u);
    return CurvePoint_from(&ret);
}

static PyObject *NurbsSurface_evaluate(PyObject *self, PyObject *args) {
    NurbsSurface *surface = (NurbsSurface*)self;
    double u;
    double v;
    if (!PyArg_ParseTuple(args, "dd", &u, &v)) {
        return NULL;
    }
    if (!surface->ctx->ok) {
        return Context_error(surface->ctx);
    }
    ufbx_surface_point ret = ufbx_evaluate_nurbs_surface(surface->data, (ufbx_real)u, (ufbx_real)v);
    return SurfacePoint_from(&ret);
}

static PyObject *BlendDeformer_get_vertex_offset(PyObject *self, PyObject *args) {
    BlendDeformer *blend = (BlendDeformer*)self;
    Py_ssize_t vertex;
    if (!PyArg_ParseTuple(args, "n", &vertex)) {
        return NULL;
    }
    if (!blend->ctx->ok) {
        return Context_error(blend->ctx);
    }
    ufbx_vec3 ret = ufbx_get_blend_vertex_offset(blend->data, (size_t)vertex);
    return Vec3_from(&ret);
}

static PyObject *BlendChannel_evaluate_blend_weight(PyObject *self, PyObject *args) {
    Anim *anim;
    BlendChannel *channel = (BlendChannel*)self;
    double time;
    if (!PyArg_ParseTuple(args, "O!d", &Anim_Type, &anim, &time)) {
        return NULL;
    }
    if (!anim->ctx->ok) {
        return Context_error(anim->ctx);
    }
    ufbx_real ret = ufbx_evaluate_blend_weight(anim->data, channel->data, time);
    return PyFloat_FromDouble(ret);
}

static PyObject *BlendShape_get_vertex_offset(PyObject *self, PyObject *args) {
    BlendShape *shape = (BlendShape*)self;
    Py_ssize_t vertex;
    if (!PyArg_ParseTuple(args, "n", &vertex)) {
        return NULL;
    }
    if (!shape->ctx->ok) {
        return Context_error(shape->ctx);
    }
    ufbx_vec3 ret = ufbx_get_blend_shape_vertex_offset(shape->data, (size_t)vertex);
    return Vec3_from(&ret);
}

static PyObject *Material_find_prop_texture(PyObject *self, PyObject *args) {
    Material *material = (Material*)self;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "s#", &name, &name_len)) {
        return NULL;
    }
    if (!material->ctx->ok) {
        return Context_error(material->ctx);
    }
    ufbx_texture* ret = ufbx_find_prop_texture_len(material->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, material->ctx);
}

static PyObject *Shader_find_shader_prop(PyObject *self, PyObject *args) {
    Shader *shader = (Shader*)self;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "s#", &name, &name_len)) {
        return NULL;
    }
    if (!shader->ctx->ok) {
        return Context_error(shader->ctx);
    }
    ufbx_string ret = ufbx_find_shader_prop_len(shader->data, name, (size_t)name_len);
    return String_from(ret);
}

static PyObject *AnimLayer_find_anim_prop(PyObject *self, PyObject *args) {
    AnimLayer *layer = (AnimLayer*)self;
    Element *element;
    const char *prop;
    Py_ssize_t prop_len;
    if (!PyArg_ParseTuple(args, "O!s#", &Element_Type, &element, &prop, &prop_len)) {
        return NULL;
    }
    if (!layer->ctx->ok) {
        return Context_error(layer->ctx);
    }
    ufbx_anim_prop* ret = ufbx_find_anim_prop_len(layer->data, element->data, prop, (size_t)prop_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return to_pyobject_todo("ufbx_anim_prop*");
}

static PyObject *AnimLayer_find_anim_props(PyObject *self, PyObject *args) {
    AnimLayer *layer = (AnimLayer*)self;
    Element *element;
    if (!PyArg_ParseTuple(args, "O!", &Element_Type, &element)) {
        return NULL;
    }
    if (!layer->ctx->ok) {
        return Context_error(layer->ctx);
    }
    ufbx_anim_prop_list ret = ufbx_find_anim_props(layer->data, element->data);
    return AnimPropList_from(ret, layer->ctx);
}

static PyObject *AnimValue_evaluate_real(PyObject *self, PyObject *args) {
    AnimValue *anim_value = (AnimValue*)self;
    double time;
    if (!PyArg_ParseTuple(args, "d", &time)) {
        return NULL;
    }
    if (!anim_value->ctx->ok) {
        return Context_error(anim_value->ctx);
    }
    ufbx_real ret = ufbx_evaluate_anim_value_real(anim_value->data, time);
    return PyFloat_FromDouble(ret);
}

static PyObject *AnimValue_evaluate_vec3(PyObject *self, PyObject *args) {
    AnimValue *anim_value = (AnimValue*)self;
    double time;
    if (!PyArg_ParseTuple(args, "d", &time)) {
        return NULL;
    }
    if (!anim_value->ctx->ok) {
        return Context_error(anim_value->ctx);
    }
    ufbx_vec3 ret = ufbx_evaluate_anim_value_vec3(anim_value->data, time);
    return Vec3_from(&ret);
}

static PyObject *AnimCurve_evaluate(PyObject *self, PyObject *args) {
    AnimCurve *curve = (AnimCurve*)self;
    double time;
    double default_value;
    if (!PyArg_ParseTuple(args, "dd", &time, &default_value)) {
        return NULL;
    }
    if (!curve->ctx->ok) {
        return Context_error(curve->ctx);
    }
    ufbx_real ret = ufbx_evaluate_curve(curve->data, time, (ufbx_real)default_value);
    return PyFloat_FromDouble(ret);
}

static PyObject *Scene_find_node(PyObject *self, PyObject *args) {
    Scene *scene = (Scene*)self;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "s#", &name, &name_len)) {
        return NULL;
    }
    if (!scene->ctx->ok) {
        return Context_error(scene->ctx);
    }
    ufbx_node* ret = ufbx_find_node_len(scene->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, scene->ctx);
}

static PyObject *Scene_find_anim_stack(PyObject *self, PyObject *args) {
    Scene *scene = (Scene*)self;
    const char *name;
    Py_ssize_t name_len;
    if (!PyArg_ParseTuple(args, "s#", &name, &name_len)) {
        return NULL;
    }
    if (!scene->ctx->ok) {
        return Context_error(scene->ctx);
    }
    ufbx_anim_stack* ret = ufbx_find_anim_stack_len(scene->data, name, (size_t)name_len);
    if (!ret) {
        return Py_NewRef(Py_None);
    }
    return Element_from(ret, scene->ctx);
}

static PyObject *Scene_evaluate(PyObject *self, PyObject *args, PyObject *kwargs) {
    Scene *scene = (Scene*)self;
    Anim *anim;
    double time;
    ufbx_evaluate_opts opts = { 0 };
    ufbx_error error;
    if (!PyArg_ParseTuple(args, "O!d", &Anim_Type, &anim, &time)) {
        return NULL;
    }
    if (!scene->ctx->ok) {
        return Context_error(scene->ctx);
    }
    if (to_evaluate_opts(&opts, kwargs) < 0) {
        return NULL;
    }
    ufbx_scene* ret = ufbx_evaluate_scene(scene->data, anim->data, time, &opts, &error);
    if (error.type != UFBX_ERROR_NONE) {
        return UfbxError_raise(&error);
    }
    return Scene_create(ret);
}

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

static ExternalType enum_types[] = {
    { &RotationOrder_Enum, "RotationOrder" },
    { &DomValueType_Enum, "DomValueType" },
    { &PropType_Enum, "PropType" },
    { &PropFlags_Enum, "PropFlags" },
    { &ElementType_Enum, "ElementType" },
    { &InheritMode_Enum, "InheritMode" },
    { &MirrorAxis_Enum, "MirrorAxis" },
    { &SubdivisionDisplayMode_Enum, "SubdivisionDisplayMode" },
    { &SubdivisionBoundary_Enum, "SubdivisionBoundary" },
    { &LightType_Enum, "LightType" },
    { &LightDecay_Enum, "LightDecay" },
    { &LightAreaShape_Enum, "LightAreaShape" },
    { &ProjectionMode_Enum, "ProjectionMode" },
    { &AspectMode_Enum, "AspectMode" },
    { &ApertureMode_Enum, "ApertureMode" },
    { &GateFit_Enum, "GateFit" },
    { &ApertureFormat_Enum, "ApertureFormat" },
    { &CoordinateAxis_Enum, "CoordinateAxis" },
    { &NurbsTopology_Enum, "NurbsTopology" },
    { &MarkerType_Enum, "MarkerType" },
    { &LodDisplay_Enum, "LodDisplay" },
    { &SkinningMethod_Enum, "SkinningMethod" },
    { &CacheFileFormat_Enum, "CacheFileFormat" },
    { &CacheDataFormat_Enum, "CacheDataFormat" },
    { &CacheDataEncoding_Enum, "CacheDataEncoding" },
    { &CacheInterpretation_Enum, "CacheInterpretation" },
    { &ShaderType_Enum, "ShaderType" },
    { &MaterialFbxMap_Enum, "MaterialFbxMap" },
    { &MaterialPbrMap_Enum, "MaterialPbrMap" },
    { &MaterialFeature_Enum, "MaterialFeature" },
    { &TextureType_Enum, "TextureType" },
    { &BlendMode_Enum, "BlendMode" },
    { &WrapMode_Enum, "WrapMode" },
    { &ShaderTextureType_Enum, "ShaderTextureType" },
    { &Interpolation_Enum, "Interpolation" },
    { &ExtrapolationMode_Enum, "ExtrapolationMode" },
    { &ConstraintType_Enum, "ConstraintType" },
    { &ConstraintAimUpType_Enum, "ConstraintAimUpType" },
    { &ConstraintIkPoleType_Enum, "ConstraintIkPoleType" },
    { &Exporter_Enum, "Exporter" },
    { &FileFormat_Enum, "FileFormat" },
    { &WarningType_Enum, "WarningType" },
    { &ThumbnailFormat_Enum, "ThumbnailFormat" },
    { &SpaceConversion_Enum, "SpaceConversion" },
    { &GeometryTransformHandling_Enum, "GeometryTransformHandling" },
    { &InheritModeHandling_Enum, "InheritModeHandling" },
    { &PivotHandling_Enum, "PivotHandling" },
    { &TimeMode_Enum, "TimeMode" },
    { &TimeProtocol_Enum, "TimeProtocol" },
    { &SnapMode_Enum, "SnapMode" },
    { &TopoFlags_Enum, "TopoFlags" },
    { &OpenFileType_Enum, "OpenFileType" },
    { &ErrorType_Enum, "ErrorType" },
    { &ProgressResult_Enum, "ProgressResult" },
    { &IndexErrorHandling_Enum, "IndexErrorHandling" },
    { &UnicodeErrorHandling_Enum, "UnicodeErrorHandling" },
    { &BakedKeyFlags_Enum, "BakedKeyFlags" },
    { &EvaluateFlags_Enum, "EvaluateFlags" },
    { &BakeStepHandling_Enum, "BakeStepHandling" },
    { &TransformFlags_Enum, "TransformFlags" },
};

static ExternalType pod_types[] = {
    { &Transform_Type, "Transform" },
    { &Edge_Type, "Edge" },
    { &Face_Type, "Face" },
    { &CoordinateAxes_Type, "CoordinateAxes" },
    { &LodLevel_Type, "LodLevel" },
    { &SkinVertex_Type, "SkinVertex" },
    { &SkinWeight_Type, "SkinWeight" },
    { &TransformOverride_Type, "TransformOverride" },
    { &Tangent_Type, "Tangent" },
    { &Keyframe_Type, "Keyframe" },
    { &CurvePoint_Type, "CurvePoint" },
    { &SurfacePoint_Type, "SurfacePoint" },
    { &TopoEdge_Type, "TopoEdge" },
};

static ErrorType error_types[] = {
    { NULL },
    { "ufbx.UnknownError", "UnknownError" },
    { "ufbx.FileNotFoundError", "FileNotFoundError" },
    { "ufbx.EmptyFileError", "EmptyFileError" },
    { "ufbx.ExternalFileNotFoundError", "ExternalFileNotFoundError" },
    { "ufbx.OutOfMemoryError", "OutOfMemoryError" },
    { "ufbx.MemoryLimitError", "MemoryLimitError" },
    { "ufbx.AllocationLimitError", "AllocationLimitError" },
    { "ufbx.TruncatedFileError", "TruncatedFileError" },
    { "ufbx.IoError", "IoError" },
    { "ufbx.CancelledError", "CancelledError" },
    { "ufbx.UnrecognizedFileFormatError", "UnrecognizedFileFormatError" },
    { "ufbx.UninitializedOptionsError", "UninitializedOptionsError" },
    { "ufbx.ZeroVertexSizeError", "ZeroVertexSizeError" },
    { "ufbx.TruncatedVertexStreamError", "TruncatedVertexStreamError" },
    { "ufbx.InvalidUtf8Error", "InvalidUtf8Error" },
    { "ufbx.FeatureDisabledError", "FeatureDisabledError" },
    { "ufbx.BadNurbsError", "BadNurbsError" },
    { "ufbx.BadIndexError", "BadIndexError" },
    { "ufbx.NodeDepthLimitError", "NodeDepthLimitError" },
    { "ufbx.ThreadedAsciiParseError", "ThreadedAsciiParseError" },
    { "ufbx.UnsafeOptionsError", "UnsafeOptionsError" },
    { "ufbx.DuplicateOverrideError", "DuplicateOverrideError" },
    { "ufbx.UnsupportedVersionError", "UnsupportedVersionError" },
};

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

static PyMethodDef mod_methods[] = {
    { "is_thread_safe", &mod_is_thread_safe, METH_VARARGS, NULL },
    { "load_memory", (PyCFunction)&mod_load_memory, METH_VARARGS|METH_KEYWORDS, NULL },
    { "load_file", (PyCFunction)&mod_load_file, METH_VARARGS|METH_KEYWORDS, NULL },
    { "find_prop", &mod_find_prop, METH_VARARGS, NULL },
    { "find_real", &mod_find_real, METH_VARARGS, NULL },
    { "find_vec3", &mod_find_vec3, METH_VARARGS, NULL },
    { "find_int", &mod_find_int, METH_VARARGS, NULL },
    { "find_bool", &mod_find_bool, METH_VARARGS, NULL },
    { "find_node", &mod_find_node, METH_VARARGS, NULL },
    { "find_anim_stack", &mod_find_anim_stack, METH_VARARGS, NULL },
    { "find_material", &mod_find_material, METH_VARARGS, NULL },
    { "find_anim_prop", &mod_find_anim_prop, METH_VARARGS, NULL },
    { "find_anim_props", &mod_find_anim_props, METH_VARARGS, NULL },
    { "get_compatible_matrix_for_normals", &mod_get_compatible_matrix_for_normals, METH_VARARGS, NULL },
    { "evaluate_curve", &mod_evaluate_curve, METH_VARARGS, NULL },
    { "evaluate_curve_flags", &mod_evaluate_curve_flags, METH_VARARGS, NULL },
    { "evaluate_anim_value_real", &mod_evaluate_anim_value_real, METH_VARARGS, NULL },
    { "evaluate_anim_value_vec3", &mod_evaluate_anim_value_vec3, METH_VARARGS, NULL },
    { "evaluate_anim_value_real_flags", &mod_evaluate_anim_value_real_flags, METH_VARARGS, NULL },
    { "evaluate_anim_value_vec3_flags", &mod_evaluate_anim_value_vec3_flags, METH_VARARGS, NULL },
    { "evaluate_props_flags", &mod_evaluate_props_flags, METH_VARARGS, NULL },
    { "evaluate_transform", &mod_evaluate_transform, METH_VARARGS, NULL },
    { "evaluate_transform_flags", &mod_evaluate_transform_flags, METH_VARARGS, NULL },
    { "evaluate_blend_weight", &mod_evaluate_blend_weight, METH_VARARGS, NULL },
    { "evaluate_blend_weight_flags", &mod_evaluate_blend_weight_flags, METH_VARARGS, NULL },
    { "evaluate_scene", (PyCFunction)&mod_evaluate_scene, METH_VARARGS|METH_KEYWORDS, NULL },
    { "create_anim", (PyCFunction)&mod_create_anim, METH_VARARGS|METH_KEYWORDS, NULL },
    { "bake_anim", (PyCFunction)&mod_bake_anim, METH_VARARGS|METH_KEYWORDS, NULL },
    { "find_baked_node_by_typed_id", &mod_find_baked_node_by_typed_id, METH_VARARGS, NULL },
    { "find_baked_node", &mod_find_baked_node, METH_VARARGS, NULL },
    { "find_baked_element_by_element_id", &mod_find_baked_element_by_element_id, METH_VARARGS, NULL },
    { "find_baked_element", &mod_find_baked_element, METH_VARARGS, NULL },
    { "get_bone_pose", &mod_get_bone_pose, METH_VARARGS, NULL },
    { "find_prop_texture", &mod_find_prop_texture, METH_VARARGS, NULL },
    { "find_shader_prop", &mod_find_shader_prop, METH_VARARGS, NULL },
    { "find_shader_prop_bindings", &mod_find_shader_prop_bindings, METH_VARARGS, NULL },
    { "find_shader_texture_input", &mod_find_shader_texture_input, METH_VARARGS, NULL },
    { "vec3_normalize", &mod_vec3_normalize, METH_VARARGS, NULL },
    { "quat_dot", &mod_quat_dot, METH_VARARGS, NULL },
    { "quat_mul", &mod_quat_mul, METH_VARARGS, NULL },
    { "quat_normalize", &mod_quat_normalize, METH_VARARGS, NULL },
    { "quat_fix_antipodal", &mod_quat_fix_antipodal, METH_VARARGS, NULL },
    { "quat_slerp", &mod_quat_slerp, METH_VARARGS, NULL },
    { "quat_rotate_vec3", &mod_quat_rotate_vec3, METH_VARARGS, NULL },
    { "get_blend_shape_offset_index", &mod_get_blend_shape_offset_index, METH_VARARGS, NULL },
    { "get_blend_shape_vertex_offset", &mod_get_blend_shape_vertex_offset, METH_VARARGS, NULL },
    { "get_blend_vertex_offset", &mod_get_blend_vertex_offset, METH_VARARGS, NULL },
    { "evaluate_nurbs_curve", &mod_evaluate_nurbs_curve, METH_VARARGS, NULL },
    { "evaluate_nurbs_surface", &mod_evaluate_nurbs_surface, METH_VARARGS, NULL },
    { "find_face_index", &mod_find_face_index, METH_VARARGS, NULL },
    { "dom_find", &mod_dom_find, METH_VARARGS, NULL },
    { "get_vertex_real", &mod_get_vertex_real, METH_VARARGS, NULL },
    { "get_vertex_vec2", &mod_get_vertex_vec2, METH_VARARGS, NULL },
    { "get_vertex_vec3", &mod_get_vertex_vec3, METH_VARARGS, NULL },
    { "get_vertex_vec4", &mod_get_vertex_vec4, METH_VARARGS, NULL },
    { "get_vertex_w_vec3", &mod_get_vertex_w_vec3, METH_VARARGS, NULL },
    { "as_unknown", &mod_as_unknown, METH_VARARGS, NULL },
    { "as_node", &mod_as_node, METH_VARARGS, NULL },
    { "as_mesh", &mod_as_mesh, METH_VARARGS, NULL },
    { "as_light", &mod_as_light, METH_VARARGS, NULL },
    { "as_camera", &mod_as_camera, METH_VARARGS, NULL },
    { "as_bone", &mod_as_bone, METH_VARARGS, NULL },
    { "as_empty", &mod_as_empty, METH_VARARGS, NULL },
    { "as_line_curve", &mod_as_line_curve, METH_VARARGS, NULL },
    { "as_nurbs_curve", &mod_as_nurbs_curve, METH_VARARGS, NULL },
    { "as_nurbs_surface", &mod_as_nurbs_surface, METH_VARARGS, NULL },
    { "as_nurbs_trim_surface", &mod_as_nurbs_trim_surface, METH_VARARGS, NULL },
    { "as_nurbs_trim_boundary", &mod_as_nurbs_trim_boundary, METH_VARARGS, NULL },
    { "as_procedural_geometry", &mod_as_procedural_geometry, METH_VARARGS, NULL },
    { "as_stereo_camera", &mod_as_stereo_camera, METH_VARARGS, NULL },
    { "as_camera_switcher", &mod_as_camera_switcher, METH_VARARGS, NULL },
    { "as_marker", &mod_as_marker, METH_VARARGS, NULL },
    { "as_lod_group", &mod_as_lod_group, METH_VARARGS, NULL },
    { "as_skin_deformer", &mod_as_skin_deformer, METH_VARARGS, NULL },
    { "as_skin_cluster", &mod_as_skin_cluster, METH_VARARGS, NULL },
    { "as_blend_deformer", &mod_as_blend_deformer, METH_VARARGS, NULL },
    { "as_blend_channel", &mod_as_blend_channel, METH_VARARGS, NULL },
    { "as_blend_shape", &mod_as_blend_shape, METH_VARARGS, NULL },
    { "as_cache_deformer", &mod_as_cache_deformer, METH_VARARGS, NULL },
    { "as_cache_file", &mod_as_cache_file, METH_VARARGS, NULL },
    { "as_material", &mod_as_material, METH_VARARGS, NULL },
    { "as_texture", &mod_as_texture, METH_VARARGS, NULL },
    { "as_video", &mod_as_video, METH_VARARGS, NULL },
    { "as_shader", &mod_as_shader, METH_VARARGS, NULL },
    { "as_shader_binding", &mod_as_shader_binding, METH_VARARGS, NULL },
    { "as_anim_stack", &mod_as_anim_stack, METH_VARARGS, NULL },
    { "as_anim_layer", &mod_as_anim_layer, METH_VARARGS, NULL },
    { "as_anim_value", &mod_as_anim_value, METH_VARARGS, NULL },
    { "as_anim_curve", &mod_as_anim_curve, METH_VARARGS, NULL },
    { "as_display_layer", &mod_as_display_layer, METH_VARARGS, NULL },
    { "as_selection_set", &mod_as_selection_set, METH_VARARGS, NULL },
    { "as_selection_node", &mod_as_selection_node, METH_VARARGS, NULL },
    { "as_character", &mod_as_character, METH_VARARGS, NULL },
    { "as_constraint", &mod_as_constraint, METH_VARARGS, NULL },
    { "as_audio_layer", &mod_as_audio_layer, METH_VARARGS, NULL },
    { "as_audio_clip", &mod_as_audio_clip, METH_VARARGS, NULL },
    { "as_pose", &mod_as_pose, METH_VARARGS, NULL },
    { "as_metadata_object", &mod_as_metadata_object, METH_VARARGS, NULL },
    { "dom_is_array", &mod_dom_is_array, METH_VARARGS, NULL },
    { "dom_array_size", &mod_dom_array_size, METH_VARARGS, NULL },
    { "dom_as_int32_list", &mod_dom_as_int32_list, METH_VARARGS, NULL },
    { "dom_as_int64_list", &mod_dom_as_int64_list, METH_VARARGS, NULL },
    { "dom_as_float_list", &mod_dom_as_float_list, METH_VARARGS, NULL },
    { "dom_as_double_list", &mod_dom_as_double_list, METH_VARARGS, NULL },
    { "dom_as_real_list", &mod_dom_as_real_list, METH_VARARGS, NULL },
    { "dom_as_blob_list", &mod_dom_as_blob_list, METH_VARARGS, NULL },
    { "dom_find", &mod_dom_find, METH_VARARGS, NULL },
    { "dom_is_array", &mod_dom_is_array, METH_VARARGS, NULL },
    { "dom_array_size", &mod_dom_array_size, METH_VARARGS, NULL },
    { "dom_as_int32_list", &mod_dom_as_int32_list, METH_VARARGS, NULL },
    { "dom_as_int64_list", &mod_dom_as_int64_list, METH_VARARGS, NULL },
    { "dom_as_float_list", &mod_dom_as_float_list, METH_VARARGS, NULL },
    { "dom_as_double_list", &mod_dom_as_double_list, METH_VARARGS, NULL },
    { "dom_as_real_list", &mod_dom_as_real_list, METH_VARARGS, NULL },
    { "dom_as_blob_list", &mod_dom_as_blob_list, METH_VARARGS, NULL },
    { "find_prop", &mod_find_prop, METH_VARARGS, NULL },
    { "find_real", &mod_find_real, METH_VARARGS, NULL },
    { "find_vec3", &mod_find_vec3, METH_VARARGS, NULL },
    { "find_int", &mod_find_int, METH_VARARGS, NULL },
    { "find_bool", &mod_find_bool, METH_VARARGS, NULL },
    { "get_compatible_matrix_for_normals", &mod_get_compatible_matrix_for_normals, METH_VARARGS, NULL },
    { "evaluate_transform", &mod_evaluate_transform, METH_VARARGS, NULL },
    { "evaluate_nurbs_curve", &mod_evaluate_nurbs_curve, METH_VARARGS, NULL },
    { "evaluate_nurbs_surface", &mod_evaluate_nurbs_surface, METH_VARARGS, NULL },
    { "get_blend_vertex_offset", &mod_get_blend_vertex_offset, METH_VARARGS, NULL },
    { "evaluate_blend_weight", &mod_evaluate_blend_weight, METH_VARARGS, NULL },
    { "get_blend_shape_vertex_offset", &mod_get_blend_shape_vertex_offset, METH_VARARGS, NULL },
    { "find_prop_texture", &mod_find_prop_texture, METH_VARARGS, NULL },
    { "find_shader_prop", &mod_find_shader_prop, METH_VARARGS, NULL },
    { "find_anim_prop", &mod_find_anim_prop, METH_VARARGS, NULL },
    { "find_anim_props", &mod_find_anim_props, METH_VARARGS, NULL },
    { "evaluate_anim_value_real", &mod_evaluate_anim_value_real, METH_VARARGS, NULL },
    { "evaluate_anim_value_vec3", &mod_evaluate_anim_value_vec3, METH_VARARGS, NULL },
    { "evaluate_curve", &mod_evaluate_curve, METH_VARARGS, NULL },
    { "find_node", &mod_find_node, METH_VARARGS, NULL },
    { "find_anim_stack", &mod_find_anim_stack, METH_VARARGS, NULL },
    { "evaluate_scene", (PyCFunction)&mod_evaluate_scene, METH_VARARGS|METH_KEYWORDS, NULL },
    { NULL },
};

