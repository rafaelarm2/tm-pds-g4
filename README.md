# TRABALHO DE PROGRAMAÇAO E DESENVOLVIMENTO DE SOFTWARE - TM-PDS-G4

#	 		CONTROLE DE ESTOQUE
**Funcionamento:**

O programa trata-se de um controle de estoque e, para tal, registra as vendas de uma determinada empresa 
identificando, no processo, o cliente e o funcionario.
	
As vendas são compostas de uma seleção de produtos e suas respectivas quantidades.
	
Além disso, o programa gera dois relatórios:
* Entregas pendentes
* Entregas realizadas

**Informações técnicas:**

O programa foi desenvolvido em C++ e é composto de 30 arquivos, sendo que desses, 14 são classes e 1 é o banco de dados.
	
Há polimorfismo em venda e venda com entrega, dessa forma, entrega herda de venda, então possui todos seus 
atributos e métodos e acrescenta-se o endereço, status de entrega e data de entrega.
	
O status da entrega pode ser pendente ou realizada, assim, quando for alterado para "realizada", a data de
entrega é adicionada. 

O relatório de entregas realizadas utiliza o id da venda para conseguir alterar seu status de pendente para realizada e sua data de entrega. Isso acarreta uma mudança no próprio banco de dados, pois é necessário utilizar a função de controlador.


## Utilizando o programa

O programa funciona no terminal do compilador e para avançar pelo menu é necessário utilizar entradas do teclado. Todas as instruções necessárias para utilizar cada uma das funcionalidades é exibida na tela.


## Autores

* **André Fiuza Fonseca Camargos** 
* **Danilo Siqueira Santos** 
* **Rafaela Milagres Moreira**   
