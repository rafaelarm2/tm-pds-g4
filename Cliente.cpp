#include "Cliente.h"
#include "Pessoa.h"
#include <string>
#include "excecoes.h"

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

Cliente::Cliente(std::string nome, std::string cpf, std::string email, Endereco endereco, // @suppress("Class members should be properly initialized")
		std::string tel, std::string dtcadastro, TipoCliente tipo): Pessoa(nome, cpf, email, endereco, tel) {
	if(checa_data(dtcadastro) == 1)
		this->dtcadastro = dtcadastro;
	else 
		throw InsercaoDeDadosIncorreta();
	this->tipo = tipo;

}

Cliente::Cliente(int id, std::string nome, std::string cpf, std::string email, Endereco endereco,
		std::string tel, std::string dtcadastro, TipoCliente tipo): Pessoa(nome, cpf, email, endereco, tel) {
	if(checa_data(dtcadastro) == 1)
		this->dtcadastro = dtcadastro;
	else 
		throw InsercaoDeDadosIncorreta();
	this->tipo = tipo;
	this->id = id;

}

Cliente::Cliente(int id): Pessoa() { // @suppress("Class members should be properly initialized")
	this->id = id;
}

Cliente::Cliente(): Pessoa() { // @suppress("Class members should be properly initialized")

}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

Endereco Cliente::getEndereco() {
	return this->endereco;
}

std::string Cliente::getNome() {
	return this->nome;
}

std::string Cliente::getCpf() {
	return this->cpf;
}

std::string Cliente::getEmail() {
	return this->email;
}

std::string Cliente::getTel() {
	return this->tel;
}

std::string Cliente::getDtcadastro() {
	return this->dtcadastro;
}

TipoCliente Cliente::getTipo() {
	return this->tipo;
}
