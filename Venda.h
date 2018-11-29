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
	int id;
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
	void tenhofrete();


	double getVlfinal();
	int getID();
	std::string getDtcompra();
	std::list<Item> getItens();
	Cliente getCliente();
	Funcionario getFuncionario();
	double getVlliquido();
	int getDesconto();

	void setDtcompra(std::string dtcompra_);
	void setItens(std::list<Item> itens_);
	void setCliente(Cliente cliente_);
	void setFuncionario(Funcionario funcionario_);
	void setVlliquido(double vlliquido_);
	void setDesconto(int desconto_);
	void setVlfinal(double vlfinal_);
};

#endif /* VENDA_H_ */
