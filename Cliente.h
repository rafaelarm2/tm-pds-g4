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
	Cliente(std::string nome, std::string cpf, std::string email, Endereco endereco, std::string tel,
			std::string dtcadastro, TipoCliente tipo);
	Cliente();
	virtual ~Cliente();
	int gerarId();

	Endereco getEndereco();
	std::string getNome();
	std::string getCpf();
	std::string getEmail();
	std::string getTel();

	std::string getDtcadastro();
	TipoCliente getTipo();


};

#endif /* CLIENTE_H_ */
