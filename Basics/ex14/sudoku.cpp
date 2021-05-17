
/*
L’algorisme ha de començar a partir d’un Sudoku inicial que es passa com a paràmetre a la funció principal de l’algorisme. 

Durant la partida, a cada moviment se li demanarà al jugador que introdueixi un número del 1 al 9 i la casella (fila i columna) on el vol posar (també valors entre 1 i 9). 

L’algorisme haurà de comprovar que la casella no estigui ja ocupada i que sigui vàlid posar el número a la casella indicada segons les regles del joc. 

Si es compleixen aquestes condicions, l’hi posarà. Si no, es mostrarà per pantalla un missatge d’error. Després de cada moviment es mostrarà l'estat actual del Sudoku. 
La partida s’acabarà quan s’hagin omplert totes les caselles del Sudoku o quan el jugador indiqui que vol acabar, introduint un 0 quan se li demana el número a posar.

Quan s’acabi la partida, la funció principal del joc retornarà el nº de moviments que s’han intentat (siguin vàlids o no) i un array de valors lògics indicant, 
per cada moviment intentat, si és vàlid o no.

*/


#include <iostream>
#include "sudoku.h"

using namespace std;

bool jugaSudoku(int tauler[N_FILES][N_COLUMNES], int nLliures, bool resultat[], int& nMoviments)
{
	int numero;
	int fila, columna;
	int filaIni, columnaIni;
	int filaFin, columnaFin;
	//int mirando =0; // variable para saber si se ha completado el cuadrado correspondiente y no se ha encontrado numero repetido
	nMoviments = 0; // variable que cuenta el numero de acciones hechas
	//int CC = 0; // comprueba si hay mas 0s en el cuadrado
	//int CCol = 0;

	if (nLliures != 0) 
	{

		
			for (int i = 0; i < 13;i++)
			{
				// ESCRIURE NUMERO, FILA, COLUMNA...... FALTA QUE SI ES = 0, SORTIR

				cin >> numero;
				cout << endl;
				
				int mirando = 0;
				int CC = 0;
				int CCol = 9;

	

				if (numero != 0)
				{
					nMoviments++;
					cin >> fila;
					cout << endl;
					cout << "EL NUMERO ES " << numero << endl;
					cout << "LA FILA ES " << fila << endl;
					cin >> columna;
					cout << "LA COLUMNA ES " << columna << endl;
					fila = fila - 1;
					columna = columna - 1;

					//MIRAR SI ESTA OCUPADA O NO LA CASELLA, Y VEURE SI ES VALIDA

					if (tauler[fila][columna] == 0) // no esta ocupada si es 0 y per tant miro el cuadrat que esta
					{
						filaIni = ((fila / 3) * 3);   /// exemple fila 5  ----> 5/3= 1r cuadrant x 3 = 3,   3 es la Fila inicial del cuadrat
						columnaIni = ((columna / 3) * 3);

						filaFin = filaIni + 3;
						columnaFin = columnaIni + 3;

						for (int s = filaIni; s < filaFin; s++)
						{
							for (int r =columnaIni; r < columnaFin; r++) 
							{
								
								if ((tauler[s][r] == numero))
								{
									resultat[i] = false;
									
								}
								if (((tauler[s][r] != numero)))
								{
									mirando++;
									cout << "MIRANDO " << mirando << endl;
								}
								if (tauler[s][r] == 0) //para comprobar si hay  mas 0s en el cuadrado
								{
									CC++;
									
								}
								
								
							}
							
						}
					}
					else {
						resultat[i] = false;
					}
					
					if (CC > 1) //para comprobar columnas
					{
						//cout << "CC " << CC << endl;
						CCol = 0;
						for (int R=0; R < 9; R++)
							
						{
							
							cout << tauler[R][columna] << endl;

							if (tauler[R][columna] == numero)
							{

								resultat[R] = false;

							}
							if (((tauler[R][columna] != numero)))
							{
								CCol++;
								cout << "MIRANDO columnas " << CCol << endl;
								
							}
						}
					}
					cout << "CCol " << CCol << endl;
					if ((mirando == 9) && (CCol == 9))
					{
						resultat[i] = true;
						tauler[fila][columna] = numero;
						
					}
					


					//DESPRES DE QUE VEIEM SI ES O NO VALID, NEM MIRANT EL NUMERO DE MOVIMENTS QUE FEM, I EN CAS QUE SIGUI VALID RESTEM A NLLIURES -1;



					if (resultat[i] == true)
					{
						nLliures--;
					}
				}
				else { return 0; }
        }
	}
	
	//dibuixar 

	for (int i = 0; i < 9; i++) {
		cout << tauler[0][i];
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << tauler[1][i];
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << tauler[2][i];
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << tauler[3][i];
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << tauler[4][i];
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << tauler[5][i];
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << tauler[6][i];
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << tauler[7][i];
	}
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << tauler[8][i];
	}
	cout << endl;
	
// HEM DE RETORNAR EL N_DE_MOVIMENTS I L'ARRAY RESULTAT(VALID/NO VALID)
	
	return resultat;
}