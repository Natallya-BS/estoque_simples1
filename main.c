#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

// Definindo a estrutura para armazenar os dados do produto
typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;



void adicionarProduto(Produto estoque[], int *quantidadeProdutos) {
    if (*quantidadeProdutos >= MAX_PRODUTOS) {
        printf("Estoque cheio! Não é possível adicionar mais produtos.\n");
        return;
    }
    Produto p;
    printf("Digite o nome do produto: ");
    scanf("%s", p.nome);
    printf("Digite a quantidade: ");
    scanf("%d", &p.quantidade);
    printf("Digite o preço: ");
    scanf("%f", &p.preco);

    estoque[*quantidadeProdutos] = p;
    (*quantidadeProdutos)++;
    printf("Produto adicionado com sucesso!\n");
}



void consultarEstoque(Produto estoque[], int quantidadeProdutos) {
    if (quantidadeProdutos == 0) {
        printf("O estoque está vazio!\n");
        return;
    }
    printf("\nEstoque Atual:\n");
    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("Produto: %s, Quantidade: %d, Preço: %.2f\n", estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
    }
}



void venderProduto(Produto estoque[], int *quantidadeProdutos) {
    char nomeProduto[50];
    int quantidadeVenda;

    printf("Digite o nome do produto a ser vendido: ");
    scanf("%s", nomeProduto);
    printf("Digite a quantidade a ser vendida: ");
    scanf("%d", &quantidadeVenda);

    int encontrado = 0;
    for (int i = 0; i < *quantidadeProdutos; i++) {
        if (strcmp(estoque[i].nome, nomeProduto) == 0) {
            if (estoque[i].quantidade >= quantidadeVenda) {
                estoque[i].quantidade -= quantidadeVenda;
                printf("Venda realizada com sucesso!\n");
            } else {
                printf("Quantidade insuficiente em estoque!\n");
            }
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado no estoque.\n");
    }
}


int main() {
    Produto estoque[MAX_PRODUTOS];
    int quantidadeProdutos = 0;
    int opcao;

    while (1) {
        printf("\nMenu de Gerenciamento de Estoque\n");
        printf("1. Adicionar produto\n");
        printf("2. Consultar estoque\n");
        printf("3. Vender produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(estoque, &quantidadeProdutos);
                break;
            case 2:
                consultarEstoque(estoque, quantidadeProdutos);
                break;
            case 3:
                venderProduto(estoque, &quantidadeProdutos);
                break;
            case 4:
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
}
