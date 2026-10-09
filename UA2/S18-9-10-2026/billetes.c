//ALGORITMO PARA BILLETES

#include <stdio.h>
int monto, resta, cantidad;

int main(void){
    printf("Monto a desglosar: ");
    scanf("%d", &monto);
    //BILLETES DE 20000
    cantidad = monto / 20000;
    //SE GUARDA EL RESIDUO PARA SABER CUANTO QUEDA
    resta = monto % 20000;

    // MUESTRE BILLETES
    printf("Billetes de 20000: %d\n", cantidad);
    //BILLETES DE 10000
    cantidad = resta / 10000;

    resta %= 10000;//resta = resta % 10000
    printf("Billetes de 10000: %d\n", cantidad);
    //BILLETES DE 5000
    cantidad = resta / 5000;

    resta %= 5000;//resta = resta % 5000
    printf("Billetes de 5000: %d\n", cantidad);
    //BILLETES DE 5000
    cantidad = resta / 2000;

    resta %= 2000;//resta = resta % 2000
    printf("Billetes de 2000: %d\n", cantidad);

    //BILLETES DE 1000
    cantidad = resta / 1000;

    resta %= 1000;//resta = resta % 2000
    printf("Billetes de 1000: %d\n", cantidad);

    //LO QUE QUEDA SON MONEDAS
    printf("En monedas: %d\n", resta);



    return 0 ;
}