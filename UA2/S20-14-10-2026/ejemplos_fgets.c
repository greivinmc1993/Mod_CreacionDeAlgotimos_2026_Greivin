/*

    Ingresar datos personales

*Leer nombres completos, apellidos, direcciones o correos electrónicos.



*Leer frases y mensajes
*Recibir texto que contiene espacios sin detenerse en la primera palabra.



*Controlar la cantidad de entrada
*Limitar cuántos bytes se guardan en un arreglo y ayudar a evitar desbordamientos de memoria.



*Leer archivos de texto
*Procesar un archivo línea por línea cuando se usa con un flujo de archivo en lugar de stdin.



    TEMA: La funcion fgets() en lenguaje C

    fgets() permite leer una linea de texto y guardarla en un arreglo de char.
    Es especialmente util para leer nombres completos y frases que contienen espacios.

    Sintaxis:
        fgets(arreglo, capacidad, stdin);

    - arreglo: donde se guardara el texto.
    - capacidad: cantidad maxima de bytes que se pueden guardar, incluyendo '\0'.
    - stdin: indica que se lee desde la entrada estandar (normalmente el teclado).

    Si hay espacio, fgets() conserva el salto de linea '\n' que se genera al pulsar
    Enter. Siempre agrega el terminador '\0' cuando logra leer texto.
    Si no puede leer datos, devuelve NULL.

    Este archivo contiene un menu para ejecutar varios ejemplos.


    *fgets(arreglo, capacidad, stdin);


    Cada argumento tiene una función:
    
    *Argumento	    ¿Qué significa?

    *arreglo	    Variable donde se guardará el texto.
    *capacidad	    Cantidad máxima de caracteres que puede almacenar el arreglo, contando el espacio reservado para '\0'.
    *stdin	        Indica que los datos se leen de la entrada estándar, normalmente el teclado.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Quita el salto de linea final, si existe. */
void quitar_salto_linea(char texto[])
{
    texto[strcspn(texto, "\n")] = '\0';
}

/* EJEMPLO 1: leer un nombre completo (incluye espacios). */
void ejemplo1_nombre_completo(void)
{
    char nombre[100];

    printf("\n--- EJEMPLO 1: Nombre completo ---\n");
    printf("Escribe tu nombre completo: ");

    if (fgets(nombre, sizeof(nombre), stdin) != NULL)
    {
        quitar_salto_linea(nombre);
        printf("Hola, %s.\n", nombre);
    }
    else
    {
        printf("No se pudo leer la entrada.\n");
    }
}

/* EJEMPLO 2: leer una frase y calcular su longitud. */
void ejemplo2_longitud_frase(void)
{
    char frase[200];
    size_t longitud;

    printf("\n--- EJEMPLO 2: Longitud de una frase ---\n");
    printf("Escribe una frase: ");

    if (fgets(frase, sizeof(frase), stdin) != NULL)
    {
        quitar_salto_linea(frase);
        longitud = strlen(frase);
        printf("Tu frase es: %s\n", frase);
        printf("Tiene %zu caracteres (incluyendo espacios).\n", longitud);
    }
    else
    {
        printf("No se pudo leer la entrada.\n");
    }
}

/* EJEMPLO 3: contar vocales en una frase. */
void ejemplo3_contar_vocales(void)
{
    char frase[200];
    int vocales = 0;
    size_t i;

    printf("\n--- EJEMPLO 3: Contar vocales ---\n");
    printf("Escribe una frase: ");

    if (fgets(frase, sizeof(frase), stdin) != NULL)
    {
        for (i = 0; frase[i] != '\0'; i++)
        {
            int letra = tolower((unsigned char)frase[i]);
            if (letra == 'a' || letra == 'e' || letra == 'i' ||
                letra == 'o' || letra == 'u')
            {
                vocales++;
            }
        }

        printf("La frase contiene %d vocales (sin contar tildes como vocales separadas).\n",
               vocales);
    }
    else
    {
        printf("No se pudo leer la entrada.\n");
    }
}

/* EJEMPLO 4: leer varias lineas hasta que la persona escriba "fin". */
void ejemplo4_varias_lineas(void)
{
    char linea[150];

    printf("\n--- EJEMPLO 4: Leer varias lineas ---\n");
    printf("Escribe varias lineas. Para terminar, escribe fin y pulsa Enter.\n");

    while (fgets(linea, sizeof(linea), stdin) != NULL)
    {
        quitar_salto_linea(linea);

        if (strcmp(linea, "fin") == 0)
        {
            break;
        }

        printf("Leiste: %s\n", linea);
    }

    printf("Fin del ejemplo.\n");
}

/* EJEMPLO 5: mostrar que el tamano del arreglo limita la lectura. */
void ejemplo5_limite_buffer(void)
{
    char texto[12]; /* Puede guardar como maximo 11 caracteres mas '\0'. */

    printf("\n--- EJEMPLO 5: Limite de lectura ---\n");
    printf("Escribe un texto (el arreglo solo guarda hasta 11 caracteres): ");

    if (fgets(texto, sizeof(texto), stdin) != NULL)
    {
        printf("Contenido guardado: [%s]\n", texto);
        printf("El arreglo tiene capacidad para 12 bytes; uno se reserva para '\\0'.\n");
        if (strchr(texto, '\n') == NULL)
        {
            printf("Aviso: no se encontro '\\n'. La linea podria ser mas larga que el espacio disponible.\n");
            printf("Si queda texto pendiente en la entrada, una siguiente lectura podria recibirlo.\n");
        }
        else
        {
            printf("La linea completa cupo en el arreglo.\n");
        }
    }
    else
    {
        printf("No se pudo leer la entrada.\n");
    }
}

int main(void)
{
    char opcion[20];
    int seleccion;

    do
    {
        printf("\n=====================================\n");
        printf("       EJEMPLOS DE fgets() EN C\n");
        printf("=====================================\n");
        printf("1. Leer un nombre completo\n");
        printf("2. Leer una frase y contar caracteres\n");
        printf("3. Contar vocales en una frase\n");
        printf("4. Leer varias lineas hasta escribir fin\n");
        printf("5. Ver el limite del arreglo\n");
        printf("0. Salir\n");
        printf("Selecciona un ejemplo: ");

        if (fgets(opcion, sizeof(opcion), stdin) == NULL)
        {
            break;
        }

        seleccion = atoi(opcion);

        switch (seleccion)
        {
            case 1:
                ejemplo1_nombre_completo();
                break;
            case 2:
                ejemplo2_longitud_frase();
                break;
            case 3:
                ejemplo3_contar_vocales();
                break;
            case 4:
                ejemplo4_varias_lineas();
                break;
            case 5:
                ejemplo5_limite_buffer();
                break;
            case 0:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opcion no valida. Elige un numero del menu.\n");
        }
    } while (seleccion != 0);

    return 0;
}
