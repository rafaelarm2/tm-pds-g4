/*
 * Funcionario.h
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <string>
#include <iostream>
#include "Pessoa.h"

using namespace std;

class Funcionario: public Pessoa{
protected:
	static int id;
	std::string usuario;
	std::string senha;
	std::string dtadmissao;
	std::string dtdemissao;
public:
	Funcionario(std::string nome, std::string cpf, std::string rg, std::string email, Endereco endereco,
			std::string tel, std::string usuario, std::string senha, std::string dtadmissao, std::string dtdemissao);
	Funcionario();
	virtual ~Funcionario();
};

#endif /* FUNCIONARIO_H_ */
