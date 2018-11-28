/*
 * VendaEntrega.h
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#ifndef VENDAENTREGA_H_
#define VENDAENTREGA_H_

#include "Pessoa.h"
#include "Endereco.h"
#include "Venda.h"
#include <string>

using namespace std;

enum StatusEntrega {
	PENDENTE, ATRASADA, ENTREGUE
};

class VendaEntrega: public Venda {
private:
	Endereco endereco;
	std::string dtentrega;
	StatusEntrega status;
	double frete;
	double vlfinalcomfrete;
public:
	VendaEntrega(std::string dtcompra, std::list<Item> itens, Cliente cliente, Funcionario funcionario, int desconto,
			Endereco endereco, double frete, StatusEntrega status);
	VendaEntrega();
	virtual ~VendaEntrega();

	//gets
		int getID();
		std::string getDtcompra();
		std::list<Item> getItens();
		Cliente getCliente();
		Funcionario getFuncionario();
		double getVlliquido();
		int getDesconto();
		double getVlfinal();

		Endereco getEndereco();
		std::string getDtentrega();
		StatusEntrega getStatus();
		double getFrete();
		double getVlfinalcomfrete();

	//sets
		void setDtcompra(std::string dtcompra_);
		void setItens(std::list<Item> itens_);
		void setCliente(Cliente cliente_);
		void setFuncionario(Funcionario funcionario_);
		void setVlliquido(double vlliquido_);
		void setDesconto(int desconto_);
		void setVlfinal(double vlfinal_);

		void setEndereco(Endereco endereco_);
		void setDtentrega(std::string dtentrega_);
		void setStatus(StatusEntrega status_);
		void setFrete(double frete_);

};

#endif /* VENDAENTREGA_H_ */
