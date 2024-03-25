#include <stdio.h>
#include <stdlib.h>

#define QTDQUESTOES 10
#define QTDAREAS 5

int main(void)
{
    int     pos;
    int     numArea = 0;
    int     numNotas = 1;

    float   maiorNota;
    float   menorNota;
    float   somaNotas;
    float   somaCandidato = 0;
    float   notas[QTDQUESTOES];
    float   notaArea[QTDAREAS];

    char    *area[] = { \
        "Raciocínio Lógico", \
        "Conceito de Gerenciamento de Projetos", \
        "Língua Inglesa", \
        "Conceito e Metodologia Ágil", \
        "Linguagem Javascript" \
    };

    while (numNotas != 0 && numArea < QTDAREAS)
    {
        printf("Insira a quantidade de questões de %s: ", area[numArea]);
        scanf("%i", &numNotas);
        if (numNotas == 0)
            return (0);
        else if (numNotas <= 2 || numNotas > 10)
            printf("O número de questões deve ser maior que 2 e menor que 10\n");
        else
        {
            switch (numNotas)
            {
                case (3):
                {
                    printf("Digite a nota de cada questão separada por um espaço: ");
                    scanf("%f %f %f", &notas[0], &notas[1], &notas[2]);
                    break;
                }
                case (4):
                {
                    printf("Digite a nota de cada questão separada por um espaço: ");
                    scanf("%f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3]);
                    break;
                }
                case (5):
                {
                    printf("Digite a nota de cada questão separada por um espaço: ");
                    scanf("%f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4]);
                    break;
                }
                case (6):
                {
                    printf("Digite a nota de cada questão separada por um espaço: ");
                    scanf("%f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5]);
                    break;
                }
                case (7):
                {
                    printf("Digite a nota de cada questão separada por um espaço: ");
                    scanf("%f %f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5], &notas[6]);
                    break;
                }
                case (8):
                {
                    printf("Digite a nota de cada questão separada por um espaço: ");
                    scanf("%f %f %f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5], &notas[6], &notas[7]);
                    break;
                }
                case (9):
                {
                    printf("Digite a nota de cada questão separada por um espaço: ");
                    scanf("%f %f %f %f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5], &notas[6], &notas[7], &notas[8]);
                    break;
                };
                case (10):
                {
                    printf("Digite a nota de cada questão separada por um espaço: ");
                    scanf("%f %f %f %f %f %f %f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3], &notas[4], &notas[5], &notas[6], &notas[7], &notas[8], &notas[9]);
                    break;
                }
            }
            menorNota = notas[0];
            maiorNota = notas[0];
            pos = 0;
            somaNotas = 0;
            while (pos < numNotas)
            {
                somaNotas += notas[pos];
                if (notas[pos] < menorNota)
                    menorNota = notas[pos];
                else if (notas[pos] > maiorNota)
                    maiorNota = notas[pos];
                pos++;
            }
            somaNotas = somaNotas - (menorNota + maiorNota);
            notaArea[numArea] = somaNotas;
            somaCandidato += somaNotas;
            numArea++;
        }
    }
    numArea = 0;
    while (numArea < QTDAREAS)
    {
        printf("Nota de %s = %.2f\n", area[numArea], notaArea[numArea]);
        numArea++;
    }
    printf("Nota do Candidato = %.2f\n", somaCandidato);
    return (0);
}
