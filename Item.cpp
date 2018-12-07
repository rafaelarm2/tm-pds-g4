#include "Item.h"
#include <string>
#include "excecoes.h"

using namespace std;

Item::Item(Produto produto, int qtd) { // @suppress("Class members should be properly initialized")
	this->produto = produto;
	
	if(qtd > 0)
		this->qtd = qtd;
	else 
		throw InsercaoDeDadosIncorreta();
	

	this->vltotal = produto.getPreco() * qtd;
}

Item::~Item() {
	// TODO Auto-generated destructor stub
}

//gets
int Item::getID(){
	return this->id;
}

Produto Item::getProduto(){
	return this->produto;
}

int Item::getQtd(){
	return this->qtd;
}

double Item::getVltotal() {
	return this->vltotal;
}


//sets
void Item::setID(int id_){
	this->id = id_;
}

void Item::setProduto(Produto produto_){
	this->produto = produto_;
}

void Item::setQtd(int qtd_){
	this->qtd = qtd_;
}

void Item::setVltotal(double vltotal_){
	this->vltotal = vltotal_;
}
