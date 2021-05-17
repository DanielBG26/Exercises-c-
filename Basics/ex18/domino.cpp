#include "domino.h"
#include <iostream>

using namespace std;
int torn = 1;
int extremE = -2;
int extremD = -2;
int prueba = 0;
int PF = 0;


void inicialitzaFitxa(Fitxa& fitxa, int valor1, int valor2)
{
	fitxa.valor1 = valor1;
	fitxa.valor2 = valor2;
}

void valorsFitxa(Fitxa& fitxa, int& valor1, int& valor2)
{
	valor1 = fitxa.valor1;
	valor2 = fitxa.valor2;
}

int jugadorActual(Partida& partida)
{
	
	if (torn > 4)
	{
		torn = 1;
	}

	partida.jugadorActual = torn;

	return partida.jugadorActual;
	
}

int extremEsquerra(Partida& partida)
{
	partida.valorEsq = extremE;
	return partida.valorEsq;
}

int extremDret(Partida& partida)
{
	
	partida.valorDreta = extremD;
	return partida.valorDreta;
}

int nFitxesJugador(Jugador& jugador)
{
	
	return jugador.nFitxes;
}


void inicialitzaPartida(Partida& partida, Fitxa fitxesInicials[])
{
	//cout << "PROBANDO INICIALITZA PARTIDA PRUEBAAAAS " << endl << endl;
	int Total = 0;
		for (int J = 0; J < MAX_JUGADORS; J++)
		{
			//cout << "JUGADOR " << J + 1 << endl;
			for (int P = 0; P < MAX_FITXES; P++)
			{
				
				partida.jugadors[J].fitxes[P].valor1 = fitxesInicials[Total].valor1;
				partida.jugadors[J].fitxes[P].valor2 = fitxesInicials[Total].valor2;

				//cout << partida.jugadors[J].fitxes[P].valor1 << ",";
				//cout << partida.jugadors[J].fitxes[P].valor2 << endl;
				Total++;
			}
		}

		
		

}

void actualitzaPartida(Partida& partida, Fitxa& fitxa)
{
	
}

void seleccionaFitxa(Partida& partida, Fitxa& fitxa)
{
	torn++;
	bool trobat = false;

	if (partida.jugadorActual == 1)
	{
		if (((extremE == -2) && (extremD == -2)) &&( PF ==0)) //significa que encara no hi ha peçes posades
		{
			fitxa.valor1 = partida.jugadors[0].fitxes[0].valor1; // aqui fiquem els valors de la ficha utilitzada
			fitxa.valor2 = partida.jugadors[0].fitxes[0].valor1;

			extremE = partida.jugadors[0].fitxes[0].valor1; // aqui guardem els extrems
			extremD = partida.jugadors[0].fitxes[0].valor1;

			partida.jugadors[0].fitxes[0].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
			partida.jugadors[0].fitxes[0].valor2 = -10; /// -10 sera que ja ha utilitzat i no el pot tornar a tirar

			trobat = true;

		}
		if (PF == 1)
		{
			for (int R = 0; R < 7; R++)
			{
				if ((extremE == partida.jugadors[0].fitxes[R].valor1) && (trobat != true))
				{
					fitxa.valor1 = partida.jugadors[0].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
					fitxa.valor2 = partida.jugadors[0].fitxes[R].valor2;

					extremE = partida.jugadors[0].fitxes[R].valor2; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


					partida.jugadors[0].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
					partida.jugadors[0].fitxes[R].valor2 = -10;

					trobat = true;
				}
				if ((extremD == partida.jugadors[0].fitxes[R].valor2) && (trobat != true))
				{
					fitxa.valor1 = partida.jugadors[0].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
					fitxa.valor2 = partida.jugadors[0].fitxes[R].valor2;

					extremD = partida.jugadors[0].fitxes[R].valor1; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


					partida.jugadors[0].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
					partida.jugadors[0].fitxes[R].valor2 = -10;

					trobat = true;
				}
				if ((extremE == partida.jugadors[0].fitxes[R].valor2) && (trobat != true))
				{
					fitxa.valor1 = partida.jugadors[0].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
					fitxa.valor2 = partida.jugadors[0].fitxes[R].valor2;

					extremE = partida.jugadors[0].fitxes[R].valor1; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


					partida.jugadors[0].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
					partida.jugadors[0].fitxes[R].valor2 = -10;

					trobat = true;
				}
				if ((extremD == partida.jugadors[0].fitxes[R].valor1) && (trobat != true))
				{
					fitxa.valor1 = partida.jugadors[0].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
					fitxa.valor2 = partida.jugadors[0].fitxes[R].valor2;

					extremD = partida.jugadors[0].fitxes[R].valor2; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


					partida.jugadors[0].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
					partida.jugadors[0].fitxes[R].valor2 = -10;

					trobat = true;
				}
				

			}
		}
		PF = 1;
		if (trobat == false)
		{
			fitxa.valor1 = -1;
			fitxa.valor2 = -1;
		}

		cout << "HOLAAAA SOY EL JUGADOR 1" << endl;
		cout << "Mis fichas son: " << endl << endl;
		for (int R = 0; R < 7; R++)
		{

			cout << "(";
			cout << partida.jugadors[0].fitxes[R].valor1;
			cout << ",";
			cout << partida.jugadors[0].fitxes[R].valor2;
			cout << ")";

		}
		cout << endl << endl;
	}



	if (partida.jugadorActual == 2)
	{
		
		for (int R = 0; R < 7; R++)
		{
			if ((extremE == partida.jugadors[1].fitxes[R].valor1) && (trobat != true))
			{
				fitxa.valor1 = partida.jugadors[1].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[1].fitxes[R].valor2;

				extremE = partida.jugadors[1].fitxes[R].valor2; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta
				

				partida.jugadors[1].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[1].fitxes[R].valor2 = -10;

				trobat = true;
			}
			if ((extremD == partida.jugadors[1].fitxes[R].valor2) && (trobat != true))
				{
				fitxa.valor1 = partida.jugadors[1].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[1].fitxes[R].valor2;

				extremD = partida.jugadors[1].fitxes[R].valor1; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


				partida.jugadors[1].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[1].fitxes[R].valor2 = -10;

				trobat = true;
				}
			if ((extremE == partida.jugadors[1].fitxes[R].valor2) && (trobat != true))
			{
				fitxa.valor1 = partida.jugadors[1].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[1].fitxes[R].valor2;

				extremE = partida.jugadors[1].fitxes[R].valor1; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


				partida.jugadors[1].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[1].fitxes[R].valor2 = -10;

				trobat = true;
			}
			if ((extremD == partida.jugadors[1].fitxes[R].valor1) && (trobat != true))
			{
				fitxa.valor1 = partida.jugadors[1].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[1].fitxes[R].valor2;

				extremD = partida.jugadors[1].fitxes[R].valor2; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


				partida.jugadors[1].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[1].fitxes[R].valor2 = -10;

				trobat = true;
			}
				
				//fitxa.valor1 = -1;
				//fitxa.valor2 = -1;
				

		}
		if (trobat == false)
		{
			fitxa.valor1 = -1;
			fitxa.valor2 = -1;
		}
		cout << "HOLAAAA SOY EL JUGADOR 2" << endl;
		cout << "Mis fichas son: " << endl << endl;
		for (int R = 0; R < 7; R++)
		{

			cout << "(";
			cout << partida.jugadors[1].fitxes[R].valor1;
			cout << ",";
			cout << partida.jugadors[1].fitxes[R].valor2;
			cout << ")";

		}
		cout << endl << endl;
		cout << endl << endl;
	}
	if (partida.jugadorActual == 3)
	{
		for (int R = 0; R < 7; R++)
		{
			if ((extremE == partida.jugadors[2].fitxes[R].valor1) && (trobat != true))
			{
				fitxa.valor1 = partida.jugadors[2].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[2].fitxes[R].valor2;

				extremE = partida.jugadors[2].fitxes[R].valor2; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


				partida.jugadors[2].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[2].fitxes[R].valor2 = -10;

				trobat = true;
			}
			if ((extremD == partida.jugadors[2].fitxes[R].valor2) && (trobat != true))
			{
				fitxa.valor1 = partida.jugadors[2].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[2].fitxes[R].valor2;

				extremD = partida.jugadors[2].fitxes[R].valor1; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


				partida.jugadors[2].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[2].fitxes[R].valor2 = -10;

				trobat = true;
			}
			if ((extremE == partida.jugadors[2].fitxes[R].valor2) && (trobat != true))
			{
				fitxa.valor1 = partida.jugadors[2].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[2].fitxes[R].valor2;

				extremE = partida.jugadors[2].fitxes[R].valor1; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


				partida.jugadors[2].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[2].fitxes[R].valor2 = -10;

				trobat = true;
			}
			if ((extremD == partida.jugadors[2].fitxes[R].valor1) && (trobat != true))
			{
				fitxa.valor1 = partida.jugadors[2].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[2].fitxes[R].valor2;

				extremD = partida.jugadors[2].fitxes[R].valor2; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


				partida.jugadors[2].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[2].fitxes[R].valor2 = -10;

				trobat = true;
			}

		}
		if (trobat == false)
		{
			fitxa.valor1 = -1;
			fitxa.valor2 = -1;
		}
		cout << endl << endl;
	}
	if (partida.jugadorActual == 4)
	{
		for (int R = 0; R < 7; R++)
		{
			if ((extremE == partida.jugadors[3].fitxes[R].valor1) && (trobat != true))
			{
				fitxa.valor1 = partida.jugadors[3].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[3].fitxes[R].valor2;

				extremE = partida.jugadors[3].fitxes[R].valor2; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


				partida.jugadors[3].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[3].fitxes[R].valor2 = -10;

				trobat = true;
			}
			if ((extremD == partida.jugadors[3].fitxes[R].valor2) && (trobat != true))
			{
				fitxa.valor1 = partida.jugadors[3].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[3].fitxes[R].valor2;

				extremD = partida.jugadors[3].fitxes[R].valor1; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


				partida.jugadors[3].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[3].fitxes[R].valor2 = -10;

				trobat = true;
			}
			if ((extremE == partida.jugadors[3].fitxes[R].valor2) && (trobat != true))
			{
				fitxa.valor1 = partida.jugadors[3].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[3].fitxes[R].valor2;

				extremE = partida.jugadors[3].fitxes[R].valor1; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


				partida.jugadors[3].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[3].fitxes[R].valor2 = -10;

				trobat = true;
			}
			if ((extremD == partida.jugadors[3].fitxes[R].valor1) && (trobat != true))
			{
				fitxa.valor1 = partida.jugadors[3].fitxes[R].valor1; // aqui fiquem els valors de la ficha utilitzada
				fitxa.valor2 = partida.jugadors[3].fitxes[R].valor2;

				extremD = partida.jugadors[3].fitxes[R].valor2; // aqui guardem el extrem perque l'altre ja el tenim, guardem el valor 2, perque el 1 es el que junta


				partida.jugadors[3].fitxes[R].valor1 = -10;  /// -10 sera que ja ha utilitzat i no el pot tornar a tirar
				partida.jugadors[3].fitxes[R].valor2 = -10;

				trobat = true;
			}

		}
		if (trobat == false)
		{
			fitxa.valor1 = -1;
			fitxa.valor2 = -1;
		}
		cout << endl << endl;
	}
}
