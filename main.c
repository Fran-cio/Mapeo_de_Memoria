#include "./include/struct.h"
#include "./include/funciones.h"
#include <stdio.h>

int main ()
{
	int num_de_struct;
	num_de_struct = obtener_num_de_struct("./rawdata/datos", sizeof(archivo));
	archivo *lectura;
	/*
	 * mapeo en la posicion de memoria al archivo
	 */
	obtener_estructura(&lectura,num_de_struct);
	/*
	 * Imprimo los valores dentro de la structura
	 */
	for (int i=0; i<num_de_struct;i++)
		imprimir(lectura[i]);
	/*
	 * Aca se calcula el promedio 
	 */
	/*ejecucion(lectura);*/
	int promedio=obtener_promedio_validSample(lectura, num_de_struct); 
	printf("Numero de Estructuras: %d\nPromedio de muestras valid Samples: %d\n",
			num_de_struct,promedio);
	
	return 0;	
}


