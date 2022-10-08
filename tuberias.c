
/*
---------------------------------------
         **Age quod agis**
-------------------------------------------
          tuberias.c
----------------------------------------
   Hilario Iglesias Martínez.        
------------------------------------------

Podríamos definir escuetamente las pipe,
como la comunicación entre dos procesos.
Podemos decir, estableciendo la similitud a
una tubería de fluidos, -en nuestro caso de octetos-,
que comunican dos extremos,
bajo  mecanismos de sincronización.
Para ello utilizamos un depósito buffer
donde almacenamos los datos
que serán enviados.

Otra de las utilidades de las pipes podría
ser encadenar comandos,que permitan
que la salida de un comando sirva como
la entrada a otro.

En este programa se usa una de estas 
utiliades, la comunicación de dos procesos padre e hijo,
a través de una pipe creado por el padre
como proceso hijo.


Llamando a la función pipe, el padre crea este proceso.
Una vez creado el pipe, el padre crea el proceso hijo
mediante la función fork. A partir de esa llamada,
los procesos se generan, idénticos, con sus correspondientes
descriptores.
Se utiliza la llamada write para
leer la frase incluida en el buffer reservado.

La seuencia resumida del programa podría serla siguiente:
PADRE.                     HIJO
--------                  ------            
Crea pipe.             Escribe mensaje 
Crea hijo.             Cierra.
Lee mensaje.
Cierra.

Algunos descriptores se eliminan cuando
no vuelven a ser utilizados.
-------------------------------------
| La diferencia fundamental entre    |
| las pipes y los socketpair, es que |
| los segundos son con flujo en los  |
| dos sentidos.                      |
 ------------------------------------ 
------------------------------------
Por otro lado, volcamos la disposición
del buffer con la frase elegida,
y su posición de inicio en la memoria.

También hacemos una llamada al PID,
-número identificador de proceso-, 
con el fin de ver la ejecución continuada
del programa, y sus aproximaciones,
o áreas de memoria.

Se puede indagar y jugar con el programa
sobre su funcionamiento, modificando
parámetros, sobre los detalles generales
del mismo.
Con este fin está hecho.
Se puede jugar y mejorar.
**************************************************
**************************************************
Compilar:
$ gcc -Wall -Werror  -o tuberias tuberias.c
-------------------------------------------
Ejecutar:
$ ./tuberias

*/

#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
char buf[1048];
#define MENSAJE "AMOR OMNIBUS IDEM - HUMILITAS OCCIDIT SUPERBIAN"
int salida;
void El_Pid();

void El_Pid()
{
	
    char comando[60];	/* Comando a ejecutar */
	long int pid;
pid=getpid();
printf("\n");
    
    sprintf (comando, "pmap  -d %ld", pid);
    salida = system (comando);
 
	
}
	
int main(int argc, char const *argv[])
{
printf("*************************************************************\n");	 

int PADRE[2], EL_HIJO;
if (pipe(PADRE)<0)
{
	perror("abriendo el par de descriptores");
	exit(1);
}


if ((EL_HIJO=fork())==-1)
	
{
	perror("Error creando el proceso hijo");
	exit(2);
}

El_Pid();
if (EL_HIJO !=0) //Este es el padre)
{
printf("Descriptor EL_HIJO [%d] [Dirección]%p\n",EL_HIJO,&EL_HIJO);		
	
close(PADRE[1]);
if (read(PADRE[0],buf,1024)<0)
	perror("leyendo mensaje");

printf("********************************************************\n");

printf("DIRECCIÓN MEMORIA DEL INICIO DEL BUFFER MENSAJE:%p\n",&buf );
/*Rutina de volcado*/
char Codigo_ascii[17];
int i;
 
for (i = 0; i < 64; ++i) {
        printf("%02X ", ((unsigned char*)buf)[i]);
        if (((unsigned char*)buf)[i] >= ' ' && ((unsigned char*)buf)[i] <= '~')
         {
            Codigo_ascii[i % 16] = ((unsigned char*)buf)[i];
        } else {
            Codigo_ascii[i % 16] = '.';
        }
        if ((i+1) % 8 == 0 || i+1==64) {
            printf(" ");
            if ((i+1) % 16 == 0) {

                printf(" |  %s \n", Codigo_ascii);
 
}}}

printf("\n");
printf("---------------------------------------------------------\n");
printf("Descriptor PADRE[0] [%d] [Dirección]%p\n",PADRE[0],&PADRE);

close(PADRE[0]);
}
else{ //es el hijo
close(PADRE[0]);
if(write(PADRE[1],MENSAJE,strlen(MENSAJE)+1)<0)
	
perror("error escribiendo MENSAJE");
printf("Descriptor PADRE[1] %d [Dirección]%p\n",PADRE[1],&PADRE);
close(PADRE[1]);
   
}
El_Pid();
printf("**************************************\n");

}









	