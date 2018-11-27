
#include "Funcionario.h"

#include <string>
#include <iostream>

using namespace std;

Funcionario::Funcionario(std::string nome, std::string cpf, std::string email, Endereco endereco,
		std::string tel, std::string dtadmissao, std::string dtdemissao):
		Pessoa(nome, cpf, email, endereco, tel) {
	this->dtadmissao = dtadmissao;
	this->dtdemissao = dtdemissao;

}

Funcionario::Funcionario(): Pessoa() {

}

Funcionario::~Funcionario() {
	// TODO Auto-generated destructor stub
}


//gets
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


int Funcionario::getID(){
	return this->id;
}

std::string Funcionario::getDtadmissao() {
	return this->dtadmissao;
}

std::string Funcionario::getDtdemissao() {
	return this->dtdemissao;
}


//sets
void Funcionario::setEndereco(Endereco endereco_) {
	this->endereco = endereco_;
}

void Funcionario::setNome(std::string nome_) {
	this->nome = nome_;
}

void Funcionario::setCpf(std::string cpf_) {
	this->cpf = cpf_;
}

void Funcionario::setEmail(std::string email_) {
	this->email = email_;
}

void Funcionario::setTel(std::string tel_) {
	this->tel = tel_;
}


void Funcionario::setID(int id_){
	this->id = id_;
}

void Funcionario::setDtadmissao(std::string dtadmissao_) {
	this->dtadmissao = dtadmissao_;
}

void Funcionario::setDtdemissao(std::string dtdemissao_) {
	this->dtdemissao = dtdemissao_;
}