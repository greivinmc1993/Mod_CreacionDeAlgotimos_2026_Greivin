//SE HACE UN CALCULO PARA CAMBIAR LAS TEMPERATURAS DE CENTIGRADOS A FIRENHEINT

#include <stdio.h>

const double FACTOR_CELSIUS = 1.8;
const double FACTOR_FAHRENHEIT = 0.5555555555555556;
const double AJUSTE = 32;

int opcion;
double tempertura, resultado;

int main(void){



    printf("Qué desea realizar?\n");
    printf("1- De C a F\n");
    printf("2- De F a C\n");
    scanf("%d", &opcion);
    


    switch (opcion)
    {
    case 1:
        printf("INGRESE LA TEMP EN CELSIUS\n");
        scanf("%lf", &tempertura);
        resultado = (tempertura * FACTOR_CELSIUS) + AJUSTE;
        printf("La temperatura en F es: %.2f", resultado);
        break;

    case 2:
        printf("INGRESE LA TEMP EN FARENTHEINT\n");
        scanf("%lf", &tempertura);
        resultado = (tempertura - AJUSTE) * FACTOR_FAHRENHEIT;
        printf("La temperatura en C es: %.2f", resultado);
        break;
    
    default:
        break;
    }

    return 0;
}


