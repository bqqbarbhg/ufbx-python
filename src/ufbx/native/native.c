
#include "generated.h"

static PyObject *ufbx_hello(PyObject *self, PyObject *args)
{
    printf("Hello world!\n");
    return Py_None;
}

static int ufbx_module_exec(PyObject *m)
{
    return 0;
}

static PyModuleDef_Slot ufbx_module_slots[] = {
    {Py_mod_exec, ufbx_module_exec},
    {0, NULL}
};

static PyMethodDef ufbx_methods[] = {
    {"hello",  &ufbx_hello, METH_VARARGS, "Hello world"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef ufbx_module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "ufbx",
    .m_size = 0,  // non-negative
    .m_slots = ufbx_module_slots,
    .m_methods = ufbx_methods,
};

PyMODINIT_FUNC
PyInit__native(void)
{
    return PyModuleDef_Init(&ufbx_module);
}
