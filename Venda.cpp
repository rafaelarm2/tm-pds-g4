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


void Venda::tenhofrete() {
	std::cout << "Não tenho frete" << endl;

}


//gets
int getID(){
	return this->id;
}

std::string getDtcompra(){
	return this->dtcompra;
}

std::list<Item> getItens(){
	return this->itens;
}

Cliente getCliente(){
	return this->cliente;
}

Funcionario getFuncionario(){
	return this->funcionario;
}

double getVlliquido(){
	return this->vlliquido;
}

int getDesconto(){
	return this->desconto;
}

double Venda::getVlfinal() {
	return this->vlfinal;
}


//sets
void setDtcompra(std::string dtcompra_){
	this->dtcompra = dtcompra_;
}

void setItens(std::list<Item> itens_){
	this->itens = itens_;
}

void setCliente(Cliente cliente_){
	this->cliente = cliente_;
}

void setFuncionario(Funcionario funcionario_){
	this->funcionario = funcionario_;
}

void setVlliquido(double vlliquido_){
	this->vlliquido = vlliquido_;
}

void setDesconto(int desconto_){
	this->desconto = desconto_;
}

void setVlfinal(double vlfinal_){
	this->vlfinal = vlfinal_;
}