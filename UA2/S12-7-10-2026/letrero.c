/* 
    Preprocesador | Inserta los #include y quita comentarios. | gcc -E hola.c -o hola.i -> hola.i
    Compilador    | Traduce a lenguaje ensamblador.           | gcc -S hola.c -> hola.s 
    Ensamblador   | Genera código máquina.                    | gcc -c hola.c -> hola.o 
    Enlazador     | Une con las bibliotecas.                  | gcc hola.o -o hola -> hola.exe 

    gcc -Wall hola.c -o hola -> hola.exe con advertencias 
*/


/* 
    1. Con letrero.c, genere los archivos de cada etapa: gcc -E, gcc -S, gcc -c y el enlace. 
    2. ¿Qué archivo contiene el texto de stdio.h? ¿Cómo lo comprobó? 
    !    El .i incluye todo de stdio.h encima del codigo
    3. ¿Qué archivo tiene instrucciones como mov y call? 
    !    El .s ensamblador
    4. ¿Cuál no se puede leer como texto? ¿Por qué? 
    !    El .o porque el ensamblador ya lo tradujo a lenguaje maquina
    5. ¿Qué etapa une su programa con el código de printf? 
    !    Etapa Enlazador Une con las bibliotecas.
    6. Borre los archivos .i y .s antes de hacer commit.  
    !    rm letrero.i letrero.s   o   del letrero.i letrero.s
*/

#include <stdio.h>

int main(void){
    printf("\n");
    printf("=========================================\n");
    printf("MENU DEL DIA - SODA \"LA ESQUINA\"\n");
    printf("PLATILLO \t PRECIO\n");
    printf("Casado \t\t $3500\n");
    printf("Gallo Pinto \t $2000\n");
    printf("Refresco \t $1000\n");
    printf("Archivo C:\\INA\\Menu.txt\n");
    printf("=========================================\n");
    printf("\n");
return 0;
}