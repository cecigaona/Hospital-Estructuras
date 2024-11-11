#pragma once
#include "Global.h"
//estructura de los datos que lleva la lista de cama-pacientes
struct cama_paciente {
	string ID_paciente;
	string ID_cama;
	string ubicacion;
	string nombre;
};
struct datos_cama_paciente {
	cama_paciente info;
	datos_cama_paciente* sig;
};
class LISTA_CAMA_PACIENTES
{
public:
	LISTA_CAMA_PACIENTES();
	void insertar(cama_paciente);
	cama_paciente extraer(cama_paciente);
	void mostrar();
private:
	datos_cama_paciente* nodo, * cabecera, * fin;
};

