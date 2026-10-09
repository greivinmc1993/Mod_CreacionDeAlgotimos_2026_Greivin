#include <stdio.h>
// Definición de una función llamada 'imprimirMensaje'.
// 'void' indica que esta función realiza una acción pero no regresa ningún valor de tipo numérico  o texto.
void imprimirMensaje() {
 // printf es una función del sistema que imprime en la consola el texto que está entre comillas.
 // El símbolo '\n' genera un salto de línea (un "Enter") en la salida de texto.
printf("Hola, este es un programa estructurado en C.\n");
} // Este cierre de llave indica que aquí termina el bloque de código de la función 'imprimirMensaje'.

// Definición de una función llamada 'sumar'.
// El primer 'int' indica que la función va a devolver un número entero como resultado.
// Instituto Nacional de Aprendizaje CSTI12010 Diseño de algoritmos
// Núcleo Comercio y Servicios · Subsector Informática y Comunicación Sesión 14 · Conceptos del día
// Persona facilitadora: Giovanni Antonio Coto Calderón
// '(int a, int b)' son los parámetros: la función recibe dos números enteros para trabajar con ellos.
int sumar(int a, int b) {
 // 'return' toma el resultado de la operación (a + b) y lo envía de vuelta a quien invocó la función.
return a + b;
} // Cierre del bloque de la función 'sumar'.
// La función 'main' (principal) es el punto de inicio obligatorio de cualquier programa en C.
// El sistema operativo siempre busca esta función para comenzar a ejecutar las instrucciones.
int main() {
 // Se declaran dos variables de tipo entero ('int') llamadas 'x' e 'y'.
 // Al mismo tiempo se les asignan sus valores iniciales: 5 a la 'x' y 10 a la 'y'.
int x = 5, y = 10;

 // Se declara una variable entera llamada 'resultado'. Esta servirá para guardar el éxito de la suma más adelante.
int resultado;
 // Se invoca (llama) a la función 'imprimirMensaje'. El programa salta a esa función,
 // ejecuta su printf en pantalla y luego regresa aquí para continuar con la siguiente línea.
imprimirMensaje(); // Llamada a función
 // Se llama a la función 'sumar' pasando los valores de 'x' (5) e 'y' (10) como argumentos.
 // El valor devuelto por la función (15) se almacena dentro de la variable 'resultado' mediante el signo '='.
 resultado = sumar(x, y); // Llamada a función
 // printf imprime el texto formateado. Cada '%d' es un marcador de posición para números enteros.
 // Los valores de 'x', 'y' y 'resultado' se acomodan en orden en cada uno de los '%d'.
//Instituto Nacional de Aprendizaje CSTI12010 Diseño de algoritmos
//Núcleo Comercio y Servicios · Subsector Informática y Comunicación Sesión 14 · Conceptos del día
//Persona facilitadora: Giovanni Antonio Coto Calderón
printf("La suma de %d y %d es: %d\n", x, y, resultado);
 // 'return 0' le avisa al sistema operativo que el programa finalizó correctamente y sin errores.
return 0;
} // Cierre del bloque de la función 'main' y fin del programa.