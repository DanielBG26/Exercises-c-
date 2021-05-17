#include "domino.h"
#include <iostream>
using namespace std;

void mostraFitxa(Fitxa& fitxa)
{
	int valor1, valor2;
	valorsFitxa(fitxa, valor1, valor2);
	cout << "(" << valor1 << "," << valor2 << ") ";
}


void mostraFitxes(Fitxa fitxes[], int nFitxes)
{
	for (int i = 0; i < nFitxes; i++)
		mostraFitxa(fitxes[i]);
}

bool igualFitxa(Fitxa& fitxa1, Fitxa& fitxa2)
{
	int valorEsq1, valorDreta1, valorEsq2, valorDreta2;
	valorsFitxa(fitxa1, valorEsq1, valorDreta1);
	valorsFitxa(fitxa2, valorEsq2, valorDreta2);
	return (((valorEsq1 == valorEsq2) && (valorDreta1 == valorDreta2)) ||
		((valorEsq1 == valorDreta2) && (valorDreta1 == valorEsq2)));
}

float testDomino()
{
	float reduccio = 0.0;
	const int N_PROVES = 29;
	Fitxa resultatEsperat[N_PROVES] = { {0, 0}, {-1, -1}, {-1, -1}, {-1, -1}, {0, 1}, {1, 1}, {-1, -1}, {-1, -1}, {0, 2}, {1, 2}, {2, 3}, {3, 6}, {0, 6}, {2, 2}, {2, 4}, {4, 4}, {0, 3}, {1, 3}, {3, 4}, {-1, -1}, {-1, -1}, {1, 4}, {3, 3}, {4, 5}, {0, 5}, {-1, -1}, {3, 5}, {5, 5}, {0, 4} };
	Fitxa valorsPartidaEsperat[N_PROVES] = { {0,0},{ 0,0 },{ 0,0 },{ 0,0 }, {1, 0}, {1, 0},{ 1, 0 },{ 1, 0 }, {1, 2}, {2, 2}, {3, 2}, {6, 2}, {0, 2}, {0, 2}, {0, 4}, {0, 4}, {3, 4}, {1, 4}, {1, 3}, {1, 3}, {1, 3}, {4, 3}, {4, 3}, {5, 3}, {0, 3}, {0, 3}, {0, 5}, {0, 5}, {4, 5} };

	Fitxa fitxesInicials[MAX_JUGADORS * MAX_FITXES];
	int nFitxa = 0;
	for (int i = 0; i < 7; i++)
		for (int j = i; j < 7; j++)
		{
			inicialitzaFitxa(fitxesInicials[nFitxa], i, j);
			nFitxa++;
		}

	Partida partida;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Repartint fitxes inicials als jugadors i inicialitzant partida.... " << endl;
	cout << "Comment :=>> Valor de l'array fitxes inicials: ";
	cout << "Comment :=>>"; 
	mostraFitxes(fitxesInicials, MAX_FITXES* MAX_JUGADORS);
	cout << endl;
	inicialitzaPartida(partida, fitxesInicials);
	cout << "Comment :=>> ------------------------------------------------------------------" << endl;
	

	int jugadorEsperat = 1;
	for (int i = 0; i < N_PROVES; i++)
	{
		Fitxa fitxa;

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Seleccionant fitxa per tirar ..." << endl;
		cout << "Comment :=>> -------" << endl;
		cout << "Comment :=>> Jugador esperat que te el torn: " << jugadorEsperat << endl;
		cout << "Comment :=>> Fitxa seleccionada esperada: "; mostraFitxa(resultatEsperat[i]); cout << endl;
		cout << "Comment :=>> -------" << endl;
		int jugador = jugadorActual(partida);
		seleccionaFitxa(partida, fitxa);
		cout << "Comment :=>> Jugador que te el torn: " << jugador << endl;
		cout << "Comment :=>> Fitxa seleccionada obtinguda: "; mostraFitxa(fitxa); cout << endl;

		if ((jugadorEsperat == jugador) && igualFitxa(fitxa, resultatEsperat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		cout << "Comment :=>> --------------------" << endl;

		cout << "Comment :=>> Actualitzant valors de la partida ..." << endl;
		cout << "Comment :=>> -------" << endl;
		cout << "Comment :=>> Extrems de la partida esperats: "; mostraFitxa(valorsPartidaEsperat[i]); cout << endl;
		cout << "Comment :=>> -------" << endl;
		actualitzaPartida(partida, fitxa);
		int valorEsqObtingut = extremEsquerra(partida);
		int valorDretaObtingut = extremDret(partida);
		Fitxa valorsPartidaObtingut;
		inicialitzaFitxa(valorsPartidaObtingut, valorEsqObtingut, valorDretaObtingut);
		cout << "Comment :=>> Extrems de la partida obtinguts: "; mostraFitxa(valorsPartidaObtingut); cout << endl;

		int valorEsqEsperat, valorDretaEsperat;
		valorsFitxa(valorsPartidaEsperat[i], valorEsqEsperat, valorDretaEsperat);
		if ((valorEsqEsperat == valorEsqObtingut) && (valorDretaEsperat == valorDretaObtingut))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		jugadorEsperat = (jugadorEsperat % MAX_JUGADORS) + 1;
	}

	return reduccio;
}



int main()
{
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	cout << "Grade :=>> " << grade << endl;
	float reduccio = testDomino();
	grade = grade + (10 - reduccio);
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}