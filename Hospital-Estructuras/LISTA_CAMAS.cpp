#include "LISTA_CAMAS.h"

LISTA_CAMAS::LISTA_CAMAS() {

	arregloCamas = new Camas[CANTIDADCAMAS];
	Poblar();
}

LISTA_CAMAS::~LISTA_CAMAS() {
	delete[] arregloCamas;  
}

void LISTA_CAMAS::Mostrar() {

	cout << "--------------------- Lista de Camas ---------------------" << endl << endl;
	for (int i = 0; i < CANTIDADCAMAS; i++) {
		cout << "ID: " << arregloCamas[i].ID << "\tUbicación: " << arregloCamas[i].ubicacion << "\tEstado: ";
		if (arregloCamas[i].estado) cout << "Ocupada" << endl;
		else cout << "Desocupada" << endl;
	}

}

void LISTA_CAMAS::Poblar() {
    int piso = 1;
    for (int i = 0; i < CANTIDADCAMAS; i++) {
        arregloCamas[i].ID = i + 1;

        if (i % 10 == 0 && i != 0) {
            piso++;
        }
        arregloCamas[i].ubicacion = "Piso " + to_string(piso);
        arregloCamas[i].estado = false;
		arregloCamas[i].IDPaciente = 0;
    }
}

void LISTA_CAMAS::OcuparCama(int IDPaciente)
{

    for (int i = 0; i < CANTIDADCAMAS; i++) {

        if (!arregloCamas[i].estado) {
            arregloCamas[i].estado = true;
            arregloCamas[i].IDPaciente = IDPaciente;
            cout << "Paciente " << IDPaciente << " ha sido asignado a la cama " << arregloCamas[i].ID << " en " << arregloCamas[i].ubicacion << endl;
            return;
        }
    }
    cout << "No hay camas disponibles para el paciente" << endl;
 
}

void LISTA_CAMAS::DesocuparCama(int IDPaciente)
{
    if (!arregloCamas[0].estado) cout << "No hay camas ocupadas" << endl; return;

    for (int i = 0; i < CANTIDADCAMAS; i++) {

        if (arregloCamas[i].IDPaciente == IDPaciente) {
            arregloCamas[i].estado = false;
            arregloCamas[i].IDPaciente = 0;
            cout << "Cama de paciente " << IDPaciente << " ha sido liberada"<< endl;
            return;
        }
    }

    cout << "No se encontro el paciente" << endl;
}
