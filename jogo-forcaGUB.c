#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define verdadeiro 1
#define falso 0

int main() {
    int i, j, sorteio, numletras, contagem, vidas = 6, acertos, lugar, letra_invalida = 0, num_invalido = 0, cont = -1, erros = 0;
    char letra, formacao[20], palavraSeparada[20], invalidos[20], letraErros[20], elemento, resposta = 's';
    int acertou = falso, letrarepetida = falso;
    char *palavra[] = {"sextou", "intervalo", "prova", "professor", "senai", "github", "carnaval", "capivara"};
    char *palavraSorteada;

    srand(time(NULL));

    while (resposta != 'n') {
        vidas = 6;
        letra_invalida = 0;
        num_invalido = 0;
        cont = -1;
        erros = 0;

        system("cls"); // ou system("clear") no Linux
        printf("--------------------------------------------JOGO DA FORCA--------------------------------------------");
        printf("\n Funcionamento do jogo:");
        printf("\n So e permitido inserir letras minusculas, sendo descontado 1 vida caso contrario;");
        printf("\n Nao e permitido inserir caracteres especiais no jogo, sendo descontado 1 vida caso contrario;");
        printf("\n O jogador tem 6 vidas, e o jogo acaba quando o jogador acerta a palavra ou perde todas as vidas;");
        printf("\n-----------------------------------------------------------------------------------------------------\n");

        sorteio = rand() % 8;
        palavraSorteada = palavra[sorteio];
        numletras = strlen(palavraSorteada);
        acertos = numletras;

        for (lugar = 0; lugar < numletras; lugar++) {
            palavraSeparada[lugar] = palavraSorteada[lugar];
            formacao[lugar] = '_';
        }

        while (vidas > 0 && acertos > 0) {
            printf("\nVidas: %d\n", vidas);

            for (lugar = 0; lugar < numletras; lugar++) {
                printf("%c ", formacao[lugar]);
            }

            printf("\n\nDigite uma letra minuscula: ");
            scanf(" %c", &letra);

            if (letra >= 'a' && letra <= 'z') {
                // Letra válida
            } else if (letra >= 'A' && letra <= 'Z') {
                letra_invalida++;
                vidas--;
                printf("\nERRO! A letra digitada e maiuscula! insira APENAS MINUSCULA!!!\n");
                continue;
            } else {
                letra_invalida++;
                vidas--;
                printf("\nERRO! Voce digitou um caractere especial! insira APENAS letras MINUSULA!!!\n");
                continue;
            }

            acertou = falso;
            letrarepetida = falso;

            for (lugar = 0; lugar < numletras; lugar++) {
                if (letra == palavraSeparada[lugar]) {
                    if (formacao[lugar] == letra) {
                        letrarepetida = verdadeiro;
                    } else if (letra != formacao[lugar]) {
                        acertou = verdadeiro;
                        formacao[lugar] = letra;
                        acertos--;
                    }
                }
            }

            if (letrarepetida == verdadeiro) {
                printf("\nATENCAO! A letra digitada ja foi utilizada!");
            } else if (acertou == verdadeiro) {
                printf("ACERTOU\n");
            } else {
                printf("ERROU\n");
                erros++;
                vidas--;
                cont++;
                letraErros[cont] = letra;
            }

            if (erros > 0) {
                printf("\nERROS COMETIDOS: ");
                for (int indice = 0; indice < cont + 1; indice++) {
                    printf("%c ", letraErros[indice]);
                }
            }

            if (acertos == 0) {
                printf("\n\nPalavra completa: ");
                for (lugar = 0; lugar < numletras; lugar++) {
                    printf("%c ", formacao[lugar]);
                }
                printf("\n\nPARABENS! Voce acertou a palavra: %s", palavraSorteada);
            }
        }

        if (vidas == 0) {
            printf("\n\nVoce perdeu! A palavra era: %s", palavraSorteada);
            printf("\n----------------------------------------------------------------------------------------------------------");
            if (num_invalido != 0) {
                printf("\nDigitou %d valor(es) inválido(s) como números ou caracteres especiais", num_invalido);
            }
            if (acertos < numletras) {
                printf("\nDigitou %d letra(s) certa(s)", letra_invalida - acertos);
            } else {
                printf("\nNão acertou nenhuma letra! Dica: Comece com vogais!\n");
            }
            printf("\nTente denovo, quem sabe numa proxima vez...");
        }

        printf("\n\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &resposta);
    }

    return 0;
}
