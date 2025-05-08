#include <stdio.h>
#include <unistd.h> // Para usar sleep() no Linux/macOS (use <windows.h> e Sleep() no Windows)

void forca(int estado) {
    printf("\n-------------------------");
    printf("\n|                        |");

    if (estado >= 1)
        printf("\n|                        o");
    else
        printf("\n|");

    if (estado == 2)
        printf("\n|                        |");
    else if (estado == 3)
        printf("\n|                       /|");
    else if (estado >= 4)
        printf("\n|                       /|\\");

    else
        printf("\n|");

    if (estado == 5)
        printf("\n|                       / ");
    else if (estado >= 6)
        printf("\n|                       / \\");
    else
        printf("\n|");

    printf("\n|");
    printf("\n|");
    printf("\n-");
}

int main(void) {
    printf("Demonstração da forca (estados de 0 a 6):\n");

    for (int i = 0; i <= 6; i++) {
        forca(i);
        printf("\n\nPressione ENTER para o próximo estado...");
        getchar(); // Espera o usuário pressionar ENTER
    }

    printf("\nFim da demonstração.\n");
    return 0;
}
