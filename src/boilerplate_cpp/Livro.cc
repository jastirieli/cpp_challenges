#include "Livro.h"
#include <iostream>
#include <cstring>

Livro::Livro()
{

}

Livro::Livro(unsigned int codigo, char titulo[], char editora[], unsigned int paginas, char isbn[])
{
    this->codigo = codigo;
    strcpy(this->titulo, titulo);
    strcpy(this->editora, editora);
    this->paginas = paginas;
    strcpy(this->isbn, isbn);
}

Livro::~Livro()
{
    std::cout << "Livro deletado" << '\n';
}
