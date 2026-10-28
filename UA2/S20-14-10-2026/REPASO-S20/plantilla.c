/* temperaturas.c -  Temperaturas de la semana
==========================================================================
* ENUNCIADO:
    Solicitar temperatura maxima del dia, mostrar el nombre del dia: lunes a domingo.(0-45°C)
    Si esta fuera de rango vuelve a pedir el valor.
    Guardarlas en un arreglo de 7 posiciones.
    Calcular el promedio de la semana

* QUÉ SE LOGRA:
    Encontrar el dia más caluroso.
    El promedio.

* CÓMO SE LOGRA:
    -do-while para validar el rango de temperatura aceptada
    -Arreglo para guardar temperaturas
    -for para sacar al mas caluros
    -for para recorrer los dias

* RESULTADO ESPERADO:
    Muestra la temperatura de cada dia.
    El promedio de temperatura (float: dos decimales)
    El dia mas caluroso
    La lista de dias que superaron el promedio con su cantidad
========================================================================== */

//! LIBRERIAS VISTAS
#include <stdio.h>      //! TEXTOS PRINTF, SCANF
//!------------FUNCIONES DE VALIDACION DE STDIO.H----------------
/* 
printf()
scanf()
getchar()       LEE UN UNICO CARACTER DESDE LA ENTRADA ESTANDAR
putchar()       ESCRIBE UN UNICO CARACTER EN LA SALIDA ESTANDAR
fgets(ARREGLO, sizeof(ARREGLO), stdin);----> JUSTO DEESPUES----> ARREGLO[strcspn(ARREGLO, "\n")] = '\0'; 
puts()      INGRESA TEXTO SIN VARIABLES Y PONE UN SALTO DE LINEA
*/

#include <string.h>     //! STRING
//!------------FUNCIONES DE VALIDACION DE STRING.H----------------
/* 
strcpy(destino, "A GUARDAR");
strcat(destino, "SE GUARDA AL FINAL");
strlen(ARREGLO);          MUESTRA TAMAÑO DE ARREGLO
strcmp("DONDE SE BUSCA", "QUÉ SE BUSCA") == 0;  DA 0 SI ES VERDADERO 
*/

#include <ctype.h>      //! PARA VALIDAR CARACTERES Y CONVERSIONES
//!------------FUNCIONES DE VALIDACION DE CTYPE.H----------------
/*
isalpha(variable);
islower(variable);
isupper(variable);
isdigit(variable);
isxdigit(variable);
isalnum(variable); 

DEVUELVEN 1 PARA VERDADERO 0 PARA FALSO
*/

#include <math.h>       //! PARA VALIDAR CARACTERES Y CONVERSIONES
//!------------FUNCIONES DE VALIDACION DE MATH.H----------------
/* 
fabs(VARIABLE);     -7.5 -->  7.5  DA EL VALOR ABSOLUTO
ceil(VARIABLE);     REDONDEA AL ENTERO SUPERIOR
pow(BASE, POTENCIA);PARA HACER POTENCIAS
floor(VARIABLE);    REDONDEA AL ENTERO INFERIOR
sqrt(VARIABLE);     PARA RAICES CUADRADAS
round(VARIABLE);    REDONDEA AL ENTERO MÁS CERCANO 
*/      

//!------------FUNCION PARA LIMPIAR BUFER O BASURA----------------
//! CREAR PROTOTIPOS AL COMIENZO Y LAS FUNCIONES AL FINAL
void limpiarBuffer(void)
{
    int caracter;

    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
    }
}