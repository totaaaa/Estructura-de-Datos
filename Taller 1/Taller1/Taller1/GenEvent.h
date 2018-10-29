#pragma once
#include "ListaEvento.h"
#include "ListaCliente.h"
#include "ListaAdmin.h"
#include "ListaCiudad.h"
class GenEvent
{
private:
	ListaEvento eventos;
	ListaCliente clientes;
	ListaAdmin admins;
	ListaCiudad ciudades;
public:
	GenEvent();
	~GenEvent();


	void leerEvento();	// lee los Eventos
	void leerAdmin();	// lee los Administradores
	void leerCliente();		// lee los Clientes
	
	void menu();		// Menú de opciones para e usuario.

	void agregar();		// SubMenú que permite agregar EVENTOS, CLIENTES y/o ADMINISTRADORES a sus respectivas listas.
	void administrarEvento();	// SubMenú que permite cambiar el estado de un evento de REALIZADO a CANCELADO y viceversa.
	void buscar();		// SubMenú para buscar Eventos, clientes o administradores.
	void actualizarDatos();		// Actualiza los datos de los archivo de textos utilizados.
	void generarDespedidos();		// Genera un archivo .txt con los Administradores despedidos.
	
	bool isNumeric(string str);		// valida si el valor ingresado es un int.
	int clasificarTipo(string str);		// devuelve: 0 si str=="Social", 1 si str=="Cultural", 2 si str=="Deportivo",

	ListaEvento getEventos();
	ListaCliente getClientes();

	ListaAdmin getAdmins();
	ListaCiudad getCiudades();


};

