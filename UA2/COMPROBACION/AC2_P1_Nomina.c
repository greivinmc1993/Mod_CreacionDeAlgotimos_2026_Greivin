/* Una empresa de consultoría necesita calcular el salario neto de sus empleados. 
Escriba un programa en C */
#include <stdio.h>
#include <string.h>

int main(void){
    const double CAJA = 0.095;
    const double IESS = 0.025;
    const double RENTA = 0.10;
    char nombre[50];
    double salarioBruto, salarioNeto, montoCaja, montoIess, montoRenta;

    //! SOLICITUD DE NOMBRE
    do
    {
        printf("Ingrese su nombre: \n");
        fgets(nombre, sizeof(nombre), stdin );//! PARA GUARDAR EL TEXTO EN NOMBRE
        nombre[strcspn(nombre, "\n")] = '\0';//! PARA QUITAR EL SALTO DE LINEA

        if (strlen(nombre) == 0)//! VERIFICAR QUE NO ESTÉ VACIO
        {
            printf("El nombre no puede estar vacio: \n");
        }
        

    } while (strlen(nombre) == 0);


    //! SOLICITUD DE SALARIO
    do
    {
        printf("Ingrese su salario bruto: \n");
        scanf("%lf", &salarioBruto);//! PARA GUARDAR EL SALARIO

        if (salarioBruto <= 0)//! VERIFICAR QUE NO SEA MENOR O IGUAL A 0
        {
            printf("El salario no puede ser menor o igual a 0: \n");
        }
        

    } while (salarioBruto <= 0);
    
    
    //! CALCULOS
    montoCaja = salarioBruto * CAJA;
    montoIess = salarioBruto * IESS;
    
    if (salarioBruto > 800)
    {
        montoRenta = salarioBruto * RENTA;
    }
    else
    {
        montoRenta = 0;
    }

    salarioNeto = salarioBruto - montoCaja - montoIess - montoRenta;

    printf("==============COMPROBANTE DE PAGO================ \n");
    printf("Empleado : \t\t %s \n", nombre);
    printf("Salario bruto: \t\t %.2f \n", salarioBruto);
    printf("Descuento CAJA (9.5%%): \t %.2f \n", montoCaja);
    printf("Descuento IESS (2.5%%): \t %.2f \n", montoIess);
    printf("Descuento RENTA (10%%): \t %.2f \n", montoRenta);
    printf("Salario NETO: \t\t %.2f \n", salarioNeto);
    printf("==============COMPROBANTE DE PAGO================ \n");

    



    return 0;
}