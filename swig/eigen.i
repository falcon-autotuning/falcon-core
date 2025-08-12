// SWIG typemaps for Eigen::Matrix <-> NumPy array conversion.

%{
#define SWIG_FILE_WITH_INIT
#include <Eigen/Dense>
%}

// Include NumPy fragments
%include "numpy.i"

// This block ensures that the NumPy C-API is initialized.
%init %{
import_array();
%}

// Typemap for converting a NumPy array to an Eigen::Matrix (input)
%typemap(in) const Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>& (Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> temp) {
    if (!PyArray_Check($input)) {
        PyErr_SetString(PyExc_ValueError, "Expected a NumPy array.");
        SWIG_fail;
    }
    PyArrayObject *array = (PyArrayObject*)$input;
    if (PyArray_NDIM(array) != 2) {
        PyErr_SetString(PyExc_ValueError, "Expected a 2D NumPy array.");
        SWIG_fail;
    }
    if (PyArray_TYPE(array) != NPY_DOUBLE) {
        PyErr_SetString(PyExc_ValueError, "Expected a NumPy array of type float64.");
        SWIG_fail;
    }
    npy_intp* dims = PyArray_DIMS(array);
    temp.resize(dims[0], dims[1]);
    memcpy(temp.data(), PyArray_DATA(array), dims[0] * dims[1] * sizeof(double));
    $1 = &temp;
}

// Typemap for converting an Eigen::Matrix to a NumPy array (output)
%typemap(out) Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> {
    npy_intp dims[2] = {$1.rows(), $1.cols()};
    $result = PyArray_SimpleNew(2, dims, NPY_DOUBLE);
    memcpy(PyArray_DATA((PyArrayObject*)$result), $1.data(), $1.size() * sizeof(double));
}

// Typemap for returning a const reference to an Eigen::Matrix
%typemap(out) const Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>& {
    npy_intp dims[2] = {$1->rows(), $1->cols()};
    $result = PyArray_SimpleNew(2, dims, NPY_DOUBLE);
    memcpy(PyArray_DATA((PyArrayObject*)$result), $1->data(), $1->size() * sizeof(double));
}
