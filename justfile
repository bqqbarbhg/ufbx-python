
parse:
    python3 bindgen/ufbx_parser.py -i src/ufbx/native/ufbx.h
    python3 bindgen/ufbx_ir.py

generate:
    python3 bindgen/generate_python.py

build:
    python setup.py build

