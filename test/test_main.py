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

    # curve = scene.find_anim_prop(
