#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    // Declaração da matriz do tabuleiro 10x10, inicializada com água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializando o tabuleiro com 0 (água)
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Declaração dos dois navios com tamanho 3
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    // === Posicionamento do navio horizontal ===
    int linhaH = 3;   // Linha de início do navio horizontal
    int colunaH = 2;  // Coluna de início

    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: navio horizontal ultrapassa os limites do tabuleiro.\n");
    }

    // === Posicionamento do navio vertical ===
    int linhaV = 5;   // Linha de início do navio vertical
    int colunaV = 6;  // Coluna de início

    // Verificação de limites e sobreposição
    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        } else {
            printf("Erro: navio vertical sobrepõe outro navio.\n");
        }
    } else {
        printf("Erro: navio vertical ultrapassa os limites do tabuleiro.\n");
    }

    // === Impressão do tabuleiro ===
    printf("\nTabuleiro (0 = água, 3 = navio):\n");
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
