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
public:
	Produto(std::string nome, double preco, std::string marca);
	Produto(int id, std::string nome, double preco, std::string marca);
	Produto();
	virtual ~Produto();

//gets
	int getID();
	std::string getNome();
	double getPreco();
	std::string getMarca();

//sets
	void setID(int id_);
	void setNome(std::string nome_);
	void setPreco(double preco_);
	void setMarca(std::string marca_);	
};

#endif /* PRODUTO_H_ */

