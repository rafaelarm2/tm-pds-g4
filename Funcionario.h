#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <string>
#include <iostream>
#include "Pessoa.h"

using namespace std;

class Funcionario: public Pessoa{
protected:
	static int id;
	std::string dtadmissao;
	std::string dtdemissao;
public:
	Funcionario(std::string nome, std::string cpf, std::string email, Endereco endereco,
			std::string tel, std::string dtadmissao, std::string dtdemissao);
	Funcionario();
	virtual ~Funcionario();


//gets
	Endereco getEndereco();
	std::string getNome();
	std::string getCpf();
	std::string getEmail();
	std::string getTel();

	int getID();
	std::string getDtadmissao();
	std::string getDtdemissao();

//sets
	void setEndereco(Endereco endereco_);
	void setNome(std::string nome_);
	void setCpf(std::string cpf_);
	void setEmail(std::string email_);
	void setTel(std::string tel_);

	//void setID(int id_);
	void setDtadmissao(std::string dtadmissao_);
	void setDtdemissao(std::string dtdemissao_);
};

#endif /* FUNCIONARIO_H_ */
