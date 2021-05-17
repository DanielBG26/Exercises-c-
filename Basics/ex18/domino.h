#ifndef DOMINO_H
#define DOMINO_H

const int MAX_FITXES = 7;
const int MAX_JUGADORS = 4;

typedef struct
{
	int valor1;
	int valor2;

} Fitxa;

typedef struct
{
	Fitxa fitxes[MAX_FITXES];
	int nFitxes;

} Jugador;

typedef struct
{
	Jugador jugadors[MAX_JUGADORS];
	int valorEsq, valorDreta;
	int jugadorActual;

} Partida;

void inicialitzaFitxa(Fitxa& fitxa, int valor1, int valor2);
void valorsFitxa(Fitxa& fitxa, int& valor1, int& valor2);
int jugadorActual(Partida& partida);
int extremEsquerra(Partida& partida);
int extremDret(Partida& partida);
int nFitxesJugador(Jugador& jugador);
void inicialitzaPartida(Partida& partida, Fitxa fitxesInicials[]);
void seleccionaFitxa(Partida& partida, Fitxa& fitxa);
void actualitzaPartida(Partida& partida, Fitxa& fitxa);

#endif

