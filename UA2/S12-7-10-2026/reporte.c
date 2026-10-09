/* 
    Preprocesador | Inserta los #include y quita comentarios. | gcc -E hola.c -o hola.i -> hola.i
    Compilador    | Traduce a lenguaje ensamblador.           | gcc -S hola.c -> hola.s 
    Ensamblador   | Genera código máquina.                    | gcc -c hola.c -> hola.o 
    Enlazador     | Une con las bibliotecas.                  | gcc hola.o -o hola -> hola.exe 

    gcc -Wall hola.c -o hola -> hola.exe con advertencias 
*/



// reporte.c - Programa con errores 
#include <stdio.h> 
    
    int main(void) { 
    printf("Reporte de ventas\n");
    Printf("Total: 25000\n"); 
    printf("Gracias por su compra\n"); 
    return 0; 

    }



    /* 
    N.° | Línea | Mensaje de gcc (resumido) | Corrección 
    1   |  4    | Int MAL ESCRITO           | SE CORRIGE LA MAYUSCULA
    2   |  5    | NO TIENE EL ;             | SE AGREGA EL ;      
    3   |  7    | NO TIENE LA "             | SE AGREGA LA "
    4   |  10   | FALTA EL CIERRE DEL MAIN  | SE AGREGA }
    5   |       |                           | 
    */
