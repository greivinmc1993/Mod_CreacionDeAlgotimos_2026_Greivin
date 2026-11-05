/* 1. Enunciado

Crear un programa que registre de 1 a 10 clientes de telefonía, solicitando su número telefónico, plan contratado y GB consumidos. Debe calcular el monto de cada factura, sin superar los ₡25 000.

2. ¿Qué se logra?

Calcular la factura de cada cliente, obtener el total facturado, identificar al cliente que más pagó y contar cuántos llegaron al monto máximo.

3. ¿Cómo se logra?

Utilizando funciones, arreglos, punteros, ciclos y condiciones para registrar los clientes, validar los datos, calcular los cobros adicionales y mostrar los resultados.

4. Resultado esperado

Mostrar una tabla con los números telefónicos, GB consumidos y montos de las facturas, además del total facturado, la factura mayor y la cantidad de clientes que alcanzaron el tope de ₡25 000. */

#include <stdio.h>

#define MAX_CLIENTES 10
#define COSTO_EXTRA 1200
#define TOPE_FACTURA 25000

//* PROTOTIPOS
void limpiarBuffer();
void registrarClientes(int cantidad, char numeros[][20], float consumos[], float facturas[]);
void obtenerPlan(int plan, float *gbIncluidos, float *precio);
int solicitarPlan();
float calcularFactura(float gbUsados, float gbIncluidos, float precio);

int main() {

    //* VARIABLES
    int cantidad;
    int i;
    int posicionMayor = 0;
    int cantidadTope = 0;

    float totalFacturado = 0;

    //* ARREGLOS
    char numeros[MAX_CLIENTES][20];
    float consumos[MAX_CLIENTES];
    float facturas[MAX_CLIENTES];

//* -------------------------------------------------------------------------------    
    //* AQUI SE SOLICITAN CLIENTES
    do {

        cantidad = 0;

        printf("Cantidad de clientes (1-10): ");
        scanf("%d", &cantidad);
        limpiarBuffer();

        if (cantidad < 1 || cantidad > 10) {
            printf("Cantidad invalida.\n");
        }

    } while (cantidad < 1 || cantidad > 10);

//* -------------------------------------------------------------------------------  
    //* AQUI SE REGISTRAN CLIENTES
    registrarClientes(cantidad, numeros, consumos, facturas);

//* -------------------------------------------------------------------------------
    //* PROCESAR FACTURAS
    for (i = 0; i < cantidad; i++) {

        totalFacturado = totalFacturado + facturas[i];

        //* BUSCA FACTURA MAYOR
        if (facturas[i] > facturas[posicionMayor]) {
            posicionMayor = i;
        }

        //* CONTADOR DE CLIENTES QUE SE PASAN EL TOPE
        if (facturas[i] == TOPE_FACTURA) {
            cantidadTope++;
        }
    }

//* -------------------------------------------------------------------------------
    //*PRINTS DE LOS RESULTADOS
    printf("\n========== FACTURACION ==========\n");

    printf("%-15s %-10s %-10s\n", "Numero", "GB", "Monto");

    for (i = 0; i < cantidad; i++) {

        printf("%-15s %-10.2f %.2f\n",numeros[i], consumos[i], facturas[i]);
    }

    printf("\nTotal facturado: %.2f\n", totalFacturado);

    printf("Cliente con factura mayor: %s\n", numeros[posicionMayor]);

    printf("Factura mayor: %.2f\n", facturas[posicionMayor]);

    printf("Clientes que llegaron al tope: %d\n", cantidadTope);

    return 0;
}




//* -----------------------------PROTOTIPOS-------------------------------------
//* -----------------------------FUNCION----1-----------------------------------
//* FUNCION 1: LIMPIAR BUFER
void limpiarBuffer() {

    int caracter;

    while ((caracter = getchar()) != '\n' && caracter != EOF) {
    }
}

//* -----------------------------FUNCION----2-----------------------------------

//* FUNCION 2: SOLICITAR Y VALIDAR EL PLAN
int solicitarPlan() {

    int plan;
    

    do {

        plan = 0;

        printf("\n1. Basico\n");
        printf("2. Medio\n");
        printf("3. Plus\n");

        printf("Seleccione plan: ");
        scanf("%d", &plan);
        limpiarBuffer();

        if (plan < 1 || plan > 3) {
            printf("Debe ingresar un numero.\n");
        }
        else if (plan < 1 || plan > 3) {
            printf("Plan invalido.\n");
        }

    } while (plan < 1 || plan > 3);

    return plan;
}

//* -----------------------------FUNCION----3-----------------------------------

//* FUNCION 3: PARA OBTENER PRECIO Y GBs DEL PLAN
void obtenerPlan(int plan, float *gbIncluidos, float *precio) {

    switch (plan) {

        case 1:
            *gbIncluidos = 5;
            *precio = 6000;
            break;

        case 2:
            *gbIncluidos = 10;
            *precio = 9000;
            break;

        case 3:
            *gbIncluidos = 20;
            *precio = 14000;
            break;
    }
}


//* -----------------------------FUNCION----4-----------------------------------
//* FUNCION 4: CALCULAR FACTURAS
float calcularFactura(float gbUsados, float gbIncluidos, float precio) {

    float total = precio;
    float gbExtra;

    if (gbUsados > gbIncluidos) {

        gbExtra = gbUsados - gbIncluidos;

        total = total + (gbExtra * COSTO_EXTRA);
    }

    if (total > TOPE_FACTURA) {
        total = TOPE_FACTURA;
    }

    return total;

}
//* -----------------------------FUNCION----5-----------------------------------
//* FUNCION 5: REGISTRAR CLIENTES
void registrarClientes(int cantidad, char numeros[][20], float consumos[], float facturas[]) {

    int i;
    int plan;

    float gbIncluidos;
    float precio;

    for (i = 0; i < cantidad; i++) {

        printf("\n--- CLIENTE %d ---\n", i + 1);

        //* REGISTRAR NUMERO
        printf("Numero telefonico: ");
        scanf("%19s", numeros[i]);
        limpiarBuffer();


        //* SOLICITAR EL PLAN
        plan = solicitarPlan();


        //* SOLICTAR, VALIDAR EL CONSUMO
        do {

            consumos[i] = -1;

            printf("GB utilizados (0-100): ");
            scanf("%f", &consumos[i]);
            limpiarBuffer();

            if (consumos[i] < 0 || consumos[i] > 100) {
                printf("Debe ingresar un numero.\n");
            }
            else if (consumos[i] < 0 || consumos[i] > 100) {
                printf("Consumo invalido.\n");
            }

        } while (consumos[i] < 0 || consumos[i] > 100);


        //* USO DE LOS PUNTEROS PARA OBTENER GBs Y PRECIOS DEL PLAN
        obtenerPlan(plan, &gbIncluidos, &precio);

        //* CALCULAR FACTURA Y GUARDARLA
        facturas[i] = calcularFactura(consumos[i], gbIncluidos, precio);
        
    }
}





