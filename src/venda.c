#include <stdio.h>
#include "config.h"
#include "produto.h"
#include "utils.h"
#include "interface.h"
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

    printf("\n");
    tabelaCarrinhoCabecalho();

    for (i = 0; i < totalItens; i++) {
        p = obterProduto(carrinho[i].posicao);
        subtotal = carrinho[i].quantidade * p->preco;
        tabelaCarrinhoLinha(p->nome, carrinho[i].quantidade, p->preco, subtotal);
        total += subtotal;
    }

    tabelaCarrinhoTotal(total);
    return total;
}

void realizarVenda(void){
    ItemCarrinho carrinho[MAX_ITENS_VENDA];
    int totalItens = 0, codigo, i, forma;
    float total, desconto, pago;

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
        forma = lerInt("Pagamento (1 = Dinheiro com 5% de desconto | 2 = Cartao): ");

        if (forma != 1 && forma != 2) {
            printf("Opcao invalida!\n");
        }
    } while (forma != 1 && forma != 2);

    if (forma == 1) {
        desconto = total * DESCONTO_DINHEIRO;
        desconto = (int)(desconto * 100 + 0.5) / 100.0;
        total -= desconto;
        printf("Desconto: -R$ %.2f\n", desconto);
    }

    total = (int)(total * 100 + 0.5) / 100.0;
    printf("Total a pagar: R$ %.2f\n", total);

    if (forma == 1) {
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
    } else {
        pago = total;
    }

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