#include <stdio.h>

int main(){

    int tabuleiro[10][10] = {0};
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int navioH[3];
    int navioV[3];

    int linhaHorizontal = 1;
    char colunaHorizontal = 'A';
    int linhaVertical = 5;
    char colunaVertical = 'B';

    // Converter para índices
    // Índice será sempre 0, então, diminuir por 1 a gente adequa ao índice
    int lh = linhaHorizontal - 1;
    int ch = colunaHorizontal - 'A';
    int lv = linhaVertical - 1;
    int cv = colunaVertical - 'A';

    // Inicializando os vetores com as posições dos navios
    for (int i = 0; i < 3; i++) {
        navioH[i] = ch + i;  // Armazena as colunas ocupadas pelo navio horizontal
    }

    for (int i = 0; i < 3; i++) {
        navioV[i] = lv + i;  // Armazena as linhas ocupadas pelo navio vertical
    }

    // Posicionar navio horizontal (3 posições para a direita)
    if (ch + 2 < 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[lh][navioH[i]] = 3;  // Marca as posições no tabuleiro
        }
    }

    // Posicionar navio vertical (3 posições para baixo)
    if (lv + 2 < 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[navioV[i]][cv] = 3;  // Marca as posições no tabuleiro
        }
    }


    printf("---------------------------------\n");
    printf("##          TABULEIRO          ##\n");
    printf("---------------------------------\n");
    printf("  ");

    // Cabeçalho com letras das colunas
    for (int a = 0; a < 10; a++) {
        printf("%2c ", linha[a]);
    }

    printf("\n");

    // Imprime o tabuleiro
    printf("---------------------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", coluna[i]); // número da linha

        for (int j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]); // Valor da célula
        }
        printf("\n");
        printf("---------------------------------\n");
    }

    return 0;
}