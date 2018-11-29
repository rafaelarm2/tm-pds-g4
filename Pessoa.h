#ifndef PESSOA_H_
#define PESSOA_H_

#include <string>
#include "Endereco.h"

using namespace std;

class Pessoa {
protected:
	std::string nome;
	std::string cpf;
	std::string email;
	Endereco endereco;
	std::string tel;
public:
	Pessoa(std::string nome, std::string cpf, std::string email, Endereco endereco, std::string tel);
	Pessoa();
	virtual ~Pessoa();

	Endereco getEndereco();
	std::string getNome();
	std::string getCpf();
	std::string getEmail();
	std::string getTel();
};

#endif /* PESSOA_H_ */
