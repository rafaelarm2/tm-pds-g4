#include "Pessoa.h"
#include "Endereco.h"
#include <string>

using namespace std;

bool validaCPF(const char * cpf){
    unsigned lenght = 0;
    int ver1 = 0, ver2 = 0;
    char aux;

    /* contando o tamanho de cpf e verificando se o o tamanho do mesmo é 11
     */
    while (cpf[lenght]) {
        lenght++;
    }

    if (lenght != 11)
        return false;

    /* Calculando o primeiro dígito verificador. Cada dígito tem um peso co-
     * meçando de 1 até 9. Para calculá-lo deve-se somar cada dígito, multi-
     * plicando-se por seu peso e ao final realizar a operação de módulo por
     * 11
     */
    for (int j=0; j<9; j++){
        aux = cpf[j];
        ver1 += atoi(&aux)*(j+1);
    }

    ver1 %= 11;

    /* Para o segundo dígito verificador calcula-se a partir do segundo dí-
     * gito até o 10º ( dígito verificador 1 ) atribuindo-se o peso de 1  a
     * 9, e no final realizar a operação Módulo por 11
     */
    for (int j=0; j<9; j++){
        aux = cpf[j];
        ver2 += atoi(&aux)*j;
    }

    ver2 += ver1*9;
    ver2 %= 11;

    /* compara-se agora ver1 e ver2 com os dígitos do cpf */
    aux = cpf[lenght-2];
    if (atoi(&aux) == ver1){
        aux = cpf[lenght-1];
        if ( atoi(&aux) == ver2)
            return true;
    }
    return false;
}

Pessoa::Pessoa(std::string nome, std::string cpf, std::string email, Endereco endereco,
		std::string tel) {
	this->nome = nome;
	if(validaCpf(cpf) == 1)
		this->cpf = cpf;
	else 
		throw InsercaoDeDadosInvalida();
	this->email = email;
	this->endereco = endereco;
	this->tel = tel;
}

Pessoa::Pessoa() {

}

Pessoa::~Pessoa() {
	// TODO Auto-generated destructor stub
}

Endereco Pessoa::getEndereco() {
	return this->endereco;
}

std::string Pessoa::getNome() {
	return this->nome;
}

std::string Pessoa::getCpf() {
	return this->cpf;
}

std::string Pessoa::getEmail() {
	return this->email;
}

std::string Pessoa::getTel() {
	return this->tel;
}

