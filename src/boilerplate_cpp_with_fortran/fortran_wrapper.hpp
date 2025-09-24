// src/cpp/fortran_wrapper.h
#ifndef FORTRAN_WRAPPER_H
#define FORTRAN_WRAPPER_H

#include <string>

// Declarações externas das funções Fortran
extern "C" {
    int fortran_initialize();
    void fortran_cleanup();
    void fortran_say_hello();
    void fortran_say_hello_to(const char* name);
    int fortran_calculate(int a, int b, int operation);
    void fortran_version_info();
}

namespace FortranWrapper {

    enum class Operation {
        ADD = 0,
        SUBTRACT = 1,
        MULTIPLY = 2,
        DIVIDE = 3
    };

    class FortranManager {
    private:
        static bool is_initialized;
        
    public:
        static bool initialize();
        static void cleanup();
        static bool isFortranInitialized() { return is_initialized; }
        
        static void sayHello();
        static void sayHelloTo(const std::string& name);
        static int calculate(int a, int b, Operation op);
        static void showVersionInfo();
    };

} // namespace FortranWrapper

#endif // FORTRAN_WRAPPER_H