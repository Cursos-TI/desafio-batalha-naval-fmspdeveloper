#include <stdio.h>

int main()
{
    int tamanhoTabuleiro = 10;
    int agua = 0;
    int tamanhoNavio = 3;
    int index;
    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];

    //for para sempre colocar 0 no tabuleiro
    for (int linha = agua; linha < tamanhoTabuleiro; linha++)
    {
        for (int coluna = agua; coluna < tamanhoTabuleiro; coluna++)
        {
            tabuleiro[linha][coluna] = agua;
        }
    }

    // navio 1
    tabuleiro[2][4] = tamanhoNavio;
    tabuleiro[2][5] = tamanhoNavio;
    tabuleiro[2][6] = tamanhoNavio;
    // navio 2
    tabuleiro[5][8] = tamanhoNavio;
    tabuleiro[6][8] = tamanhoNavio;
    tabuleiro[7][8] = tamanhoNavio;
    // navio 3
    tabuleiro[9][1] = tamanhoNavio;
    tabuleiro[9][2] = tamanhoNavio;
    tabuleiro[9][3] = tamanhoNavio;


    //for para apresentar navios no mapa
    for (int linha = 0; linha < tamanhoTabuleiro; linha++)
    {
        for (int coluna = 0; coluna < tamanhoTabuleiro; coluna++)
        {
            printf("%d", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
