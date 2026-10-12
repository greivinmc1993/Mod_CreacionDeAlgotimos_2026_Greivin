//AÑO BISIESTO

#include <stdio.h>
#include <stdbool.h>//LIBRERIA PARA USAR BOOL TRUE FALSE

int main(void){
    //VARIABLES
    int anio;
    bool esBisiesto;


    //Entradas Y LECTURAS
    printf("Ingrese el año: \n");
    scanf("%d", &anio);

    esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;

    esBisiesto ? printf("Es bisiesto \n") :  printf("No es bisiesto\n");


    
    return 0;
}