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
	int contadorDeError = 0;	// para desplegar en cual linea del archivo ocurre un error

	arch.open("Eventos.txt", ios::in);	//	Abrimos el archivo en modo lectura 
	if (arch.fail()) {
		cout << "No se pudo abrir el archivo 'Eventos.txt' ";
		exit(EXIT_FAILURE);
	}
	
	this->eventos = ListaEvento(11);	// la cantidad de Eventos que vienen en el archivo es 11.

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

		getline(is, nombre, ',');
		getline(is, ciudad, ',');
		getline(is, idCliente, ',');
		getline(is, idAdmin, ',');
		getline(is, id, ',');
		getline(is, tipo, ',');
		
		switch (clasificarTipo(tipo)) {
		case 0:		// Social
			getline(is, estado, ',');

			if (estado == "Realizado") {
				getline(is, personasEsperadas, ',');
				getline(is, personasAsistentes, ',');

				Evento e = Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), stoi(personasAsistentes), 5*stoi(personasEsperadas), 9*stoi(personasAsistentes));

				eventos.agregarEvento(e);
			}
			else {
				getline(is, personasEsperadas, ',');
				
				Evento e = Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), 0, 5*stoi(personasEsperadas),0);

				eventos.agregarEvento(e);
			}

			break;
		case 1:		//	Cultural
			getline(is, estado, ',');

			if (estado == "Realizado") {
				getline(is, personasEsperadas, ',');
				getline(is, personasAsistentes, ',');

				Evento e = Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), stoi(personasAsistentes), 2*stoi(personasEsperadas), 4*stoi(personasAsistentes));
				eventos.agregarEvento(e);
			}
			else {
				getline(is, personasEsperadas, ',');

				Evento e = Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), 0, 2*stoi(personasEsperadas), 0);
				eventos.agregarEvento(e);
			}
			break;
		case 2:		//	Deportivo
			getline(is, estado, ',');

			if (estado == "Realizado") {
				getline(is, personasEsperadas, ',');
				getline(is, personasAsistentes, ',');

				Evento e = Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), stoi(personasAsistentes), 8*stoi(personasEsperadas), 11*stoi(personasAsistentes));
				eventos.agregarEvento(e);
			}
			else {
				getline(is, personasEsperadas, ',');

				Evento e = Evento(nombre, ciudad, idCliente, idAdmin, id, tipo, estado,
					stoi(personasEsperadas), 0, 8*stoi(personasEsperadas), 0);
				eventos.agregarEvento(e);
			}
			break;
		case -1:
			cout << "Error en el tipo del Evento.";
			cout << "\nEn la Linea \n";  
			cout << contadorDeError << endl;
			exit(EXIT_FAILURE);
			break;

		}
		contadorDeError++;
	}

	arch.close();
}

void GenEvent::leerCliente() {
	ifstream arch;
	string linea;

	arch.open("Clientes.txt", ios::in);
	if (arch.fail()) {
		cout << "No se pudo abrir el archivo 'Clientes.txt' ";
		exit(EXIT_FAILURE);
	}

	this->clientes =  ListaCliente(6);	// la cantidad de clientes que vienen en el archivo es 6.

	while (!arch.eof()) {
		getline(arch, linea);

		//datos del Cliente
		string nombre = "";
		string apellido = "";
		string id = "";
		string ciudad = "";
		string telefono = "";
		
		
		istringstream line(linea);
		while (!line.eof()) {
			getline(line, nombre, ';');
			getline(line, apellido, ';');
			getline(line, id, ';');
			getline(line, ciudad, ';');
			getline(line, telefono, ';');
			
			int c = 0;
			string* eventos = new string[5];
			
			while (!line.eof()) {
				getline(line, eventos[c], ';');
				c++;
			}
			
			Cliente	cliente =Cliente(nombre,apellido,id,ciudad,telefono,eventos);

			clientes.agregarCliente(cliente);
		}
	}
	
	arch.close();
}



void GenEvent::leerAdmin() {
	ifstream arch;
	string linea;

	arch.open("Administradores.txt", ios::in);
	if (arch.fail()) {
		cout << "No se pudo abrir el archivo 'Administradores.txt' ";
		exit(EXIT_FAILURE);
	}

	this->admins = ListaAdmin(6);	// la cantidad de Administradores que vienen en el archivo es 6.

	while (!arch.eof()) {
		getline(arch, linea);

		//datos del Admin
		string nombre = "";
		string apellido = "";
		string id = "";
		string ciudad = "";
		string monto = "";
		
		istringstream line(linea);
		while (!line.eof()) {
			getline(line, nombre, ';');
			getline(line, apellido, ';');
			getline(line, id, ';');
			getline(line, ciudad, ';');
			getline(line, monto, ';');

			int c = 0;
			string* eventos = new string[5];

			while (!line.eof()) {
				getline(line, eventos[c], ';');
				c++;
			}

			Admin	admin = Admin(nombre, apellido, id, ciudad, stoi(monto), eventos);

			admins.agregarAdmin(admin);
			
		}
	}

	arch.close();
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
		exit(EXIT_SUCCESS);

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
	catch (exception ex) {		
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



ListaEvento GenEvent::getEventos()
{
	return	eventos;
}

ListaCliente GenEvent::getClientes()
{
	return	clientes;
}



