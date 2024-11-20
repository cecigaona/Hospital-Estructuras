#include "Global.h"
#include "PILA_HISTORIALMEDICO.h"
#include "FILA.h"
#include "LISTA_CAMAS.h"
#include "LISTA_CAMA_PACIENTES.h"
#include "LISTA_PACIENTES.h"
#include "LISTA_DOCTORES.h"

//funcion encargada en crear los ids de los pacientes
string generador_ID_paciente() {
	static int contador = 1;
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
	contador++;
	return nuevo;
}
void main() {
	setlocale(LC_ALL, "");
	int opc_main, opc_paciente, opc_urgencias, opc_expediente, opc_lista, opc_doctor, estado;
	//pacientes
	historiales persona_hist;
	info_paciente datos_persona, datos_persona2;
	string nombre_persona, nombre_persona2, id_persona, id_persona2, expediente;
	FILA normal, urgencias;
	LISTA_PACIENTES l_pacientes;
	//camas
	Camas dato_camas;
	LISTA_CAMAS l_camas;
	//pacientes con cama
	cama_paciente registro, alta;
	LISTA_CAMA_PACIENTES l_camas_pacientes;
	//doctores disponibles
	LISTA_DOCTORES l_doctores;

	//INICIO MENÚ
	cout << "BIENVENIDO AL GESTOR HOSPITALARIO" << endl;
	do {
		system("cls");
		cout << "MENÚ PRINCIPAL" << endl;
		cout << "1. Gestión de Pacientes \n2. Gestión de Camas \n3. Observación Pacientes camas \n4. Salir"<<endl;
		cin >> opc_main;
		system("cls");
		switch (opc_main) {
		case 1:
			//submenú de todo lo que conlleva los pacientes
			cout << "\t MANEJADOR DE PACIENTES" << endl;
			cout << "1. Formarse \n2. Modificar paciente \n3. Atender pacientes \n4. Mostrar Pacientes \n5. Salir" << endl;
			cin >> opc_paciente;
			if (opc_paciente < 2) {
				cout << "Dame el nombre del paciente:" << endl;
				cin.ignore();
				getline(cin, nombre_persona);
				system("cls");
			}
			switch (opc_paciente) {
			case 1:
				// Confirmar por donde entro el paciente
				cout << "¿El paciente entra por urgencias?" << endl;
				cout << "1. Si \n2. No " << endl;
				cin >> opc_urgencias;

				// Si el paciente esta en urgencias asignar todo al momento
				if (opc_urgencias == 1) {
					urgencias.insertar_fila(nombre_persona);
					cout << "Se formó en urgencias..." << endl;
					id_persona = l_pacientes.buscar_paciente(nombre_persona);
					system("cls");

					// Si la persona no está en el sistema, se crea como nuevo paciente
					if (id_persona == "") {
						l_doctores.Mostrar();
						do {
							cout << endl << "Seleccione doctor que quiera asignar (1-10): ";
							cin >> opc_doctor;
							if (opc_doctor < 1 || opc_doctor > 10) cout << "Ingrese doctor válido" << endl;
						} while (opc_doctor < 1 || opc_doctor > 10);
						l_doctores.MostrarDoctorEspecifico(opc_doctor);

						// Crear un nuevo paciente
						datos_persona.datos.numeroDeDoctor = opc_doctor;
						datos_persona.datos.ID = generador_ID_paciente();
						cout << "Dame el género de " << nombre_persona << ":" << endl;
						cin.ignore();
						getline(cin, datos_persona.datos.genero);
						cout << "Dame el motivo de ingreso: " << endl;
						getline(cin, datos_persona.datos.motivo);
						cout << "Dame la edad de " << nombre_persona << ":" << endl;
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

						// Asignar cama al paciente
						datos_persona.datos.nombre = urgencias.extraer_fila(); // Asignar nombre al paciente de urgencias
						l_pacientes.insertar(datos_persona); // Insertar paciente en lista
						dato_camas = l_camas.OcuparCama(datos_persona.datos.ID);

						// Registrar paciente en camas
						registro.ID_cama = dato_camas.ID;
						registro.ubicacion = dato_camas.ubicacion;
						registro.ID_paciente = datos_persona.datos.ID;
						registro.nombre = datos_persona.datos.nombre;
						l_camas_pacientes.insertar(registro);

						system("cls");
					}
					// Si la persona está en el sistema, solo actualiza la cama
					else {
						l_pacientes.modificar_paciente(id_persona);
						dato_camas = l_camas.OcuparCama(id_persona);
						registro.ID_cama = dato_camas.ID;
						registro.ubicacion = dato_camas.ubicacion;
						registro.ID_paciente = id_persona;
						registro.nombre = nombre_persona;
						l_camas_pacientes.insertar(registro);
						system("cls");
					}
				}
				// Si el paciente no entra por urgencias, se forma en la fila normal
				else {
					normal.insertar_fila(nombre_persona);
					cout << "Se formó en la fila normal..." << endl;
				}
				break;
			case 2:
				//modificar el paciente
				system("cls");
				cout << "Ingrese el nombre del paciente a modificar: ";
				cin.ignore();
				getline(cin, nombre_persona);
				id_persona = l_pacientes.buscar_paciente(nombre_persona);
				system("cls");
				if (id_persona != "") {
					estado = l_pacientes.modificar_paciente(id_persona);
					if (estado == 1) {
						l_camas.DesocuparCama(id_persona);
						registro.ID_paciente = id_persona;
						alta = l_camas_pacientes.extraer(registro);
						cout << "Se dio de alta: " << alta.nombre << " cama " << alta.ID_cama << " liberada..." << endl;
					}
					else if (estado == -1)
						cout << "No hay pacientes por modificar..." << endl;
					else
						cout << "Paciente modificado..." << endl;
				}
				else {
					cout << "Paciente no encontrado..." << endl;
				}
				break;
			case 3:
				// Atender al siguiente paciente en la fila normal
				system("cls");
				nombre_persona2 = normal.extraer_fila();

				if (nombre_persona2 == "") {
					cout << "No hay pacientes en espera." << endl;
					break;
				}

				cout << "Atendiendo a " << nombre_persona2 << endl;
				id_persona2 = l_pacientes.buscar_paciente(nombre_persona2);

				// Si el paciente no existe, se crea como un nuevo paciente
				if (id_persona2 == "") {
					l_doctores.Mostrar();
					do {
						cout << endl << "Seleccione doctor que quiera asignar (1-10): ";
						cin >> opc_doctor;
						if (opc_doctor < 1 || opc_doctor > 10) cout << "Ingrese doctor válido" << endl;
					} while (opc_doctor < 1 || opc_doctor > 10);

					l_doctores.MostrarDoctorEspecifico(opc_doctor);
					datos_persona2.datos.numeroDeDoctor = opc_doctor;
					datos_persona2.datos.ID = generador_ID_paciente();
					cout << "Dame el género de " << nombre_persona2 << ":" << endl;
					cin.ignore();
					getline(cin, datos_persona2.datos.genero);
					cout << "Dame el motivo de ingreso: " << endl;
					getline(cin, datos_persona2.datos.motivo);
					cout << "Dame la edad de " << nombre_persona2 << ":" << endl;
					cin >> datos_persona2.datos.edad;
					datos_persona2.datos.estado = false;

					// Preguntar por expediente
					cout << "¿Desea agregar un expediente? " << endl;
					cout << "1. Si \n2. No " << endl;
					cin >> opc_expediente;
					if (opc_expediente == 1) {
						cout << "Dame el expediente a insertar: " << endl;
						cin.ignore();
						getline(cin, expediente);
						datos_persona2.expediente.insertar_historial(expediente);
					}

					datos_persona2.datos.nombre = nombre_persona2;
					l_pacientes.insertar(datos_persona2);
					dato_camas = l_camas.OcuparCama(datos_persona2.datos.ID);

					// Registrar en camas
					registro.ID_cama = dato_camas.ID;
					registro.ubicacion = dato_camas.ubicacion;
					registro.ID_paciente = datos_persona2.datos.ID;
					registro.nombre = datos_persona2.datos.nombre;
					l_camas_pacientes.insertar(registro);
					system("cls");
				}
				else {
					// Si el paciente ya existe, se modifica y asigna cama
					l_pacientes.modificar_paciente(id_persona2);
					dato_camas = l_camas.OcuparCama(id_persona2);
					registro.ID_cama = dato_camas.ID;
					registro.ubicacion = dato_camas.ubicacion;
					registro.ID_paciente = id_persona2;
					registro.nombre = nombre_persona2;
					l_camas_pacientes.insertar(registro);
					system("cls");
				}
				break;

			case 4:
				//mostrar fila o pacientes lista
				cout << "Elija que fila quiere mostrar (1.-Formados   2.-Admitidos)" << endl;
				cin >> opc_lista;
				if (opc_lista == 1) 
					normal.mostrar();
				else if (opc_lista == 2) 
					l_pacientes.Mostrar();	
				else 
					cout << "Opcion invalida" << endl;
				break;
			case 5:
				//salir del sistema
				cout << "Guardando cambios..." << endl;
				system("cls");
				break;
			default:
				cout << "Opción invalida..." << endl;
				cout << "Intentar de nuevo..." << endl;
				system("cls");
				break;
			}
			break;
		case 2:
			//mostrar las camas
			l_camas.Mostrar();
			cout << endl;
			break;
		case 3:
			//mostrar las camas ocupadas con sus pacientes
			l_camas_pacientes.mostrar();
			break;
		case 4:
			cout << "Guardando cambios..." << endl;
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opción invalida..." << endl;
			cout << "Intentar de nuevo..." << endl;
			system("cls");
			break;
		}
	} while (opc_main != 4);
}