#include <iostream>

// declaração de run_app (definida em app_logic.cpp)
void run_app();

int main() {
    try {
        run_app();
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Erro desconhecido." << std::endl;
        return 1;
    }

    return 0;
}
