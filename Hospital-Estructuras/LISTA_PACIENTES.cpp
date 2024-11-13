#include "LISTA_PACIENTES.h"

LISTA_PACIENTES::LISTA_PACIENTES()
{
	cabecera = fin = NULL;
}
//funcion encargada de que se inserten los pacientes nuevos en la lista
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
//funcion encargada de cambiar los datos de los pacientes para mantenerlos actualizados
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
			string actualiza;
			cout << "Nombre: " << nodo->reporte.datos.nombre << endl;
			do {
				cout << "\tINFORMACION A MODIFICAR" << endl;
				cout << "1. Edad \n2. Estado \n3. Motivo \n4. Expediente \n5. Salir " << endl;
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
					int opc;
					cout << "Desea agregar o elimar un expediente: \n1. agregar \n2. eliminar";
					cin >> opc;
					if (opc == 1) {
						cout << "Ingresa el nuevo expediente: ";
						cin.ignore();
						getline(cin, actualiza);
						nodo->reporte.expediente.insertar_historial(actualiza);
					}
					else if (opc == 2) {
						actualiza = nodo->reporte.expediente.extraer_historial();
						cout << "Se elimino el historial defectuoso del paciente quedo ahora " << nodo->reporte.expediente.consultar_tope() << endl;
					}
					break;
				case 5:
					cout << "Cerrando modificaciones..." << endl;
					break;
				default:
					cout << "Opción no válida." << endl;
					break;
				}
			} while (opc != 5);
			return;
		}
		nodo = nodo->sig;
	}
	cout << "Paciente con ID " << ID << " no encontrado." << endl;
}
//funcion encargada en mostrar los datos del paciente deseado
string LISTA_PACIENTES::buscar_paciente(string nombre)
{
	if (cabecera == NULL) {
		cout << "La lista está vacía." << endl;
		return "";
	}

	nodo = cabecera;
	while (nodo != NULL) {
		if (nodo->reporte.datos.nombre == nombre) {
			cout << "\tPaciente encontrado: " << endl;
			cout << "Nombre: " << nodo->reporte.datos.nombre << endl;
			cout << "ID: " << nodo->reporte.datos.ID << endl;
			cout << "Género: " << nodo->reporte.datos.genero << endl;
			cout << "Edad: " << nodo->reporte.datos.edad << endl;
			cout << "Motivo de ingreso: " << nodo->reporte.datos.motivo << endl;
			cout<< "Estado: " << (nodo->reporte.datos.estado ? "Dado de alta" : "No dado de alta") << endl;
			cout<<"Expedientes: "<< nodo->reporte.expediente.consultar_tope()<<endl; 
			return nodo->reporte.datos.ID;
		}
		nodo = nodo->sig;
	}
}
//funcion encargada de mostrar toda la lista de pacientes
void LISTA_PACIENTES::mostrar()
{
	int cont=0;
	cout << "\tINFORMACIÓN DE LOS PACIENTES" << endl;
	if (cabecera == NULL) {
		cout << "No hay pacientes registrados..." << endl;
		return;
	}
	nodo = cabecera;
	cout << "  Nombre\tID\tGénero\tEdad\tMotivo de Ingreso\tEstado\t\tExpediente" << endl;
	while (nodo != NULL) {
		cout << ++cont<<". " << nodo->reporte.datos.nombre << "\t\t" << nodo->reporte.datos.ID << "\t" << nodo->reporte.datos.genero;
		cout << "\t" << nodo->reporte.datos.edad << "\t" << nodo->reporte.datos.motivo << "\t\t";
		if (nodo->reporte.datos.estado) 
			cout << "Alta";
		else 
			cout << "No alta";
		cout << "\t\t" << nodo->reporte.expediente.consultar_tope();
		nodo = nodo->sig;
		cout << endl;
	}
}

