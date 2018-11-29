#include "excecoes.h"

const char* SelecaoMenuInvalida::what() const noexcept{
    return "Opcao inserida invalida, por favor digite outro numero";
}

const char* InsercaoDeDadosIncorreta::what() const noexcept{
        return "Argumentos invalidos";
}

const char* OperacaoInvalida::what() const noexcept{
        return "Voce tentou realizar uma operacao invalida! Confira o restante no estoque ou reveja os valores inseridos como demanda.";
}
