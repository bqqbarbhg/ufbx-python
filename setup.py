from setuptools import setup, Extension, find_packages

ufbx_module = Extension(
    "ufbx._native",
    sources=["ufbx/native.c", "ufbx/ufbx.c"],
    extra_compile_args=["-O2"],
)

setup(
    name="ufbx",
    version="0.0.2",
    packages=find_packages(exclude=["test"]),
    ext_modules=[ufbx_module],
)
