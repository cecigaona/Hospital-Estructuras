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
	int opc_main, opc_paciente, opc_urgencias, opc_expediente, cont=0;
	//pacientes
	historiales persona_hist;
	info_paciente datos_persona;
	string nombre_persona, id_persona, expediente;
	FILA normal, urgencias;
	LISTA_PACIENTES l_pacientes;
	//camas
	Camas dato_camas;
	LISTA_CAMAS l_camas;
	//pacientes con cama
	cama_paciente registro;
	LISTA_CAMA_PACIENTES l_camas_pacientes;
	//INICIO MENÚ
	cout << "BIENVENIDO AL GESTOR HOSPITALARIO" << endl;
	do {
		cout << "MENÚ PRINCIPAL" << endl;
		cout << "1. Gestión de Pacientes \n2. GEstión de Camas \n3. Observación Pacientes camas \n4. Salir"<<endl;
		cin >> opc_main;
		system("cls");
		switch (opc_main) {
		case 1:
			do {
				cout << "\t MANEJADOR DE PACIENTES" << endl;
				cout << "1. Formarse \n2. Modificar paciente \n4. Salir" << endl;
				cin >> opc_paciente;
				if (opc_paciente < 3) {
					cout << "Dame el nombre del paciente:" << endl;
					cin.ignore();
					getline(cin, nombre_persona);
				}
				switch (opc_paciente) {
				case 1:
					cout << "¿El paciente entra por urgencias?" << endl;
					cout << "1. Si \n2. No " << endl;
					cin >> opc_urgencias;
					if (opc_urgencias == 1) {
						urgencias.insertar_fila(nombre_persona);
						cout << "Se formo en urgencias..." << endl;
						id_persona = l_pacientes.buscar_paciente(nombre_persona);
						if (id_persona == "") {
							datos_persona.datos.ID = generador_ID_paciente(++cont);
							cout<<"Dame el género de "<< nombre_persona<<":" << endl;
							cin.ignore();
							getline(cin, datos_persona.datos.genero);
							cout << "Dame el motivo de ingreso: " << endl;
							getline(cin, datos_persona.datos.motivo);
							cout << "Dame la edad de "<< nombre_persona<<":" << endl;
							cin >> datos_persona.datos.edad;
							datos_persona.datos.estado = false;
							cout << "¿Desea agregar un expediente? " << endl;
							cout << "1. Si \n2. No " << endl;
							cin >> opc_expediente;
							if (opc_expediente == 1) {
								cout << "Dame el expediente a insertar: " << endl;
								cin.ignore();
								getline(cin, expediente);
								datos_persona.expediente.insertar_historial(expediente);
							}
							datos_persona.datos.nombre = urgencias.extraer_fila();
							l_pacientes.insertar(datos_persona);
							dato_camas=l_camas.OcuparCama(datos_persona.datos.ID);
							registro.ID_cama = dato_camas.ID;
							registro.ubicacion = dato_camas.ubicacion;
							registro.ID_paciente = datos_persona.datos.ID;
							registro.nombre = datos_persona.datos.nombre;
							l_camas_pacientes.insertar(registro);
							l_pacientes.mostrar();
							l_camas_pacientes.mostrar();
							l_camas.Mostrar();
						}
					}
					else {
						normal.insertar_fila(nombre_persona);
						cout << "Se formo en la fila normal..." << endl;
					}
					break;
				case 2:
				case 3:
					cout << "Guardando cambios..." << endl;
					system("cls");
					break;
				default:
					cout << "Opción invalida..." << endl;
					cout << "Intentar de nuevo..." << endl;
					system("cls");
					break;
				}
			} while (opc_paciente != 3);
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
			break;
		}
	} while (opc_main != 4);
}