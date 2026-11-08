#include <stdio.h>
#include <string.h>
#include "produto.h"

int main(){
    Produto p;

    p.codigo = 1;
    strcpy(p.nome, "Arroz 5kg");
    p.preco = 25.90;
    p.quantidade = 10;
    p.totalVendido = 0;

    printf("%d - %s - R$ %.2f - %d un\n", p.codigo, p.nome, p.preco, p.quantidade);

    return 0;
}