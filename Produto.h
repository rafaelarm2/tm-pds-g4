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

	double getPreco();
	std::string getNome();
	std::string getMarca();
};

#endif /* PRODUTO_H_ */

