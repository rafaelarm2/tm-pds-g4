#ifndef PRODUTO_H_
#define PRODUTO_H_

#include <string>

using namespace std;

class Produto {
private:
	int id;
	std::string nome;
	double preco;
	std::string marca;
	int estoque;
public:
	Produto(std::string nome, double preco, std::string marca, int estoque);
	Produto(int id, std::string nome, double preco, std::string marca, int estoque);
	Produto(std::string nome, double preco, std::string marca);
	Produto();
	virtual ~Produto();

	//gets
	int getID();
	std::string getNome();
	double getPreco();
	std::string getMarca();
	int getEstoque();

	//sets
	void setID(int id_);
	void setNome(std::string nome_);
	void setPreco(double preco_);
	void setMarca(std::string marca_);
	void setEstoque(int estoque_);

	void saidaProduto(int qtd);
	void entradaProduto(int qtd);
};

#endif /* PRODUTO_H_ */
