#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define HABILIDADE_CONE 7
#define HABILIDADE_CRUZ 8
#define HABILIDADE_OCTAEDRO 9
#define TAM_HAB 5
#define AGUA 0
#define NAVIO_GRANDE 5
#define NAVIO_MEDIO 3
#define NAVIO_PEQUENO 2

// Protótipos das funções
void aplicarHabilidade(int tabuleiro[LINHAS][COLUNAS], int hab[TAM_HAB][TAM_HAB], 
                      int linha_centro, int coluna_centro, int tipo_habilidade);
void criarCone(int hab[TAM_HAB][TAM_HAB]);
void criarCruz(int hab[TAM_HAB][TAM_HAB]);
void criarOctaedro(int hab[TAM_HAB][TAM_HAB]);
void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]);
void inicializarTabuleiro(int tabuleiro[LINHAS][COLUNAS]);
void posicionarNavios(int tabuleiro[LINHAS][COLUNAS]);

int main() {
    int tabuleiro[LINHAS][COLUNAS];
    
    // Inicialização do tabuleiro
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    
    // Criação das habilidades
    int cone[TAM_HAB][TAM_HAB] = {0};
    criarCone(cone);
    
    int cruz[TAM_HAB][TAM_HAB] = {0};
    criarCruz(cruz);
    
    int octaedro[TAM_HAB][TAM_HAB] = {0};
    criarOctaedro(octaedro);
    
    // Aplicação das habilidades
    aplicarHabilidade(tabuleiro, cone, 3, 3, HABILIDADE_CONE);
    aplicarHabilidade(tabuleiro, cruz, 5, 5, HABILIDADE_CRUZ);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7, HABILIDADE_OCTAEDRO);
    
    // Exibição final
    printf("Tabuleiro com navios e habilidades:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}

void aplicarHabilidade(int tabuleiro[LINHAS][COLUNAS], int hab[TAM_HAB][TAM_HAB],
                      int linha_centro, int coluna_centro, int tipo_habilidade) {
    int inicio_linha = linha_centro - TAM_HAB/2;
    int inicio_coluna = coluna_centro - TAM_HAB/2;

    for(int i = 0; i < TAM_HAB; i++) {
        for(int j = 0; j < TAM_HAB; j++) {
            int tab_linha = inicio_linha + i;
            int tab_coluna = inicio_coluna + j;
            
            if(tab_linha >= 0 && tab_linha < LINHAS &&
               tab_coluna >= 0 && tab_coluna < COLUNAS &&
               hab[i][j] == 1) {
                tabuleiro[tab_linha][tab_coluna] = tipo_habilidade;
            }
        }
    }
}

void criarCone(int hab[TAM_HAB][TAM_HAB]) {
    for(int linha = 0; linha < TAM_HAB/2 + 1; linha++) {
        for(int coluna = 0; coluna < TAM_HAB; coluna++) {
            if(coluna >= (TAM_HAB/2 - linha) && 
               coluna <= (TAM_HAB/2 + linha)) {
                hab[linha][coluna] = 1;
            }
        }
    }
}

void criarCruz(int hab[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB/2;
    for(int i = 0; i < TAM_HAB; i++) {
        hab[centro][i] = 1;  // Linha horizontal
        if(i != centro) {     // Evita sobrescrever o centro
            hab[i][centro] = 1;  // Linha vertical
        }
    }
}

void criarOctaedro(int hab[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB/2;
    for(int linha = 0; linha < TAM_HAB; linha++) {
        int distancia = (linha <= centro) ? (centro - linha) : (linha - centro);
        for(int coluna = 0; coluna < TAM_HAB; coluna++) {
            if(coluna >= (centro - distancia) && 
               coluna <= (centro + distancia)) {
                hab[linha][coluna] = 1;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    for(int linha = 0; linha < LINHAS; linha++) {
        for(int coluna = 0; coluna < COLUNAS; coluna++) {
            switch(tabuleiro[linha][coluna]) {
                case AGUA: printf("0 "); break;
                case NAVIO_PEQUENO: 
                case NAVIO_MEDIO: 
                case NAVIO_GRANDE: printf("N "); break;
                case HABILIDADE_CONE: printf("C "); break;
                case HABILIDADE_CRUZ: printf("+ "); break;
                case HABILIDADE_OCTAEDRO: printf("O "); break;
                default: printf("? ");
            }
        }
        printf("\n");
    }
}

void inicializarTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    for(int linha = 0; linha < LINHAS; linha++) {
        for(int coluna = 0; coluna < COLUNAS; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }
}

void posicionarNavios(int tabuleiro[LINHAS][COLUNAS]) {
    // Navio 1 (Horizontal)
    tabuleiro[2][4] = NAVIO_MEDIO;
    tabuleiro[2][5] = NAVIO_MEDIO;
    tabuleiro[2][6] = NAVIO_MEDIO;
    
    // Navio 2 (Vertical)
    tabuleiro[5][8] = NAVIO_MEDIO;
    tabuleiro[6][8] = NAVIO_MEDIO;
    tabuleiro[7][8] = NAVIO_MEDIO;
    
    // Navio 3 (Horizontal)
    tabuleiro[9][1] = NAVIO_MEDIO;
    tabuleiro[9][2] = NAVIO_MEDIO;
    tabuleiro[9][3] = NAVIO_MEDIO;
    
    // Navio 4 (Vertical)
    tabuleiro[1][7] = NAVIO_MEDIO;
    tabuleiro[2][7] = NAVIO_MEDIO;
    tabuleiro[3][7] = NAVIO_MEDIO;
    
    // Navio 5 (Pequeno - Horizontal)
    tabuleiro[1][4] = NAVIO_PEQUENO;
    tabuleiro[1][5] = NAVIO_PEQUENO;
    
    // Navio 6 (Grande - Horizontal)
    tabuleiro[8][5] = NAVIO_GRANDE;
    tabuleiro[8][6] = NAVIO_GRANDE;
    tabuleiro[8][7] = NAVIO_GRANDE;
    tabuleiro[8][8] = NAVIO_GRANDE;
    tabuleiro[8][9] = NAVIO_GRANDE;
}
