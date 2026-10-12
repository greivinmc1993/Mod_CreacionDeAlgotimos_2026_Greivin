//SE SIMULA UNA TABLA DEL MULTIPLO 7

#include <stdio.h>

int main(void){
    int num1=7, resultado, i;

    for ( i=1; i < 13; i++)
    {
        resultado = num1 * i;/* code */
        printf("%d x %d = %d \n", num1, i, resultado);
    }
    

    return 0;

}
