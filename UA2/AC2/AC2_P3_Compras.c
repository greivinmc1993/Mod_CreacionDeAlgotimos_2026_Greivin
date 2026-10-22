
/*
ENUNCIADO:
Una tienda de electronica necesita procesar las compras de sus clientes.
Se debe recibir el nombre del cliente y registrar hasta 10 productos,
incluyendo nombre, precio unitario y cantidad.
Se validan los datos, se calcula el subtotal de cada producto,
se aplica un descuento segun el total y se calcula el impuesto del 13 %.

QUE SE LOGRA:
Generar una factura con el detalle de los productos y el total a pagar.

COMO SE LOGRA:
Se utilizan arreglos paralelos para guardar nombres, precios y cantidades.
Se usa fgets para leer nombres con espacios, scanf para leer numeros,
getchar para descartar el Enter pendiente y for para mostrar la factura.

RESULTADO ESPERADO:
Mostrar el cliente, los productos comprados, sus subtotales,
el descuento, el impuesto y el total final de la compra.
*/

#include <stdio.h>
#include <string.h>

/* CONSTANTES */
#define MAX_PRODUCTOS 10       // Maximo de productos que se pueden registrar
#define ANCHO_NOMBRE 100       // Espacio para nombres de productos y clientes

int main(void)
{
    /* ARREGLOS PARALELOS */
    char nombres[MAX_PRODUCTOS][ANCHO_NOMBRE]; // Nombre de cada producto
    float precios[MAX_PRODUCTOS];              // Precio unitario de cada producto
    int cantidades[MAX_PRODUCTOS];             // Cantidad comprada de cada producto

    /* VARIABLES DE TEXTO */
    char cliente[ANCHO_NOMBRE]; // Nombre completo del cliente
    char respuesta;             // Indica si desea agregar otro producto

    /* VARIABLES DE CONTROL */
    int i = 0;                  // Posicion del producto actual
    int totalProductos = 0;     // Cantidad de productos registrados

    /* VARIABLES DE DINERO */
    float subtotalProducto;     // Subtotal del producto actual
    float subtotal = 0;         // Suma de todos los subtotales
    float descuento = 0;        // Descuento aplicado a la compra
    float totalDescuento = 0;   // Total despues de descontar
    float impuesto = 0;         // Impuesto del 13 %
    float totalPagar = 0;       // Total final de la factura

    /* RECIBIR EL NOMBRE DEL CLIENTE */
    printf("Ingrese el nombre del cliente: ");
    fgets(cliente, sizeof(cliente), stdin);

    // Eliminar el salto de linea del nombre del cliente
    cliente[strcspn(cliente, "\n")] = '\0';

    /* REGISTRAR LOS PRODUCTOS */
    do
    {
        // Leer el nombre del producto
        printf("\nIngrese el nombre del producto: ");
        fgets(nombres[i], sizeof(nombres[i]), stdin);

        // Eliminar el salto de linea del nombre
        nombres[i][strcspn(nombres[i], "\n")] = '\0';

        /* VALIDAR EL PRECIO */
        do
        {
            printf("Ingrese el precio unitario: ");

            if (scanf("%f", &precios[i]) != 1)
            {
                printf("Entrada invalida. Ingrese un numero.\n");

                // Descartar la entrada incorrecta
                while (getchar() != '\n')
                {
                }

                precios[i] = 0;
            }
            else if (precios[i] <= 0)
            {
                printf("El precio debe ser positivo.\n");
            }

        } while (precios[i] <= 0);

        /* VALIDAR LA CANTIDAD */
        do
        {
            printf("Ingrese la cantidad: ");

            if (scanf("%d", &cantidades[i]) != 1)
            {
                printf("Entrada invalida. Ingrese un numero entero.\n");

                while (getchar() != '\n')
                {
                }

                cantidades[i] = 0;
            }
            else if (cantidades[i] <= 0)
            {
                printf("La cantidad debe ser positiva.\n");
            }

        } while (cantidades[i] <= 0);

        /* CALCULAR EL SUBTOTAL DEL PRODUCTO */
        subtotalProducto = precios[i] * cantidades[i];

        printf("Subtotal del producto: %.2f\n", subtotalProducto);

        // Acumular el subtotal en el total de la compra
        subtotal += subtotalProducto;

        // Contar el producto registrado
        totalProductos++;
        i++;

        // Descartar el Enter pendiente antes de leer otro nombre
        while (getchar() != '\n')
        {
        }

        /* PREGUNTAR SI DESEA AGREGAR OTRO PRODUCTO */
        if (totalProductos < MAX_PRODUCTOS)
        {
            do
            {
                printf("Desea agregar otro producto? (S/N): ");
                scanf(" %c", &respuesta);

                // Aceptar S, s, N o n
                if (respuesta != 'S' && respuesta != 's' &&
                    respuesta != 'N' && respuesta != 'n')
                {
                    printf("Respuesta invalida. Escriba S o N.\n");
                }

            } while (respuesta != 'S' && respuesta != 's' &&
                    respuesta != 'N' && respuesta != 'n');

            // Descartar el Enter despues de leer la respuesta
            while (getchar() != '\n')
            {
            }
        }
        else
        {
            respuesta = 'N'; // Ya se alcanzo el maximo de productos
        }

    } while ((respuesta == 'S' || respuesta == 's') &&
            totalProductos < MAX_PRODUCTOS);

    /* CALCULAR EL DESCUENTO */
    if (subtotal < 100)
    {
        descuento = 0;          // Sin descuento
    }
    else if (subtotal < 500)
    {
        descuento = subtotal * 0.05; // Descuento del 5 %
    }
    else if (subtotal <= 1000)
    {
        descuento = subtotal * 0.10; // Descuento del 10 %
    }
    else
    {
        descuento = subtotal * 0.15; // Descuento del 15 %
    }

    /* CALCULAR EL TOTAL CON DESCUENTO */
    totalDescuento = subtotal - descuento;

    /* CALCULAR EL IMPUESTO DEL 13 % */
    impuesto = totalDescuento * 0.13;

    /* CALCULAR EL TOTAL A PAGAR */
    totalPagar = totalDescuento + impuesto;

    /* MOSTRAR LA FACTURA */
    printf("\n============================================\n");
    printf("             FACTURA DE COMPRA\n");
    printf("============================================\n");
    printf("Cliente: %s\n", cliente);
    printf("--------------------------------------------\n");

    for (i = 0; i < totalProductos; i++)
    {
        printf("\nProducto: %s\n", nombres[i]);
        printf("Precio unitario: %.2f\n", precios[i]);
        printf("Cantidad: %d\n", cantidades[i]);
        printf("Subtotal: %.2f\n", precios[i] * cantidades[i]);
    }

    printf("\n============================================\n");
    printf("Cantidad de productos: %d\n", totalProductos);
    printf("Subtotal de la compra: %.2f\n", subtotal);
    printf("Descuento: %.2f\n", descuento);
    printf("Total con descuento: %.2f\n", totalDescuento);
    printf("Impuesto (13%%): %.2f\n", impuesto);
    printf("--------------------------------------------\n");
    printf("TOTAL A PAGAR: %.2f\n", totalPagar);
    printf("============================================\n");

    return 0;
}
