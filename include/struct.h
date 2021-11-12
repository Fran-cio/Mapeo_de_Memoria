#ifndef STRUCT

#define STRUCT
#include <stdbool.h>
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
#endif
