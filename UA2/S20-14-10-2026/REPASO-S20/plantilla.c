/* NOMBRE.c -  TITULO
==========================================================================
* ENUNCIADO:
    DESCRIBA ENUNCIADO

* QUÉ SE LOGRA:
    PONGA QUE SE LOGRA DE FORMA PUNTUAL

* CÓMO SE LOGRA:
    PONGA COMO SE LOGRA DE FORMA PUNTUAL

* RESULTADO ESPERADO:
    PONGA RESULTADO ESPERADO DE FORMA PUNTUAL
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