/* Feu una funció que calculi xn utilitzant només multiplicacions. 
La funció ha de rebre com a paràmetres els valors de x i n i ha de retornar el valor de xn.
Tingueu en compte també el cas en què lexponent sigui negatiu.

Feu també el programa principal que llegeix per teclat els valors de x i n i mostra per pantalla el resultat de cridar a la funció anterior*/

#include <iostream>

using namespace std;

int main()
{
	double x, n;
	double resultat = 1.0;

	cout << "x: ";
	cin >> x;

	cout << endl;

	cout << "n: ";
	cin >> n;
	
	if (n >= 0)
	{
		for (int i = 0; i < n; i++)
		{
			resultat = resultat * x;
		}

		cout << resultat << endl;
	}
	if (n < 0)
	{
	    n = n *(-1);
	    
		for (int i = 0; i < n; i++)
		{
				resultat = (resultat * x);
	
		}

			cout << 1/resultat << endl;
	}
	

	return 0;
}