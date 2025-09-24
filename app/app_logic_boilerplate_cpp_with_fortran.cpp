// app/app_logic.cpp
#include <iostream>
#include <string>

// Declarações vindas do wrapper (src/)
void call_fortran_hello();
void call_fortran_hello_name(const std::string& name);
int call_fortran_add(int a, int b);

void run_app_logic() {
    std::cout << "=== Lógica da App (C++ chamando Fortran) ===" << std::endl;

    call_fortran_hello();
    call_fortran_hello_name("Elmir");
    int resultado = call_fortran_add(7, 5);

    std::cout << "Resultado recebido em C++: " << resultado << std::endl;
}
