#include "../h/funcs.h"

struct ASTNode *raizDaArvore = NULL;
LexemaList *listLexema = NULL;

struct Lexema *idLexema, *numLexema, *intLexema, *ifLexema, *returnLexema;
struct Lexema *elseLexema, *voidLexema, *whileLexema;
struct Lexema *plusLexema, *minusLexema, *multiplyLexema, *divideLexema;
struct Lexema *equalsLexema, *gtLexema, *assignLexema;
struct Lexema *ltLexema, *leLexema, *geLexema, *netLexema;

// Função para inicializar uma lista de lexemas
LexemaList *initLexemaList()
{
    // Aloca memória para uma nova lista de lexemas
    LexemaList *list = (LexemaList *)malloc(sizeof(LexemaList));

    // Verifica se a alocação de memória foi bem-sucedida
    if (list == NULL)
    {
        // Em caso de falha na alocação de memória, retorna NULL
        return NULL;
    }

    // Inicializa o topo da lista como NULL, indicando que a lista está vazia
    list->top = NULL;

    // Retorna o ponteiro para a lista de lexemas recém-criada
    return list;
}

// Função para adicionar um lexema à lista de lexemas
void pushLexema(LexemaList *list, struct Lexema *lexema)
{
    // Verifica se a lista ou o lexema a ser adicionado são nulos
    if (list == NULL || lexema == NULL)
    {
        // Se qualquer um deles for nulo, a função retorna sem fazer nada
        return;
    }

    // Aloca memória para um novo nó na lista de lexemas
    LexemaNode *newNode = (LexemaNode *)malloc(sizeof(LexemaNode));

    // Verifica se a alocação de memória para o novo nó foi bem-sucedida
    if (newNode == NULL)
    {
        // Se a alocação falhar, a função retorna sem adicionar o lexema
        return;
    }

    // Define o lexema do novo nó
    newNode->lexema = lexema;
    // Faz o novo nó apontar para o atual topo da lista
    newNode->next = list->top;
    // Atualiza o topo da lista para ser o novo nó
    list->top = newNode;

    // (Código opcional para depuração)
    // printf("Lista lexema é: %s\n", newNode->lexema->lexemaBuffer);
}

// Função para remover e retornar o lexema do topo da lista de lexemas
struct Lexema *popLexema(LexemaList *list)
{
    // Verifica se a lista é nula ou se o topo da lista é nulo
    if (list == NULL || list->top == NULL)
    {
        // Se a lista for nula ou não tiver elementos, retorna NULL
        return NULL;
    }

    // Armazena o nó do topo  (o último lexema adicionado)
    LexemaNode *nodeToRemove = list->top;

    // Extrai o lexema do nó que está no topo
    struct Lexema *lexema = nodeToRemove->lexema;

    // Atualiza o topo  para ser o próximo nó na lista
    list->top = nodeToRemove->next;

    // (Código opcional para depuração)
    // printf("Pop lexema é: %s\n", nodeToRemove->lexema->lexemaBuffer);

    // Libera a memória do nó que foi removido
    free(nodeToRemove);

    // Retorna o ponteiro para o lexema que estava no topo
    return lexema;
}

// Função para criar um novo nó na Árvore Sintática Abstrata (AST)
ASTNode *createNode(type nodeType, struct Lexema *lexemaInfo)
{
    // Aloca memória para um novo nó da AST
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));

    // Verifica se a alocação de memória foi bem-sucedida
    if (node == NULL)
    {
        // Em caso de falha na alocação, retorna NULL
        return NULL;
    }

    // Define o tipo do nó conforme o valor passado para a função
    node->type = nodeType;

    // Associa informações do lexema ao nó (pode ser NULL se o nó não estiver associado a um lexema específico)
    node->lexema = lexemaInfo;

    // Inicializa os ponteiros para os nós filhos e irmãos como NULL
    // Isso indica que, inicialmente, o nó não tem filhos ou irmãos
    node->left = NULL;    // Ponteiro para o filho à esquerda
    node->middle = NULL;  // Ponteiro para o filho do meio (usado em algumas estruturas de dados específicas)
    node->right = NULL;   // Ponteiro para o filho à direita
    node->sibling = NULL; // Ponteiro para o irmão do nó (usado para representar listas ou sequências de nós)

    // Retorna o ponteiro para o novo nó da AST
    return node;
}

// Função para adicionar um irmão a um nó na Árvore Sintática Abstrata (AST)
void *addSibling(ASTNode *node, ASTNode *sibling)
{
    // Verifica se o nó fornecido é nulo
    if (node == NULL)
    {
        // Se o nó for nulo, imprime uma mensagem de erro e retorna NULL
        printf("addSibling chamado com node NULL\n");
        return NULL;
    }

    // Percorre os irmãos do nó fornecido até encontrar o último irmão
    while (node->sibling != NULL)
    {
        // Avança para o próximo irmão
        node = node->sibling;
    }

    // Uma vez encontrado o último irmão, adiciona o novo irmão (sibling) a ele
    node->sibling = sibling;

    // (Código opcional para depuração)
    // printf("Adicionando irmão. Node Tipo = %d, Sibling Tipo = %d\n", node->type, sibling->type);
}

// Função para adicionar um filho a um nó na Árvore Sintática Abstrata (AST)
void *addSon(ASTNode *parent, ASTNode *son)
{
    // Verifica se o nó pai fornecido é nulo
    if (parent == NULL)
    {
        // Se o nó pai for nulo, retorna NULL e não faz nada
        return NULL;
    }

    // Verifica se o nó filho a ser adicionado é nulo
    if (son == NULL)
    {
        // Se o nó filho for nulo, retorna NULL e não faz nada
        return NULL;
    }

    // (Código opcional para depuração)
    // printf("Adicionando filho. Parent Tipo = %d, Son Tipo = %d\n", parent->type, son->type);

    // Verifica se o filho esquerdo do nó pai está vazio
    if (parent->left == NULL)
    {
        // Se estiver vazio, adiciona o filho ao lado esquerdo
        parent->left = son;
    }
    // Se o filho esquerdo não estiver vazio, mas o filho do meio estiver, adiciona ao meio
    else if (parent->middle == NULL)
    {
        parent->middle = son;
    }
    // Se tanto o filho esquerdo quanto o do meio não estiverem vazios, adiciona ao lado direito
    else if (parent->right == NULL)
    {
        parent->right = son;
    }

    // Retorna o ponteiro para o nó pai
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