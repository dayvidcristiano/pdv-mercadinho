#include <stdio.h>
#include "utils.h"
#include "estoque.h"

int main(){
    int opcao;

    do {
        printf("\n1 - Cadastrar produto\n");
        printf("2 - Dar entrada em estoque\n");
        printf("3 - Listar estoque\n");
        printf("4 - Consultar produto\n");
        printf("0 - Sair\n");
        opcao = lerInt("Opcao: ");

        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: entradaEstoque(); break;
            case 3: listarEstoque(); break;
            case 4: consultarProduto(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}