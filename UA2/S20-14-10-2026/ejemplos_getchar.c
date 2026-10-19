/*
    Leer caracteres

*Obtener una letra, un número o un símbolo introducido por el usuario.

*Elegir opciones de un menú
*Por ejemplo, leer A, B o C para seleccionar una operación.

*Confirmar decisiones
*Preguntar si deseas continuar, usando S para sí y N para no.

*Validar entradas
*Comprobar si un carácter es una letra, un dígito u otro símbolo.

*Limpiar el búfer de entrada
*Consumir caracteres sobrantes, como el salto de línea \n, que puede quedar después de leer una entrada.

    ARCHIVO: ejemplos_getchar.c
    TEMA: Leer caracteres con getchar() en lenguaje C.

    ¿QUE HACE getchar()?
    --------------------
    getchar() lee un solo caracter de la entrada estandar (normalmente, el
    teclado) y lo devuelve como un int. Aunque se usa para leer caracteres,
    devuelve int para que tambien pueda representar EOF, que indica que no
    hay mas datos disponibles o que ocurrio un fin de entrada.

    IMPORTANTE:
    - En una consola normal, habitualmente debes escribir el caracter y pulsar
      ENTER para que getchar() reciba la entrada.
    - getchar() lee solamente el primer caracter disponible.
    - Los caracteres restantes (incluido ENTER, representado por '\n') pueden
      quedarse en la entrada. La funcion limpiarEntrada() de este ejemplo ayuda
      a descartar los caracteres sobrantes de una linea.
    - system("pause") se incluye para que la consola no se cierre enseguida en
      Windows. Es una orden propia de Windows y no es parte de getchar().
*/

#include <stdio.h>   // printf(), getchar()
#include <stdlib.h>  // system()
#include <ctype.h>   // isalpha(), isupper(), islower(), isdigit(), tolower()

/*
    Descarta lo que quede de la linea actual hasta encontrar ENTER ('\\n')
    o el fin de entrada (EOF).

    ¿Por que se necesita?
    Si escribimos A y pulsamos ENTER, la entrada normalmente contiene 'A' y
    despues '\\n'. getchar() lee solo 'A'; esta funcion elimina el '\\n' para
    que no interfiera con la siguiente lectura.
*/
void limpiarEntrada(void)
{
    int caracter;

    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
        /* No hay que hacer nada dentro: solo consumimos los caracteres. */
    }
}

/* EJEMPLO 1: leer un caracter y mostrarlo. */
void ejemplo1(void)
{
    int caracter;

    printf("\n=== EJEMPLO 1: leer un caracter ===\n");
    printf("Escribe una letra, numero o simbolo y pulsa ENTER: ");

    /* getchar() obtiene un solo caracter de la entrada. */
    caracter = getchar();

    /* Limpiamos ENTER y cualquier otro caracter que quede en esa linea. */
    limpiarEntrada();

    if (caracter == EOF)
    {
        printf("No se pudo leer un caracter (fin de entrada).\n");
        return;
    }

    /* %c muestra el caracter; %d muestra su valor numerico. */
    printf("Caracter leido: '%c'\n", (char)caracter);
    printf("Valor numerico del caracter: %d\n", caracter);

    /*
        Ejemplo: si escribes A, se mostrara el caracter A y, normalmente en
        sistemas ASCII, su valor numerico sera 65.

        USO TIPICO: leer una letra, un simbolo o la primera letra de una
        respuesta sencilla.
    */
}

/* EJEMPLO 2: identificar que tipo de caracter se introdujo. */
void ejemplo2(void)
{
    int caracter;

    printf("\n=== EJEMPLO 2: identificar el caracter ===\n");
    printf("Escribe una letra, un digito o un simbolo y pulsa ENTER: ");

    caracter = getchar();
    limpiarEntrada();

    if (caracter == EOF)
    {
        printf("No se pudo leer el caracter.\n");
        return;
    }

    /*
        Las funciones de ctype.h ayudan a clasificar caracteres.
        Se convierte a unsigned char antes de llamar a estas funciones para
        evitar problemas con valores que no sean representables como char.
    */
    if (isalpha((unsigned char)caracter))
    {
        printf("'%c' es una letra.\n", (char)caracter);

        if (isupper((unsigned char)caracter))
        {
            printf("La letra esta en MAYUSCULA.\n");
        }
        else if (islower((unsigned char)caracter))
        {
            printf("La letra esta en minuscula.\n");
        }

        printf("En minuscula seria: '%c'\n",
               tolower((unsigned char)caracter));
    }
    else if (isdigit((unsigned char)caracter))
    {
        printf("'%c' es un digito numerico.\n", (char)caracter);
    }
    else
    {
        printf("'%c' es un simbolo, espacio u otro tipo de caracter.\n",
               (char)caracter);
    }

    /*
        USO TIPICO: validar una entrada sencilla, comprobar si se escribio
        una letra o un digito, o adaptar una letra a mayuscula/minuscula.
        Este ejemplo clasifica caracteres basicos; letras acentuadas pueden
        depender de la configuracion regional y la codificacion usadas.
    */
}

/* EJEMPLO 3: preguntar si el usuario desea continuar (S/N). */
void ejemplo3(void)
{
    int respuesta;

    printf("\n=== EJEMPLO 3: respuesta SI o NO ===\n");
    printf("Deseas continuar? Escribe S para SI o N para NO: ");

    respuesta = getchar();
    limpiarEntrada();

    /* Aceptamos S/s y N/n para que no importe el uso de mayusculas. */
    if (respuesta == 'S' || respuesta == 's')
    {
        printf("Elegiste SI. El programa podria continuar con la siguiente tarea.\n");
    }
    else if (respuesta == 'N' || respuesta == 'n')
    {
        printf("Elegiste NO. El programa podria cancelar o terminar la tarea.\n");
    }
    else if (respuesta == EOF)
    {
        printf("No se recibio ninguna respuesta.\n");
    }
    else
    {
        printf("Respuesta no valida: escribe S o N.\n");
    }

    /*
        USO TIPICO: confirmar una accion antes de ejecutarla, por ejemplo,
        preguntar si se desea repetir un calculo o confirmar una opcion.
        Para validar de verdad, se podria repetir la pregunta hasta recibir
        S o N; aqui se muestra la idea de forma sencilla.
    */
}

/* EJEMPLO 4: elegir una opcion mediante una sola tecla. */
void ejemplo4(void)
{
    int opcion;

    printf("\n=== EJEMPLO 4: elegir una opcion ===\n");
    printf("A) Mostrar un mensaje\n");
    printf("B) Mostrar otro mensaje\n");
    printf("Elige A o B y pulsa ENTER: ");

    opcion = getchar();
    limpiarEntrada();

    /* Aceptamos tanto mayusculas como minusculas. */
    switch (opcion)
    {
        case 'A':
        case 'a':
            printf("Elegiste la opcion A.\n");
            break;

        case 'B':
        case 'b':
            printf("Elegiste la opcion B.\n");
            break;

        case EOF:
            printf("No se recibio ninguna opcion.\n");
            break;

        default:
            printf("Opcion no valida. Debes escribir A o B.\n");
            break;
    }

    /*
        USO TIPICO: leer opciones de menus pequenos donde basta con una letra
        o un caracter. Para menus mas complejos puede convenir fgets() y luego
        validar la linea completa.
    */
}

int main(void)
{
    int opcion;

    printf("===============================================\n");
    printf("       APRENDIENDO getchar() EN LENGUAJE C\n");
    printf("===============================================\n");
    printf("Selecciona un ejemplo escribiendo un numero:\n\n");
    printf("1. Leer un caracter y mostrarlo\n");
    printf("2. Identificar si es letra, digito o simbolo\n");
    printf("3. Preguntar SI o NO\n");
    printf("4. Elegir una opcion A o B\n");
    printf("Seleccion: ");

    /* Leemos la opcion del menu con getchar() tambien. */
    opcion = getchar();
    limpiarEntrada();

    switch (opcion)
    {
        case '1':
            ejemplo1();
            break;
        case '2':
            ejemplo2();
            break;
        case '3':
            ejemplo3();
            break;
        case '4':
            ejemplo4();
            break;
        default:
            printf("\nOpcion no valida. Ejecuta el programa y escribe 1, 2, 3 o 4.\n");
            break;
    }

    printf("\nFin del programa.\n");

#ifdef _WIN32
    /* Mantiene abierta la consola cuando se ejecuta el .exe en Windows. */
    system("pause");
#else
    /* Alternativa para sistemas que no tienen el comando de Windows 'pause'. */
    printf("Pulsa ENTER para finalizar...");
    (void)getchar();
#endif

    return 0;
}
