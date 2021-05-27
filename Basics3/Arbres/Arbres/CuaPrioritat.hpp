#pragma once
#include "Heap.hpp"

template <class T>
class CuaPrioritat
{
public:
	CuaPrioritat() { m_actual = -1; m_max = 0; }
	~CuaPrioritat() {}
	CuaPrioritat(const CuaPrioritat<T>& cua);
	CuaPrioritat& operator=(const CuaPrioritat<T>& cua);

	bool esBuida() const;
	int getNElements() const;
	T& top();
	void push(const T& element);
	void pop();
	void remove(const T& element);
private:
	vector<T> m_data;
	int m_max;
	int m_actual;


	int getFillEsq(int pos) const { return ((2 * pos) + 1); }
	int getFillDret(int pos) const { return ((2 * pos) + 2); }
	int getPare(int pos) const { return ((pos - 1) / 2); }
	void intercanvia(T& v1, T& v2) { T aux = v1; v1 = v2; v2 = aux; }
	void descendeix(int pos);

};

template<class T>
CuaPrioritat<T>::CuaPrioritat(const CuaPrioritat<T>& cua)
{
	m_data = cua.m_data;
	m_actual = cua.m_actual;
	m_max = cua.m_max;
}

template<class T>
CuaPrioritat<T>& CuaPrioritat<T>::operator=(const CuaPrioritat<T>& h)
{
	if (this != &h)
	{
		m_data = h.m_data;
		m_max = h.m_max;
		m_actual = h.m_actual;
	}
	return *this;
}

template<class T>
inline bool CuaPrioritat<T>::esBuida() const
{
	bool ret = false;
	if (m_actual == -1)
	{
		ret = true;
	}
	return ret;
}

template<class T>
inline int CuaPrioritat<T>::getNElements() const
{
	return m_data.size();
}

template<class T>
inline T & CuaPrioritat<T>::top()
{
	return m_data[0];
}

template<class T>
inline void CuaPrioritat<T>::push(const T & el)
{
	// Inserim element al final
	m_actual++;
	if (m_actual < m_max)
		m_data[m_actual] = el;
	else
	{
		m_data.push_back(el);
		m_max++;
	}
	int posAct = m_actual;
	// Si no es compleix la propietat del heap, intercanviem amb el pare per solucionar-ho
	while ((posAct != 0) && (m_data[posAct] < m_data[getPare(posAct)]))
	{
		intercanvia(m_data[posAct], m_data[getPare(posAct)]);
		posAct = getPare(posAct);
	}
}

template<class T>
inline void CuaPrioritat<T>::pop()
{
	if (m_actual >= 0)
	{
		// Posar element ultim a l'arrel, decrementar nombre elements i descendir l'arrel per mantenir propietat de heap
		intercanvia(m_data[0], m_data[m_actual]);
		m_actual--;
		descendeix(0);
	}
}

template<class T>
inline void CuaPrioritat<T>::remove(const T & el)
{
	int pos;
	for (int i = 0; i <= m_actual; i++) {
		if (el == m_data[i]) {
			pos = i;
		}
	}

	if (m_actual >= 0)
	{
		intercanvia(m_data[pos], m_data[m_actual]);
		m_actual--;
		descendeix(0);
	}

}

template<class T>
inline void CuaPrioritat<T>::descendeix(int posAct)
{
	int fEsq = getFillEsq(posAct);
	int fDret = getFillDret(posAct);
	int mesPetit = posAct;
	if ((fEsq <= m_actual) && (m_data[fEsq] < m_data[posAct]))
		mesPetit = fEsq;
	if ((fDret <= m_actual) && (m_data[fDret] < m_data[mesPetit]))
		mesPetit = fDret;
	if (mesPetit != posAct)
	{
		intercanvia(m_data[posAct], m_data[mesPetit]);
		descendeix(mesPetit);
	}
}
