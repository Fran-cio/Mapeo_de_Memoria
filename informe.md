# TP6
## Aclaraciom
Es interesante ver los commits anteriores para ver como interprete la consigna mal e hice malabares de los cuales me siento orgulloso porque quedaron bastente bien y hubo aprendizajes interensantes

## Mapeo en Memoria
Conceptualmente tengo un archivo que necesito mapear en memoria, y este archivo contiene campos que tengo que leer. Para esto utilizo una structura que me permita acceder a los campos segmentados por el tamaño de memoria que le corresponde a cada campo. 


Posteriormente genero un puntero a esta estructura para utilizar de manera que mapee el archivo en la posicion donde yo tengo un conjunto de estructuras contiguas, de esta manera cada longitud de estructura accedo al campo que elija.


## Numero de Estructuras
Previamente hago una comparacion entre el tamaño del archivo y el tamaño de mi estructura en bytes, de tal manera que _(TamañoArchivo)/(TamañoDeEstructura)_ me va a dar la cantidad de estructuras contenidas en el archivo.

## Calculo del promedio de validSamples
Dado que tengo acceso sencillo a cada campo de las estructuras, es muy sencillo sumar cada valor de muestra y despues dividirlo entre el numero de muestras
