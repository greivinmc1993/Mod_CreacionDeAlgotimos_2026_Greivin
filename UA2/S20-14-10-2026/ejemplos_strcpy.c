/*

*Duplicar cadenas
*Crear una copia de un texto sin modificar el arreglo original.

*Trabajar con datos de texto
*Copiar nombres, apellidos, etiquetas y otras cadenas entre arreglos.

*Almacenar información
*Guardar una cadena en otro arreglo para procesarla o utilizarla en una parte distinta del programa.

*Manipular cadenas
*Preparar una copia que después pueda modificarse, compararse o procesarse.



    FUNCION strcpy() EN LENGUAJE C
    --------------------------------
    strcpy() copia una cadena de caracteres desde un origen hasta un destino.
    Se declara en la biblioteca <string.h>.

    IMPORTANTE:
    El arreglo destino debe tener espacio suficiente para todos los caracteres
    de la cadena de origen, incluido el terminador '\0'. strcpy() NO comprueba
    el tamaño del destino. Si no cabe, puede producir un comportamiento indefinido.


    *strcpy(destino, origen);


    *Elemento	    Función
    *destino	    Arreglo donde se guardará la copia.
    *origen	        Cadena de caracteres que queremos copiar.

    Importante: el arreglo de destino debe tener suficiente espacio para todos los caracteres de la cadena, incluido el carácter especial '\0', que marca el final del texto.



    Duplicar cadenas

*Crear una copia de un texto sin modificar el arreglo original.

*Trabajar con datos de texto
*Copiar nombres, apellidos, etiquetas y otras cadenas entre arreglos.

*Almacenar información
*Guardar una cadena en otro arreglo para procesarla o utilizarla en una parte distinta del programa.

*Manipular cadenas
*Preparar una copia que después pueda modificarse, compararse o procesarse.
*/

#include <stdio.h>
#include <string.h>

/* Ejemplo 1: copiar una cadena literal a un arreglo. */
void ejemplo1(void)
{
    char saludo[30];

    strcpy(saludo, "Hola, mundo");

    printf("Ejemplo 1 - Copiar una cadena\n");
    printf("Texto copiado: %s\n\n", saludo);
}

/* Ejemplo 2: copiar el contenido de un arreglo a otro. */
void ejemplo2(void)
{
    char original[] = "Estoy aprendiendo C";
    char copia[40];

    strcpy(copia, original);

    printf("Ejemplo 2 - Copiar entre arreglos\n");
    printf("Original: %s\n", original);
    printf("Copia:    %s\n\n", copia);
}

/* Ejemplo 3: cambiar la copia sin modificar la cadena original. */
void ejemplo3(void)
{
    char original[] = "Programacion";
    char copia[30];

    strcpy(copia, original);
    copia[0] = 'p';  /* Cambiamos la primera letra de la copia. */

    printf("Ejemplo 3 - La copia es independiente\n");
    printf("Original: %s\n", original);
    printf("Copia modificada: %s\n\n", copia);
}

/* Ejemplo 4: guardar el nombre de una opcion en otro arreglo. */
void ejemplo4(void)
{
    char opcion[20];

    /* El destino tiene capacidad suficiente para "Guardar" y '\0'. */
    strcpy(opcion, "Guardar");

    printf("Ejemplo 4 - Guardar texto para usarlo despues\n");
    printf("Opcion seleccionada: %s\n\n", opcion);
}

/* Ejemplo 5: copiar texto leido con fgets().
   Se elimina primero el salto de linea, si se leyó, y luego se copia.
   El arreglo destino es suficientemente grande para el texto permitido. */
void ejemplo5(void)
{
    char entrada[50];
    char copia[50];

    printf("Ejemplo 5 - Leer una frase y copiarla\n");
    printf("Escribe una frase (maximo 49 bytes): ");

    if (fgets(entrada, sizeof entrada, stdin) == NULL) {
        printf("No se pudo leer la entrada.\n\n");
        return;
    }

    entrada[strcspn(entrada, "\n")] = '\0';

    /* entrada tiene como máximo 49 bytes de contenido; copia tiene 50. */
    strcpy(copia, entrada);

    printf("Texto original: %s\n", entrada);
    printf("Texto copiado:  %s\n\n", copia);
}

int main(void)
{
    int opcion;

    do {
        printf("=====================================\n");
        printf(" PRACTICA DE LA FUNCION strcpy()\n");
        printf("=====================================\n");
        printf("1. Copiar una cadena literal\n");
        printf("2. Copiar entre arreglos\n");
        printf("3. Modificar solamente la copia\n");
        printf("4. Guardar el texto de una opcion\n");
        printf("5. Leer una frase y copiarla\n");
        printf("0. Salir\n");
        printf("Elige un ejemplo: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada no valida. Ejecuta el programa de nuevo e ingresa un numero.\n");
            return 1;
        }

        /* Consumir el resto de la linea para que fgets() funcione en el ejemplo 5. */
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            /* Descartar caracteres sobrantes. */
        }

        printf("\n");
        switch (opcion) {
            case 1: ejemplo1(); break;
            case 2: ejemplo2(); break;
            case 3: ejemplo3(); break;
            case 4: ejemplo4(); break;
            case 5: ejemplo5(); break;
            case 0: printf("Practica finalizada.\n"); break;
            default: printf("Opcion no valida. Intenta de nuevo.\n\n");
        }
    } while (opcion != 0);

    return 0;
}
