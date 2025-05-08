#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "util.h"
#include "pontuacao.h"

#define TAM_MAX 20
#define VERDADEIRO 1
#define FALSO 0

void jogar(char palavra[]) {
    int vidas = 6;
    int tamanho = strlen(palavra);
    int acertos = tamanho;
    char formacao[TAM_MAX];
    char erros[TAM_MAX];
    int total_erros = 0;
    char letra;

    int pontos = 0;

    for (int i = 0; i < tamanho; i++) formacao[i] = '_';

    while (vidas > 0 && acertos > 0) {
        limpar_tela();
        
        forca(6 - vidas);

        printf("\nVidas: %d\n", vidas);
        mostrar_palavra(formacao, tamanho);
        mostrar_barra_de_progresso(pontos); 
        mostrar_erros(erros, total_erros);

        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);

        int valida = checar_letra(letra);
        if (valida == -1) {
            printf("Letra maiuscula! Use minusculas.\n");
            vidas--;
            continue;
        } else if (valida == 0) {
            printf("Caractere invalido!\n");
            vidas--;
            continue;
        }

        int acertou = FALSO, repetida = FALSO;

        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == letra) {
                if (formacao[i] == letra) {
                    repetida = VERDADEIRO;
                } else {
                    formacao[i] = letra;
                    acertos--;
                    acertou = VERDADEIRO;
                }
            }
        }

        if (repetida) {
            printf("Letra ja utilizada.\n");
        } else if (acertou) {
            printf("Acertou!\n");
            pontos += 10;
        } else {
            int letra_repetida = FALSO;
            for (int i = 0; i < total_erros; i++) {
                if (erros[i] == letra) {
                    letra_repetida = VERDADEIRO;
                    break;
                }
            }
        
            if (letra_repetida) {
                printf("Letra ja utilizada.\n");
            } else {
                printf("Errou!\n");
                erros[total_erros++] = letra;
                vidas--;
                pontos -= 2;
            }
        }
        
        if (pontos < 0) pontos = 0;
        
        printf("\nPressione ENTER para continuar...");
        getchar();
        getchar();
        
    }

    limpar_tela();
    mostrar_palavra(formacao, tamanho);
    mostrar_barra_de_progresso(pontos);

    if (acertos == 0) {
        limpar_tela();
        printf("\nParabens! Voce venceu! A palavra era: %s\n", palavra);
    } else {
        limpar_tela();
        printf("\nVoce perdeu! A palavra era: %s\n", palavra);
    }

    printf("Pontuacao final: %d\n", pontos);
    printf("Desempenho: %s\n", avaliar_desempenho(pontos));
}
