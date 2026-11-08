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

    // repete ate o codigo ser novo
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

static void exibirProduto(const Produto *p){
    printf("%-8d %-30s R$ %8.2f %6d", p->codigo, p->nome, p->preco, p->quantidade);

    if (p->quantidade < ESTOQUE_BAIXO) {
        printf("  <-- ESTOQUE BAIXO");
    }

    printf("\n");
}

void entradaEstoque(void){
    int codigo, posicao, quantidade;

    codigo = lerInt("Codigo do produto: ");
    posicao = buscarProduto(codigo);

    if (posicao == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    quantidade = lerIntMin("Quantidade recebida: ", 1);
    produtos[posicao].quantidade += quantidade;

    printf("Estoque atualizado! %s agora tem %d unidade(s).\n",
           produtos[posicao].nome, produtos[posicao].quantidade);
}

void listarEstoque(void){
    int i;

    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("%-8s %-30s %11s %6s\n", "Codigo", "Nome", "Preco", "Qtd");

    for (i = 0; i < totalProdutos; i++) {
        exibirProduto(&produtos[i]);
    }
}

void consultarProduto(void){
    int codigo, posicao;

    codigo = lerInt("Codigo do produto: ");
    posicao = buscarProduto(codigo);

    if (posicao == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("%-8s %-30s %11s %6s\n", "Codigo", "Nome", "Preco", "Qtd");
    exibirProduto(&produtos[posicao]);
}