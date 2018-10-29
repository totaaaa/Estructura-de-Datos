#pragma once
#include "Evento.h"
class ListaEvento
{
private:
	int cantActual;		//	cantidad Actual.
	int cantMax;		//	cantidad Máxima.
	Evento* listaEvento;	//	Lista de Eventos.

public:
	ListaEvento();
	~ListaEvento();
	ListaEvento(int max);

	void desplegarEventoXTipo(string tipo);		// desplega todos los Eventos del tipo dado.
	Evento getEvento(int pos);	//	retorna un Evento de una pocición dada.
	int getPosEvento(Evento evento);	//	retorna la posición de un Evento dado.
	void agregarEvento(Evento evento);	// agrega un nuevo Evento a la lista.


	int getCantActual();
	int getCantMax();
	Evento* getLista();	
	
};