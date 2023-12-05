#include "sintatical.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
extern struct tabelaSimbolos **tabela;

typedef struct tabelaSimbolos
{
    char *ID;         // Nome do ID
    char *scope;      // Escopo do ID
    type typeId;      // Tipo do ID (por exemplo, função, variável)
    int dataType;     // Tipo de Dados (por exemplo, int, void, 0 ou 1)
    int *lineNumbers; // Linhas onde o ID aparece
    int lineCount;    // Contagem de linhas
    struct tabelaSimbolos *next, *last;
} tabelaSimbolos;

// Aloca um novo símbolo na tabela de símbolos
struct tabelaSimbolos *allocateTabela(char *scope, int dataType, char *ID, type typeId, int linha);

// Inicializa a tabela de símbolos
void initTabela(void);

// Adiciona um novo símbolo à tabela de símbolos no índice especificado
void addNewSymbolToTable(int indice, char *escopo, int tipoDados, char *identificador, type tipoId, int numeroLinha);

// Verifica e adiciona uma linha à entrada existente na tabela de símbolos
bool checkAndAddLine(int indice, char *identificador, char *escopo, int numeroLinha);

// Insere um símbolo na tabela de símbolos
void pushTabela(type tipoId, int tipoDados, char *identificador, char *escopo, int numeroLinha);

// Calcula o valor hash para uma string, usado para indexação na tabela de símbolos
unsigned getHash(char *str);

// Adiciona uma linha à lista de linhas de um símbolo na tabela
void addLine(struct tabelaSimbolos *tabela, int lineToAdd);

// Verifica se um tipo de nó é uma declaração
bool isDeclaracao(type nodeType);

// Verifica se um tipo de nó é uma expressão
bool isExpressao(type nodeType);

// Pesquisa na AST e realiza ações baseadas no escopo atual
void searchTree(ASTNode *node, char *scope);

// Verifica se um tipo é válido
bool isValidType(type nodeType);

// Procura na tabela de símbolos por declarações de funções
struct tabelaSimbolos *procurarNaTabelaParaDeclaracaoFuncao(ASTNode *auxNode);

// Procura na tabela de símbolos para outros casos que não sejam declaração de funções
struct tabelaSimbolos *procurarNaTabelaParaOutrosCasos(ASTNode *auxNode, char *scope);

// Pesquisa na tabela de símbolos e retorna o resultado da pesquisa
int searchTabela(ASTNode *node, int position, char *scope);

// Verifica erros relacionados à tabela de símbolos
int verifyErrors(struct tabelaSimbolos *tabelaAux, struct ASTNode *node, struct ASTNode *auxNode, const char *scope);

// Obtém o nome do tipo a partir de um typeId
const char *getTypeName(type typeId);

// Obtém o nome do tipo de dados a partir de um dataType
const char *getDataTypeName(int dataType);

// Imprime a tabela semântica
void printSemanticTable(void);

// Libera a memória alocada para a tabela de símbolos
void freeTabela(void);

// Libera a memória alocada para o escopo auxiliar
void freeAuxScope(char *auxScope);

// Lida com a declaração de variáveis
void handleVarDeclaration(ASTNode *node, char *scope);

// Processa os parâmetros de uma função
void processarParametrosFuncao(ASTNode *node, char *auxScope);

// Lida com a declaração de funções
void handleFunctionDeclaration(ASTNode *node, char *auxScope);

// Procura por declarações existentes na tabela de símbolos
struct tabelaSimbolos *procurarDeclaracaoExistente(ASTNode *node, char *scope, type typeDeclara);

// Trata uma declaração ou um erro encontrado na tabela de símbolos
void tratarDeclaracaoOuErro(struct tabelaSimbolos *tabelaAux, ASTNode *node);

// Verifica o uso correto de variáveis em funções
void verificarUsoEmFuncao(ASTNode *node, unsigned int indice);

// Lida com a declaração de identificadores de variáveis
void handleVarIdDeclaration(ASTNode *node, char *scope);

// Lida com a declaração de vetores
void handleVarVetDeclaration(ASTNode *node, char *scope);

// Lida com a ativação de funções
void handleFunctionCall(struct ASTNode *node, char *scope);

// Lida com a verificação de identificadores de variáveis
void handleVarID(struct ASTNode *node, char *scope);

// Lida com a ativação de funções
void handleFunctionActivation(ASTNode *node, char *scope);

// Lida com a expressão em um nó da AST
void handleExpression(ASTNode *node);
