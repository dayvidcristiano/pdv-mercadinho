#include <stdio.h>
#include "produto.h"
#include "estoque.h"
#include "venda.h"
#include "relatorio.h"

void relatorioDia(void){
    int posicao;
    const Produto *p;

    printf("Vendas realizadas: %d\n", quantidadeVendas());
    printf("Total arrecadado: R$ %.2f\n", valorArrecadado());

    posicao = produtoMaisVendido();

    if (posicao == -1) {
        printf("Produto mais vendido: nenhuma venda realizada.\n");
    } else {
        p = obterProduto(posicao);
        printf("Produto mais vendido: %s (%d unidade(s))\n", p->nome, p->totalVendido);
    }
}