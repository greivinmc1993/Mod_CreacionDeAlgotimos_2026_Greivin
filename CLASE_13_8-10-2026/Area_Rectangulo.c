//SAC EL ÁREA DE UN RÉCTANGULO

#include <stdio.h>

int main(void){
    //declarar variable double
    double base, altura, area;

    //Entrada de datos
    printf("Digite la base del rectangulo (cm):");
    scanf("%lf", &base);

    printf("Digite la altura del rectangulo (cm):");
    scanf("%lf", &altura);

    area = base * altura;

    printf("El área del rectangulo es: %5.2fcm", area);



    return 0;
}