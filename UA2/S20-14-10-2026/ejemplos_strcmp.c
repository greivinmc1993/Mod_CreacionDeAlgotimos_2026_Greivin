/*
    EJEMPLOS DE strcmp() EN LENGUAJE C
    ----------------------------------
    La funcion strcmp() compara dos cadenas de caracteres.
    Se declara en la biblioteca <string.h>.

    Valores de retorno:
    - Un valor menor que 0: la primera cadena aparece antes que la segunda.
    - 0: las dos cadenas son iguales.
    - Un valor mayor que 0: la primera cadena aparece despues que la segunda.

    Importante: no se debe asumir que devuelve exactamente -1 o 1.
    La comparacion distingue entre mayusculas y minusculas.



    Resultado	    Significado
    0	            Ambas cadenas son iguales.
    Menor que 0	    La primera cadena precede a la segunda en la comparación.
    Mayor que 0	    La primera cadena sigue a la segunda en la comparación.

    Importante: strcmp() no necesariamente devuelve exactamente -1, 0 o 1. Por eso se recomienda comprobar si el resultado es menor que cero, igual a cero o mayor que cero.    




    *Comprobar si dos textos son iguales

*Verificar que dos nombres, palabras o cadenas coinciden exactamente.

*Crear menús interactivos
*Comprobar si el usuario escribió "guardar", "salir" o alguna otra opción textual.

*Buscar palabras o nombres
*Comparar una cadena introducida con un nombre previamente almacenado.

*Ordenar cadenas
*Utilizar el signo del resultado para establecer un orden entre nombres o palabras.
*/

#include <stdio.h>
#include <string.h>

/* Elimina el salto de linea que fgets() puede guardar al final. */
void quitarSaltoLinea(char texto[])
{
    texto[strcspn(texto, "\n")] = '\0';
}

void ejemplo1(void)
{
    /* Ejemplo 1: comparar dos cadenas iguales. */
    char palabra1[] = "gato";
    char palabra2[] = "gato";
    int resultado = strcmp(palabra1, palabra2);

    printf("\n--- Ejemplo 1: cadenas iguales ---\n");
    printf("Palabra 1: %s\n", palabra1);
    printf("Palabra 2: %s\n", palabra2);

    if (resultado == 0)
        printf("Las dos palabras son iguales.\n");
    else
        printf("Las palabras son diferentes.\n");
}

void ejemplo2(void)
{
    /* Ejemplo 2: comparar dos cadenas diferentes. */
    char palabra1[] = "perro";
    char palabra2[] = "gato";

    printf("\n--- Ejemplo 2: cadenas diferentes ---\n");
    printf("Palabra 1: %s\n", palabra1);
    printf("Palabra 2: %s\n", palabra2);

    if (strcmp(palabra1, palabra2) == 0)
        printf("Las palabras son iguales.\n");
    else
        printf("Las palabras son diferentes.\n");
}

void ejemplo3(void)
{
    /* Ejemplo 3: interpretar si el resultado es negativo o positivo. */
    char palabra1[] = "abeja";
    char palabra2[] = "barco";
    int resultado = strcmp(palabra1, palabra2);

    printf("\n--- Ejemplo 3: orden de las cadenas ---\n");
    printf("Primera palabra: %s\n", palabra1);
    printf("Segunda palabra: %s\n", palabra2);

    if (resultado < 0)
        printf("La primera cadena se ordena antes que la segunda.\n");
    else if (resultado > 0)
        printf("La primera cadena se ordena despues que la segunda.\n");
    else
        printf("Las dos cadenas son iguales.\n");

    /* No asumas que strcmp() devuelve exactamente -1 o 1. */
}

void ejemplo4(void)
{
    /* Ejemplo 4: la comparacion distingue mayusculas y minusculas. */
    char palabra1[] = "Hola";
    char palabra2[] = "hola";

    printf("\n--- Ejemplo 4: mayusculas y minusculas ---\n");
    printf("Palabra 1: %s\n", palabra1);
    printf("Palabra 2: %s\n", palabra2);

    if (strcmp(palabra1, palabra2) == 0)
        printf("Las cadenas son iguales.\n");
    else
        printf("Las cadenas son diferentes porque cambia la mayuscula/minuscula.\n");
}

void ejemplo5(void)
{
    /* Ejemplo 5: leer dos textos y compararlos. */
    char texto1[100];
    char texto2[100];

    printf("\n--- Ejemplo 5: comparar textos ingresados ---\n");
    printf("Escribe el primer texto: ");

    if (fgets(texto1, sizeof texto1, stdin) == NULL)
    {
        printf("No se pudo leer el primer texto.\n");
        return;
    }
    quitarSaltoLinea(texto1);

    printf("Escribe el segundo texto: ");
    if (fgets(texto2, sizeof texto2, stdin) == NULL)
    {
        printf("No se pudo leer el segundo texto.\n");
        return;
    }
    quitarSaltoLinea(texto2);

    if (strcmp(texto1, texto2) == 0)
        printf("Los textos son exactamente iguales.\n");
    else
        printf("Los textos son diferentes.\n");

    printf("Primer texto:  [%s]\n", texto1);
    printf("Segundo texto: [%s]\n", texto2);
}

int main(void)
{
    int opcion;

    do
    {
        printf("\n========================================\n");
        printf("       PRACTICA DE strcmp() EN C\n");
        printf("========================================\n");
        printf("1. Comparar cadenas iguales\n");
        printf("2. Comparar cadenas diferentes\n");
        printf("3. Interpretar el orden de las cadenas\n");
        printf("4. Comparar mayusculas y minusculas\n");
        printf("5. Ingresar y comparar dos textos\n");
        printf("0. Salir\n");
        printf("Elige un ejemplo: ");

        if (scanf("%d", &opcion) != 1)
        {
            printf("Entrada no valida. Ejecuta el programa de nuevo e ingresa un numero.\n");
            return 1;
        }

        /* Consumir el resto de la linea para que fgets() lea el texto despues. */
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
                /* Descartar caracteres sobrantes de la linea del menu. */
            }
        }

        switch (opcion)
        {
            case 1: ejemplo1(); break;
            case 2: ejemplo2(); break;
            case 3: ejemplo3(); break;
            case 4: ejemplo4(); break;
            case 5: ejemplo5(); break;
            case 0: printf("Programa finalizado.\n"); break;
            default: printf("Opcion no valida. Selecciona un numero del 0 al 5.\n");
        }

    } while (opcion != 0);

    return 0;
}
