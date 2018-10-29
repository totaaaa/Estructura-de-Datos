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



