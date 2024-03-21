#include <stdio.h>

#define LIN 8
#define COL 8

void    iniTabuleiro(char tabuleiro[LIN][COL])
{
    int     posLin = 0;
    int     posCol;

    while (posLin < LIN)
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

    while (posLin < LIN)
    {
        posCol = 0;
        while (posCol < COL)
        {
            printf(" %c ", tabuleiro[posLin][posCol]);
            posCol++;
        }
        printf("\n");
        posLin++;
    }
}

int main(void)
{
    char    tabuleiro[LIN][COL];

    iniTabuleiro(tabuleiro);
    printTabuleiro(tabuleiro);
    return (0);
}

/*
** 
**
*/