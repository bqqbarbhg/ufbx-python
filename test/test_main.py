from pytest import approx
import ufbx
import os
import math

import faulthandler
faulthandler.enable()

self_root = os.path.dirname(os.path.abspath(__file__))
data_root = os.path.join(self_root, "data")

rcp_sqrt_2 = 1.0 / math.sqrt(2)

def test_loading():
    is_thread_safe = ufbx.is_thread_safe()
    assert is_thread_safe

def test_simple():
    scene = ufbx.load_file(os.path.join(data_root, "blender-default.fbx"))
    assert scene

def test_nonexistent():
    try:
        scene = ufbx.load_file(os.path.join(data_root, "nonexistent.fbx"))
        assert False
    except ufbx.FileNotFoundError as e:
        msg = str(e)
        assert msg.startswith("File not found:")
        assert msg.endswith("nonexistent.fbx")

def test_geometry():
    scene = ufbx.load_file(os.path.join(data_root, "blender-default.fbx"))

    node = ufbx.find_node(scene, "Cube")
    assert node
    mesh = node.mesh
    assert mesh
    assert len(mesh.vertices) == 8
    assert abs(mesh.vertices[0].x - 1) <= 0.01

def test_ignore_geometry():
    scene = ufbx.load_file(os.path.join(data_root, "blender-default.fbx"),
        ignore_geometry=True)

    node = ufbx.find_node(scene, "Cube")
    assert node
    mesh = node.mesh
    assert mesh
    assert len(mesh.vertices) == 0

def test_element_identity():
    scene = ufbx.load_file(os.path.join(data_root, "blender-default.fbx"),
        ignore_geometry=True)

    a = scene.root_node
    b = scene.root_node
    assert a is b

    a = ufbx.find_node(scene, "Cube")
    b = ufbx.find_node(scene, "Cube")
    assert a is b

    pos_a = a.local_transform.translation
    pos_b = a.local_transform.translation
    assert pos_a is pos_b

def test_axis_conversion():
    scene = ufbx.load_file(os.path.join(data_root, "max-geometry-transform.fbx"),
        target_axes=ufbx.axes_right_handed_y_up,
        target_unit_meters=1,
        space_conversion=ufbx.SpaceConversion.ADJUST_TRANSFORMS,
    )
    assert scene

    node = scene.find_node("Plane001")
    assert node

    transform = node.local_transform
    assert transform.translation == approx(ufbx.Vec3(0, 0, 0))
    assert transform.rotation == approx(ufbx.Quat(-rcp_sqrt_2, 0.0, 0.0, rcp_sqrt_2))
    assert transform.scale == approx(ufbx.Vec3(0.0254, 0.0254, 0.0254))

def test_anim_evaluation():
    scene = ufbx.load_file(os.path.join(data_root, "maya-anim.fbx"))
    assert scene

    anim = scene.anim

    node = scene.find_node("pCube1")

    transform = node.evaluate_transform(anim, 0.0)
    assert transform.translation == approx(ufbx.Vec3(0.0, 0.0, 0.0))

    transform = node.evaluate_transform(anim, 0.5)
    assert transform.translation == approx(ufbx.Vec3(-3.0, 0.0, 0.0))

    layer = scene.anim_layers[0]
    assert layer

    props = layer.find_anim_props(node)
    assert len(props) == 3

    names = set(p.prop_name for p in props)
    assert names == { "Lcl Translation", "Lcl Scaling", "Lcl Rotation" }

    prop = layer.find_anim_prop(node, "Lcl Translation")
    assert prop

    curve = prop.anim_value.curves[0]
    assert curve

    assert curve.evaluate(0.5, 0.0) == approx(-3.0)

def test_separate_opts():
    opts = ufbx.LoadOpts(
        filename="fake.fbx",
    )

    scene = ufbx.load_file(os.path.join(data_root, "blender-default.fbx"), **opts)
    assert scene

    assert scene.metadata.filename == "fake.fbx"

def test_opts_bytes():
    opts = ufbx.LoadOpts(
        raw_filename=b"bad\xff.fbx",
    )

    scene = ufbx.load_file(os.path.join(data_root, "blender-default.fbx"), **opts)
    assert scene

    assert scene.metadata.raw_filename == b"bad\xff.fbx"

def test_unload():
    scene = ufbx.load_file(os.path.join(data_root, "blender-default.fbx"))
    assert scene

    scene.free()

def test_unload_error():
    scene = ufbx.load_file(os.path.join(data_root, "blender-default.fbx"))
    assert scene

    root = scene.root_node
    name = root.name

    scene.free()

    try:
        node = scene.find_node("Cube")
        assert False
    except ufbx.UseAfterFreeError:
        pass

    try:
        children = root.children
        assert False
    except ufbx.UseAfterFreeError:
        pass

    try:
        name = root.name
        assert False
    except ufbx.UseAfterFreeError:
        pass

def test_context():
    with ufbx.load_file(os.path.join(data_root, "blender-default.fbx")) as scene:
        assert scene

def test_unload_error():
    with ufbx.load_file(os.path.join(data_root, "blender-default.fbx")) as scene:
        assert scene

        root = scene.root_node
        name = root.name

    try:
        node = scene.find_node("Cube")
        assert False
    except ufbx.UseAfterFreeError:
        pass

    try:
        children = root.children
        assert False
    except ufbx.UseAfterFreeError:
        pass

    try:
        name = root.name
        assert False
    except ufbx.UseAfterFreeError:
        pass

def test_dangling_buffer():
    scene = ufbx.load_file(os.path.join(data_root, "blender-default.fbx"))
    assert scene

    mesh = scene.meshes[0]
    vertices = memoryview(mesh.vertices)
    assert vertices
    assert vertices.shape == (8, 3)

    try:
        scene.free()
    except ufbx.BufferReferenceError:
        pass

    del vertices

    scene.free()
