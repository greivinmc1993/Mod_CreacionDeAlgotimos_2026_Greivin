
/*
Enunciado:
Registrar la temperatura maxima de cada dia de la semana,
desde lunes hasta domingo, con valores entre 0 y 45 grados C.
Calcular el promedio semanal, encontrar el dia mas caluroso
y mostrar los dias que superaron el promedio.

Que se logra:
Guardar las temperaturas, calcular el promedio, identificar
el dia mas caluroso y contar los dias sobre el promedio.

Como se logra:
Se utilizan arreglos, ciclos for, condiciones if y una variable
para acumular las temperaturas y otra para guardar la posicion
del dia mas caluroso.

Resultado esperado:
Mostrar la temperatura de cada dia, el promedio semanal,
el dia mas caluroso y la lista de dias sobre el promedio.

Constantes:
DIAS: cantidad de dias de la semana.
MIN_TEMP: temperatura minima permitida.
MAX_TEMP: temperatura maxima permitida.
*/


/* void limpiarEntrada(void)
{
    int caracter;  // Guarda temporalmente cada caracter leido

    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
    }
} */

// Libreria para utilizar printf, scanf y getchar
#include <stdio.h>
#include <string.h>

// Constantes del programa
#define DIAS 7
#define MIN_TEMP 0
#define MAX_TEMP 45

int main(void)
{
    // Arreglo con los nombres de los dias
    char dias[7][4] = {
        "Lun", "Mar", "Mie", "Jue",
        "Vie", "Sab", "Dom"
    };

    // Arreglo con las temperaturas de cada dia
    int temperaturas[7];

    // Variables para recorrer los arreglos
    int i;

    // Variable para guardar la temperatura ingresada
    int temperatura;

    // Variable para sumar todas las temperaturas
    int suma = 0;

    // Variable para guardar el promedio semanal
    float promedio;

    // Posicion del dia mas caluroso
    int diaCaluroso = 0;

    // Cantidad de dias que superaron el promedio
    int cantidadSobrePromedio = 0;

    // Variable para comprobar si se ingreso un numero
    int correcto;

    // Variable auxiliar para limpiar la entrada incorrecta
    int caracter;

    // Pedir la temperatura maxima de cada dia
    for (i = 0; i < DIAS; i++)
    {
        do
        {
            printf("Ingrese la temperatura de %s (0-45 C): ", dias[i]);

            correcto = scanf("%d", &temperatura);

            // Comprobar que se ingreso un numero entero
            if (correcto != 1)
            {
                printf("Error: debe ingresar un numero entero.\n");

                // Eliminar los caracteres incorrectos
                while ((caracter = getchar()) != '\n' && caracter != EOF)
                {
                }

                temperatura = -1;
            }
            else if (temperatura < MIN_TEMP || temperatura > MAX_TEMP)
            {
                printf("Error: la temperatura debe estar entre 0 y 45.\n");
            }

        } while (temperatura < MIN_TEMP || temperatura > MAX_TEMP);

        // Guardar la temperatura en su posicion
        temperaturas[i] = temperatura;

        // Sumar la temperatura al acumulador
        suma = suma + temperaturas[i];
    }

    // Calcular el promedio de la semana
    promedio = (float)suma / DIAS;

    // Buscar el dia con la temperatura mas alta
    for (i = 1; i < DIAS; i++)
    {
        if (temperaturas[i] > temperaturas[diaCaluroso])
        {
            diaCaluroso = i;
        }
    }

    // Mostrar las temperaturas registradas
    printf("\n=================================\n");
    printf(" TEMPERATURAS DE LA SEMANA\n");
    printf("=================================\n");

    for (i = 0; i < DIAS; i++)
    {
        printf("%s: %d grados C\n", dias[i], temperaturas[i]);
    }

    // Mostrar el promedio semanal
    printf("\nPromedio semanal: %.2f grados C\n", promedio);

    // Mostrar el dia mas caluroso
    printf("\nDia mas caluroso: %s\n", dias[diaCaluroso]);
    printf("Temperatura maxima: %d grados C\n", temperaturas[diaCaluroso]);

    // Recorrer nuevamente el arreglo para buscar
    // los dias que superaron el promedio
    printf("\nDias que superaron el promedio:\n");

    for (i = 0; i < DIAS; i++)
    {
        if (temperaturas[i] > promedio)
        {
            printf("%s: %d grados C\n", dias[i], temperaturas[i]);

            // Contar los dias que superaron el promedio
            cantidadSobrePromedio++;
        }
    }

    // Mostrar la cantidad de dias sobre el promedio
    printf("\nCantidad de dias sobre el promedio: %d\n", cantidadSobrePromedio);

    // Informar si ningun dia supero el promedio
    if (cantidadSobrePromedio == 0)
    {
        printf("Ningun dia supero el promedio semanal.\n");
    }

    return 0;
}
