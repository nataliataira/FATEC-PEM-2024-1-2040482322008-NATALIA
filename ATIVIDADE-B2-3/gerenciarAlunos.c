/*
Objetivo do programa: Gerenciar alunos de uma instituição.

Nome do programador: Natália Taira.

Data de criação: 24/05/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Aluno
{
    char    nome[50];
    double  notaFinal;
    char    situacao[10];
} Aluno;

char    *palavraMinuscula(char *str);
void    incluirAluno(Aluno aluno[], int posAluno);
void    listarAlunos(Aluno aluno[], int posAluno);
void    progAlunos(void);
        
int    main(void)
{
    progAlunos();
    return (0);
}

char    *palavraMinuscula(char *str)
{
    unsigned char *p = (unsigned char *)str;

    while (*p)
    {
        *p = tolower(*p);
        p++;
    }

    return str;
}


void    incluirAluno(Aluno aluno[], int posAluno)
{
    double  nota;

    printf("Digite o nome do aluno: ");
    fgets(aluno[posAluno].nome, sizeof(aluno[posAluno].nome), stdin);
    aluno[posAluno].nome[strcspn(aluno[posAluno].nome, "\n")] = 0;
    palavraMinuscula(aluno[posAluno].nome);

    while (1)
    {
        printf("Digite a nota final do aluno: ");
        scanf("%lf", &nota);
        if (nota > 10 || nota < 0)
        {
            fprintf(stderr, "Nota inválida\n");
            continue;
        }
        aluno[posAluno].notaFinal = nota;
        if (nota > 0 && nota <= 5)
        {
            strncpy(aluno[posAluno].situacao, "Reprovado",  sizeof(aluno[posAluno].situacao));
            break;
        }
        else if (nota > 5 && nota <= 10)
        {
            strncpy(aluno[posAluno].situacao, "Aprovado",  sizeof(aluno[posAluno].situacao));
            break;
        }
    }
}

void    listarAlunos(Aluno aluno[], int posAluno)
{
    Aluno   aux;
    int     pos2;
    int     pos = 0;

    while (pos < posAluno - 1)
    {
        pos2 = 0;
        while (pos2 < posAluno - 1 - pos)
        {
            if (strcmp(aluno[pos2].nome, aluno[pos2 + 1].nome) > 1)
            {
                aux = aluno[pos2];
                aluno[pos2] = aluno[pos2 + 1];
                aluno[pos2 + 1] = aux;
            }
            pos2++;
        }
        pos++;
    }

    printf("\nNome\t\tNota Final\ttSituação\n");

    pos = 0;
    
    while (pos < posAluno)
    {
        printf("%s\t%2.f\t\t%s\n", aluno[pos].nome, aluno[pos].notaFinal, aluno[pos].situacao);
        pos++;
    }
}

void    progAlunos(void)
{
    Aluno    aluno[50];
    int    opc = 0;
    int    posAluno = 0;

    while (opc != 3)
    {

        printf("\nMenu:\n(1) Incluir aluno\n(2)Listar alunos\n(3)Sair\n");
        scanf("%i", &opc);
        getchar();

        if (opc == 1)
        {
            incluirAluno(aluno, posAluno);
            posAluno++;
        }
        else if (opc == 2)
        {
            listarAlunos(aluno, posAluno);
        }
        else if (opc > 3 || opc < 1)
        {
            printf("Opção inválida\n");
        }
    }
}