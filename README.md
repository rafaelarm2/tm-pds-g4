# TRABALHO DE PROGRAMAÇAO E DESENVOLVIMENTO DE SOFTWARE - TM-PDS-G4

#	 		CONTROLE DE ESTOQUE

 	O programa trata-se de um controle de estoque e, para tal, registra as vendas de uma determinada empresa 
identificando, no processo, o cliente e o funcionario.
	As vendas são compostas de uma seleção de produtos e suas respectivas quantidades.
	Além disso, o programa gera dois relatórios:
		1. Entregas pendentes
		2. Entregas realizadas

Informações técnicas:
	O programa é composto de 29 arquivos, sendo que desses, 14 são classes e 1 é o banco de dados.
	Há polimorfismo em venda e venda com entrega, dessa forma, entrega herda de venda, então possui todos seus 
atributos e métodos e acrescenta-se o endereço, status de entrega e data de entrega.
	O status da entrega pode ser pendente ou realizada, assim, quando for alterado para "realizada", a data de
entrega é adicionada. 
	O relatório de entregas realizadas utiliza o id da venda para conseguir alterar seu status de pendente para realizada e sua data de entrega. Isso acarreta uma mudança no próprio banco de dados, pois é necessário utilizar a função de controlador.

## Utilizando o programa

//These instructions will get you a copy of the project up and running on your local machine for development and //testing purposes. See deployment for notes on how to deploy the project on a live system.


## Rodando os tests

Explain how to run the automated tests for this system

Explain what these tests test and why

```
Give an example
```

## Autores

* **André Fiuza Fonseca Camargos** 
* **Danilo Siqueira Santos** 
* **Rafaela Moreira Milagres**   