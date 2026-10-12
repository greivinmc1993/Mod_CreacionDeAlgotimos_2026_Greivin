//SIMULA UNA APROBACION O RECHAZO DE CREDITO

#include <stdio.h>
#include <stdbool.h>//LIBRERIA PARA USAR BOOL TRUE FALSE
#include <ctype.h>// CON ESTO SE PUEDE USAR LA FUNCION TOUPPER() PARA PASAR A MAYUSCULA LOS CARACTERES

int main(void){
    //reaLES
    double salario, cuota;
    int antiguedad;
    char respDeudas, respFiador;
    bool capacidadPago, tieneDeudas, tieneFiador, aprobado;


    //Entradas Y LECTURAS
    printf("Ingrese Salario Mensual: ");
    scanf("%lf", &salario);

    printf("Ingrese cuota mensual: ");
    scanf("%lf", &cuota);

    printf("Ingrese años de antiguedad: ");
    scanf("%d", &antiguedad);

    printf("tiene deudas atrasadas: ");
    printf("S/N: ");
    scanf(" %c", &respDeudas);
    respDeudas = toupper(respDeudas);

    printf("tiene fiador: ");
    printf("S/N: ");
    scanf(" %c", &respFiador);
    respFiador = toupper(respFiador);

    capacidadPago = salario >= cuota * 3;

    if (respDeudas == 'S')
    {
        tieneDeudas = true;/* code */
    }
    else
    {
        tieneDeudas = false;/* code */
    }

    if (respFiador == 'S')
    {
        tieneFiador = true;/* code */
    }
    else
    {
        tieneFiador = false;/* code */
    }
    
    aprobado = capacidadPago && !tieneDeudas && (antiguedad >= 1 || tieneFiador);


    //procesos
    if (aprobado)
    {
        printf("Crédito aprobado \n");
    }
    else
    {
        printf("Crédito rechazado \n");
    }
    
    return 0;
}