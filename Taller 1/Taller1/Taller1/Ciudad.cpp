#include "pch.h"
#include "Ciudad.h"


Ciudad::Ciudad()
{
}
Ciudad::~Ciudad()
{
}


Ciudad::Ciudad(string nombre, ListaAdmin listaA, ListaCliente listaC)
{
	this->nombre = nombre;
	this->listaA = listaA;
	this->listaC = listaC;
}

string Ciudad::getNombre()
{
	return this->nombre;
}

ListaAdmin Ciudad::getListaAdmin()
{
	return this->listaA;
}

ListaCliente Ciudad::getListaCliente()
{
	return this->listaC;
}
