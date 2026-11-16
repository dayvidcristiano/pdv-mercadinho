#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

#define LARGURA 44

static const int COLS_ESTOQUE[5] = {6, 30, 11, 5, 8};
static const int COLS_CARRINHO[4] = {30, 5, 11, 11};

static void repetir(char c, int n){
    int i;

    for (i = 0; i < n; i++) {
        printf("%c", c);
    }
}

// Borda de tabela: +------+------+
static void bordaTabela(const int larguras[], int colunas){
    int i;

    printf("+");
    for (i = 0; i < colunas; i++) {
        repetir('-', larguras[i] + 2);
        printf("+");
    }
    printf("\n");
}

void linhaBorda(void){
    printf("+");
    repetir('=', LARGURA - 2);
    printf("+\n");
}

void linhaTexto(const char *texto){
    printf("| %-*.*s |\n", LARGURA - 4, LARGURA - 4, texto);
}

static void linhaCentro(const char *texto){
    int tam = strlen(texto);
    int esquerda = (LARGURA - 2 - tam) / 2;
    int direita = LARGURA - 2 - tam - esquerda;

    printf("|%*s%s%*s|\n", esquerda, "", texto, direita, "");
}

void limparTela(void){
    system("cls");
}

void pausar(void){
    char linha[10];

    printf("\nPressione ENTER para continuar...");
    fgets(linha, sizeof(linha), stdin);
}

void abrirTela(const char *titulo){
    limparTela();
    linhaBorda();
    linhaCentro(titulo);
    linhaBorda();
    printf("\n");
}

void exibirMenu(void){
    limparTela();
    linhaBorda();
    linhaCentro("PDV MERCADINHO");
    linhaBorda();
    linhaTexto("[1] Cadastrar produto");
    linhaTexto("[2] Dar entrada em estoque");
    linhaTexto("[3] Listar estoque");
    linhaTexto("[4] Consultar produto");
    linhaTexto("[5] Realizar venda");
    linhaTexto("[6] Relatorio do dia");
    linhaTexto("[7] Sair");
    linhaBorda();
}

void tabelaEstoqueCabecalho(void){
    bordaTabela(COLS_ESTOQUE, 5);
    printf("| %-6s | %-30s | %11s | %5s | %-8s |\n", "Codigo", "Nome", "Preco", "Qtd", "Situacao");
    bordaTabela(COLS_ESTOQUE, 5);
}

void tabelaEstoqueLinha(int codigo, const char *nome, float preco, int quantidade, const char *situacao){
    printf("| %-6d | %-30s | R$ %8.2f | %5d | %-8s |\n", codigo, nome, preco, quantidade, situacao);
}

void tabelaEstoqueRodape(void){
    bordaTabela(COLS_ESTOQUE, 5);
}

void tabelaCarrinhoCabecalho(void){
    bordaTabela(COLS_CARRINHO, 4);
    printf("| %-30s | %5s | %11s | %11s |\n", "Produto", "Qtd", "Unitario", "Subtotal");
    bordaTabela(COLS_CARRINHO, 4);
}

void tabelaCarrinhoLinha(const char *nome, int quantidade, float preco, float subtotal){
    printf("| %-30s | %5d | R$ %8.2f | R$ %8.2f |\n", nome, quantidade, preco, subtotal);
}

void tabelaCarrinhoTotal(float total){
    bordaTabela(COLS_CARRINHO, 4);
    printf("| %-30s | %5s | %11s | R$ %8.2f |\n", "TOTAL", "", "", total);
    bordaTabela(COLS_CARRINHO, 4);
}