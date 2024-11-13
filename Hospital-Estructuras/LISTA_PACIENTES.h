#pragma once
#include "Global.h"
#include "PILA_HISTORIALMEDICO.h"
//registro donde va estar la pila y toda la informacion del paciente
struct info_paciente {
	pacientes datos;
	PILA_HISTORIALMÉDICO expediente;
};
//registro de la lista de pacientes
struct beneficiario {
	info_paciente reporte;
	beneficiario* sig;
};
class LISTA_PACIENTES
{
public:
	LISTA_PACIENTES();
	void insertar(info_paciente);
	void modificar_paciente(string);
	string buscar_paciente(string);
	void mostrar();
private:
	beneficiario* nodo, * cabecera, * fin;
};

