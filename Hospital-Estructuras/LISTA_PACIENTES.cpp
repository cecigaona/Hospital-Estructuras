#include "LISTA_PACIENTES.h"

LISTA_PACIENTES::LISTA_PACIENTES()
{
	cabecera = fin = NULL;
}

void LISTA_PACIENTES::insertar(info_paciente nuevo_paciente)
{
	nodo = new beneficiario;
	nodo->reporte = nuevo_paciente;
	if (cabecera == NULL && fin == NULL) {
		nodo->sig = cabecera;
		cabecera = nodo;
		fin = nodo;
		return;
	}
	nodo->sig = NULL;
	fin->sig = nodo;
	fin = nodo;
}

void LISTA_PACIENTES::modificar_paciente(string ID)
{
	if (cabecera == NULL) {
		cout << "No hay pacientes almacenados" << endl;
		return;
	}
	int opc;
	nodo = cabecera;
	while (nodo != NULL) {
		if (nodo->reporte.datos.ID == ID) {
			cout << "Nombre: " << nodo->reporte.datos.nombre << endl;
			do {
				cout << "\tINFORMACION A MODIFICAR" << endl;
				cout << "1. Edad \n2. Estado \n3. Motivo \n4. Salir " << endl;
				cin >> opc;
				switch (opc) {
				case 1:
					cout << "Ingresa la nueva edad: ";
					cin >> nodo->reporte.datos.edad;
					break;
				case 2:
					int estado;
					cout << "De alta: \n1. si \n2. no";
					cin >> estado;
					if (estado == 1)
						nodo->reporte.datos.estado = true;
					else
						nodo->reporte.datos.estado = false;
					break;
				case 3:
					cout << "Ingresa el nuevo motivo de ingreso: ";
					cin.ignore();
					getline(cin, nodo->reporte.datos.motivo);
					break;
				case 4:
					cout << "Cerrando modificaciones..." << endl;
					break;
				default:
					cout << "Opción no válida." << endl;
					break;
				}
			} while (opc != 4);
			return;
		}
		nodo = nodo->sig;
	}
	cout << "Paciente con ID " << ID << " no encontrado." << endl;
}

void LISTA_PACIENTES::buscar_paciente(string ID)
{
	if (cabecera == NULL) {
		cout << "La lista está vacía." << endl;
		return;
	}

	nodo = cabecera;
	while (nodo != NULL) {
		if (nodo->reporte.datos.ID == ID) {
			cout << "\tPaciente encontrado: " << endl;
			cout << "Nombre: " << nodo->reporte.datos.nombre << endl;
			cout << "ID: " << nodo->reporte.datos.ID << endl;
			cout << "Género: " << nodo->reporte.datos.genero << endl;
			cout << "Edad: " << nodo->reporte.datos.edad << endl;
			cout << "Motivo de ingreso: " << nodo->reporte.datos.motivo << endl;
			cout<< "Estado: " << (nodo->reporte.datos.estado ? "Dado de alta" : "No dado de alta") << endl;
			cout<<"Expedientes: "<< nodo->reporte.expediente.consultar_tope()<<endl; 
			return;
		}
		nodo = nodo->sig;
	}
}

void LISTA_PACIENTES::mostrar()
{
	int cont=0;
	cout << "\tINFORMACIÓN DE LOS PACIENTES" << endl;
	if (cabecera == NULL) {
		cout << "No hay pacientes registrados..." << endl;
		return;
	}
	nodo = cabecera;
	cout << "  Nombre\tID\tGénero\tEdad\tMotivo de Ingreso\tAlta\tExpediente" << endl;
	while (nodo != NULL) {
		cout << ++cont<<". " << nodo->reporte.datos.nombre << "\t\t" << nodo->reporte.datos.ID << "\t" << nodo->reporte.datos.genero;
		cout << "\t" << nodo->reporte.datos.edad << "\t" << nodo->reporte.datos.motivo << "\t\t";
		if (nodo->reporte.datos.estado) 
			cout << "Dado de alta";
		else 
			cout << "No dado de alta";
		cout << "\t" << nodo->reporte.expediente.consultar_tope();
		nodo = nodo->sig;
		cout << endl;
	}
}
