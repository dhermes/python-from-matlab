import numpy as np

from cython cimport view

from bar import waldo


cdef public void from_waldo(double* zap, size_t zap_size,
                            size_t zap_rows, size_t zap_cols):
    cdef view.array py_zap = <double[:zap_size]> zap
    waldo(np.asarray(py_zap, order='F').reshape(
        (zap_rows, zap_cols), order='F'))
