#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

extern struct ASTNode *raizDaArvore;
extern struct LexemaList *listLexema;
extern struct Lexema *idLexema, *numLexema, *intLexema, *ifLexema, *returnLexema;
extern struct Lexema *elseLexema, *voidLexema, *whileLexema;
extern struct Lexema *plusLexema, *minusLexema, *multiplyLexema, *divideLexema;
extern struct Lexema *equalsLexema, *gtLexema, *assignLexema;
extern struct Lexema *ltLexema, *leLexema, *geLexema, *netLexema;

typedef enum
{
    R_default = 0,
    R_programa = 1,
    R_declaracao_lista = 2,
    R_declaracao = 3,
    R_var_declaracao = 4,
    R_tipo_especificador = 5,
    R_fun_declaracao = 6,
    R_params = 7,
    R_param_lista = 8,
    R_param = 9,
    R_composto_decl = 10,
    R_local_declaracoes = 11,
    R_statement_lista = 12,
    R_statement = 13,
    R_expressao_decl = 14,
    R_selecao_decl = 15,
    R_iteracao_decl = 16,
    R_retorno_decl = 17,
    R_expressao = 18,
    R_var = 19,
    R_simples_expressao = 20,
    R_relacional = 21,
    R_soma_expressao = 22,
    R_soma = 23,
    R_termo = 24,
    R_mult = 25,
    R_fator = 26,
    R_ativacao = 27,
    R_args = 28,
    R_arg_lista = 29
} type;

typedef struct ASTNode
{
    type type;               // Tipo do nó (por exemplo, "operador", "identificador")
    struct Lexema *lexema;   // Ponteiro para o lexema associado (se houver)
    struct ASTNode *left;    // Primeiro filho
    struct ASTNode *middle;  // Segundo filho
    struct ASTNode *right;   // Terceiro filho
    struct ASTNode *sibling; // Irmão
} ASTNode;

typedef struct LexemaNode
{
    struct Lexema *lexema;   // Ponteiro para uma struct Lexema
    struct LexemaNode *next; // Ponteiro para o próximo nó na lista
} LexemaNode;

typedef struct LexemaList
{
    LexemaNode *top; // Ponteiro para o topo da lista
} LexemaList;

LexemaList *initLexemaList();                                  // Lista
void printTree(ASTNode *node);                                 // Função para imprimir a arvore
ASTNode *createNode(type nodeType, struct Lexema *lexemaInfo); // criar arvore
void *addSibling(ASTNode *node, ASTNode *sibling);             // ADICIONA IRMAO
void *addSon(ASTNode *parent, ASTNode *son);                   // filho
void pushLexema(LexemaList *list, struct Lexema *lexema);      // lista
void print_ast(ASTNode *root, int num);
void deallocateNode(ASTNode *node);
struct Lexema *popLexema(LexemaList *list); // pop
void analisadorSintatico();                 // print
int parse();                                // Parser