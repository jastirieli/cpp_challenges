#include "SquareDigits.hpp"
#include <string>

int SquareDigits::run(int num) {
    std::string squared = squareDigitsToString(num);
    return std::stoi(squared); // converte de volta para int
}

std::string SquareDigits::squareDigitsToString(int num) {
    std::string result;
    std::string str = std::to_string(num);

    for (char c : str) {
        int digit = c - '0';
        int squared = digit * digit;
        result += std::to_string(squared);
    }

    return result;
}


/*
code golf version

int square_digits(int n) {
  int a = 1;   // fator multiplicador para "posicionar" os dígitos
  int m = 0;   // resultado acumulado
  while (n > 0) {
    int d = n % 10;   // pega o último dígito
    m += a * d * d;   // soma o quadrado do dígito, deslocado pela potência correta
    a *= d <= 3 ? 10 : 100;  // ajusta o deslocamento para o próximo quadrado
    n /= 10;  // descarta o último dígito
  }
  return m;
}

*/