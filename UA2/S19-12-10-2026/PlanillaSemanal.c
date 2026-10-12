//PAGO SEMANAL CON HORAS XTRAS DE VARIAS PERSONAS.
#include <stdio.h>
int main(void){
    //! VARIABLES DECLARADAS
    int cantidad, i, conExtra;
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
    for ( i = 1; i < cantidad; i++)
    {
        printf("=========================================\n");
        printf("Ingresa su Nombre: \n");
        printf("=========================================\n");
        scanf("%s", nombre);
            //! CICLO DO-WHILE PARA VALIDAR DATOS CORRECTOS
            do
            {
                printf("=========================================\n");
                printf("Ingrese las horas de la semana: \n");
                printf("=========================================\n");
                scanf("%d", &horas);
                if (horas < 0)
                {
                    printf("DATO INCORRECTO\n");
                }
                
            } while (horas >= 0 || horas <= 72);

            printf("Ingrese la tarifa por hora: \n");
            scanf("%lf", tarifa);

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

            printf
            
            
    }
    
    

    return 0;
}