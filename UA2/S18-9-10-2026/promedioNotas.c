//SACA PROMEDIO DE NOTAS INGRESADAS

#include <stdio.h>
int main(void){
    //3 notas enteras y su suma
    int nota1, nota2, nota3, suma;
    //dos resultados reales para comparar
    double promedioMal, promedioBien;

    //Entradas Y LECTURAS: NOTAS
    printf("Digite las 3 notas: ");
    scanf("%d %d %d", &nota1, &nota2, &nota3);

    //procesos
    suma = nota1 + nota2 + nota3;

    //int / int
    promedioMal = suma / 3;
    promedioBien = (double) suma / 3;

    printf("PROMEDIO MAL: %f\n", promedioMal);
    printf("PROMEDIO MAL: %.2f\n", promedioBien);


    return 0;
}