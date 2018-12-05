#include "Endereco.h"
#include <string>

using namespace std;

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

Endereco::Endereco(std::string logradouro, std::string bairro, std::string cep, // @suppress("Class members should be properly initialized")
		int num, std::string comp, std::string cidade) {
	// TODO Auto-generated constructor stub
	if(verifica_dados_endereco(logradouro) == 1)
		this->logradouro = logradouro;
	else 
		throw InsercaoDeDadosIncorreta();
	
	if(verifica_dados_endereco(bairro) == 1)
		this->bairro = bairro;
	else 
		throw InsercaoDeDadosIncorreta();
	
	if(verifica_dados_endereco(cidade) == 1)
		this->cidade = cidade;
	else 
		throw InsercaoDeDadosIncorreta();
	
	if(verifica_cep(cep) == 1)
		this->cep = cep;
	else 
		throw InsercaoDeDadosIncorreta();
	
	this->num = num;
	this->comp = comp;
}

Endereco::Endereco() { // @suppress("Class members should be properly initialized")

}

Endereco::~Endereco() {
	// TODO Auto-generated destructor stub
}

std::string Endereco::getCidade() {
	return this->cidade;
}

std::string Endereco::getLogradouro() {
	return this->logradouro;
}

std::string Endereco::getBairro() {
	return this->bairro;
}

std::string Endereco::getCep() {
	return this->cep;
}

int Endereco::getNum() {
	return this->num;
}

std::string Endereco::getComp() {
	return this->comp;
}

