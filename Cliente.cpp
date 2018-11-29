

#include "Cliente.h"
#include "Pessoa.h"
#include <string>

Cliente::Cliente(std::string nome, std::string cpf, std::string email, Endereco endereco, // @suppress("Class members should be properly initialized")
		std::string tel, std::string dtcadastro, TipoCliente tipo): Pessoa(nome, cpf, email, endereco, tel) {
	this->dtcadastro = dtcadastro;
	this->tipo = tipo;

}

Cliente::Cliente(int id, std::string nome, std::string cpf, std::string email, Endereco endereco,
		std::string tel, std::string dtcadastro, TipoCliente tipo): Pessoa(nome, cpf, email, endereco, tel) {
	this->dtcadastro = dtcadastro;
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
