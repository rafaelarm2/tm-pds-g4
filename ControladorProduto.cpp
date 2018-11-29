/*
 * ControladorProduto.cpp
 *
 *  Created on: 26 de nov de 2018
 *      Author: rafaelamoreira
 */

#include "ControladorProduto.h"
#include "Produto.h"

#include <string>
#include <string.h>
#include <cstring>

#include <list>


#include <sqlite3.h>

#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>

using namespace std;

ControladorProduto::ControladorProduto() {


}

ControladorProduto::~ControladorProduto() {
	// TODO Auto-generated destructor stub
}


bool ControladorProduto::idExiste(int id) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	std::string str;
	std::stringstream ss;
	bool encontrou = 0;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss << "SELECT * FROM tbproduto WHERE idproduto = " << id;
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

void ControladorProduto::inserirProduto(Produto p) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss;


	if (sqlite3_open("db", &db) == SQLITE_OK) {
		int rc;
		ss << "INSERT INTO tbproduto(nmproduto, preco, marca, estoque) VALUES('" << p.getNome() << "'," << p.getPreco() << ",'" << p.getMarca() <<"'," << p.getEstoque() <<")";
		str = ss.str();
		std::cout << str <<endl;
		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void ControladorProduto::listarProduto() {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	if (sqlite3_open("db", &db) == SQLITE_OK) {

		std::list<Produto> produtos;
		rc = sqlite3_prepare_v2(db, "SELECT idproduto, nmproduto, preco, marca, estoque FROM tbproduto WHERE estoque > 0",-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			int idproduto = sqlite3_column_int(stmt, 0);
			const char* nmproduto = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			double preco = sqlite3_column_double(stmt, 2);
			const char* marca = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
			int estoque = sqlite3_column_int(stmt, 4);
			// let's assume number can be NULL:

			std::cout << idproduto << " "<< nmproduto << " " << preco << " " << marca << " " << estoque << endl;
			produtos.push_back(Produto(idproduto, nmproduto,preco, marca, estoque));
		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

}

Produto ControladorProduto::buscarProduto(int id) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	std::string str;
	std::stringstream ss;
	Produto *p;

	int idproduto = 0;
	const char* nmproduto;
	double preco = 0.0;
	const char* marca;
	int estoque = 0;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss << "SELECT idproduto, nmproduto, preco, marca, estoque FROM tbproduto WHERE idproduto = " << id;
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			idproduto = sqlite3_column_int(stmt, 0);
			nmproduto = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			preco = sqlite3_column_double(stmt, 2);
			marca = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
			estoque = sqlite3_column_int(stmt, 4);
			// let's assume number can be NULL:

			std::cout << idproduto << " "<< nmproduto << " " << preco << " " << marca << "  " << estoque << endl;
			p = new Produto(idproduto, nmproduto, preco, marca, estoque);
		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return (*p);
}


void ControladorProduto::removerProduto(int id) {
	sqlite3 *db;
	sqlite3_stmt * stmt;

	std::string str;
	std::stringstream ss;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		int rc;
		ss << "DELETE FROM tbproduto WHERE idproduto = " << id;
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}


void ControladorProduto::alterarProduto(int id, Produto p) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		int rc;
		ss << "UPDATE tbproduto SET nmproduto='" << p.getNome() << "', preco=" << p.getPreco() << ", marca='" << p.getMarca() <<"' WHERE idproduto=" << id;
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void ControladorProduto::saidaProduto(int id, int estoque, int qtd) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		int rc;
		ss << "UPDATE tbproduto SET estoque="<< estoque - qtd <<" WHERE idproduto=" << id;
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void ControladorProduto::entradaProduto(int id, int qtd) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss1, ss2;
	int estoque = 0;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		int rc;

		ss1 << "SELECT estoque FROM tbproduto WHERE idproduto = " << id;
		str = ss1.str();

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			estoque = sqlite3_column_int(stmt, 0);
		}
		sqlite3_reset(stmt);


		estoque = estoque + qtd;
		ss2 << "UPDATE tbproduto SET estoque="<< estoque <<" WHERE idproduto=" << id;
		str = ss2.str();

		std::cout << str << endl;

		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}


