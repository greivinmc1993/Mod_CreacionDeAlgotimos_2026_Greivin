//* UN CINE REGISTRA LAS COMPRAS DE UNA FUNCION DE 1 A 10 COMPRAS POR PERSONA SE DIGITA EL NOMBRE, EL TIPO DE ENTRADA 1 PARA GENERAL 3500 2 PARA NIÑO 2500 3 PARA ADULTO MAYOR 2000 Y LA CANTIDAD DE ENTRADAS DE 1 A 8 SE VALIDAD QUE NO SEA UN VALOR INCORRECTO SI SON MAS DE 5 ENTRADAS SE HACE UN 10% DE DESCUENTO

#include <stdio.h>
//* SE DEFINEN CONSTANTES
#define MAX_COMPRAS 10
#define GENERAL 3500
#define NIÑOS 2500
#define DORADO 2000
#define PARA_DESCUENTO 5
#define TASA_DESCUENTO 0.10

//* PROTOTIPOS
int leerEntero(const char mensaje[], int minimo, int maximo);
float precioEntrada(int tipo);
float calcTotal(int tipo, int cantidad);
void resumir(const int cant[], const float tot[], int n, int* posMayor, int* conDescuento);

//* MAIN
int main(void){

    //* SE DEFINEN VARIBLES
    char clientes[MAX_COMPRAS][15];     //* NOMBRES DE LOS CLIENTES
    int cantidades[MAX_COMPRAS];           //* CANTIDAD DE COMPRAS DEL CLIENTE
    float totales[MAX_COMPRAS];         //* TOTALES DE TODAS LAS COMPRAS

    //* CANTIDAD DE COMPRAS,  INDICE, TIPO DE ENTRADA
    int n, i, tipo;
    //*CANTIDAD DE COMPRAS  
    float totalVendido;
    //* RESULTADOS
    int posMayor, conDescuento;

    //* PORTADA
    puts("=====VENTA DE ENTRADAS=====");
    printf("Tipos: 1-General ===> 3500 \n 2-Niños ===> 2500 \n 3-Adulto Mayor ===> 2000");

    //* LEER CANTIDAD DE COMPRAS -> 4
    n = leerEntero("\nCantidad de compras\n", 1, MAX_COMPRAS);

    //* VUELTA POR COMPRA
    for ( i = 0; i < n; i++)
    {
        printf("Compras %d\n cliente: ", i+1);//* NUMERO DE COMPRA Y PEDIDO DEL CLIENTE
        scanf("%14s", clientes[i]);

        //* SE LEE EL TIPO DE ENTRADA
        tipo = leerEntero("Ingrese el tipo: ", 1, 3);

        //* LEER CANTIDAD DE ENTRADAS
        cantidades[i] = leerEntero("Entradas ", 1, 8);

        //*CALCULAR TOTAL DE LA COMPRA
        totales[i] = calcTotal(tipo, cantidades[i]);

        totalVendido = totalVendido + totales[i];
    }
    
    //* CALCULAR EL RESUMEN EN UNA PASADA
    resumir(cantidades, totales, n, &posMayor, &conDescuento);

    //* ENCABEZADO DE LA TABLA
    puts("=====================================");
    printf("\n %-12s %9s %12s\n", "clientes", "cantidades", "totales");

    //* RECORRER LAS COMPRAS
    for ( i = 0; i < n; i++)
    {
        printf(" %-12s %9d %12.2f\n", clientes[i], cantidades[i], totales[i]);

        
        
    }


    //* TOTAL VENDIDO
        puts("=====================================");
        printf("\nTotal vendido: %12.2f\n ", totalVendido);

        //* COMPRA MAYOR
        printf("\nCompra mayor: %s %12.2f\n ", clientes[posMayor], totales[posMayor]);

        //* COMPRAS CON DESCUENTO
        printf("\nCon descuento:      %d compras(s)\n \n",conDescuento);

    
    //* TERMINA EL MAIN
    return 0;
}

//* DEFINICIONES, LEER ENTERO
int leerEntero(const char mensaje[], int minimo, int maximo){
    //*VARIABLE LOCAL PARA EL DATO
    int valor;

    do
    {
        printf("%s (%d a %d)\n", mensaje, minimo, maximo);
        scanf("%d", &valor);

        if (valor < minimo || valor > maximo)
        {
            puts("valor invalido.............");
        }
        

    } while (valor < minimo || valor > maximo);

    return valor;
    
}

//*DEFINICION PRECIOENTRADA
float precioEntrada(int tipo){
    switch (tipo)
    {
    case 1:
        return GENERAL;
        

    case 2:
        return NIÑOS;

    case 3:
        return DORADO;

    default:
        return 0;
    
    }
}

//* CALCULAR TOTAL
float calcTotal(int tipo, int cantidad){
    float total = precioEntrada(tipo) * cantidad;

    if (cantidad >= PARA_DESCUENTO)
    {
        total = total * (1 - TASA_DESCUENTO);
    }
    
    return total;

}

//* DEFINIR RESUMIR
void resumir(const int cant[], const float tot[], int n, int* posMayor, int* conDescuento){
    int i;
    //* INICIALIZA LOS TRES RESULTADOS EN LA MEMORIA DE MAIN

    *posMayor = 0;
    *conDescuento = 0;

    //* RECORRER LAS COMPRAS
    for ( i = 0; i < n; i++)
    {
        if (tot[i] > tot[*posMayor])
        {
            *posMayor = i;
        }
        
        if (cant[i] >= PARA_DESCUENTO)
        {
            *conDescuento = *conDescuento + 1;
        }
        
    }
    
}