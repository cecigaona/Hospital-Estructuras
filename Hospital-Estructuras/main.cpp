#include "Global.h"
#include "PILA_HISTORIALMEDICO.h"
#include "FILA.h"
#include "LISTA_CAMAS.h"
#include "LISTA_CAMA_PACIENTES.h"
#include "LISTA_PACIENTES.h"
using namespace std;
void main() {
	//prueba
	LISTA_PACIENTES prueba;
	info_paciente info;
	info.datos.nombre = "aaa";
	info.datos.ID = "A01";
	info.datos.estado = false;
	info.datos.genero = "M";
	info.datos.motivo = "dolor de cabeza";
	info.datos.edad = 12;
	prueba.insertar(info);
	prueba.mostrar();
	prueba.buscar_paciente("A01");
	prueba.buscar_paciente("A02");
	prueba.modificar_paciente("A02");
	prueba.modificar_paciente("A01");
	prueba.mostrar();

	LISTA_CAMAS prueba2;

	prueba2.Mostrar();
	prueba2.OcuparCama("A01");
	prueba2.Mostrar();
	prueba2.DesocuparCama("A01");
	prueba2.Mostrar();
}