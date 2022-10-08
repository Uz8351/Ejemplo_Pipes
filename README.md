# Ejemplo_Pipes
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
 La diferencia fundamental entre    
 las pipes y los socketpair, es que 
 los segundos son con flujo en los  
 dos sentidos.                      
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
