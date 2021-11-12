#include <semaphore.h>
#include "../include/struct.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void generar_valores(sem_t* semaforo,archivo* lectura);

void ejecucion(sem_t* semaforo,archivo* lectura)
{
	long unsigned int promedio=0;
	if(fork()==0)
	{
		generar_valores(semaforo,lectura);
	}
	while(1)
	{
		/*
		 * El proceso padre obtiene el mutex, calcula el promedio, imprime el valor
		 * y hace un pequeño delay antes de liberar el mutex
		 */
		sem_wait(semaforo);
		promedio=(promedio+lectura->validSamples)/2;
		printf("\rPromedio de validSamples: %ld",promedio);
		usleep(1000);
		sem_post(semaforo);
	}
}

void generar_valores(sem_t* semaforo,archivo* lectura)
{
	long unsigned int valor_Nuevo=lectura->validSamples;
	while (1) 
	{
		sem_wait(semaforo);
		/*
		 * Cambia el valor en mas menos 100, es para simular un valor nuevo
		 */
		lectura->validSamples=valor_Nuevo-rand () % (100) ; 	
		sem_post(semaforo);
	}
	exit(0);
}
