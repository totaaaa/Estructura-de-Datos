#include "pch.h"
#include "GenEvent.h"
#include "ListaEvento.h"
#include "ListaAdmin.h"
#include "ListaCliente.h"
#include "ListaCiudad.h"

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>




GenEvent::GenEvent() {

}
GenEvent::~GenEvent() {

}

void GenEvent::leerEvento() {
	ifstream arch;
	string linea;
	arch.open("Eventos.txt", ios::in);	//	Abrimos el archivo en modo lectura
	if (arch.fail()) {
		cout << "No se pudo abrir el archivo 'Eventos.txt' ";
		exit(EXIT_FAILURE);
	}
	this->eventos = new ListaEvento(10);

	while (!arch.eof()) {
		getline(arch, linea);
		
		//datos del Evento
		string nombre = "";
		string ciudad = "";
		string idCliente = ""; 
		string idAdmin = "";
		string id = "";
		string tipo = "";
		string estado = "";
		string personasEsperadas = "";
		string personasAsistentes = "";
		
		istringstream is(linea);

		getline(is, nombre, ';');
		getline(is, ciudad, ';');
		getline(is, idCliente, ';');
		getline(is, idAdmin, ';');
		getline(is, id, ';');
		getline(is, tipo, ';');
				
		switch (clasificarTipo(tipo)) {
		case 0:		// Social
			getline(is, estado, ';');

			if (estado == "Realizado") {
				getline(is, personasEsperadas, ';');
				getline(is, personasAsistentes, ';');

				Evento* e = new Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), stoi(personasAsistentes), 5 * stoi(personasEsperadas), 9 * stoi(personasAsistentes));
				eventos->agregarEvento(*e);
			}
			else {
				getline(is, personasEsperadas, ';');
				
				Evento* e = new Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), stoi(personasAsistentes), 5 * stoi(personasEsperadas),0);
				eventos->agregarEvento(*e);
			}

			break;
		case 1:		//	Cultural
			getline(is, estado, ';');

			if (estado == "Realizado") {
				getline(is, personasEsperadas, ';');
				getline(is, personasAsistentes, ';');

				Evento* e = new Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), stoi(personasAsistentes), 2 * stoi(personasEsperadas), 4 * stoi(personasAsistentes));
				eventos->agregarEvento(*e);
			}
			else {
				getline(is, personasEsperadas, ';');

				Evento* e = new Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), stoi(personasAsistentes), 2 * stoi(personasEsperadas), 0);
				eventos->agregarEvento(*e);
			}
			break;
		case 2:		//	Deportivo
			getline(is, estado, ';');

			if (estado == "Realizado") {
				getline(is, personasEsperadas, ';');
				getline(is, personasAsistentes, ';');

				Evento* e = new Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), stoi(personasAsistentes), 8 * stoi(personasEsperadas), 11 * stoi(personasAsistentes));
				eventos->agregarEvento(*e);
			}
			else {
				getline(is, personasEsperadas, ';');

				Evento* e = new Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), stoi(personasAsistentes), 8 * stoi(personasEsperadas), 0);
				eventos->agregarEvento(*e);
			}
			break;
		case -1:
			cout << "Error en el tipo del Evento.";
			exit(EXIT_FAILURE);
			break;

		}
	}

}
void GenEvent::leerCliente() {

}


void GenEvent::leerAdmin() {
}

void GenEvent::menu() {
	cout << "\n\n\n\n\n Bienvenid@ al sistema de administracion de la empresa GenEvent: \n\nEstas son las opciones disponibles: \n";

	cout << "1) SubMenu que permite agregar EVENTOS, CLIENTES y/o ADMINISTRADORES \n";
	cout << "2) SubMenu que permite cambiar el estado de un evento de REALIZADO a CANCELADO y viceversa \n";
	cout << "3) SubMenu para buscar Eventos, Clientes o Administradores \n";
	cout << "\nPor favor ingrese una opcion para continuar: \n \n";

	cout << "1) Agregar \n\n";
	cout << "2) Administrar evento \n\n";
	cout << "3) Buscar \n\n";
	cout << "4) Salir \n\n";

	
	string strOpcion;
	getline(cin,strOpcion);
	
	int opcion;
	while (	!isNumeric(strOpcion)	||	(	
			stoi(strOpcion)!=1	&& stoi(strOpcion) != 2 && 
			stoi(strOpcion) != 3 && stoi(strOpcion) != 4 ) ) {
		cout << "\n Ha ocurrido un error , intente de nuevo. \n";
		getline(cin, strOpcion);
	}
	opcion = stoi(strOpcion);

	switch (opcion)
	{
	case 1:
		agregar();
		break;
	case 2:
		administrarEvento();
		break;
	case 3:
		buscar();
		break;
	case 4:
		cout << "\n Actualizando datos...\n";
		actualizarDatos();
		cout << "\n Generando texto...\n";
		generarDespedidos();

		cout << "\n Muchas gracias, vuelva pronto n.n \n";
		 (EXIT_SUCCESS);

	}// no hay default porque la validación no admite errores.

}

void GenEvent::agregar() {

}

void GenEvent::administrarEvento() {

}

void GenEvent::buscar() {

}

void GenEvent::actualizarDatos() {

}

void GenEvent::generarDespedidos() {

}

bool GenEvent::isNumeric(string str)
{
	try {
		int n = stoi(str);
	}
	catch (exception ex) {		//xd
		return false;
	}
	return true;

}

int GenEvent::clasificarTipo(string str)
{
	if (str == "Social") {
		return 0;
	}
	if (str == "Cultural") {
		return 1;
	}
	if (str == "Deportivo") {
		return 2;
	}
	return -1;



}

ListaEvento * GenEvent::getEventos()
{
	return	this->eventos;
}


