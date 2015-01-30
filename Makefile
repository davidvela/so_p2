#/* 
# * Author: David Vela Tirado
# * Software Developer
# * email:  david.vela.tirado@gmail.com
# * 
# */

PHONY: clean
CFLAGS= -g -Wall -c
all: libp2.a practica2 practica2lib 

practica2: buscar.o contar.o practica2.o
	gcc buscar.o contar.o practica2.o -o practica2

practica2lib: practica2.o
	gcc practica2.o -L. -lp2 -o practica2lib
	
	
libp2.a: contar.o buscar.o
	ar rv libp2.a contar.o buscar.o 

buscar.o: buscar.c 
	gcc $(CFLAGS) buscar.c

contar.o: contar.c
	gcc $(CFLAGS) contar.c

practica2.o: practica2.c
	gcc $(CFLAGS) practica2.c

clean: 
	-rm -f *.o
	-rm -f practica2 practica2lib
	-rm -f libp2.a 
