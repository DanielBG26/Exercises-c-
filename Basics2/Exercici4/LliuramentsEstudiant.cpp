#include "LliuramentsEstudiant.h"


void LliuramentsEstudiant::afegeixTramesa(const string& fitxer, const string& data)
{
        Tramesa NTramesa;
        
		NTramesa.setFitxer(fitxer);
		NTramesa.setData(data);
		
		m_trameses.push_front(NTramesa);
}

bool LliuramentsEstudiant::eliminaTramesa(const string& data)
{
	bool eliminar = false;
	
	std::forward_list<Tramesa>::iterator aux = m_trameses.begin();
	std::forward_list<Tramesa>::iterator anterior = m_trameses.before_begin();

	while((aux != m_trameses.end()) && (!eliminar))
	{
		if (aux->getData() != data)
		{
			anterior++; //o anterior = aux
			aux++;
		}
		else 
		{
	    	eliminar = true;	
		}
	}
	if (eliminar == true)
	{
		m_trameses.erase_after(anterior);
	}
	return eliminar;
}


bool LliuramentsEstudiant::consultaTramesa(const string& data, string& fitxer)
{
	bool trobat = false;
	
	std::forward_list<Tramesa>::iterator aux = m_trameses.begin();
	
	while (aux != m_trameses.end() && !trobat)
	{
		if((*aux).getData() != data)
		{
			aux++;
		}
		else 
		{
		    trobat = true;	
		}
	}
	
	if(trobat)
	{
	    fitxer = (*aux).getFitxer();
	}
	return trobat;
}
