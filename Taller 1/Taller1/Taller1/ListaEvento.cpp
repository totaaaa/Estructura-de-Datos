#include "pch.h"
#include "ListaEvento.h"



ListaEvento::ListaEvento()
{
}
ListaEvento::~ListaEvento()
{
}


ListaEvento::ListaEvento(int max)
{
	this->cantActual = 0;
	this->cantMax = max;
	this->listaEvento = new Evento[max];
}

void ListaEvento::agregarEvento(Evento evento)
{
	if (cantActual < cantMax) {	// Si el arreglo tiene espacio se agrega un nuevo Evento.
		this->listaEvento[cantActual] = evento;
		this->cantActual++;	
	}
	else {

		Evento* auxiliar = new Evento[1 + cantActual]; //	arreglo para guardar los datos del arreglo original con tamaño mayor por 1.

		for (int i = 0; i < cantActual;i++) {
			auxiliar[i] = this->listaEvento[i]; // copiamos iterativamente el vector en el auxiliar
		}

		delete[] listaEvento; // se elimina la lista anterior para guardar memoria

		Evento* listaEvento = new Evento[cantActual + 1];	// se crea un nuevo arreglo con capacidad aumentada

		for (int i = 0; i < cantActual;i++) {
			listaEvento[i] = auxiliar[i];
		}

		delete[] auxiliar;		// eliminamos la lista auxiliar

		listaEvento[cantActual] = evento;	// por último de añade el evento desde parámetros.
		cantActual++;
		
	}
}

int ListaEvento::getCantActual()
{
	return this->cantActual;
}

int ListaEvento::getCantMax()
{
	return this->cantMax;
}

Evento* ListaEvento::getLista()
{
	return this->listaEvento;
}



