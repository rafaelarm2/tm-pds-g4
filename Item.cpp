#include "Item.h"
#include <string>

using namespace std;

Item::Item(Produto produto, int qtd) {
	this->produto = produto;
	this->qtd = qtd;
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

