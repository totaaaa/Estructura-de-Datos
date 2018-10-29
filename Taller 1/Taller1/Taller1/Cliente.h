#pragma once
#include <string>

#include "ListaEvento.h"
using namespace std;


class Cliente
{

private:
	string nombre, apellido, id, ciudad, telefono;
	string* listaEventos;

public:
	Cliente();
	~Cliente();
	Cliente(string nombre, string apellido, string id, string ciudad, string telefono, string* listaEventos);

	// sin métodos extra aún

	string getNombre();
	string getApellido();
	string getId();				// get´s
	string getCiudad();
	string getTelefono();
	string* getListaEvento();
};

