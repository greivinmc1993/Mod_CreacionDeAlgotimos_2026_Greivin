/*
==========================================================================
                    FACTURACION ELECTRICA
==========================================================================

ENUNCIADO:
Una cooperativa electrica emite recibos de electricidad.
Se solicita el numero de medidor, tipo de cliente y consumo en kWh.
El programa calcula el costo de energia y agrega un 2% de alumbrado
publico. Al finalizar muestra la cantidad de recibos, el total
facturado y el medidor con la factura mayor.

QUE SE LOGRA:
Calcular los recibos electricos de clientes residenciales y
comerciales, aplicando las tarifas correspondientes.

COMO SE LOGRA:
Mediante funciones, ciclos do-while, condiciones if-else, switch,
constantes y punteros para validar, calcular y mostrar resultados.

RESULTADO ESPERADO:
3 recibos.
Total facturado: 101430.00
Medidor con recibo mayor: 1002
Recibo mayor: 46410.00

==========================================================================
*/

#include <stdio.h>

//! CONSTANTES
#define TARIFA_R_1 80
#define TARIFA_R_2 110
#define TARIFA_R_3 150
#define TARIFA_C_1 130
#define TARIFA_FIJA 3000
#define ALUMBRADO 0.02
#define MINIMO 0
#define MAXIMO 3000

//!=================PROTOTIPOS==============================
void limpiarBuffer();
int leerEntero(const char mensaje[], int minimo, int maximo);
char leerSN(const char mensaje[]);
double energiaResidencial(int kwh);
double calcularRecibo(int tipo, int kwh);

int main(void) {

    //! VARIABLES
    int medidor;
    int tipo;
    int kwh;
    int cantidadRecibos = 0;
    int medidorMayor = 0;
    double recibo;
    double totalFacturado = 0;
    double reciboMayor = 0;
    char continuar;

    printf("====================================\n");
    printf("       FACTURACION ELECTRICA\n");
    printf("====================================\n");

    //! REGISTRO DE RECIBOS
    do {

        printf("\n--- NUEVO RECIBO ---\n");

        //* SOLICITAR MEDIDOR
        medidor = leerEntero("Numero de medidor", 1000, 9999);

        //! SOLICITAR TIPO
        printf("\n1. Residencial\n");
        printf("2. Comercial\n");

        tipo = leerEntero("Tipo de cliente", 1, 2);

        //! SOLICITAR CONSUMO
        kwh = leerEntero("Consumo en kWh", MINIMO, MAXIMO);

        //! CALCULAR RECIBO
        recibo = calcularRecibo(tipo, kwh);

        //! MOSTRAR RESULTADO
        printf("\nMedidor: %d\n", medidor);
        printf("Consumo: %d kWh\n", kwh);
        printf("Total del recibo: %.2f\n", recibo);

        //! CONTAR RECIBOS
        cantidadRecibos++;

        //! ACUMULAR TOTAL
        totalFacturado = totalFacturado + recibo;

        //! BUSCAR RECIBO MAYOR
        if (cantidadRecibos == 1 || recibo > reciboMayor) {

            reciboMayor = recibo;
            medidorMayor = medidor;
        }

        //! PREGUNTAR SI HAY OTRO RECIBO
        continuar = leerSN("\nDesea registrar otro recibo? (S/N): ");

    } while (continuar == 'S' || continuar == 's');

    //! RESULTADOS FINALES
    printf("\n====================================\n");
    printf("          RESUMEN FINAL\n");
    printf("====================================\n");

    printf("Cantidad de recibos: %d\n", cantidadRecibos);

    printf("Total facturado: %.2f\n", totalFacturado);

    printf("Medidor con recibo mayor: %d\n", medidorMayor);

    printf("Recibo mayor: %.2f\n", reciboMayor);

    return 0;
}


//!===============FUNCION 1: LIMPIAR BUFFER=======================
void limpiarBuffer() {

    int caracter;

    while ((caracter = getchar()) != '\n' && caracter != EOF) {
    }
}


//!===============FUNCION 2: LEER Y VALIDAR ENTERO================
int leerEntero(const char mensaje[], int minimo, int maximo) {

    int valor;

    do {

        valor = 0;

        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        scanf("%d", &valor);
        limpiarBuffer();

        if (valor < minimo || valor > maximo) {
            printf("ERROR: Dato fuera de rango.\n");
        }

    } while (valor < minimo || valor > maximo);

    return valor;
}


//!=================FUNCION 3: LEER S O N====================
char leerSN(const char mensaje[]) {

    char respuesta;

    do {

        respuesta = ' ';

        printf("%s", mensaje);
        scanf(" %c", &respuesta);

        limpiarBuffer();

        if (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n') {

            printf("ERROR: Debe ingresar S o N.\n");
        }

    } while (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n');

    return respuesta;
}


//!==========FUNCION 4: CALCULAR ENERGIA RESIDENCIAL==========
double energiaResidencial(int kwh) {

    double total;

    if (kwh <= 200) {

        //! Primeros 200 kWh
        total = kwh * TARIFA_R_1;
    }
    else if (kwh <= 400) {

        //! Primeros 200 a 80 y restantes a 110
        total = (200 * TARIFA_R_1) + ((kwh - 200) * TARIFA_R_2);
    }
    else {

        //! Primeros 200 a 80, siguientes 200 a 110 y el resto a 150
        total = (200 * TARIFA_R_1) + (200 * TARIFA_R_2) + ((kwh - 400) * TARIFA_R_3);
    }

    return total;
}


//!==================FUNCION 5: CALCULAR RECIBO===============

double calcularRecibo(int tipo, int kwh) {

    double energia = 0;
    double cargoFijo = 0;
    double alumbrado;
    double total;

    switch (tipo) {

        case 1:

            //! CLIENTE RESIDENCIAL
            energia = energiaResidencial(kwh);

            break;

        case 2:

            //! CLIENTE COMERCIAL
            energia = kwh * TARIFA_C_1;

            cargoFijo = TARIFA_FIJA;

            break;
    }

    //! ALUMBRADO: 2% SOLO SOBRE ENERGIA
    alumbrado = energia * ALUMBRADO;

    //! TOTAL DEL RECIBO
    total = energia + alumbrado + cargoFijo;

    return total;
}