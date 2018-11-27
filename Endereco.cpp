#include "Endereco.h"
#include <string>

using namespace std;

Endereco::Endereco(std::string logradouro, std::string bairro, std::string cep,
		int num, std::string comp, std::string cidade) {
	// TODO Auto-generated constructor stub
	this->logradouro = logradouro;
	this->bairro = bairro;
	this->cep = cep;
	this->num = num;
	this->comp = comp;
	this->cidade = cidade;
}

Endereco::Endereco() { // @suppress("Class members should be properly initialized")

}

Endereco::~Endereco() {
	// TODO Auto-generated destructor stub
}

std::string Endereco::getCidade() {
	return this->cidade;
}
