#include "Pessoa.h"
#include "Endereco.h"
#include <string>

using namespace std;

Pessoa::Pessoa(std::string nome, std::string cpf, std::string rg, std::string email, Endereco endereco,
		std::string tel) {
	this->nome = nome;
	this->cpf = cpf;
	this->rg = rg;
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

