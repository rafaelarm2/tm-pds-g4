#ifndef CONTROLADORCLIENTE_H_
#define CONTROLADORCLIENTE_H_

#include "Cliente.h"

class ControladorCliente {
public:
	ControladorCliente();
	virtual ~ControladorCliente();

	void inserirCliente(Cliente c);
	void listarCliente();
	Cliente buscarCliente(int id);
	void removerCliente(int id);
	void alterarCliente(int id, Endereco end);
	bool idExiste(int id);
};

#endif /* CONTROLADORCLIENTE_H_ */
