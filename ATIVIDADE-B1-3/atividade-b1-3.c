#include <stdio.h>
#include <stdlib.h>

#define LIN 8
#define COL 8

typedef struct  peca
{
    char    cor;
    char    nome;
    char    num;
}   Peca;

void    camposVazios(Peca tabuleiro[LIN][COL])
{
    int posLin = 2;
    int posCol;

    while (posLin < LIN - 2)
    {
        posCol = 0;
        while (posCol < COL)
        {
            tabuleiro[posLin][posCol].cor = '-';
            tabuleiro[posLin][posCol].nome = 'X';
            tabuleiro[posLin][posCol].num = '-';
            posCol++;
        }
        posLin++;
    }
}

void    defineCorPecas(Peca tabuleiro[LIN][COL])
{
    int posLin = 0;
    int posCol;

    while (posLin < LIN)
    {
        posCol = 0;
        while (posCol < COL)
        {
            if (posLin == 0 || posLin == 1)
                tabuleiro[posLin][posCol].cor = 'B';
            else if (posLin == 6 || posLin == 7)
                tabuleiro[posLin][posCol].cor = 'P';
            posCol++;
        }
        posLin++;
    }
}

void    posicaoPecas(Peca tabuleiro [LIN][COL])
{
    int     posLin = 0;
    int     posCol;
    char    pecas[8] = {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'};
    char    num[8] = {'1', '1', '1', '-', '-', '2', '2', '2'};
    char    numP[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};

    while (posLin < LIN)
    {
        posCol = 0;
        while (posCol < COL)
        {
            if (posLin == 0 || posLin == 7)
            {
                tabuleiro[posLin][posCol].nome = pecas[posCol];
                tabuleiro[posLin][posCol].num = num[posCol];
            }
            else if (posLin == 1 || posLin == 6)
            {
                tabuleiro[posLin][posCol].nome = 'P';
                tabuleiro[posLin][posCol].num = numP[posCol];
            }
            posCol++;
        }
        posLin++;
    }
}

void    inserirPecas(Peca tabuleiro[LIN][COL])
{
    defineCorPecas(tabuleiro);
    posicaoPecas(tabuleiro);
}

void    printTabuleiro(Peca tabuleiro[LIN][COL])
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
            printf(" %c%c%c ", tabuleiro[posLin][posCol].cor, \
            tabuleiro[posLin][posCol].nome, \
            tabuleiro[posLin][posCol].num);
            posCol++;
        }
        printf("\n");
        posLin++;
    }
    printf("    A    B    C    D    E    F    G    H\n");
}

int main(void)
{
    Peca    tabuleiro[LIN][COL];

    camposVazios(tabuleiro);
    inserirPecas(tabuleiro);
    printTabuleiro(tabuleiro);
    return (0);
}