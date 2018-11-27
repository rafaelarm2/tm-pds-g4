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

void ControladorProduto::inserirProduto(Produto p) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss;
	int rc;

	if (sqlite3_open("db", &db) == SQLITE_OK) {

		ss << "INSERT INTO tbproduto(nmproduto, preco, marca) VALUES('" << p.getNome() << "'," << p.getPreco() << ",'" << p.getMarca() <<"')";
		str = ss.str();

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
		rc = sqlite3_prepare_v2(db, "SELECT idproduto, nmproduto, preco, marca FROM tbproduto",-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			int idproduto = sqlite3_column_int(stmt, 0);
			const char* nmproduto = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			double preco = sqlite3_column_double(stmt, 2);
			const char* marca = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
			// let's assume number can be NULL:

			std::cout << idproduto << " "<< nmproduto << " " << preco << " " << marca << endl;
			produtos.push_back(Produto(idproduto, nmproduto,preco, marca));
		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

}

void ControladorProduto::buscarProduto(int id) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	std::string str;
	std::stringstream ss;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss << "SELECT idproduto, nmproduto, preco, marca FROM tbproduto WHERE idproduto = " << id;
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			int idproduto = sqlite3_column_int(stmt, 0);
			const char* nmproduto = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			double preco = sqlite3_column_double(stmt, 2);
			const char* marca = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
			// let's assume number can be NULL:

			std::cout << idproduto << " "<< nmproduto << " " << preco << " " << marca << endl;
		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}


void ControladorProduto::removerProduto(int id) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	std::string str;
	std::stringstream ss;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
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
	int rc;

	if (sqlite3_open("db", &db) == SQLITE_OK) {

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


