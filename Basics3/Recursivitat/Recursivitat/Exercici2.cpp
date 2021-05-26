#include <vector>
using namespace std;

int posicioMinim(vector<int> v, int indexInici, int indexFinal) {
	int minim = indexInici;
	
	for (int i = indexInici; i < indexFinal; i++) {
		if (v[i+1] < v[minim]) {
			minim = i+1;
		}
	}
	return minim;
}

void ordenaArray(vector<int>& v, int indexInici, int indexFinal)
{
	if (indexInici < indexFinal) {
		int minim = posicioMinim(v, indexInici, indexFinal);
		int aux = v[indexInici];
		
		v[indexInici] = v[minim];
		v[minim] = aux;
		ordenaArray(v, indexInici+1, indexFinal);
	}
}