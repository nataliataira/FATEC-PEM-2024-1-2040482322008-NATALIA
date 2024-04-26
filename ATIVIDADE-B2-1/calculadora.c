#include <stdio.h>
#include <ctype.h>
#include <float.h>

void    calcular(void);
float   soma(float operador1, float operador2);
float   subtracao(float operador1, float operador2);
float multiplicacao(float operador1, float operador2);
float   divisao(float operador1, float operador2);

int main(void)
{
    calcular();
    return (0);
}

void    calcular(void)
{
    char    operacao = '0';
    int c;
    int     valido = 0;
    float   operadores[2] = {0, 0};
    float resultado = 0;

    printf("\nCALCULADORA!\n\n");

    while (operacao != 's')
    {

        printf("(1)Soma           (4)Divisão\n");
        printf("(2)Subtração      (S)Sair\n(3)Multiplicação\n\n");
        printf("Escolha a operação desejada: ");
        scanf("%c", &operacao);

        operacao = tolower(operacao);

        if (isalpha(operacao) && operacao != 's')
        {
            printf("Operação inválida.\n");
            continue;
        }
        else if (operacao == 's')
            return (0);

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

        switch (operacao)
        {
            case '1':
            {
                resultado = soma(operadores[0], operadores[1]);
                printf("%2.f + %2.f = %2.f\n\n", operadores[0], operadores[1], resultado);
                break;
            }
            case '2':
            {
                resultado = subtracao(operadores[0], operadores[1]);
                printf("%2.f - %2.f = %2.f\n\n", operadores[0], operadores[1], resultado);
                break;
            }
            case '3':
            {
                resultado = multiplicacao(operadores[0], operadores[1]);
                printf("%2.f * %2.f = %2.f\n\n", operadores[0], operadores[1], resultado);
                break;
            }
            case '4':
            {
                resultado = divisao(operadores[0], operadores[1]);
                printf("%2.f / %2.f = %2.f\n\n", operadores[0], operadores[1], resultado);
                break;
            }
            case 's':
                break;
            default:
                printf("Operação inválida.\n");
        }
        valido = 0;
    }
}

    

float   soma(float operador1, float operador2)
{
    float floatmax = FLT_MAX;
    float floatmin = FLT_MIN;

    if (operador1 > 0 && operador2 > 0 && operador1 > floatmax - operador2)
    {
        printf("Resultado da operação é grande demais, será mostrado o maior valor possível.\n");
        return floatmax;
    }
    else if (operador1 < 0 && operador2 < 0 && operador1 < floatmin - operador2)
    {
        printf("Resultado da operação é pequeno demais, será mostrado o menor valor possível.\n");
        return floatmin;
    }
    else
    {
        return operador1 + operador2;
    }
}

float   subtracao(float operador1, float operador2)
{
    float floatmax = FLT_MAX;

    if (operador1 > 0 && operador2 < 0 && operador1 > floatmax + operador2)
    {
        printf("Resultado da operação é grande demais, será mostrado o menor valor possível.\n");
        return floatmax;
    }
    else if (operador1 < 0 && operador2 > 0 && operador1 < -floatmax - operador2)
    {
        printf("Resultado da operação é pequeno demais, será mostrado o menor valor possível.\n");
        return -floatmax;
    }
    else
    {
        return operador1 - operador2;
    }
}

float multiplicacao(float operador1, float operador2)
{
    float floatmax = FLT_MAX;
    float floatmin = FLT_MIN;

    if (operador1 != 0 && operador2 != 0 && operador1 > floatmax / operador2)
    {
        printf("Resultado da operação é grande demais, será mostrado o maior valor possível.\n");
        return floatmax;
    }
    else if (operador1 != 0 && operador2 != 0 && operador1 < floatmin / operador2)
    {
        printf("Resultado da operação é pequeno demais, será mostrado o menor valor possível.\n");
        return floatmin;
    }
    else
    {
        return operador1 * operador2;
    }
}

float   divisao(float operador1, float operador2)
{
    float floatmax = FLT_MAX;
    float floatmin = FLT_MIN;

    if ((operador1 > 0 && operador2 < 0 && operador1 > -floatmin / operador2) ||
        (operador1 < 0 && operador2 > 0 && operador1 < -floatmin / operador2) ||
        (operador1 > 0 && operador2 > 0 && operador1 > floatmax / operador2) ||
        (operador1 < 0 && operador2 < 0 && operador1 < floatmax / operador2))
    {
        printf("Resultado da operação é grande demais, será mostrado o maior valor possível.\n");
        return floatmax;
    }
    else
    {
        return operador1 / operador2;
    }
}