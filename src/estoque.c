#include <stdio.h>
#include "config.h"
#include "produto.h"
#include "utils.h"
#include "estoque.h"

static Produto produtos[MAX_PRODUTOS];
static int totalProdutos = 0;

int buscarProduto(int codigo){
    int i;

    for (i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

void cadastrarProduto(void){
    Produto novo;

    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Estoque cheio! Limite de %d produtos.\n", MAX_PRODUTOS);
        return;
    }

    do {
        novo.codigo = lerIntMin("Codigo: ", 1);

        if (buscarProduto(novo.codigo) != -1) {
            printf("Codigo ja cadastrado! Digite outro.\n");
        }
    } while (buscarProduto(novo.codigo) != -1);

    lerTexto("Nome: ", novo.nome, TAM_NOME);
    novo.preco = lerFloatMin("Preco de venda: ", 0.0);
    novo.quantidade = lerIntMin("Quantidade inicial: ", 0);
    novo.totalVendido = 0;

    produtos[totalProdutos] = novo;
    totalProdutos++;

    printf("Produto cadastrado com sucesso!\n");
}