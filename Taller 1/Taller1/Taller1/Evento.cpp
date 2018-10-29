#include "pch.h"
#include "Evento.h"


Evento::Evento()
{
}
Evento::~Evento()
{
}


Evento::Evento(string nombre, string ciudad, string idCliente, string idAdmin, string id, string tipo,string estado, int personasEsperadas, int personasAsistentes, int gastos, int ingresos)
{
	this->nombre = nombre;
	this->ciudad = ciudad;
	this->idCliente = idCliente;
	this->idAdmin = idAdmin;
	this->estado = estado;
	this->tipo = tipo;
	this->personasEsperadas = personasEsperadas;
	this->personasAsistentes = personasAsistentes;
	this->gastos = 0;
	this->ingresos = 0;

}

void Evento::setEstado(string estado)
{
	this->estado = estado;
}

string Evento::getNombre()
{
	return this->nombre;
}

string Evento::getCiudad()
{
	return this->ciudad;
}

string Evento::getIdCliente()
{
	return this->idCliente;
}

string Evento::getIdAdmin()
{
	return this->idAdmin;
}

string Evento::getId()
{
	return this->id;
}

string Evento::getTipo()
{
	return this->tipo;
}

string Evento::getEstado()
{
	return this->estado;
}

int Evento::getPersonasEsperadas()
{
	return this->personasEsperadas;
}

int Evento::getPersonasAsistentes()
{
	return this->personasAsistentes;
}

int Evento::getGastos()
{
	return this->gastos;
}

int Evento::getIngresos()
{
	return this->ingresos;
}



