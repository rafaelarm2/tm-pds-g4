/*
 * Cidade.h
 *
 *  Created on: 25 de nov de 2018
 *      Author: rafaelamoreira
 */

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
	std::string nome;
	Estado sgestado;
public:
	Cidade(std::string nome, Estado sgestado);
	Cidade();
	virtual ~Cidade();

	std::string getNome();
};

#endif /* CIDADE_H_ */
