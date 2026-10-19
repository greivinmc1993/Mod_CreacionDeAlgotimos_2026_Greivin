
#include <stdio.h>

#define ESTUDIANTES 4
#define DIAS 5

int main(void) {
    char nombres[ESTUDIANTES][10] = {
        "Ana",
        "Luis",
        "Sofia",
        "Daniel"
    };

    // 1 = Presente, 0 = Ausente
    int asistencia[ESTUDIANTES][DIAS] = {
        {1, 1, 1, 1, 1},  // Ana
        {1, 0, 1, 1, 0},  // Luis
        {1, 1, 1, 0, 1},  // Sofia
        {0, 1, 1, 1, 1}   // Daniel
    };

    char dias[DIAS] = {'L', 'K', 'M', 'J', 'V'};

    int i, j;
    int presentes;
    int totalPresentes;

    double porcentaje;

    printf("=== ASISTENCIA SEMANAL ===\n\n");

    // Recorrer las filas: calcular la asistencia de cada estudiante
    for (i = 0; i < ESTUDIANTES; i++) {
        presentes = 0;

        for (j = 0; j < DIAS; j++) {
            presentes += asistencia[i][j];
        }

        // Casting para obtener un porcentaje decimal
        porcentaje = ((double)presentes / DIAS) * 100;

        printf("%s: %.0f%%\n", nombres[i], porcentaje);
    }

    printf("\n=== PRESENTES POR DIA ===\n");

    // Recorrer las columnas: contar presentes de cada dia
    for (j = 0; j < DIAS; j++) {
        totalPresentes = 0;

        for (i = 0; i < ESTUDIANTES; i++) {
            totalPresentes += asistencia[i][j];
        }

        // Operador ternario ?: para mostrar el resultado
        printf("%c: %d estudiante%s\n",
            dias[j],
            totalPresentes,
            totalPresentes == 1 ? "" : "s");
    }

    return 0;
}
