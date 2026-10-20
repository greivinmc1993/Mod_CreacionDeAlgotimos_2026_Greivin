/* Una empresa de consultoría necesita calcular el salario neto de sus empleados. 
Escriba un programa en C */
#include <stdio.h>
#include <string.h>

int main(void){
    const CAJA = 0.095;
    const IESS = 0.025;
    const RENTA = 0.10;
    char nombre[50];
    double salarioBruto, salarioNeto, salarioNeto;

    //! SOLICITUD DE NOMBRE
    printf("Ingrese su nombre");
    fgets(nombre, sizeof(nombre), stdin );//! PARA GUARDAR EL TEXTO EN NOMBRE
    nombre[strcspn(nombre, "\n")] = '\0';//! PARA QUITAR EL SALTO DE LINEA


    return 0;
}