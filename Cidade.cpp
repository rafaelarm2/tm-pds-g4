#include "Cidade.h"
#include <string>

Cidade::Cidade(string nome, Estado sgestado) {
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

string Cidade::getNome() {
	return this->nome;
}

int Cidade::getID(){
	return this->id;
}

Estado Cidade::getEstado(){
	return this->sgestado;
}

void Cidade::setNome(string nome_){
	this->nome = nome_;
}

void Cidade::setID(int id_){
	this->id = id_;
}

void Cidade::setEstado(Estado state){
	this->sgestado = state;
}