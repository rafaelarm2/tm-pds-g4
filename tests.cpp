#include "doctest.h"
#include "Cliente.h"
#include "ControladorCliente.h"
#include "ControladorProduto.h"
#include "Endereco.h"
#include "Funcionario.h"
#include "Item.h"
#include "Pessoa.h"
#include "Produto.h"
#include "Venda.h"
#include "VendaEntrega.h"

TEST_CASE("01 - Testando a incializacao de um cliente pelo construtor") {
    /*
    Endereco(std::string logradouro, std::string bairro, std::string cep, int num,
			std::string comp, std::string cidade);
    */
    Endereco end_client1("Rua dos Caetes", "Bairro Jardim Canada", "30421546", 493, "Sem complemento", "Belo Horizonte");
    Cliente new_client1("Kelly Oubre", "43518535811", "kellyoubre@dc.wiz", end_client1, "33254819", "01/12/2018", "ouro");
    CHECK(new_client1.getCpf() == 43518535811);
    CHECK(new_client1.getDtcadastro() == 01/12/2018);
    CHECK(new_client1.getNome() == "Kelly Oubre");
}

TEST_CASE("1.1 - Testando a validade dos dados de um cliente") {
    Endereco end_client1("Rua dos Caetes", "Bairro Jardim Canada", "30421546", 493, "Sem complemento", "Belo Horizonte");
    Cliente new_client1("Kelly Oubre", "43518535811", "kellyoubre@dc.wiz", end_client1, "33254819", "01/12/2018", "ouro");
    CHECK(validaCPF(new_client1.getCpf()) == true);
    CHECK(checa_data(new_client1.getDtcadastro()) == true);
}

//Cpf invalido
TEST_CASE("1.2 - Testando a incializacao incorreta de um cliente") {
    Endereco end_client2("Rua Quinze de Novembro", "Bairro Prado", "37511546", 555, "Sem complemento", "Belo Horizonte");
    CHECK_THROWS(new Cliente("Jeff Green", "43518535817", "unclejeff@dc.wiz", end_client2, "33254480", "01/12/2018", "prata");
}
//Formato de data invalido
TEST_CASE("1.3 - Testando a incializacao incorreta de um cliente") {
    Endereco end_client3("Rua dos Otoni", "Bairro Grajau", "54125963", 26, "Sem complemento", "Belo Horizonte");
    CHECK_THROWS(new Cliente("Otto Porter", "72543568069", "HarryOtto@dc.wiz", end_client3, "33148989", "07/13/2018", "bronze");
}

                 
TEST_CASE("02 - Testando o registro dos dados do endereco pelo construtor") {
    Endereco end1("Rua das Flores", "Campos Rosados", "30421379", 574, "Sem complemento", "Miami");
    CHECK(end1.getLogradouro() == "Rua das Flores");
    CHECK(end1.getBairro() == "Campos Rosados");
    CHECK(end1.getCep() == 30421379);
    CHECK(end1.getCidade() == "Miami");
}

//Cep com digitos insuficientes
TEST_CASE("2.1 - Testando a validade dos dados de um endereco") {
    CHECK_THROWS(new Endereco("Avenida Brasil", "Bairro America do Sul", "3254", 1295, "Sem complemento", "Sao Carlos"));
}    

//Rua composta de numeros
TEST_CASE("2.2 - Testando a validade dos dados de um endereco") {
    CHECK_THROWS(new Endereco("1665465", "Bairro Europa Ocidental", "30250460", 51, "Sem complemento", "Nova Savassi"));
}    

//Numero indicado por letras
TEST_CASE("2.3 - Testando a validade dos dados de um endereco") {
    CHECK_THROWS(new Endereco("Rua do Ouro", "Bairro Guaporel", "65984567", num, "Sem complemento", "Oakland"));
}    

/*
Funcionario::Funcionario(std::string nome, std::string cpf, std::string email, Endereco endereco, 
std::string tel, std::string dtadmissao):
*/
                 
                 
TEST_CASE("03 - Testando a incializacao de um funcionario pelo construtor") {
    Endereco end_func1("Rua dos Caetes", "Bairro Jardim Canada", "30421546", 493, "Sem complemento", "Belo Horizonte");
    Cliente new_funcionario1("Jimmy Butler", "63680134002", "jimmygbuckets@sixers.ph", end_func1, "25769898", "05/12/2018");
    CHECK(new_funcionario1.getCpf() == 63680134002);
    CHECK(new_funcionario1.getDtcadastro() == 05/12/2018);
    CHECK(new_funcionario1.getNome() == "Jimmy Butler");
}

TEST_CASE("3.1 - Testando a validade dos dados de um funcionario") {
    Endereco end_func1("Rua dos Caetes", "Bairro Jardim Canada", "30421546", 493, "Sem complemento", "Belo Horizonte");
    Cliente new_funcionario1("Jimmy Butler", "63680134002", "jimmiygbuckets@sixers.ph", end_func1, "25769898", "05/12/2018");
    CHECK(validaCPF(new_funcionario1.getCpf()) == true);
    CHECK(checa_data(new_funcionario1.getDtcadastro()) == true);
}

//Cpf invalido
TEST_CASE("3.2 - Testando a incializacao incorreta de um funcionario") {
    Endereco end_func2("Rua Quinze de Novembro", "Bairro Prado", "37511546", 555, "Sem complemento", "Belo Horizonte");
    CHECK_THROWS(new Funcionario("Ben Simmons", "26713481025", "bentreysimmons@sixers.ph", end_func2, "31457676", "05/12/2018");
}
//Formato de data invalido
TEST_CASE("3.3 - Testando a incializacao incorreta de um funcionario") {
    Endereco end_func3("Rua dos Otoni", "Bairro Grajau", "54125963", 26, "Sem complemento", "Belo Horizonte");
    CHECK_THROWS(new Funcionario("Joel Embiid", "61435981006", "Jojotheprocess@sixers.ph", end_func3, "21000376", "30/02/2018");
}
                 
