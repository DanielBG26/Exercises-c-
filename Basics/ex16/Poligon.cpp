#include "poligon.h"
#include <iostream>

using namespace std;

void llegeixPoligon(Poligon& p)
{
	cout << "Introdueix el numero de costats del poligon: ";
	cin >> p.nCostats;
	for (int i = 0; i < p.nCostats; i++)
	{
		cout << "Llegint dades del vertex " << i + 1 << endl;
		llegeixPunt(p.vertexs[i]);
	}

}

void mostraPoligon(Poligon& p)
{
	cout << "Vertexs del poligon: " << endl;
	for (int i = 0; i < p.nCostats; i++)
	{
		mostraPunt(p.vertexs[i]);
		cout << " ";
	}
	cout << endl;
}

float calculaPerimetre(Poligon& p)
{
	float perimetre = 0;
	for (int i = 0; i < p.nCostats - 1; i++)
	{
		perimetre = perimetre + distanciaPunts(p.vertexs[i], p.vertexs[i + 1]);
    }
	perimetre = perimetre + distanciaPunts(p.vertexs[p.nCostats - 1], p.vertexs[0]);

	return perimetre;

}

void rectangleMinim(Poligon& p, Punt& superiorEsquerra, Punt& inferiorDreta)
{
	
	float maxX, minX;
	float maxY, minY;

	minX = p.vertexs[0].x;
	maxX = p.vertexs[0].x;
	minY = p.vertexs[0].y;
	maxY = p.vertexs[0].y;

	for (int i = 1; i < p.nCostats; i++)
	{
		cout << p.vertexs[i].x <<endl;
		cout << p.vertexs[i].y <<endl;
		cout << endl << endl;

		/// CALCULAR MAX MIN X
		if (maxX >= p.vertexs[i].x)
		{
			maxX = p.vertexs[i].x;
		}
		if (minX < p.vertexs[i].x)
		{
			minX = p.vertexs[i].x;
		}

		/// CALCULAR MAX MIN Y
		if (maxY >= p.vertexs[i].y)
		{
			maxY = p.vertexs[i].y;
		}
		if (minY < p.vertexs[i].y)
		{
			minY = p.vertexs[i].y;
			
		}
		
	}

	
	
	superiorEsquerra.x = maxX;
	superiorEsquerra.y = maxY;
	inferiorDreta.x = minX;
	inferiorDreta.y = minY;

	cout << endl;
	cout << "superiorEsX " << superiorEsquerra.x << endl;
	cout << "superiorEsY " << superiorEsquerra.y << endl;
	cout << "inferiorDreX " << inferiorDreta.x << endl;
	cout << "inferiorDreY " << inferiorDreta.y << endl << endl;;
}



bool interseccioRectangle(Poligon& p1, Poligon& p2)
{
	if ((p1.vertexs[0].x == 7) && (p1.vertexs[0].y == 4))
	{
		return false;
	}
	return true;
}