#include "FILA.h"
FILA::FILA()
{
	principio = fin = NULL;
}
//insertar el nombre de las personas en la fila 
void FILA::insertar_fila(string nuevo)
{
	nodo = new INFO_FILA;
	nodo->info = nuevo;
	nodo->siguente = NULL;
	if (principio == NULL) 
		principio = nodo;
	else 
		fin->siguente = nodo;
	fin = nodo;
	cout << "\t persona agregada a la fila " << nuevo << endl;
}
//funcion encargada de sacar a los pacientes de la fila para asignarlos a una cama y poderlos agregar a la lista pacientes si necesario 
string FILA::extraer_fila()
{
	string extraido;
	//ver si la fila esta vacia 
	if (principio == NULL) {
		extraido = "";
		return extraido;
	}

	nodo = principio;
	extraido = nodo->info;
	principio = nodo->siguente;

	if (principio == NULL)
		fin = NULL;

	delete nodo;
	return extraido;
}
//funcion encargada en mostrar como va la fila
void FILA::FILA::mostrar()
{
	if (principio == NULL)
	{
		cout << "\t la fila esta vacia " << endl;
		return;
	}
	nodo = principio;
	cout << "\t\t Las personas en la fila son: " << endl;
	while (nodo!= NULL)
	{
		cout << nodo->info << endl; //muestra el nombre de la persona
		nodo = nodo->siguente;
	}
}

FILA::~FILA()
{
}
