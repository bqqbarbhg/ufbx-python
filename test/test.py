from ufbx.native import load_scene

scene = load_scene("test/blender-default.fbx")
node = scene.root_node
print(node.name)
