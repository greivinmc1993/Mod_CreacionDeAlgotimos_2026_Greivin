//! Una tienda de electrónica necesita procesar las compras de sus clientes.

#include <stdio.h>
#include <string.h>

//! CONSTANTES
#define MAX_PRODUCTOS 10
#define ANCHO_NOMBRE 50


int main(void){
    //! VARIABLES
    char nombre[50], productos[MAX_PRODUCTOS][ANCHO_NOMBRE];
    double precios[MAX_PRODUCTOS], subtotalProdu, subtotal, totalDescuentos,impuesto, totalPagar;
    int cantidades[MAX_PRODUCTOS], i=0, totalProductos=0;
    char respuesta;

    printf("Ingrese su nombre: \n");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    do
    {
        printf("Ingrese el nombre del producto: \n");
        fgets(productos[i], sizeof(productos[i]), stdin);
        productos[i][strcspn(nombre, "\n")] = '\0';
//!--------------------SE VALIDA PRECIO------------------------------------------------
        do
        {
            printf("Ingrese el precio del producto: \n");
            scanf("%lf", &precios[i]);

            if (precios[i] < 0)
            {
                printf("Precio incorrecto: \n");
            }
            

        } while (precios[i] < 0);
//!-----------------SE VALIDA CANTIDAD------------------------------------------------
        do
        {
            printf("Ingrese la cantidad: \n");
            scanf("%d", &cantidades[i]);

            if (cantidades[i] < 0)
            {
                printf("Dato incorrecto: \n");
            }
            

        } while (cantidades[i] < 0);

//!-----------------CALCULAR EL SUBTOTAL DEL PRODUCTO---------------------------------  
        printf("El subtotal del prodcuto es %.2f", subtotalProdu);

        

    } while (condition);
    


    return 0;
}