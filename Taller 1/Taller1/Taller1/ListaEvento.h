#pragma once
#include "Evento.h"
class ListaEvento
{
private:
	int cantActual;		//	cantidad Actual.
	int cantMax;		//	cantidad M�xima.
	Evento* listaEvento;	//	Lista de Eventos.

public:
	ListaEvento();
	~ListaEvento();
	ListaEvento(int max);

	void desplegarEventoXTipo(string tipo);		// desplega todos los Eventos del tipo dado.
	Evento getEvento(int pos);	//	retorna un Evento de una pocici�n dada.
	int getPosEvento(Evento evento);	//	retorna la posici�n de un Evento dado.
	void agregarEvento(Evento evento);	// agrega un nuevo Evento a la lista.


	int getCantActual();
	int getCantMax();
	Evento* getLista();	
	
};