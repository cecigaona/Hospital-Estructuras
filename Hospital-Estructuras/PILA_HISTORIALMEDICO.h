#pragma once
#include "Global.h"
//registro donde se guarda toda la informacion de los historiales m�dicos
struct historiales {
	string informe; //todo el informe se guarda como un string individual por cuesti�n de pr�ctica 
	historiales* dir;
};
class PILA_HISTORIALM�DICO
{
public:
	PILA_HISTORIALM�DICO();
	void insertar_historial(string);
	string extraer();
private:
	historiales* tope, * nodo;
};

