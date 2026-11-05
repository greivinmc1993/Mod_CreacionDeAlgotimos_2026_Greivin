//* No actualizaba el original.
//* Solo modificaba una copia local.
//* Recibir un puntero y modificar el valor apuntado.
#include <stdio.h>

void sumarPuntos(int *puntos, int compra) {
    *puntos = *puntos + compra / 1000;
}

int main(void) {
    int puntos = 0, compra, i;

    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);
        if (scanf("%d", &compra) != 1) {
            printf("Compra invalida.\n");
            return 1;
        }
        sumarPuntos(&puntos, compra);
    }

    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}
