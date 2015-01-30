 /* 
# * Author: David Vela Tirado
# * Software Developer
# * email:  david.vela.tirado@gmail.com
# * 
  */
#include <stdio.h>
#include <unistd.h>
#include "buscar.h"
#include <stdio.h>
#include <stdlib.h>  //permite poner seek_set
#include <fcntl.h>   


char buscaCaracter(int fd,int posicion)
{
	
	char  caracter;
	int bytesleidos;
	
	lseek(fd,posicion,SEEK_SET);
	bytesleidos=read(fd,&caracter,1);//si los bytes leidos son distintos de -1 no hay error
		if(bytesleidos==(-1)) 
			printf("ha abido un error al leer");
		else
			printf("\nel caracter situado en la posicion /%d/ es /%c/ \n",posicion,caracter); //imprimo el caracter leido

	return(caracter);
}
