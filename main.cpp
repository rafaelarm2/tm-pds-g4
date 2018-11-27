
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

void crud_produto(ControladorVenda cv, ControladorCliente cc, ControladorFuncionario cf, ControladorProduto cp) {

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

			cp.inserirProduto(*p);

		}break;

		case 2: {
			cp.listarProduto();

		}break;

		case 3: {
			int id;
			std::cout << "Insira um id para busca: ";
			scanf("%d", &id);
			cp.buscarProduto(id);
		}break;

		case 4: {
			cp.listarProduto();
			int id;
			std::cout << "\nInsira um id para remover: ";
			scanf("%d", &id);
			cp.removerProduto(id);
		} break;
		case 5: {
			cp.listarProduto();
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

			cp.alterarProduto(id, *p);
		}break;
		case 6: {
			printf("\n\n\n");
			return;
		}break;
		}
}

void crud_cliente(ControladorVenda cv, ControladorCliente cc, ControladorFuncionario cf, ControladorProduto cp) {
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

			cc.inserirCliente(*c);

		}break;

		case 2: {
			cc.listarCliente();

		}break;

		case 3: {
			int id;
			std::cout << "Insira um id para busca: ";
			scanf("%d", &id);
			cc.buscarCliente(id);
		}break;

		case 4: {
			cc.listarCliente();
			int id;
			std::cout << "\nInsira um id para remover: ";
			scanf("%d", &id);
			cc.removerCliente(id);
		} break;
		case 5: {
			cc.listarCliente();
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
			cc.alterarCliente(id, *end);
		}break;
		case 6: {
			printf("\n\n\n");
			return;
		}break;
		}
}

bool checa_double(std::string str){
	std::string::size_type sz;     // alias of size_t
	
	try {
		std::stod (str, &sz);
	}
	catch (const std::invalid_argument& ia){
		std::cout << "Argumento invalido, por favor insira outro valor. " << std::endl;
		return 0;
	}
	double valor = std::stod (str, &sz); 
	
	int valor_em_inteiro = int(valor);
	
	if ((valor / valor_em_inteiro) == 1)
		return false;	
	else 
		return true;
}

bool checa_data(std::string str){
    std::string::size_type sz;
    
    std::string dia;
    dia[0] = str[0];
    dia[1] = str[1];
    
    try {
		std::stod (dia, &sz);
	}
	catch (const std::invalid_argument& ia){
		std::cout << "Argumento invalido, por favor insira outro valor. " << std::endl;
		return 0;
	}
    int day = std::stod (dia, &sz);
    
    
    std::string mes;
    mes[0] = str[3];
    mes[1] = str[4];
    
    try {
		std::stod (mes, &sz);
	}
	catch (const std::invalid_argument& ia){
		std::cout << "Argumento invalido, por favor insira outro valor. " << std::endl;
		return 0;
	}
    int month = std::stod (mes, &sz);
    
    
    std::string ano;
    ano[0] = str[6];
    ano[1] = str[7];
    ano[2] = str[8];
    ano[3] = str[9];
    
    try {
		std::stod (ano, &sz);
	}
	catch (const std::invalid_argument& ia){
		std::cout << "Argumento invalido, por favor insira outro valor. " << std::endl;
		return 0;
	}
    int year = std::stod (ano, &sz);
    
    if ( (str[5] == '/') && (str[2] == '/') ){
        std::cout << "Formato de data valido, fique atento para as excecoes" << std::endl;
        return true;
    }
    else{ 
        std::cout << "Formato de data invalido, por favor insira outro valor!" << std::endl;
        return false;
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

