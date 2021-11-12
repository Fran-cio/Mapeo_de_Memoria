#include <stdio.h>
#include "../include/struct.h"
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

archivo* obtener_estructura()
{
	archivo *lectura;
	int fd;
	fd = open("./rawdata/datos", O_RDONLY); //Obtengo el file descriptor
	if(fd==-1)
	{
		perror("open fail");
		exit(EXIT_FAILURE);
	}

	/*
	 * Mapeo el fd en algun lugar de la memoria comaprtida
	 */
	lectura=mmap(NULL, sizeof(lectura), PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);
	if (lectura==MAP_FAILED)
	{
		perror(" failed ");
		exit(EXIT_FAILURE);
	}
	else
	{
		return lectura;
	}
}

