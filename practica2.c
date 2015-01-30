 /* 
# * Author: David Vela Tirado
# * Software Developer
# * email:  david.vela.tirado@gmail.com
# * 
  */

#include <unistd.h>  //contiene informacion para sistemas unix 
#include <stdio.h>
#include <fcntl.h> //me permite poner en la funcion open el flag en vez de como un int como un nombre  ((( O_RDONLY)))
#include <stdlib.h>//para el exit(0) no de warning y para la funcion atoi
#include "buscar.h"
#include "contar.h"



int main(int argc,char *argv[])
{
// estructura: programa char(b/c)  archivo posicion/caracter
	
int descriptor1;
char caracter;
int cuenta=0;
int f=0;

	
	if(argc != 4)
	{
		printf("el numero de argumentos es incorrecto\n");
		exit(0);

	}
	printf("el numero de argumentos es correcto\n");

//ahora voy a abrir el archivo:
//descriptor=open(argv[2],'r','r');
//descriptor= open ( argv[2],  O_RDONLY); 
//abro el archivo ((0-rdonly)) es una funcion incluida dentro de fcntl.h ((significa solo lectura))	
	
	
	
//comparo el char: 'b' -> buscar s, 'c'->contar
	if(*argv[1]=='b')
	{
		f=atoi(argv[3]);	//convierto de char a int		
		descriptor1= open ( argv[2],  O_RDONLY);
			
			if (descriptor1==-1) 	//compruebo quela apertura es correcta
			printf("error de apertura de fichero");
		
		
		caracter=(char)buscaCaracter(descriptor1,f);
		//printf("el caracter situado en la posicion %d es %c\n",*argv[3],caracter);
		//close(descriptor1);	//cierro el archivo

	}

	if(*argv[1]=='c')
	{	

		descriptor1= open ( argv[2],  O_RDONLY);
			if (descriptor1==-1) //comprobacion de que esta bien abierto
			printf("error de apertura de fichero");
		
		cuenta=(int)contarCaracteres(descriptor1,*argv[3]);
		//printf("el caracter /%c/ aparece  /%d/ veces\n\n",*argv[3] cuenta);
		//close(descriptor);//cierro el archivo

	}


	close(*argv[2]);
	return 0;


}
	
		

		


