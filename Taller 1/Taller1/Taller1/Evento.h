#pragma once
#include <string>

using namespace std;


class Evento
{

private:
	string nombre, ciudad, idCliente, idAdmin, id, tipo, estado;
	int personasEsperadas, gastos;
	int personasAsistentes, ingresos;
	
public:
	Evento();
	~Evento();
	Evento(string nombre, string ciudad, string idCliente, 
		string idAdmin,string id, string tipo , string estado ,int personaEsperadas, 
		int personasAsistentes, int gastos, int ingresos);

	void setEstado(string estado);		
	   
	string getNombre();
	string getCiudad();
	string getIdCliente();				// get´s
	string getIdAdmin();
	string getId();
	string getTipo();
	string getEstado();
	int getPersonasEsperadas();
	int getPersonasAsistentes();
	int getGastos();
	int getIngresos();

};

