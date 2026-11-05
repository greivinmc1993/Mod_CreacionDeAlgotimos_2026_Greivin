#include <stdio.h>

#define TARIFA_R_1 80
#define TARIFA_R_2 110
#define TARIFA_R_3 150
#define TARIFA_C_1 130
#define TARIFA_FIJA 3000
#define ALUMBRADO 0.02
#define MINIMO 0
#define MAXIMO 3000

void limpiarBuffer();
int leerEntero(const char mensaje[], int minimo, int maximo);
char leerSN(const char mensaje[]);
double energiaResidencial(const char mensaje[], int minimo, int maximo);
double calcularRecibo(int tipo, int kwh, int tarifa1, int tarifa2, int tarifa3, int tarifac, int fija, int alumbrado);


int main(void){
    int prueba, kwh, tipo, medidor = 1000;


    tipo = leerEntero("ingrese el tipo de servicio ", 1, 2);
    printf("%d", tipo);


    return 0;
}

//*====================FUNCIONES==============================
//*====================FUNCION 1==============================
//*LIMPIAR BUFER
void limpiarBuffer() {
    int caracter;

    while ((caracter = getchar()) != '\n' && caracter != EOF) {
    }
}


//*====================FUNCION 2==============================
//*LEER ENTERO
int leerEntero(const char mensaje[], int minimo, int maximo){
    
    int valor = 0;

    do{
        printf("%s %d al %d \n", mensaje, minimo, maximo);
        scanf("%d", &valor);
        limpiarBuffer();

        if (valor < minimo || valor > maximo)
        {
            puts("Dato fuera de rango");
        }
        
    } while (valor < minimo || valor > maximo);
    
    return valor;   
}

//*====================FUNCION 2==============================
//*ENERGIA RESIDENCIAL
double energiaResidencial(const char mensaje[], int minimo, int maximo){
    
    int kwh = 0;

    do{
        printf("%s %d al %d \n", mensaje, minimo, maximo);
        scanf("%d", &kwh);
        limpiarBuffer();

        if (kwh < minimo || kwh > maximo)
        {
            puts("Dato fuera de rango");
        }
        
    } while (kwh < minimo || kwh > maximo);
    
    return kwh;   
}

//*====================FUNCION 3==============================
//*CALCULAR RECIBO
double calcularRecibocalcularRecibo(int tipo, int kwh, int tarifa1, int tarifa2, int tarifa3, int tarifac, int fija, int alumbrado){
    
    
    switch (tipo)
    {
    case 1:
        if (kwh <= 200  )
        {
            /* code */
        }
        
        break;

    case 2:
        /* code */
        break;
    
    default:
        break;
    }
}