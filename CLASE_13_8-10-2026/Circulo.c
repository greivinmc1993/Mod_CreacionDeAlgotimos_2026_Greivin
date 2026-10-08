//SACA AREA DE CIRCULOS

#include <stdio.h>

#define PI 3.14159265358979

int main(void){
    //constatnte de cadena de texto
    const char UNIDAD[] = "cm";
    //variables reales para el radio y los resultados
    double radio, area, perimetro;

    printf("Ingrese el radio del circulo: ");
    scanf("%lf", &radio);

    //EN C NO EXISTE IMBOLO DE POTENCIA EL PROCESO SE HACE MUY MANUAL

    area = PI * (radio * radio);

    perimetro = 2 * PI * radio;

    printf("El área del circulo es: %f%s \n", area, UNIDAD);
    printf("El perimetro del circulo es: %f%s", perimetro, UNIDAD);


    return 0;
}