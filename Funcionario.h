

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
			std::string tel, std::string dtadmissao);
	Funcionario(int id, std::string nome, std::string cpf, std::string email, Endereco endereco,
			std::string tel, std::string dtadmissao);
	Funcionario(int id);
	Funcionario();
	virtual ~Funcionario();
	Endereco getEndereco();
	std::string getNome();
	std::string getCpf();
	std::string getEmail();
	std::string getTel();
	int getID();
	std::string getDtadmissao();
	std::string getDtdemissao();


};

#endif /* FUNCIONARIO_H_ */
