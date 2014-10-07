#ifndef INDUTOR_H
#define INDUTOR_H

#include <fstream>
#include <string>
#include "Elemento.h"

//C<nome> <n�1> <n�2> <Capacit�ncia>
class Indutor : public Elemento
{
	double m_L;
		
public:
	Indutor(std::ifstream &arq);

	//*****METODOS VIRTUAIS*****
	void associaMatriz(Matriz *matriz);
	void estampaPO();
	void estampaBE(double tempo, double passo);
	void estampaGEAR(double tempo, double passo);
	//void estampaTRAP(Matriz *matriz,);
};

#endif