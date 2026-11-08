#include <stdio.h>
#include "config.h"
#include "utils.h"

int main(){
    int codigo, quantidade;
    float preco;
    char nome[TAM_NOME];

    codigo = lerIntMin("Codigo: ", 1);
    lerTexto("Nome: ", nome, TAM_NOME);
    preco = lerFloatMin("Preco: ", 0.0);
    quantidade = lerIntMin("Quantidade: ", 0);

    printf("%d - %s - R$ %.2f - %d un\n", codigo, nome, preco, quantidade);

    return 0;
}