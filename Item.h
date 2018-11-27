#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include "Produto.h"

using namespace std;

class Item {
private:
	static int id;
	Produto produto;
	int qtd;
	double vltotal;
public:
	Item(Produto produto, int qtd);
	virtual ~Item();

//gets
	int getID();
	Produto getProduto();
	int getQtd();
	double getVltotal();

//sets
	void setID(int id_);
	void setProduto(Produto produto_);
	void setQtd(int qtd_);
	void setVltotal(double vltotal_);

};

#endif /* ITEM_H_ */
