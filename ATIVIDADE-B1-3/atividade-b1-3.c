#include <stdio.h>

#define LIN 8
#define COL 8

typedef struct  peca
{
    char    cor;
    char    *nome;
    char     num;
}   Peca;

void    camposVazios(Peca tabuleiro[LIN][COL])
{
    int     posLin = 2;
    int     posCol;

    while (posLin < LIN - 2)
    {
        posCol = 0;
        while (posCol < COL)
        {
            tabuleiro[posLin][posCol].cor = '-';
            tabuleiro[posLin][posCol].nome = "X";
            tabuleiro[posLin][posCol].num = '-';
            posCol++;
        }
        posLin++;
    }
}

// void    inserirPecas(Peca *tabuleiro[LIN][COL])
// {
//     if ()
// }

// void    printTabuleiro(Peca tabuleiro[LIN][COL])
// {
//     int     posLin = 0;
//     int     posCol;
//     int     num = 1;
    

//     while (posLin < LIN)
//     {
//         posCol = 0;
//         printf("%i ", num++);
//         while (posCol < COL)
//         {
//             printf("%c%s%c", tabuleiro[posLin][posCol].cor, tabuleiro[posLin][posCol].nome, tabuleiro[posLin][posCol].num);
//             posCol++;
//         }
//         printf("\n");
//         posLin++;
//     }
//     printf("   A  B  C  D  E  F  G  H\n");
// }

int main(void)
{
    Peca    tabuleiro[LIN][COL];

    camposVazios(tabuleiro);
    // inserirPecas(tabuleiro);
    // printTabuleiro(tabuleiro);
    printf("%c%s%c", tabuleiro[3][0].cor, tabuleiro[3][0].nome, tabuleiro[3][0].num);
    return (0);
}
