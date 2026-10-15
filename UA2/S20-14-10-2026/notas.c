//NOTAS Y PROMEDIO CON ARREGLOS

#include <stdio.h>
#define N 5

int main(void){

    double notas[N], suma = 0, promedio, mayor, menor; //DEFINE EL ARREGLO

    int i;

    //LECTURA DE DATOS
    for ( i = 0; i < N; i++)
    {
        // VALIDACIÓN
        do
        {
            printf("Nota %d (0 a 100): ", i + 1);
            scanf("%lf", &notas[i]);
        } while (notas[i] < 0 || notas[i] > 100);

        suma += notas[i];
        
    }
    
    promedio = suma / N;

    //MAYOR O MENOR
    mayor = notas[0];
    menor = notas[0];
    
    for ( i = 1; i < N; i++)
    {
        if (notas[i] > mayor)
        {
            mayor = notas[i];
        }
        else if (notas[i] < menor)
        {
            menor = notas[i];
        }
    }

    printf("Promedio: %.2f\n", promedio);
    printf("Mayor: %.1f Menor: %.1f\n", mayor, menor);


    //SEGUNDO RECORRIDO
    printf("Sobre el promedio: ");
    for ( i = 0; i < N; i++)
    {
        if (notas[i] > promedio)
        {
            printf("%.1f ", notas[i]);
        }
    }

    printf("\n");
    
    

    return 0;
}