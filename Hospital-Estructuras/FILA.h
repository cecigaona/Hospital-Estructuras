#pragma once
#include "Global.h"
#include <iostream>
#include <string>


struct DATOS_PERSONA
{
	string nombre;
};
struct INFO_FILA
{
	DATOS_PERSONA info;
	INFO_FILA* siguente;;
};
class FILA
{
public:
	FILA();
	~FILA();

	void insertarfila(DATOS_PERSONA);
	DATOS_PERSONA extraerdelafila();
	void mostrar();

private:
	INFO_FILA* principio;
	INFO_FILA* fin;
	INFO_FILA*nodo;

};

