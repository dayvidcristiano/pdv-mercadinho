#ifndef INTERFACE_H
#define INTERFACE_H

void limparTela(void);
void pausar(void);
void abrirTela(const char *titulo);
void exibirMenu(void);

void linhaBorda(void);
void linhaTexto(const char *texto);

void tabelaEstoqueCabecalho(void);
void tabelaEstoqueLinha(int codigo, const char *nome, float preco, int quantidade, const char *situacao);
void tabelaEstoqueRodape(void);

void tabelaCarrinhoCabecalho(void);
void tabelaCarrinhoLinha(const char *nome, int quantidade, float preco, float subtotal);
void tabelaCarrinhoTotal(float total);

#endif