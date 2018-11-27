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
//gets
	Endereco getEndereco();
	std::string getNome();
	std::string getCpf();
	std::string getEmail();
	std::string getTel();

	int getID();
	std::string getDtcadastro();
	TipoCliente getTipo();

//sets
	void setEndereco(Endereco endereco_);
	void setNome(std::string nome_);
	void setCpf(std::string cpf_);
	void setEmail(std::string email_);
	void setTel(std::string tel_);

	void setID(int id_);
	void setDtcadastro(std::string dtcadastro_);
	void setTipo(TipoCliente tipo_);
};

#endif /* CLIENTE_H_ */
