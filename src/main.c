#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "interface.h"
#include "logica.h"
#include "util.h"
#include "sorteio.h"

#define TAM_MAX 20

int main() {
    char palavra[TAM_MAX];
    char opcao;

    srand(time(NULL));

    do {
        limpar_tela();
        mostrar_menu();

        printf("\nEscolha uma opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1': {
                int qtd_palavras = obter_qtd_palavras();
                const char* palavra_sorteada = obter_palavra(rand() % qtd_palavras);
                if (palavra_sorteada != NULL) {
                    strcpy(palavra, palavra_sorteada);
                    jogar(palavra);
                } else {
                    printf("Erro ao sortear palavra.\n");
                }
                break;
            }
            case '2':
                mostrar_instrucoes();
                break;
            case '3':
                printf("\nSaindo do jogo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

        if (opcao != '3') {
            printf("\n\nPressione ENTER para voltar ao menu...");
            getchar(); 
            getchar(); 
        }

    } while (opcao != '3');

    return 0;
}
