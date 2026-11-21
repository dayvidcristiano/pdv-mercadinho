# Roteiro de Testes - PDV Mercadinho

Os testes devem ser executados na ordem, sem reiniciar o programa, porque cada caso depende do estado deixado pelo anterior. O campo "Obtido" deve ser preenchido com o que o programa realmente mostrou.

## Preparação

Abra o programa e use a opção 1 para cadastrar:

| Código | Nome | Preço | Quantidade |
|---|---|---|---|
| 1 | Arroz 5kg | 25.90 | 10 |
| 2 | Feijao 1kg | 8.50 | 3 |
| 3 | Leite 1L | 5.00 | 20 |

## Caso 1: Listagem com alerta de estoque baixo

Entrada: opção 3.

Esperado: tabela com os 3 produtos. Somente o Feijao 1kg aparece com a situação BAIXO. Rodapé com "Total de produtos: 3".

Obtido:

## Caso 2: Cadastro com entradas inválidas

Entrada: opção 1, depois na ordem: código 1, código 4, nome com 36 caracteres (Sabao em po marca muito longa demais), nome Sabao, preço -5, preço 3.50, quantidade -1, quantidade 4.

Esperado: "Codigo ja cadastrado! Digite outro." para o código 1. "Texto invalido! Digite de 1 a 30 caracteres." para o nome longo. "Valor invalido! O minimo permitido e 0.00." para o preço negativo. "Valor invalido! O minimo permitido e 0." para a quantidade negativa. Ao final, "Produto cadastrado com sucesso!".

Obtido:

## Caso 3: Consulta de código inexistente

Entrada: opção 4, código 99.

Esperado: "Produto nao encontrado."

Obtido:

## Caso 4: Venda com código inexistente

Entrada: opção 5, código 99, depois código 0.

Esperado: "Produto nao encontrado." para o 99. Ao digitar 0, "Carrinho vazio. Venda cancelada."

Obtido:

## Caso 5: Venda com estoque insuficiente

Entrada: opção 5, código 2, quantidade 5, depois código 0.

Esperado: "Estoque insuficiente! Disponivel: 3". Ao digitar 0, "Carrinho vazio. Venda cancelada."

Obtido:

## Caso 6: Entrada em estoque

Entrada: opção 2, código 2, quantidade 10. Depois opção 3.

Esperado: "Estoque atualizado! Feijao 1kg agora tem 13 unidade(s)." Na listagem, o Feijao passa a aparecer como OK.

Obtido:

## Caso 7: Venda em dinheiro com valor pago insuficiente

Entrada: opção 5, código 2 quantidade 2, código 3 quantidade 4, código 0. Pagamento 1 (dinheiro). Valor pago 30, depois valor pago 40.

Esperado: carrinho com Feijao 1kg (2 x 8.50 = 17.00) e Leite 1L (4 x 5.00 = 20.00), TOTAL 37.00. "Desconto: -R$ 1.85" e "Total a pagar: R$ 35.15". Para o valor 30: "Valor insuficiente! Faltam R$ 5.15". Para o valor 40: "Troco: R$ 4.85" e "Venda finalizada!".

Obtido:

## Caso 8: Venda no cartão

Entrada: opção 5, código 1 quantidade 2, código 0. Pagamento 2 (cartão).

Esperado: TOTAL 51.80, sem desconto, sem pedir valor pago. "Total a pagar: R$ 51.80", "Troco: R$ 0.00" e "Venda finalizada!".

Obtido:

## Caso 9: Pagamento inválido e cancelamento de venda

Entrada: opção 5, código 1 quantidade 1, código 0. Pagamento 3, depois pagamento 1. Valor pago 0. Depois opção 3.

Esperado: "Opcao invalida!" para o pagamento 3. Ao informar 0 como valor pago, "Venda cancelada." Na listagem, o Arroz 5kg continua com 8 unidades (o estoque não foi alterado).

Obtido:

## Caso 10: Relatório do dia com alerta de reposição

Entrada: opção 6.

Esperado: "Vendas realizadas: 2". "Total arrecadado: R$ 86.95". Produto mais vendido: Leite 1L (4 un). Alerta de reposição listando o Sabao com quantidade 4 e situação BAIXO.

Obtido:

## Caso extra: Opção inválida no menu

Entrada: digitar 9 e depois a letra a no menu.

Esperado: "Opcao invalida!" para o 9. "Entrada invalida! Digite um numero inteiro." para a letra.

Obtido:
