#pragma once
#include "Global.h"
//registro donde se guarda toda la informacion de los historiales médicos
struct historiales {
	string informe; //todo el informe se guarda como un string individual por cuestión de práctica 
	historiales* dir;
};
class PILA_HISTORIALMÉDICO
{
public:
	PILA_HISTORIALMÉDICO();
	void insertar_historial(string);
	string extraer_historial();
	string consultar_tope();
private:
	historiales* tope, * nodo;
};

