#include <stdio.h>

#define LIN 8
#define COL 8
#define ID "TCBDRP"
typedef enum cor
{
    BRANCO,
    PRETO
}   Cor;

typedef struct  peca
{
    char    *cor;
    char    *id;
    char    *pos;
}   Peca;

void    camposVazios(char tabuleiro[LIN][COL])
{
    int     posLin = 2;
    int     posCol;

    while (posLin < LIN - 2)
    {
        posCol = 0;
        while (posCol < COL)
        {
            tabuleiro[posLin][posCol] = 'X';
            posCol++;
        }
        posLin++;
    }
}

void    printTabuleiro(char tabuleiro[LIN][COL])
{
    int     posLin = 0;
    int     posCol;
    int     num = 1;
    

    while (posLin < LIN)
    {
        posCol = 0;
        printf("%i ", num++);
        while (posCol < COL)
        {
            printf(" %c ", tabuleiro[posLin][posCol]);
            posCol++;
        }
        printf("\n");
        posLin++;
    }
    printf("   A  B  C  D  E  F  G  H\n");
}

int main(void)
{
    char    tabuleiro[LIN][COL];

    camposVazios(tabuleiro);
    printTabuleiro(tabuleiro);
    return (0);
}
