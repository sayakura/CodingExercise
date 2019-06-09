
#include "dynamic.hpp"
#include <iostream>

extern "C" MyClass* create_class()
{
    return new MyClass();
}


MyClass::MyClass()
{
    
}
void MyClass::dosth(void)
{
    std::cout << "wtf" << std::endl;
}

