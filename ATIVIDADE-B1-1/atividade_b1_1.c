/*
Objetivo do programa: Calcular a nota de candidatos à vaga de estágio.
Nome do programador: Natália Taira
Data de criação: 28/02/2024
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int     numNotas;
    int     pos;
    int     numArea;
    int     qtsAreas;
    float   maior;
    float   menor;
    float   *notas;
    float   somaNotas;
    float   somaCandidato;
    char *area[] = { \
        "Raciocínio Lógico", \
        "Conceito de Gerenciamento de Projetos", \
        "Língua Inglesa", \
        "Conceito e Metodologia Ágil", \
        "Linguagem Javascript" \
    };

    numNotas = 1;
    pos = 0;
    somaCandidato = 0;
    numArea = 0;
    qtsAreas = sizeof(area) / sizeof(area[0]);


    while (numNotas != 0 && numArea < qtsAreas)
    {
        printf("Insira a quantidade de notas para a área \"%s\" (0 para sair): ", area[numArea]);
        scanf("%i", &numNotas);
        if (numNotas == 0)
        {
            return (0);
        }
        else if (numNotas <= 2)
        {
            printf("O número de notas deve ser maior que 2\n");
        }
        else
        {
            switch (numNotas)
            {
                case (numNotas == 3)
                {
                    scanf("%f %f %f", &notas[0], &notas[1], &notas[2]);
                    break;
                }
                case (numNotas == 4)
                {
                    scanf("%f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3]);
                    break;
                }
                case (numNotas == 5)
                {
                    scanf("%f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4]);
                    break;
                }
                case (numNotas == 6)
                {
                    scanf("%f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4]);
                    break;
                }
                case (numNotas == 7)
                {
                    scanf("%f %f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4]);
                    break;
                }
                case (numNotas == 8)
                {
                    scanf("%f %f %f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4]);
                    break;
                }
                case (numNotas == 9)
                {
                    scanf("%f %f %f %f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4]);
                    break;
                }
                case (numNotas == 10)
                {
                    scanf("%f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4]);
                    break;
                }
                
            }
            while (pos < numNotas)
            {
                printf("Insira a notas: ");
                scanf("%f", &notas[pos]);
                pos++;
            }
            pos = 0;
            maior = notas[0];
            menor = notas[0];
            somaNotas = 0;
            while (pos < numNotas)
            {
                somaNotas += notas[pos];
                if (notas[pos] < menor)
                {
                    menor = notas[pos];
                }
                else if (notas[pos] > maior)
                {
                    maior = notas[pos];
                }
                pos++;
            }
            somaNotas = somaNotas - (menor + maior);
            printf("Nota de %s: %f\n", area[numArea], somaNotas);
            somaCandidato += somaNotas;
            numArea++;
            pos = 0;
            free(notas);
            if (numArea == qtsAreas)
            {
                printf("Nota Final do Candidato: %f\n", somaCandidato);
            }
        }
    }
    return (0);
}
