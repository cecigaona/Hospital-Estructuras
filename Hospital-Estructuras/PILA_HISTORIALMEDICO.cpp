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
//funcion encargada en obtener el tope
string PILA_HISTORIALMÉDICO::consultar_tope()
{
	if (tope == NULL) 
		return "sin historial";
	return tope->informe;
}
