#include <stdio.h>
#include <string.h>

/* ENUNCIADO: Administrar pases de bus estudiantiles.
QUE SE LOGRA: Incluir, consultar, usar, buscar y dar de baja.
COMO SE LOGRA: Arreglos paralelos, funciones, punteros y menu.
RESULTADO: 3 pases iniciales; hasta 5 posiciones usadas. */

#define MAX_PASES 5
#define MIN_CODIGO 100
#define MAX_CODIGO 999
#define MIN_VIAJES 1
#define MAX_VIAJES 40
#define MAX_NOMBRE 20

int leerEntero(const char mensaje[], int minimo, int maximo);
int buscarCodigo(const int codigos[], const int estados[],int n, int codigo);
void incluir(int codigos[], char nombres[][MAX_NOMBRE],int viajes[], int estados[], int *n);
void consultar(const int codigos[],const char nombres[][MAX_NOMBRE],const int viajes[], const int estados[], int n);
int usarViaje(int *viajes);
void darDeBaja(int *estado);

int main(void) {
    // Cada posicion representa un estudiante en los 4 arreglos.
    int codigos[MAX_PASES] = {201, 202, 203};
    char nombres[MAX_PASES][MAX_NOMBRE] = {
        "Ana", "Luis", "Sofia"
    };
    int viajes[MAX_PASES] = {5, 1, 8};
    int estados[MAX_PASES] = {1, 1, 1};
    int n = 3;
    int opcion, codigo, posicion, resultado;

    do {
        printf("\n=== PASES DE BUS ESTUDIANTILES ===\n");
        printf("1. Incluir pase\n");
        printf("2. Consultar pases\n");
        printf("3. Registrar un viaje\n");
        printf("4. Dar de baja un pase\n");
        printf("5. Buscar pase\n");
        printf("0. Salir\n");
        opcion = leerEntero("Seleccione una opcion", 0, 5);
        if (opcion == -1) {
            printf("Entrada finalizada.\n");
            break;
        }
        switch (opcion) {
            case 1:
                incluir(codigos, nombres, viajes, estados, &n);
                break;
            case 2:
                consultar(codigos, nombres, viajes, estados, n);
                break;
            case 3:
                codigo = leerEntero("Codigo del pase",
                                    MIN_CODIGO, MAX_CODIGO);
                if (codigo == -1) break;
                posicion = buscarCodigo(codigos, estados, n, codigo);
                if (posicion == -1) {
                    printf("No existe un pase activo con el codigo %d.\n",codigo);
                } else {
                    resultado = usarViaje(&viajes[posicion]);
                    if (resultado == 1)
                        printf("A %s le quedan %d viajes.\n",nombres[posicion], viajes[posicion]);
                    else
                        printf("%s no tiene viajes disponibles.\n",nombres[posicion]);
                }
                break;
            case 4:
                codigo = leerEntero("Codigo del pase",
                                    MIN_CODIGO, MAX_CODIGO);
                if (codigo == -1) break;
                posicion = buscarCodigo(codigos, estados, n, codigo);
                if (posicion == -1) {
                    printf("No existe un pase activo con el codigo %d.\n",codigo);
                } else {
                    darDeBaja(&estados[posicion]);
                    printf("Pase de %s dado de baja.\n",nombres[posicion]);
                }
                break;
            case 5:
                codigo = leerEntero("Codigo del pase",
                                    MIN_CODIGO, MAX_CODIGO);
                if (codigo == -1) break;
                posicion = buscarCodigo(codigos, estados, n, codigo);
                if (posicion == -1) {
                    printf("No existe un pase activo con el codigo %d.\n",codigo);
                } else {
                    printf("%d %s: %d viajes.\n", codigos[posicion],nombres[posicion], viajes[posicion]);
                }
                break;
            case 0:
                printf("Gracias por utilizar el sistema.\n");
                break;
        }
    } while (opcion != 0);
    return 0;
}

// Lee una linea y comprueba que sea un entero dentro del rango.
int leerEntero(const char mensaje[], int minimo, int maximo) {
    char texto[100], extra;
    int numero, correcto;
    do {
        correcto = 0;
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        if (fgets(texto, sizeof(texto), stdin) == NULL)
            return -1;
        if (strchr(texto, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("ERROR: Entrada demasiado larga.\n");
        } else if (sscanf(texto, " %d %c", &numero, &extra) == 1) {
            if (numero >= minimo && numero <= maximo)
                correcto = 1;
            else
                printf("ERROR: Numero fuera de rango.\n");
        } else {
            printf("ERROR: Ingrese solo un numero entero.\n");
        }
    } while (correcto == 0);
    return numero;
}

// Busca solo pases activos. Devuelve posicion o -1.
int buscarCodigo(const int codigos[], const int estados[],int n, int codigo) {
    int i, posicion = -1;
    for (i = 0; i < n; i++) {
        if (codigos[i] == codigo && estados[i] == 1) {
            posicion = i;
            break;
        }
    }
    return posicion;
}

// Agrega un pase y aumenta *n: modifica n de main.
void incluir(int codigos[], char nombres[][MAX_NOMBRE],
             int viajes[], int estados[], int *n) {
    int codigo, cantidadViajes, posicion;
    char nombre[MAX_NOMBRE], linea[100], extra;
    int correcto;
    if (*n >= MAX_PASES) {
        printf("No hay espacio para mas pases.\n");
    } else {
        codigo = leerEntero("Codigo del nuevo pase",
                            MIN_CODIGO, MAX_CODIGO);
        if (codigo == -1) return;
        posicion = buscarCodigo(codigos, estados, *n, codigo);
        if (posicion != -1) {
            printf("El codigo %d ya existe.\n", codigo);
        } else {
            // Una palabra de hasta 19 caracteres.
            do {
                correcto = 0;
                printf("Nombre del estudiante: ");
                if (fgets(linea, sizeof(linea), stdin) == NULL)
                    return;
                if (strchr(linea, '\n') == NULL) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) { }
                    printf("ERROR: Nombre demasiado largo.\n");
                } else if (sscanf(linea, " %19s %c",nombre, &extra) == 1) {
                    correcto = 1;
                } else {
                    printf("ERROR: Escriba un solo nombre valido.\n");
                }
            } while (correcto == 0);
            cantidadViajes = leerEntero("Viajes disponibles",MIN_VIAJES, MAX_VIAJES);
            if (cantidadViajes == -1) return;
            codigos[*n] = codigo;
            strcpy(nombres[*n], nombre);
            viajes[*n] = cantidadViajes;
            estados[*n] = 1;
            *n = *n + 1;
            printf("Pase incluido (%d de %d).\n", *n, MAX_PASES);
        }
    }
}

// Recorre las posiciones utilizadas y muestra solo activos.
void consultar(const int codigos[],const char nombres[][MAX_NOMBRE],const int viajes[], const int estados[], int n) {
    int i, activos = 0;
    printf("\n%-10s %-20s %-10s\n", "CODIGO", "NOMBRE", "VIAJES");
    for (i = 0; i < n; i++) {
        if (estados[i] == 1) {
            printf("%-10d %-20s %-10d\n",codigos[i], nombres[i], viajes[i]);
            activos++;
        }
    }
    printf("Pases activos: %d\n", activos);
}

// Devuelve 1 si pudo descontar un viaje, o 0 si no quedaban.
int usarViaje(int *viajes) {
    int resultado = 0;
    if (*viajes > 0) {
        *viajes = *viajes - 1;
        resultado = 1;
    }
    return resultado;
}

// Cambia el estado original del pase a inactivo.
void darDeBaja(int *estado) {
    *estado = 0;
}
