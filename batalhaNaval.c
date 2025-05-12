#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define EDGE 2
#define SIZE 3

// ## Navios

// Posição Horizontal
void navioHorizontal(int tabuleiro[LINHAS][COLUNAS], int inputNavioHorizontalRow, char inputNavioHorizontalCol){
    
    int navioH[SIZE];
    int linha = inputNavioHorizontalRow - 1;
    int coluna = inputNavioHorizontalCol - 'A';

    // Armazena as colunas ocupadas pelo navio horizontal
    for (int i = 0; i < SIZE; i++) {
        navioH[i] = coluna + i;
    }

    // Valida os navios dentro do tabuleiro
    if (coluna + EDGE < COLUNAS && linha + EDGE < LINHAS) {
        for (int i = 0; i < SIZE; i++) {

            //Posição navio horizontal
            tabuleiro[linha][navioH[i]] = 3;
        }
    } else{
        printf("Ultrapassou o limite do espaço no tabuleiro \n");
    }
}

// Posição Vertical
void navioVertical(int tabuleiro[LINHAS][COLUNAS], int inputNavioVerticalRow, char inputNavioVerticalCol){
    
    int navioV[SIZE];
    int linha = inputNavioVerticalRow - 1;
    int coluna = inputNavioVerticalCol - 'A';

    // Armazena as colunas ocupadas pelo navio Vertical
    for (int i = 0; i < SIZE; i++) {
        navioV[i] = linha + i;
    }

    // Valida os navios dentro do tabuleiro
    if (coluna + EDGE < COLUNAS && linha + EDGE < LINHAS) {
        for (int i = 0; i < SIZE; i++) {

            //Posição navio vertical
            tabuleiro[navioV[i]][coluna] = 3;
        }
    } else{
        printf("Ultrapassou o limite do espaço no tabuleiro \n");
    }
}

// Posição Diagonal para Cima
void navioDiagonalCima(int tabuleiro[LINHAS][COLUNAS], int inputNavioDiagonalCimaRow, char inputNavioDiagonalCimaCol){
    
    int navioDcima1[SIZE];
    int navioDcima2[SIZE];
    int linha = inputNavioDiagonalCimaRow - 1;
    int coluna = inputNavioDiagonalCimaCol - 'A';

    // Armazena as colunas ocupadas pelo navio Vertical
    for (int i = 0; i < SIZE; i++) {
        navioDcima1[i] = linha - i;
        navioDcima2[i] = coluna + i;
    }

    // Valida os navios dentro do tabuleiro
    if (coluna + EDGE < COLUNAS && linha + EDGE < LINHAS) {
        for (int i = 0; i < SIZE; i++) {

            //Posição navio diagonal para cima
            tabuleiro[navioDcima1[i]][navioDcima2[i]] = 3;
        }
    } else{
        printf("Ultrapassou o limite do espaço no tabuleiro \n");
    }
}

// Posição Diagonal para Baixo
void navioDiagonalBaixo(int tabuleiro[LINHAS][COLUNAS], int inputNavioDiagonalBaixoRow, char inputNavioDiagonalBaixoCol){
    
    int navioDbaixo1[SIZE];
    int navioDbaixo2[SIZE];
    int linha = inputNavioDiagonalBaixoRow - 1;
    int coluna = inputNavioDiagonalBaixoCol - 'A';

    // Armazena as colunas ocupadas pelo navio Vertical
    for (int i = 0; i < SIZE; i++) {
        navioDbaixo1[i] = linha + i;
        navioDbaixo2[i] = coluna + i;
    }

    // Valida os navios dentro do tabuleiro
    if (coluna + EDGE < COLUNAS && linha + EDGE < LINHAS) {
        for (int i = 0; i < SIZE; i++) {

            //Posição navio diagonal para baixo
            tabuleiro[navioDbaixo1[i]][navioDbaixo2[i]] = 3;
        }
    } else{
        printf("Ultrapassou o limite do espaço no tabuleiro \n");
    }
}


// ## Estratégias de jogo

// Cone
void cone(int tabuleiro[LINHAS][COLUNAS], int inputEstrategiaConeRow, char inputEstrategiaConeCol){

    int item1Linha1[1];
    int item1Linha2[3];
    int linhaEstrategiaCone = inputEstrategiaConeRow - 1;
    int colunaEstrategiaCone = inputEstrategiaConeCol - 'A';

    // Validar se há espaço para o cone completo
    if (linhaEstrategiaCone + EDGE < LINHAS &&
        colunaEstrategiaCone - EDGE >= 0 && colunaEstrategiaCone + EDGE < COLUNAS) {
        
        // Linha 0: 1 coluna (centro)
        tabuleiro[linhaEstrategiaCone][colunaEstrategiaCone] = 5;

        // Linha 1: 3 colunas (centro -1, centro, centro +1)
        for (int j = -1; j <= 1; j++) {
            tabuleiro[linhaEstrategiaCone + 1][colunaEstrategiaCone + j] = 5;
        }

        // Linha 2: 5 colunas (centro -2 até centro +2)
        for (int j = -2; j <= 2; j++) {
            tabuleiro[linhaEstrategiaCone + 2][colunaEstrategiaCone + j] = 5;
        }
    } else{
        printf("Ultrapassou o limite para a estratégia cone \n");
    }

}

// Cruz
void cruz(int tabuleiro[LINHAS][COLUNAS], int inputEstrategiaCruzRow, char inputEstrategiaCruzCol){

    int linhaEstrategiaCruz = inputEstrategiaCruzRow - 1;
    int colunaEstrategiaCruz = inputEstrategiaCruzCol - 'A';

    // Validar se há espaço para a cruz
    if (linhaEstrategiaCruz + EDGE < LINHAS &&
        colunaEstrategiaCruz - EDGE >= 0 && colunaEstrategiaCruz + EDGE < COLUNAS) {
        
        // Linha 0: 1 coluna (centro)
        tabuleiro[linhaEstrategiaCruz][colunaEstrategiaCruz] = 5;

        // Linha 1: 5 colunas (centro -2, centro, centro +2)
        for (int j = -2; j <= 2; j++) {
            tabuleiro[linhaEstrategiaCruz + 1][colunaEstrategiaCruz + j] = 5;
        }

        // Linha 2: 1 coluna (centro)
        for (int j = 0; j <= 0; j++) {
            tabuleiro[linhaEstrategiaCruz + 2][colunaEstrategiaCruz] = 5;
        }
    } else{
        printf("Ultrapassou o limite para a estratégia cruz \n");
    }
}

//Octaedro
void octaedro(int tabuleiro[LINHAS][COLUNAS], int inputEstrategiaOctaedroRow, char inputEstrategiaOctaedroCol){

    int linhaEstrategiaOctaedro = inputEstrategiaOctaedroRow - 1;
    int colunaEstrategiaOctaedro = inputEstrategiaOctaedroCol - 'A';

    // Validar se há espaço para o octaedro
    if (linhaEstrategiaOctaedro + EDGE < LINHAS &&
        colunaEstrategiaOctaedro - 1 >= 0 && colunaEstrategiaOctaedro + 1 < COLUNAS) {
        
        // Linha 0: 1 coluna (centro)
        tabuleiro[linhaEstrategiaOctaedro][colunaEstrategiaOctaedro] = 5;

        // Linha 1: 3 colunas (centro -1, centro, centro +1)
        for (int j = -1; j <= 1; j++) {
            tabuleiro[linhaEstrategiaOctaedro + 1][colunaEstrategiaOctaedro + j] = 5;
        }

        // Linha 2: 1 coluna (centro)
        for (int j = 0; j <= 0; j++) {
            tabuleiro[linhaEstrategiaOctaedro + 2][colunaEstrategiaOctaedro] = 5;
        }
    } else{
        printf("Ultrapassou o limite para a estratégia octaedro \n");
    }
}


int main(){

    int tabuleiro[LINHAS][COLUNAS] = {0};
    char colunaTabuleiro[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linhaTabuleiro[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Input usuário para começar o navio
    int inputNavioHorizontalRow = 3;
    char inputNavioHorizontalCol = 'G';
    int inputNavioVerticalRow = 7;
    char inputNavioVerticalCol = 'C';
    int inputNavioDiagonalCimaRow = 3;
    char inputNavioDiagonalCimaCol = 'D';
    int inputNavioDiagonalBaixoRow = 4;
    char inputNavioDiagonalBaixoCol = 'B';
    int inputEstrategiaConeRow = 8;
    char inputEstrategiaConeCol = 'H';
    int inputEstrategiaCruzRow = 5;
    char inputEstrategiaCruzCol = 'G';
    int inputEstrategiaOctaedroRow = 1;
    char inputEstrategiaOctaedroCol = 'B';


    navioDiagonalCima(tabuleiro, inputNavioDiagonalCimaRow, inputNavioDiagonalCimaCol);
    navioDiagonalBaixo(tabuleiro, inputNavioDiagonalBaixoRow, inputNavioDiagonalBaixoCol);
    navioHorizontal(tabuleiro, inputNavioHorizontalRow, inputNavioHorizontalCol);
    navioVertical(tabuleiro, inputNavioVerticalRow, inputNavioVerticalCol);
    cone(tabuleiro, inputEstrategiaConeRow, inputEstrategiaConeCol);
    cruz(tabuleiro, inputEstrategiaCruzRow, inputEstrategiaCruzCol);
    octaedro(tabuleiro, inputEstrategiaOctaedroRow, inputEstrategiaOctaedroCol);

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