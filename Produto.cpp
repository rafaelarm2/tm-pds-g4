/*
 * Produto.cpp
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#include "Produto.h"

Produto::Produto(std::string nome, double preco, std::string marca) {
	// TODO Auto-generated constructor stub
	this->nome = nome;
	this->preco = preco;
	this->marca = marca;
}

Produto::Produto(){ // @suppress("Class members should be properly initialized")

}

Produto::~Produto() {
	// TODO Auto-generated destructor stub
}

double Produto::getPreco() {
	return this->preco;
}
