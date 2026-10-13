//PAGO SEMANAL CON HORAS XTRAS DE VARIAS PERSONAS.
#include <stdio.h>
#include <string.h>

int main(void){
    //! VARIABLES DECLARADAS
    int cantidad, i, conExtra, longitud;
    char nombre[100];
    double horas, tarifa, horasExtra, pago, totalPlanilla;
    //! SE INICIAN ACUMULADORES
    totalPlanilla = 0;
    conExtra = 0;


    printf("=========================================\n");
    printf("Cnatidad de personas colaboradoras: \n");
    printf("=========================================\n");
    scanf("%d", &cantidad);
    //! CICLO PARA INICIALIZAR EL INGRESO DE TRABJADORES
    for ( i = 0; i < cantidad; i++)
    {//! INICIO DEL CICLO
        printf("=========================================\n");
        printf("Ingresa su Nombre: \n");
        printf("=========================================\n");
        scanf(" %s", nombre);
            //! CICLO DO-WHILE PARA VALIDAR DATOS CORRECTOS
            do
            {
                printf("=========================================\n");
                printf("Ingrese las horas de la semana: \n");
                printf("=========================================\n");
                scanf("%lf", &horas);
                if (horas < 0)
                {
                    printf("DATO INCORRECTO\n");
                }
                
            } while (horas < 0 || horas > 72);

            printf("Ingrese la tarifa por hora: \n");
            scanf("%lf", &tarifa);

            if (horas > 48)
            {
                horasExtra = horas - 48;
                pago = (48 * tarifa) + (horasExtra * (tarifa *1.5));
                conExtra = conExtra + 1;
            }
            else
            {
                pago = horas * tarifa;
            }

            printf("%s : %.2f Horas extra %.2f Pago de extras: %.2f \n", nombre, pago, horasExtra, tarifa*1.5);
            totalPlanilla = totalPlanilla + pago;
            
            
    }//! FIN DEL FOR

    longitud = strlen(nombre);
    printf("Total de la planilla: %.2f\n", totalPlanilla);
    printf("Personas con horas extra: %d\n", conExtra);
    printf("Longitud de arreglo: %d\n", longitud);
    
    

    return 0;
}