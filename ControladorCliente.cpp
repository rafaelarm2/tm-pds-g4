/*
 * ControladorCliente.cpp
 *
 *  Created on: 26 de nov de 2018
 *      Author: rafaelamoreira
 */

#include "ControladorCliente.h"
#include "Cliente.h"
#include <string>
#include <string.h>
#include <cstring>
#include <list>
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>

ControladorCliente::ControladorCliente() {
	// TODO Auto-generated constructor stub

}

ControladorCliente::~ControladorCliente() {
	// TODO Auto-generated destructor stub
}

bool ControladorCliente::idExiste(int id) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	std::string str;
	std::stringstream ss;
	bool encontrou = 0;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss << "SELECT * FROM tbcliente WHERE idcliente = " << id;
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			encontrou = 1;
		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

	return (encontrou);
}

void ControladorCliente::inserirCliente(Cliente c) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss1, ss2, ss3;
	int rc;
	int idendereco = 0;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		std::cout << str << endl;
		ss1 << "INSERT INTO tbendereco(logradouro, bairro, cep, num, comp, cidade) VALUES ('"
				<< c.getEndereco().getLogradouro() << "','" << c.getEndereco().getBairro() << "','"
				<< c.getEndereco().getCep() <<"'," << c.getEndereco().getNum() << ", '"
				<< c.getEndereco().getComp() << "','" << c.getEndereco().getCidade() << "')";

		str = ss1.str();
		std::cout << str << endl;
		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
		sqlite3_reset(stmt);

		ss2 << "SELECT idendereco FROM tbendereco WHERE idendereco = (SELECT MAX(idendereco) FROM tbendereco)";
		str = ss2.str();
		std::cout << str << endl;

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}
		sqlite3_step(stmt);
		int idendereco = sqlite3_column_int(stmt, 0);
		sqlite3_reset(stmt);

		ss3 << "INSERT INTO tbcliente(nmcliente, cpf, email, tel, dtcadastro, tipo, idendereco) VALUES('"
				<< c.getNome() << "','" << c.getCpf() << "','" << c.getEmail() << "','" << c.getTel() << "','"
				<< c.getDtcadastro() <<"','" << c.getTipo() <<"'," << idendereco << ")";
		str = ss3.str();
		std::cout << str << endl;
		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void ControladorCliente::listarCliente() {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	if (sqlite3_open("db", &db) == SQLITE_OK) {

		std::list<Cliente> clientes;
		rc = sqlite3_prepare_v2(db, "SELECT idcliente, nmcliente, cpf, email, tel, dtcadastro, tipo, logradouro, bairro, cep, num, comp, cidade FROM tbcliente, tbendereco WHERE tbcliente.idendereco = tbendereco.idendereco",-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			int idcliente = sqlite3_column_int(stmt, 0);
			const char* nmcliente = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			const char* cpf = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
			const char* email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
			const char* tel = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
			const char* dtcadastro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
			const char* tipo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
			const char* logradouro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
			const char* bairro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
			const char* cep = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));
			int num = sqlite3_column_int(stmt, 10);
			const char* comp = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 11));
			const char* cidade = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 12));

			std::cout << idcliente << " " << nmcliente << " " << cpf << " " << email << " " << tel << " "
					<< dtcadastro << " " << tipo << " " << logradouro << " " << bairro << " " << cep << " "
					<< num << " " << comp << " " << cidade << endl;
//			Endereco *end = new Endereco();
//			clientes.push_back(Cliente(idcliente, nmcliente, cpf, marca));
		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

}

Cliente ControladorCliente::buscarCliente(int id) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	std::string str;
	std::stringstream ss;

	Endereco *end;
	Cliente *c;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss << "SELECT idcliente, nmcliente, cpf, email, tel, dtcadastro, tipo, logradouro, bairro, cep, num, comp, cidade FROM tbcliente, tbendereco WHERE tbcliente.idendereco = tbendereco.idendereco and idcliente = " << id;
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			int idcliente = sqlite3_column_int(stmt, 0);
			const char* nmcliente = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			const char* cpf = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
			const char* email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
			const char* tel = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
			const char* dtcadastro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
			const char* tipo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
			const char* logradouro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
			const char* bairro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
			const char* cep = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));
			int num = sqlite3_column_int(stmt, 10);
			const char* comp = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 11));
			const char* cidade = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 12));

			std::cout << idcliente << " " << nmcliente << " " << cpf << " " << email << " " << tel << " "
					<< dtcadastro << " " << tipo << " " << logradouro << " " << bairro << " " << cep << " "
					<< num << " " << comp << " " << cidade << endl;
			TipoCliente tc;
			if (tipo == "1") tc = TipoCliente::BRONZE;
			if (tipo == "2") tc = TipoCliente::PRATA;
			if (tipo == "3") tc = TipoCliente::OURO;
			if (tipo == "4") tc = TipoCliente::DIAMANTE;

			end = new Endereco(logradouro, bairro, cep, num, comp, cidade);
			c = new Cliente(idcliente, nmcliente, cpf, email, *end, tel, dtcadastro, tc);

		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

	return (*c);
}



void ControladorCliente::removerCliente(int id) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	std::string str;
	std::stringstream ss;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss << "DELETE FROM tbcliente WHERE idcliente = " << id;
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}


void ControladorCliente::alterarCliente(int id, Endereco end) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss1, ss2;
	int rc;
	int idendereco = 0;
	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss1 << "SELECT idendereco FROM tbcliente WHERE idcliente = " << id;
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
