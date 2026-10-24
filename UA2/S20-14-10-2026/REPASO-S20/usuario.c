
#include <stdio.h>
#include <string.h>

/*
Enunciado:
Crear una cuenta para un estudiante usando su nombre completo.
Generar un nombre de usuario, validar una contrasena y mostrar
un mensaje de cuenta creada.

Que se logra:
Crear el usuario con la primera letra del nombre y el primer
apellido. Validar que la contrasena tenga al menos 8 caracteres
y que coincida con su confirmacion.

Como se logra:
Se utilizan arreglos de caracteres, fgets, strcspn, strlen,
strcmp, strcpy, strcat y ciclos para recorrer y validar datos.

Resultado esperado:
Mostrar el usuario, la cantidad de caracteres y el mensaje
de cuenta creada para el estudiante.
*/


/* void limpiarEntrada(void)
{
    int caracter;  // Guarda temporalmente cada caracter leido

    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
    }
}  */



int main(void)
{
    // Nombre completo del estudiante
    char nombre[50];

    // Nombre de usuario que se va a crear
    char usuario[50];

    // Contrasena y confirmacion
    char contrasena[50];
    char confirmacion[50];

    // Mensaje final de la cuenta
    char mensaje[100];

    // Variables para recorrer las cadenas
    int i;
    int j;

    // Cantidad de caracteres del usuario
    int cantidad;

    // Indica si se encontro un espacio en el nombre
    int espacioEncontrado = 0;

    // Variable para limpiar la entrada
    int caracter;

    // Pedir el nombre completo
    do
    {
        printf("Ingrese su nombre completo: ");
        fgets(nombre, sizeof(nombre), stdin);

        // Eliminar el salto de linea
        nombre[strcspn(nombre, "\n")] = '\0';

        if (strlen(nombre) == 0)
        {
            printf("El nombre no puede estar vacio.\n");
        }

    } while (strlen(nombre) == 0);

    // Copiar la primera letra del nombre al usuario
    usuario[0] = nombre[0];

    // La siguiente posicion disponible es la numero 1
    j = 1;

    // Buscar el primer espacio del nombre
    for (i = 0; nombre[i] != '\0'; i++)
    {
        if (nombre[i] == ' ')
        {
            espacioEncontrado = 1;

            // Pasar a la primera letra de la siguiente palabra
            i++;

            // Copiar esa palabra hasta el siguiente espacio
            while (nombre[i] != '\0' && nombre[i] != ' ')
            {
                usuario[j] = nombre[i];
                j++;
                i++;
            }

            // Terminar la busqueda
            break;
        }
    }

    // Si el nombre tiene una sola palabra, copiarlo completo
    if (espacioEncontrado == 0)
    {
        strcpy(usuario, nombre);
    }
    else
    {
        // Indicar el final del usuario
        usuario[j] = '\0';
    }

    // Calcular la cantidad de caracteres del usuario
    cantidad = strlen(usuario);

    // Pedir la contrasena y su confirmacion
    do
    {
        printf("\nIngrese una contrasena (minimo 8 caracteres): ");
        scanf("%49s", contrasena);

        // Limpiar los caracteres pendientes
        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
        }

        printf("Confirme la contrasena: ");
        scanf("%49s", confirmacion);

        // Limpiar los caracteres pendientes
        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
        }

        // Revisar si la contrasena tiene al menos 8 caracteres
        if (strlen(contrasena) < 8)
        {
            printf("Error: la contrasena debe tener al menos 8 caracteres.\n");
        }

        // Revisar si las contrasenas son diferentes
        if (strcmp(contrasena, confirmacion) != 0)
        {
            printf("Error: las contrasenas no coinciden.\n");
        }

    } while (strlen(contrasena) < 8 ||
            strcmp(contrasena, confirmacion) != 0);

    // Construir el mensaje final
    strcpy(mensaje, "Cuenta creada para ");
    strcat(mensaje, nombre);

    // Mostrar los resultados
    printf("\n===============================\n");
    printf("       CUENTA EDUCATIVA\n");
    printf("===============================\n");
    printf("Nombre de usuario: %s\n", usuario);
    printf("Cantidad de caracteres: %d\n", cantidad);
    printf("%s\n", mensaje);
    printf("===============================\n");

    return 0;
}
