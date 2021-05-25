#include <list>
using namespace std;

int MaxElsRec(list<int> &l, list<int>::iterator it) {
	int max = 0;
	if (it != l.end()) {
		int aux=*it;
		it++;
		max = MaxElsRec(l, it);
		if (max < aux) {
			max = aux;
		}
	}
	return max;
};

int MaxElementsLlista(list<int> &l)
{
	if (l.size()<=0) {
		return 0;
	}
	else {
		list<int>::iterator it = l.begin();
		return MaxElsRec(l, it);
	}
}