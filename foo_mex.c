#include <dlfcn.h>
#include <Python.h>
#include <stdio.h>
#include "foo.h"
#include "mex.h"

void call_py(double *zap, size_t zap_size, size_t zap_rows, size_t zap_cols)
{
    void* handle = dlopen("libpython2.7.so", RTLD_LAZY | RTLD_GLOBAL);
    Py_Initialize();
    initfoo();
    from_waldo(zap, zap_size, zap_rows, zap_cols);
    Py_Finalize();
    dlclose(handle);
}

void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[])
{
    double *out_matrix;
    size_t zap_size;
    size_t zap_rows;
    size_t zap_cols;

    if (nrhs != 1) {
        mexErrMsgIdAndTxt("foo_mex:nrhs", "One input required.");
    }
    if (nlhs != 1) {
        mexErrMsgIdAndTxt("foo_mex:nlhs", "One output required.");
    }

    zap_rows = mxGetM(prhs[0]);
    zap_cols = mxGetN(prhs[0]);
    zap_size = zap_rows * zap_cols;

    /* Create a copy of input to be modified. */
    plhs[0] = mxDuplicateArray(prhs[0]);
    out_matrix = mxGetPr(plhs[0]);
    call_py(out_matrix, zap_size, zap_rows, zap_cols);
}
