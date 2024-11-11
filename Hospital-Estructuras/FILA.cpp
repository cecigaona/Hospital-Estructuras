#include "FILA.h"
FILA::FILA()
{
	principio = fin = NULL;
}



// insertar el nombre de las personas en la fila 
void FILA::insertar_fila(string nuevo)
{
	nodo = new INFO_FILA;
	nodo->info = nuevo;
	nodo->siguente = NULL;

	if (principio == NULL)
		principio = nodo;
	if (fin != NULL)
		fin->siguente = nodo;
	fin = nodo;
	//mostrar el nombre de la persona agregada 
	cout << "\t persona agregada a la fila " << nuevo << endl;
}

string FILA::extraer_fila()
{
	string extraido;
	//ver si la fila esta vacia 
	if (principio == NULL)
		extraido = "";
	return extraido;

	nodo = principio;
	extraido = nodo->info;
	principio = nodo->siguente;

	if (principio == NULL)
		fin = NULL;

	delete nodo;
	return extraido;
}
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
