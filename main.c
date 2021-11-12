#include "./include/struct.h"
#include "./include/funciones.h"
#include "./include/ejecutor.h"

int main ()
{
	/*
	 * mapeo en la posicion de memoria al archivo
	 * Y genero el semaforo binario para trabajar con concurrentemente
	 */
	archivo *lectura= obtener_estructura();
	sem_t *semaforo=set_semaforo();

	/*
	 * Imprimo los valores dentro de la structura
	 */
	imprimir(*lectura);

	/*
	 * Aca se calcula el promedio y se simula un cambio en la variable
	 */
	ejecucion(semaforo,lectura);
	
	return 0;	
}


