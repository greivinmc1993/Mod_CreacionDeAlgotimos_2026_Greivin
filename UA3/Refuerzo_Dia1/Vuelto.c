/*
=========================================================
EJERCICIO 2: VUELTO EN BILLETES Y MONEDAS
=========================================================

ENUNCIADO:
Calcular el vuelto de una compra y determinar cuantos
billetes y monedas entregar, validando los montos
ingresados y permitiendo registrar varias compras.

QUE SE LOGRA:
Calcular correctamente el vuelto, la cantidad de piezas
necesarias y los colones que no pueden entregarse.

COMO SE LOGRA:
Mediante arreglos, funciones, punteros, ciclos for y
do-while, condiciones y operadores / y %.

RESULTADO ESPERADO:
Compra 13745, pago 20000: vuelto 6255, 6 piezas.
Compra 2318, pago 5000: vuelto 2682, 6 piezas
y 2 colones sin moneda.

=========================================================
*/

#include <stdio.h>

//* CONSTATNTES
#define MAX_COMPRA 1000000
#define MAX_PAGO 2000000000
#define CANT_DEN 11

//* PROTIPOS
void limpiarBuffer();
int leerEntero(const char mensaje[], int minimo, int maximo);
char leerSN(const char mensaje[]);
int cuantas(int *resto, int denominacion);

int main(void){

    //* ARREGLO CON DEMONIMACIONES
    const int DEN[CANT_DEN] = {20000, 10000, 5000, 2000, 1000, 500, 100, 50, 25, 10, 5};

    //* VARIABLES
    int compra, pago, vuelto;
    int resto, piezas, totalPiezas;
    int i;
    char continuar;

    printf("====================================\n");
    printf("      CALCULADORA DE VUELTO\n");
    printf("====================================\n");

    do
    {
        //* SOLICITAR TOTAL DE LA COMPRA
        compra = leerEntero("Total de la compra", 1, MAX_COMPRA);
        pago = leerEntero("Monto pagado", compra, MAX_PAGO);

        //* CALCULAR EL VUELTO
        vuelto = pago - compra;
        resto = vuelto;

        totalPiezas = 0;

        printf("\n========== RESULTADO ==========\n");
        printf("Compra: %d\n", compra);
        printf("Pago: %d\n", pago);
        printf("Vuelto: %d\n", vuelto);

        printf("\nBilletes y monedas a entregar:\n");

        //* FOR PARA RECORRER EL ARREGLO DE MONTOS
        for (i = 0; i < CANT_DEN; i++)
        {
            piezas = cuantas(&resto, DEN[i]);

            //* FICHAS QUE SE USARON
            if (piezas > 0)
            {
                printf("%d de %d colones\n", piezas, DEN[i]);

                //* CONTADOR DE PIEZAS TOTALES
                totalPiezas = totalPiezas + piezas;
            }
            
        }

        //* MOSTRAR COLONES QUE SOBRAN
        if (resto > 0)
        {
            printf("Colones sin moneda: %d\n", resto);
        }
        
        //* MUESTRA TOTAL DE PIEZAS
        printf("Total de piezas: %d \n", totalPiezas);
        

        //* PREGUNTA SI DESEA CONTINUAR
        continuar = leerSN("Otra compra (S/N)");

    } while (continuar == 'S' || continuar == 's');
    


    return 0;
}

//* =======================================================
//* FUNCION 1: LIMPIAR BUFFER
//* Elimina los caracteres que quedaron en la entrada
//* =======================================================

void limpiarBuffer() {

    int caracter;

    while ((caracter = getchar()) != '\n' && caracter != EOF) {
    }
}

//* =======================================================
//* FUNCION 2: LEER UN NUMERO ENTERO
//* Solicita un numero y verifica que este en el rango
//* =======================================================

int leerEntero(const char mensaje[], int minimo, int maximo) {

    int numero;

    do {

        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        scanf("%d", &numero);

        limpiarBuffer();

        if (numero < minimo || numero > maximo) {
            printf("ERROR: Numero fuera de rango.\n");
        }

    } while (numero < minimo || numero > maximo);

    return numero;
}

//* =======================================================
//* FUNCION 3: LEER UN CARACTER
//* Solicita un caracter para continuar o terminar
//* =======================================================

char leerSN(const char mensaje[]){

    char respuesta;

    do {
        printf("%s", mensaje);
        scanf("%c", &respuesta);

        limpiarBuffer();

        if (respuesta != 's' && respuesta != 's' && respuesta != 'n' && respuesta != 'N')
        {
            printf("ERROR: Debe ingresar S/N");
        }
        
    } while (respuesta != 's' && respuesta != 's' && respuesta != 'n' && respuesta != 'N');

    return respuesta;

}

//* =======================================================
//* FUNCION 4: CALCULAR LAS PIEZAS Y EL PUNTEROr
//* =======================================================
int cuantas(int *resto, int denominacion){
    int cantidad;

    //*DIVISION PARA CANTIDAD DE PIEZAS
    cantidad = *resto / denominacion;

    //*DINERO QUEDA
    *resto = *resto % denominacion;

    return cantidad;
}
    
