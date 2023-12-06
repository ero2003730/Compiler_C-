# Compilador da Linguagem C-

## Visão Geral
Este projeto apresenta um compilador para a linguagem C-, desenvolvido como parte do curso de Ciência da Computação. O compilador inclui um analisador léxico customizado, um analisador sintático usando Bison, e um analisador semântico com uma tabela de símbolos.

## Componentes do Compilador

### Analisador Léxico
- Desenvolvido do zero, o analisador léxico é responsável por decompor o código-fonte da linguagem C- em tokens, facilitando a análise sintática.

### Analisador Sintático
- Utiliza o Bison, uma ferramenta para a geração de analisadores sintáticos.
- Constrói uma árvore de análise sintática para representar a estrutura gramatical do código-fonte C-.

### Analisador Semântico
- Inclui uma tabela de símbolos para gerenciar os identificadores e seus atributos na linguagem C-.
- Realiza a verificação de tipos e escopos, assegurando a correção semântica do código.

## Instruções de Execução
Para executar o compilador da linguagem C-, siga os comandos abaixo:

- `make teste1`: Executa o compilador com 'Exemplo 1' de código C- como entrada.
- `make teste2`: Executa o compilador com 'Exemplo 2' de código C- como entrada.

Assegure-se de ter todas as dependências necessárias, incluindo o Bison e as ferramentas de compilação relacionadas.
