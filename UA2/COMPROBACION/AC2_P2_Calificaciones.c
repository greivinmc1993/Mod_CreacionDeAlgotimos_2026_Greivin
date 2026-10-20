//Un centro educativo necesita automatizar el cálculo de notas finales. 
#include <stdio.h>
#include <string.h>
#define MIN_NOTA 0
#define MAX_NOTA 100

int main(void){
    char nombre[50], condicion[20];
    int i;
    double promedio, sumaPromedio=0, alta=0, calaficaciones[3];


    printf("Ingrese su nombre: \n");
    fgets(nombre, sizeof(nombre), stdin );//! PARA GUARDAR EL TEXTO EN NOMBRE
    nombre[strcspn(nombre, "\n")] = '\0';//! PARA QUITAR EL SALTO DE LINEA

    for ( i = 0; i < 3; i++)
    {
        do
        {
            //! INGRESO DE LAS 3 NOTAS
            printf("Ingrese la nota %d: \n", i + 1);
            scanf("%lf", &calaficaciones[i]);

            if (calaficaciones[i] < MIN_NOTA || calaficaciones[i] > MAX_NOTA)
            {
                printf("El valor está fuera del rango: \n");
            }
            
        } while (calaficaciones[i] < 0 || calaficaciones[i] > 100);
        
        //! SUMA DE NOTAS
        sumaPromedio = sumaPromedio + calaficaciones[i];
        
    }


    //! CALCULOS DE PROMEDIOS
    promedio = sumaPromedio / i;

    //! CALCULO DEL MAYOR
    for (i = 0; i < 3; i++)
    {
        if (calaficaciones[i] > alta)
        {
            alta = calaficaciones[i];
        }
    }

    //! GUARDADO DE LA CONDICION
    if (promedio >= 70)
    {
        strcpy(condicion, "APROBADO");
    }
    else if (promedio < 70 && promedio >= 60)
    {
        strcpy(condicion, "ESTA EN RIESGO");
    }
    else
    {
        strcpy(condicion, "REPROBADO");
    }
    

    //! SALIDA DE DATOS
    printf("============%s============\n", nombre);
    printf("Calificacion 1: %.2f \n", calaficaciones[0]);
    printf("Calificacion 2: %.2f \n", calaficaciones[1]);
    printf("Calificacion 3: %.2f \n", calaficaciones[2]);
    printf("Promedio: %.2f \n", promedio);
    printf("Nota mas alta: %.2f \n", alta);
    printf("CONDICION: %s \n", condicion);


    return 0;
}