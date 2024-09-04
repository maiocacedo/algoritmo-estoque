#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
>O QUE FAZER:
*- DECORAÇÃO
*- MENU DE OPÇÕES
*- CALCULO DE VENDAS
*- PRODUTO COM MAIOR QUANTIDADE
*- PRODUTO COM MENOR QUANTIDADE
*- SISTEMA DE DESCONTO
*- SANITIZAÇÃO DE INPUT
*- COMENTAR!!!!!!!!!!!!!!!!!!!!!!

>FEITO:
!- INSERÇÃO DE DADOS
!- CALCULO DE LUCRO
*/

// struct para definir um tipo de Produto
typedef struct
{
    char nome[50];
    float valor_compra;
    float valor_venda;
    int numero_vendas;
} Produto;

int main()
{
    int num_produtos;

    printf("Bem-vindo ao SEI (Sistema de Estoque Integrado)!\n\n");

    printf("Digite o número de produtos a ser inseridos: ");
    scanf("%d", &num_produtos);

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
}