//APLICA 10% DESCUENTO POR UN MONTO

#include <stdio.h>
int main(void){
    #define MINIMO 50000.0
    const double TASA = 0.10;

    //reaLES
    double compra, descuento, total;
    //dos resultados reales para comparar


    //Entradas Y LECTURAS
    printf("Monto de la compra?: ");
    scanf("%lf", &compra);

    //procesos
    if (compra >= MINIMO)
    {
        descuento = compra * TASA;
    }
    else
    {
        descuento = 0;
    }
    

    //int / int
    total = compra - descuento;

    printf ("%-20s %.2f\n", "Descuento de:", descuento);
    printf ("%-20s %.2f\n", "Total a pagar de:", total);


    return 0;
}