/*
 * main.cpp
 *
 *  Created on: 25 de nov de 2018
 */

#include "Cliente.h"
#include "Endereco.h"
#include "Produto.h"
#include "ControladorProduto.h"
#include "Venda.h"
#include "VendaEntrega.h"
#include "Item.h"
#include "Funcionario.h"
#include "Pessoa.h"
#include <string>
#include <string.h>
#include <list>
#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <curses.h>

#define MAX 20

using namespace std;

void listarmenu() {
	std::cout << "Menu"<< endl;
	std::cout << "1. Venda" << endl;
	std::cout << "2. CRUD Produto" << endl;
	std::cout << "3. CRUD Cliente" << endl;
	std::cout << "4. CRUD Funcionário\n" << endl;
}

void venda() {

}

void crud_produto() {
		std::cout << "CRUD PRODUTO"<< endl;
		std::cout << "1. Inserir" << endl;
		std::cout << "2. Listar" << endl;
		std::cout << "3. Buscar" << endl;
		std::cout << "4. Remover" << endl;
		std::cout << "5. Alterar" << endl;
		std::cout << "6. Voltar" << endl;

		int item_menu;
		std::cout << "Escolha uma seção: ";
		scanf("%d", &item_menu);


		fflush(stdin);

		ControladorProduto *cp = new ControladorProduto();
		switch (item_menu) {
		case 1: {
			std::cout << "Nome: " << endl;
			std::string nome;
			std::cin.ignore();
			std::getline(std::cin, nome);
			std::cout << nome << endl;

			std::cout << "Marca: " << endl;
			std::string marca;
			std::getline(std::cin, marca);
			std::cout << marca << endl;

			std::cout << "Preco: " << endl;
			std::string preco;
			std::getline(std::cin, preco);
			std::cout << preco << endl;

			Produto *p = new Produto(nome, atof(preco.c_str()), marca);

			cp->inserirProduto(*p);

		}break;

		case 2: {
			cp->listarProduto();

		}break;

		case 3: {
			int id;
			std::cout << "Insira um id para busca: ";
			scanf("%d", &id);
			cp->buscarProduto(id);
		}break;

		case 4: {
			cp->listarProduto();
			int id;
			std::cout << "\nInsira um id para remover: ";
			scanf("%d", &id);
			cp->removerProduto(id);
		} break;
		case 5: {
			cp->listarProduto();
			int id;
			std::cout << "\nInsira um id para alterar: ";
			scanf("%d", &id);

			std::cout << "Novo nome: " << endl;
			std::string nome;
			std::cin.ignore();
			std::getline(std::cin, nome);
			std::cout << nome << endl;

			std::cout << "Nova marca: " << endl;
			std::string marca;
			std::getline(std::cin, marca);
			std::cout << marca << endl;

			std::cout << "Novo preco: " << endl;
			std::string preco;
			std::getline(std::cin, preco);
			std::cout << preco << endl;

			Produto *p = new Produto(nome, atof(preco.c_str()), marca);

			cp->alterarProduto(id, *p);
		}break;
		case 6: {
			printf("\n\n\n");
			return;
		}break;
		}
}

int main() {
	while(1){
		int item_menu;
		listarmenu();

		std::cout << "Selecionar função: ";
		scanf("%d", &item_menu);
		switch (item_menu) {
		case 1: {
			// VENDA

			printf("\n\n\n");

			venda();
		}break;
		case 2: {
			//CRUD DE PRODUTO
			printf("\n\n\n");
			crud_produto();
		}break;
		case 3: {

		}break;
		case 4: {

		}break;
		default: {

		}
		}

	}
	////////////////////// CRUD DE PRODUTO ///////////////////////////////



	return 0;
}


