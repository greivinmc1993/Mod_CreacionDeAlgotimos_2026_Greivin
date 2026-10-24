
/*
Enunciado:
Un docente desea registrar las notas de cuatro estudiantes
en tres evaluaciones. Debe calcular los promedios, mostrar
los promedios de cada evaluacion, encontrar al estudiante
con mejor promedio y permitir buscar un estudiante.

Que se logra:
Registrar las notas, calcular promedios y determinar si un
estudiante aprobo o no aprobo.

Como se logra:
Se utilizan arreglos, una matriz, ciclos for, condiciones if,
strcmp para comparar nombres y strcpy para guardar la condicion.

Resultado esperado:
Mostrar una tabla con las notas y promedios, el promedio
de cada evaluacion, el mejor estudiante y el resultado
de la busqueda.

Constantes:
ESTUDIANTES: cantidad de estudiantes.
EVALUACIONES: cantidad de evaluaciones.
MIN_NOTA: nota minima permitida.
MAX_NOTA: nota maxima permitida.
APROBACION: nota minima para aprobar.
*/

/* void limpiarEntrada(void)
{
    int caracter;  // Guarda temporalmente cada caracter leido

    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
    }
} */

#include <stdio.h>
#include <string.h>

#define ESTUDIANTES 4
#define EVALUACIONES 3
#define MIN_NOTA 0
#define MAX_NOTA 100
#define APROBACION 70

int main(void)
{
    // Matriz con las notas de los estudiantes
    int notas[4][3];

    // Arreglo con los nombres de los estudiantes
    char nombres[4][15];

    // Arreglo con el promedio de cada estudiante
    float prom[4];

    // Arreglo con el promedio de cada evaluacion
    float promEvaluaciones[3];

    // Variables para recorrer los arreglos
    int i, j;

    // Acumulador para sumar las notas
    int suma;

    // Variable para guardar cada nota ingresada
    int nota;

    // Posicion del estudiante con mejor promedio
    int mejorEstudiante = 0;

    // Nombre que se desea buscar
    char buscar[15];

    // Condicion del estudiante: aprobado o no aprobado
    char condicion[20];

    // Indica si se encontro al estudiante
    int encontrado = 0;

    // Variable para comprobar si se ingreso un numero
    int correcto;

    // Variable auxiliar para limpiar la entrada
    int caracter;

    // Pedir el nombre y las notas de cada estudiante
    for (i = 0; i < ESTUDIANTES; i++)
    {
        printf("\nNombre del estudiante %d: ", i + 1);
        scanf("%14s", nombres[i]);

        // Pedir las tres notas del estudiante
        for (j = 0; j < EVALUACIONES; j++)
        {
            do
            {
                printf("Ingrese la nota %d de %s (0-100): ", j + 1, nombres[i]);

                correcto = scanf("%d", &nota);

                if (correcto != 1)
                {
                    printf("Error: debe ingresar un numero entero.\n");

                    // Limpiar la entrada incorrecta
                    while ((caracter = getchar()) != '\n' && caracter != EOF)
                    {
                    }

                    nota = -1;
                }
                else if (nota < MIN_NOTA || nota > MAX_NOTA)
                {
                    printf("Error: la nota debe estar entre 0 y 100.\n");
                }

            } while (nota < MIN_NOTA || nota > MAX_NOTA);

            // Guardar la nota en la matriz
            notas[i][j] = nota;
        }
    }

    // Calcular el promedio de cada estudiante
    for (i = 0; i < ESTUDIANTES; i++)
    {
        suma = 0;

        for (j = 0; j < EVALUACIONES; j++)
        {
            suma = suma + notas[i][j];
        }

        prom[i] = (float)suma / EVALUACIONES;
    }

    // Calcular el promedio de cada evaluacion
    for (j = 0; j < EVALUACIONES; j++)
    {
        suma = 0;

        for (i = 0; i < ESTUDIANTES; i++)
        {
            suma = suma + notas[i][j];
        }

        promEvaluaciones[j] = (float)suma / ESTUDIANTES;
    }

    // Buscar al estudiante con el mejor promedio
    for (i = 1; i < ESTUDIANTES; i++)
    {
        if (prom[i] > prom[mejorEstudiante])
        {
            mejorEstudiante = i;
        }
    }

    // Mostrar la tabla de notas
    printf("\n====================================================\n");
    printf("%-14s %8s %8s %8s %10s\n", "Estudiante", "Nota 1", "Nota 2", "Nota 3", "Promedio");
    printf("====================================================\n");

    for (i = 0; i < ESTUDIANTES; i++)
    {
        printf("%-14s", nombres[i]);

        for (j = 0; j < EVALUACIONES; j++)
        {
            printf(" %7d", notas[i][j]);
        }

        printf(" %10.2f\n", prom[i]);
    }

    printf("====================================================\n");

    // Mostrar el promedio de cada evaluacion
    printf("\nPromedio de las evaluaciones:\n");

    for (j = 0; j < EVALUACIONES; j++)
    {
        printf("Evaluacion %d: %.2f\n", j + 1, promEvaluaciones[j]);
    }

    // Mostrar al estudiante con el mejor promedio
    printf("\nEstudiante con mejor promedio:\n");
    printf("Nombre: %s\n", nombres[mejorEstudiante]);
    printf("Promedio: %.2f\n", prom[mejorEstudiante]);

    // Pedir el nombre que se desea buscar
    printf("\nIngrese el nombre que desea buscar: ");
    scanf("%14s", buscar);

    // Buscar el nombre en el arreglo
    for (i = 0; i < ESTUDIANTES; i++)
    {
        if (strcmp(buscar, nombres[i]) == 0)
        {
            encontrado = 1;

            // Comprobar si aprobo
            if (prom[i] >= APROBACION)
            {
                strcpy(condicion, "APROBADO");
            }
            else
            {
                strcpy(condicion, "NO APROBADO");
            }

            // Mostrar los datos del estudiante encontrado
            printf("\nEstudiante: %s\n", nombres[i]);
            printf("Promedio: %.2f\n", prom[i]);
            printf("Condicion: %s\n", condicion);
        }
    }

    // Si no se encontro el nombre, mostrar un mensaje
    if (encontrado == 0)
    {
        printf("El estudiante %s no se encuentra en el grupo.\n", buscar);
    }

    return 0;
}
