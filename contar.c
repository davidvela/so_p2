 /* 
# * Author: David Vela Tirado
# * Software Developer
# * email:  david.vela.tirado@gmail.com
# * 
  */
#include "contar.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int contarCaracteres(int descriptor,char caracter)
{
	int tam;
	char* puntero;
	int i=0;
	int contador=0;

	tam=(int)lseek(descriptor,0,SEEK_END);
	puntero=(char*) mmap(0,tam,PROT_READ,MAP_SHARED,descriptor,0);
	//puntero=(char*)mmap(0, 100, PROT_READ, MAP_SHARED, descriptor, 0);	

	for(i=0; i<tam; i++)
	{ if(puntero[i]==caracter)
		contador++;
	
	}

printf("el caracter /%c/ aparece  /%d/ veces\n\n",caracter,contador);	

return (contador);

}

