#pragma once
#include<string>

#include "ListaEvento.h"
using namespace std;


class Admin
{

private:
	string nombre, apellido, id, ciudad;
	int monto;
	string* listaEventos;
public:
	Admin();
	~Admin();
	Admin(string nombre, string pellido, string id, string ciudad, 
		int monto, string* listaEventos);

	void setMonto(int monto);	
	bool isFired();	// retorna false si  monto > 0

	string getNombre();
	string getApellido();
	string getId();				// get´s
	string getCiudad();
	int getMonto();
	string* getListaEvento();
};

