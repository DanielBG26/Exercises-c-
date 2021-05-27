#include "Persona.h"

ostream& operator<<(ostream &out, const Persona& p)
{
	out << "(" << p.m_nom << ", " << p.m_edat << ")";
	return out;
}

bool Persona::operator>(const Persona& p)
{
	bool mesGran = 0;
    if (m_edat == p.m_edat)
			if (m_nom > p.m_nom)
				mesGran = 1;
	else
			if (m_edat > p.m_edat)
	    	mesGran = 1;
	return mesGran;
}

bool Persona::operator==(const Persona& p) const
{
	return ((m_nom == p.m_nom) && (m_edat == p.m_edat));
}

Persona& Persona::operator=(const Persona& p)
{
	m_nom = p.m_nom;
	m_edat = p.m_edat;
	return *this;
}