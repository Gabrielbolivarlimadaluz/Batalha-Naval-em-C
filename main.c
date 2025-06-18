#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main() {
    char tabuleiro[TAM][TAM];
    int linha, coluna;
    int acerto = 0;

    srand(time(NULL));
    int navioLinha = rand() % TAM;
    int navioColuna = rand() % TAM;

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~'; // água
        }
    }

    printf("=== BATALHA NAVAL ===\n");
    printf("Tente acertar o navio escondido em um tabuleiro 5x5\n");

    while (!acerto) {
        printf("Digite a linha (0 a 4): ");
        scanf("%d", &linha);
        printf("Digite a coluna (0 a 4): ");
        scanf("%d", &coluna);

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            printf("Coordenada inválida. Tente de novo.\n");
            continue;
        }

        if (linha == navioLinha && coluna == navioColuna) {
            printf("ACERTOU! Você afundou o navio inimigo!\n");
            tabuleiro[linha][coluna] = 'X';
            acerto = 1;
        } else {
            printf("Água. Tente novamente.\n");
            tabuleiro[linha][coluna] = '*';
        }

        // Mostrar o tabuleiro
        printf("\nTabuleiro:\n");
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                printf("%c ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
