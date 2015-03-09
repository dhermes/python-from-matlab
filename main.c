#include <dlfcn.h>
#include <Python.h>
#include <stdio.h>
#include "foo.h"

int main(void)
{
    void* handle = dlopen("libpython2.7.so", RTLD_LAZY | RTLD_GLOBAL);
    Py_Initialize();
    initfoo();
    double zap[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    size_t zap_size = 6;
    size_t zap_rows = 3;
    size_t zap_cols = 2;

    int i;
    for (i = 0; i < zap_size; i++) {
        printf("zap[%d] before: %f\n", i, zap[i]);
    }
    from_waldo(&zap[0], zap_size, zap_rows, zap_cols);
    puts("================================================================");
    for (i = 0; i < zap_size; i++) {
        printf("zap[%d] after: %f\n", i, zap[i]);
    }
    Py_Finalize();
    dlclose(handle);
    return 0;
}
