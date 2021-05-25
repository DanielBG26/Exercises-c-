#include "Persona.h"

ostream& operator<<(ostream &out, const Persona& p)
{
	out << "(" << p.m_nom << ", " << p.m_edat << ")";
	return out;
}
bool Persona::operator==(const Persona& p) const
{
	bool eq = false;
	if ((m_edat == p.m_edat) && (m_nom == p.m_nom)) {
		eq = true;
	}
	return eq;
}
