// Calcula el pago semanal de una persona colaboradora 

#include <stdio.h>

int main(void){
    //DEFINIR VARIABLES
    double horas, tarifaHora, salario;
    #define BONO 5000.0

    //ENTRADA Y SALIDA DE DATOS
    printf ("Horas trabajadas en la semana:");
    scanf ("%lf", &horas);

    printf ("Pago por hora:");
    scanf ("%lf", &tarifaHora);

    //PROCESOS
    salario = (horas * tarifaHora) + BONO;

    printf ("---------------------------------------------\n");
    printf ("%-20s %10.2f\n", "Horas:", horas);
    printf ("%-20s %10.2f\n", "PAgo por hora: ", tarifaHora);
    printf ("%-20s %10.2f\n", "El bono es de: ", BONO);
    printf ("%-20s %10.2f\n", "Salario neto: ", salario);
    printf ("---------------------------------------------");

    return 0;
}