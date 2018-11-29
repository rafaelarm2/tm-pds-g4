

#include "ControladorFuncionario.h"
#include "Funcionario.h"
#include <string>
#include <string.h>
#include <cstring>
#include <list>
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>

ControladorFuncionario::ControladorFuncionario() {
	// TODO Auto-generated constructor stub

}

ControladorFuncionario::~ControladorFuncionario() {
	// TODO Auto-generated destructor stub
}

bool ControladorFuncionario::idExiste(int id) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	std::string str;
	std::stringstream ss;
	bool encontrou = 0;

	//TESTA A CONEXAO COM O BD
	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss << "SELECT * FROM tbfuncionario WHERE idfuncionario = " << id;
		str = ss.str();
		//PREPARA A QUERY E EXECUTA
		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}
		//CHECA SE ALGUM RESULTADO SERÁ OBTIDO
		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			encontrou = 1;
		}

	} else {
		cout << "Failed to open db\n";
	}
	//FINALIZA A CONEXAO
	sqlite3_finalize(stmt);
	sqlite3_close(db);

	return (encontrou);
}

void ControladorFuncionario::inserirFuncionario(Funcionario f) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss1, ss2, ss3;
	int rc;
	//INICIA E TESTA A CONEXAO COM O BD
	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss1 << "INSERT INTO tbendereco(logradouro, bairro, cep, num, comp, cidade) VALUES ('"
				<< f.getEndereco().getLogradouro() << "','" << f.getEndereco().getBairro() << "','"
				<< f.getEndereco().getCep() <<"'," << f.getEndereco().getNum() << ", '"
				<< f.getEndereco().getComp() << "','" << f.getEndereco().getCidade() << "')";

		str = ss1.str();
		//PREPARA E EXECUTA A QUERY PARA INSERIR O ENDERECO
		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
		//RESETA O STATEMENT
		sqlite3_reset(stmt);

		ss2 << "SELECT idendereco FROM tbendereco WHERE idendereco = (SELECT MAX(idendereco) FROM tbendereco)";
		str = ss2.str();

		//PREPARA E EXECUTA OUTRA QUERY PARA VERIFICAR O ID DO ENDERECO INSERIDO
		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}
		sqlite3_step(stmt);
		int idendereco = sqlite3_column_int(stmt, 0);
		sqlite3_reset(stmt);

		//PREPARA E EXECUTA OUTRA QUERY PARA INSERIR O CLIENTE
		ss3 << "INSERT INTO tbfuncionario(nmfuncionario, cpf, email, tel, dtadmissao, idendereco) VALUES('"
				<< f.getNome() << "','" << f.getCpf() << "','" << f.getEmail() << "','" << f.getTel() << "','"
				<< f.getDtadmissao() << "'," << idendereco << ")";
		str = ss3.str();

		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
	} else {
		cout << "Failed to open db\n";
	}
	//FECHA A CONEXAO
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void ControladorFuncionario::listarFuncionario() {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	//TESTA A CONEXAO DO BANCO DE DADOS
	if (sqlite3_open("db", &db) == SQLITE_OK) {

		std::list<Funcionario> funcionarios;
		//MONTA A QUERY PARA PEGAR TODOS OS CLIENTES DA TABELA
		rc = sqlite3_prepare_v2(db, "SELECT idfuncionario, nmfuncionario, cpf, email, tel, dtadmissao, logradouro, bairro, cep, num, comp, cidade FROM tbfuncionario, tbendereco WHERE tbfuncionario.idendereco = tbendereco.idendereco",-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}
		//PARA CADA LINHA DA TABELA DA CONSULTA SALVA OS RESULTADOS NA VARIAVEL E EXIBE
		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			int idfuncionario = sqlite3_column_int(stmt, 0);
			const char* nmfuncionario = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			const char* cpf = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
			const char* email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
			const char* tel = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
			const char* dtadmissao = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
			const char* logradouro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
			const char* bairro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
			const char* cep = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
			int num = sqlite3_column_int(stmt, 9);
			const char* comp = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10));
			const char* cidade = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 11));

			std::cout << idfuncionario << " " << nmfuncionario << " " << cpf << " " << email << " " << tel << " "
					<< dtadmissao << " " << logradouro << " " << bairro << " " << cep << " "
					<< num << " " << comp << " " << cidade << endl;
//			Endereco *end = new Endereco();
//			funcionarios.push_back(Funcionario(idfuncionario, nmfuncionario, cpf, marca));
		}

	} else {
		cout << "Failed to open db\n";
	}
	//FECHA A CONEXAO
	sqlite3_finalize(stmt);
	sqlite3_close(db);

}

Funcionario ControladorFuncionario::buscarFuncionario(int id) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	std::string str;
	std::stringstream ss;

	Endereco *end;
	Funcionario *f;
	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss << "SELECT idfuncionario, nmfuncionario, cpf, email, tel, dtadmissao, logradouro, bairro, cep, num, comp, cidade FROM tbfuncionario, tbendereco WHERE tbfuncionario.idendereco = tbendereco.idendereco and idfuncionario = " << id;
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			int idfuncionario = sqlite3_column_int(stmt, 0);
			const char* nmfuncionario = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			const char* cpf = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
			const char* email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
			const char* tel = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
			const char* dtadmissao = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
			const char* logradouro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
			const char* bairro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
			const char* cep = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
			int num = sqlite3_column_int(stmt, 9);
			const char* comp = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10));
			const char* cidade = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 11));

			std::cout << idfuncionario << " " << nmfuncionario << " " << cpf << " " << email << " " << tel << " "
					<< dtadmissao << " " << logradouro << " " << bairro << " " << cep << " "
					<< num << " " << comp << " " << cidade << endl;


			end = new Endereco(logradouro, bairro, cep, num, comp, cidade);
			f = new Funcionario(idfuncionario, nmfuncionario, cpf, email, *end, tel, dtadmissao);

		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

	return (*f);
}



void ControladorFuncionario::removerFuncionario(int id) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	std::string str;
	std::stringstream ss;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss << "DELETE FROM tbfuncionario WHERE idfuncionario = " << id;
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}


void ControladorFuncionario::alterarFuncionario(int id, Endereco end) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss1, ss2;
	int rc;
	int idendereco = 0;
	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss1 << "SELECT idendereco FROM tbfuncionario WHERE idfuncionario = " << id;
		str = ss1.str();

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		sqlite3_step(stmt);
		idendereco = sqlite3_column_int(stmt, 0);
		sqlite3_reset(stmt);

		ss2 << "UPDATE tbendereco SET logradouro='" << end.getLogradouro() << "', bairro='"
				<< end.getBairro() << "', cep = '" << end.getCep() <<"', num = " << end.getNum() << ", comp = '"
				<< end.getComp() <<"', cidade= '" << end.getCidade() << "' WHERE idendereco=" << idendereco;

		str = ss2.str();

		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

