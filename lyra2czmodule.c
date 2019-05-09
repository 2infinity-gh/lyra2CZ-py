#include <Python.h>

#include "lyra2cz.h"

static PyObject *lyra2cz_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    lyra2cz_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    lyra2cz_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef Lyra2ZMethods[] = {
    { "getPoWHash", lyra2cz_getpowhash, METH_VARARGS, "Returns the proof of work hash using lyra2cz hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef Lyra2ZModule = {
    PyModuleDef_HEAD_INIT,
    "lyra2cz_hash",
    "...",
    -1,
    Lyra2ZMethods
};

PyMODINIT_FUNC PyInit_lyra2cz_hash(void) {
    return PyModule_Create(&Lyra2ZModule);
}

#else

PyMODINIT_FUNC initlyra2cz_hash(void) {
    (void) Py_InitModule("lyra2cz_hash", Lyra2ZMethods);
}
#endif
