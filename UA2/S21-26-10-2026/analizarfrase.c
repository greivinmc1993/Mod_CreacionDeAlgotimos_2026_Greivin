
#include <stdio.h>
#include <ctype.h>

/*
    Ejercicio 3: Analizar una frase

    Objetivo:
    Leer una frase, mostrarla en mayusculas y contar
    las vocales, consonantes y digitos.

    Como se logra:
    1. getchar() lee un caracter a la vez.
    2. putchar() muestra cada caracter.
    3. toupper() convierte las letras a mayusculas.
    4. isalpha() identifica las letras.
    5. isdigit() identifica los digitos.
    6. esVocal() determina si una letra es vocal.
*/

/* PROTOTIPO */
int esVocal(int c);

int main(void)
{
    int caracter;
    int vocales = 0;
    int consonantes = 0;
    int digitos = 0;

    printf("Frase: ");

    /* Leer y analizar cada caracter */
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
        /* Mostrar el caracter en mayusculas */
        putchar(toupper(caracter));

        /* Contar las letras */
        if (isalpha(caracter))
        {
            if (esVocal(caracter) == 1)
            {
                vocales++;
            }
            else
            {
                consonantes++;
            }
        }

        /* Contar los digitos */
        if (isdigit(caracter))
        {
            digitos++;
        }
    }

    /* Mostrar los resultados */
    printf("\n\nVocales: %d\n", vocales);
    printf("Consonantes: %d\n", consonantes);
    printf("Digitos: %d\n", digitos);

    return 0;
}

/* FUNCION: determinar si un caracter es vocal */
int esVocal(int c)
{
    c = tolower(c);

    if (c == 'a' || c == 'e' || c == 'i' ||
        c == 'o' || c == 'u')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
