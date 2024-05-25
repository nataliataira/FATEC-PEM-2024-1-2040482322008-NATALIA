/*
B2-4-Praticando Struct/Ponteiro
Instruções
Criar um programa em C que use ponteiros para manipular variáveis e funções.

Cenário:
Você foi contratado para desenvolver um programa simples em C para uma loja de produtos eletrônicos. O programa deve ser capaz de armazenar uma lista de produtos eletrônicos (struct):
Id do produito
nome do produto
Descricao do produto
Preço Unitário
Quantide disponível em estoque.


Pede-se:
 O programa deve estar preparado para:

Inserir lista de produtos
Simular comprar on-line
Seleção de produto (por código)
Quantidade de produtos comprados
Finalizar venda
Mostrar lista de produtos na tela

No processo de inclusão de produtos, solicitar os dados para inclusão de produtos.

No processo de compra online, solicitar ao usuário que insira o código de produto. Buscar na lista e, se não encontrar, dar mensagem "Produto Inexistente.

Para cada venda, solitar a quantidade de produtos que o comprador deseja. Verificar se existe estoque para o produto. Caso não existir, avisar ao encauto comprador.

para a opção de listar, mostrar a lista de produtos, em ordem alfabética de nome de produto.

Requisitos técnicos:
Fazer programação modular
Fazer bubblesort (nao utilizar biblioteca) para classificar a lista por ordem ascendente  de nome do produto
.Usar ponteiros para passar valores para as funções e manipulação do array de produtos
O array de produtos deverá utilizado Struct.
Subir o código em seu repositório GitHub.
*/


typedef struct produto
{
    int     id;
    char    nome[50];
    char    descricao[100];
    double  precoUnit;
    int     quantDisponivel;
} Produto;