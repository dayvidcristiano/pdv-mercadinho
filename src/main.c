#include <stdio.h>
#include "utils.h"
#include "estoque.h"
#include "venda.h"
#include "relatorio.h"

int main(){
    int opcao;

    do {
        printf("\n.:: PDV Mercadinho ::.\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Dar entrada em estoque\n");
        printf("3 - Listar estoque\n");
        printf("4 - Consultar produto\n");
        printf("5 - Realizar venda\n");
        printf("6 - Relatorio do dia\n");
        printf("7 - Sair\n");
        opcao = lerInt("Opcao: ");

        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: entradaEstoque(); break;
            case 3: listarEstoque(); break;
            case 4: consultarProduto(); break;
            case 5: realizarVenda(); break;
            case 6: relatorioDia(); break;
            case 7: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 7);

    return 0;
}