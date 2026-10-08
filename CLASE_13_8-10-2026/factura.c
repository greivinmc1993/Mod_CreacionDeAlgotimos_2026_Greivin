//CALCULO DE FACTURA CON SU IVA

#include <stdio.h>

int main(void){
    //IVA
    const double TASA_IVA = 0.13;
    //variables enteras para cantidades y reales para montos
    int cantidad;
    double precio, subTotal, iva, total;

    printf("Ingrese cantidad: ");
    scanf("%d", &cantidad);

    printf("Ingrese el precio: ");
    scanf("%lf", &precio);

    subTotal = precio * cantidad;
    iva = subTotal * TASA_IVA;
    total = subTotal + iva;

    printf("=========FACTURA=========\n");
    printf("CANTIDAD: %d\n", cantidad);
    printf("MONTO POR ARTICULO: %.2f\n", precio);
    printf("SUBTOTAL: %.2f\n", subTotal);
    printf("I.V.A 13%%: %.2f\n", iva);
    printf("TOTAL: %.2f\n", total);


    return 0;
}