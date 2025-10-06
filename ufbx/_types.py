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
