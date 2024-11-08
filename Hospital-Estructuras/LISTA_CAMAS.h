#pragma once
#include "Global.h"
#define CANTIDADCAMAS 100

class LISTA_CAMAS
{

public:
	LISTA_CAMAS();
	~LISTA_CAMAS();
	void Mostrar();
	void Poblar();
	void OcuparCama(int IDPaciente);
	void DesocuparCama(int IDPaciente);

private:

	Camas* arregloCamas;
	int ocupados;

};

