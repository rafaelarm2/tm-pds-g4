/*
 * main.cpp
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#include "Cliente.h"
#include "Cidade.h"
#include "Endereco.h"
#include "Produto.h"
#include "Venda.h"
#include "VendaEntrega.h"
#include "Item.h"
#include "Funcionario.h"
#include "Pessoa.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

int main() {
	Cidade *cid = new Cidade();

	std::cout << cid->getNome() << endl;

	Endereco *end = new Endereco(Logradouro::Rua, std::string("Guarapari"), std::string("Giovanini"), std::string("35170102"), 471,std::string(""), *cid);

	std::cout << end->getCidade().getNome() << endl;

	Cliente *cli = new Cliente(std::string("Rafaela"),std::string("11550565664"), std::string("MG17033716"), std::string("moreiramrafaela@gmail.com"), *end, std::string("31988959190"), std::string("19/11/2018"), TipoCliente::OURO);

	std::cout << cli->getEndereco().getCidade().getNome() << endl;

	Produto *prod1 = new Produto(std::string("Condicionador"), 39.90, std::string("Viverdí"));
	Produto *prod2 = new Produto(std::string("Shampoo"), 36.90, std::string("Viverdí"));
	Produto *prod3 = new Produto(std::string("Máscara"), 42.00, std::string("Viverdí"));

	std::cout << prod1->getPreco() << endl;
	std::cout << prod2->getPreco() << endl;
	std::cout << prod3->getPreco() << endl;


	Item *it1 = new Item(*prod1, 3);
	Item *it2 = new Item(*prod2, 2);
	Item *it3 = new Item(*prod3, 1);

	std::cout << it1->getVltotal() << endl;
	std::cout << it2->getVltotal() << endl;
	std::cout << it3->getVltotal() << endl;

	std::list<Item> itens;
	itens.push_back(*it1);
	itens.push_back(*it2);
	itens.push_back(*it3);

	std::cout << "           " << endl;


	Funcionario *func = new Funcionario();

	Venda *v = new Venda(std::string("19/11/2018"), itens, *cli, *func, 0);

	std::cout << v->getVlfinal() << endl;

	VendaEntrega *ve = new VendaEntrega(std::string("19/11/2018"), itens, *cli, *func, 0, *end, std::string("29/11/2018"), 20.50, std::string("Embalagem A"));

	std::cout << ve->getVlfinalcomfrete() << endl;

	v->tenhofrete();
	ve->tenhofrete();

	return 0;
}



