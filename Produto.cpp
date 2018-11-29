#include "Produto.h"

Produto::Produto(std::string nome, double preco, std::string marca, int estoque) { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub
	this->nome = nome;
	this->preco = preco;
	this->marca = marca;
	this->estoque = estoque;
}

Produto::Produto(std::string nome, double preco, std::string marca) { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub
	this->nome = nome;
	this->preco = preco;
	this->marca = marca;
}

Produto::Produto(int id, std::string nome, double preco, std::string marca, int estoque) {
	// TODO Auto-generated constructor stub
	this->nome = nome;
	this->preco = preco;
	this->marca = marca;
	this->id = id;
	this->estoque = estoque;
}

Produto::Produto(){ // @suppress("Class members should be properly initialized")

}

Produto::~Produto() {
	// TODO Auto-generated destructor stub
}

//gets
int Produto::getID(){
	return this->id;
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

int Produto::getEstoque(){
	return this->estoque;
}

//sets
void Produto::setID(int id_){
	this->id = id_;
}

void Produto::setNome(std::string nome_){
	this->nome = nome_;
}

void Produto::setPreco(double preco_){
	this->preco = preco_;
}

void Produto::setMarca(std::string marca_){
	this->marca = marca_;
}

void Produto::setEstoque(int estoque_){
	this->estoque = estoque_;
}

void Produto::saidaProduto(int qtd) {
	if (this->estoque - qtd >= 0) {
		this->estoque = this->estoque - qtd;
	}


}
