from typing import NamedTuple
from dataclasses import dataclass

class Vec2(NamedTuple):
    x: float
    y: float

class Vec3(NamedTuple):
    x: float
    y: float
    z: float

class Vec4(NamedTuple):
    x: float
    y: float
    z: float
    w: float

class Quat(NamedTuple):
    x: float
    y: float
    z: float
    w: float

class Matrix(NamedTuple):
    c0: Vec3
    c1: Vec3
    c2: Vec3
    c3: Vec3

zero_vec2 = Vec2(0, 0)
zero_vec3 = Vec3(0, 0, 0)
zero_vec4 = Vec4(0, 0, 0, 0)
identity_quat = Quat(0, 0, 0, 1)
identity_matrix = Matrix(Vec3(1, 0, 0), Vec3(0, 1, 0), Vec3(0, 0, 1), Vec3(0, 0, 0))
