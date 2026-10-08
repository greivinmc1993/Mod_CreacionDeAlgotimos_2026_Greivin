//SE HACE UN CALCULO PARA CAMBIAR LAS TEMPERATURAS DE CENTIGRADOS A FIRENHEINT

#include <stdio.h>

const FACTOR_CELSIUS = 9/5;
const FACTOR_FAHRENHEIT = 5/9;
const AJUSTE = 32;

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
        resultado = (tempertura * FACTOR_CELSIUS) +32;
        printf("La temperatura en F es: %f", resultado);
        break;
    
    default:
        break;
    }

    return 0;
}


