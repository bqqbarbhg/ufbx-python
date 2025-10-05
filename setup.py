from setuptools import setup, Extension, find_packages

ufbx_module = Extension(
    "ufbx._native",
    sources=["src/ufbx/native/native.c", "src/ufbx/native/ufbx.c"],
    extra_compile_args=["-O2"]
)

setup(
    name="ufbx",
    version="1.1.3",
    packages=find_packages(),
    ext_modules=[ufbx_module],
)
