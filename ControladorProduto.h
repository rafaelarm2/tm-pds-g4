

#ifndef CONTROLADORPRODUTO_H_
#define CONTROLADORPRODUTO_H_

#include "Produto.h"

class ControladorProduto {
public:
	ControladorProduto();
	virtual ~ControladorProduto();

	void inserirProduto(Produto p);
	void listarProduto();
	Produto buscarProduto(int id);
	void removerProduto(int id);
	void alterarProduto(int id, Produto p);
	bool idExiste(int id);
	void saidaProduto(int id, int estoque, int qtd);
	void entradaProduto(int id, int qtd);
};

#endif /* CONTROLADORPRODUTO_H_ */
