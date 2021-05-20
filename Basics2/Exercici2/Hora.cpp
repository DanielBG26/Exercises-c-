#include "Hora.h"
#include <iostream>

using namespace std;

bool Hora::horaValida()
{
	bool valida = false;

	if ((((m_hora >= 0) && (m_hora < 24)) && ((m_minut >= 0) && (m_minut < 60))) && ((m_segon >= 0) && (m_segon < 60)))
	{
		valida = true;
	}

	return valida;
}

Hora Hora::operator+(int& segons) 
{
	Hora hora;
	hora.setHora(m_hora);
	hora.setMinuts(m_minut);
	hora.setSegons(m_segon);

	int cont = 0;
	int cont2 = 0;

	hora.setSegons(hora.getSegons() + segons);

	if (hora.getSegons() >= 60)
	{
		while (hora.getSegons() >= 60)
		{
			hora.setSegons(hora.getSegons() - 60);
			cont++;
		}
		
		hora.setMinuts(hora.getMinuts() + cont);
		if (hora.getMinuts() >= 60)
		{
			while (hora.getMinuts() >= 60)
			{
				hora.setMinuts(hora.getMinuts() - 60);
				cont2++;
			}
			hora.setHora(hora.getHora() + cont2);
			if (hora.getHora() >= 24)
			{
				hora.setHora(hora.getHora() - 24);
			}
		}

		
	}
	
	return hora;
}

Hora Hora::operator+(const Hora& hores)
{
	Hora hora2;
	hora2.setHora(m_hora);
	hora2.setMinuts(m_minut);
	hora2.setSegons(m_segon);

	hora2.setSegons(hora2.getSegons() + hores.getSegons());

	int cont = 0;
	int cont2 = 0;

	if (hora2.getSegons() >= 60)
	{
		hora2.setSegons(hora2.getSegons() - 60);
		cont++;
	}
	
	hora2.setMinuts((hora2.getMinuts() + hores.getMinuts()) + cont);

	if (hora2.getMinuts() >= 60)
	{
		hora2.setMinuts(hora2.getMinuts() - 60);
		cont2++;
	}

	hora2.setHora((hora2.getHora() + hores.getHora()) + cont2);

	return hora2;
}

bool Hora::operator==(const Hora& hores)
{
	bool igual = false;

	if (hores.m_segon == m_segon && hores.m_minut == m_minut && hores.m_hora && m_hora)
		igual = true;
	
	return igual;
}

bool Hora::operator<(const Hora& hores)
{
	bool petita = false;

	if (m_hora < hores.getHora()) 
	{
		petita = true;
	}
	else {
		if ((m_minut < hores.getMinuts()) && (m_hora == hores.getHora()))
		{
			petita = true;
		}
		else
		{
			if (((m_segon < hores.getSegons()) && (m_minut == hores.getMinuts())) && (m_hora == hores.getHora()))
			{
				petita = true;
			}
			else
			{
				petita = false;
			}
		}
	}
	return petita;
}

Hora Hora::operator=(const Hora& hora)
{
	Hora asign;
	asign.setHora(hora.getHora());
	asign.setMinuts(hora.getMinuts());
	asign.setSegons(hora.getSegons());

	return asign;
}