#include <stdio.h>
#include <stdbool.h>

// Constantes para as direções
#define CIMA 1
#define BAIXO 2
#define ESQUERDA 3
#define DIREITA 4
#define DIAG_SUP_DIR 5
#define CAVALO_CIMA_DIREITA 6

// Constantes para os movimentos das peças
#define BISPO_MOVIMENTO 5
#define TORRE_MOVIMENTO 5
#define RAINHA_MOVIMENTO 8
#define CAVALO_MOVIMENTO_X 2
#define CAVALO_MOVIMENTO_Y 1

// Função recursiva para movimentar o Bispo (diagonal superior direita)
void moverBispoRecursivo(int casasRestantes) {
    if (casasRestantes > 0) {
        printf("  Bispo: Movendo na diagonal superior direita...\n");
        moverBispoRecursivo(casasRestantes - 1); // Chamada recursiva
    }
}

// Função recursiva para movimentar a Torre (direita)
void moverTorreRecursiva(int casasRestantes) {
    if (casasRestantes > 0) {
        printf("  Torre: Movendo para a direita...\n");
        moverTorreRecursiva(casasRestantes - 1);
    }
}

// Função recursiva para movimentar a Rainha (esquerda)
void moverRainhaRecursiva(int casasRestantes) {
    if (casasRestantes > 0) {
        printf("  Rainha: Movendo para a esquerda...\n");
        moverRainhaRecursiva(casasRestantes - 1);
    }
}

int main() {
    int peca, direcao, casas;
    bool movimentoValido = false;

    // 1. Entrada de Dados
    printf("Bem-vindo ao Simulador de Movimentação de Xadrez!\n");

    printf("\nEscolha a peça (1=Bispo, 2=Torre, 3=Rainha, 4=Cavalo): ");
    scanf("%d", &peca);

    printf("Escolha a direção (1=Cima, 2=Baixo, 3=Esquerda, 4=Direita, 5=Diag. Sup. Dir., 6=Cavalo Cima-Direita): ");
    scanf("%d", &direcao);

    printf("Digite o número de casas a mover: ");
    scanf("%d", &casas);

    // 2. Estruturas de Repetição e Lógica de Movimentação
    switch (peca) {
        case 1: // Bispo
            printf("\nMovimentando o Bispo:\n");
            if (direcao == DIAG_SUP_DIR && casas == BISPO_MOVIMENTO) {
                moverBispoRecursivo(casas); // Chamada da função recursiva
                movimentoValido = true;
            } else {
                printf("Movimento inválido para o Bispo.\n");
            }
            break;

        case 2: // Torre
            printf("\nMovimentando a Torre:\n");
            if (direcao == DIREITA && casas == TORRE_MOVIMENTO) {
                moverTorreRecursiva(casas);
                movimentoValido = true;
            } else {
                printf("Movimento inválido para a Torre.\n");
            }
            break;

        case 3: // Rainha
            printf("\nMovimentando a Rainha:\n");
            if (direcao == ESQUERDA && casas == RAINHA_MOVIMENTO) {
                moverRainhaRecursiva(casas);
                movimentoValido = true;
            } else {
                printf("Movimento inválido para a Rainha.\n");
            }
            break;

        case 4: // Cavalo
            printf("\nMovimentando o Cavalo:\n");
            if (direcao == CAVALO_CIMA_DIREITA) {
                printf("Cavalo: Movimento em L para cima e direita:\n");

                // Loop com variáveis múltiplas e/ou condições múltiplas (exemplo)
                for (int i = 0, j = 0; i < 1; i++, j++) { // Uma vez, pois é um movimento em L
                    if (j == 0) {
                        printf("  Cavalo: Cima %d casas, Direita %d casas\n", CAVALO_MOVIMENTO_Y, CAVALO_MOVIMENTO_X);
                        movimentoValido = true;
                    }
                    // Exemplo de uso de continue e break (não obrigatório para este caso)
                    if (i == 0 && j == 0) {
                        continue; // Pula para a próxima iteração (não faz nada neste caso)
                    }
                    if (j > 0) {
                        break; // Sai do loop
                    }
                }
            } else {
                printf("Movimento inválido para o Cavalo.\n");
            }
            break;

        default:
            printf("Peça inválida.\n");
    }

    // 3. Saída de Dados
    if (movimentoValido) {
        printf("Movimento válido.\n");
    } else {
        printf("Movimento inválido.\n");
    }

    return 0;
}