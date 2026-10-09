/* 
    Preprocesador | Inserta los #include y quita comentarios. | gcc -E hola.c -o hola.i -> hola.i
    Compilador    | Traduce a lenguaje ensamblador.           | gcc -S hola.c -> hola.s 
    Ensamblador   | Genera código máquina.                    | gcc -c hola.c -> hola.o 
    Enlazador     | Une con las bibliotecas.                  | gcc hola.o -o hola -> hola.exe 

    gcc -Wall hola.c -o hola -> hola.exe con advertencias 
*/
//PRESENTACION.C
//AUTOR: GREIVIN MONTERO CONTRERAS
#include <stdio.h>



int main(void){
    printf("\n");
    printf("=========================================\n");
    printf("Instituto Nacional de Aprendizaje\n");
    printf("Módulo: CSTI12010 Diseño de Algoritmos\n");
    printf("Unidad 2: Programacón estructurada\n");
    printf("\t Sesión: 16 \n");
    printf("Lenguaje \"C\" %% | Compilador: gcc \n");
    printf("=========================================\n");
    printf("\n");




    return 0;
}
