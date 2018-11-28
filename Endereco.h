/*
 * Endereco.h
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#ifndef ENDERECO_H_
#define ENDERECO_H_

#include <string>
#include "Endereco.h"

using namespace std;

class Endereco {
private:
	int id;
	std::string logradouro;
	std::string bairro;
	std::string cep;
	int num;
	std::string comp;
	std::string cidade;
public:
	Endereco(std::string logradouro, std::string bairro, std::string cep, int num,
			std::string comp, std::string cidade);
	Endereco();
	virtual ~Endereco();

	std::string getLogradouro();
	std::string getBairro();
	std::string getCep();
	int getNum();
	std::string getComp();
	std::string getCidade();
};

#endif /* ENDERECO_H_ */
