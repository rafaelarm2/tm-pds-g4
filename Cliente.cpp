#include "Cliente.h"
#include "Pessoa.h"
#include <string>

Cliente::Cliente(std::string nome, std::string cpf, std::string rg, std::string email, Endereco endereco,
		std::string tel, std::string dtcadastro, TipoCliente tipo): Pessoa(nome, cpf, rg, email, endereco, tel) {
	this->dtcadastro = dtcadastro;
	this->tipo = tipo;

}

Cliente::Cliente(): Pessoa() { // @suppress("Class members should be properly initialized")

}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

Endereco Cliente::getEndereco() {
	return this->endereco;
}


