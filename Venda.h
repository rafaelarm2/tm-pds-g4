/*
 * Venda.h
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#ifndef VENDA_H_
#define VENDA_H_

#include "Item.h"
#include "Cliente.h"
#include "Pessoa.h"
#include "Funcionario.h"
#include <iostream>
#include <list>

using namespace std;

class Venda {
protected:
	static int id;
	std::string dtcompra;
	std::list<Item> itens;
	Cliente cliente;
	Funcionario funcionario;
	double vlliquido;
	int desconto;
	double vlfinal;

public:
	Venda(std::string dtcompra, std::list<Item> itens, Cliente cliente, Funcionario funcionario, int desconto);
	virtual ~Venda();

	double getVlfinal();
	void tenhofrete();
};

#endif /* VENDA_H_ */
