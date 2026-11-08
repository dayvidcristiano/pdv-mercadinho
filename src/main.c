#include <stdio.h>
#include "utils.h"
#include "estoque.h"

int main(){
    int codigo, posicao;

    cadastrarProduto();
    cadastrarProduto();

    codigo = lerInt("Buscar codigo: ");
    posicao = buscarProduto(codigo);

    if (posicao == -1) {
        printf("Produto nao encontrado.\n");
    } else {
        printf("Produto encontrado na posicao %d.\n", posicao);
    }

    return 0;
}