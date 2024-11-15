#include "Global.h"
#include "PILA_HISTORIALMEDICO.h"
#include "FILA.h"
#include "LISTA_CAMAS.h"
#include "LISTA_CAMA_PACIENTES.h"
#include "LISTA_PACIENTES.h"

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
	int opc_main, opc_paciente, opc_urgencias, opc_expediente, opc_lista, cont=0;
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
		cout << "1. Gestión de Pacientes \n2. Gestión de Camas \n3. Observación Pacientes camas \n4. Salir"<<endl;
		cin >> opc_main;
		system("cls");
		switch (opc_main) {
		case 1:
			do {
				//primer submenú de todo lo que conlleva los pacientes
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
					//Confirmar por donde entro el paciente
					cout << "¿El paciente entra por urgencias?" << endl;
					cout << "1. Si \n2. No " << endl;
					cin >> opc_urgencias;
					//si el paciente esta en urgencias asignar todo al momento
					if (opc_urgencias == 1) {
						urgencias.insertar_fila(nombre_persona);
						cout << "Se formo en urgencias..." << endl;
						id_persona = l_pacientes.buscar_paciente(nombre_persona);
						system("cls");
						//si la persona no esta en el sistema
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
							//luego luego se le asigna cama no permitiendo que quede gente formada en urgencias
							datos_persona.datos.nombre = urgencias.extraer_fila();
							//se inserta a la fila de pacientes
							l_pacientes.insertar(datos_persona);
							//se ocupa una cama
							dato_camas=l_camas.OcuparCama(datos_persona.datos.ID);
							registro.ID_cama = dato_camas.ID;
							registro.ubicacion = dato_camas.ubicacion;
							registro.ID_paciente = datos_persona.datos.ID;
							registro.nombre = datos_persona.datos.nombre;
							//se pasa a cama pacientes
							l_camas_pacientes.insertar(registro);
							system("cls");
						}
						//si la persona esta en el sistema se debe de actualizar
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
					//se forma en la fila normal y se antienden despues
					else {
						normal.insertar_fila(nombre_persona);
						cout << "Se formo en la fila normal..." << endl;
					}
					break;

				case 2:

					system("cls");
					cout << "Ingrese el nombre del paciente a modificar: ";
					cin.ignore();
					getline(cin, nombre_persona);
					id_persona = l_pacientes.buscar_paciente(nombre_persona);
					system("cls");
					if (id_persona != "") {
						l_pacientes.modificar_paciente(id_persona);
						cout << "Paciente modificado." << endl;
					}
					else {
						cout << "Paciente no encontrado." << endl;
					}
					
					break;

				case 3:

					system("cls");
					nombre_persona = normal.extraer_fila();

					if(nombre_persona == ""){
						cout << "No hay pacientes en espera." << endl;
						break;
					}

					cout << "Atendiendo a " << nombre_persona << endl;

					id_persona = l_pacientes.buscar_paciente(nombre_persona);

					if (id_persona == "") { 
						datos_persona.datos.ID = generador_ID_paciente(++cont);
						datos_persona.datos.nombre = nombre_persona;
						datos_persona.datos.estado = true; 
						l_pacientes.insertar(datos_persona);
						id_persona = datos_persona.datos.ID;
					}
					else {

						cout << "El paciente ya se encuentra con los pacientes siendo atendidos (posible bug??)" << endl;
						break;

					}

					dato_camas = l_camas.OcuparCama(id_persona);
					registro.ID_cama = dato_camas.ID;
					registro.ubicacion = dato_camas.ubicacion;
					registro.ID_paciente = id_persona;
					registro.nombre = nombre_persona;
					l_camas_pacientes.insertar(registro);
					system("cls");
					break;


				case 4:
					//mostrar fila o pacientes lista
					cout << "Elija que fila quiere mostrar (1.-Urgentes   2.-Normales" << endl;
					cin >> opc_lista;
					if (opc_lista == 1) {
						l_pacientes.Mostrar();
					}
					else if (opc_lista == 2) {

					}
					else {

						cout << "Opcion invalida" << endl;

					}
					break;

				case 5:
					cout << "Guardando cambios..." << endl;
					system("cls");
					break;
				default:
					cout << "Opción invalida..." << endl;
					cout << "Intentar de nuevo..." << endl;
					system("cls");
					break;
				}
			} while (opc_paciente != 5);
			break;
		case 2:
			l_camas.Mostrar();
			break;
		case 3:
			//ESTA MAL CREO, osea creo q no es lo q quiere cecisisabe, LUEGO DESCIFRO COMO HACERLO CORRECTAMENTE
			l_camas_pacientes.mostrar();
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