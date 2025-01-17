
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
#include <algorithm>
#include <cctype>

using namespace std;

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

//funcao que indica incorrecao na entrada dos dados. Nao permite valor em branco, apenas espacos ou apenas caracteres numericos.
bool verifica_dados_endereco(std::string info){
    if((info == "") || (info == " ")){
	    std::cout << "Invalido. Insira o argumento corretamente." << std::endl;
	    return 0;
	}
	else {
	    for (int i = 0; i < info.length(); i++){
	        if((isalpha(info[i]) == 0) && (info[i] != ' ')){
	            std::cout << "Invalido. Insira o argumento corretamente." << std::endl;
	            return 0;
	        }
	       else continue;
	    }
	}
    
    return 1;
}

//funcao que indica incorrecao na entrada dos dados. Nao permite valor em branco, apenas espacos ou apenas caracteres numericos.
//Numeros podem ser incluidos, porem, desde que nao representem a totalidade da palavra
bool verifica_dados(std::string info){
int contador = 0;
	
	if((info == "") || (info == " ")){
		std::cout << "Invalido. Insira o argumento corretamente." << std::endl;
	    	return 0;
	}
	else {
	    for (int i = 0; i < info.length(); i++){
	        if(isalpha(info[i]) == 0)
	        	contador += 1;
		else 
			continue;
	    }
		
	if ( contador == info.length() ){
		std::cout << "Invalido. Insira o argumento corretamente." << std::endl;
		return 0;
	}
	else 
		return 1;	}
}

bool verifica_cep(std::string cep){
    std::string::size_type sz;
    
    try {
        std::stod (cep, &sz);
    }

    catch (const std::invalid_argument& ia){
		std::cout << "Argumento invalido, por favor insira outro valor. " << std::endl;
		return 0;
	}
	
	for (int i = 0; i < 8; i++){
	    if(cep[i] == '\0'){
	        std::cout << "Argumento invalido, por favor insira outro valor. " << std::endl;
	        return 0;
	        break;
	    }
	    else 
	        continue;
	}
	
	if(cep[8] != '\0'){
	    std::cout << "Argumento invalido, por favor insira outro valor. " << std::endl;
	    return 0;
	}
	
	return 1; 
}

bool validaCPF(const char * cpf){
    unsigned lenght = 0;
    int ver1 = 0, ver2 = 0;
    char aux;

    /* contando o tamanho de cpf e verificando se o o tamanho do mesmo é 11
     */
    while (cpf[lenght]) {
        lenght++;
    }

    if (lenght != 11)
        return false;

    /* Calculando o primeiro dígito verificador. Cada dígito tem um peso co-
     * meçando de 1 até 9. Para calculá-lo deve-se somar cada dígito, multi-
     * plicando-se por seu peso e ao final realizar a operação de módulo por
     * 11
     */
    for (int j=0; j<9; j++){
        aux = cpf[j];
        ver1 += atoi(&aux)*(j+1);
    }

    ver1 %= 11;

    /* Para o segundo dígito verificador calcula-se a partir do segundo dí-
     * gito até o 10º ( dígito verificador 1 ) atribuindo-se o peso de 1  a
     * 9, e no final realizar a operação Módulo por 11
     */
    for (int j=0; j<9; j++){
        aux = cpf[j];
        ver2 += atoi(&aux)*j;
    }

    ver2 += ver1*9;
    ver2 %= 11;

    /* compara-se agora ver1 e ver2 com os dígitos do cpf */
    aux = cpf[lenght-2];
    if (atoi(&aux) == ver1){
        aux = cpf[lenght-1];
        if ( atoi(&aux) == ver2)
            return true;
    }
    return false;
}

void listarmenu() {
	std::cout << "\n******* Menu *******"<< endl;
	std::cout << "1. Venda" << endl;
	std::cout << "2. Entrega" << endl;
	std::cout << "3. Fornecimento" << endl;
	std::cout << "4. CRUD Produto" << endl;
	std::cout << "5. CRUD Cliente" << endl;
	std::cout << "6. CRUD Funcionario" << endl;
	std::cout << "7. Encerrar\n" << endl;

}

void venda(ControladorVenda cv, ControladorCliente cc, ControladorFuncionario cf, ControladorProduto cp) {
	//MENU DE VENDA
	std::cout << "VENDAS"<< endl;
	std::cout << "1. Registrar nova venda" << endl;
	std::cout << "2. Relatorio de vendas" << endl;
	std::cout << "3. Voltar" << endl;

	//LEITURA DO MENU COM RESTRIÇÃO
	std::cout << "Selecione uma seção: ";
	std::string strmenu;
	int menu;

	do {
		std::getline(std::cin, strmenu);

		try {
			menu = stoi(strmenu.c_str());
		} catch (...){
			menu = 0;
		}

		if (menu <= 0 || menu > 3) {
			std::cout << "Inválido. Selecione novamente: ";
		}

	} while (menu <= 0 || menu > 3);



	std::string choice, idproduto, idcliente, idfuncionario, qtdstr;
	Cliente cli;
	Funcionario fun;
	Venda *v;
	VendaEntrega *ve;
	Endereco *end;

	switch (menu) {
		case 1: {
			///////////////////////////////////////// SELEÇÃO DE CLIENTE
			std::list<Item> itens;
			std::cout << "\n\nCLIENTE" << endl;
			std::cout << "Deseja selecionar cliente? s/n";
			std::getline(std::cin, choice);
			//RESTRIÇÃO DA ESCOLHA
			while(choice != "n" && choice != "s" && choice != "S"  && choice != "N") {

				std::cout << "Entrada inválida. Deseja selecionar cliente? s/n";
				std::getline(std::cin, choice);
			}
			//VERIFICA SE O CLIENTE SERA INSERIDO
			//CASO A RESPOSTA SEJA NAO O CLIENTE COM ID 0 SERA REGISTRADO NO BANCO, COMO SE FOSSE UM CLIENTE GERAL
			//ISSO SERA USADO EM CASOS DE CLIENTES NAO REGISTRADOS
			if(choice == "n" || choice == "N") {
				Cliente *c = new Cliente(0);
				cli = *c;
				idcliente = "0";
			} else {
				if(choice == "s" || choice == "S") {
					std::cout << "\n" << endl;
					std::cout << "LISTA DE CLIENTES" << endl;
					cc.listarCliente();
					std::cout << "\n";
					std::cout << "Selecione o id desejado: ";
					int id;
					//LEITURA DO ID COM RESTRIÇÃO
					do {
						std::getline(std::cin, idcliente);

						try {
							id = stoi(idcliente.c_str());
						} catch (...){
							id = -1;
						}

						if (id < 0) {
							std::cout << "Inválido. Insira o ID novamente: ";
						}else {
							if (!cc.idExiste(id)) {
								std::cout << "Nao consta na lista. Insira o ID novamente: ";
							}
						}

					} while (id < 0 || !cc.idExiste(id) );

					std::cout << "\n";

					cli = cc.buscarCliente(id);


				}
			}

			///////////////////////////////////////// SELEÇÃO DE FUNCIONARIO

			std::cout << "\nFUNCIONARIO" << endl;
			std::cout << "Deseja selecionar funcionario? s/n ";
			std::getline(std::cin, choice);
			//RESTRIÇÃO
			while(choice != "n" && choice != "s" && choice != "S"  && choice != "N") {
				std::cout << "Entrada inválida. Deseja selecionar funcionario? s/n ";
				std::getline(std::cin, choice);
			}
			//VERIFICA SE O FUNCIONARIO SERA INSERIDO
			//CASO A RESPOSTA SEJA NAO O FUNCIONARIO COM ID 0 SERA REGISTRADO NO BANCO, COMO SE FOSSE UM FUNCIONARIO GERAL

			if(choice == "n" || choice == "N") {
				Funcionario *f = new Funcionario(0);
				fun = *f;
				idfuncionario = "0";
			} else {
				if(choice == "s" || choice == "S") {
					std::cout << "\n" << endl;
					std::cout << "LISTA DE FUNCIONARIOS" << endl;
					//cc.listarFuncionario();
					std::cout << "Selecione o id desejado: ";
					std::getline(std::cin, idfuncionario);
					std::cout << idfuncionario << endl;
				}
			}
			


			///////////////////////////////////////// SELEÇÃO DE PRODUTOS
			std::cout << "\nLISTA DE PRODUTOS" << endl;
			cp.listarProduto();
			std::cout << "\n";
			std::cout << "Digite 0 para encerrar a seleção de produtos.\n" << endl;
			int id = -1;
			int qtd = -1;

			//VAI COLOCANDO PRODUTO NO CARRINHO ATÉ O ID FOR 0
			while (id != 0) {
				std::cout << "Selecionar produto: ";
				do {

					//LEITURA DO ID COM RESTRIÇÃO
					std::getline(std::cin, idproduto);

					try {
						id = stoi(idproduto.c_str());
						if (id == 0) break;
					} catch (...){
						id = -1;
					}

					if (id < 0) {
						std::cout << "Inválido. Insira o ID novamente: ";
					}

					if (!cp.idExiste(id) && id > 0) {
						std::cout << "Nao consta na lista.Insira o ID novamente: ";
					}

				} while(!cp.idExiste(id) || id < 0) ;

				//LEITURA DA QUANTIDADE COM RESTRIÇÃO
				if (id != 0 ) {
					std::cout << "Quantidade: ";
					do {
						std::getline(std::cin, qtdstr);

						try {
							qtd = stoi(qtdstr.c_str());
						} catch (...){
							qtd = 0;
						}

						if (qtd == 0) {
							std::cout << "Inválido. Insira a quantidade novamente: ";
						}

						if (!cv.verificaEstoque(id, qtd) && qtd != 0) {
							std::cout << "Estoque insuficiente. Insira a quantidade novamente: ";
						}

					} while(qtd == 0 || cv.verificaEstoque(id, qtd) == 0);
					Produto *p = new Produto();

					//REALIZA A BUSCA DO PRODUTONO BANCO DE DADOS
					*p = cp.buscarProduto(id);
					//O PRODUTO P CRIADO RECEBERÁ UM PRODUTO Q SERÁ GERADO NA FUNCAO DO BANCO

					//ADICIONA NO LIST
					itens.push_back(Item(*p, qtd));
					std::cout << "\n";;
				}
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
			std::cout << "\nDesconto: ";
			int desconto;
			std::string descontostr;

			//LEITURA DO DESCONTO COM RESTRIÇÃO
			do {
				std::getline(std::cin, descontostr);

				try {
					desconto = stoi(descontostr.c_str());
				} catch (...){
					desconto = -1;
				}

				if (desconto < 0) {
					std::cout << "Inválido. Insira a quantidade novamente: ";
				}

			} while (desconto < 0);

			///////////////////////////////////////// SERA UMA VENDA COMUM OU VENDA ENTREGA?
			std::cout << "Deseja cadastrar uma entrega? s/n " << endl;
			std::getline(std::cin, choice);

			//RESTRIÇÃO
			while(choice != "n" && choice != "s" && choice != "S"  && choice != "N") {
				std::cout << "Entrada inválida. Deseja selecionar funcionario? s/n ";
				std::getline(std::cin, choice);
			}

			if(choice == "n" || choice == "N") {
				//GERA VENDA SIMPLES
				v = new Venda(dtvenda, itens, cli, fun, desconto);
				//CADASTRA NO BANCO
				cv.novaVenda(*v, stoi(idcliente.c_str()), stoi(idfuncionario.c_str()));
			} else {
				if(choice == "s" || choice == "S") {
					std::cout << "ENTREGA" << endl;

					std::string logradouro;
					do {
					std::cout << "Logradouro: ";
					std::getline(std::cin, logradouro);
					} while (verifica_dados_endereco(logradouro) != 1);

					
					std::string bairro;
					
					do {
					std::cout << "Bairro: ";
					std::getline(std::cin, bairro);
					} while (verifica_dados_endereco(bairro) != 1);

					std::cout << "Num: ";
					int num;
					std::string numstr;

					//LEITURA DO NUMERO COM RESTRIÇÃO
					do {
						std::getline(std::cin, numstr);

						try {
							num = stoi(numstr.c_str());
						} catch (...){
							num = 0;
						}

						if (num <= 0) {
							std::cout << "Inválido. Insira o número novamente: ";
						}

					} while (num <= 0);

					std::string cep;
					do {
					std::cout << "CEP: ";
					std::getline(std::cin, cep);
					} while (verifica_cep(cep) != 1);
					
					std::cout << "Complemento: ";
					std::string comp;
					std::getline(std::cin, comp);

					std::string cidade;
					do {
					std::cout << "Cidade: ";
					std::getline(std::cin, cidade);
					} while (verifica_dados_endereco(cidade) != 1);

					std::cout << "Frete: ";
					int frete;
					std::string fretestr;

					//LEITURA DO NUMERO COM RESTRIÇÃO
					do {
						std::getline(std::cin, fretestr);
						std::replace(fretestr.begin(), fretestr.end(), ',', '.');

						try {
							frete = stod(fretestr.c_str());
						} catch (...){
							frete = 0.0;
						}

						if (frete <= 0.0) {
							std::cout << "Inválido. Insira o frete novamente: ";
						}

					} while (frete <= 0.0);

					//GERA NOVO ENDERECO E VENDA
					end = new Endereco(logradouro, bairro, cep, stoi(numstr.c_str()), comp, cidade);
					ve = new VendaEntrega(dtvenda, itens, cli, fun, desconto, *end, frete, StatusEntrega::PENDENTE);

					//ADICIONA NO BANCO DE DADOS
					cv.novaVendaEntrega(*ve, *end, stoi(idcliente.c_str()), stoi(idfuncionario.c_str()));
				}
			}
			//PERCORRE O LIST PARA DESCONTAR OS PRODUTOS VENDIDOS NO ESTOQUE
			for (std::list<Item>::iterator it = itens.begin(); it != itens.end(); ++it) {
				cp.saidaProduto(it->getProduto().getID(),it->getProduto().getEstoque(), it->getQtd());
			}


		} break;

		case 2: {
///////////////////////////////////////////////////// RELATORIO DE VENDA///////////////////////////////////////////
			std::cout << "RELATORIO DE VENDAS"<< endl;
			cv.relatorioVendas();

			std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
			std::getline(std::cin, strmenu);
		} break;

		case 3: {

		}break;
	}

}

void entrega(ControladorVenda cv, ControladorCliente cc, ControladorFuncionario cf, ControladorProduto cp) {
	std::cout << "\nENTREGAS"<< endl;
	std::cout << "1. Realizar entrega" << endl;
	std::cout << "2. Relatorio de entregas realizadas" << endl;
	std::cout << "3. Voltar" << endl;

	//LEITURA DO MENU COM RESTRIÇÃO
	std::cout << "Selecione uma funcionalidade: ";
	std::string strmenu;
	int menu;

	do {
		std::getline(std::cin, strmenu);

		try {
			menu = stoi(strmenu.c_str());
		} catch (...){
			menu = 0;
		}

		if (menu <= 0 || menu > 3) {
			std::cout << "Inválido. Selecione novamente: ";
		}

	} while (menu <= 0 || menu > 3);

	std::string idstr;
	int id;
	switch (menu) {
	case 1: {
		std::cout << "\nLISTA DE ENTREGAS PENDENTES"<< endl;
		cv.relatorioVendasEntregas(0);
		std::cout <<"\n Insira o ID da entrega para marcar como ENTREGUE: ";
		int identrega;
		//LEITURA DO ID COM RESTRIÇÃO
		do {
			std::getline(std::cin, idstr);

			try {
				id = stoi(idstr.c_str());
			} catch (...){
				id = -1;
			}

			if (id < 0) {
				std::cout << "Inválido. Insira o ID novamente: ";
			}else {
				if (!cv.idExiste(id)) {
					std::cout << "Nao consta na lista. Insira o ID novamente: ";
				}
			}

		} while (id < 0 || !cv.idExiste(id) );

		std::cout << "\n";
		//PEGA A DATA ATUAL
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
		//REALIZA A ENTREGA NO BANCO DE DADOS E SALVA A DATA DA ENTREGA
		cv.entregar(id, dtatual);
		//EXIBE RELATORIO DE VENDAS COM ENTREGAS REALIZADAS
		cv.relatorioVendasEntregas(1);


		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);
	}break;
	case 2: {
		std::cout << "\nLISTA DE ENTREGAS REALIZADAS"<< endl;
		cv.relatorioVendasEntregas(1);


		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);
	}break;
	case 3: {

	}break;
	}

}

void fornecimento(ControladorVenda cv, ControladorCliente cc, ControladorFuncionario cf, ControladorProduto cp) {
	std::cout << "FORNECIMENTO DE PRODUTO\n"<< endl;

	std::cout << "LISTA DE PRODUTOS\n"<< endl;
	cp.listarProduto();
	std::string idstr;
	int id;
	std::cout << "\nInsira o ID desejado para fornecimento: ";
	//LEITURA DO ID COM RESTRIÇÃO
	do {
		std::getline(std::cin, idstr);

		try {
			id = stoi(idstr.c_str());
		} catch (...){
			id = -1;
		}

		if (id < 0) {
			std::cout << "Inválido. Insira o ID novamente: ";
		}

	} while (id < 0);
	//CHECA SE O ID EXISTE NO BANCO
	if(cp.idExiste(id)) {
		// QTD QUE SERA ACRESCIDA NO ESTOQUE
		std::cout << "Acrescimo no estoque: ";
		std::string qtdstr;
		int qtd;
		//LEITURA DO NUMERO COM RESTRIÇÃO
		do {
			std::getline(std::cin, qtdstr);

			try {
				qtd = stoi(qtdstr.c_str());
			} catch (...){
				qtd = 0;
			}

			if (qtd <= 0) {
				std::cout << "Inválido. Insira a quantidade novamente: ";
			}

		} while (qtd <= 0);

		//CHAMA A FUNCAO QUE DA ENTRADA NO ESTOQUE NO BANCO DE DADOS
		cp.entradaProduto(id, qtd);
	} else {
		std::cout << "ID não existe." << endl;
	}

	std::cout << "\nLISTA DE PRODUTOS\n"<< endl;
	cp.listarProduto();

	std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
	std::string strmenu;
	std::getline(std::cin, strmenu);




}

void crud_produto(ControladorVenda cv, ControladorCliente cc, ControladorFuncionario cf, ControladorProduto cp) {

	std::cout << "CRUD PRODUTO"<< endl;
	std::cout << "1. Inserir" << endl;
	std::cout << "2. Listar" << endl;
	std::cout << "3. Buscar" << endl;
	std::cout << "4. Remover" << endl;
	std::cout << "5. Alterar" << endl;
	std::cout << "6. Voltar" << endl;

	//LEITURA DO MENU COM RESTRIÇÃO
	std::cout << "Selecione uma funcionalidade: ";
	std::string strmenu;
	int menu;

	do {
		std::getline(std::cin, strmenu);

		try {
			menu = stoi(strmenu.c_str());
		} catch (...){
			menu = 0;
		}

		if (menu <= 0 || menu > 6) {
			std::cout << "Inválido. Selecione novamente: ";
		}

	} while (menu <= 0 || menu > 6);


	fflush(stdin);

	switch (menu) {
	case 1: {
		std::cout << "\nINSERIR NOVO PRODUTO\n" << endl;
		//CAPTA TODOS OS DADOS DE PRODUTO PELO TECLADO
		
		std::string nome;
		do {
		std::cout << "Nome: ";
		std::getline(std::cin, nome);
		} while (verifica_dados(nome) != 1);

		std::string marca;
		do {
		std::cout << "Marca: ";
		std::getline(std::cin, marca);
		} while (verifica_dados(marca) != 1);

		std::cout << "Preco: ";
		std::string precostr;
		double preco;

		//LEITURA DO NUMERO COM RESTRIÇÃO
		do {
			std::getline(std::cin, precostr);
			std::replace(precostr.begin(), precostr.end(), ',', '.');

			try {
				preco = stod(precostr.c_str());
			} catch (...){
				preco = 0.0;
			}

			if (preco <= 0.0) {
				std::cout << "Inválido. Insira o preco novamente: ";
			}

		} while (preco <= 0.0);


		std::cout << "Estoque: ";
		int estoque;
		std::string estoquestr;

		//LEITURA DO NUMERO COM RESTRIÇÃO
		do {
			std::getline(std::cin, estoquestr);

			try {
				estoque = stoi(estoquestr.c_str());
			} catch (...){
				estoque = 0;
			}

			if (estoque <= 0) {
				std::cout << "Inválido. Insira o estoque novamente: ";
			}

		} while (estoque <= 0);
		//CRIA NOVO OBJETO DE PRODUTO
		//LEMBRANDO Q O ID NO BANCO É AUTOINCREMENTO, LOGO N PRECISA GERAR
		Produto *p = new Produto(nome, preco, marca, estoque);
		//INSERE NO BANCO DE DADOS
		cp.inserirProduto(*p);

		std::cout << "\nLISTA DE CLIENTES\n" << endl;
		cp.listarProduto();

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);

	}break;

	case 2: {
		std::cout << "\nLISTA DE PRODUTOS\n" << endl;
		cp.listarProduto();


		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);
	}break;

	case 3: {
		std::cout << "\nBUSCA DE PRODUTOS" << endl;
		std::string idstr;
		int id;
		std::cout << "\nInsira o ID desejado para buscar: ";
		//LEITURA DO ID COM RESTRIÇÃO
		do {
			std::getline(std::cin, idstr);

			try {
				id = stoi(idstr.c_str());
			} catch (...){
				id = -1;
			}

			if (id < 0) {
				std::cout << "Invalido. Insira o ID novamente: ";
			}

		} while (id < 0);
		//VERIFICA SE O ID EXISTE NO BANCO
		if(cp.idExiste(id)) {
			//REALIZA A BUSCA NO BANCO
			cp.buscarProduto(id);
		} else {
			std::cout << "ID não existe." << endl;
		}

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);

	}break;

	case 4: {
		std::cout << "\nLISTA DE PRODUTOS\n" << endl;
		cp.listarProduto();
		std::string idstr;
		int id;
		std::cout << "\nInsira o ID desejado para remover: ";
		//LEITURA DO ID COM RESTRIÇÃO
		do {
			std::getline(std::cin, idstr);

			try {
				id = stoi(idstr.c_str());
			} catch (...){
				id = -1;
			}

			if (id < 0) {
				std::cout << "Invalido. Insira o ID novamente: ";
			}

		} while (id < 0);
		//VERIFICA SE O ID EXISTE NO BANCO
		if(cp.idExiste(id)) {
			//REMOVE O PRODUTO DO BANCO
			cp.removerProduto(id);
		} else {
			std::cout << "\nErro: ID não encontrado." << endl;
		}

		std::cout << "\nLISTA DE PRODUTOS\n" << endl;
		cp.listarProduto();

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);
	} break;
	case 5: {
		std::cout << "\nLISTA DE PRODUTOS\n" << endl;
		cp.listarProduto();
		std::string idstr;
		int id;
		std::cout << "\nInsira o ID desejado para alterar: ";
		//LEITURA DO ID COM RESTRIÇÃO
		do {
			std::getline(std::cin, idstr);

			try {
				id = stoi(idstr.c_str());
			} catch (...){
				id = -1;
			}

			if (id < 0) {
				std::cout << "Invalido. Insira o ID novamente: ";
			}

		} while (id < 0);

		//CHECA SE O ID EXISTE E CAPTA OS DADOS DO PRODUTO PARA ALTERAR
		if(cp.idExiste(id)) {
			
			std::string nome;
			do {
			std::cout << "Nome: ";
			std::getline(std::cin, nome);
			} while (verifica_dados(nome) != 1);


			std::string marca;
			do {
			std::cout << "Marca: ";
			std::getline(std::cin, marca);
			} while (verifica_dados(marca) != 1);

			std::cout << "Preco: ";
			std::string precostr;
			double preco;
			//O ESTOQUE SO EH POSSIVEL ALTERAR ATRAVES DO FORNECIMENTO

			//LEITURA DO NUMERO COM RESTRIÇÃO
			do {
				std::getline(std::cin, precostr);
				std::replace(precostr.begin(), precostr.end(), ',', '.');

				try {
					preco = stod(precostr.c_str());
				} catch (...){
					preco = 0.0;
				}

				if (preco <= 0.0) {
					std::cout << "Invalido. Insira o preco novamente: ";
				}

			} while (preco <= 0.0);

			//CRIA NOVO OBJETO PREODUTO
			Produto *p = new Produto(nome, preco, marca);
			//REALIZA A ALTERACAO NO BANCO
			cp.alterarProduto(id, *p);

			std::cout << "\nLISTA DE PRODUTOS\n" << endl;
			cp.listarProduto();
		} else {
			std::cout << "\nErro: ID não encontrado." << endl;
		}

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);
	}break;
	case 6: {
		printf("\n\n");
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

	//LEITURA DO MENU COM RESTRIÇÃO
	std::cout << "Selecione uma funcionalidade: ";
	std::string strmenu;
	int menu;
	//VALIDAÇÃO DO ITEM DO MENU
	do {
		std::getline(std::cin, strmenu);

		try {
			menu = stoi(strmenu.c_str());
		} catch (...){
			menu = 0;
		}

		if (menu <= 0 || menu > 6) {
			std::cout << "Inválido. Selecione novamente: ";
		}

	} while (menu <= 0 || menu > 6);


	fflush(stdin);

	switch (menu) {
	case 1: {
		std::cout << "\nINSERIR NOVO CLIENTE\n" << endl;
		//PEGA OS DADOS DO CLIENTE DO TECLADO
		std::string nome;
		do {
		std::cout << "Nome: ";
		std::getline(std::cin, nome);
		} while (verifica_dados(nome) != 1);


		std::cout << "CPF: ";
		std::string cpfstr;
		//CHAMA A FUNÇÃO DE VALIDAÇÃO DE CPF
		do {
			std::getline(std::cin, cpfstr);

			if (!validaCPF(cpfstr.c_str())) {
				std::cout << "Inválido. Insira o CPF novamente: ";
			}

		} while (!validaCPF(cpfstr.c_str()));
		
		std::string email;
		do {
		std::cout << "Email: ";
		std::getline(std::cin, email);
		} while (verifica_dados(email) != 1);

		std::cout << "Tel: ";
		std::string tel;
		std::getline(std::cin, tel);

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

		//PEGA O ENDERECO DO CLIENTE
		std::string logradouro;
		do {
		std::cout << "Logradouro: ";
		std::getline(std::cin, logradouro);
		} while (verifica_dados_endereco(logradouro) != 1);


		std::string bairro;
		do {
		std::cout << "Bairro: ";
		std::getline(std::cin, bairro);
		} while (verifica_dados_endereco(bairro) != 1);

		std::cout << "Num: ";
		int num;
		std::string numstr;


		//LEITURA DO NUMERO COM RESTRIÇÃO
		do {
			std::getline(std::cin, numstr);

			try {
				num = stoi(numstr.c_str());
			} catch (...){
				num = 0;
			}

			if (num <= 0) {
				std::cout << "Inválido. Insira o número novamente: ";
			}

		} while (num <= 0);

		std::string cep;
		do {
		std::cout << "CEP: ";
		std::getline(std::cin, cep);
		} while (verifica_cep(cep) != 1);

		std::cout << "Complemento: ";
		std::string comp;
		std::getline(std::cin, comp);

		std::string cidade;
		do {
		std::cout << "Cidade: ";
		std::getline(std::cin, cidade);
		} while (verifica_dados_endereco(cidade) != 1);
		
		//CRIA NOVOS OBJETOS DE ENDERECO E CLIENTE
		Endereco *end = new Endereco(logradouro, bairro, cep, num, comp, cidade);
		Cliente *c = new Cliente(nome, cpfstr, email, *end, tel, dtcadastro, TipoCliente::BRONZE);

		//INSERE CLIENTE NO BANCO DE DADOS
		cc.inserirCliente(*c);

		std::cout << "\nLISTA DE CLIENTES\n" << endl;
		cc.listarCliente();

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);

	} break;

	case 2: {

		std::cout << "\nLISTA DE CLIENTES\n" << endl;
		cc.listarCliente();


		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);


	}break;

	case 3: {

		std::cout << "\nBUSCA DE CLIENTES" << endl;
		std::string idstr;
		int id;
		std::cout << "\nInsira o ID desejado para buscar: ";
		//LEITURA DO ID COM RESTRIÇÃO
		do {
			std::getline(std::cin, idstr);

			try {
				id = stoi(idstr.c_str());
			} catch (...){
				id = -1;
			}

			if (id < 0) {
				std::cout << "Inválido. Insira o ID novamente: ";
			}

		} while (id < 0);
		//SE O ID EXISTE (CHECAGEM NO BANCO DE DADOS)
		if(cc.idExiste(id)) {
			//CLIENTE É BUSCADO NO BANCO
			cc.buscarCliente(id);
		} else {
			std::cout << "ID não existe." << endl;
		}

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);

	}break;

	case 4: {
		std::cout << "\nLISTA DE CLIENTES\n" << endl;
		cc.listarCliente();
		std::string idstr;
		int id;
		std::cout << "\nInsira o ID desejado para remover: ";
		//LEITURA DO ID COM RESTRIÇÃO
		do {
			std::getline(std::cin, idstr);

			try {
				id = stoi(idstr.c_str());
			} catch (...){
				id = -1;
			}

			if (id < 0) {
				std::cout << "Inválido. Insira o ID novamente: ";
			}

		} while (id < 0);
		//VERIFICA NO BANCO DE DADOS SE O CLIENTE EXISTE
		if(cc.idExiste(id)) {
			//REMOVE CLIENTE NO BANCO DE DADOS
			cc.removerCliente(id);
		} else {
			std::cout << "\nErro: ID não encontrado." << endl;
		}

		std::cout << "\nLISTA DE CLIENTES\n" << endl;
		cc.listarCliente();

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);
	} break;
	case 5: {
		std::cout << "\nLISTA DE CLIENTES\n" << endl;
		cc.listarCliente();
		std::string idstr;
		int id;
		std::cout << "\nInsira o ID desejado para alterar: ";
		//LEITURA DO ID COM RESTRIÇÃO
		do {
			std::getline(std::cin, idstr);

			try {
				id = stoi(idstr.c_str());
			} catch (...){
				id = -1;
			}

			if (id < 0) {
				std::cout << "Inválido. Insira o ID novamente: ";
			}

		} while (id < 0);

		//VERIFICA SE O CLIENTE EXISTE E INICIA A CAPTAÇÃO DOS NOVOS DADOS NO TECLADO
		if(cc.idExiste(id)) {
			std::string logradouro;
			do {
			std::cout << "Logradouro: ";
			std::getline(std::cin, logradouro);
			} while (verifica_dados_endereco(logradouro) != 1);

			
			std::string bairro;
			do {
			std::cout << "Novo bairro: ";
			std::getline(std::cin, bairro);
			} while (verifica_dados_endereco(bairro) != 1);
			
			std::cout << "Novo numero: ";
			int num;
			std::string numstr;


			//LEITURA DO NUMERO COM RESTRIÇÃO
			do {
				std::getline(std::cin, numstr);

				try {
					num = stoi(numstr.c_str());
				} catch (...){
					num = 0;
				}

				if (num <= 0) {
					std::cout << "Invalido. Insira o numero novamente: ";
				}

			} while (num <= 0);

			
			std::string cep;
			do {
			std::cout << "Novo CEP: ";
			std::getline(std::cin, cep);
			} while (verifica_cep(cep) != 1);
		
			std::cout << "Novo complemento: ";
			std::string comp;
			std::getline(std::cin, comp);
			
			std::string cidade;
			do {
			std::cout << "Nova cidade: ";
			std::getline(std::cin, cidade);
			} while (verifica_dados_endereco(cidade) != 1);
			

			//CRIA UM NOVO OBJETO CLIENTE
			Endereco *end = new Endereco(logradouro, bairro, cep, stoi(numstr.c_str()), comp, cidade);
			//ALTERA NO BANCO DE DADOS
			cc.alterarCliente(id, *end);

			std::cout << "\nLISTA DE CLIENTES\n" << endl;
			cc.listarCliente();
		} else {
			std::cout << "\nErro: ID não encontrado." << endl;
		}

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);
	}break;
	case 6: {
		printf("\n\n");
		return;
	}break;
	}
}

void crud_funcionario(ControladorVenda cv, ControladorCliente cc, ControladorFuncionario cf, ControladorProduto cp) {
	std::cout << "CRUD FUNCIONARIOS"<< endl;
	std::cout << "1. Inserir" << endl;
	std::cout << "2. Listar" << endl;
	std::cout << "3. Buscar" << endl;
	std::cout << "4. Remover" << endl;
	std::cout << "5. Alterar" << endl;
	std::cout << "6. Voltar" << endl;

	//LEITURA DO MENU COM RESTRIÇÃO
	std::cout << "Selecione uma funcionalidade: ";
	std::string strmenu;
	int menu;
	//VALIDAÇÃO DO ITEM DO MENU
	do {
		std::getline(std::cin, strmenu);

		try {
			menu = stoi(strmenu.c_str());
		} catch (...){
			menu = 0;
		}

		if (menu <= 0 || menu > 6) {
			std::cout << "Inválido. Selecione novamente: ";
		}

	} while (menu <= 0 || menu > 6);


	fflush(stdin);

	switch (menu) {
	case 1: {
		std::cout << "\nINSERIR NOVO FUNCIONARIO\n" << endl;
		//PEGA OS DADOS DO CLIENTE DO TECLADO
		std::string nome;
		do {
		std::cout << "Nome: ";
		std::getline(std::cin, nome);
		} while (verifica_dados(nome) != 1);

		std::cout << "CPF: ";
		std::string cpfstr;
		//CHAMA A FUNÇÃO DE VALIDAÇÃO DE CPF
		do {
			std::getline(std::cin, cpfstr);

			if (!validaCPF(cpfstr.c_str())) {
				std::cout << "Inválido. Insira o CPF novamente: ";
			}

		} while (!validaCPF(cpfstr.c_str()));

		std::cout << "Email: ";
		std::string email;
		std::getline(std::cin, email);

		std::cout << "Tel: ";
		std::string tel;
		std::getline(std::cin, tel);

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
		std::string dtadmissao = ss.str();

		//PEGA O ENDERECO DO CLIENTE
		std::string logradouro;
		do {
		std::cout << "Logradouro: ";
		std::getline(std::cin, logradouro);
		} while (verifica_dados_endereco(logradouro) != 1);


		std::string bairro;
		do {
		std::cout << "Bairro: ";
		std::getline(std::cin, bairro);
		} while (verifica_dados_endereco(bairro) != 1);


		std::cout << "Num: ";
		int num;
		std::string numstr;


		//LEITURA DO NUMERO COM RESTRIÇÃO
		do {
			std::getline(std::cin, numstr);

			try {
				num = stoi(numstr.c_str());
			} catch (...){
				num = 0;
			}

			if (num <= 0) {
				std::cout << "Inválido. Insira o número novamente: ";
			}

		} while (num <= 0);

		std::string cep;
		do {
		std::cout << "CEP: ";
		std::getline(std::cin, cep);
		} while (verifica_cep(cep) != 1);

		std::cout << "Complemento: ";
		std::string comp;
		std::getline(std::cin, comp);

		std::cout << "Cidade: ";
		std::string cidade;
		std::getline(std::cin, cidade);
		//CRIA NOVOS OBJETOS DE ENDERECO E CLIENTE
		Endereco *end = new Endereco(logradouro, bairro, cep, num, comp, cidade);
		Funcionario *f = new Funcionario(nome, cpfstr, email, *end, tel, dtadmissao);

		//INSERE CLIENTE NO BANCO DE DADOS
		cf.inserirFuncionario(*f);

		std::cout << "\nLISTA DE FUNCIONARIOS\n" << endl;
		cf.listarFuncionario();

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);

	} break;

	case 2: {

		std::cout << "\nLISTA DE FUNCIONARIOS\n" << endl;
		cf.listarFuncionario();


		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);


	}break;

	case 3: {

		std::cout << "\nBUSCA DE FUNCIONARIOS" << endl;
		std::string idstr;
		int id;
		std::cout << "\nInsira o ID desejado para buscar: ";
		//LEITURA DO ID COM RESTRIÇÃO
		do {
			std::getline(std::cin, idstr);

			try {
				id = stoi(idstr.c_str());
			} catch (...){
				id = -1;
			}

			if (id < 0) {
				std::cout << "Inválido. Insira o ID novamente: ";
			}

		} while (id < 0);
		//SE O ID EXISTE (CHECAGEM NO BANCO DE DADOS)
		if(cf.idExiste(id)) {
			//CLIENTE É BUSCADO NO BANCO
			cf.buscarFuncionario(id);
		} else {
			std::cout << "ID não existe." << endl;
		}

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);

	}break;

	case 4: {
		std::cout << "\nLISTA DE FUNCIONARIOS\n" << endl;
		cc.listarCliente();
		std::string idstr;
		int id;
		std::cout << "\nInsira o ID desejado para remover: ";
		//LEITURA DO ID COM RESTRIÇÃO
		do {
			std::getline(std::cin, idstr);

			try {
				id = stoi(idstr.c_str());
			} catch (...){
				id = -1;
			}

			if (id < 0) {
				std::cout << "Inválido. Insira o ID novamente: ";
			}

		} while (id < 0);
		//VERIFICA NO BANCO DE DADOS SE O CLIENTE EXISTE
		if(cf.idExiste(id)) {
			//REMOVE CLIENTE NO BANCO DE DADOS
			cf.removerFuncionario(id);
		} else {
			std::cout << "\nErro: ID não encontrado." << endl;
		}

		std::cout << "\nLISTA DE FUNCIONARIOS\n" << endl;
		cf.listarFuncionario();

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);
	} break;
	case 5: {
		std::cout << "\nLISTA DE FUNCIONARIOS\n" << endl;
		cf.listarFuncionario();
		std::string idstr;
		int id;
		std::cout << "\nInsira o ID desejado para alterar: ";
		//LEITURA DO ID COM RESTRIÇÃO
		do {
			std::getline(std::cin, idstr);

			try {
				id = stoi(idstr.c_str());
			} catch (...){
				id = -1;
			}

			if (id < 0) {
				std::cout << "Inválido. Insira o ID novamente: ";
			}

		} while (id < 0);

		//VERIFICA SE O CLIENTE EXISTE E INICIA A CAPTAÇÃO DOS NOVOS DADOS NO TECLADO
		if(cf.idExiste(id)) {
			
			std::string logradouro;
			do {
			std::cout << "Novo logradouro: ";
			std::getline(std::cin, logradouro);
			} while (verifica_dados_endereco(logradouro) != 1);


			std::string bairro;
			do {
			std::cout << "Novo bairro: ";
			std::getline(std::cin, bairro);
			} while (verifica_dados_endereco(bairro) != 1);


			std::cout << "Novo numero: ";
			int num;
			std::string numstr;


			//LEITURA DO NUMERO COM RESTRIÇÃO
			do {
				std::getline(std::cin, numstr);

				try {
					num = stoi(numstr.c_str());
				} catch (...){
					num = 0;
				}

				if (num <= 0) {
					std::cout << "Invalido. Insira o numero novamente: ";
				}

			} while (num <= 0);

			std::string cep;
			do {
			std::cout << "Novo CEP: ";
			std::getline(std::cin, cep);
			} while (verifica_cep(cep) != 1);

			std::cout << "Novo complemento: ";
			std::string comp;
			std::getline(std::cin, comp);

			std::string cidade;
			do {
			std::cout << "Nova cidade: ";
			std::getline(std::cin, cidade);
			} while (verifica_dados_endereco(cidade) != 1);


			//CRIA UM NOVO OBJETO CLIENTE
			Endereco *end = new Endereco(logradouro, bairro, cep, stoi(numstr.c_str()), comp, cidade);
			//ALTERA NO BANCO DE DADOS
			cf.alterarFuncionario(id, *end);

			std::cout << "\nLISTA DE FUNCIONARIOS\n" << endl;
			cf.listarFuncionario();
		} else {
			std::cout << "\nErro: ID não encontrado." << endl;
		}

		std::cout << "\nDigite qualquer caracter para voltar ao menu: ";
		std::getline(std::cin, strmenu);
	}break;
	case 6: {
		printf("\n\n");
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
		listarmenu();

		//LEITURA DO MENU COM RESTRIÇÃO
		std::cout << "Selecione uma seção: ";
		std::string strmenu;
		int menu;

		do {
			std::getline(std::cin, strmenu);

			try {
				menu = stoi(strmenu.c_str());
			} catch (...){
				menu = 0;
			}

			if (menu <= 0 || menu > 7) {
				std::cout << "Inválido. Selecione novamente: ";
			}

		} while (menu <= 0 || menu > 7);


		switch (menu) {
		case 1: {
			// VENDA
			printf("\n\n");
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
			printf("\n\n");
			crud_produto(*cv, *cc, *cf, *cp);
		}break;
		case 5: {
			//CRUD DE CLIENTE
			printf("\n\n");
			crud_cliente(*cv, *cc, *cf, *cp);

		} break;
		case 6: {
			//CRUD DE FUNCIONARIOS
			printf("\n\n");
			crud_funcionario(*cv, *cc, *cf, *cp);
		}break;
		case 7: {
			exit(0);
		} break;
		default: {

		}break;
		}

	}
	//LIBERAR MEMÓRIA DOS PONTEIROS
	free(cp);
	free(cv);
	free(cf);
	free(cc);

	return 0;
}




