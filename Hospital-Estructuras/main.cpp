#include "Global.h"
#include "PILA_HISTORIALMEDICO.h"
#include "FILA.h"
#include "LISTA_CAMAS.h"
#include "LISTA_CAMA_PACIENTES.h"
#include "LISTA_PACIENTES.h"
using namespace std;
//funcion encargada en crear los ids de los pacientes
string generador_ID_paciente(int contador) {
	string nuevo = "P";
	if (contador <= 9) {
		nuevo = "P00";
		nuevo += to_string(contador);
	}
	else if (contador >= 10 && contador <= 99) {
		nuevo = "P0";
		nuevo += to_string(contador);
	}
	else {
		nuevo += to_string(contador);
	}
	return nuevo;
}
void main() {
	setlocale(LC_ALL, "");
	int opc_main, opc_paciente;
	//pacientes
	pacientes persona;
	historiales persona_hist;
	info_paciente datos_persona;
	string nombre_persona;
	//camas
	//pacientes con cama
	//INICIO MENÚ
	cout << "BIENVENIDO AL GESTOR HOSPITALARIO" << endl;
	do {
		cout << "MENÚ PRINCIPAL" << endl;
		cout << "1. Gestión de Pacientes \n2. GEstión de Camas \n3. Observación Pacientes camas \n4. Salir";
		cin >> opc_main;
		switch (opc_main) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			cout << "Guardando cambios..." << endl;
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opción invalida..." << endl;
			cout << "Intentar de nuevo..." << endl;
		}
	} while (opc_main != 4);
}