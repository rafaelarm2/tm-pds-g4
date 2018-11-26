/*
 * Venda.cpp
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */


#include <list>
#include <iostream>
#include "Venda.h"
#include "Item.h"
#include "Cliente.h"
#include "Funcionario.h"

using namespace std;


Venda::Venda(std::string dtcompra, std::list<Item> itens, Cliente cliente, Funcionario funcionario, int desconto) {
	this->dtcompra = dtcompra;
	this->itens = itens;
	this->cliente = cliente;
	this->funcionario = funcionario;
	this->desconto = desconto;

	//percorre a lista de itens para fazer o somatório dos valores de cada um
	vlliquido = 0;
	for (std::list<Item>::iterator it = itens.begin(); it != itens.end(); ++it) {
		vlliquido = vlliquido + it->getVltotal();
	}

	//subtrai o valor pelo desconto (em porcentagem)
	vlfinal = vlliquido - (vlliquido * desconto / 100);

}

Venda::~Venda() {
	// TODO Auto-generated destructor stub
}

double Venda::getVlfinal() {
	return this->vlfinal;
}

void Venda::tenhofrete() {
	std::cout << "Não tenho frete" << endl;

}
