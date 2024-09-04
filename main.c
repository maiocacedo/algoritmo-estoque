#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
>O QUE FAZER:
*- DECORAÇÃO
*- MENU DE OPÇÕES
*- CALCULO DE VENDAS
*- SISTEMA DE DESCONTO
*- SANITIZAÇÃO DE INPUT
*- COMENTAR PELO AMOR DE DEUS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

>FEITO:
!- INSERÇÃO DE DADOS
!- CALCULO DE LUCRO
!- PRODUTO COM MAIOR QUANTIDADE
!- PRODUTO COM MENOR QUANTIDADE
*/

// struct para definir um tipo de Produto
typedef struct
{
    char nome[50];
    float valor_compra;
    float valor_venda;
    int numero_vendas;
    int numero_estoque;
} Produto;

int main()
{
    int num_produtos;

    printf("Bem-vindo ao SEI (Sistema de Estoque Integrado)!\n\n");
    
    printf("Digite o número de produtos a ser inseridos: ");
    scanf("%d", &num_produtos);
    while (num_produtos <= 0)
    {
        printf("Digite um número de produtos validos a ser inseridos: ");
        scanf("%d", &num_produtos);
    }
    

    // matriz de produtos de tipo Produto
    Produto produtos[num_produtos];

    for (int i = 0; i < num_produtos; i++)
    {
        printf("\nDigite as informações do produto %d:\n", i + 1);

        // definir as variáveis do struct
        printf(">Nome: ");
        scanf(" %[^\n]", produtos[i].nome);
        printf(">Valor de compra: ");
        scanf("%f", &produtos[i].valor_compra);
        printf(">Valor de venda: ");
        scanf("%f", &produtos[i].valor_venda);
        printf(">Número de vendas: ");
        scanf("%d", &produtos[i].numero_vendas);
        printf(">Quantidade em estoque: ");
        scanf("%d", &produtos[i].numero_estoque);
        while (produtos[i].numero_estoque < 0 || (produtos[i].numero_estoque == 0 && produtos[i].numero_vendas == 0))
        {
        printf("\n\nProduto invalido\nDigite novamente as informações do produto %d:\n", i + 1);

        // definir as variáveis do struct
        printf(">Nome: ");
        scanf(" %[^\n]", produtos[i].nome);
        printf(">Valor de compra: ");
        scanf("%f", &produtos[i].valor_compra);
        printf(">Valor de venda: ");
        scanf("%f", &produtos[i].valor_venda);
        printf(">Número de vendas: ");
        scanf("%d", &produtos[i].numero_vendas);
        printf(">Quantidade em estoque: ");
        scanf("%d", &produtos[i].numero_estoque);
        }
        
    }

    // define os produtos de maior e menor lucro e vendas
    Produto produto_maior_lucro = produtos[0];
    Produto produto_menor_lucro = produtos[0];
    Produto produto_maior_vendas = produtos[0];
    Produto produto_menor_vendas = produtos[0];

    // define o calculo de lucro
    float maior_lucro = produto_maior_lucro.valor_venda - produto_maior_lucro.valor_compra;
    float menor_lucro = maior_lucro;

    // calculo de lucro:
    for (int i = 0; i < num_produtos; i++)
    {
        // calculo do lucro do produto da iteração atual
        float lucro_atual = produtos[i].valor_venda - produtos[i].valor_compra;

        // se o lucro atual for maior que o lucro maior, ele substitui
        if (lucro_atual > maior_lucro)
        {
            maior_lucro = lucro_atual;
            produto_maior_lucro = produtos[i];
        }

        // se o lucro atual for menor que o lucro menor, ele substitui
        if (lucro_atual < menor_lucro)
        {
            menor_lucro = lucro_atual;
            produto_menor_lucro = produtos[i];
        }
    }

    
    int aux; // variavel auxiliar para mudar posicao
    int j; // indiceMudança
    
while (j != 0){

        // Definindo j = 0, ainda não ouve mudanças
        j = 0;

        // for para percorrer o vetor comparando os valores dos indices.
        for (int i = 0; i < num_produtos; i++){

            // Checando se o indice i e maior que o proximo indice
            if (produtos[i].numero_estoque > produtos[i+1].numero_estoque){

                // Trocando os indices de posição
                aux = produtos[i].numero_estoque;
                produtos[i].numero_estoque = produtos[i+1].numero_estoque;
                produtos[i+1].numero_estoque = aux;

                // Definindo j = 1, pois ouve mudanças
                j = 1;
            }
        }

    } 
    // exibindo o top 3 produtos com maior e menor estoque.
    if (num_produtos>= 3){
        printf("Menor quantidade: 1o %s: %d em estoque;\n 2o %s: %d em estoque;\n 3o %s: %d em estoque.\n\n", produtos[0].nome, produtos[0].numero_estoque,produtos[1].nome, produtos[1].numero_estoque,produtos[2].nome, produtos[2].numero_estoque);
        printf("Maior quantidade: 1o %s: %d em estoque;\n 2o %s: %d em estoque;\n 3o %s: %d em estoque.\n\n", produtos[num_produtos-1].nome,produtos[num_produtos-1].numero_estoque,produtos[num_produtos-2].nome, produtos[num_produtos-2].numero_estoque, produtos[num_produtos-3].nome,produtos[num_produtos-3].numero_estoque);
    }
    else if (num_produtos = 2){
        printf("Menor quantidade: 1o %s: %d em estoque;\n 2o %s %d em estoque;\n\n", produtos[0].nome, produtos[0].numero_estoque, produtos[1].nome,produtos[1].numero_estoque);
        printf("Maior quantidade: 1o %s: %d em estoque;\n 2o %s %d em estoque;\n\n", produtos[num_produtos-1].nome,produtos[num_produtos-1].numero_estoque,produtos[num_produtos-2].nome, produtos[num_produtos-2].numero_estoque);
    }
    else if (num_produtos < 2){
        printf("Menor quantidade: 1o %s: %d em estoque;\n\n", produtos[0].nome, produtos[0].numero_estoque);
        printf("Maior quantidade: 1o %s: %d em estoque.\n\n", produtos[num_produtos-1].nome, produtos[num_produtos-1].numero_estoque);
    }
}