#pragma once
#include <stdlib.h>
#include <iostream>
#include <utility>
#include "TreeRB.hpp"
using namespace std;



template<class TClau, class TValor>
class PairMap
{
public:
	TClau first;
	TValor second;
	PairMap() { first = TClau(); second = TValor(); };
	PairMap(TClau primer, TValor segon) { first = primer; second = segon; };
	bool operator<(PairMap<TClau, TValor> valor) const { return (first < valor.first); };
	bool operator==(PairMap<TClau, TValor> valor) const { return (first == valor.first); };
	friend ostream& operator<<(ostream& out, PairMap<TClau, TValor> valor)
	{
		out << "<" << valor.first << ", " << valor.second << ">";
		return out;
	};
};



template<class TClau, class TValor>
class Map
{
public:
	Map() {
		tRB=new TreeRB<PairMap<TClau, TValor>>;
	};
	Map(const Map& m) {
		ClauDef = m.ClauDef;
		p = m.p;
		tRB = m.tRB;
	};
	~Map() {};
	bool esBuit() const {
		return tRB->isEmpty();
	};
	TValor& operator[](const TClau& clau) {
		PairMap<TClau, TValor> aux = PairMap<TClau, TValor>(clau, TValor());
		bool trobat = tRB->cerca(aux, actual);
		if (trobat) {
			return actual->getData().second;
		}
		else {
			p = TValor();
			return p;
		}
	};
	void afegeix(const TClau& clau, const TValor& valor) {
		PairMap<TClau, TValor> aux = PairMap<TClau, TValor>(clau, valor);
		bool trobat = tRB->cerca(aux, actual);
		if (trobat) {
			actual->setVal(aux);
		}
		else {
			tRB->insert(aux);
		}
	};
	friend ostream& operator<<(ostream& out, const Map<TClau, TValor>& m)
	{
		out<<*m.tRB;
		return out;
	};
private:
	TreeRB<PairMap<TClau,TValor>> *tRB;
	TreeRB<PairMap<TClau, TValor>> *actual;
	TClau ClauDef;
	TValor p;
};