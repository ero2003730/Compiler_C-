#include "../h/funcs.h"

struct ASTNode *raizDaArvore = NULL;
LexemaList *listLexema = NULL;

struct Lexema *idLexema, *numLexema, *intLexema, *ifLexema, *returnLexema;
struct Lexema *elseLexema, *voidLexema, *whileLexema;
struct Lexema *plusLexema, *minusLexema, *multiplyLexema, *divideLexema;
struct Lexema *equalsLexema, *gtLexema, *assignLexema;
struct Lexema *ltLexema, *leLexema, *geLexema, *netLexema;

LexemaList *initLexemaList()
{
    LexemaList *list = (LexemaList *)malloc(sizeof(LexemaList));
    if (list == NULL)
    {
        // Erro de alocação de memória
        return NULL;
    }

    list->top = NULL;
    return list;
}

void pushLexema(LexemaList *list, struct Lexema *lexema)
{
    if (list == NULL || lexema == NULL)
    {

        return;
    }

    LexemaNode *newNode = (LexemaNode *)malloc(sizeof(LexemaNode));
    if (newNode == NULL)
    {
        // Erro de alocação de memória
        return;
    }

    newNode->lexema = lexema;
    newNode->next = list->top;
    list->top = newNode;

    // printf("Lista lexema é: %s\n", newNode->lexema->lexemaBuffer);
}

struct Lexema *popLexema(LexemaList *list)
{
    if (list == NULL || list->top == NULL)
    {
        return NULL;
    }

    LexemaNode *nodeToRemove = list->top;
    struct Lexema *lexema = nodeToRemove->lexema;
    list->top = nodeToRemove->next;
    // printf("Pop lexema é: %s\n", nodeToRemove->lexema->lexemaBuffer);
    free(nodeToRemove);

    return lexema; // Retorna o ponteiro para o lexema desempilhado
}

ASTNode *createNode(type nodeType, struct Lexema *lexemaInfo)
{
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));

    if (node == NULL)
    {
        // Erro de alocação de memória
        return NULL;
    }

    node->type = nodeType;

    node->lexema = lexemaInfo;
    node->left = NULL;
    node->middle = NULL;
    node->right = NULL;
    node->sibling = NULL;

    return node;
}

void *addSibling(ASTNode *node, ASTNode *sibling)
{
    if (node == NULL)
    {
        printf("addSibling chamado com node NULL\n");
        return NULL;
    }

    // Percorre os irmãos até encontrar o último
    while (node->sibling != NULL)
    {
        node = node->sibling;
    }

    node->sibling = sibling;

    // printf("Adicionando irmão. Node Tipo = %d, Sibling Tipo = %d\n", node->type, sibling->type);
}

void *addSon(ASTNode *parent, ASTNode *son)
{
    if (parent == NULL)
    {
        return NULL;
    }

    if (son == NULL)
    {
        return NULL;
    }

    // printf("Adicionando filho. Parent Tipo = %d, Son Tipo = %d\n", parent->type, son->type);

    // Adiciona sempre ao filho esquerdo se estiver vazio
    if (parent->left == NULL)
    {
        parent->left = son;
    }
    // Se o esquerdo não estiver vazio, mas o meio estiver, adiciona ao meio
    else if (parent->middle == NULL)
    {
        parent->middle = son;
    }
    // Se nem o esquerdo nem o meio estiverem vazios, adiciona ao direito
    else if (parent->right == NULL)
    {
        parent->right = son;
    }

    return parent;
}

void print_ast(ASTNode *root, int num)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < num; i++)
    {
        printf("\t");
    }
    printf("%s\n", root->lexema->lexemaBuffer);

    print_ast(root->left, num + 1);
    print_ast(root->middle, num + 1);
    print_ast(root->right, num + 1);
    print_ast(root->sibling, num);
}

void deallocateNode(ASTNode *node)
{
    if (node == NULL)
    {
        return;
    }

    // Desaloca recursivamente os filhos
    deallocateNode(node->left);
    deallocateNode(node->middle);
    deallocateNode(node->right);

    // Desaloca recursivamente os irmãos
    deallocateNode(node->sibling);

    // Finalmente, desaloca o próprio nó
    free(node);
}