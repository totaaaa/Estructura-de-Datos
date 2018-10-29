#pragma once
#include "Admin.h"
class ListaAdmin
{
private:
	int cantActual;		//	cantidad Actual.
	int cantMax;		//	cantidad M�xima.
	Admin* listaAdmin;	//	Lista de Admin.

public:
	ListaAdmin();
	~ListaAdmin();
	ListaAdmin(int max);

	Admin getAdmin(int pos);	//	retorna un Admin de una pocici�n dada.
	int getPosAdmin(Admin admin);	//	retorna la posici�n de un Admin dado.
	bool agregarAdmin(Admin admin);		// agraga un nuevo Admin a la lista.
	bool eliminarAdmin(Admin admin);	// elimina un Admin de la lista.
	void desplegarTodos();		// desplega todos los administradores.

	int getCantActual();	//	retorna la cantidad actual de Admin en la lista.
	int getCantMax();		//	retorna la cantidad m�xima de la Lista.
	Admin* getLista();		//	retorna la lista de Admin.
};
