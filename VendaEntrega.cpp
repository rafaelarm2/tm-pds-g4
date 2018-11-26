#include "VendaEntrega.h"

VendaEntrega::VendaEntrega(std::string dtcompra, std::list<Item> itens, Cliente cliente, Funcionario funcionario,
		int desconto, Endereco endereco, std::string dtentrega, double frete, std::string observacoes):
		Venda(dtcompra, itens, cliente, funcionario, desconto) {
	// TODO Auto-generated constructor stub
	this->endereco = endereco;
	this->dtentrega = dtentrega;
	this->frete = frete;
	this->observacoes = observacoes;
	this->vlfinalcomfrete = this->getVlfinal() + frete;

}

VendaEntrega::~VendaEntrega() {
	// TODO Auto-generated destructor stub
}

double VendaEntrega::getVlfinalcomfrete() {
	return this->vlfinalcomfrete;
}

double VendaEntrega::getVlfinal() {
	return this->vlfinal;
}

void VendaEntrega::tenhofrete() {
	std::cout << "Tenho frete" << endl;

}

