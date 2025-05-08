#include <string.h>
#include <stdlib.h>
#include "sorteio.h"

#define TOTAL_PALAVRAS 8
#define TAM_MAX 20

static const char* palavras[TOTAL_PALAVRAS] = {
    "sextou", "intervalo", "prova", "professor", "senai", "github", "carnaval", "capivara"
};

void sortear_palavra(char destino[]) {
    int indice = rand() % TOTAL_PALAVRAS;
    strcpy(destino, palavras[indice]);
}

const char* obter_palavra(int indice) {
    if (indice >= 0 && indice < TOTAL_PALAVRAS) {
        return palavras[indice];
    }
    return NULL;
}

int obter_qtd_palavras() {
    return TOTAL_PALAVRAS;
}
