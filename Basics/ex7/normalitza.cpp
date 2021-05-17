#include <iostream>
#include <math.h>
using namespace std;

void normalitzaValors(float vector[], int nValors)
{
	int max, min, res;

	/////CALCULAR VALOR MAXIMO ARRAY / VECTOR

	max = vector[0];
	
	for (int i = 0; i < 5; i++)
		if (vector[i] > max)
		{
		    max = vector[i];
	    }

    /////CALCULAR VALOR MINIMO ARRAY / VECTOR

	min = vector[0];

    for (int i = 0; i < 5; i++)
		if (vector[i] < min)
		{
			min = vector[i];
		}
    /// FORMULA 
	for (int i = 0; i < 5; i++)
	{
		vector[i] = ((vector[i] - min) / (max - min));
	}



}


