//PROGRAMA PARA CALCULAR SALARIO NETO

#include <stdio.h>

int main(void){
    //DEFINIR VARIABLES
    double horas, tarifaHora, bruto, deduccion, neto;
    const double rebajo = 0.10;
    #define BONO 5000.0

    //ENTRADA Y SALIDA DE DATOS
    printf ("Ingrese horas trabajadas: ");
    scanf ("%lf", &horas);

    printf ("Ingrese cosro por hora: ");
    scanf ("%lf", &tarifaHora);

    //PROCESOS
    bruto = horas * tarifaHora;

    deduccion = bruto * rebajo;

    neto = bruto - deduccion + BONO;

    printf ("%-20s %10.2f\n", "Salario bruto es de:", bruto);
    printf ("%-20s %10.2f\n", "La deducción es de: ", deduccion);
    printf ("%-20s %10.2f\n", "El bono es de: ", BONO);
    printf ("%-20s %10.2f\n", "Salario neto: ", neto);

    return 0;
}