#include "Exercici.h"
#include <fstream>
#include <iostream>
using namespace std;


Exercici::Exercici(const Exercici& e)
{

	m_descripcio = e.m_descripcio;
	m_dataLimit = e.m_dataLimit;
	m_nEstudiants = e.m_nEstudiants;

	m_lliuraments = new LliuramentsEstudiant[e.m_nEstudiants];

	for (int i = 0; i < m_nEstudiants; i++) 
	{
		m_lliuraments[i] = e.m_lliuraments[i];
	}
}

Exercici::~Exercici() 
{
		delete[] m_lliuraments;
}

Exercici& Exercici::operator=(const Exercici& e) 
{
    m_descripcio = e.m_descripcio;
	m_dataLimit = e.m_dataLimit;
    m_nEstudiants = e.m_nEstudiants;
		
	m_lliuraments = new LliuramentsEstudiant[e.m_nEstudiants];

	for (int i = 0; i < m_nEstudiants; i++) 
	{
		m_lliuraments[i] = e.m_lliuraments[i];
	}
    
	return *this;
}

void Exercici::inicialitzaEstudiants(const string& fitxerEstudiants)
{
	string m_niu;

	ifstream fitxer(fitxerEstudiants);
	
	if (fitxer.is_open()) {
		fitxer >> m_nEstudiants;
		m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
		
		int i = 0;
		
		while (i < m_nEstudiants)
		{
			LliuramentsEstudiant nou;
			fitxer >> m_niu;
			nou.setNiu(m_niu);
			m_lliuraments[i] = nou; 
			i++;
		}
		fitxer.close();
	}
}


bool Exercici::afegeixTramesa(const string& niu, const string& fitxer, const string& data)
{
	bool trobat = false;
	bool existeix = false;
	int i = 0;
	
	while((i < m_nEstudiants) && (!existeix))
	{
		if (niu == m_lliuraments[i].getNiu()) 
		{
			existeix = true;
		}
		else 
		{
			i++;
		}
	}
	if (existeix)
	{
		trobat = true;
		m_lliuraments[i].afegeixTramesa(fitxer, data);
	}
	return trobat;
}

bool Exercici::consultaTramesa(const string& niu, const string& data, string& fitxer)
{
	bool existeix = false;
	int i = 0;

	
	while ((i < m_nEstudiants) && (!existeix))
	{
		if (niu == m_lliuraments[i].getNiu())
		{
			existeix = m_lliuraments[i].consultaTramesa(data, fitxer);
			i = m_nEstudiants;
		}
		else
		{
	    	i++;
		}
	}
	return existeix;
}

bool Exercici::eliminaTramesa(const string& niu, const string& data)
{
	bool trobat = 0;
	int i = 0;
	
	while ((i < m_nEstudiants) && (!trobat))
	{
		if (niu == m_lliuraments[i].getNiu())
		{
			trobat = m_lliuraments[i].eliminaTramesa(data);
			i = m_nEstudiants;
		}
		else 
		{
			i++;
		}
	}
	return trobat;
}


