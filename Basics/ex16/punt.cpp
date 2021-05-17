#include "punt.h"
#include <iostream>
#include <math.h>

using namespace std;

void llegeixPunt(Punt& p)
{
	//cout << "Escriu coordenadaaaa X: ";
	cin >> p.x;
	cout << endl;
	//cout << "Escriu coordenadaaaa Y: ";
	cin >> p.y;
}

void mostraPunt(Punt & p)
{
	cout << "Coordenada X = " << p.x << " y la Coordenada Y = " << p.y << endl;
}

float distanciaPunts(Punt &p1, Punt &p2)
{
	float dx = p1.x - p2.x;
	float dy = p1.y - p2.y;
	return sqrt(dx * dx + dy * dy);

}
