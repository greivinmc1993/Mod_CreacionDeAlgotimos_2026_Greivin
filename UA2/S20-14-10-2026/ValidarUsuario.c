#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char usuario[30];
    char clave[30];

    int usuarioOk;
    int claveOk;

    printf("Usuario: ");
    scanf("%29s", usuario);

    printf("Clave: ");
    scanf("%29s", clave);

    usuarioOk = (strcmp(usuario, "admin") == 0);
    claveOk = (strcmp(clave, "Ina2026") == 0);

    if (usuarioOk && claveOk) {
        printf("Bienvenido al sistema\n");
    } else {
        printf("Usuario o clave incorrectos\n");
    }

    system("pause");

    return 0;
}

