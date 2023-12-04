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

struct tabelaSimbolos *initTabela(char *scope, int dataType, char *ID, type typeId, int linha);

void initHash();

void pushTabela(type typeId, int dataType, char *ID, char *scope, int linha);

void addLine(struct tabelaSimbolos *item, int lineToAdd);

bool isDeclaracao(type nodeType);

bool isExpressao(type nodeType);

void imprimirTabela();

void searchTree(ASTNode *node, char *scope);

bool isValidType(type nodeType);

int buscarIgual(ASTNode *node, int position, char *scope);

struct tabelaSimbolos *procuraTabelaExp(char *ID, char *scope, type type);

void chamadaFunc(ASTNode *node, char *scope);

struct tabelaSimbolos *procuraTabela(char *ID, char *scope, type type);

void removeTabela();

struct tabelaSimbolos *searchTabela();

void freeTabela();

void printTabela();

unsigned longhash(char *str);
