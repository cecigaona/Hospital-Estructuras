#pragma once
#include "Global.h"
#define CANTIDADCAMAS 100
#define CANTIDADPISOS 10

class LISTA_CAMAS
{

public:
	LISTA_CAMAS();
	~LISTA_CAMAS();
	void Mostrar();
	void Poblar();
	Camas OcuparCama(string IDPaciente);
	void DesocuparCama(string IDPaciente);

private:

	Camas* arregloCamas;
	int ocupados;

};

