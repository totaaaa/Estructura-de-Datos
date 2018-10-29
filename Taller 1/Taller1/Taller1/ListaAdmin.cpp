#include "pch.h"
#include "ListaAdmin.h"



ListaAdmin::ListaAdmin()
{
}
ListaAdmin::~ListaAdmin()
{
}


ListaAdmin::ListaAdmin(int max)
{
	this->cantActual = 0;
	this->cantMax = max;
	this->listaAdmin = new Admin[max];
}


void ListaAdmin::agregarAdmin(Admin admin)
{
	if (cantActual < cantMax) {	// Si el arreglo tiene espacio se agrega un nuevo Admin.
		this->listaAdmin[cantActual] = admin;
		this->cantActual++;
	}
	else {

		Admin* auxiliar = new Admin[1 + cantActual]; //	arreglo para guardar los datos del arreglo original con tamaño mayor por 1.

		for (int i = 0; i < cantActual;i++) {
			auxiliar[i] = this->listaAdmin[i]; // copiamos iterativamente el vector en el arreglo auxiliar
		}

		delete[] listaAdmin; // se elimina la lista anterior para guardar memoria

		Admin* listaAdmin = new Admin[cantActual + 1];	// se crea un nuevo arreglo con capacidad aumentada

		for (int i = 0; i < cantActual;i++) {
			listaAdmin[i] = auxiliar[i];
		}

		delete[] auxiliar;		// eliminamos la lista auxiliar

		listaAdmin[cantActual] = admin;	// por último de añade el Admin desde parámetros.
		cantActual++;
	}
}

int ListaAdmin::getCantActual()
{
	return this->cantActual;
}

int ListaAdmin::getCantMax()
{
	return this->cantMax;
}

Admin * ListaAdmin::getLista()
{
	return this->listaAdmin;
}



