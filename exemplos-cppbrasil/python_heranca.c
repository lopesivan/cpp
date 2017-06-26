// http://svn.python.org/view/python/trunk/Include/object.h

#define PyObject_HEAD                   \
    _PyObject_HEAD_EXTRA                \
    Py_ssize_t ob_refcnt;               \
    struct _typeobject *ob_type;

#define PyObject_VAR_HEAD \
    PyObject_HEAD \
    Py_ssize_t ob_size; /* Number of items in variable part */

typedef struct _object {
    PyObject_HEAD
} PyObject;

// http://svn.python.org/view/python/trunk/Include/stringobject.h

typedef struct {
    PyObject_VAR_HEAD
    long ob_shash;
    int ob_sstate;
    char ob_sval[1];
} PyStringObject;

// http://svn.python.org/view/python/trunk/Include/floatobject.h

typedef struct {
    PyObject_HEAD
    double ob_fval;
} PyFloatObject;

// http://svn.python.org/view/python/trunk/Include/listobject.h

typedef struct {
    PyObject_VAR_HEAD
    PyObject **ob_item;
    Py_ssize_t allocated;
} PyListObject;

// http://svn.python.org/view/python/trunk/Objects/listobject.c

PyObject *PyList_GetItem(PyObject *op, Py_ssize_t i)
{
    if (!PyList_Check(op)) {
        PyErr_BadInternalCall();
        return NULL;
    }
    if (i < 0 || i >= Py_SIZE(op)) {
        if (indexerr == NULL) {
            indexerr = PyString_FromString("list index out of range");
            if (indexerr == NULL)
                return NULL;
        }
        PyErr_SetObject(PyExc_IndexError, indexerr);
        return NULL;
    }
    return ((PyListObject *)op) -> ob_item[i];
}