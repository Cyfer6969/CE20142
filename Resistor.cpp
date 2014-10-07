//Resistor.cpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Resistor.h"

using namespace std;

//Resistor: <nome> <n�1> <n�2> <Resist�ncia>
Resistor::Resistor(ifstream &arq)
{
	m_erro = false;
	int i = 0;
	while(arq.good() && arq.peek() != '\n')
	{
		//ignora espacos
		if(arq.peek() == ' ')
		{
			arq.ignore();
			continue;
		}
		switch(i)
		{
			case 0: arq >> m_nome;		break;
			case 1: arq >> m_nome_a;	break;
			case 2: arq >> m_nome_b;	break;
			case 3: arq >> m_R;			break;
			default:arq >> m_ignora;		break;
		}
		i++;
	}
	arq.ignore();
	if(i!=4)
	{
		cout<< m_nome <<": Numero de parametros errado " << i << "/4"<<endl;
		arq.close();
		m_erro = true;
	}

	cout<<m_nome<<": "<<m_nome_a<<" "<<m_nome_b<<" "<<m_R<<endl;
}

void Resistor::associaMatriz(Matriz *matriz)
{
	m_matriz = matriz;
	m_a = matriz->adVariavel(m_nome_a);
	m_b = matriz->adVariavel(m_nome_b);
}

void Resistor::estampaPO()
{
	estampaPrimR(m_a,m_b,m_R);
}

void Resistor::estampaBE(double tempo, double passo)
{
	estampaPrimR(m_a,m_b,m_R);
}

void Resistor::estampaGEAR(double tempo, double passo)
{
	estampaPrimR(m_a,m_b,m_R);
}
