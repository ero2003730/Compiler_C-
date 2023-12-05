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

typedef tabelaSimbolos *TABELA;

struct tabelaSimbolos *allocateTabela(char *scope, int dataType, char *ID, type typeId, int linha);

void initTabela();

void pushTabela(type typeId, int dataType, char *ID, char *scope, int linha);

void handleVarDeclaration(ASTNode *node, char *auxScope);

void handleFunctionDeclaration(ASTNode *node, char *auxScope);

void handleVarIdDeclaration(ASTNode *node, char *scope);

void handleVarVetDeclaration(ASTNode *node, char *scope);

void handleFunctionActivation(ASTNode *node, char *scope);

void handleExpression(ASTNode *node);

int verifyErrors(struct tabelaSimbolos *tabelaAux, struct ASTNode *node, struct ASTNode *auxNode, const char *scope);

void addLine(struct tabelaSimbolos *item, int lineToAdd);

bool isDeclaracao(type nodeType);

bool isExpressao(type nodeType);

void imprimirTabela();

void searchTree(ASTNode *node, char *scope);

bool isValidType(type nodeType);

int searchTabela(ASTNode *node, int position, char *scope);

struct tabelaSimbolos *procuraTabelaExp(char *ID, char *scope, type type);

void chamadaFunc(ASTNode *node, char *scope);

struct tabelaSimbolos *procuraTabela(char *ID, char *scope, type type);

void removeTabela();

void freeTabela();

void printSemanticTable();

unsigned getHash(char *str);
