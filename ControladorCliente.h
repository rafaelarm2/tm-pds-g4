/*
 * ControladorCliente.h
 *
 *  Created on: 26 de nov de 2018
 *      Author: rafaelamoreira
 */

#ifndef CONTROLADORCLIENTE_H_
#define CONTROLADORCLIENTE_H_

#include "Cliente.h"

class ControladorCliente {
public:
	ControladorCliente();
	virtual ~ControladorCliente();

	void inserirCliente(Cliente c);
	void listarCliente();
	void buscarCliente(int id);
	void removerCliente(int id);
	void alterarCliente(int id, Endereco end);
};

#endif /* CONTROLADORCLIENTE_H_ */