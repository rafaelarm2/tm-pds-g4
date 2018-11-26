/*
 * Produto.h
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#ifndef PRODUTO_H_
#define PRODUTO_H_

#include <string>

using namespace std;

class Produto {
private:
	static int id;
	std::string nome;
	double preco;
	std::string marca;
public:
	Produto(std::string nome, double preco, std::string marca);
	Produto();
	virtual ~Produto();

	double getPreco();
};

#endif /* PRODUTO_H_ */
