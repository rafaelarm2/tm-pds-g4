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

double Item::getVltotal() {
	return this->vltotal;
}
