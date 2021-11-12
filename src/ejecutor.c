#include <semaphore.h>
#include "../include/struct.h"
#include "../include/funciones.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define NUM_PROM 10

void manejo_sig(int sig);
unsigned long int hacer_suma(unsigned long int []);

void ejecucion(archivo* lectura)
{
	signal(SIGINT, manejo_sig);
	
	int i=0;
	/*
	 * genero un buffer circular de tamaño NUM_PROM del cual obtengo el promedio
	 * esto se hizo de este modo con ek fin de obtener un estimativo del promedio
	 * con algunos valores
	 */
	long unsigned int valores[NUM_PROM] = {0};
	long unsigned int promedio;
	while(1)
	{
		/*
		 * Calcula el promedio, imprime el valor
		 */
		valores[i]=lectura->validSamples; //agrego la lectura al arreglo
		promedio=hacer_suma(valores); //Obtengo el promedio del arreglo

		printf("\rPromedio de validSamples: %ld",promedio);
		if(munmap(lectura, sizeof(lectura))==-1) //Desmapeo el archivo de memoria para volver a leerlo
		{
			perror("fallo munmap");
			exit(EXIT_FAILURE);
		}
		i++;
		if(i>NUM_PROM)
			i=0;
		lectura=obtener_estructura();
	}
}

void manejo_sig(int sig)
{
	printf("\nFin del programa");
	exit(EXIT_SUCCESS);
}

unsigned long int hacer_suma(unsigned long int valores[])
{
	long unsigned int promedio=0;

for (int j=0; j<NUM_PROM; j++)
		{
			promedio=promedio+valores[j];
		}
		return promedio/NUM_PROM;
}
