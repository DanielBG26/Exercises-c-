#include "Matriu.h"
#include <cmath>

Matriu::~Matriu()
{
}

Matriu& Matriu::operator=(const Matriu& m)
{
	m_nColumnes = m.m_nColumnes;
	m_nFiles = m.m_nFiles;

	/////////////////////// CREAR MATRIU //////////////////////////
	
	m_matriu = new float* [m_nFiles]; // La matriu m_matriu es crea com un array d’apuntadors (a tipus float*) del tamany del nº de files
	
	
	for (int i = 0; i < m_nFiles; i++) {
		m_matriu[i] = new float[m_nColumnes]; //Cada element de la matriu (cada fila) és un array de tipus int del tamany del nº de columnes
		
	}
	 ///////////////// GUARDA MATRIU EN M_MATRIU ////////////////
	for (int f = 0; f < m_nFiles; f++) {
		for (int c = 0; c < m_nColumnes; c++) {
			m_matriu[f][c] = m.m_matriu[f][c];
		}
	}
	return *this;
}
void Matriu::resize(int nFiles, int nColumnes)
{
	
	Matriu M;
	
	M.m_nColumnes = m_nColumnes;
	M.m_nFiles = m_nFiles;
	
	//////////////////////////////////////////////////////////////
	
	M.m_matriu = new float* [m_nColumnes];

	for (int c = 0; c < m_nColumnes; c++) {
		M.m_matriu[c] = new float[m_nFiles];
	}
	for (int f = 0; f < m_nFiles; f++) {
		for (int c = 0; c < m_nColumnes; c++) {
			M.m_matriu[f][c] = m_matriu[f][c];
		}
	}
	
	///////////////////////////////////////////////////////////////
	
	m_matriu = new float* [nFiles];

	for (int f = 0; f < nFiles; f++) {
		m_matriu[f] = new float[nColumnes];
	}

	for (int f = 0; f < nFiles; f++) {
		for (int c = 0; c < nColumnes; c++) {
			if (((f) < m_nFiles) && ((c) < nColumnes))
			{
				m_matriu[f][c] = M.m_matriu[f][c];
			}
			else
			{
				m_matriu[f][c] = 0;
			}
		}
	}
	
	/////////////////////////////////////////////////////////////////
	
	m_nFiles = nFiles;
	m_nColumnes = nColumnes;

}

void Matriu::transpose()
{

	Matriu M;
	
	M.m_nColumnes = m_nColumnes;
	M.m_nFiles = m_nFiles;
	
	//////////////////////////////////////////////////////////////////////
	M.m_matriu = new float* [m_nColumnes];
	for (int i = 0; i < m_nColumnes; i++) {
		M.m_matriu[i] = new float[m_nFiles];
	}
	for (int i = 0; i < m_nFiles; i++) {
		for (int n = 0; n < m_nColumnes; n++) {
			M.m_matriu[n][i] = m_matriu[i][n];
		}
	}
    /////////////////////////////////////////////////////////////////////////
	
	int novafila = m_nColumnes;
	int novacolumna = m_nFiles;
	
	m_nFiles = novafila;
	m_nColumnes = novacolumna;
	m_matriu = M.m_matriu;
}


void Matriu::setValor(int fila, int columna, float valor)
{
    if((m_nFiles >= fila) && (m_nColumnes >= columna))
    {
	    m_matriu[fila][columna] = valor;
    }
}
float Matriu::getValor(int fila, int columna) const {

	return m_matriu[fila][columna];
}
void Matriu::initValor(float valor)
{
	for (int f = 0; f < m_nFiles; f++) {
		for (int c = 0; c < m_nColumnes; c++) {
			m_matriu[f][c] = valor;
		}
	}
}

Matriu Matriu::operator+(float s) {

	Matriu M;
	
	M.m_nColumnes = m_nColumnes;
	M.m_nFiles = m_nFiles;
	
	////////////////////////////////////////////////
	M.m_matriu = new float* [m_nFiles];
	
	for (int i = 0; i < m_nFiles; i++) {
		M.m_matriu[i] = new float[m_nColumnes];
	}
	for (int i = 0; i < m_nFiles; i++) {
		for (int n = 0; n < m_nColumnes; n++) {
			M.m_matriu[i][n] = m_matriu[i][n] + s;
		}
	}
	return M;
}

Matriu Matriu::operator+(const Matriu& m)
{
	Matriu M;
	
	if ((m_nColumnes == m.m_nColumnes) && (m_nFiles == m.m_nFiles))
	{
		M.m_nColumnes = m_nColumnes;
		M.m_nFiles = m_nFiles;
		
		/////////////////////////////////////////////////////////
		M.m_matriu = new float* [m_nFiles];
		
		for (int i = 0; i < m_nFiles; i++) {
			M.m_matriu[i] = new float[m_nColumnes];
		}
		for (int i = 0; i < m_nFiles; i++) {
			for (int n = 0; n < m_nColumnes; n++) {
				M.m_matriu[i][n] = m_matriu[i][n] + m.m_matriu[i][n];
			}
		}
	}

	return M;

}


bool Matriu::operator==(const Matriu& m)
{
	bool igual = true;

	for (int i = 0; i < m_nFiles; i++) {
		for (int n = 0; n < m_nColumnes; n++) {
			if (m_matriu[i][n] != m.m_matriu[i][n])
			{
				igual = false;
				return igual;
			}
		}
	}
	return igual;
}