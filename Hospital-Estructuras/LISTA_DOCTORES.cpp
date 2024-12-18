#include "LISTA_DOCTORES.h"

LISTA_DOCTORES::LISTA_DOCTORES()
{
	Poblar();
}

void LISTA_DOCTORES::Mostrar() {
    cout << "Lista de doctores disponibles:" << endl;
    for (int i = 0; i < MAXDOCTORES; i++) {
        cout << i + 1 << "- Nombre: " << doctores[i].nombre
        << "\t\tEspecialidad: " << doctores[i].especialidad
        << "\t\tCedula: " << doctores[i].cedula << endl;
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
        cout << "Opci�n no valida. Por favor, elija un numero entre 1 y "<< MAXDOCTORES << "." << endl;
    }
}

void LISTA_DOCTORES::MostrarNombreDoctor(int opc)
{
    if (opc > 0 && opc <= MAXDOCTORES) {
        Doctor doc = doctores[opc - 1];
        cout << doc.nombre;
    }
}

void LISTA_DOCTORES::Poblar() {
    string nombres[MAXDOCTORES] = {
        "Fer Pena", "Cecilia Ga", "Gabriel Al", "Pepe Po",
        "Karla Me", "Felipe Ca", "Benito Jua", "Donald Tr",
        "Oscar Di", "Lucia Mor"
    };

    string especialidades[MAXDOCTORES] = {
        "Cardiologia", "Pediatria   ", "Neurologia", "Dermatologia",
        "Oncologia   ", "Oftalmologia", "Psiquiatria", "Gastroenterologia",
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


