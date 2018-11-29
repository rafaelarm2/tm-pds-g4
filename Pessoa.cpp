#include "Pessoa.h"
#include "Endereco.h"
#include <string>

using namespace std;

Pessoa::Pessoa(std::string nome, std::string cpf, std::string email, Endereco endereco,
		std::string tel) {
	this->nome = nome;
	this->cpf = cpf;
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

