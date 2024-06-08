/*
Objetivo do programa: Refatorar algum programa desenvolvido.

Nome do programador: Natália Taira.

Data de criação: 07/06/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lerNumNotas(char *area)
{
    int numNotas;

    do
    {
        printf("Insira a quantidade de notas para a área \"%s\" (0 para sair): ", area);
        scanf("%d", &numNotas);
        getchar();

        if (numNotas == 0)
        {
            exit(0);
        }
        else if (numNotas <= 2)
        {
            printf("O número de notas deve ser maior que 2\n");
        }
    }
    while (numNotas <= 2);
    return (numNotas);
}

void    lerNotas(float *notas, int numNotas)
{
    printf("Insira as notas separadas por espaços: ");

    switch (numNotas)
    {
        case 3:
            scanf("%f %f %f", &notas[0], &notas[1], &notas[2]);
            break;
        case 4:
            scanf("%f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3]);
            break;
        case 5:
            scanf("%f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4]);
            break;
        case 6:
            scanf("%f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5]);
            break;
        case 7:
            scanf("%f %f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5], &notas[6]);
            break;
        case 8:
            scanf("%f %f %f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5], &notas[6], &notas[7]);
            break;
        case 9:
            scanf("%f %f %f %f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5], &notas[6], &notas[7], &notas[8]);
            break;
        case 10:
            scanf("%f %f %f %f %f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5], &notas[6], &notas[7], &notas[8], &notas[9]);
            break;
        default:
            printf("Número de notas não suportado\n");
            exit(1);
    }
}

float calcularSomaNotas(float *notas, int numNotas)
{
    float   maior = notas[0];
    float   menor = notas[0];
    float   somaNotas = 0;
    int     pos = 0;

    while (pos < numNotas)
    {
        if (notas[pos] > maior)
        {
            maior = notas[pos];
        }
        else if (notas[pos] < menor)
        {
            menor = notas[pos];
        }
        somaNotas += notas[pos];
        pos++;
    }

    somaNotas -= (menor + maior);
    return (somaNotas);
}

void    liberarMem(float *notas)
{
    free(notas);
}

void    calcNota(void)
{
    int     numNotas;
    int     pos = 0;
    float   somaCandidato = 0;
    float   somaNotas;
    float   *notas;
    char    *areas[] = { \
        "Raciocínio Lógico", \
        "Conceito de Gerenciamento de Projetos", \
        "Língua Inglesa", \
        "Conceito e Metodologia Ágil", \
        "Linguagem Javascript" \
    };

    int qtsAreas = sizeof(areas) / sizeof(areas[0]);

    while (pos < qtsAreas)
    {
        numNotas = lerNumNotas(areas[pos]);
        notas = (float *)malloc(numNotas * sizeof(float));

        if (notas == NULL)
        {
            printf("Erro de alocação de memória\n");
            exit(1);
        }

        lerNotas(notas, numNotas);
        somaNotas = calcularSomaNotas(notas, numNotas);
        printf("Nota de %s: %f\n", areas[pos], somaNotas);
        somaCandidato += somaNotas;
        liberarMem(notas);

        pos++;
    }
    printf("Nota Final do Candidato: %f\n", somaCandidato);
}

int main(void)
{
    calcNota();
    return (0);
}