/*
Objetivo do programa: Criar um programa que mostre um
tabuleiro de xadrez com as peças e cores das casas.
Nome do programador: Natália Taira.
Data de criação: 11/04/2024
*/

#include <stdio.h>

typedef struct s_peca
{
    char    cor;
    char    nome;
    char    num;
} t_peca;

typedef struct s_casaTab
{
    char    corCasa;
    t_peca  peca;
    int     estaVazio;
} t_tab;

void    inicTabuleiro(t_tab tabuleiro[][8], const int tamTab);
void    insCorCasas(t_tab tabuleiro[][8], const int tamTab);
void    inserirPecas(t_tab tabuleiro[][8], const int tamTab);
void    mostrarTabuleiro(t_tab tabuleiro[][8], const int tamTab);
void    headerTabuleiro(int jogada);

int main(void)
{
    const int tamTab = 8;
    int         jogada = 0;
    t_tab   tabuleiro[tamTab][tamTab];

    inicTabuleiro(tabuleiro, tamTab);
    headerTabuleiro(jogada);
    mostrarTabuleiro(tabuleiro, tamTab);

    return (0);
}

void    inicTabuleiro(t_tab tabuleiro[][8], const int tamTab)
{
    insCorCasas(tabuleiro, tamTab);
    inserirPecas(tabuleiro, tamTab);
}

void    insCorCasas(t_tab tabuleiro[][8], const int tamTab)
{
    int posLin = 0;
    int posCol;

    while (posLin < tamTab)
    {
        posCol = 0;
        while (posCol < tamTab)
        {
            if ((posLin + posCol) % 2 == 0)
            {
                tabuleiro[posCol][posLin].corCasa = '-'; //branco
                tabuleiro[posCol][posLin].estaVazio = 1;
            }
            else
            {
                tabuleiro[posCol][posLin].corCasa = 'x'; //preto
                tabuleiro[posCol][posLin].estaVazio = 1;
            }
            posCol++;
        }
        posLin++;
    }
}

void    inserirPecas(t_tab tabuleiro[][8], const int tamTab)
{
    char nmPeca[] = {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'};
    char nrPeca[] = {'1', '1', '1', ' ', ' ', '2', '2', '2'};
    char nrPeao[] = {'1', '2', '3', '4', '5', '6', '7', '8'};

    for (int col = 0; col < tamTab; ++col)
    {
        tabuleiro[0][col].peca.cor = 'P';
        tabuleiro[0][col].peca.nome = nmPeca[col];
        tabuleiro[0][col].peca.num = nrPeca[col];
        tabuleiro[0][col].estaVazio = 0;

        tabuleiro[1][col].peca.cor = 'P';
        tabuleiro[1][col].peca.nome = 'P';
        tabuleiro[1][col].peca.num = nrPeao[col];
        tabuleiro[1][col].estaVazio = 0;
    }

    for (int col = 0; col < tamTab; ++col)
    {
        tabuleiro[7][col].peca.cor = 'B';
        tabuleiro[7][col].peca.nome = nmPeca[col];
        tabuleiro[7][col].peca.num = nrPeca[col];
        tabuleiro[7][col].estaVazio = 0;

        tabuleiro[6][col].peca.cor = 'B';
        tabuleiro[6][col].peca.nome = 'P';
        tabuleiro[6][col].peca.num = nrPeao[col];
        tabuleiro[6][col].estaVazio = 0;
    }
}

void    mostrarTabuleiro(t_tab tabuleiro[][8], const int tamTab)
{
    int posLin = 0;
    int posCol;


    while (posLin < tamTab)
    {
        posCol = 0;
        printf("%i", tamTab - posLin);
        while (posCol < tamTab)
        {
            if (tabuleiro[posLin][posCol].estaVazio == 1)
            {
                printf("  %c  ", tabuleiro[posLin][posCol].corCasa);
                posCol++;
            }
            else
            {
                printf(" %c%c%c ", \
                tabuleiro[posLin][posCol].peca.cor, \
                tabuleiro[posLin][posCol].peca.nome, \
                tabuleiro[posLin][posCol].peca.num);
                posCol++;
            }
        }
        printf("\n");
        posLin++;
    }
    printf("   a    b    c    d    e    f    g    h\n\n");
}

void    headerTabuleiro(int jogada)
{
    if (jogada == 0)
    {
            printf("\n*****************************************\n");
            printf("*                                       *\n");
            printf("*     Posição inicial do tabuleiro!     *\n");
            printf("*                                       *\n");
            printf("*****************************************\n\n");
    }
    else
    {
        printf("\n*****************************************\n");
        printf("*                Jogada %i                *\n", jogada);
        printf("*****************************************\n\n");
    }
}


