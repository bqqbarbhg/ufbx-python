import pytest
import ufbx
import os

root = os.path.dirname(os.path.abspath(__file__))

def test_loading():
    is_thread_safe = ufbx.is_thread_safe()
    assert is_thread_safe

def test_simple():
    scene = ufbx.load_file(os.path.join(root, "blender-default.fbx"))
    assert scene

def test_nonexistent():
    try:
        scene = ufbx.load_file(os.path.join(root, "nonexistent.fbx"))
        assert False
    except ufbx.FileNotFoundError as e:
        msg = str(e)
        assert msg.startswith("File not found:")
        assert msg.endswith("nonexistent.fbx")

def test_geometry():
    scene = ufbx.load_file(os.path.join(root, "blender-default.fbx"))

    node = ufbx.find_node(scene, "Cube")
    assert node
    mesh = node.mesh
    assert mesh
    assert len(mesh.vertices) == 8
    assert abs(mesh.vertices[0].x - 1) <= 0.01

def test_ignore_geometry():
    scene = ufbx.load_file(os.path.join(root, "blender-default.fbx"),
        ignore_geometry=True)

    node = ufbx.find_node(scene, "Cube")
    assert node
    mesh = node.mesh
    assert mesh
    assert len(mesh.vertices) == 0
