#include <stdio.h>
#include "produto.h"
#include "estoque.h"
#include "venda.h"
#include "interface.h"
#include "relatorio.h"

void relatorioDia(void){
    int posicao;
    char linha[100];
    const Produto *p;

    linhaBorda();

    snprintf(linha, sizeof(linha), "Vendas realizadas: %d", quantidadeVendas());
    linhaTexto(linha);

    snprintf(linha, sizeof(linha), "Total arrecadado: R$ %.2f", valorArrecadado());
    linhaTexto(linha);

    posicao = produtoMaisVendido();

    if (posicao == -1) {
        linhaTexto("Produto mais vendido: nenhum");
    } else {
        p = obterProduto(posicao);
        linhaTexto("Produto mais vendido:");
        snprintf(linha, sizeof(linha), "  %s (%d un)", p->nome, p->totalVendido);
        linhaTexto(linha);
    }

    linhaBorda();

    printf("\nAlerta de reposicao:\n");

    if (listarEstoqueBaixo() == 0) {
        printf("Nenhum produto com estoque baixo.\n");
    }
}