CC=gcc
CFLAGS=-Wall -Werror -pedantic  
PATHh=./include/
PATHrec=./src/
PATHout=./out/
PATHlib=./lib/
PATHbin=./bin/

Tp6: $(PATHbin)main

main_gdb: main.c $(PATHrec)funciones.c 
	mkdir -p $(PATHbin)
	$(CC) $(CFLAGS) -o $(PATHbin)main_gdb main.c $(PATHrec)funciones.c -g
	
$(PATHbin)main: $(PATHout)main.o $(PATHlib)lib_tp6.a 
	mkdir -p $(PATHbin)
	$(CC) $(CFLAGS) -o $(PATHbin)main $(PATHout)main.o -L$(PATHlib) -l_tp6 
	
$(PATHlib)lib_tp6.a: $(PATHout)funciones.o 
	mkdir -p $(PATHlib) 
	ar cr $(PATHlib)lib_tp6.a $(PATHout)funciones.o 

$(PATHout)main.o: main.c 
	mkdir -p $(PATHout)
	$(CC) $(CFLAGS) -c main.c
	mv ./main.o $(PATHout)/main.o

$(PATHout)funciones.o: $(PATHrec)funciones.c  
	$(CC) $(CFLAGS) -c $(PATHrec)funciones.c 
	mv ./funciones.o $(PATHout)

clean:
	rm -f -d $(PATHlib)* $(PATHlib) $(PATHout)* $(PATHout) $(PATHbin)* $(PATHbin) 




