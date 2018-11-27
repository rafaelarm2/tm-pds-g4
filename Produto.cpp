
#include "Produto.h"

Produto::Produto(std::string nome, double preco, std::string marca) {
	// TODO Auto-generated constructor stub
	this->nome = nome;
	this->preco = preco;
	this->marca = marca;
}

Produto::Produto(int id, std::string nome, double preco, std::string marca) {
	// TODO Auto-generated constructor stub
	this->nome = nome;
	this->preco = preco;
	this->marca = marca;
	this->id = id;
}

Produto::Produto(){ // @suppress("Class members should be properly initialized")

}

Produto::~Produto() {
	// TODO Auto-generated destructor stub
}

double Produto::getPreco() {
	return this->preco;
}

std::string Produto::getMarca() {
	return this->marca;
}

std::string Produto::getNome() {
	return this->nome;
}
