
#include <stdio.h>
#include <stdlib.h>

/*
    Ejercicio 2: LanzarDado

    Objetivo:
    Simular 600 lanzamientos de un dado y contar
    cuantas veces aparece cada cara.

    Como se logra:
    1. La funcion lanzarDado() genera un numero del 1 al 6.
    2. Un arreglo guarda la frecuencia de cada cara.
    3. La funcion mostrarBarra() imprime un asterisco
    por cada 10 lanzamientos.

    Resultado esperado:
    Mostrar las frecuencias de las seis caras
    y una barra de asteriscos para cada una.
*/

#define LANZAMIENTOS 600

/* PROTOTIPOS */
int lanzarDado(void);
void mostrarBarra(int cantidad);

int main(void)
{
    int frecuencia[7] = {0};
    /* int lanzamiento; */
    int cara;
    int i;

    /* Inicializar la semilla aleatoria */
    srand(2026);

    /* Realizar los 600 lanzamientos */
    for (i = 0; i < LANZAMIENTOS; i++)
    {
        cara = lanzarDado();

        frecuencia[cara]++;
    }

    /* Mostrar los resultados */
    printf("RESULTADOS DE LOS LANZAMIENTOS\n\n");

    for (cara = 1; cara <= 6; cara++)
    {
        printf("Cara %d: %3d ", cara, frecuencia[cara]);

        mostrarBarra(frecuencia[cara]);

        printf("\n");
    }

    return 0;
}

/* FUNCION: generar un numero del 1 al 6 */
int lanzarDado(void)
{
    int numero;

    numero = rand() % 6 + 1;

    return numero;
}

/* FUNCION: mostrar un asterisco por cada 10 lanzamientos */
void mostrarBarra(int cantidad)
{
    int i;
    int asteriscos;

    asteriscos = cantidad / 10;

    for (i = 0; i < asteriscos; i++)
    {
        printf("*");
    }
}
