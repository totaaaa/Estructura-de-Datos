#include "pch.h"
#include "ListaCiudad.h"



ListaCiudad::ListaCiudad()
{
}
ListaCiudad::~ListaCiudad()
{
}


ListaCiudad::ListaCiudad(int max)
{
	this->cantActual = 0;
	this->cantMax = max;
	this->listaCiudad = new Ciudad[max];
}

int ListaCiudad::getCantActual()
{
	return this->cantActual;
}

int ListaCiudad::getCantMax()
{
	return this->cantMax;
}

Ciudad* ListaCiudad::getLista()
{
	return this->listaCiudad;
}

