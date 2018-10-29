#pragma once
#include<string>

#include "ListaAdmin.h"
#include "ListaCliente.h"
using namespace std;


class Ciudad
{

private:
	string nombre;
	ListaAdmin listaA;
	ListaCliente listaC;

public:
	Ciudad();
	~Ciudad();
	Ciudad(string nombre, ListaAdmin listaA, ListaCliente listaC);

	bool nameChecker(Admin admin);		// retorna true si el Admin enviado está en listaA.
	bool nameChecker(Cliente cliente);	// retorna true si el Cliente enviado está en listaC.

	string getNombre();
	ListaAdmin getListaAdmin();
	ListaCliente getListaCliente();
};

