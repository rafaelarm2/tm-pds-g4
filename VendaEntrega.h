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
			Endereco endereco, std::string dtentrega, double frete, StatusEntrega status);
	VendaEntrega();
	virtual ~VendaEntrega();

	double getVlfinal();
	double getVlfinalcomfrete();
	void tenhofrete();
};

#endif /* VENDAENTREGA_H_ */

