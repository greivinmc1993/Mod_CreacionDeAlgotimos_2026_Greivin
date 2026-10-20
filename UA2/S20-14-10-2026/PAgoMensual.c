#include <stdio.h>
#include <string.h>


int main(void){
    char nombre[50];
    double ventas[4], mes=0, MontoRet, MontoComi, pago;
    int semana, bono;
    const double COMISION = 0.05, BONO = 50, RETENCION=0.02;

    printf("Ingrese el nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0'; //con strcspn VAMOS AQUITAR EL SALTO DE LINEA QUE GENERA EL FGETS

    for ( semana = 0; semana < 4; semana++)
    {
    //!-----------------------------------------------------------------    
        do
        {
            printf("Ingrese el monto de la semana: %d \n", semana + 1);
            scanf("%lf", &ventas[semana]);

            if (ventas[semana] < 0)
            {
                printf("El valor es incorrecto debe ser mayor a 0 \n");
            }            

        } while (ventas[semana] < 0);
    //!------------------------------------------------------------------    
        mes = mes + ventas[semana];
    }

    //CALCULO DE LA COMISION DEL BONO DEL MES DEL PUNTO 2
    if (mes > 2000)
    {
        printf("SI HAY BONO \n");
        bono = BONO;
    }
    else
    {
        printf("NO HAY BONO \n");
        bono = 0;
    }
    
//------------------------------------------------------------------------------

    //INICIO PUNTO 3 CALCULO DEL 2% Y DEL PAGO
    MontoComi = mes * COMISION;

    MontoRet = (bono + MontoComi) * RETENCION;

    pago = MontoComi + BONO - MontoRet;

    printf("==================================================\n");
    for ( semana = 0; semana < 4 ; semana++)
    {
        printf("Ventas de la semana %d: %.2f\n", semana + 1, ventas[semana]);
    }
    printf("Ventas de mes %.2f:\n", mes);
    
    
    printf("La comisión es de: %.2f \n", MontoComi);
    printf("El bono es de: %.2d \n", bono);
    printf("La retención es de: %.2f \n", MontoRet);
    printf("El pago del mes es de: %.2f \n", pago);
    printf("==================================================\n");


    return 0;
}