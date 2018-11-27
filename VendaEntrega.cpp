#include "VendaEntrega.h"

VendaEntrega::VendaEntrega(std::string dtcompra, std::list<Item> itens, Cliente cliente, Funcionario funcionario,
		int desconto, Endereco endereco, std::string dtentrega, double frete, StatusEntrega status):
		Venda(dtcompra, itens, cliente, funcionario, desconto) {
	// TODO Auto-generated constructor stub
	this->endereco = endereco;
	this->dtentrega = dtentrega;
	this->frete = frete;
	this->status = status;
	this->vlfinalcomfrete = this->getVlfinal() + frete;

}

VendaEntrega::~VendaEntrega() {
	// TODO Auto-generated destructor stub
}


void VendaEntrega::tenhofrete() {
	std::cout << "Tenho frete" << endl;

}


//gets
int VendaEntrega::getID(){
	return this->id;
}

std::string VendaEntrega::getDtcompra(){
	return this->dtcompra;
}

std::list<Item> VendaEntrega::getItens(){
	return this->itens;
}

Cliente VendaEntrega::getCliente(){
	return this->cliente;
}

Funcionario VendaEntrega::getFuncionario(){
	return this->funcionario;
}

double VendaEntrega::getVlliquido(){
	return this->vlliquido;
}

int VendaEntrega::getDesconto(){
	return this->desconto;
}

double VendaEntrega::getVlfinal() {
	return this->vlfinal;
}


Endereco VendaEntrega::getEndereco(){
	return this->endereco;
}

std::string VendaEntrega::getDtentrega(){
	return this->dtentrega;
}

StatusEntrega VendaEntrega::getStatus(){
	return this->status;
}

double VendaEntrega::getFrete(){
	return this->frete;
}

double VendaEntrega::getVlfinalcomfrete(){
	return this->vlfinalcomfrete;
}



//sets
void VendaEntrega::setDtcompra(std::string dtcompra_){
	this->dtcompra = dtcompra_;
}

void VendaEntrega::setItens(std::list<Item> itens_){
	this->itens = itens_;
}

void VendaEntrega::setCliente(Cliente cliente_){
	this->cliente = cliente_;
}

void VendaEntrega::setFuncionario(Funcionario funcionario_){
	this->funcionario = funcionario_;
}

void VendaEntrega::setVlliquido(double vlliquido_){
	this->vlliquido = vlliquido_;
}

void VendaEntrega::setDesconto(int desconto_){
	this->desconto = desconto_;
}

void VendaEntrega::setVlfinal(double vlfinal_){
	this->vlfinal = vlfinal_;
}


void VendaEntrega::setEndereco(Endereco endereco_){
	this->endereco = endereco_;
}

void VendaEntrega::setDtentrega(std::string dtentrega_){
	this->dtentrega = dtentrega_;
}

void VendaEntrega::setStatus(StatusEntrega status_){
	this->status = status_;
}

void VendaEntrega::setFrete(double frete_){
	this->frete = frete_;
}