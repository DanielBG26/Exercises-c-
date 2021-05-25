#include <vector>
using namespace std;

int DividirArray(vector<int>& v,int indexInici,int indexFinal) {
	int pos=indexInici;
	int pivot = v[indexFinal];
	for (int i = indexInici-1; i < indexFinal;i++) {
		if (v[i+1] < pivot) {				
			if (pos != i+1) {
				int aux = v[pos];
				v[pos] = v[i+1];
				v[i+1] = aux;
			}
			pos++;
		}
	}
	int aux = v[indexFinal];
	v[indexFinal] = v[pos];
	v[pos] = aux;
	return pos;
}

void quicksort(vector<int>& v, int indexInici, int indexFinal)
{
	if (indexInici < indexFinal) {
		int PosPivot = DividirArray(v,indexInici,indexFinal);
		quicksort(v,indexInici,PosPivot-1);
		quicksort(v, PosPivot+1, indexFinal);
	}
}
