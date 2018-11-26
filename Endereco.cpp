#include "Endereco.h"
#include <string>

using namespace std;

Endereco::Endereco(Logradouro logradouro, std::string tipologradouro, std::string bairro, std::string cep, int num, std::string comp, Cidade cidade) {
	// TODO Auto-generated constructor stub
	this->logradouro = logradouro;
	this->tipologradouro = tipologradouro;
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

Cidade Endereco::getCidade() {
	return this->cidade;
}

