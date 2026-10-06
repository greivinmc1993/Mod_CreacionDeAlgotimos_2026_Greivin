//CONVERTIR DE DECIMAL A BINARIO
#include <stdio.h>

int main(void){
    int numero, cociente,b0 ,b1 ,b2 ,b3 ;
    
    //ENTRADA: LEE EK NUMERO -> NUMERO = 13
    printf("Numero decimal 0 L 15: ");
    scanf("%d", &numero);

    //VALIDACION
    if (numero < 0 || numero > 15)
    {
        printf("Fuera de rango");
        return 1;
    }
    
    //SE EMPIEZA DIVIDIENDO EL NUMERO COMPLETO -> COCIENTE = 13
    cociente = numero;

    //DIVISION
    b0 = cociente % 2;

    //MUESTRA EL PRIIMER PASO
    printf("%2d / 2 = %d residuo %d \n", cociente, cociente / 2, b0);
    cociente = cociente / 2;

    //DIVISION
    b1 = cociente % 2;

    //MUESTRA EL PRIIMER PASO
    printf("%2d / 2 = %d residuo %d \n", cociente, cociente / 2, b1);
    cociente = cociente / 2;

    //DIVISION
    b2 = cociente % 2;

    //MUESTRA EL PRIIMER PASO
    printf("%2d / 2 = %d residuo %d \n", cociente, cociente / 2, b2);
    cociente = cociente / 2;

    //DIVISION
    b3 = cociente % 2;

    //MUESTRA EL PRIIMER PASO
    printf("%2d / 2 = %d residuo %d\n", cociente, cociente / 2, b3);

    //RESULTADOS LOS RESIDUOS SE LEEN DE ABAJO HACIA ARRIBA
    printf("en binario: %d%d%d%d \n", b3, b2, b1, b0);

    //! COMPROBACION AL PONER %o MUESTRA EL NUMERO EN OCTAL Y SI SU USA %x SE MUESTRA EN DECIMAL

    printf("Octal %o, dexadecimal %x \n ", numero, numero);

    return 0;


}