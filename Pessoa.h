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
};

#endif /* PESSOA_H_ */

