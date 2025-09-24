// src/fortran_wrapper.cpp
#include <iostream>
#include <string>

extern "C" {
    void fortran_hello();
    void fortran_hello_name(const char* name);
    int  fortran_add(int a, int b);
}

void call_fortran_hello() {
    fortran_hello();
}

void call_fortran_hello_name(const std::string& name) {
    fortran_hello_name(name.c_str());
}

int call_fortran_add(int a, int b) {
    return fortran_add(a, b);
}
