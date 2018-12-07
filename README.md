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

**A respeito das classes:**

Foram criadas classes que representam indivíduos: 

Pessoa, que possui atributos que são dados pessoais comuns. Tal classe é herdada por Cliente e por Funcionário, sendo que a diferença entre elas é que a primeira possui uma data de cadastro e o seu tipo (classificação de nível do cliente) e a segunda, possui informações relativas à contratação de funcionário.

Existem, também, as classes que estão relacionadas aos produtos da empresa:

Produto, que possui informações gerais de um determinado produto. Item, que tem Produto e mais algumas características que são utilizadas para a venda.

Outro quesito essencial é o que tange às vendas:

Venda, tem Item, Cliente e Funcionário, sendo uma das principais classes, pois é a que realiza as vendas na empresa. VendaEntrega herda de Venda e acrescenta-se as especificidades de uma entrega, como Endereço, data de entrega e status da encomenda.

As classes controladoras intermediam o contato com o banco de dados, para que as informações sajam lidas, salvas ou removidas.


## Utilizando o programa

O programa funciona no terminal do compilador e para avançar pelo menu é necessário utilizar entradas do teclado. Todas as instruções necessárias para utilizar cada uma das funcionalidades é exibida na tela.


## Autores

* **André Fiuza Fonseca Camargos** 
* **Danilo Siqueira Santos** 
* **Rafaela Milagres Moreira**   
