/*
Objetivo do programa: Identificar palavras palíndromas dentro de uma frase.
Nome do programador: Natália Taira e Cristian Daniel.
Data de criação: 15/03/2024
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char  frase[100];
    char  *palavra;
    int   tamPalavra;
    int   palindromo;
    int   i;

    palindromo = 0;

    printf("-------------------\n");
    printf("Digite uma frase: \n");
    fgets(frase, sizeof(frase), stdin);

    palavra = strtok(frase, " \n");

    printf("Palavras palindromo na frase: \n");

    while (palavra != NULL)
    {
        tamPalavra = strlen(palavra);
        for(i = 0; i < tamPalavra / 2; i++)
        {
            if (palavra[i] == palavra[tamPalavra - i - 1])
            {
                palindromo = 1;
            }
            else
            {
                palindromo = 0;
                break;
            }
        }

        if(palindromo == 1)
            printf("%s \n", palavra);

        palavra = strtok(NULL, " \n");
    }

    printf("-------------------");
    return 0;
}
