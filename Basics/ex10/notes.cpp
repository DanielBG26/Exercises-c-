#include <iostream>
#include "notes.h"

using namespace std;

float calculaNota(float teoria, float problemes, float practiques, char& acta)
{
	float notaFinal = 0.0;
	
	if ((((teoria < 11) && (teoria >= 0)) || ((problemes < 11) && (problemes >= 0))) || ((practiques < 11) && (practiques >= 0)))
	{
		notaFinal = (0.4 * teoria) + (0.3 * problemes) + (0.3 * practiques);
	}
	if(((teoria == -1) || (problemes == -1)) || (practiques == -1))
	{
		notaFinal = -1;
		acta = 'P';
	}
	
	if ((notaFinal >= 0) && (notaFinal < 5))
	{
		acta = 'S';
	}
	if ((notaFinal >= 5) && (notaFinal < 7))
	{
		acta = 'A';
	}
	if ((notaFinal >= 7) && (notaFinal < 9))
	{
		acta = 'N';
	}
	if ((notaFinal >= 9) && (notaFinal < 10))
	{
		acta = 'E';
	}
	if (notaFinal == 10)
	{
		acta = 'M';
	}


	return notaFinal;


}

int calculaNotes(float notesFinals[], char notesActa[])
{
	float teoria, problemes, practiques;
	char continuar = ' ';
	int n_Estudiants = 0;
	int i = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> teoria;
		cout << endl;
		cin >> problemes;
		cout << endl;
		cin >> practiques;
		cout << endl;
		cin >> continuar;

		//cout << teoria << "    " << problemes << "      " << practiques << "       " << continuar << endl;

		notesFinals[i]= calculaNota(teoria, problemes, practiques, continuar);
		notesActa[i] = continuar;
		n_Estudiants++;
		

	}
	return n_Estudiants;
}


