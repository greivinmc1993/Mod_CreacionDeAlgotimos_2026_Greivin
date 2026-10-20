#include <stdio.h>
#include <string.h>

//CONSTANTES
/* #define CENTINELA1 "FIN"
#define CENTINELA2 "fin" */
#define MAX_LIBROS 10
#define ANCHO_PALABRA 50

int main(void){
    char libros[MAX_LIBROS][ANCHO_PALABRA];//! [CANTIDAD DE LIBROS][ANCHO DEL TITULO]
    double precios[MAX_LIBROS];//! LAS VECES QUE VAMOS A PONER EL PRECIO DE LOS LIBROS
    int cantidades[MAX_LIBROS];//! LAS UNIDADES POR CADA LIBRO
    int contadorLibros=0, TotalCantidades=0, i;
    double TotalPrecios=0;
    char tituloTemp[ANCHO_PALABRA];//! PARA GUARDAR EL TITULO DURANTE LA VALIDACION

    printf("Ingrese el titulo del libro: \n");
    printf("O fin para terminar: \n");
    fgets(tituloTemp, sizeof(tituloTemp), stdin );//! PARA GUARDAR EL TEXTO EN TITUTLO TEMPORAL
    tituloTemp[strcspn(tituloTemp, "\n")] = '\0';//! PARA QUITAR EL SALTO DE LINEA


    //! INICIO DEL WHILE PARA VERIFICAR CENTINELA 
    while (strcmp(tituloTemp, "FIN") != 0 && strcmp(tituloTemp, "fin") != 0 && contadorLibros < MAX_LIBROS)
    {
        //! GUARDAR TITULO TEMPORAL EN MATRIZ
        strcpy(libros[contadorLibros], tituloTemp);

        //! VALIDAR PRECIO
        do
        {
            printf("Ingrese el precio del libro: \n");
            scanf("%lf", &precios[contadorLibros]);

            if (precios[contadorLibros] < 0)
            {
                printf("Valor no valido debe ser mayor a 0 \n");
            }
            
        } while (precios[contadorLibros] < 0);

        //! VALIDAR CANTIDADES
        do
        {
            printf("Ingrese ela cantidad: \n");
            scanf("%d", &cantidades[contadorLibros]);

            if (cantidades[contadorLibros] < 0)
            {
                printf("Valor no valido debe ser mayor a 0 \n");
            }
            
        } while (cantidades[contadorLibros] < 0);

        //! ACUMULAMOS EL TOTAL DE PRECIOS Y EL TOTAL DE CANTIDADES
        TotalCantidades = TotalCantidades + cantidades[contadorLibros];
        TotalPrecios = precios[contadorLibros] * cantidades[contadorLibros];

        //! SE SUMA EL CONTADOR CONTADOR LIBROS
        contadorLibros = contadorLibros + 1;

        while (getchar() != '\n')
        {
            
        }
        

        //! 

        printf("Ingrese el titulo del siguiente libro: \n");
        printf("O fin para terminar: \n");
        fgets(tituloTemp, sizeof(tituloTemp), stdin );//! PARA GUARDAR EL TEXTO EN TITUTLO TEMPORAL
        tituloTemp[strcspn(tituloTemp, "\n")] = '\0';//! PARA QUITAR EL SALTO DE LINEA
        
    }

    for ( contadorLibros = 0; contadorLibros < 10; contadorLibros++)
    {
        printf("=========================================s\n" );
        printf("el titulo del libro es: %s\n", libros[contadorLibros] );
        printf("la cantidad es: %d\n",cantidades[contadorLibros] );
        printf("el precio es: %f\n", precios[contadorLibros] );
    }
    
    


    return 0;
}