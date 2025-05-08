#include <stdio.h>
#include <string.h>
#include <time.h>

#define TAM_MAX 20
#define VERDADEIRO 1
#define FALSO 0

void mostrar_menu();
void mostrar_instrucoes();
void sortear_palavra(char palavra[], int qtd);
void jogar(char palavra[]);
int checar_letra(char letra);
void mostrar_palavra(char formacao[], int tamanho);
void mostrar_erros(char erros[], int total);

int main() {
    char palavras[8][TAM_MAX] = {"sextou", "intervalo", "prova", "professor", "senai", "github", "carnaval", "capivara"};
    int qtd_palavras = sizeof(palavras) / sizeof(palavras[0]);
    char opcao;

    srand(time(NULL));

    do {
        system("cls");
        mostrar_menu();

        printf("\nEscolha uma opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                jogar(palavras[rand() % qtd_palavras]);
                break;
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

void sortear_palavra(char palavra[], int qtd) {
    const char *palavras[8] = {"sextou", "intervalo", "prova", "professor", "senai", "github", "carnaval", "capivara"};
    strcpy(palavra, palavras[rand() % qtd]);
}

int checar_letra(char letra) {
    if (letra >= 'a' && letra <= 'z') return 1;
    if (letra >= 'A' && letra <= 'Z') return -1;
    return 0;
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

void jogar(char palavra[]) {
    int vidas = 6;
    int tamanho = strlen(palavra);
    int acertos = tamanho;
    char formacao[TAM_MAX];
    char erros[TAM_MAX];
    int total_erros = 0;
    char letra;

    for (int i = 0; i < tamanho; i++) formacao[i] = '_';

    while (vidas > 0 && acertos > 0) {
        printf("\nVidas: %d\n", vidas);
        mostrar_palavra(formacao, tamanho);

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
        } else {
            printf("Errou!\n");
            erros[total_erros++] = letra;
            vidas--;
        }

        mostrar_erros(erros, total_erros);
    }

    if (acertos == 0) {
        printf("\nParabens! Voce venceu! A palavra era: %s\n", palavra);
    } else {
        printf("\nVoce perdeu! A palavra era: %s\n", palavra);
    }
}