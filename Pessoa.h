/*
 * Funcionario.h
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#ifndef PESSOA_H_
#define PESSOA_H_

#include <string>
#include "Cidade.h"
#include "Endereco.h"

using namespace std;

class Pessoa {
protected:
	std::string nome;
	std::string cpf;
	std::string rg;
	std::string email;
	Endereco endereco;
	std::string tel;
public:
	Pessoa(std::string nome, std::string cpf, std::string rg, std::string email, Endereco endereco, std::string tel);
	Pessoa();
	virtual ~Pessoa();

	Endereco getEndereco();
};

#endif /* PESSOA_H_ */
