//PROMEDIO DE UNA CANTIDAD VARIABLE DE NOTAS
#include <stdio.h>


int main(void){
    //VARIABLES
    double nota, suma, promedio;
    int cantidad, i;

    //INICIALIZACION DE VARIABLES
    suma = 0;

    

    do
    {
        printf("Cuantas notas desea digitar?: ");
        scanf("%d", &cantidad);/* code */

        if (cantidad > 10 || cantidad < 1)
        {
            printf("Valor invalido ingrese valor del 1 al 10 \n");
        }
        

    } while (cantidad > 10 || cantidad < 1);
    

    for ( i = 0; i < cantidad; i++)
    {
        do
        {
            printf("Nota %d: \n", i);
            scanf("%lf", &nota);

            if (nota <= 100 && nota >= 0)//VALIDACION DE NOTAS SEGÚN EL RANGO
            {
                suma += nota;
            }
            else
            {
                printf("Valor invalido ingrese valor del 0 al 100 \n");
            }
            
        } while (nota < 0 || nota > 100);
        
    }//FIN DE FOR

    promedio = suma / cantidad;
    printf("Suma: %.2f \n", suma);
    printf("Promedio: %.2f\n", promedio);
    


    return 0;
}