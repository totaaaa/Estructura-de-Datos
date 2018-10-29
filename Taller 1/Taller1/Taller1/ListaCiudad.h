#pragma once
#include "Ciudad.h"
class ListaCiudad
{
private:
	int cantActual;		//	cantidad Actual.
	int cantMax;		//	cantidad M�xima.
	Ciudad* listaCiudad;	//	Lista de Ciudad.

public:
	ListaCiudad();
	~ListaCiudad();
	ListaCiudad(int max);

	Ciudad getCiudad(int pos);	//	retorna una Ciudad de una pocici�n dada.
	int getPosCiudad(Ciudad);	//	retorna la posici�n de una Ciudad dado.
	bool agregarCiudad();	// agrega una nueva Ciudad a la lista.
	
	int getCantActual();	//	retorna la cantidad actual de Ciudades en la lista.
	int getCantMax();		//	retorna la cantidad m�xima de la Lista.
	Ciudad* getLista();		//	retorna la lista de Ciudades.
	
};