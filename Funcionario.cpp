
#include "Funcionario.h"

#include <string>
#include <iostream>

using namespace std;

Funcionario::Funcionario(std::string nome, std::string cpf, std::string email, Endereco endereco, // @suppress("Class members should be properly initialized")
		std::string tel, std::string dtadmissao):
		Pessoa(nome, cpf, email, endereco, tel) {
	this->dtadmissao = dtadmissao;

}

Funcionario::Funcionario(int id, std::string nome, std::string cpf, std::string email, Endereco endereco, // @suppress("Class members should be properly initialized")
		std::string tel, std::string dtadmissao):
		Pessoa(nome, cpf, email, endereco, tel) {
	this->dtadmissao = dtadmissao;
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

