#include "FILA.h"
FILA::FILA()
{
	principio = fin = NULL;
}



// insertar el nombre de las personas en la fila 
void FILA::insertarfila(DATOS_PERSONA nuevo_en_fila)
{
	//preguntar nombre del paciente a agregar a la fila 
	string nombre;
	cout << "\t ingresa el nombre de la persona a agregar a la fila ";
	cin.ignore();
	getline(cin, nombre);

	nodo = new INFO_FILA;
	nodo->info = nuevo_en_fila;
	nodo->siguente = NULL;

	if (principio == NULL)
		principio = nodo;
	if (fin != NULL)
		fin->siguente = nodo;
	fin = nodo;
	//mostrar el nombre de la persona agregada 
	cout << "\t persona agregada a la fila " << nombre << endl;
}

DATOS_PERSONA FILA::extraerdelafila()
{
	DATOS_PERSONA extraido;
	//ver si la fila esta vacia 
	if (principio == NULL)
		extraido.nombre = "";
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
		cout << nodo->info.nombre << endl; //muestra el nombre de la persona
		nodo = nodo->siguente;
	}
}

FILA::~FILA()
{
}
