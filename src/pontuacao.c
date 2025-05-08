#include <stdio.h>
#include "pontuacao.h"

void mostrar_barra_de_progresso(int pontuacao) {
    int total_barras = 10;
    int preenchidas = pontuacao * total_barras / 100;
    if (preenchidas > total_barras) preenchidas = total_barras;
    if (preenchidas < 0) preenchidas = 0;

    printf("Progresso: ");
    for (int i = 0; i < preenchidas; i++) printf("#");
    for (int i = 0; i < total_barras - preenchidas; i++) printf("-");
    printf(" %d%%\n", pontuacao);
}

const char* avaliar_desempenho(int pontuacao) {
    if (pontuacao >= 80) return "Excelente";
    else if (pontuacao >= 50) return "Bom";
    else return "Regular";
}
