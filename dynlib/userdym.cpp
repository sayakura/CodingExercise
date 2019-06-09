#include <dlfcn.h>
#include "dynamic.hpp"

int main(void)
{
    void *handle = dlopen("dynamic.so", RTLD_LAZY);
    MyClass *(*create)();

    create = (MyClass *(*)())dlsym(handle, "create_class");
    MyClass *a = create();
    a->dosth();
    delete a;
}