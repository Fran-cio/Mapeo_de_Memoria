#include "../include/struct.h"

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
/*
 * Recorro e imprimo todos los valores
 */
void imprimir(archivo archivo)
{
	printf("version: %d\n",archivo.version);
	printf("drxVersion: %d\n",archivo.drxVersion);
	printf("reservado1: %s\n",archivo.reservado1);
	printf("initCW: %lf\n",archivo.initCW);
	printf("azimuth: %f\n",archivo.azimuth);
	printf("elevation: %f\n",archivo.elevation);
	printf("idVolume: %d\n",archivo.idVolume);
	printf("idBarrido: %d\n",archivo.idBarrido);
	printf("idCnjunto: %d\n",archivo.idCnjunto);
	printf("idGrupo: %d\n",archivo.idGrupo);
	printf("idPulso: %d\n",archivo.idPulso);
	printf("iniBarrido: %d\n",archivo.iniBarrido);
	printf("finBarrido: %d\n",archivo.finBarrido);
	printf("finGrupo: %d\n",archivo.finGrupo);
	printf("inhibido: %d\n",archivo.inhibido);
	printf("validSamples: %d\n",archivo.validSamples);
	printf("nroAdquisicion: %d\n",archivo.nroAdquisicion);
	printf("reservado2: %s\n",archivo.reservado2);
	printf("nroSecuencia: %d\n",archivo.nroSecuencia);
	printf("readTime_high: %lu\n",archivo.readTime_high);
	printf("readTime_low: %lu\n",archivo.readTime_low);
	printf("reservado3: %s\n",archivo.reservado3);
	printf("\n\n");
}

void obtener_estructura(archivo** lectura,int num_de_struct)
{
	int fd;
	fd = open("./rawdata/datos", O_RDONLY); //Obtengo el file descriptor
	if(fd==-1)
	{
		perror("open fail");
		exit(EXIT_FAILURE);
	}

	/*
	 * Mapeo el fd en algun lugar de la memoria 
	 */
	*lectura=mmap(NULL, sizeof(archivo)*num_de_struct, PROT_READ|PROT_WRITE,
			MAP_PRIVATE, fd, 0);
	/*
	 * La idea es que mapeo consecutivamente el tamaño de la estructura el numero
	 * de estructuras que haya calculado, de esa manera cada movimiento de puntero
	 * del tamaño de la estructura, accedo a cada una de manera individual
	 */
	close(fd);
	if (lectura==MAP_FAILED)
	{
		perror(" failed ");
		exit(EXIT_FAILURE);
	}
}
/*
 * La idea es que el tamaño del archivo, dividido el tamaño de la estructura 
 * me va a dar el numero de estructuras que esta aloja
 */
int obtener_num_de_struct(char* path, int size_de_struct)
{
	int num_de_struct;
	int fd_data;
	struct stat st;
	fd_data = open(path, O_RDONLY);
	if (fd_data==-1)
	{
		perror("error al abrir archivo");
		exit(EXIT_FAILURE);
	}
	fstat(fd_data, &st);

	num_de_struct = st.st_size/size_de_struct;
	close(fd_data);
	return num_de_struct;
}
/*
 * Calculo la suma de cada valor en el archivo y lo divido por el numero de
 * estructuras
 */
int obtener_promedio_validSample(archivo* lectura, int num_de_struct)
{
	int promedio=0;
	for (int i=0;i<num_de_struct ; i++)
		promedio+=lectura[i].validSamples;

	promedio/=num_de_struct;
	return promedio;
}

