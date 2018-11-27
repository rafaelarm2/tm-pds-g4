#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>

using namespace std;

class SelecaoMenuInvalida : public std::exception {
    const char* what() const noexcept override;
};

#endif