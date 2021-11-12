#include <semaphore.h>
#include "../include/struct.h"
#include "../include/funciones.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ejecucion(archivo* lectura)
{
	long unsigned int promedio=0;
	while(1)
	{
		/*
		 * Calcula el promedio, imprime el valor
		 */
		promedio=(promedio+lectura->validSamples)/2;
		printf("\rPromedio de validSamples: %ld",promedio);
		munmap(lectura, sizeof(lectura)); //Desmapeo el archivo de memoria para volver a leerlo

		lectura=obtener_estructura();
	}
}
