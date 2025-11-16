#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 7
#define AGUA 0
#define NAVIO 3
#define EFEITO_HABILIDADE 5

// Limpa o tabuleiro inteiro, enchendo de água
void limparTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int i, j;
    for(i = 0; i < TAMANHO_TABULEIRO; i++) {
        for(j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Mostra o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], const char* titulo) {
    int i, j;
    
    printf("\n=== %s ===\n\n", titulo);
    
    // Imprime os números das colunas no topo
    printf("   ");
    for(j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    // Imprime linha por linha
    for(i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);  // número da linha
        for(j = 0; j < TAMANHO_TABULEIRO; j++) {
            if(tabuleiro[i][j] == AGUA) {
                printf("~ ");
            } else if(tabuleiro[i][j] == NAVIO) {
                printf("# ");
            } else if(tabuleiro[i][j] == EFEITO_HABILIDADE) {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Cria a habilidade em formato de CONE
// Começa fino em cima e vai abrindo pra baixo
void criarHabilidadeCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    int centro = TAMANHO_HABILIDADE / 2;
    
    // Zera tudo primeiro
    for(i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz[i][j] = 0;
        }
    }
    
    // Agora cria o cone
    for(i = 0; i < TAMANHO_HABILIDADE; i++) {
        int largura = i;  // a largura vai aumentando com a linha
        for(j = 0; j < TAMANHO_HABILIDADE; j++) {
            if(j >= centro - largura && j <= centro + largura) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Cria uma CRUZ simples - linha e coluna no meio
void criarHabilidadeCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    int centro = TAMANHO_HABILIDADE / 2;
    
    // Limpa tudo
    for(i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz[i][j] = 0;
        }
    }
    
    // Marca a cruz - se tá no meio (linha ou coluna), marca
    for(i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(j = 0; j < TAMANHO_HABILIDADE; j++) {
            if(i == centro || j == centro) {
                matriz[i][j] = 1;
            }
        }
    }
}

// OCTAEDRO = losango (tipo um diamante)
// Usei a distância de Manhattan aqui (achei num tutorial)
void criarHabilidadeOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    int centro = TAMANHO_HABILIDADE / 2;
    
    // Limpa
    for(i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz[i][j] = 0;
        }
    }
    
    // Cria o losango calculando a distância do centro
    for(i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(j = 0; j < TAMANHO_HABILIDADE; j++) {
            int distancia = abs(i - centro) + abs(j - centro);
            if(distancia <= centro) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Aplica a habilidade no tabuleiro
// Pega a matriz da habilidade e coloca em cima do tabuleiro
void sobreporHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                        int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                        int origem_linha, int origem_coluna) {
    int i, j;
    int offset = TAMANHO_HABILIDADE / 2;  // pra centralizar
    
    for(i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Calcula onde vai cair no tabuleiro
            int tab_linha = origem_linha - offset + i;
            int tab_coluna = origem_coluna - offset + j;
            
            // Verifica se tá dentro do tabuleiro
            if(tab_linha >= 0 && tab_linha < TAMANHO_TABULEIRO &&
               tab_coluna >= 0 && tab_coluna < TAMANHO_TABULEIRO) {
                
                // Se a habilidade marca essa posição (valor 1 na matriz)
                if(matriz[i][j] == 1) {
                    // Só marca se não for navio (pra não apagar o navio)
                    if(tabuleiro[tab_linha][tab_coluna] != NAVIO) {
                        tabuleiro[tab_linha][tab_coluna] = EFEITO_HABILIDADE;
                    }
                }
            }
        }
    }
}

// Coloca os 4 navios no tabuleiro
void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int i;
    
    // Navio 1 - Horizontal na linha 2
    for(i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[2][1 + i] = NAVIO;
    }
    
    // Navio 2 - Vertical na coluna 8
    for(i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[6 + i][8] = NAVIO;
    }
    
    // Navio 3 - Diagonal pra baixo
    for(i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[i][5 + i] = NAVIO;
    }
    
    // Navio 4 - Diagonal pra cima
    for(i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[4 + i][5 - i] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int matriz_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    
    printf("=== BATALHA NAVAL - NIVEL AVANCADO ===\n");
    printf("Sistema de Habilidades Especiais\n\n");
    
    // Testando a habilidade CONE
    printf("\n--- HABILIDADE: CONE ---\n");
    limparTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    criarHabilidadeCone(matriz_cone);
    
    printf("Aplicando habilidade CONE no ponto (1, 5)\n");
    sobreporHabilidade(tabuleiro, matriz_cone, 1, 5);
    exibirTabuleiro(tabuleiro, "TABULEIRO COM HABILIDADE CONE");
    
    // Agora a CRUZ
    printf("\n\n--- HABILIDADE: CRUZ ---\n");
    limparTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    criarHabilidadeCruz(matriz_cruz);
    
    printf("Aplicando habilidade CRUZ no ponto (5, 5)\n");
    sobreporHabilidade(tabuleiro, matriz_cruz, 5, 5);
    exibirTabuleiro(tabuleiro, "TABULEIRO COM HABILIDADE CRUZ");
    
    // Por último, o OCTAEDRO (losango)
    printf("\n\n--- HABILIDADE: OCTAEDRO (LOSANGO) ---\n");
    limparTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    criarHabilidadeOctaedro(matriz_octaedro);
    
    printf("Aplicando habilidade OCTAEDRO no ponto (7, 4)\n");
    sobreporHabilidade(tabuleiro, matriz_octaedro, 7, 4);
    exibirTabuleiro(tabuleiro, "TABULEIRO COM HABILIDADE OCTAEDRO");
    
    // Mostra a legenda
    printf("\n\nLEGENDA:\n");
    printf("  ~ = Agua\n");
    printf("  # = Navio\n");
    printf("  X = Area de efeito da habilidade\n");
    
    return 0;
}
