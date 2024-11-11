#pragma once
#include "Global.h"
#include <iostream>
#include <string>
struct INFO_FILA
{
	string info;
	INFO_FILA* siguente;;
};
class FILA
{
public:
	FILA();
	~FILA();

	void insertar_fila(string);
	string extraer_fila();
	void mostrar();

private:
	INFO_FILA* principio;
	INFO_FILA* fin;
	INFO_FILA*nodo;

};

