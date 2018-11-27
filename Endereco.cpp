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


//gets
int Endereco::getID(){
	return this->id;
}

std::string Endereco::getLogradouro(){
	return this->logradouro;
}

std::string Endereco::getBairro(){
	return this->bairro;
}

std::string Endereco::getCep(){
	return this->cep;
}

int Endereco::getNum(){
	return this->num;
}

std::string Endereco::getComp(){
	return this->comp;
}

std::string Endereco::getCidade() {
	return this->cidade;
}

//sets
void Endereco::setID(int id_){
	this->id = id_;
}

void Endereco::setLogradouro(std::string logradouro_){
	this->logradouro = logradouro_;
}

void Endereco::setBairro(std::string bairro_){
	this->bairro = bairro_;
}

void Endereco::setCep(std::string cep_){
	this->cep = cep_;
}

void Endereco::setNum(int num_){
	this->num = num_;
}

void Endereco::setComp(std::string comp_){
	this->comp = comp_;
}

void Endereco::setCidade(std::string cidade_){
	this->cidade = cidade_;
}