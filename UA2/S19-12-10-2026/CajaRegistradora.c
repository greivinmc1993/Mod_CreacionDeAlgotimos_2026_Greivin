//CAJA REGISTRADORA 

#include <stdio.h>
int main(void){

    int opcion, productos = 0; //OPCION DEL MENU Y ACUMUADOR DE PRODUCTOS
    double precio, total = 0; //PRECIO Y TOTAL DE LOS PRODUCTOS



    do
    {
        //MOSTRAR MENU
        printf("=========================================\n");
        printf("Seleccione la opción que desea realizar: \n");
        printf("1- AGREGAR \n");
        printf("2- VER TOTAL\n");
        printf("3- COBRAR\n");
        printf("0- SALIR\n");
        printf("=========================================\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
            //! CASO 1
        case 1:
            do
            {
                printf("Ingrese precio correcto: \n");
                scanf("%lf", &precio);

                if (precio <= 0)
                {
                    printf("¡¡¡¡¡¡IPRECIO INCORRECTO!!!!!! \n");/* code */
                }
                
            } while (precio <= 0);
            productos++;
            total += precio;
            break;
            //! CASO 2 MUESTRA AVANCE
        case 2:
            printf("Productos: %d Total: %.2f\n", productos, total);/* code */
            break;
            //! COBRA Y REINICIA TODO
        case 3:
            printf("Cobrado: %.2f  nueva venta\n", total);
            productos = 0;
            total = 0;
            break;
        
        default:
            printf("GRACIAS POR SU REFERENCIA \n");
            break;
        }/* code */
    } while (opcion != 0);
    

    return 0;
}