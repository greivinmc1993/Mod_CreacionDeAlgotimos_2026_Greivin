#include <stdio.h>
#include <string.h>

#define N 4

int buscar(const char nombres[][15], int n, const char buscado[]) {
    int i;

    //* ERROR: El ciclo usaba i <= n.
    for (i = 0; i < n; i++) {
        //* ERROR: Se comparaban cadenas con ==.
        if (strcmp(nombres[i], buscado) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    char nombres[N][15] = {"Arroz", "Frijoles", "Cafe", "Azucar"};
    double precios[N] = {1200, 1500, 3200, 900};
    char buscado[15];
    int pos;

    printf("Producto: ");
    if (scanf("%14s", buscado) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    pos = buscar(nombres, N, buscado);
    if (pos == -1) {
        printf("No existe\n");
    } else {
        printf("%s cuesta %.2f\n", nombres[pos], precios[pos]);
    }
    return 0;
}