/* 
    Preprocesador | Inserta los #include y quita comentarios. | gcc -E hola.c -o hola.i -> hola.i
    Compilador    | Traduce a lenguaje ensamblador.           | gcc -S hola.c -> hola.s 
    Ensamblador   | Genera código máquina.                    | gcc -c hola.c -> hola.o 
    Enlazador     | Une con las bibliotecas.                  | gcc hola.o -o hola -> hola.exe 

    gcc -Wall hola.c -o hola -> hola.exe con advertencias 
*/
//MENU.C TRADUCCION DEL ALGORITMO MENU CAJERO PSEINT
#include <stdio.h>





int main(void){
    
    printf("\n");
    printf("=========================================\n");
    printf("Cajero I.N.A\n");
    printf("1- Consultar Saldo.\n");
    printf("2- Retirar Saldo.\n");
    printf("3- Salir.\n");
    printf("=========================================\n");
    printf("\n");

    return 0;
}