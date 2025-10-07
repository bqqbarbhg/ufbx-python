import numpy as np
from numpy.testing import assert_equal, assert_allclose
import ufbx
import os

self_root = os.path.dirname(os.path.abspath(__file__))
data_root = os.path.join(self_root, "data")

def test_np_geometry():
    scene = ufbx.load_file(os.path.join(data_root, "blender-default.fbx"))

    node = scene.find_node("Cube")
    assert node

    mesh = node.mesh
    assert mesh

    ref_indices = list(mesh.vertex_indices)

    indices = np.array(mesh.vertex_indices)
    assert indices.shape == (24,)
    assert_equal(indices, np.array(ref_indices))

    ref_vertices = list(mesh.vertices)

    vertices = np.array(mesh.vertices)
    assert vertices.shape == (8, 3)
    assert_equal(vertices, np.array(ref_vertices))
