#include "pch.h"
#include "ListaCliente.h"



ListaCliente::ListaCliente()
{
}
ListaCliente::~ListaCliente()
{
}


ListaCliente::ListaCliente(int max)
{
	this->cantActual = 0;
	this->cantMax = max;
	this->listaCliente = new Cliente[max];
}

void ListaCliente::agregarCliente(Cliente cliente)
{
	this->listaCliente[cantActual] = cliente;
	this->cantActual++;
}

int ListaCliente::getCantActual()
{
	return this->cantActual;
}

int ListaCliente::getCantMax()
{
	return this->cantMax;
}

Cliente * ListaCliente::getLista()
{
	return this->listaCliente;
}