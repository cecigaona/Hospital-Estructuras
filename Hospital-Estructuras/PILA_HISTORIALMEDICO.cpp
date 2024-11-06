#include "PILA_HISTORIALMEDICO.h"

PILA_HISTORIALMÉDICO::PILA_HISTORIALMÉDICO()
{
	tope = NULL;
}
//funcion encargada en agregar los nuevos historiales del paciente
void PILA_HISTORIALMÉDICO::insertar_historial(string actualiza)
{
	nodo = new historiales;
	nodo->informe = actualiza;
	nodo->dir = tope;
	tope = nodo;
}
//funcion encargada en sacar la informacion actual del paciente
string PILA_HISTORIALMÉDICO::extraer_historial()
{
	historiales* extraido;
	string informe_actual;
	if (tope == NULL)
		return "";//esto es si esta vacío
	extraido = tope;
	tope = extraido->dir;
	informe_actual = extraido->informe;
	delete extraido;
	return informe_actual;

}
//funcion encargada en que se pueda mostrar solo el informe actual del paciente
void PILA_HISTORIALMÉDICO::mostrar_tope()
{
	cout << "\tHISTORIAL MÉDICO " << endl;
	if (tope == NULL) {
		cout << "No hay un registro del historial" << endl;
		return;
	}
	cout << "\t Informe actual: " << tope->informe << endl;
}
