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

	double getVltotal();

};

#endif /* ITEM_H_ */
