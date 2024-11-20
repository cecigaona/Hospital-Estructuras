#pragma once
#include "Global.h"
#define MAXDOCTORES 10

struct Doctor {

	string nombre;
	string especialidad;
	int cedula;

};

class LISTA_DOCTORES
{

public:

	LISTA_DOCTORES();
	void Mostrar();

	//este metodo va a ser para mostrar los datosw del doctor que se le haya asignado al paciente, 
	// por medio de una varibale int (porque los docotores ya van pre creados)
	void MostrarDoctorEspecifico(int opcion);
	void MostrarNombreDoctor(int opc);

private:

	void Poblar();
	Doctor doctores [MAXDOCTORES];

};

