
#ifndef CONTROLADORFUNCIONARIO_H_
#define CONTROLADORFUNCIONARIO_H_

#include "Funcionario.h"

class ControladorFuncionario {
public:
	ControladorFuncionario();
	virtual ~ControladorFuncionario();


	void inserirFuncionario(Funcionario f);
	void listarFuncionario();
	Funcionario buscarFuncionario(int id);
	void removerFuncionario(int id);
	void alterarFuncionario(int id, Endereco end);
	bool idExiste(int id);
};

#endif /* CONTROLADORFUNCIONARIO_H_ */
