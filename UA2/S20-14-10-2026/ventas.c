//VENTAS DE UNA CADENA DE SODAS POR SUCURSAL Y POR DIA
//QUE LOGRA: GUARDAR EN UNA MATRIZ LAS VENTAS DE 3 SUCURSALES EN 4 DIAS.

//SUMAS CADA SUCURSAL (FILA) Y CADA DIA POR MEDIO DE LA (COLUMNA) E IDENTIFICAR LA SUCURSAL QUE MÁS VENDIÓ, CON SU NOMBRE GUARDADO EN UNA CADENA.
//RESULTADO ESPERADO: CENTRO 470, NORTE 350, SUR 410 POR DIA 330, 270 330, SUCURSAL CON MAS VENTAS CENTRO CON 470

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUC 3  //filas sucursales
#define DIAS 4 //columnas dias

int main(void){

    //ARREGLO DE CADENAS UNA FILA POR NOMBRE CON 9 LETRAS + ´\0´
    char nombres[SUC][10] = {"Central", "Norte", "Sur"};


    //VENTAS EN MILES DE COLONES
    int ventas[SUC][DIAS] ={{120, 100, 130, 120},
                            {90 ,  80, 100,  80},
                            {120,  90, 100, 100}};

    char mejor[10]; //NOMBRE DE LA SUCURSAL GANADORA
    int s=0, d=0, total=0, totalDia=0, mayor=0;

    //ENCABEZADO: D1 A D4
    printf("%-8s", "");
    for ( d = 0; d < DIAS; d++)
    {
        printf("  D%d", d + 1);
    }

    printf("  |  Total\n");

    //RECORRIDO POR FILAS
    for ( s = 0; s < SUC; s++)
    {
        total = 0; //REINICIA CADA FILA EN 0
        printf("%-8s", nombres[s]);
        for ( d = 0; d < DIAS; d++)
        {
            printf("%5d", ventas[s][d]);
            total += ventas[s][d];
        }
        printf("  | %5d\n", total); //470 3750 410

        //GUARDAR LA VARIABLE CON MAYOR TOTAL; STRCPY
        if (total > mayor)
        {
            mayor = total;
            strcpy(mejor, nombres[s]);  //LA MEJOR = CENTRO
        }
        
    }

    //RECORRIDO POR COLUMNAS EL FOR EXTERNO RECORRE LOS DIAS
    printf("%-8s", "Dia");
    for ( d = 0; d < DIAS; d++)
    {
        totalDia = 0;
        for ( s = 0; s < SUC; s++)
        {
            totalDia += ventas[s][d];
        }
        printf("%5d", totalDia);  //330 270 330 300
    }

    printf("\n");

    //SALIDAS: SUCURSAL CON MAS VENTAS: Centro 470
    printf("Sucursal con más ventas: %s (%d)\n", mejor, mayor);

    //system("pause");    

    return 0;
}