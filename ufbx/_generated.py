from ._types import *
from typing import NamedTuple
from enum import IntEnum, IntFlag

class RotationOrder(IntEnum):
    XYZ = 0
    XZY = 1
    YZX = 2
    YXZ = 3
    ZXY = 4
    ZYX = 5
    SPHERIC = 6

class DomValueType(IntEnum):
    NUMBER = 0
    STRING = 1
    BLOB = 2
    ARRAY_I32 = 3
    ARRAY_I64 = 4
    ARRAY_F32 = 5
    ARRAY_F64 = 6
    ARRAY_BLOB = 7
    ARRAY_IGNORED = 8

class PropType(IntEnum):
    UNKNOWN = 0
    BOOLEAN = 1
    INTEGER = 2
    NUMBER = 3
    VECTOR = 4
    COLOR = 5
    COLOR_WITH_ALPHA = 6
    STRING = 7
    DATE_TIME = 8
    TRANSLATION = 9
    ROTATION = 10
    SCALING = 11
    DISTANCE = 12
    COMPOUND = 13
    BLOB = 14
    REFERENCE = 15

class PropFlags(IntFlag):
    ANIMATABLE = 0x1
    USER_DEFINED = 0x2
    HIDDEN = 0x4
    LOCK_X = 0x10
    LOCK_Y = 0x20
    LOCK_Z = 0x40
    LOCK_W = 0x80
    MUTE_X = 0x100
    MUTE_Y = 0x200
    MUTE_Z = 0x400
    MUTE_W = 0x800
    SYNTHETIC = 0x1000
    ANIMATED = 0x2000
    NOT_FOUND = 0x4000
    CONNECTED = 0x8000
    NO_VALUE = 0x10000
    OVERRIDDEN = 0x20000
    VALUE_REAL = 0x100000
    VALUE_VEC2 = 0x200000
    VALUE_VEC3 = 0x400000
    VALUE_VEC4 = 0x800000
    VALUE_INT = 0x1000000
    VALUE_STR = 0x2000000
    VALUE_BLOB = 0x4000000

class ElementType(IntEnum):
    UNKNOWN = 0
    NODE = 1
    MESH = 2
    LIGHT = 3
    CAMERA = 4
    BONE = 5
    EMPTY = 6
    LINE_CURVE = 7
    NURBS_CURVE = 8
    NURBS_SURFACE = 9
    NURBS_TRIM_SURFACE = 10
    NURBS_TRIM_BOUNDARY = 11
    PROCEDURAL_GEOMETRY = 12
    STEREO_CAMERA = 13
    CAMERA_SWITCHER = 14
    MARKER = 15
    LOD_GROUP = 16
    SKIN_DEFORMER = 17
    SKIN_CLUSTER = 18
    BLEND_DEFORMER = 19
    BLEND_CHANNEL = 20
    BLEND_SHAPE = 21
    CACHE_DEFORMER = 22
    CACHE_FILE = 23
    MATERIAL = 24
    TEXTURE = 25
    VIDEO = 26
    SHADER = 27
    SHADER_BINDING = 28
    ANIM_STACK = 29
    ANIM_LAYER = 30
    ANIM_VALUE = 31
    ANIM_CURVE = 32
    DISPLAY_LAYER = 33
    SELECTION_SET = 34
    SELECTION_NODE = 35
    CHARACTER = 36
    CONSTRAINT = 37
    AUDIO_LAYER = 38
    AUDIO_CLIP = 39
    POSE = 40
    METADATA_OBJECT = 41
    FIRST_ATTRIB = 2
    LAST_ATTRIB = 16

class InheritMode(IntEnum):
    NORMAL = 0
    IGNORE_PARENT_SCALE = 1
    COMPONENTWISE_SCALE = 2

class MirrorAxis(IntEnum):
    NONE = 0
    X = 1
    Y = 2
    Z = 3

class SubdivisionDisplayMode(IntEnum):
    DISABLED = 0
    HULL = 1
    HULL_AND_SMOOTH = 2
    SMOOTH = 3

class SubdivisionBoundary(IntEnum):
    DEFAULT = 0
    LEGACY = 1
    SHARP_CORNERS = 2
    SHARP_NONE = 3
    SHARP_BOUNDARY = 4
    SHARP_INTERIOR = 5

class LightType(IntEnum):
    POINT = 0
    DIRECTIONAL = 1
    SPOT = 2
    AREA = 3
    VOLUME = 4

class LightDecay(IntEnum):
    NONE = 0
    LINEAR = 1
    QUADRATIC = 2
    CUBIC = 3

class LightAreaShape(IntEnum):
    RECTANGLE = 0
    SPHERE = 1

class ProjectionMode(IntEnum):
    PERSPECTIVE = 0
    ORTHOGRAPHIC = 1

class AspectMode(IntEnum):
    WINDOW_SIZE = 0
    FIXED_RATIO = 1
    FIXED_RESOLUTION = 2
    FIXED_WIDTH = 3
    FIXED_HEIGHT = 4

class ApertureMode(IntEnum):
    HORIZONTAL_AND_VERTICAL = 0
    HORIZONTAL = 1
    VERTICAL = 2
    FOCAL_LENGTH = 3

class GateFit(IntEnum):
    NONE = 0
    VERTICAL = 1
    HORIZONTAL = 2
    FILL = 3
    OVERSCAN = 4
    STRETCH = 5

class ApertureFormat(IntEnum):
    CUSTOM = 0
    E16MM_THEATRICAL = 1
    SUPER_16MM = 2
    E35MM_ACADEMY = 3
    E35MM_TV_PROJECTION = 4
    E35MM_FULL_APERTURE = 5
    E35MM_185_PROJECTION = 6
    E35MM_ANAMORPHIC = 7
    E70MM_PROJECTION = 8
    VISTAVISION = 9
    DYNAVISION = 10
    IMAX = 11

class CoordinateAxis(IntEnum):
    POSITIVE_X = 0
    NEGATIVE_X = 1
    POSITIVE_Y = 2
    NEGATIVE_Y = 3
    POSITIVE_Z = 4
    NEGATIVE_Z = 5
    UNKNOWN = 6

class NurbsTopology(IntEnum):
    OPEN = 0
    PERIODIC = 1
    CLOSED = 2

class MarkerType(IntEnum):
    UNKNOWN = 0
    FK_EFFECTOR = 1
    IK_EFFECTOR = 2

class LodDisplay(IntEnum):
    USE_LOD = 0
    SHOW = 1
    HIDE = 2

class SkinningMethod(IntEnum):
    LINEAR = 0
    RIGID = 1
    DUAL_QUATERNION = 2
    BLENDED_DQ_LINEAR = 3

class CacheFileFormat(IntEnum):
    UNKNOWN = 0
    PC2 = 1
    MC = 2

class CacheDataFormat(IntEnum):
    UNKNOWN = 0
    REAL_FLOAT = 1
    VEC3_FLOAT = 2
    REAL_DOUBLE = 3
    VEC3_DOUBLE = 4

class CacheDataEncoding(IntEnum):
    UNKNOWN = 0
    LITTLE_ENDIAN = 1
    BIG_ENDIAN = 2

class CacheInterpretation(IntEnum):
    UNKNOWN = 0
    POINTS = 1
    VERTEX_POSITION = 2
    VERTEX_NORMAL = 3

class ShaderType(IntEnum):
    UNKNOWN = 0
    FBX_LAMBERT = 1
    FBX_PHONG = 2
    OSL_STANDARD_SURFACE = 3
    ARNOLD_STANDARD_SURFACE = 4
    E3DS_MAX_PHYSICAL_MATERIAL = 5
    E3DS_MAX_PBR_METAL_ROUGH = 6
    E3DS_MAX_PBR_SPEC_GLOSS = 7
    GLTF_MATERIAL = 8
    OPENPBR_MATERIAL = 9
    SHADERFX_GRAPH = 10
    BLENDER_PHONG = 11
    WAVEFRONT_MTL = 12

class MaterialFbxMap(IntEnum):
    DIFFUSE_FACTOR = 0
    DIFFUSE_COLOR = 1
    SPECULAR_FACTOR = 2
    SPECULAR_COLOR = 3
    SPECULAR_EXPONENT = 4
    REFLECTION_FACTOR = 5
    REFLECTION_COLOR = 6
    TRANSPARENCY_FACTOR = 7
    TRANSPARENCY_COLOR = 8
    EMISSION_FACTOR = 9
    EMISSION_COLOR = 10
    AMBIENT_FACTOR = 11
    AMBIENT_COLOR = 12
    NORMAL_MAP = 13
    BUMP = 14
    BUMP_FACTOR = 15
    DISPLACEMENT_FACTOR = 16
    DISPLACEMENT = 17
    VECTOR_DISPLACEMENT_FACTOR = 18
    VECTOR_DISPLACEMENT = 19

class MaterialPbrMap(IntEnum):
    BASE_FACTOR = 0
    BASE_COLOR = 1
    ROUGHNESS = 2
    METALNESS = 3
    DIFFUSE_ROUGHNESS = 4
    SPECULAR_FACTOR = 5
    SPECULAR_COLOR = 6
    SPECULAR_IOR = 7
    SPECULAR_ANISOTROPY = 8
    SPECULAR_ROTATION = 9
    TRANSMISSION_FACTOR = 10
    TRANSMISSION_COLOR = 11
    TRANSMISSION_DEPTH = 12
    TRANSMISSION_SCATTER = 13
    TRANSMISSION_SCATTER_ANISOTROPY = 14
    TRANSMISSION_DISPERSION = 15
    TRANSMISSION_ROUGHNESS = 16
    TRANSMISSION_EXTRA_ROUGHNESS = 17
    TRANSMISSION_PRIORITY = 18
    TRANSMISSION_ENABLE_IN_AOV = 19
    SUBSURFACE_FACTOR = 20
    SUBSURFACE_COLOR = 21
    SUBSURFACE_RADIUS = 22
    SUBSURFACE_SCALE = 23
    SUBSURFACE_ANISOTROPY = 24
    SUBSURFACE_TINT_COLOR = 25
    SUBSURFACE_TYPE = 26
    SHEEN_FACTOR = 27
    SHEEN_COLOR = 28
    SHEEN_ROUGHNESS = 29
    COAT_FACTOR = 30
    COAT_COLOR = 31
    COAT_ROUGHNESS = 32
    COAT_IOR = 33
    COAT_ANISOTROPY = 34
    COAT_ROTATION = 35
    COAT_NORMAL = 36
    COAT_AFFECT_BASE_COLOR = 37
    COAT_AFFECT_BASE_ROUGHNESS = 38
    THIN_FILM_FACTOR = 39
    THIN_FILM_THICKNESS = 40
    THIN_FILM_IOR = 41
    EMISSION_FACTOR = 42
    EMISSION_COLOR = 43
    OPACITY = 44
    INDIRECT_DIFFUSE = 45
    INDIRECT_SPECULAR = 46
    NORMAL_MAP = 47
    TANGENT_MAP = 48
    DISPLACEMENT_MAP = 49
    MATTE_FACTOR = 50
    MATTE_COLOR = 51
    AMBIENT_OCCLUSION = 52
    GLOSSINESS = 53
    COAT_GLOSSINESS = 54
    TRANSMISSION_GLOSSINESS = 55

class MaterialFeature(IntEnum):
    PBR = 0
    METALNESS = 1
    DIFFUSE = 2
    SPECULAR = 3
    EMISSION = 4
    TRANSMISSION = 5
    COAT = 6
    SHEEN = 7
    OPACITY = 8
    AMBIENT_OCCLUSION = 9
    MATTE = 10
    UNLIT = 11
    IOR = 12
    DIFFUSE_ROUGHNESS = 13
    TRANSMISSION_ROUGHNESS = 14
    THIN_WALLED = 15
    CAUSTICS = 16
    EXIT_TO_BACKGROUND = 17
    INTERNAL_REFLECTIONS = 18
    DOUBLE_SIDED = 19
    ROUGHNESS_AS_GLOSSINESS = 20
    COAT_ROUGHNESS_AS_GLOSSINESS = 21
    TRANSMISSION_ROUGHNESS_AS_GLOSSINESS = 22

class TextureType(IntEnum):
    FILE = 0
    LAYERED = 1
    PROCEDURAL = 2
    SHADER = 3

class BlendMode(IntEnum):
    TRANSLUCENT = 0
    ADDITIVE = 1
    MULTIPLY = 2
    MULTIPLY_2X = 3
    OVER = 4
    REPLACE = 5
    DISSOLVE = 6
    DARKEN = 7
    COLOR_BURN = 8
    LINEAR_BURN = 9
    DARKER_COLOR = 10
    LIGHTEN = 11
    SCREEN = 12
    COLOR_DODGE = 13
    LINEAR_DODGE = 14
    LIGHTER_COLOR = 15
    SOFT_LIGHT = 16
    HARD_LIGHT = 17
    VIVID_LIGHT = 18
    LINEAR_LIGHT = 19
    PIN_LIGHT = 20
    HARD_MIX = 21
    DIFFERENCE = 22
    EXCLUSION = 23
    SUBTRACT = 24
    DIVIDE = 25
    HUE = 26
    SATURATION = 27
    COLOR = 28
    LUMINOSITY = 29
    OVERLAY = 30

class WrapMode(IntEnum):
    REPEAT = 0
    CLAMP = 1

class ShaderTextureType(IntEnum):
    UNKNOWN = 0
    SELECT_OUTPUT = 1
    OSL = 2

class Interpolation(IntEnum):
    CONSTANT_PREV = 0
    CONSTANT_NEXT = 1
    LINEAR = 2
    CUBIC = 3

class ExtrapolationMode(IntEnum):
    CONSTANT = 0
    REPEAT = 1
    MIRROR = 2
    SLOPE = 3
    REPEAT_RELATIVE = 4

class ConstraintType(IntEnum):
    UNKNOWN = 0
    AIM = 1
    PARENT = 2
    POSITION = 3
    ROTATION = 4
    SCALE = 5
    SINGLE_CHAIN_IK = 6

class ConstraintAimUpType(IntEnum):
    SCENE = 0
    TO_NODE = 1
    ALIGN_NODE = 2
    VECTOR = 3
    NONE = 4

class ConstraintIkPoleType(IntEnum):
    VECTOR = 0
    NODE = 1

class Exporter(IntEnum):
    UNKNOWN = 0
    FBX_SDK = 1
    BLENDER_BINARY = 2
    BLENDER_ASCII = 3
    MOTION_BUILDER = 4

class FileFormat(IntEnum):
    UNKNOWN = 0
    FBX = 1
    OBJ = 2
    MTL = 3

class WarningType(IntEnum):
    MISSING_EXTERNAL_FILE = 0
    IMPLICIT_MTL = 1
    TRUNCATED_ARRAY = 2
    MISSING_GEOMETRY_DATA = 3
    DUPLICATE_CONNECTION = 4
    BAD_VERTEX_W_ATTRIBUTE = 5
    MISSING_POLYGON_MAPPING = 6
    UNSUPPORTED_VERSION = 7
    INDEX_CLAMPED = 8
    BAD_UNICODE = 9
    BAD_BASE64_CONTENT = 10
    BAD_ELEMENT_CONNECTED_TO_ROOT = 11
    DUPLICATE_OBJECT_ID = 12
    EMPTY_FACE_REMOVED = 13
    UNKNOWN_OBJ_DIRECTIVE = 14
    FIRST_DEDUPLICATED = 8

class ThumbnailFormat(IntEnum):
    UNKNOWN = 0
    RGB_24 = 1
    RGBA_32 = 2

class SpaceConversion(IntEnum):
    TRANSFORM_ROOT = 0
    ADJUST_TRANSFORMS = 1
    MODIFY_GEOMETRY = 2

class GeometryTransformHandling(IntEnum):
    PRESERVE = 0
    HELPER_NODES = 1
    MODIFY_GEOMETRY = 2
    MODIFY_GEOMETRY_NO_FALLBACK = 3

class InheritModeHandling(IntEnum):
    PRESERVE = 0
    HELPER_NODES = 1
    COMPENSATE = 2
    COMPENSATE_NO_FALLBACK = 3
    IGNORE = 4

class PivotHandling(IntEnum):
    RETAIN = 0
    ADJUST_TO_PIVOT = 1
    ADJUST_TO_ROTATION_PIVOT = 2

class TimeMode(IntEnum):
    DEFAULT = 0
    E120_FPS = 1
    E100_FPS = 2
    E60_FPS = 3
    E50_FPS = 4
    E48_FPS = 5
    E30_FPS = 6
    E30_FPS_DROP = 7
    NTSC_DROP_FRAME = 8
    NTSC_FULL_FRAME = 9
    PAL = 10
    E24_FPS = 11
    E1000_FPS = 12
    FILM_FULL_FRAME = 13
    CUSTOM = 14
    E96_FPS = 15
    E72_FPS = 16
    E59_94_FPS = 17

class TimeProtocol(IntEnum):
    SMPTE = 0
    FRAME_COUNT = 1
    DEFAULT = 2

class SnapMode(IntEnum):
    NONE = 0
    SNAP = 1
    PLAY = 2
    SNAP_AND_PLAY = 3

class TopoFlags(IntFlag):
    NON_MANIFOLD = 0x1

class OpenFileType(IntEnum):
    MAIN_MODEL = 0
    GEOMETRY_CACHE = 1
    OBJ_MTL = 2

class ErrorType(IntEnum):
    NONE = 0
    UNKNOWN = 1
    FILE_NOT_FOUND = 2
    EMPTY_FILE = 3
    EXTERNAL_FILE_NOT_FOUND = 4
    OUT_OF_MEMORY = 5
    MEMORY_LIMIT = 6
    ALLOCATION_LIMIT = 7
    TRUNCATED_FILE = 8
    IO = 9
    CANCELLED = 10
    UNRECOGNIZED_FILE_FORMAT = 11
    UNINITIALIZED_OPTIONS = 12
    ZERO_VERTEX_SIZE = 13
    TRUNCATED_VERTEX_STREAM = 14
    INVALID_UTF8 = 15
    FEATURE_DISABLED = 16
    BAD_NURBS = 17
    BAD_INDEX = 18
    NODE_DEPTH_LIMIT = 19
    THREADED_ASCII_PARSE = 20
    UNSAFE_OPTIONS = 21
    DUPLICATE_OVERRIDE = 22
    UNSUPPORTED_VERSION = 23

class ProgressResult(IntEnum):
    CONTINUE = 256
    CANCEL = 512

class IndexErrorHandling(IntEnum):
    CLAMP = 0
    NO_INDEX = 1
    ABORT_LOADING = 2
    UNSAFE_IGNORE = 3

class UnicodeErrorHandling(IntEnum):
    REPLACEMENT_CHARACTER = 0
    UNDERSCORE = 1
    QUESTION_MARK = 2
    REMOVE = 3
    ABORT_LOADING = 4
    UNSAFE_IGNORE = 5

class BakedKeyFlags(IntFlag):
    STEP_LEFT = 0x1
    STEP_RIGHT = 0x2
    STEP_KEY = 0x4
    KEYFRAME = 0x8
    REDUCED = 0x10

class EvaluateFlags(IntFlag):
    NO_EXTRAPOLATION = 0x1

class BakeStepHandling(IntEnum):
    DEFAULT = 0
    CUSTOM_DURATION = 1
    IDENTICAL_TIME = 2
    ADJACENT_DOUBLE = 3
    IGNORE = 4

class TransformFlags(IntFlag):
    IGNORE_SCALE_HELPER = 0x1
    IGNORE_COMPONENTWISE_SCALE = 0x2
    EXPLICIT_INCLUDES = 0x4
    INCLUDE_TRANSLATION = 0x10
    INCLUDE_ROTATION = 0x20
    INCLUDE_SCALE = 0x40
    NO_EXTRAPOLATION = 0x80

class Transform(NamedTuple):
    translation: Vec3
    rotation: Quat
    scale: Vec3

class Edge(NamedTuple):
    a: int
    b: int

class Face(NamedTuple):
    index_begin: int
    num_indices: int

class CoordinateAxes(NamedTuple):
    right: CoordinateAxis
    up: CoordinateAxis
    front: CoordinateAxis

class LodLevel(NamedTuple):
    distance: float
    display: LodDisplay

class SkinVertex(NamedTuple):
    weight_begin: int
    num_weights: int
    dq_weight: float

class SkinWeight(NamedTuple):
    cluster_index: int
    weight: float

class TransformOverride(NamedTuple):
    node_id: int
    transform: Transform

class Tangent(NamedTuple):
    dx: float
    dy: float

class Keyframe(NamedTuple):
    time: float
    value: float
    interpolation: Interpolation
    left: Tangent
    right: Tangent

class CurvePoint(NamedTuple):
    valid: bool
    position: Vec3
    derivative: Vec3

class SurfacePoint(NamedTuple):
    valid: bool
    position: Vec3
    derivative_u: Vec3
    derivative_v: Vec3

class TopoEdge(NamedTuple):
    index: int
    next: int
    prev: int
    twin: int
    face: int
    edge: int
    flags: TopoFlags
