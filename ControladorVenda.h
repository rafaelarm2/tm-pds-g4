#ifndef CONTROLADORVENDA_H_
#define CONTROLADORVENDA_H_

#include "Venda.h"
#include "VendaEntrega.h"
#include <string>

using namespace std;

class ControladorVenda {
public:
	ControladorVenda();
	virtual ~ControladorVenda();

	void novaVenda(Venda v, int idcliente, int idfuncionario);
	void novaVendaEntrega(VendaEntrega ve, Endereco end, int idcliente, int idfuncionario);
	void buscarEntregasPendentes();
	void realizarEntrega();
	bool verificaEstoque(int idproduto, int qtd);
	void buscarVendasCliente();
	void relatorioVendas();
	void relatorioVendasEntregas();
	void relatorioVendasEntregas(int status);
	void entregar(int identrega, std::string dtentrega);
	bool idExiste(int id);


};

#endif /* CONTROLADORVENDA_H_ */
