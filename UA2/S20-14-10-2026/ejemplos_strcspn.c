/*
    EJEMPLOS DE strcspn() EN LENGUAJE C
    -----------------------------------
    strcspn() pertenece a <string.h>.
    Devuelve cuántos caracteres iniciales de la primera cadena aparecen
    antes de encontrar cualquier carácter que esté en la segunda cadena.

    Sintaxis:
        size_t cantidad = strcspn(cadena, caracteres_a_buscar);

    Nota: no busca una palabra completa. La segunda cadena es un conjunto
    de caracteres individuales que se buscan en la primera cadena.


    *strcspn(cadena, caracteres_a_buscar);


*Esta función devuelve la cantidad de caracteres iniciales de cadena que no contienen ninguno de los caracteres indicados en caracteres_a_buscar.

Veamos qué significa cada argumento:
Argumento	            Función
cadena	                Texto en el que queremos buscar.
caracteres_a_buscar	    Conjunto de caracteres que queremos detectar.


Resultado	            Número de caracteres anteriores a la primera coincidencia.



Importante: el segundo argumento no tiene que ser una palabra completa. Cada uno de sus caracteres se considera una posibilidad de coincidencia.
*/

#include <stdio.h>
#include <string.h>

void ejemplo1(void)
{
    char texto[] = "Hola,mundo";
    size_t posicion = strcspn(texto, ",");

    printf("\nEJEMPLO 1: Encontrar una coma\n");
    printf("Texto: %s\n", texto);
    printf("strcspn(texto, \",\") devuelve: %zu\n", posicion);
    printf("La coma aparece en el indice %zu (contando desde 0).\n", posicion);
}

void ejemplo2(void)
{
    char texto[] = "Hola mundo\n";

    printf("\nEJEMPLO 2: Quitar el salto de linea de fgets()\n");
    printf("Antes de limpiar, la cadena puede contener \\n al final.\n");

    /*
        strcspn(texto, "\n") devuelve el indice del salto de linea,
        si existe. Reemplazar ese caracter por '\0' lo elimina.
        Si no hay '\n', devuelve la longitud de la cadena y escribir '\0'
        en ese indice deja la cadena tal como estaba.
    */
    texto[strcspn(texto, "\n")] = '\0';

    printf("Despues de limpiar: [%s]\n", texto);
}

void ejemplo3(void)
{
    char texto[] = "uno;dos,tres cuatro";
    size_t posicion = strcspn(texto, ";, ");

    printf("\nEJEMPLO 3: Encontrar el primer separador\n");
    printf("Texto: %s\n", texto);
    printf("Caracteres de separacion: punto y coma, coma o espacio.\n");
    printf("La primera palabra tiene %zu caracteres.\n", posicion);
    printf("Primera palabra: %.*s\n", (int)posicion, texto);
}

void ejemplo4(void)
{
    char usuario[] = "ana maria";
    size_t posicion = strcspn(usuario, " \t\n");

    printf("\nEJEMPLO 4: Detectar espacios en un nombre de usuario\n");
    printf("Texto ingresado: [%s]\n", usuario);

    /* Busca cualquiera de estos caracteres: espacio, tabulador o salto de linea. */
    if (usuario[posicion] != '\0')
    {
        printf("Se encontro un espacio o caracter de separacion en el indice %zu.\n", posicion);
        printf("El texto contiene un caracter que podria no permitirse en un usuario.\n");
    }
    else
    {
        printf("No se encontraron espacios ni tabuladores.\n");
    }
}

void ejemplo5(void)
{
    char texto[] = "Programacion";
    size_t posicion = strcspn(texto, "xyz");

    printf("\nEJEMPLO 5: Cuando no se encuentra ningun caracter buscado\n");
    printf("Texto: %s\n", texto);
    printf("Caracteres que buscamos: x, y o z\n");
    printf("strcspn devuelve %zu, la longitud completa de la cadena.\n", posicion);
}

int main(void)
{
    int opcion;

    do
    {
        printf("\n=====================================\n");
        printf("       PRACTICA DE strcspn()\n");
        printf("=====================================\n");
        printf("1. Encontrar una coma\n");
        printf("2. Quitar el salto de linea\n");
        printf("3. Encontrar el primer separador\n");
        printf("4. Detectar espacios en un usuario\n");
        printf("5. No se encuentra el caracter buscado\n");
        printf("0. Salir\n");
        printf("Elige un ejemplo: ");

        if (scanf("%d", &opcion) != 1)
        {
            printf("Entrada no valida. Ejecuta el programa de nuevo e introduce un numero.\n");
            return 1;
        }

        switch (opcion)
        {
            case 1: ejemplo1(); break;
            case 2: ejemplo2(); break;
            case 3: ejemplo3(); break;
            case 4: ejemplo4(); break;
            case 5: ejemplo5(); break;
            case 0: printf("Fin de la practica.\n"); break;
            default: printf("Opcion no valida. Selecciona del 0 al 5.\n");
        }
    } while (opcion != 0);

    return 0;
}
