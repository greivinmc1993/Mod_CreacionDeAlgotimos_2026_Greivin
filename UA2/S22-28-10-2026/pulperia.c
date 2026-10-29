/*
    Practica integradora: Inventario de una pulperia

    Que se logra:
    - Listar productos, vender si hay existencias, reponer productos
    y consultar el valor total del inventario.
    - Practicar arreglos paralelos, cadenas, funciones, apuntadores,
    do...while, switch y lectura validada.

    Resultado esperado:
    - Vender 5 unidades de Cafe: quedan 7.
    - Rechazar la venta de 20 unidades de Aceite: solo hay 8 unidades.
    - Reponer 10 unidades de Aceite: quedan 18.
    - El valor final del inventario es 164100.00.
*/

#include <stdio.h>   // Permite usar printf, scanf y getchar.
#include <string.h>  // Permite usar strcspn para quitar el salto de linea.

#define TOTAL 4      // Define la cantidad de productos del inventario.

/* Prototipos: anuncian las funciones antes de que main las utilice. */
int leerEntero(const char mensaje[], int minimo, int maximo);
void listar(const char nombres[][20], const double precios[], const int existencias[], int total);
int vender(int *existencia, int cantidad);
void reponer(int *existencia, int cantidad);
double valorInventario(const double precios[], const int existencias[], int total);

int main(void)
{
    /* Arreglo de cadenas: guarda el nombre de cada producto. */
    char nombres[TOTAL][20] = {
        "Arroz 2 kg",
        "Frijoles 1 kg",
        "Cafe 1 kg",
        "Aceite 1 L"
    };

    /* Arreglo paralelo: cada precio corresponde al mismo indice de nombres. */
    double precios[TOTAL] = {2400, 1800, 4500, 3200};

    /* Arreglo paralelo: cada existencia corresponde al mismo indice. */
    int existencias[TOTAL] = {20, 15, 12, 8};

    /* Guarda la opcion elegida en el menu. */
    int opcion;

    /* Guarda el indice del producto elegido, convertido a indice desde cero. */
    int producto;

    /* Guarda la cantidad que se desea vender o reponer. */
    int cantidad;

    /* El menu se repite hasta que la persona elija 0. */
    do
    {
        printf("\n===== INVENTARIO DE LA PULPERIA =====\n"); // Muestra el titulo.
        printf("1. Listar productos\n");                    // Opcion para listar.
        printf("2. Vender\n");                              // Opcion para vender.
        printf("3. Reponer\n");                             // Opcion para reponer.
        printf("4. Valor del inventario\n");                // Opcion para calcular valor.
        printf("0. Salir\n");                               // Opcion para terminar.

        /* Lee una opcion valida entre 0 y 4. */
        opcion = leerEntero("Seleccione una opcion: ", 0, 4);

        /* Ejecuta la accion que corresponde a la opcion. */
        switch (opcion)
        {
            case 1:
                /* Muestra todos los productos y sus existencias. */
                listar(nombres, precios, existencias, TOTAL);
                break; // Termina este caso del switch.

            case 2:
                /* Muestra los productos antes de pedir cual vender. */
                listar(nombres, precios, existencias, TOTAL);

                /* Pide el numero de producto entre 1 y TOTAL. */
                producto = leerEntero("Numero de producto que desea vender: ", 1, TOTAL);

                /* Convierte el numero mostrado (1 a 4) al indice del arreglo (0 a 3). */
                producto = producto - 1;

                /* Pide una cantidad entre 1 y 50. */
                cantidad = leerEntero("Cantidad que desea vender (1 a 50): ", 1, 50);

                /* Pasa la direccion de la existencia para que la funcion pueda modificarla. */
                if (vender(&existencias[producto], cantidad) == 1)
                {
                    /* Informa que la venta se realizo y muestra las existencias restantes. */
                    printf("Venta realizada. Quedan %d unidades de %s.\n",
                        existencias[producto], nombres[producto]);
                }
                else
                {
                    /* Informa que no hay suficientes unidades y no modifica las existencias. */
                    printf("Venta rechazada. Solo hay %d unidades de %s.\n",
                        existencias[producto], nombres[producto]);
                }
                break; // Termina este caso del switch.

            case 3:
                /* Muestra los productos antes de pedir cual reponer. */
                listar(nombres, precios, existencias, TOTAL);

                /* Pide el numero del producto que se va a reponer. */
                producto = leerEntero("Numero de producto que desea reponer: ", 1, TOTAL);

                /* Convierte el numero mostrado al indice del arreglo. */
                producto = producto - 1;

                /* Pide la cantidad que se agregara al inventario. */
                cantidad = leerEntero("Cantidad que desea reponer (1 a 50): ", 1, 50);

                /* Pasa la direccion de la existencia para sumar en el arreglo original. */
                reponer(&existencias[producto], cantidad);

                /* Informa la nueva cantidad disponible. */
                printf("Reposicion realizada. Ahora hay %d unidades de %s.\n",
                    existencias[producto], nombres[producto]);
                break; // Termina este caso del switch.

            case 4:
                /* Calcula y muestra el valor total del inventario. */
                printf("Valor total del inventario: %.2f\n",
                    valorInventario(precios, existencias, TOTAL));
                break; // Termina este caso del switch.

            case 0:
                /* Muestra un mensaje antes de terminar el programa. */
                printf("Saliendo del programa.\n");
                break; // Termina este caso del switch.
        }

    } while (opcion != 0); // Repite el menu mientras la opcion no sea 0.

    return 0; // Indica que el programa termino correctamente.
}

/*
    Lee un entero dentro de un rango.
    Recibe el mensaje y los limites permitidos.
    Repite la lectura si el dato no es un entero valido o esta fuera del rango.
*/
int leerEntero(const char mensaje[], int minimo, int maximo)
{
    int numero;       // Guarda el numero ingresado.
    int resultado;    // Guarda el resultado que devuelve scanf.
    int caracter;     // Permite limpiar los caracteres restantes de la entrada.

    do
    {
        printf("%s", mensaje); // Muestra el mensaje que recibe la funcion.
        resultado = scanf("%d", &numero); // Intenta leer un numero entero.

        /* Descarta el resto de la linea, incluido el salto de linea. */
        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
            /* No hace falta ejecutar nada: solo se limpia la entrada. */
        }

        /* Comprueba que scanf haya leido un entero y que este en el rango. */
        if (resultado != 1 || numero < minimo || numero > maximo)
        {
            printf("Dato invalido. Ingrese un entero entre %d y %d.\n", minimo, maximo);
        }

    } while (resultado != 1 || numero < minimo || numero > maximo); // Repite si no es valido.

    return numero; // Devuelve el entero validado.
}

/*
    Muestra todos los productos.
    Los arreglos se reciben como const porque esta funcion solo los consulta.
*/
void listar(const char nombres[][20], const double precios[], const int existencias[], int total)
{
    int i; // Controla el recorrido de los productos.

    printf("\n%-5s %-20s %-12s %-12s\n", "N.", "Producto", "Precio", "Existencias"); // Encabezados.

    /* Recorre todos los indices validos de los arreglos. */
    for (i = 0; i < total; i++)
    {
        /* Muestra numero, nombre, precio y existencias del producto actual. */
        printf("%-5d %-20s %-12.2f %-12d\n",
            i + 1, nombres[i], precios[i], existencias[i]);
    }
}

/*
    Intenta vender una cantidad.
    Recibe un apuntador a las existencias de un solo producto.
    Devuelve 1 si vende; devuelve 0 si no hay suficientes unidades.
*/
int vender(int *existencia, int cantidad)
{
    /* Comprueba si el inventario alcanza para completar la venta. */
    if (*existencia >= cantidad)
    {
        *existencia = *existencia - cantidad; // Descuenta la cantidad vendida.
        return 1; // Informa que la venta tuvo exito.
    }

    return 0; // Informa que no hay suficientes unidades; no cambia la existencia.
}

/*
    Suma unidades a las existencias.
    Recibe un apuntador para modificar directamente el dato original.
*/
void reponer(int *existencia, int cantidad)
{
    *existencia = *existencia + cantidad; // Agrega las unidades recibidas.
}

/*
    Calcula el valor total del inventario.
    Multiplica el precio por las existencias de cada producto y suma los resultados.
    Los arreglos se reciben como const porque solo se consultan.
*/
double valorInventario(const double precios[], const int existencias[], int total)
{
    int i;             // Controla el recorrido de los productos.
    double totalValor = 0.0; // Acumula el valor de todo el inventario.

    /* Recorre todos los productos. */
    for (i = 0; i < total; i++)
    {
        /* Suma el valor de las unidades del producto actual. */
        totalValor = totalValor + (precios[i] * existencias[i]);
    }

    return totalValor; // Devuelve el valor total calculado.
}


