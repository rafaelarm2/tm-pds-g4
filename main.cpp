/*
 * main.cpp
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

#include "Cliente.h"
#include "Endereco.h"
#include "Produto.h"
#include "ControladorProduto.h"
#include "ControladorCliente.h"
#include "ControladorFuncionario.h"
#include "ControladorVenda.h"
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

void listarmenu() {
	std::cout << "Menu"<< endl;
	std::cout << "1. Venda" << endl;
	std::cout << "2. Entrega" << endl;
	std::cout << "3. Fornecimento" << endl;
	std::cout << "4. CRUD Produto" << endl;
	std::cout << "5. CRUD Cliente" << endl;
	std::cout << "6. CRUD Funcionário\n" << endl;
}

void venda(ControladorVenda cv, ControladorCliente cc, ControladorFuncionario cf, ControladorProduto cp) {
	std::cout << "VENDAS"<< endl;
	std::cout << "1. Registrar nova venda" << endl;
	std::cout << "2. Relatorio de vendas" << endl;

	int item_menu;
	std::cout << "Escolha uma seção: ";
	scanf("%d", &item_menu);

	std::string choice, idproduto, idcliente, idfuncionario, qtd;
	Cliente cli;
	Funcionario fun;
	Venda *v;
	VendaEntrega *ve;
	Endereco *end;

	fflush(stdin);

	switch (item_menu) {
		case 1: {
/////////////////////////////////////////////////////////////////VENDA ////////////////////////////////////////////
			///////////////////////////////////////// SELEÇÃO DE CLIENTE
			std::list<Item> itens;
			std::cout << "\n\n";
			std::cout << "Deseja selecionar cliente? s/n";
			std::cin.ignore();
			std::getline(std::cin, choice);
			std::cout << choice << endl;

			if(choice == "n" || choice == "N") {
				Cliente *c = new Cliente(0);
				cli = *c;
				idcliente = "0";
			} else {
				if(choice == "s" || choice == "S") {
					std::cout << "\n\n" << endl;
					std::cout << "**LISTA DE CLIENTES**" << endl;
					cc.listarCliente();
					std::cout << "\n";
					std::cout << "Selecione o id desejado: ";
					std::getline(std::cin, idcliente);
					std::cout << idcliente << endl;
					std::cout << "\n\n";
					//Cliente *cli = new Cliente();

					cli = cc.buscarCliente(stoi(idcliente.c_str()));


				}
			}

			///////////////////////////////////////// SELEÇÃO DE FUNCIONARIO
			std::cout << "Deseja selecionar funcionario? s/n";
			std::getline(std::cin, choice);
			std::cout << choice << endl;



			if(choice == "n" || choice == "N") {
				Funcionario *f = new Funcionario(0);
				fun = *f;
				idfuncionario = "0";
			} else {
				if(choice == "s" || choice == "S") {
					std::cout << "\n\n" << endl;
					std::cout << "**LISTA DE FUNCIONARIOS**" << endl;
					//cc.listarFuncionario();
					std::cout << "Selecione o id desejado: ";
					std::getline(std::cin, idfuncionario);
					std::cout << idfuncionario << endl;
				}
			}



			///////////////////////////////////////// SELEÇÃO DE PRODUTOS
			std::cout << "**LISTA DE PRODUTOS**" << endl;
			cp.listarProduto();
			std::cout << "\n";
			std::cout << "Digite 0 para encerrar a seleção de produtos." << endl;
			std::cout << "\n\n";
			std::cout << "Selecionar produto: ";
			std::getline(std::cin, idproduto);
			std::cout << idproduto << endl;



			while (idproduto != "0") {
				std::cout << "Quantidade: ";
				std::getline(std::cin, qtd);
				std::cout << qtd << endl;

				while (cv.verificaEstoque(stoi(idproduto.c_str()), stoi(qtd.c_str()))== 0) {

					std::cout << "Quantidade menor que o estoque.\n" << endl;

					std::cout << "Quantidade: ";
					std::getline(std::cin, qtd);
					std::cout << qtd << endl;
				}

				Produto *p = new Produto();
				*p = cp.buscarProduto(stoi(idproduto.c_str()));

				itens.push_back(Item(*p, stoi(qtd.c_str())));
				std::cout << "\n\n";;
				std::cout << "Selecionar produto: ";
				std::getline(std::cin, idproduto);
				std::cout << idproduto << endl;

			}

			///////////////////////////////////////// ACHA A DATA DA COMPRA
			time_t timer;
			struct tm *horarioLocal;
			time(&timer); // Obtem informações de data e hora
			horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
			int dia = horarioLocal->tm_mday;
			int mes = horarioLocal->tm_mon + 1;
			int ano = horarioLocal->tm_year + 1900;
			std::stringstream ss;
			ss << dia << "/" << mes << "/"<< ano;
			std::string dtvenda = ss.str();

			///////////////////////////////////////// DESCONTO?
			std::cout << "Desconto: " << endl;
			std::string desconto;
			std::getline(std::cin, desconto);
			std::cout << desconto << endl;

			///////////////////////////////////////// SERA UMA VENDA COMUM OU VENDA ENTREGA?
			std::cout << "Deseja cadastrar uma entrega? s/n " << endl;
			std::getline(std::cin, choice);
			std::cout << choice << endl;

			if(choice == "n" || choice == "N") {
				v = new Venda(dtvenda, itens, cli, fun, stoi(desconto.c_str()));
				cv.novaVenda(*v, stoi(idcliente.c_str()), stoi(idfuncionario.c_str()));
			} else {
				if(choice == "s" || choice == "S") {
					std::cout << "\n\n" << endl;
					std::cout << "**ENTREGA**" << endl;

					std::cout << "Frete: " << endl;
					std::string frete;
					std::getline(std::cin, frete);
					std::cout << frete << endl;

					std::cout << "Logradouro: " << endl;
					std::string logradouro;
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

					end = new Endereco(logradouro, bairro, cep, stoi(numstr.c_str()), comp, cidade);
					ve = new VendaEntrega(dtvenda, itens, cli, fun, stoi(desconto.c_str()), *end, stod(frete.c_str()), StatusEntrega::PENDENTE);

					cv.novaVendaEntrega(*ve, *end, stoi(idcliente.c_str()), stoi(idfuncionario.c_str()));

					std::cout << "Cidade entrega" << endl;
					std::cout << ve->getEndereco().getCidade() << endl;
					std::cout << "Cidade entrega" << endl;
					std::cout << ve->getCliente().getNome() << endl;
					std::cout << "Vlfinal" << endl;
					std::cout << ve->getVlfinal() << endl;
				}
			}

			for (std::list<Item>::iterator it = itens.begin(); it != itens.end(); ++it) {
				cp.saidaProduto(it->getProduto().getID(),it->getProduto().getEstoque(), it->getQtd());
			}


		} break;

		case 2: {
///////////////////////////////////////////////////// RELATORIO DE VENDA///////////////////////////////////////////
			cv.relatorioVendas();
		} break;
		default: {

		} break;
	}


}

void entrega(ControladorVenda cv, ControladorCliente cc, ControladorFuncionario cf, ControladorProduto cp) {
	std::cout << "ENTREGAS"<< endl;
	std::cout << "1. Realizar entrega" << endl;
	std::cout << "2. Relatorio de entregas realizadas" << endl;

	int item_menu;
	std::cout << "Escolha uma seção: ";
	scanf("%d", &item_menu);

	switch (item_menu) {
	case 1: {
		std::cout << "\nLISTA DE ENTREGAS PENDENTES"<< endl;
		cv.relatorioVendasEntregas(0);
		std::cout <<"\n Insira o ID da entrega para marcar como ENTREGUE: "<< endl;

		std::string id;
		std::cin.ignore();
		std::getline(std::cin, id);
		std::cout << id << endl;

		time_t timer;
		struct tm *horarioLocal;
		time(&timer); // Obtem informações de data e hora
		horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
		int dia = horarioLocal->tm_mday;
		int mes = horarioLocal->tm_mon + 1;
		int ano = horarioLocal->tm_year + 1900;
		std::stringstream ss;
		ss << dia << "/" << mes << "/"<< ano;
		std::string dtatual = ss.str();

		cv.entregar(stoi(id.c_str()), dtatual);
	}break;
	case 2: {
		std::cout << "\nLISTA DE ENTREGAS REALIZADAS"<< endl;
		cv.relatorioVendasEntregas(1);
	}break;
	default: {

	}break;
	}

}

void fornecimento(ControladorVenda cv, ControladorCliente cc, ControladorFuncionario cf, ControladorProduto cp) {
	std::cout << "LISTA DE PRODUTOS"<< endl;
	cp.listarProduto();
	std::cout << "Selecione um ID: ";
	int id;
	scanf("%d", &id);

	std::cout << "Acrescimo no estoque: " << endl;
	std::string qtd;
	std::cin.ignore();
	std::getline(std::cin, qtd);
	std::cout << qtd << endl;

	cp.entradaProduto(id, stoi(qtd.c_str()));


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

			std::cout << "Estoque: " << endl;
			std::string estoque;
			std::getline(std::cin, estoque);
			std::cout << estoque << endl;

			Produto *p = new Produto(nome, atof(preco.c_str()), marca, stoi(estoque.c_str()));

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



int main() {
	ControladorProduto *cp = new ControladorProduto();
	ControladorCliente *cc = new ControladorCliente();
	ControladorFuncionario *cf = new ControladorFuncionario();
	ControladorVenda *cv = new ControladorVenda();

	while(1){
		int item_menu;
		listarmenu();

		std::cout << "Selecionar função: ";
		scanf("%d", &item_menu);
		switch (item_menu) {
		case 1: {
			// VENDA
			printf("\n\n\n");
			venda(*cv, *cc, *cf, *cp);
		}break;
		case 2: {
			entrega(*cv, *cc, *cf, *cp);
		}break;
		case 3: {
			fornecimento(*cv, *cc, *cf, *cp);

		}break;
		case 4: {
			//CRUD DE PRODUTO
			printf("\n\n\n");
			crud_produto(*cv, *cc, *cf, *cp);
		}break;
		case 5: {
			//CRUD DE CLIENTE
			printf("\n\n\n");
			crud_cliente(*cv, *cc, *cf, *cp);

		} break;
		case 6: {
			//CRUD DE FUNCIONARIOS
			printf("\n\n\n");
		}break;
		default: {

		}
		}

	}
	////////////////////// CRUD DE PRODUTO ///////////////////////////////



	return 0;
}




