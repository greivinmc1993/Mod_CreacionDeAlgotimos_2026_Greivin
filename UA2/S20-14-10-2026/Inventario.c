
#include <stdio.h>
#include <stdlib.h>

#define PRODUCTOS 5

int main(void) {

    // 1. Arreglos paralelos: los datos coinciden por índice
    int codigos[PRODUCTOS] = {101, 205, 310, 412, 518};

    char descripciones[PRODUCTOS][20] = {
        "Arroz 2 kg",
        "Frijoles 1 kg",
        "Cafe 1 kg",
        "Azucar 2 kg",
        "Aceite 1 L"
    };

    int existencias[PRODUCTOS] = {20, 15, 12, 30, 8};

    double precios[PRODUCTOS] = {
        2400.00, 1800.00, 4500.00, 2100.00, 3200.00
    };

    int codigoBuscado;
    int indice;
    int i;

    // 2. Acumulador para calcular el valor total del inventario
    double valorInventario = 0.0;

    // Sumamos existencias por precio de cada producto
    for (i = 0; i < PRODUCTOS; i++) {
        valorInventario += existencias[i] * precios[i];
    }

    printf("=== CONSULTA DE INVENTARIO ===\n");

    // 3. Centinela: el codigo 0 termina el programa
    do {
        printf("\nIngrese el codigo del producto (0 para terminar): ");

        if (scanf("%d", &codigoBuscado) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }

        // Si ingresa 0, salimos del ciclo
        if (codigoBuscado == 0) {
            break;
        }

        // 4. Busqueda lineal: -1 significa que no se ha encontrado
        indice = -1;

        for (i = 0; i < PRODUCTOS; i++) {

            if (codigos[i] == codigoBuscado) {
                indice = i;  // Guardamos la posicion encontrada
                break;       // Terminamos la busqueda
            }
        }

        // 5. Mostramos el resultado de la busqueda
        if (indice == -1) {
            printf("Codigo %d no encontrado\n", codigoBuscado);
        } else {
            printf("%s: %d unidades a %.2f\n",
                descripciones[indice],
                existencias[indice],
                precios[indice]);
        }

    } while (codigoBuscado != 0);

    // 6. Mostramos el valor total del inventario
    printf("\nValor del inventario: %.2f\n", valorInventario);

    system("pause");
    return 0;
}




/* void pausar() {
    printf("Presiona ENTER para continuar...");
    while (getchar() != '\n'); // Limpia el búfer
    getchar(); // Espera un salto de línea (Enter)
}
 */