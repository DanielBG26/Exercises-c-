class Hora
{
public:
	Hora() : m_hora(0), m_minut(0), m_segon(0) {} //constructor defecte
	Hora(int hora, int minut, int segon) : m_hora(hora), m_minut(minut), m_segon(segon){}  // constructor parametres
	Hora(const Hora& hora) : m_hora(hora.m_hora), m_minut(hora.m_minut), m_segon(hora.m_segon) {} // constructor copia

	//setter y getters
	void setHora(int hora) {m_hora = hora;}
	void setMinuts(int minut) {m_minut = minut;}
	void setSegons(int segon){m_segon = segon;}
	int getHora() const {return m_hora;}
	int getMinuts() const {return m_minut;}
	int getSegons() const {return m_segon;}

    //metode si la hora es valida
	bool horaValida();
	
	Hora operator+(int& segons);
	Hora operator+(const Hora& hores);
	bool operator==(const Hora& hores);
	bool operator<(const Hora& hores);
	Hora operator=(const Hora& hora);

private:
	int m_hora;
	int m_minut;
	int m_segon;
};
