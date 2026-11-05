#include <stdio.h>   // printf(), scanf(), getchar()
#include <string.h>  // strcpy()

// Ajustar estos limites si el enunciado cambia.
#define MAX_REGISTROS 5
#define MAX_NOMBRE 20
#define MIN_CODIGO 100
#define MAX_CODIGO 999
#define MIN_CANTIDAD 1
#define MAX_CANTIDAD 40

// PROTOTIPOS: permiten llamar las funciones antes de definirlas.
void limpiarBuffer(void);
int leerEntero(const char mensaje[], int minimo, int maximo);
int buscarCodigo(const int codigos[], const int estados[], int n, int codigo);
void incluir(int codigos[], char nombres[][MAX_NOMBRE], int cantidades[], int estados[], int *n);
void consultar(const int codigos[], char nombres[][MAX_NOMBRE], const int cantidades[], const int estados[], int n);
int descontarUnidad(int *cantidad);
void darDeBaja(int *estado);

int main(void) {
    // Datos precargados. Cambiar segun el nuevo enunciado.
    int codigos[MAX_REGISTROS] = {201, 202, 203};
    char nombres[MAX_REGISTROS][MAX_NOMBRE] = {"Ana", "Luis", "Sofia"};
    int cantidades[MAX_REGISTROS] = {5, 1, 8};
    int estados[MAX_REGISTROS] = {1, 1, 1};

    int n = 3; // Hay 3 posiciones utilizadas al iniciar.
    int opcion, codigo, posicion, resultado;

    do {
        printf("\n===== MENU DE REGISTROS =====\n");
        printf("1. Incluir registro\n");
        printf("2. Consultar activos\n");
        printf("3. Descontar una unidad\n");
        printf("4. Dar de baja\n");
        printf("5. Buscar por codigo\n");
        printf("0. Salir\n");

        opcion = leerEntero("Seleccione una opcion", 0, 5);

        switch (opcion) {
            case 1:
                // &n: la funcion puede aumentar n en main.
                incluir(codigos, nombres, cantidades, estados, &n);
                break;

            case 2:
                // n se pasa por valor: consultar no lo modifica.
                consultar(codigos, nombres, cantidades, estados, n);
                break;

            case 3:
                codigo = leerEntero("Codigo", MIN_CODIGO, MAX_CODIGO);
                posicion = buscarCodigo(codigos, estados, n, codigo);

                if (posicion == -1) {
                    printf("No existe un registro activo con ese codigo.\n");
                } else {
                    // &cantidades[posicion]: direccion del dato a modificar.
                    resultado = descontarUnidad(&cantidades[posicion]);
                    if (resultado == 1) {
                        printf("Operacion realizada. A %s le quedan %d unidades.\n", nombres[posicion], cantidades[posicion]);
                    } else {
                        printf("%s no tiene unidades disponibles.\n", nombres[posicion]);
                    }
                }
                break;

            case 4:
                codigo = leerEntero("Codigo", MIN_CODIGO, MAX_CODIGO);
                posicion = buscarCodigo(codigos, estados, n, codigo);

                if (posicion == -1) {
                    printf("No existe un registro activo con ese codigo.\n");
                } else {
                    darDeBaja(&estados[posicion]);
                    printf("Registro de %s dado de baja.\n", nombres[posicion]);
                }
                break;

            case 5:
                codigo = leerEntero("Codigo", MIN_CODIGO, MAX_CODIGO);
                posicion = buscarCodigo(codigos, estados, n, codigo);

                if (posicion == -1) {
                    printf("No existe un registro activo con ese codigo.\n");
                } else {
                    printf("Codigo: %d | Nombre: %s | Cantidad: %d\n", codigos[posicion], nombres[posicion], cantidades[posicion]);
                }
                break;

            case 0:
                printf("Programa finalizado.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}

// Limpia caracteres pendientes hasta Enter. Se usa despues de scanf().
void limpiarBuffer(void) {
    int caracter;
    caracter = getchar();
    while (caracter != '\n' && caracter != EOF) {
        caracter = getchar();
    }
}

// Pide un entero en un rango. scanf() esta FUERA de cualquier if.
// 'leidos' vale 1 cuando scanf pudo leer un entero.
// Se descartan entradas con letras al inicio y numeros fuera de rango.
int leerEntero(const char mensaje[], int minimo, int maximo) {
    int numero = 0;
    int leidos;
    int correcto;

    do {
        correcto = 1;
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        leidos = scanf("%d", &numero);
        limpiarBuffer();

        if (leidos != 1) {
            printf("ERROR: Ingrese un numero entero.\n");
            correcto = 0;
        } else {
            if (numero < minimo || numero > maximo) {
                printf("ERROR: Numero fuera de rango.\n");
                correcto = 0;
            }
        }
    } while (correcto == 0);

    return numero;
}

// Busca SOLO registros activos. Devuelve indice (0, 1, 2...)
// o -1 si no existe. Nunca usar -1 como indice de un arreglo.
int buscarCodigo(const int codigos[], const int estados[], int n, int codigo) {
    int i;
    int posicion = -1;

    for (i = 0; i < n; i++) {
        if (codigos[i] == codigo && estados[i] == 1) {
            posicion = i;
            break; // Ya se encontro: no hace falta seguir.
        }
    }
    return posicion;
}

// Agrega un registro nuevo en la posicion *n.
// El puntero int *n permite cambiar la n original de main().
void incluir(int codigos[], char nombres[][MAX_NOMBRE],
             int cantidades[], int estados[], int *n) {
    int codigo, cantidad;
    int repetido = 0;
    int i;
    char nombre[MAX_NOMBRE];

    if (*n >= MAX_REGISTROS) {
        printf("No hay espacio para mas registros.\n");
    } else {
        codigo = leerEntero("Nuevo codigo", MIN_CODIGO, MAX_CODIGO);

        // Se comprueban TODOS los codigos utilizados, incluso los
        // inactivos, para evitar duplicar identificadores.
        for (i = 0; i < *n; i++) {
            if (codigos[i] == codigo) {
                repetido = 1;
            }
        }

        if (repetido == 1) {
            printf("ERROR: Ese codigo ya fue utilizado.\n");
        } else {
            // %19s limita la lectura a 19 letras mas el '\0'.
            // Esta version admite un nombre de una sola palabra.
            printf("Nombre (una palabra): ");
            scanf("%19s", nombre);
            limpiarBuffer();

            cantidad = leerEntero("Cantidad inicial", MIN_CANTIDAD, MAX_CANTIDAD);

            // Las cuatro asignaciones usan el MISMO indice.
            codigos[*n] = codigo;
            strcpy(nombres[*n], nombre);
            cantidades[*n] = cantidad;
            estados[*n] = 1;

            *n = *n + 1; // Aumenta n en main gracias al puntero.
            printf("Registro incluido (%d de %d).\n", *n, MAX_REGISTROS);
        }
    }
}

// Recorre todos los registros utilizados y muestra solo activos.
// Esta funcion solo muestra los datos; no cambia los arreglos.
void consultar(const int codigos[], char nombres[][MAX_NOMBRE], const int cantidades[], const int estados[], int n) {
    int i;
    int activos = 0;

    printf("\n%-10s %-20s %-10s\n", "CODIGO", "NOMBRE", "CANTIDAD");
    for (i = 0; i < n; i++) {
        if (estados[i] == 1) {
            printf("%-10d %-20s %-10d\n", codigos[i], nombres[i], cantidades[i]);
            activos = activos + 1;
        }
    }
    printf("Total de registros activos: %d\n", activos);
}

// Modifica la cantidad ORIGINAL mediante un puntero.
// Devuelve 1 si desconto una unidad, o 0 si no habia unidades.
int descontarUnidad(int *cantidad) {
    int resultado = 0;
    if (*cantidad > 0) {
        *cantidad = *cantidad - 1;
        resultado = 1;
    }
    return resultado;
}

// Da de baja sin borrar el registro. 1 = activo; 0 = inactivo.
void darDeBaja(int *estado) {
    *estado = 0;
}

/*
============================================================
CHULETA RAPIDA PARA ADAPTAR EN EL EXAMEN
============================================================
1) Si cambian los nombres, cambiar nombres[] y mensajes.
2) Si cambian las cantidades, cambiar cantidades[] y limites.
3) Si hay nuevos datos, crear OTRO arreglo paralelo y agregarlo a los parametros de incluir() y consultar().
4) Para buscar: buscarCodigo(...) devuelve posicion o -1.
5) Para modificar un dato: pasar &arreglo[posicion].
6) Para modificar n: pasar &n desde main y usar *n en funcion.
7) Para dar de baja: estados[posicion] pasa de 1 a 0.
8) Si piden sumar en vez de descontar: *cantidad = *cantidad + 1.
9) Si piden registrar hasta llenar: verificar *n < MAX_REGISTROS.
10) Si piden reutilizar bajas: esta plantilla debe adaptarse.

LIMITACIONES DEL EJEMPLO PRINCIPIANTE:
- Los nombres son de una sola palabra.
- La lectura numerica no rechaza sufijos como 12abc.
- No gestiona cierre de entrada (EOF) como fin de programa.
- El total de posiciones utilizadas no baja al desactivar.
============================================================
*/
