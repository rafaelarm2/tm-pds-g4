
#include "Funcionario.h"
#include "excecoes.h"
#include <string>
#include <iostream>

using namespace std;

bool checa_data(std::string str){
    std::string::size_type sz;
    
    std::string dia;
    dia[0] = str[0];
    dia[1] = str[1];
    
    try {
		std::stod (dia, &sz);
	}
	catch (const std::invalid_argument& ia){
		std::cout << "Argumento invalido, por favor insira outro valor. " << std::endl;
		return 0;
	}
    int day = std::stod (dia, &sz);
    
    
    std::string mes;
    mes[0] = str[3];
    mes[1] = str[4];
    
    try {
		std::stod (mes, &sz);
	}
	catch (const std::invalid_argument& ia){
		std::cout << "Argumento invalido, por favor insira outro valor. " << std::endl;
		return 0;
	}
    int month = std::stod (mes, &sz);
    
    
    std::string ano;
    ano[0] = str[6];
    ano[1] = str[7];
    ano[2] = str[8];
    ano[3] = str[9];
    
    try {
		std::stod (ano, &sz);
	}
	catch (const std::invalid_argument& ia){
		std::cout << "Argumento invalido, por favor insira outro valor. " << std::endl;
		return 0;
	}
    int year = std::stod (ano, &sz);
    
    if ( (str[5] == '/') && (str[2] == '/') ){
        std::cout << "Formato de data valido, fique atento para as excecoes" << std::endl;
        return true;
    }
    else{ 
        std::cout << "Formato de data invalido, por favor insira outro valor!" << std::endl;
        return false;
    }
}

Funcionario::Funcionario(std::string nome, std::string cpf, std::string email, Endereco endereco, // @suppress("Class members should be properly initialized")
		std::string tel, std::string dtadmissao):
		Pessoa(nome, cpf, email, endereco, tel) {
	if(checa_data(dtadmissao) == 1)
		this->dtadmissao = dtadmissao;
	else 
		throw InsercaoDeDadosIncorreta();

}

Funcionario::Funcionario(int id, std::string nome, std::string cpf, std::string email, Endereco endereco, // @suppress("Class members should be properly initialized")
		std::string tel, std::string dtadmissao):
		Pessoa(nome, cpf, email, endereco, tel) {
	if(checa_data(dtadmissao) == 1)
		this->dtadmissao = dtadmissao;
	else 
		throw InsercaoDeDadosIncorreta();
	this->id = id;

}

Funcionario::Funcionario(int id): Pessoa() {
	this->id = id;
}

Funcionario::Funcionario(): Pessoa() { // @suppress("Class members should be properly initialized")

}

Funcionario::~Funcionario() {
	// TODO Auto-generated destructor stub
}

Endereco Funcionario::getEndereco() {
	return this->endereco;
}

std::string Funcionario::getNome() {
	return this->nome;
}

std::string Funcionario::getCpf() {
	return this->cpf;
}

std::string Funcionario::getEmail() {
	return this->email;
}

std::string Funcionario::getTel() {
	return this->tel;
}

std::string Funcionario::getDtadmissao() {
	return this->dtadmissao;
}

std::string Funcionario::getDtdemissao() {
	return this->dtdemissao;
}

