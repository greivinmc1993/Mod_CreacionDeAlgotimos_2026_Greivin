//Algoritmo Intercambio

#include <stdio.h>

int main(void){
    //DEFINIR VARIABLES
    int a, b, aux;
    a = 5;
    b = 9;

    aux = a;

    a = b;
    b = aux;

    /* 
        Ejecución esperada en la terminal 
        Antes:   a = 5   b = 9 
        Despues: a = 9   b = 5  
    */

    printf ("---------\n");
    printf ("| a = %d |\n" , a);
    printf ("| b = %d |\n" , b);
    printf ("---------\n");

    return 0;
}