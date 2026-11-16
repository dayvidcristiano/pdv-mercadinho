#include <stdio.h>
#include "config.h"
#include "produto.h"
#include "utils.h"
#include "estoque.h"
#include "venda.h"

typedef struct {
    int posicao;
    int quantidade;
} ItemCarrinho;

static int totalVendas = 0;
static float totalArrecadado = 0;

static int buscarNoCarrinho(const ItemCarrinho carrinho[], int totalItens, int posicao){
    int i;

    for (i = 0; i < totalItens; i++) {
        if (carrinho[i].posicao == posicao) {
            return i;
        }
    }

    return -1;
}

static int adicionarItem(ItemCarrinho carrinho[], int totalItens, int codigo){
    int posicao, indice, jaNoCarrinho, disponivel, quantidade;
    const Produto *p;

    posicao = buscarProduto(codigo);
    if (posicao == -1) {
        printf("Produto nao encontrado.\n");
        return totalItens;
    }

    indice = buscarNoCarrinho(carrinho, totalItens, posicao);
    if (indice == -1 && totalItens >= MAX_ITENS_VENDA) {
        printf("Carrinho cheio! Limite de %d itens diferentes.\n", MAX_ITENS_VENDA);
        return totalItens;
    }

    p = obterProduto(posicao);
    jaNoCarrinho = (indice == -1) ? 0 : carrinho[indice].quantidade;
    disponivel = p->quantidade - jaNoCarrinho;

    if (disponivel <= 0) {
        printf("%s sem estoque disponivel.\n", p->nome);
        return totalItens;
    }

    quantidade = lerIntMin("Quantidade: ", 1);
    if (quantidade > disponivel) {
        printf("Estoque insuficiente! Disponivel: %d\n", disponivel);
        return totalItens;
    }

    if (indice == -1) {
        carrinho[totalItens].posicao = posicao;
        carrinho[totalItens].quantidade = quantidade;
        totalItens++;
    } else {
        carrinho[indice].quantidade += quantidade;
    }

    printf("Adicionado: %d x %s\n", quantidade, p->nome);
    return totalItens;
}

static float exibirCarrinho(const ItemCarrinho carrinho[], int totalItens){
    int i;
    float subtotal, total = 0;
    const Produto *p;

    printf("\n%-30s %5s %10s %10s\n", "Produto", "Qtd", "Unitario", "Subtotal");

    for (i = 0; i < totalItens; i++) {
        p = obterProduto(carrinho[i].posicao);
        subtotal = carrinho[i].quantidade * p->preco;
        printf("%-30s %5d %10.2f %10.2f\n", p->nome, carrinho[i].quantidade, p->preco, subtotal);
        total += subtotal;
    }

    printf("TOTAL: R$ %.2f\n", total);
    return total;
}

void realizarVenda(void){
    ItemCarrinho carrinho[MAX_ITENS_VENDA];
    int totalItens = 0, codigo, i;
    float total, pago;

    printf("Nova venda. Digite 0 no codigo para finalizar.\n");

    do {
        codigo = lerInt("Codigo do produto: ");

        if (codigo != 0) {
            totalItens = adicionarItem(carrinho, totalItens, codigo);
        }
    } while (codigo != 0);

    if (totalItens == 0) {
        printf("Carrinho vazio. Venda cancelada.\n");
        return;
    }

    total = exibirCarrinho(carrinho, totalItens);

    do {
        pago = lerFloatMin("Valor pago (0 para cancelar a venda): ", 0.0);

        if (pago == 0 && total > 0) {
            printf("Venda cancelada.\n");
            return;
        }

        if (pago < total) {
            printf("Valor insuficiente! Faltam R$ %.2f\n", total - pago);
        }
    } while (pago < total);

    for (i = 0; i < totalItens; i++) {
        baixarEstoque(carrinho[i].posicao, carrinho[i].quantidade);
    }

    totalVendas++;
    totalArrecadado += total;

    printf("Troco: R$ %.2f\n", pago - total);
    printf("Venda finalizada!\n");
}

int quantidadeVendas(void){
    return totalVendas;
}

float valorArrecadado(void){
    return totalArrecadado;
}