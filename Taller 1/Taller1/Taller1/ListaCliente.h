#pragma once
#include "Cliente.h"
class ListaCliente
{
private:
	int cantActual;		//	cantidad Actual.
	int cantMax;		//	cantidad Máxima.
	Cliente* listaCliente;	//	Lista de Clientes.

public:
	ListaCliente();
	~ListaCliente();
	ListaCliente(int max);

	Cliente getCliente(int pos);	//	retorna un Cliente de una pocición dada.
	int getPosCliente(Cliente cliente);	//	retorna la posición de un Cliente dado.
	void agregarCliente(Cliente cliente);	// agrga un nuevo Cliente a la lista.
	void desplegarClienteXCiudad(string ciudad);	// desplega todos los elementos de una ciudad dada;
	   
	int getCantActual();	//	retorna la cantidad actual de Clientes en la lista.
	int getCantMax();		//	retorna la cantidad máxima de la Lista.
	Cliente* getLista();		//	retorna la lista de Clientes.
};
