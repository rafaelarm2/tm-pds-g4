#include "Funcionario.h"

#include <string>
#include <iostream>

using namespace std;

Funcionario::Funcionario(std::string nome, std::string cpf, std::string rg, std::string email, Endereco endereco,
		std::string tel, std::string usuario, std::string senha, std::string dtadmissao, std::string dtdemissao):
		Pessoa(nome, cpf, rg, email, endereco, tel) {
	this->usuario = usuario;
	this->senha = senha;
	this->dtadmissao = dtadmissao;
	this->dtdemissao = dtdemissao;

}

Funcionario::Funcionario(): Pessoa() {

}

Funcionario::~Funcionario() {
	// TODO Auto-generated destructor stub
}

