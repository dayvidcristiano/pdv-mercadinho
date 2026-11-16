#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "produto.h"

int buscarProduto(int codigo);
void cadastrarProduto(void);
void entradaEstoque(void);
void listarEstoque(void);
void consultarProduto(void);

const Produto *obterProduto(int posicao);
void baixarEstoque(int posicao, int quantidade);
int produtoMaisVendido(void);
int listarEstoqueBaixo(void);

#endif