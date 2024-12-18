#pragma once
//header encargado de guardar todas las librerias en un solo lugar y las estructuras generales
#include <iostream>
#include <string>
using namespace std;
//registro donde se guarda toda la información de los pacientes
struct pacientes {
	string ID;
	string nombre;
	bool estado;//true dado de alta, false no
	string genero;
	string motivo;
	int edad;
	int numeroDeDoctor;
};
//registro donde se guarda la información de las camas
struct Camas {
	string ID;
	string ubicacion;
	bool estado;
	string ID_paciente;
};