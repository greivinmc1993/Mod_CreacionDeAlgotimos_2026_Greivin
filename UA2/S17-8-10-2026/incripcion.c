//SE EMULA UN PROGRAMA DE INCRIPCION PARA USO DE VARIABLE BOOLEANA Y STRING

#include <stdio.h>
#include <stdbool.h>

#define COSTOMOD 15000

int main(void){
    //cadenas de texto
    char nombre[30];
    char cedula[15];
    int cantidadModulos;
    double total;
    //variable logica
    int tieneDescuento;

    printf("Ingrese su Nombre: ");
    scanf("%29s", nombre);
    printf("Ingrese su Cedula:");
    scanf("%14s", cedula);
    printf("Ingrese la Cantidad de módulos: ");
    scanf("%d", &cantidadModulos);

    total = cantidadModulos * COSTOMOD;

    tieneDescuento = cantidadModulos >= 3;

    //SALIDAS
    printf("Estudiantes: %s (%s)\n", nombre, cedula);
    printf("Total inscripción:  %.2f\n", total);
    printf("Aplica descuento?: %d (1- SI o 2- NO)\n", tieneDescuento);
    





    return 0;
}