
#include "Cliente.h"
#include "Endereco.h"
#include "Produto.h"
#include "ControladorProduto.h"
#include "ControladorCliente.h"
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
#include <time.h>
#include <sstream>

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

void crud_cliente() {
		std::cout << "CRUD CLIENTE"<< endl;
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

		ControladorCliente *cc = new ControladorCliente();
		switch (item_menu) {
		case 1: {
			std::cout << "Nome: " << endl;
			std::string nome;
			std::cin.ignore();
			std::getline(std::cin, nome);
			std::cout << nome << endl;

			std::cout << "CPF: " << endl;
			std::string cpf;
			std::getline(std::cin, cpf);
			std::cout << cpf << endl;

			std::cout << "Email: " << endl;
			std::string email;
			std::getline(std::cin, email);
			std::cout << email << endl;

			std::cout << "Tel: " << endl;
			std::string tel;
			std::getline(std::cin, tel);
			std::cout << tel << endl;

			//DATA DE CADASTRO
			time_t timer;
			struct tm *horarioLocal;
			time(&timer); // Obtem informações de data e hora
			horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
			int dia = horarioLocal->tm_mday;
			int mes = horarioLocal->tm_mon + 1;
			int ano = horarioLocal->tm_year + 1900;
			std::stringstream ss;
			ss << dia << "/" << mes << "/"<< ano;
			std::string dtcadastro = ss.str();

			std::cout << "Logradouro: " << endl;
			std::string logradouro;
			std::cin.ignore();
			std::getline(std::cin, logradouro);
			std::cout << logradouro << endl;

			std::cout << "Bairro: " << endl;
			std::string bairro;
			std::getline(std::cin, bairro);
			std::cout << bairro << endl;

			std::cout << "Num: " << endl;
			std::string numstr;
			std::getline(std::cin, numstr);
			std::cout << numstr << endl;

			std::cout << "CEP: " << endl;
			std::string cep;
			std::getline(std::cin, cep);
			std::cout << cep << endl;

			std::cout << "Complemento: " << endl;
			std::string comp;
			std::getline(std::cin, comp);
			std::cout << comp << endl;

			std::cout << "Cidade: " << endl;
			std::string cidade;
			std::getline(std::cin, cidade);
			std::cout << cidade << endl;


			Endereco *end = new Endereco(logradouro, bairro, cep, stoi(numstr.c_str()), comp, cidade);
			Cliente *c = new Cliente(nome, cpf, email, *end, tel, dtcadastro, TipoCliente::BRONZE);

			cc->inserirCliente(*c);

		}break;

		case 2: {
			cc->listarCliente();

		}break;

		case 3: {
			int id;
			std::cout << "Insira um id para busca: ";
			scanf("%d", &id);
			cc->buscarCliente(id);
		}break;

		case 4: {
			cc->listarCliente();
			int id;
			std::cout << "\nInsira um id para remover: ";
			scanf("%d", &id);
			cc->removerCliente(id);
		} break;
		case 5: {
			cc->listarCliente();
			int id;
			std::cout << "\nInsira um id para alterar o endereço: ";
			scanf("%d", &id);

			std::cout << "Novo logradouro: " << endl;
			std::string logradouro;
			std::cin.ignore();
			std::getline(std::cin, logradouro);
			std::cout << logradouro << endl;

			std::cout << "Novo bairro: " << endl;
			std::string bairro;
			std::getline(std::cin, bairro);
			std::cout << bairro << endl;

			std::cout << "Novo num: " << endl;
			std::string numstr;
			std::getline(std::cin, numstr);
			std::cout << numstr << endl;

			std::cout << "Novo CEP: " << endl;
			std::string cep;
			std::getline(std::cin, cep);
			std::cout << cep << endl;

			std::cout << "Novo complemento: " << endl;
			std::string comp;
			std::getline(std::cin, comp);
			std::cout << comp << endl;

			std::cout << "Nova cidade: " << endl;
			std::string cidade;
			std::getline(std::cin, cidade);
			std::cout << cidade << endl;


			Endereco *end = new Endereco(logradouro, bairro, cep, stoi(numstr.c_str()), comp, cidade);
			cc->alterarCliente(id, *end);
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
			printf("\n\n\n");
			crud_cliente();
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

