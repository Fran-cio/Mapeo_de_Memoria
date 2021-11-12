#include "./include/struct.h"
#include "./include/funciones.h"
#include "./include/ejecutor.h"

int main ()
{
	/*
	 * mapeo en la posicion de memoria al archivo
	 */
	archivo *lectura= obtener_estructura();
	/*
	 * Imprimo los valores dentro de la structura
	 */
	imprimir(*lectura);

	/*
	 * Aca se calcula el promedio y se simula un cambio en la variable
	 */
	ejecucion(lectura);
	
	return 0;	
}


