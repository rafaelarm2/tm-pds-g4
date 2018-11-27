/*
 * Cliente.cpp
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#include "Cliente.h"
#include "Pessoa.h"
#include <string>

Cliente::Cliente(std::string nome, std::string cpf, std::string email, Endereco endereco,
		std::string tel, std::string dtcadastro, TipoCliente tipo): Pessoa(nome, cpf, email, endereco, tel) {
	this->dtcadastro = dtcadastro;
	this->tipo = tipo;

}

Cliente::Cliente(): Pessoa() { // @suppress("Class members should be properly initialized")

}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

//gets
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



//sets
void Cliente::setEndereco(Endereco endereco_) {
	this->endereco = endereco_;
}

void Cliente::setNome(std::string nome_) {
	this->nome = nome_;
}

void Cliente::setCpf(std::string cpf_) {
	this->cpf = cpf_;
}

void Cliente::setEmail(std::string email_) {
	this->email = email_;
}

void Cliente::setTel(std::string tel_) {
	this->tel = tel_;
}

void Cliente::setDtcadastro(std::string dtcadastro_) {
	this->dtcadastro = dtcadastro_;
}

void Cliente::setTipo(std::string tipo_){
	this->tipo = tipo_;
}
