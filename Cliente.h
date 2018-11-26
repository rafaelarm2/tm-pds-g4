/*
 * Cliente.h
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Pessoa.h"
#include <string>

using namespace std;

enum TipoCliente {
	PRATA, BRONZE, OURO, DIAMANTE
};

class Cliente: public Pessoa {
protected:
	static int id;
	std::string dtcadastro;
	TipoCliente tipo;
public:
	Cliente(std::string nome, std::string cpf, std::string rg, std::string email, Endereco endereco, std::string tel,
			std::string dtcadastro, TipoCliente tipo);
	Cliente();
	virtual ~Cliente();

	Endereco getEndereco();


};

#endif /* CLIENTE_H_ */
