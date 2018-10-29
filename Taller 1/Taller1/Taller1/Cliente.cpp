#include "pch.h"
#include "Cliente.h"


Cliente::Cliente()
{
}


Cliente::~Cliente()
{
}

Cliente::Cliente(string nombre, string apellido, string id, string ciudad, string telefono, string* listaEventos)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->id = id;
	this->ciudad = ciudad;
	this->telefono = telefono;
	this->listaEventos = listaEventos;

}

string Cliente::getNombre()
{
	return this->nombre;
}

string Cliente::getApellido()
{
	return this->apellido;
}

string Cliente::getId()
{
	return this->id;
}

string Cliente::getCiudad()
{
	return this->ciudad;
}

string Cliente::getTelefono()
{
	return this->telefono;
}

string* Cliente::getListaEvento()
{
	return this->listaEventos;
}
