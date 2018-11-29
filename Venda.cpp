#include <list>
#include <iostream>
#include "Venda.h"
#include "Item.h"
#include "Cliente.h"
#include "Funcionario.h"

using namespace std;


Venda::Venda(std::string dtcompra, std::list<Item> itens, Cliente cliente, Funcionario funcionario, int desconto) { // @suppress("Class members should be properly initialized")
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


void Venda::tenhofrete() {
	std::cout << "Não tenho frete" << endl;

}

//gets
int Venda::getID(){
	return this->id;
}

std::string Venda::getDtcompra(){
	return this->dtcompra;
}

std::list<Item> Venda::getItens(){
	return this->itens;
}

Cliente Venda::getCliente(){
	return this->cliente;
}

Funcionario Venda::getFuncionario(){
	return this->funcionario;
}

double Venda::getVlliquido(){
	return this->vlliquido;
}

int Venda::getDesconto(){
	return this->desconto;
}

double Venda::getVlfinal() {
	return this->vlfinal;
}


//sets
void Venda::setDtcompra(std::string dtcompra_){
	this->dtcompra = dtcompra_;
}

void Venda::setItens(std::list<Item> itens_){
	this->itens = itens_;
}

void Venda::setCliente(Cliente cliente_){
	this->cliente = cliente_;
}

void Venda::setFuncionario(Funcionario funcionario_){
	this->funcionario = funcionario_;
}

void Venda::setVlliquido(double vlliquido_){
	this->vlliquido = vlliquido_;
}

void Venda::setDesconto(int desconto_){
	this->desconto = desconto_;
}

void Venda::setVlfinal(double vlfinal_){
	this->vlfinal = vlfinal_;
}
