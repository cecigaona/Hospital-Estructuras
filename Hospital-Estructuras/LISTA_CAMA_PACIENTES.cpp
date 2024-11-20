#include "LISTA_CAMA_PACIENTES.h"

LISTA_CAMA_PACIENTES::LISTA_CAMA_PACIENTES()
{
	cabecera = fin = NULL;
}

void LISTA_CAMA_PACIENTES::insertar(cama_paciente nuevo)
{
	nodo = new datos_cama_paciente;
	nodo->info = nuevo;
	if (cabecera == NULL && fin == NULL) {
		nodo->sig = cabecera;
		cabecera = nodo;
		fin = nodo;
		return;
	}
	nodo->sig = NULL;
	fin->sig = nodo;
	fin = nodo;
}

cama_paciente LISTA_CAMA_PACIENTES::extraer(cama_paciente expulsado)
{
	cama_paciente extraido;
	datos_cama_paciente* anterior;
	bool encontrado = false;
	if (cabecera == NULL) {
		extraido.ID_cama = "";
		extraido.ID_paciente = "";
		return extraido;
	}
	anterior = NULL;
	nodo = cabecera;
	do {
		if (nodo->info.ID_paciente == expulsado.ID_paciente) {
			encontrado = true;
			break;
		}
		anterior = nodo;
		nodo = nodo->sig;
	} while (nodo != NULL);
	if (!encontrado) {
		extraido.ID_cama = "";
		extraido.ID_paciente = "";
		return extraido;
	}
	if (nodo == cabecera) {
		nodo = cabecera;
		extraido = nodo->info;
		if (cabecera == fin)
			fin = NULL;
		cabecera = nodo->sig;
		delete nodo;
		return extraido;
	}
	if (nodo == fin) {
		extraido = nodo->info;
		anterior->sig = NULL;
		fin = anterior;
		delete nodo;
		return extraido;
	}
	extraido = nodo->info;
	anterior->sig = nodo->sig;
	delete nodo;
	return extraido;
}

void LISTA_CAMA_PACIENTES::mostrar()
{
	int cont = 0;
	cout << "\tINFORMACIÓN DE LOS PACIENTES INTERNADOS" << endl;
	if (cabecera == NULL) {
		cout << "No hay pacientes internados..." << endl;
		return;
	}
	nodo = cabecera;
	cout << "\tNombre \tID Paciente \tID Cama \tUbicacion" << endl;
	while (nodo != NULL) {
		cout << ++cont << ". \t" << nodo->info.nombre << "\t" << nodo->info.ID_paciente << "\t" << nodo->info.ID_cama <<"\t\t" << nodo->info.ubicacion;
		nodo = nodo->sig;
		cout << endl;
	}
}
