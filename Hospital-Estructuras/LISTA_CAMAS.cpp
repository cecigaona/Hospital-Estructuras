#include "LISTA_CAMAS.h"

LISTA_CAMAS::LISTA_CAMAS() {

	arregloCamas = new Camas[CANTIDADCAMAS];
	Poblar();
}

void LISTA_CAMAS::Mostrar() {

    cout << "--------------------- Lista de Camas ---------------------" << endl;
    cout << "ID \tUbicacción \tEstado" << endl;
	for (int i = 0; i < CANTIDADCAMAS; i++) {
		cout << "#: " << arregloCamas[i].ID << "\t" << arregloCamas[i].ubicacion << "\t\t";
		if (arregloCamas[i].estado) 
            cout << "Ocupada";
		else 
            cout << "Desocupada";
        cout << endl;
	}

}

void LISTA_CAMAS::Poblar() {

    for (int j = 0; j < CANTIDADPISOS; j++) {

        for (int i = 0; i < CANTIDADCAMAS/CANTIDADPISOS; i++) {
            arregloCamas[(j*10) +i].ID = to_string((j*10)+ i + 1);
            arregloCamas[(j * 10) + i].ubicacion = "Piso " + to_string(j+1);
            arregloCamas[(j * 10) + i].estado = false;
            arregloCamas[(j * 10) + i].ID_paciente = "";
        }
    }
    
}

void LISTA_CAMAS::OcuparCama(string IDPaciente)
{

    for (int i = 0; i < CANTIDADCAMAS; i++) {

        if (!arregloCamas[i].estado) {
            arregloCamas[i].estado = true;
            arregloCamas[i].ID_paciente = IDPaciente;
            cout << "Paciente " << IDPaciente << " ha sido asignado a la cama " << arregloCamas[i].ID << " en " << arregloCamas[i].ubicacion << endl;
            return;
        }
    }
    cout << "No hay camas disponibles para el paciente" << endl;
 
}

void LISTA_CAMAS::DesocuparCama(string IDPaciente)
{
    if (!arregloCamas[0].estado) {

        cout << "No hay camas ocupadas" << endl; 
        return;

    }

    for (int i = 0; i < CANTIDADCAMAS; i++) {

        if (arregloCamas[i].ID_paciente == IDPaciente) {
            arregloCamas[i].estado = false;
            arregloCamas[i].ID_paciente = "";
            cout << "Cama de paciente " << IDPaciente << " ha sido liberada"<< endl;
            return;
        }
    }

    cout << "No se encontro el paciente" << endl;
}

LISTA_CAMAS::~LISTA_CAMAS() {
    delete[] arregloCamas;
}