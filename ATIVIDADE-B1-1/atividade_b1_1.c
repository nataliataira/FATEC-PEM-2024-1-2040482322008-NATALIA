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
        // Solicitada a quantidade de notas
        printf("Insira a quantidade de notas para a área \"%s\" (0 para sair): ", area[numArea]);
        scanf("%i", &numNotas);
        // Tratamento de erro
        if (numNotas == 0)
            return (0);
        else if (numNotas <= 2)
        {
            printf("O número de notas deve ser maior que 2\n");
        }
        else
        {
            // Alocação de memória para o array de float
            notas = (float *)malloc(sizeof(float) * numNotas);
            // Tratamento de erro da alocação
            if (!notas)
                return (1);
            // Armazenamento das notas na posição certa do array
            while (pos < numNotas)
            {
                printf("Insira a notas: ");
                scanf("%f", &notas[pos]);
                pos++;
            }
            /*
                Verificação do maior e menor valor simultaneamente à soma
                dos n elementos do array e a exclusão do maior e menor valor
                do array
            */
            pos = 0;
            maior = notas[0];
            menor = notas[0];
            somaNotas = 0;
            while (pos < numNotas)
            {
                somaNotas += notas[pos];
                if (notas[pos] < menor)
                    menor = notas[pos];
                else if (notas[pos] > maior)
                    maior = notas[pos];
                pos++;
            }
            somaNotas = somaNotas - (menor + maior);
            // Escrita da soma da nota no terminal
            printf("Nota de %s: %f\n", area[numArea], somaNotas);
            // Soma da nota de uma área com as áreas seguintes
            somaCandidato += somaNotas;
            // Incremento de variável da posição do array de áreas
            numArea++;
            // Zerando variável chave para controle do array
            pos = 0;
            // Liberação da memória alocada para o array
            free(notas);
            if (numArea == qtsAreas)
                printf("Nota Final do Candidato: %f\n", somaCandidato);
        }
    }
    return (0);
}
