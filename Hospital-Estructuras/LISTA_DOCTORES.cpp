#include "LISTA_DOCTORES.h"

LISTA_DOCTORES::LISTA_DOCTORES()
{
	Poblar();
}

void LISTA_DOCTORES::Mostrar() {
    cout << "Lista de doctores disponibles:" << endl;
    for (int i = 0; i < MAXDOCTORES; i++) {
        cout << i + 1 << "Nombre: " << doctores[i].nombre
        << "\tEspecialidad: " << doctores[i].especialidad
        << "\tCedula: " << doctores[i].cedula << endl;
    }
}

void LISTA_DOCTORES::MostrarDoctorEspecifico(int opcion) {
    if (opcion > 0 && opcion <= MAXDOCTORES) {
        Doctor doc = doctores[opcion - 1];
        cout << "Doctor seleccionado:" << endl;
        cout << "Nombre: " << doc.nombre << endl;
        cout << "Especialidad: " << doc.especialidad << endl;
        cout << "Cedula: " << doc.cedula << endl;
    }
    else {
        cout << "Opción no valida. Por favor, elija un numero entre 1 y "<< MAXDOCTORES << "." << endl;
    }
}

void LISTA_DOCTORES::Poblar() {
    string nombres[MAXDOCTORES] = {
        "Fer Pena", "Cecilia Gaona", "Gabriel Alvarez", "Pepe Pio",
        "Karla Mendoza", "Felipe Calderon", "Benito Juarez", "Donald Trump",
        "Oscar Diaz", "Lucia Morales"
    };

    string especialidades[MAXDOCTORES] = {
        "Cardiologia", "Pediatria", "Neurologia", "Dermatologia",
        "Oncologia", "Oftalmologia", "Psiquiatria", "Gastroenterologia",
        "Neumologia", "Endocrinologia"
    };

    int cedulas[MAXDOCTORES] = {
        123456, 234567, 345678, 456789,
        112233, 223344, 445566, 776688,
        121212, 999999
    };

    for (int i = 0; i < MAXDOCTORES; ++i) {
        doctores[i].nombre = nombres[i];
        doctores[i].especialidad = especialidades[i];
        doctores[i].cedula = cedulas[i];
    }
}


