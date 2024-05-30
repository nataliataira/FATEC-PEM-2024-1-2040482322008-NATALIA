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
#include <ctype.h>

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
        getchar();
        if (precoUnit < 0)
        {
            fprintf(stderr, "O Preço unitário deve ser um valor positivo. Tente novamente!\n");
            continue;
        }
        prod[qtdProd].precoUnit = precoUnit;
        break;
    }

    while (1)
    {
        printf("Digite a quantidade do produto: ");
        scanf("%i", &qtdProdIncl);
        getchar();
        if (qtdProdIncl < 0)
        {
            fprintf(stderr, "A quantidade deve ser um valor positivo. Tente novamente!\n");
            continue;
        }
        prod[qtdProd].qtdDisp = qtdProdIncl;
        break;
    }

    prod[qtdProd].id = qtdProd + 1;
    printf("Produto adicionado!");
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
            if (strcmp(prod[pos2].nome, prod[pos2 + 1].nome) > 0)
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

void    mostrarProdutos(Produto prod[], int qtdProd)
{
    int pos = 0;

    printf("\n__________________________________\n\n");
    printf("COMPRAS\n");
    printf("__________________________________\n\n");
    printf("CÓDIGO | NOME |DESCRIÇÃO | PREÇO | QUANTIDADE \n");
    printf("__________________________________\n\n");
    ordenarProdutos(prod, qtdProd);

    while (pos < qtdProd)
    {
        printf("%i\t%-10s\t%-20s\t%2.lf\t%i\t\n", prod[pos].id, prod[pos].nome, prod[pos].descricao, prod[pos].precoUnit, prod[pos].qtdDisp);
        printf("__________________________________\n\n");
        pos++;
    }
}

void    compra(Produto prod[], int qtdProd)
{
    Produto *aux;
    int     idProd = 0;
    int     qtdCompra = 0;

    mostrarProdutos(prod, qtdProd);
    while (1)
    {
        printf("Digite o código do produto que deseja comprar: ");
        scanf("%i", &idProd);
        getchar();
        if (idProd < 0 || idProd > qtdProd)
        {
            fprintf(stderr, "Produto inexistente. Tente novamente!\n");
            continue;
        }
        break;
    }

    while (1)
    {
        printf("Digite a quantidade que deseja comprar: ");
        scanf("%i", &qtdCompra);
        getchar();
        if (qtdCompra < 0)
        {
            fprintf(stderr, "O código do produto deve ser um valor válido. Tente novamente!\n");
            continue;
        }
        else if (prod[idProd - 1].qtdDisp < qtdCompra)
        {
            fprintf(stderr, "Há apenas %i únidades em estoque. Tente novamente!\n", prod[idProd - 1].qtdDisp);
            continue;
        }
        break;
    }

    aux = &prod[idProd - 1];
    aux->qtdDisp -= qtdCompra;
    printf("__________________________________\n\n");
    printf("NOME\t| PREÇO UN\t| PREÇO TOTAL\n\n");
    printf("%s\t%lf\t%lf\n", prod[qtdProd - 1].nome, prod[qtdProd - 1].precoUnit, (float)qtdCompra * prod[qtdProd - 1].precoUnit);
    printf("Compra realizada!\n");
    printf("__________________________________\n");
}


void    mainFunc(void)
{
    Produto prod[100];
    int     opc = 0;
    int     qtdProd = 0;

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
