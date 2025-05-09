#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define SIZE 3


int main(){

    int tabuleiro[LINHAS][COLUNAS] = {0};
    char colunaTabuleiro[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linhaTabuleiro[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int navioH[SIZE];
    int navioV[SIZE];
    int navioDcima1[SIZE];
    int navioDcima2[SIZE];
    int navioDbaixo1[SIZE];
    int navioDbaixo2[SIZE];

    //Input usuário para começar o navio
    int inputLinhaNavioH = 3;
    char inputColunaNavioH = 'G';
    int inputLinhaNavioV = 7;
    char inputColunaNavioV = 'C';
    int inputLinhaNavioDcima = 3;
    char inputColunaNavioDcima = 'D';
    int inputLinhaNavioDnaixo = 4;
    char inputColunaNavioDnaixo = 'B';


    // Converter para índices - indice que vai começar o navio
    // Índice será sempre 0, então, diminuir por 1 a gente adequa ao índice
    int linhaHorizontal = inputLinhaNavioH - 1;
    int colunaHorizontal = inputColunaNavioH - 'A';
    int linhaVertical = inputLinhaNavioV - 1;
    int colunaVertical = inputColunaNavioV - 'A';
    int linhaDiagonalCima = inputLinhaNavioDcima - 1;
    int colunaDiagonalCima = inputColunaNavioDcima - 'A';
    int linhaDiagonalBaixo = inputLinhaNavioDnaixo - 1;
    int colunaDiagonalBaixo = inputColunaNavioDnaixo - 'A';

    // Inicializando os vetores com as posições dos navios
    // Armazena as colunas ocupadas pelo navio horizontal
    for (int i = 0; i < SIZE; i++) {
        navioH[i] = colunaHorizontal + i;
        navioV[i] = linhaVertical + i;

        navioDbaixo1[i] = linhaDiagonalBaixo + i;
        navioDbaixo2[i] = colunaDiagonalBaixo + i;

        navioDcima1[i] = linhaDiagonalCima - i;
        navioDcima2[i] = colunaDiagonalCima + i;
    }

    // Valida os navios dentro do tabuleiro
    if (colunaHorizontal + 2 < 10 && linhaVertical + 2 < 10) {
        for (int i = 0; i < SIZE; i++) {

            // Marca as posições no tabuleiro

            //Posição navio horizontal
            tabuleiro[linhaHorizontal][navioH[i]] = 3;
            //Posição navio vertical
            tabuleiro[navioV[i]][colunaVertical] = 3;
            //Posição navio diagonal para baixo
            tabuleiro[navioDbaixo1[i]][navioDbaixo2[i]] = 3;
            //Posição navio diagonal para cima
            tabuleiro[navioDcima1[i]][navioDcima2[i]] = 3;
        }
    }


    printf("---------------------------------\n");
    printf("##          TABULEIRO          ##\n");
    printf("---------------------------------\n");
    printf("  ");

    // Cabeçalho com letras das colunas
    for (int a = 0; a < 10; a++) {
        printf("%2c ", colunaTabuleiro[a]);
    }

    printf("\n");

    // Imprime o tabuleiro
    printf("---------------------------------\n");

    //Para cada linha o segundo for será executado de forma inteira
    //Exemplo: primeiro for passa pela linha 1, o segundo for vai passar pelas colunas A,B,C,D,E,F,G,H,I,J.
    // depois o primeiro for passa pela linha 1, o segundo for vai passar pelas colunas A,B,C,D,E,F,G,H,I,J.
    // e assim sucessivamente
    for (int i = 0; i < LINHAS; i++) {
        printf("%d ", linhaTabuleiro[i]); // número da linha

        for (int j = 0; j < COLUNAS; j++) {
            printf("%2d ", tabuleiro[i][j]); // Valor da célula
        }
        printf("\n");
        printf("---------------------------------\n");
    }

    return 0;
}