#include "Cidade.h"
#include <string>

Cidade::Cidade(std::string nome, Estado sgestado) {
	this->nome = nome;
	this->sgestado = sgestado;

}

Cidade::Cidade() {
	this->nome = "Coronel Fabriciano";
	this->sgestado = Estado::MG;
}

Cidade::~Cidade() {
	// TODO Auto-generated destructor stub
}

std::string Cidade::getNome() {
	return this->nome;
}

