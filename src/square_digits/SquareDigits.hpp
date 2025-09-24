#ifndef SQUAREDIGITS_H
#define SQUAREDIGITS_H

#include <string>

class SquareDigits {
public:
    // Função principal que recebe um número inteiro e retorna o número processado
    static int run(int num);

private:
    // Helpers internos
    static std::string squareDigitsToString(int num);
};

#endif // SQUAREDIGITS_H
