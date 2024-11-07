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
		cout << "\t" << nodo->reporte.datos.edad << "\t" << nodo->reporte.datos.motivo << "\t\t" << nodo->reporte.datos.estado;
		cout << "\t" << nodo->reporte.expediente.consultar_tope();
		nodo = nodo->sig;
		cout << endl;
	}
}
