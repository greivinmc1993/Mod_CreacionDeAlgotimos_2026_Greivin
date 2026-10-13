//CALCULO DE AREAS DE DIFERENTES FIGURAS

#include <stdio.h>

int main(void){

    int opcion;
    double lado, base, altura, radio;
    const double PI = 3.14;

    printf("++++++++++++++++++++++++++++++\n");
    printf("Ingrese la opción que desea realizar: \n");
    printf("1- Cuadrado.\n");
    printf("2- Rectángulo.\n");
    printf("3- Circulo.\n");
    printf("0- Salir\n");
    printf("++++++++++++++++++++++++++++++\n");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        printf("Ingrese la medida del lado del cuadrado: \n");
        scanf("%lf", &lado);
        printf("El area del cuadrado es: %.2f \n", lado * lado);
        break;

    case 2:
        printf("Ingrese la medida de la base del rectángulo: \n");
        scanf("%lf", &base);
        printf("Ingrese la medida de la altura del rectángulo: \n");
        scanf("%lf", &altura);
        printf("El area del rectángulo es: %.2f \n", base * altura);
        break;

    case 3:
        printf("Ingrese la medida del radio del circulo: \n");
        scanf("%lf", &radio);
        printf("El area del circulo es: %.2f \n", PI * (radio * radio));        
        break;
    
    default:
        printf("Opción invalida. \n");
        break;
    }

    return 0;
}