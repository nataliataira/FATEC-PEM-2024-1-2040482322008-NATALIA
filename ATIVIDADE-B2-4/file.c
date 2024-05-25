/*
B2-4-Praticando Struct/Ponteiro
Instruções
Criar um programa em C que use ponteiros para manipular variáveis e funções.

Pede-se:
 O programa deve estar preparado para:

Inserir lista de produtos
Simular comprar on-line
Seleção de produto (por código)
Quantidade de produtos comprados
Finalizar venda
Mostrar lista de produtos na tela

No processo de inclusão de produtos, solicitar os dados para inclusão de produtos.

No processo de compra online, solicitar ao usuário que insira o código de produto.
Buscar na lista e, se não encontrar, dar mensagem "Produto Inexistente.

Para cada venda, solitar a quantidade de produtos que o comprador deseja.
Verificar se existe estoque para o produto.
Caso não existir, avisar ao encauto comprador.

para a opção de listar, mostrar a lista de produtos, em ordem alfabética de nome de produto.

*/

#include <stdio.h>
#include <string.h>

typedef struct produto
{
    int     id;
    char    nome[50];
    char    descricao[100];
    double  precoUnit;
    int     qtdDisp;
} Produto;

void    incluirProduto(Produto prod[], int qtdProd)
{
    double  precoUnit = 0.0;
    int     qtdProdIncl = 0;

    printf("\n__________________________________\n\n");
    printf("CADASTRO DE PRODUTO\n");
    printf("__________________________________\n");
    printf("\nDigite o nome do produto: ");
    fgets(prod[qtdProd].nome, sizeof(prod[qtdProd].nome), stdin);
    prod[qtdProd].nome[strcspn(prod[qtdProd].nome, "\n")] = 0;

    printf("Digite a descrição do produto: ");
    fgets(prod[qtdProd].descricao, sizeof(prod[qtdProd].descricao), stdin);
    prod[qtdProd].descricao[strcspn(prod[qtdProd].descricao, "\n")] = 0;

    while (1)
    {
        printf("Digite o preço unitário do produto: ");
        scanf("%lf", &precoUnit);
        if (precoUnit < 0)
        {
            fprintf(stderr, "Não são aceitos valores negativos\n");
            continue;
        }
        prod[qtdProd].precoUnit = precoUnit;
        break;
    }

    while (1)
    {
        printf("Digite a quantidade do produto: ");
        scanf("%i", &qtdProdIncl);
        if (qtdProdIncl < 0)
        {
            fprintf(stderr, "Não são aceitos valores negativos\n");
            continue;
        }
        prod[qtdProd].qtdDisp = qtdProdIncl;
        break;
    }
    prod[qtdProd].id = qtdProd + 1;
}

void    ordenarProdutos(Produto prod[], int qtdProd)
{
    Produto aux;
    int     pos2;
    int     pos = 0;

    while (pos < qtdProd - 1)
    {
        pos2 = 0;
        while (pos2 < qtdProd - 1 - pos)
        {
            if (strcmp(prod[pos2].nome, prod[pos2 + 1].nome) > 1)
            {
                aux = prod[pos2];
                prod[pos2] = prod[pos2 + 1];
                prod[pos2 + 1] = aux;
            }
            pos2++;
        }
        pos++;
    }
}

void    compra(Produto prod[], int qtdProd)
{
    int pos = 0;

    printf("\n__________________________________\n\n");
    printf("COMPRAS\n");
    printf("__________________________________\n\n");
    printf("NOME\t\t| DESCRIÇÃO\t\t\t| PREÇO UNIT.\t| QUANT.\n");
    printf("__________________________________\n\n");
    ordenarProdutos(prod, qtdProd);

    while (pos < qtdProd)
    {
        printf("%-15s\t%-40s\t%2.lf\t%i\n", prod[pos].nome, prod[pos].descricao, prod[pos].precoUnit, prod[pos].qtdDisp);
        printf("__________________________________\n\n");
        pos++;
    }
}

void    mainFunc(void)
{
    Produto prod[100];
    int     opc = 0;
    int     qtdProd;

    while (opc != 3)
    {
        printf("\n__________________________________\n");
        printf("\nINICIO\n");
        printf("__________________________________\n\n");
        printf("(1) Inserir um novo produto\n(2) Fazer uma compra\n(3) Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%i", &opc);
        getchar();

        if (opc == 1)
        {
            incluirProduto(prod, qtdProd);
            qtdProd++;
        }
        else if (opc == 2)
        {
            compra(prod, qtdProd);
        }
        else if (opc > 3 || opc < 1)
        {
            printf("Opção inválida\n");
        }
    }
}

int main(void)
{
    mainFunc();
    return (0);
}
