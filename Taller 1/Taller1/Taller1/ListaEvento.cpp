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
	listaEvento[cantActual] = evento;
	this->cantActual++;
}

int ListaEvento::getCantActual()
{
	return this->cantActual;
}

int ListaEvento::getCantMax()
{
	return this->cantMax;
}

Evento * ListaEvento::getLista()
{
	return this->listaEvento;
}



