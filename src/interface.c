#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void mostrar_menu() {
    printf("\n--------------------------------------------\n");
    printf("                JOGO DA FORCA               \n");
    printf("--------------------------------------------\n");
    printf("1 - Jogar\n");
    printf("2 - Instrucoes\n");
    printf("3 - Sair\n");
}

void mostrar_instrucoes() {
    printf("\n------------------ INSTRUCOES ------------------\n");
    printf("- Use apenas letras minusculas.\n");
    printf("- Letras maiusculas ou caracteres invalidos custam 1 vida.\n");
    printf("- Voce tem 6 vidas para acertar a palavra.\n");
    printf("- Letras repetidas nao descontam vidas.\n");
    printf("------------------------------------------------\n");
}

void mostrar_palavra(char formacao[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c ", formacao[i]);
    }
    printf("\n");
}

void mostrar_erros(char erros[], int total) {
    if (total == 0) return;
    printf("\nErros cometidos: ");
    for (int i = 0; i < total; i++) {
        printf("%c ", erros[i]);
    }
    printf("\n");
}

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
