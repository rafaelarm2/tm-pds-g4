#ifndef ENDERECO_H_
#define ENDERECO_H_

#include <string>
#include "Endereco.h"

using namespace std;

class Endereco {
private:
	int id;
	std::string logradouro;
	std::string bairro;
	std::string cep;
	int num;
	std::string comp;
	std::string cidade;
public:
	Endereco(std::string logradouro, std::string bairro, std::string cep, int num,
			std::string comp, std::string cidade);
	Endereco();
	virtual ~Endereco();

//gets
	int getID();
	std::string getLogradouro();
	std::string getBairro();
	std::string getCep();
	int getNum();
	std::string getComp();
	std::string getCidade();

//sets
	void setID(int id_);
	void setLogradouro(std::string logradouro_);
	void setBairro(std::string bairro_);
	void setCep(std::string cep_);
	void setNum(int num_);
	void setComp(std::string comp_);
	void setCidade(std::string cidade_s);
};

#endif /* ENDERECO_H_ */
