
#include <stdio.h>
#include <string.h>

#define ESTUDIANTES 4
#define EVALUACIONES 3
#define MIN 0
#define MAX 100
#define APROBADO 70

int main(void)
{
    int notas[ESTUDIANTES][EVALUACIONES];
    char nombres[ESTUDIANTES][50];
    float promedios[ESTUDIANTES];
    float evaluaciones[EVALUACIONES];

    int filas, columnas, posicion = 0;
    float sumas = 0;
    float mejor = 0;
    int limpiar, largo;
    char buscar[50];
    char condicion[30];

    // INGRESAR NOMBRES Y NOTAS
    for (filas = 0; filas < ESTUDIANTES; filas++)
    {
        

        do
        {
            
            printf("Ingrese el nombre del estudiante %d:\n", filas + 1);
            fgets(nombres[filas], sizeof(nombres[filas]), stdin);

            // Eliminar el salto de linea que guarda fgets
            nombres[filas][strcspn(nombres[filas], "\n")] = '\0';

            largo = strlen(nombres[filas]);

            if (largo == 0)
            {
                printf("No puede ir vacio.......\n");
            }
            
        } while (largo == 0);
        

        for (columnas = 0; columnas < EVALUACIONES; columnas++)
        {
            do
            {
                printf("Ingrese la nota %d de %s (0-100): ",
                    columnas + 1, nombres[filas]);

                scanf("%d", &notas[filas][columnas]);

                while ((limpiar = getchar()) != '\n' &&
                    limpiar != EOF)
                {
                }

                if (notas[filas][columnas] < MIN ||
                    notas[filas][columnas] > MAX)
                {
                    printf("Debe ingresar un numero entero.\n");
                    notas[filas][columnas] = -1;
                }
                else if (notas[filas][columnas] < MIN ||
                        notas[filas][columnas] > MAX)
                {
                    printf("Nota incorrecta. Use valores de 0 a 100.\n");
                }

            } while (notas[filas][columnas] < MIN ||
                    notas[filas][columnas] > MAX);

            // ACUMULAR LAS TRES NOTAS
            sumas = sumas + notas[filas][columnas];
        }

        // PROMEDIO DEL ESTUDIANTE ACTUAL
        promedios[filas] = sumas / EVALUACIONES;

        // REINICIAR PARA EL SIGUIENTE ESTUDIANTE
        sumas = 0;
    }

    // BUSCAR EL MEJOR PROMEDIO
    mejor = promedios[0];
    posicion = 0;

    for (filas = 1; filas < ESTUDIANTES; filas++)
    {
        if (promedios[filas] > mejor)
        {
            mejor = promedios[filas];
            posicion = filas;
        }
    }

    // CALCULAR EL PROMEDIO DE CADA EVALUACION
    for (columnas = 0; columnas < EVALUACIONES; columnas++)
    {
        for (filas = 0; filas < ESTUDIANTES; filas++)
        {
            sumas = sumas + notas[filas][columnas];
        }

        evaluaciones[columnas] = sumas / ESTUDIANTES;
        sumas = 0;
    }

    // MOSTRAR TABLA DE NOTAS
    printf("\n====================================================\n");
    printf("%-14s %8s %8s %8s %10s\n","Estudiante", "Nota 1", "Nota 2", "Nota 3", "Promedio");
    printf("====================================================\n");

    for (filas = 0; filas < ESTUDIANTES; filas++)
    {
        printf("%-14s", nombres[filas]);

        for (columnas = 0; columnas < EVALUACIONES; columnas++)
        {
            printf(" %7d", notas[filas][columnas]);
        }

        printf(" %10.2f\n", promedios[filas]);
    }

    printf("====================================================\n");

    // MOSTRAR PROMEDIO DE CADA EVALUACION
    for (columnas = 0; columnas < EVALUACIONES; columnas++)
    {
        printf("Promedio de evaluacion %d: %.2f\n",
            columnas + 1, evaluaciones[columnas]);
    }

    // MOSTRAR ESTUDIANTE CON MEJOR PROMEDIO
    printf("\nEstudiante con mejor promedio:\n");
    printf("Nombre: %s\n", nombres[posicion]);
    printf("Promedio: %.2f\n", promedios[posicion]);

    if (promedios[posicion] >= 70)
    {
        strcpy(condicion, "APROBADO");
        printf("%s", condicion);
    }
    else
    {
        strcpy(condicion, "REPROBADO");
        printf("%s", condicion);;
    }

    // BUSCAR ESTUDIANTE
    printf("\nIngrese el nombre que desea buscar: ");
    scanf("%49s", buscar);

    for (filas = 0; filas < ESTUDIANTES; filas++)
    {
        if (strcmp(nombres[filas], buscar) == 0)
        {
            printf("Estudiante: %s\n", nombres[filas]);
            printf("Promedio: %.2f\n", promedios[filas]);
            break;
        }

        

    }

    if (filas == ESTUDIANTES)
        {
            printf("Estudiante no encontrado.\n");
        } 

    return 0;
}
