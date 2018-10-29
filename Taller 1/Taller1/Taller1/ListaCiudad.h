#pragma once
#include "Ciudad.h"
class ListaCiudad
{
private:
	int cantActual;		//	cantidad Actual.
	int cantMax;		//	cantidad Máxima.
	Ciudad* listaCiudad;	//	Lista de Ciudad.

public:
	ListaCiudad();
	~ListaCiudad();
	ListaCiudad(int max);

	Ciudad getCiudad(int pos);	//	retorna una Ciudad de una pocición dada.
	int getPosCiudad(Ciudad);	//	retorna la posición de una Ciudad dado.
	bool agregarCiudad();	// agrega una nueva Ciudad a la lista.
	
	int getCantActual();	//	retorna la cantidad actual de Ciudades en la lista.
	int getCantMax();		//	retorna la cantidad máxima de la Lista.
	Ciudad* getLista();		//	retorna la lista de Ciudades.
	
};