#ifndef CIDADE_H_
#define CIDADE_H_

#include <string>

using namespace std;

enum Estado {
	AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE, PI, RJ, RN, RS, RO, RR, SC, SP, SE, TO
};

class Cidade {
private:
	static int id;
	string nome;
	Estado sgestado;
public:
	Cidade(string nome, Estado sgestado);
	Cidade();
	virtual ~Cidade();

	string getNome();
	int getID();
	Estado getEstado();

	void setNome(string nome_);
	void setID(int id_);
	void setEstado(Estado state);

#endif /* CIDADE_H_ */
