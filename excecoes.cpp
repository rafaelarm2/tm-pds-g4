#include "excecoes.h"

const char* SelecaoMenuInvalida::what() const noexcept{
    return "Opcao inserida invalida, por favor digite outro numero";
}

const char* InsercaoDeDadosIncorreta::what() const noexcept{
        return "Argumentos invalidos";
}
