#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
typedef struct
{
	short unsigned int version,
							drxVersion;
	char reservado1[4];
	double initCW;
	float azimuth,
				elevation;
	short unsigned int idVolume,
							 idBarrido,
							 idCnjunto,
							 idGrupo,
							 idPulso;
	bool iniBarrido,
			 finBarrido,
			 finGrupo,
			 inhibido;
	unsigned int validSamples,
							 nroAdquisicion;
	char reservado2[2];
	unsigned int nroSecuencia;
	long unsigned int	readTime_high,
							readTime_low;
	char reservado3[64];
}archivo;

void imprimir(archivo);

int main ()
{
	int fd;
	fd = open("./rawdata/datos", S_IRWXG);
	archivo *lectura;
	lectura = mmap(NULL, sizeof(lectura), PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);

	imprimir(*lectura);
	printf("\n\n");
	long unsigned int promedio=0;
	/*char opt;*/
	while(1)
	{
		/*opt=fgetc(stdin);*/
		/*if(opt ==EOF)*/
			/*exit(EXIT_FAILURE);*/
		/*else if (opt=='q') */
			/*break;*/
		promedio=(promedio+lectura->validSamples)/2;
		printf("\r prom validSamples: %ld ",promedio);
	}
	return 0;	
}
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
}
