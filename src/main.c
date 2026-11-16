#include <stdio.h>
#include "utils.h"
#include "interface.h"
#include "estoque.h"
#include "venda.h"
#include "relatorio.h"
#include <stdlib.h>

int main()
{
    int opcao;

    system("color 0A");
    system("title PDV Mercadinho");

    do
    {
        exibirMenu();
        opcao = lerInt("Opcao: ");

        switch (opcao)
        {
        case 1:
            abrirTela("CADASTRAR PRODUTO");
            cadastrarProduto();
            pausar();
            break;
        case 2:
            abrirTela("ENTRADA EM ESTOQUE");
            entradaEstoque();
            pausar();
            break;
        case 3:
            abrirTela("ESTOQUE");
            listarEstoque();
            pausar();
            break;
        case 4:
            abrirTela("CONSULTAR PRODUTO");
            consultarProduto();
            pausar();
            break;
        case 5:
            abrirTela("REALIZAR VENDA");
            realizarVenda();
            pausar();
            break;
        case 6:
            abrirTela("RELATORIO DO DIA");
            relatorioDia();
            pausar();
            break;
        case 7:
            printf("Encerrando...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            pausar();
        }
    } while (opcao != 7);

    return 0;
}