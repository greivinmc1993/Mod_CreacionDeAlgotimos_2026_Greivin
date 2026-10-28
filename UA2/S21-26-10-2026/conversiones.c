
#include <stdio.h>

/*
    Ejercicio 1: Biblioteca de conversiones

    Objetivo:
    Crear cuatro funciones para realizar conversiones
    y validaciones, y probarlas desde main().

    Funciones:
    1. Convertir Celsius a Fahrenheit.
    2. Convertir colones a dolares.
    3. Determinar si un anio es bisiesto.
    4. Validar una nota de 0 a 100.
*/

//! PROTOTIPOS
double celsiusAFahrenheit(double c);
double colonesADolares(double c);
int esBisiesto(int anio);
int esNotaValida(double nota);

int main(void)
{
    printf("BIBLIOTECA DE CONVERSIONES\n\n");

    /* Prueba 1: Celsius a Fahrenheit */
    printf("25 C = %.1f F (esperado 77.0)\n",
        celsiusAFahrenheit(25));

    /* Prueba 2: Colones a dolares */
    printf("5100 colones = %.2f dolares (esperado 10.00)\n",
        colonesADolares(5100));

    /* Prueba 3: Anio bisiesto */
    printf("2024 bisiesto: %d (esperado 1)\n",
        esBisiesto(2024));

    printf("1900 bisiesto: %d (esperado 0)\n",
        esBisiesto(1900));

    /* Prueba 4: Validar notas */
    printf("Nota 105 valida: %d (esperado 0)\n",
        esNotaValida(105));

    printf("Nota 85 valida: %d (esperado 1)\n",
        esNotaValida(85));

    return 0;
}

//! FUNCION 1: Celsius a Fahrenheit 
double celsiusAFahrenheit(double c)
{
    double fahrenheit;

    fahrenheit = c * 9.0 / 5.0 + 32.0;

    return fahrenheit;
}

//! FUNCION 2: Colones a dolares
double colonesADolares(double c)
{
    double dolares;

    dolares = c / 510.0;

    return dolares;
}

//! FUNCION 3: Determinar si un anio es bisiesto 
int esBisiesto(int anio)
{
    if (anio % 400 == 0)
    {
        return 1;
    }

    if (anio % 100 == 0)
    {
        return 0;
    }

    if (anio % 4 == 0)
    {
        return 1;
    }

    return 0;
}

//! FUNCION 4: Validar una nota
int esNotaValida(double nota)
{
    if (nota >= 0 && nota <= 100)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
