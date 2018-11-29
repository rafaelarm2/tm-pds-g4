#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <string>
#include <iostream>
#include "Pessoa.h"

using namespace std;

class Funcionario: public Pessoa{
protected:
	int id;
	std::string dtadmissao;
	std::string dtdemissao;
public:
	Funcionario(std::string nome, std::string cpf, std::string email, Endereco endereco,
			std::string tel, std::string dtadmissao, std::string dtdemissao);
	Funcionario(int id);
	Funcionario();
	virtual ~Funcionario();
};

#endif /* FUNCIONARIO_H_ */
