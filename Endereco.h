/*
 * Endereco.h
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#ifndef ENDERECO_H_
#define ENDERECO_H_

#include <string>
#include "Cidade.h"
#include "Endereco.h"

using namespace std;

enum Logradouro {
	Rua, Avenida, Alameda, Condominio, Rodovia, Vila, Viela
};

class Endereco {
private:
	static int id;
	Logradouro logradouro;
	std::string tipologradouro; //Enum
	std::string bairro;
	std::string cep;
	int num;
	std::string comp;
	Cidade cidade;
public:
	Endereco(Logradouro logradouro, std::string tipologradouro, std::string bairro, std::string cep, int num,
			std::string comp, Cidade cidade);
	Endereco();
	virtual ~Endereco();

	Cidade getCidade();
};

#endif /* ENDERECO_H_ */
