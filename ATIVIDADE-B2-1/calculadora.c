/*
Objetivo do programa: Simular uma calculadora.

Nome do programador: Natália Taira.

Data de criação: 26/04/2024.
*/

#include <stdio.h>
#include <ctype.h>
#include <float.h>

int calcular(void);
void calcularOperacao(char operacao, float operadores[2]);

int main(void)
{
    while (calcular()) {}
    return 0;
}

int calcular(void)
{
    char operacao = '0';
    int c;
    int valido = 0;
    float operadores[2] = {0, 0};

    printf("\nCALCULADORA!\n\n");

    while (operacao != 's')
    {

        printf("(1)Soma           (4)Divisão\n");
        printf("(2)Subtração      (S)Sair\n(3)Multiplicação\n\n");
        printf("Escolha a operação desejada: ");
        scanf(" %c", &operacao); // Adicionando espaço antes de %c para ignorar espaços em branco

        operacao = tolower(operacao);

        if (isalpha(operacao) && operacao != 's')
        {
            printf("Operação inválida.\n");
            continue;
        }
        else if (operacao == 's')
            return 0;

        while (valido == 0)
        {
            printf("Digite o primeiro operador: ");
            scanf("%f", &operadores[0]);
            printf("Digite o segundo operador: ");
            scanf("%f", &operadores[1]);
            // Linha 50 está aqui apenas para limpar o buffer
            while ((c = getchar()) != '\n' && c != EOF);
            if (operacao != '4' && operadores[1] == 0)
            {
                printf("Não é possível dividir por zero. Por favor, escolha outro valor para o segundo operador.\n");
                continue;
            }
            valido = 1;
        }

        calcularOperacao(operacao, operadores);
        valido = 0;
    }

    return 1; // Retorna 1 para indicar que o usuário deseja continuar
}

void calcularOperacao(char operacao, float operadores[2])
{
    float resultado;

    switch (operacao)
    {
    case '1':
        resultado = operadores[0] + operadores[1];
        printf("%2.f + %2.f = %2.f\n\n", operadores[0], operadores[1], resultado);
        break;
    case '2':
        resultado = operadores[0] - operadores[1];
        printf("%2.f - %2.f = %2.f\n\n", operadores[0], operadores[1], resultado);
        break;
    case '3':
        resultado = operadores[0] * operadores[1];
        printf("%2.f * %2.f = %2.f\n\n", operadores[0], operadores[1], resultado);
        break;
    case '4':
        resultado = operadores[0] / operadores[1];
        printf("%2.f / %2.f = %2.f\n\n", operadores[0], operadores[1], resultado);
        break;
    case 's':
        printf("Saindo...\n");
        break;
    default:
        printf("Operação inválida.\n");
    }
}
