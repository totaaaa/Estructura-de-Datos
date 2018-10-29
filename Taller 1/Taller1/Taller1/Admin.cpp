#include "pch.h"
#include "Admin.h"


Admin::Admin()
{
}
Admin::~Admin()
{
}


Admin::Admin(string nombre, string pellido, string id, string ciudad, int monto, string* listaEventos)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->id = id;
	this->ciudad = ciudad;
	this->monto = monto;
	this->listaEventos = listaEventos;

}

void Admin::setMonto(int monto)
{
	this->monto = monto;
}

bool Admin::isFired()
{
	if (this->monto <= 0) 
		return true;
	
	return false;
}

string Admin::getNombre()
{
	return this->nombre;
}

string Admin::getApellido()
{
	return this->apellido;
}

string Admin::getId()
{
	return this->id;
}

string Admin::getCiudad()
{
	return this->ciudad;
}

int Admin::getMonto()
{
	return this->monto;
}

string* Admin::getListaEvento()
{
	return this->listaEventos;
}
