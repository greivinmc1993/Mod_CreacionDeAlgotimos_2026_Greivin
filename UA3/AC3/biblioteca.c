/* 
ENUNCIADO: La biblioteca de un colegio necesita un sistema para controlar el préstamo de sus libros. Puede 
registrar hasta 5 libros. De cada libro se guarda: el código (100 a 999, no se repite), el título (una 
sola palabra, hasta 19 letras), los ejemplares disponibles y si el libro está activo o dado de baja. 
El programa inicia con 3 libros ya cargados (tabla de abajo). Debe mostrar un menú que se repite 
hasta elegir 0; toda opción o dato fuera de rango se vuelve a pedir. 

SE LOGRA: INCLUYENDO, CONSULTANDO, PRESTANDO, DANDO DE BAJA Y BUSCANDO LIBROS CON ESAS FUNCIONES

RESULTADO: ADMINISTRAR LIBROS ACTIVOS Y SUS EJEMPLARES
*/

#include <stdio.h>

#define MAX_LIBROS 5        //* PARA EL MAXIMO DE LIBROS
#define MIN_CODIGO 100      //* PARA EL MIN DE CODIGOS
#define MAX_CODIGO 999      //* PARA EL MAXIMO DE CODIGOS
#define MIN_EJEMPLARES 1    //* PARA EL MINIMO DE EJEMPLARES
#define MAX_EJEMPLARES 20   //* PARA EL MAXIMO DE EJEMPLARES
#define MAX_TITULO 20       //* PARA EL MAXIMO DE LA PALABRA

/* leerEntero Pide un entero entre un mínimo y un máximo y lo vuelve a pedir si está fuera de rango (do-while). 
— 
buscarCodigo Búsqueda secuencial de un libro ACTIVO por código; devuelve la 
posición o -1. 
— 
incluir Guarda el libro en la primera posición libre y aumenta la cantidad. La cantidad de libros (int *n) 

consultar Muestra la tabla de libros activos y cuántos son. — 

prestar Resta un ejemplar disponible; devuelve 1 si pudo o 0 si no había Los disponibles del libro 

darDeBaja Pone el estado del libro en 0. El estado del libro  */

//*===============================PROTOTIPOS================================
//* YO SIEMPRE USO ESTA PARA EVITAR BASURA DE BUFER POR ERRORES PASADOS CON SCANF
void limpiarBuffer();
int leerEntero(int minimo, int maximo);
int buscarCodigo(int codigos[], int estados[], int n, int codigo);
void incluir(int codigos[], char titulos[][MAX_TITULO], int disponibles[], int estados[], int *n);
void consultar(int codigos[], char titulos[][MAX_TITULO], int disponibles[], int estados[], int n);
int prestar(int *disponibles);
void darDeBaja(int *estado);


//*=================================MAIN=================================
int main(void){
    //*ARRGLOS PARALELOS Y VARIABLES
    int codigos[MAX_LIBROS] = {101, 102, 103};
    char titulos[MAX_LIBROS][MAX_TITULO] = {"Quijote", "Principito", "Cocori"};
    int disponibles[MAX_LIBROS] = {3, 2, 4};
    int estados[MAX_LIBROS] = {1, 1, 1};
    int n = 3;
    int opcion, codigo, pos;

    do
    {
        puts("====== LA BIBLIOTECA ======");
        //* USO PUTS PORQUE YA PONE EL SALTO DE LINEA DE FORMA AUTOMATICA PERO NO SIRVE PARA TRAER VARIABLES
        puts("1- Incluir libro");
        puts("2- Consultar libros.");
        puts("3- Prestar ejemplar");
        puts("4- Dar de baja libro.");
        puts("5- Buscar libro.");
        puts("0- Salir");
        puts("Seleccione una opcoin dentro del rango: ");
        puts("===========================");
        opcion = leerEntero(0, 5);

        switch (opcion) {
            case 1:
                //* OPCION 1 INCLUIR LIBROS NUEVOS
                incluir(codigos, titulos, disponibles, estados, &n);

                break;

            case 2:
                //* OPCION 2 PARA COSULTAR TODO
                consultar(codigos, titulos, disponibles, estados, n);

                break;

            case 3:
                //* OPCION 3 PARA PRESTAR LIBRO DISPONIBLE
                printf("Codigo del libro: ");

                codigo = leerEntero(MIN_CODIGO, MAX_CODIGO);
                pos = buscarCodigo(codigos, estados, n, codigo);

                if(pos == -1)
                {
                    printf("No existe un libro activo con el codigo %d\n", codigo);

                }else if(prestar(&disponibles[pos]) == 1){
                    printf("Prestamo realizado. Quedan %d\n", disponibles[pos]);

                }else{
                    printf("No hay ejemplares disponibles.\n");
                }
                break;

            case 4:
                //* OPCION 4 PARA BORRAR UN LIBRO DE LA LISTA
                printf("Codigo del libro: ");

                codigo = leerEntero(MIN_CODIGO, MAX_CODIGO);
                pos = buscarCodigo(codigos, estados, n, codigo);
                
                if(pos == -1)
                {
                    printf("No existe un libro activo con el codigo %d\n", codigo);

                }else{
                    darDeBaja(&estados[pos]);
                    printf("Libro %s dado de baja.\n", titulos[pos]);

                }
                break;

            case 5:
                //* OPCION 5 PARA BUSCAR LIBRO
                printf("Codigo del libro: ");

                codigo = leerEntero(MIN_CODIGO, MAX_CODIGO);
                pos = buscarCodigo(codigos, estados, n, codigo);

                if(pos == -1){
                    printf("No existe un libro activo con el codigo %d\n", codigo);
                }else{
                    printf("Codigo: %d\n", codigos[pos]);
                    printf("Titulo: %s\n", titulos[pos]);
                    printf("Disponibles: %d\n", disponibles[pos]);
                }
                break;

            case 0:
                printf("Gracias por usar la biblioteca Chaolin.\n");
                break;

            default:
            printf("Opcion fuera del rango.\n");
            break;
        }

    } while (opcion != 0);
    

    return 0;
}
//*=============================FIN DE MAIN=================================


//*=============================FUNCIONES=================================
//* FUNCION 1 LIMPIAR BUFFER
void limpiarBuffer(){
    int caracter;

    while ((caracter = getchar()) != '\n' && caracter != EOF){}    
}

//* FUNCION 2 LEER LOS ENTEROS USANDO EL DO, PIDE UN ENTERO ENTRE MINIMO Y UN MAXIMO Y LO VUELVE A PEDIR SI ESTA FUERA DEL RANGO
int leerEntero(int minimo, int maximo){
    int numero = 0;
    
    do {
        scanf("%d", &numero);
        if(numero < minimo || numero > maximo)
        {
            printf("Fuera de rango (%d a %d): ", minimo, maximo);
        }
    }while(numero < minimo || numero > maximo);

    return numero;
}


//* FUNCION 3 BUSCAR LIBRO ACTIVOS -1 ES POR SI NO LO ENCUENTRA MISMO CODIGO DE CORRECION 2
int buscarCodigo(int codigos[], int estados[], int n, int codigo){
    int i;
    for (i = 0; i < n; i++) 
    {
        if (codigos[i] == codigo && estados[i] == 1) {
            return i;
        }
    }
    return -1;
}


//* FUNCION 4 GUARDA EL LIBRO EN LA PRIMERA POSICION LIBRE Y AUMENTA LA CANTIDAD
void incluir(int codigos[], char titulos[][MAX_TITULO], int disponibles[], int estados[], int *n){

    int codigo, pos;

    if (*n >= MAX_LIBROS)
    {
        printf("No hay espacio para mas libros.\n");
        return;
    }

    printf("Codigo nuevo: ");

    codigo = leerEntero(MIN_CODIGO, MAX_CODIGO);
    pos = buscarCodigo(codigos, estados, *n, codigo);

    if (pos != -1)
    {
        printf("El codigo %d ya existe.\n", codigo);
        return;
    }

    codigos[*n] = codigo;

    printf("Titulo (una palabra): ");
    scanf("%19s", titulos[*n]);
    limpiarBuffer();

    printf("Ejemplares (1 a 20): ");
    disponibles[*n] = leerEntero(MIN_EJEMPLARES, MAX_EJEMPLARES);
    estados[*n] = 1;
    (*n)++;

    printf("Libro incluido correctamente.\n");
    printf("Posiciones usadas: %d de %d\n", *n, MAX_LIBROS);
}

//* FUNCION 5 PARA MOSTRAR LOS LIBROS ACTIVOS CON CANTIDADES Y QUE SE VEAN EN COLUMNAS
void consultar(int codigos[], char titulos[][MAX_TITULO], int disponibles[], int estados[], int n){

    int i, activos = 0;

    printf("\n%-10s %-20s %-12s\n", "Codigo", "Titulo", "Disponibles");
    
    for (i = 0; i < n; i++)
    {
        if (estados[i] == 1) {
            printf("%-10d %-20s %-12d\n", codigos[i], titulos[i], disponibles[i]);
            activos++;
        }
    }
    printf("Libros activos: %d\n", activos);
}

//* FUNCION 6 DAR DE BAJA RESTA UN EJEMPLAR DISPONIBLE Y DEVUELVE 1 SI LO HACE Y 0 SI NO LO HACE
int prestar(int *disponibles){
    if (*disponibles > 0) {
        (*disponibles)--;
        return 1;
    }
    return 0;
}

//* FUNCION 7 DAR DE BAJA PONE EL ESTADO DEL LIBRO EN 0.
void darDeBaja(int *estado){
    *estado = 0;
}

