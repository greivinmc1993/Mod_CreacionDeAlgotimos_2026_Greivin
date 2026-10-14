#include <stdio.h>

int main(void){

    int cadena, i;

    cadena = printf("COMPROBANTE DE PAGO\n");

    cadena -= 1;

    printf("cadena  %d\n\n", cadena);


    printf("COMPROBANTE DE PAGO\n");

    for ( i = 1; i <= cadena; i++)
    {
        printf("-");
    }
    

    return 0;
}


