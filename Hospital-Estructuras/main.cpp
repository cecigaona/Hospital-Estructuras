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
	info.datos.edad = 12;
	prueba.insertar(info);
	prueba.mostrar();
}