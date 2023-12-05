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
    R_var_declaracao_vet = 5,
    R_tipo_especificador = 6,
    R_fun_declaracao = 7,
    R_params = 8,
    R_param_lista = 9,
    R_param_int = 10,
    R_param_vet = 11,
    R_composto_decl = 12,
    R_local_declaracoes = 13,
    R_statement_lista = 14,
    R_statement = 15,
    R_expressao_decl = 16,
    R_selecao_decl = 17,
    R_iteracao_decl = 18,
    R_retorno_decl_int = 19,
    R_retorno_decl_void = 20,
    R_expressao = 21,
    R_var_id = 22,
    R_var_vet = 23,
    R_simples_expressao = 24,
    R_relacional = 25,
    R_soma_expressao = 26,
    R_soma = 27,
    R_termo = 28,
    R_mult = 29,
    R_fator = 30,
    R_ativacao = 31,
    R_args = 32,
    R_arg_lista = 33
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

// Inicializa uma nova lista de lexemas
LexemaList *initLexemaList();

// Cria um novo nó na Árvore Sintática Abstrata (AST) com um tipo específico e informações de lexema
ASTNode *createNode(type nodeType, struct Lexema *lexemaInfo);

// Adiciona um nó irmão (sibling) a um nó existente na AST
void *addSibling(ASTNode *node, ASTNode *sibling);

// Adiciona um nó filho a um nó pai na AST
void *addSon(ASTNode *parent, ASTNode *son);

// Adiciona um lexema à lista de lexemas
void pushLexema(LexemaList *list, struct Lexema *lexema);

// Imprime a estrutura da Árvore Sintática Abstrata (AST)
void print_ast(ASTNode *root, int num);

// Libera a memória alocada para um nó da AST
void deallocateNode(ASTNode *node);

// Remove e retorna o lexema do topo da lista de lexemas (operação pop)
struct Lexema *popLexema(LexemaList *list);

// Executa a análise sintática (parsing) do programa
int parse();
