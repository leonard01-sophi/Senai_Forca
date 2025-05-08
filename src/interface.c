#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


#define ANSI_RESET   "\x1b[0m"
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"

void forca(int estado) {
    printf("\n================ FORCA ================\n");
    printf("|                        |\n");

    if (estado >= 1)
        printf("|                        o\n");
    else
        printf("|\n");

    if (estado == 2)
        printf("|                        |\n");
    else if (estado == 3)
        printf("|                       /|\n");
    else if (estado >= 4)
        printf("|                       /|\\\n");
    else
        printf("|\n");

    if (estado == 5)
        printf("|                       / \n");
    else if (estado >= 6)
        printf("|                       / \\\n");
    else
        printf("|\n");

    printf("|\n|\n-");
    printf("\n=======================================\n");
}

void mostrar_menu() {
    printf("\n============================================\n");
    printf("              JOGO DA FORCA                \n");
    printf("============================================\n");
    printf("1 - Jogar\n");
    printf("2 - Instrucoes\n");
    printf("3 - Sair\n");
    printf("============================================\n");
}

void mostrar_instrucoes() {
    printf("\n================== INSTRUCOES ==================\n");
    printf("- Use apenas letras minusculas.\n");
    printf("- Letras maiusculas ou caracteres invalidos custam 1 vida.\n");
    printf("- Voce tem 6 vidas para acertar a palavra.\n");
    printf("- Letras repetidas nao descontam vidas.\n");
    printf("================================================\n");
}

void mostrar_palavra(char formacao[], int tamanho) {
    printf("\nPalavra: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%c ", formacao[i]);
    }
    printf("\n");
}

void mostrar_erros(char erros[], int total) {
    if (total == 0) return;
    printf("\nLetras erradas: ");
    for (int i = 0; i < total; i++) {
        printf("%s%c%s ", ANSI_RED, erros[i], ANSI_RESET);
    }
    printf("\n");
}

void mostrarTela(char formacao[], int tamanho, char erros[], int total_erros, int vidas, int pontos) {
    limpar_tela();
    forca(6 - vidas);
    printf("\nVidas restantes: %s%d%s\n", ANSI_YELLOW, vidas, ANSI_RESET);
    mostrar_palavra(formacao, tamanho);
    mostrar_erros(erros, total_erros);
    printf("Pontuacao: %s%d%s\n", ANSI_GREEN, pontos, ANSI_RESET);
    printf("============================================\n");
}

void mostrarResumoFinal(int venceu, char palavra[], int pontos, const char* desempenho) {
    printf("\n============================================\n");
    if (venceu)
        printf("%sPARABENS! VOCE VENCEU!%s\n", ANSI_GREEN, ANSI_RESET);
    else
        printf("%sVOCE PERDEU!%s\n", ANSI_RED, ANSI_RESET);

    printf("A palavra era: %s\n", palavra);
    printf("Pontuacao final: %d\n", pontos);
    printf("Desempenho: %s\n", desempenho);
    printf("============================================\n");
}

void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
