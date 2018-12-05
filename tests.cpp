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
    Cliente new_client1("Kelly Oubre", "43518535811", "kellyoubre@dc.wiz", /*???*/, "33254819", "01/12/2018", /*???*/);
    CHECK(new_client1.getCpf() == 43518535811);
    CHECK(new_client1.getDtcadastro() == 01/12/2018);
    CHECK(new_client1.getNome() == "Kelly Oubre");
}

TEST_CASE("1.1 - Testando a validade dos dados de um cliente") {
    Cliente new_client1("Kelly Oubre", "43518535811", "kellyoubre@dc.wiz", /*???*/, "33254819", "01/12/2018", /*???*/);
    CHECK(validaCPF(new_client1.getCpf()) == true);
    CHECK(checa_data(new_client1.getDtcadastro()) == true);
}

//Cpf invalido
TEST_CASE("1.2 - Testando a incializacao incorreta de um cliente") {
    CHECK_THROWS(new Cliente("Jeff Green", "43518535817", "unclejeff@dc.wiz", /*???*/, "33254480", "01/12/2018", /*???*/);
}
//Formato de data invalido
TEST_CASE("1.3 - Testando a incializacao incorreta de um cliente") {
    CHECK_THROWS(new Cliente("Otto Porter", "72543568069", "HarryOtto@dc.wiz", /*???*/, "33148989", "07/13/2018", /*???*/);
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
