/*
 * ControladorVenda.cpp
 *
 *  Created on: 27 de nov de 2018
 *      Author: rafaelamoreira
 */

#include "ControladorVenda.h"
#include "Venda.h"
#include "VendaEntrega.h"
#include "Item.h"
#include <string>
#include <string.h>
#include <cstring>

#include <list>


#include <sqlite3.h>

#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>

ControladorVenda::ControladorVenda() {
	// TODO Auto-generated constructor stub

}

ControladorVenda::~ControladorVenda() {
	// TODO Auto-generated destructor stub
}

void ControladorVenda::novaVendaEntrega(VendaEntrega ve, Endereco end, int idcliente, int idfuncionario) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss1, ss2, ss3, ss4, ss5;
	int idvenda = 0;


	if (sqlite3_open("db", &db) == SQLITE_OK) {
		int rc;
		//INSERINDO NOVO ENDERECO
		ss1 << "INSERT INTO tbendereco(logradouro, bairro, cep, num, comp, cidade) VALUES ('"
				<< end.getLogradouro() << "','" << end.getBairro() << "','" << end.getCep() <<"',"
				<< end.getNum() << ", '" << end.getComp() << "','" << end.getCidade() << "')";

		str = ss1.str();
		std::cout << str << endl;
		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
		sqlite3_reset(stmt);

		//PEGANDO O ID DO ENDERECO INSERIDO
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


		//CRIANDO UMA NOVA VENDA NO BANCO DE DADOS
		ss3 << "INSERT INTO tbvendaentrega(dtcompra, idcliente, idfuncionario, vlliquido, desconto, vlfinal," <<
				"idendereco, status, frete, vlfinalcomfrete) VALUES('"
				<< ve.getDtcompra() << "'," << idcliente << "," << idfuncionario <<"," << ve.getVlliquido() <<","
				<< ve.getDesconto() << "," << ve.getVlfinal() << "," << idendereco << ",'"
				<< ve.getStatus() << "'," << ve.getFrete() << ","
				<< ve.getVlfinalcomfrete() << ")";
		str = ss3.str();

		std::cout << str << endl;
		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
		sqlite3_reset(stmt);

		//PEGANDO O ULTIMO ID DE VENDA INSERIDO

		ss4 << "SELECT idvendaentrega FROM tbvendaentrega WHERE idvendaentrega = (SELECT MAX(idvendaentrega)"
				<< "FROM tbvendaentrega)";
		str = ss4.str();
		std::cout << str << endl;

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		sqlite3_step(stmt);
		int idvenda = sqlite3_column_int(stmt, 0);
		sqlite3_reset(stmt);

		//PEGANDO INSERINDO ITEM POR ITEM NO BANCO DE DADOS E ASSOCIANDO A VENDA

		std::list<Item> aux = ve.getItens();
		for (std::list<Item>::iterator it = aux.begin(); it != aux.end(); ++it) {

			ss5.str("");
			ss5 << "INSERT INTO tbvendaproduto(idvenda, idproduto, qtd) VALUES(" << idvenda << ","
					<< it->getProduto().getID() << "," << it->getQtd() <<")";
			str = ss5.str();

			std::cout << str << endl;
			rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
			sqlite3_step(stmt);
			sqlite3_reset(stmt);


		}


	} else {
		cout << "Failed to open db\n";
	}


	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void ControladorVenda::novaVenda(Venda v, int idcliente, int idfuncionario) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss1, ss2, ss3;
	int idvenda = 0;


	if (sqlite3_open("db", &db) == SQLITE_OK) {
		int rc;

		//CRIANDO UMA NOVA VENDA NO BANCO DE DADOS
		ss1 << "INSERT INTO tbvenda(dtcompra, idcliente, idfuncionario, vlliquido, desconto, vlfinal) VALUES('"
				<< v.getDtcompra() << "'," << idcliente << "," << idfuncionario <<"," << v.getVlliquido() <<","
				<< v.getDesconto() << "," << v.getVlfinal() <<")";
		str = ss1.str();

		std::cout << str << endl;
		rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
		sqlite3_step(stmt);
		sqlite3_reset(stmt);

		//PEGANDO O ULTIMO ID DE VENDA INSERIDO

		ss2 << "SELECT idvenda FROM tbvenda WHERE idvenda = (SELECT MAX(idvenda) FROM tbvenda)";
		str = ss2.str();
		std::cout << str << endl;

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		sqlite3_step(stmt);
		int idvenda = sqlite3_column_int(stmt, 0);
		sqlite3_reset(stmt);

		//PEGANDO INSERINDO ITEM POR ITEM NO BANCO DE DADOS E ASSOCIANDO A VENDA
		std::list<Item> aux = v.getItens();
		for (std::list<Item>::iterator it = aux.begin(); it != aux.end(); ++it) {

			ss3.str("");
			ss3 << "INSERT INTO tbvendaproduto(idvenda, idproduto, qtd) VALUES(" << idvenda << ","
					<< it->getProduto().getID() << "," << it->getQtd() <<")";
			str = ss3.str();

			std::cout << str << endl;
			rc = sqlite3_prepare_v2(db, str.c_str(), -1, &stmt, NULL);
			sqlite3_step(stmt);
			sqlite3_reset(stmt);


		}


	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}


bool ControladorVenda::verificaEstoque(int idproduto, int qtd) {
	bool suficiente;
	sqlite3 *db;
	sqlite3_stmt * stmt;
	int rc;
	std::string str;
	std::stringstream ss;

	int estoque = 0;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		ss << "SELECT estoque FROM tbproduto WHERE idproduto = " << idproduto;
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			estoque = sqlite3_column_int(stmt, 0);
			if (estoque >= qtd) {
				suficiente = 1;
			} else {
				suficiente = 0;
			}
		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);

	return suficiente;
}

void ControladorVenda::relatorioVendas() {
	sqlite3 *db;
	sqlite3_stmt * stmt;

	int rc;

	std::string str;
	std::stringstream ss;

	if (sqlite3_open("db", &db) == SQLITE_OK) {

		ss << "SELECT idvenda, nmcliente, dtcompra, vlfinal FROM tbvenda, tbcliente "
				<<"WHERE tbvenda.idcliente = tbcliente.idcliente";
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			int idvenda = sqlite3_column_int(stmt, 0);
			const char* nmcliente = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			const char* dtcompra = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
			double vlfinal = sqlite3_column_double(stmt, 3);


			std::cout << idvenda << " " << nmcliente << " " << dtcompra << " " << vlfinal << endl;
		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void ControladorVenda::relatorioVendasEntregas() {
	sqlite3 *db;
	sqlite3_stmt * stmt;

	int rc;

	std::string str;
	std::stringstream ss;

	if (sqlite3_open("db", &db) == SQLITE_OK) {

		ss << "SELECT idvendaentrega, nmcliente, dtcompra, vlfinal,status, logradouro, bairro, num, cep, cidade, comp"
				<< " FROM tbvendaentrega, tbcliente, tbendereco"
				<< " WHERE tbvendaentrega.idcliente = tbcliente.idcliente" <<
				" and tbvendaentrega.idendereco = tbendereco.idendereco";
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			int idvenda = sqlite3_column_int(stmt, 0);
			const char* nmcliente = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			const char* dtcompra = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
			double vlfinal = sqlite3_column_double(stmt, 3);
			int statusnum = sqlite3_column_int(stmt, 4);
			const char* logradouro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
			const char* bairro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
			const char* cep = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
			int num = sqlite3_column_int(stmt, 8);
			const char* comp = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));
			const char* cidade = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10));
			std::string status;
			if (statusnum == 0) {
				status = "PENDENTE";
			} else {
				status = "ENTREGUE";
			}

			std::cout << idvenda << " " << nmcliente << " " << dtcompra << " " << vlfinal << " " << status << " "
					<< logradouro << " " << bairro << " " << cep << " " << num << " " << comp << " "
					<< cidade << endl;
		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void ControladorVenda::relatorioVendasEntregas(int status) {
	sqlite3 *db;
	sqlite3_stmt * stmt;

	int rc;

	std::string str;
	std::stringstream ss;

	if (sqlite3_open("db", &db) == SQLITE_OK) {

		ss << "SELECT idvendaentrega, nmcliente, dtcompra, vlfinal,status, logradouro, bairro, num, cep, cidade, comp"
				<< " FROM tbvendaentrega, tbcliente, tbendereco"
				<< " WHERE tbvendaentrega.idcliente = tbcliente.idcliente" <<
				" and tbvendaentrega.idendereco = tbendereco.idendereco and status='" << status  << "'";
		str = ss.str();

		rc = sqlite3_prepare_v2(db, str.c_str(),-1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		}

		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			int idvenda = sqlite3_column_int(stmt, 0);
			const char* nmcliente = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			const char* dtcompra = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
			double vlfinal = sqlite3_column_double(stmt, 3);
			int statusnum = sqlite3_column_int(stmt, 4);
			const char* logradouro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
			const char* bairro = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
			const char* cep = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
			int num = sqlite3_column_int(stmt, 8);
			const char* comp = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));
			const char* cidade = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10));
			std::string status;
			if (statusnum == 0) {
				status = "PENDENTE";
			} else {
				status = "ENTREGUE";
			}

			std::cout << idvenda << " " << nmcliente << " " << dtcompra << " " << vlfinal << " " << status << " "
					<< logradouro << " " << bairro << " " << cep << " " << num << " " << comp << " "
					<< cidade << endl;
		}

	} else {
		cout << "Failed to open db\n";
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void ControladorVenda::entregar(int identrega, std::string dtentrega) {
	sqlite3 *db;
	sqlite3_stmt * stmt;
	std::string str;
	std::stringstream ss1, ss2;
	int estoque = 0;

	if (sqlite3_open("db", &db) == SQLITE_OK) {
		int rc;
		ss2 << "UPDATE tbvendaentrega SET status='"<< 1 <<"', dtentrega ='"
				<< dtentrega <<"'  WHERE idvendaentrega=" << identrega;
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
