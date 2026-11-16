## PDV Mercadinho
 
Sistema de ponto de venda (PDV) para um mercadinho de bairro, desenvolvido em linguagem C e executado no terminal. O programa controla o cadastro de produtos, a entrada de mercadorias no estoque e a venda de vários itens em uma mesma compra, com cálculo de total e troco.
 
Trabalho prático da disciplina Programação Imperativa e Funcional (PIF), do curso de Análise e Desenvolvimento de Sistemas da CESAR School.
 
Todos os dados ficam apenas na memória durante a execução. Nenhuma informação é salva em arquivo, então ao encerrar o programa o estoque e as vendas são perdidos.
 
## Funcionalidades
 
1. Cadastrar produto (código, nome, preço e quantidade inicial), sem permitir código repetido, preço negativo ou quantidade negativa.
2. Dar entrada em estoque de um produto já cadastrado.
3. Listar estoque, destacando produtos com menos de 5 unidades.
4. Consultar produto por código.
5. Realizar venda com vários itens, validação de estoque, subtotal por item, total, valor pago, troco e baixa no estoque.
6. Relatório do dia com quantidade de vendas, valor arrecadado e produto mais vendido.
7. Sair.
## Tecnologias
 
- Linguagem C
- GCC (MinGW/MSYS2) como compilador
- Git e GitHub para controle de versão
## Pré-requisitos
 
- Git instalado
- GCC instalado
Para verificar:
```
gcc --version
git --version
```
 
## Como baixar
 
```
git clone https://github.com/dayvidcristiano/pdv-mercadinho.git
cd pdv-mercadinho
```
 
## Como compilar e executar
 
Na pasta raiz do projeto:
 
```
gcc src\*.c -Iinclude -o build\pdv.exe
build\pdv.exe
```
 
O parâmetro `-Iinclude` informa ao compilador onde estão os arquivos de cabeçalho (`.h`). Caso o `src\*.c` não funcione no seu terminal, liste os arquivos manualmente:
 
```
gcc src\main.c src\estoque.c src\venda.c src\relatorio.c src\utils.c src\interface.c -Iinclude -o build\pdv.exe
```
 
## Como usar
 
Ao iniciar, o programa mostra o menu principal:
 
```
+==========================================+
|              PDV MERCADINHO              |
+==========================================+
| [1] Cadastrar produto                    |
| [2] Dar entrada em estoque               |
| [3] Listar estoque                       |
| [4] Consultar produto                    |
| [5] Realizar venda                       |
| [6] Relatorio do dia                     |
| [7] Sair                                 |
+==========================================+
```
 
Digite o número da opção desejada e siga as instruções na tela. O menu só encerra quando a opção 7 é escolhida.
 
Fluxo sugerido para o primeiro uso:
 
1. Cadastre alguns produtos (opção 1).
2. Confira o estoque (opção 3).
3. Faça uma venda (opção 5). Digite o código e a quantidade de cada item e use o código 0 para finalizar a compra.
4. Informe o valor pago e confira o troco.
5. Consulte o relatório do dia (opção 6).
## Organização das pastas
 
```
pdv-mercadinho/
├── include/
│   ├── config.h
│   ├── produto.h
│   ├── estoque.h
│   ├── venda.h
│   ├── relatorio.h
│   ├── interface.h
│   └── utils.h
├── src/
│   ├── main.c
│   ├── estoque.c
│   ├── venda.c
│   ├── relatorio.c
│   ├── interface.c
│   └── utils.c
├── build/
├── docs/
└── README.md
```
 
O projeto é dividido em módulos, cada um com um arquivo de cabeçalho (`.h`, que declara o que o módulo oferece) e um arquivo de código (`.c`, que implementa).
 
| Módulo | Responsabilidade |
|---|---|
| main | Menu principal e controle do fluxo do programa |
| config | Constantes do sistema (limites e estoque baixo) |
| produto | Definição da struct Produto |
| estoque | Cadastro, entrada, listagem, consulta e busca de produtos |
| venda | Carrinho, validações, total, troco e baixa no estoque |
| relatorio | Relatório do dia |
| interface | Menu estilizado, limpeza de tela e telas de título |
| utils | Leitura de dados com validação (inteiros, reais e textos) |
 
A pasta `build` guarda o executável gerado na compilação e não é versionada. A pasta `docs` guarda o relatório e o roteiro de testes.
 
## Decisões de projeto
 
- O vetor de produtos fica dentro do módulo `estoque` e é acessado apenas por funções, para que os outros módulos não alterem os dados diretamente.
- Toda leitura do teclado passa pelo módulo `utils`, que usa `fgets` e `sscanf` para validar a entrada e evitar travamentos quando o usuário digita letras no lugar de números.
- Na venda, o estoque só é alterado depois que o pagamento é aceito, então cancelar uma venda não afeta os produtos.
- O carrinho considera as unidades do mesmo produto já adicionadas, impedindo vender mais do que existe no estoque.
## Limites do sistema
 
- Até 50 produtos cadastrados
- Até 20 itens diferentes por venda
- Nome do produto com até 30 caracteres
Os valores podem ser alterados no arquivo `include/config.h`.
 
## Autor
 
Dayvid Cristiano, responsável por todo o desenvolvimento: arquitetura, código, testes e documentação.
 
