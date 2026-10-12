//VALIDAR NOTA

#include <stdio.h>

int main(void){
    //VARIABLES
    double nota;

    //Entradas Y LECTURAS
    do
    {
        printf("Nota del 1 al 100 \n");
        scanf("%lf", &nota);
        
        if (nota < 0 || nota > 100)
        {
            printf("Número invalido \n");/* code */
        }
        
    } while (nota < 0 || nota > 100);
    
    return 0;
}