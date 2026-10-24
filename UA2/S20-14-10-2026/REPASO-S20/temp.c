/* temperaturas.c -  Temperaturas de la semana
==========================================================================
* ENUNCIADO:
    Solicitar temperatura maxima del dia, mostrar el nombre del dia: lunes a domingo.(0-45°C)
    Si esta fuera de rango vuelve a pedir el valor.
    Guardarlas en un arreglo de 7 posiciones.
    Calcular el promedio de la semana

* QUÉ SE LOGRA:
    Encontrar el dia más caluroso.
    El promedio.

* CÓMO SE LOGRA:
    -do-while para validar el rango de temperatura aceptada
    -Arreglo para guardar temperaturas
    -for para sacar al mas caluros
    -for para recorrer los dias

* RESULTADO ESPERADO:
    Muestra la temperatura de cada dia.
    El promedio de temperatura (float: dos decimales)
    El dia mas caluroso
    La lista de dias que superaron el promedio con su cantidad
* ========================================================================== */

#include <stdio.h>
#include <string.h>

#define DIAS 7
#define MIN_TEMP 0
#define MAX_TEMP 45

int main(void){
    char dias[DIAS][4] = {
    //ancho palabra = 4
        "Lun", //fila 1 
        "Mar", //fila 2
        "Mie", //fila 3
        "Jue", //fila 4
        "Vie", //fila 5
        "Sab", //fila 6
        "Dom"};//fila 7

    int  i, diaCaliente=0, cantidadSobrePromedio=0, posicionDia=0;
    double temperaturas[DIAS], suma=0;
    double promedio;

    for ( i = 0; i < DIAS; i++)
    {
        do
        {
            printf("Ingrese la temp que sea de 0 a 45 del día %s: \n", dias[i]);
            scanf("%lf", &temperaturas[i]);

            if (temperaturas[i] < MIN_TEMP || temperaturas[i] > MAX_TEMP)
            {
                printf("El valor ingresado es erroneo intente de nuevo :\n");
            }
            

        } while (temperaturas[i] < MIN_TEMP || temperaturas[i] > MAX_TEMP);

        suma = suma + temperaturas[i];
        
    }

    promedio = suma / DIAS;

    
    
    for (i = 0; i < DIAS; i++)
    {
        if (temperaturas[i] > diaCaliente)
        {
            diaCaliente = temperaturas[i];
            posicionDia = i;
        }
        
    }


    printf("========================================\n");
        for (i = 0; i < DIAS; i++)
    {
        printf("Temps del día: %s es %.1f C\n", dias[i], temperaturas[i]);
    }
    printf("el promedio es: %.2f C\n", promedio);
    printf("el dia caluroso es: %s con %d C \n", dias[posicionDia], diaCaliente);

    for (i = 0; i < DIAS; i++)
    {
        if (temperaturas[i] > promedio)
        {
            cantidadSobrePromedio = cantidadSobrePromedio +1;
            printf("Día mayor a promedio: %s con %f \n", dias[i], temperaturas[i]);
        }
        
    }
    printf ("Cantidad dia mayores al promedio son: %d dias", cantidadSobrePromedio);


    printf("========================================\n");
    
    

    return 0;
}