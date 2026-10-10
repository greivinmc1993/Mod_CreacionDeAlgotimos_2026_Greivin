/* 
    Preprocesador | Inserta los #include y quita comentarios. | gcc -E hola.c -o hola.i -> hola.i
    Compilador    | Traduce a lenguaje ensamblador.           | gcc -S hola.c -> hola.s 
    Ensamblador   | Genera código máquina.                    | gcc -c hola.c -> hola.o 
    Enlazador     | Une con las bibliotecas.                  | gcc hola.o -o hola -> hola.exe 

    gcc -Wall hola.c -o hola -> hola.exe con advertencias 
*/

#include <stdio.h>

int main(void){
    printf("\n");
    printf("=========================================\n");
    printf("\"REGLAS DE LABORATORIO\"\n");
    printf("1- \"Guardar y hacer commit con frecuencia\"\n");
    printf("2- \"No comer ni beber cerca de los equipos\"\n");
    printf("3- \"Apagar el equipo al salir\"\n");
    printf("\"Gracias por su colaboracion\"\n");
    printf("=========================================\n");
    printf("\n");
return 0;
}