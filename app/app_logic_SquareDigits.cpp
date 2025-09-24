#include <iostream>
#include "SquareDigits.hpp"

void run_app() {
    int input;
    std::cout << "Digite um número: ";
    std::cin >> input;

    int result = SquareDigits::run(input);

    std::cout << "Resultado: " << result << std::endl;
}
