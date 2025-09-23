#include <iostream>
#include "SquareDigits.h"

void run_app() {
    int input;
    std::cout << "Digite um número: ";
    std::cin >> input;

    int result = SquareDigits::run(input);

    std::cout << "Resultado: " << result << std::endl;
}
