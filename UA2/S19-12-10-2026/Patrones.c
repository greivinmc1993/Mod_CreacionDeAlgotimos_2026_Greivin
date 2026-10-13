//DIBUJA PATRONES CON CICLOS

#include <stdio.h>

int main(void) {
    int filas;

    // Solicitar la cantidad de filas al usuario
    printf("Cantidad de filas: ");
    scanf("%d", &filas);

    // --- PRIMER PATRÓN: ASTERISCOS (*) ---
    for (int i = 1; i <= filas; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n"); // Salto de línea al terminar cada fila
    }

    // --- SEGUNDO PATRÓN: NÚMEROS (1234) ---
    for (int i = 1; i <= filas; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j); // Imprime el valor actual de j
        }
        printf("\n"); // Salto de línea al terminar cada fila
    }

    return 0;
}
