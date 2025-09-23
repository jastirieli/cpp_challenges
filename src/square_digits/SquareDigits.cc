#include "SquareDigits.h"
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
