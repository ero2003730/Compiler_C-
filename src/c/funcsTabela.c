#include "../h/funcs.h"
struct tabelaSimbolos **tabela;

struct tabelaSimbolos *allocateTabela(char *scope, int dataType, char *ID, type typeId, int linha)
{
    struct tabelaSimbolos *tabelaAux = (struct tabelaSimbolos *)malloc(sizeof(struct tabelaSimbolos));

    if (tabelaAux == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória para tabelaSimbolos\n");
        return NULL;
    }

    tabelaAux->ID = strdup(ID);
    tabelaAux->scope = strdup(scope);
    tabelaAux->dataType = dataType;
    tabelaAux->typeId = typeId;
    tabelaAux->lineCount = 0;
    tabelaAux->next = NULL;
    tabelaAux->last = NULL;

    tabelaAux->lineNumbers = (int *)malloc(sizeof(int));

    if (tabelaAux->lineNumbers == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para lineNumbers\n");
        // Limpeza apropriada antes de retornar
        free(tabelaAux->ID);
        free(tabelaAux->scope);
        free(tabelaAux);
        return NULL;
    }

    // Adicionando a linha e incrementando lineCount
    tabelaAux->lineNumbers[0] = linha;
    tabelaAux->lineCount = 1;

    return tabelaAux;
}

void initTabela()
{
    int i;
    // Aloca memória para um array de ponteiros para struct tabelaSimbolos
    tabela = (struct tabelaSimbolos **)malloc(250 * sizeof(struct tabelaSimbolos *));

    if (tabela == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para a tabela de símbolos\n");
        return;
    }

    for (i = 0; i < 100; i++)
    {
        tabela[i] = NULL;
    }
}

void pushTabela(type tipoId, int tipoDados, char *identificador, char *escopo, int numeroLinha)
{
    struct tabelaSimbolos *ultimo = NULL, *atual;

    int indice = getHash(identificador);
    bool deveInserir = true;

    if (tabela[indice])
    {
        atual = tabela[indice];

        while (atual && deveInserir)
        {
            if (strcmp(atual->ID, identificador) == 0 && (strcmp(atual->scope, escopo) == 0 || strcmp(atual->scope, "global") == 0))
            {
                if (atual->lineNumbers == NULL)
                {
                    atual->lineNumbers = (int *)malloc(sizeof(int));
                    atual->lineCount = 0;
                }
                else
                {
                    int *temp = (int *)realloc(atual->lineNumbers, (atual->lineCount + 1) * sizeof(int));
                    atual->lineNumbers = temp;
                }

                atual->lineNumbers[atual->lineCount] = numeroLinha;
                atual->lineCount++;

                deveInserir = false;
            }
            else
            {
                ultimo = atual;
                atual = atual->next;
            }
        }

        if (deveInserir)
        {
            struct tabelaSimbolos *novoSimbolo = allocateTabela(escopo, tipoDados, identificador, tipoId, numeroLinha);
            if (novoSimbolo)
            {
                if (ultimo)
                {
                    ultimo->next = novoSimbolo;
                    novoSimbolo->last = ultimo;
                }
                else
                {
                    tabela[indice] = novoSimbolo;
                }
            }
        }
    }
    else
    {
        tabela[indice] = allocateTabela(escopo, tipoDados, identificador, tipoId, numeroLinha);
    }
}

unsigned getHash(char *str)
{
    unsigned hash = 0;

    // Iterar sobre cada caractere da string
    while (*str)
    {
        // Adicionar o valor ASCII do caractere ao hash e multiplicar por um fator
        hash = hash * 10 + (unsigned char)(*str);

        // Avançar para o próximo caractere
        str++;
    }

    // Restringir o valor de hash a um intervalo específico, por exemplo, 0 a 249
    return hash % 250;
}

void addLine(struct tabelaSimbolos *tabela, int lineToAdd)
{

    // Se lineNumbers ainda não foi inicializado, aloque espaço para ele
    if (tabela->lineNumbers == NULL)
    {
        tabela->lineNumbers = (int *)malloc(sizeof(int));
        if (tabela->lineNumbers == NULL)
        {
            fprintf(stderr, "Erro ao alocar memória para lineNumbers\n");
            return; // Ou maneje o erro conforme necessário
        }
        tabela->lineCount = 0;
    }
    else
    {
        // Caso contrário, realoque para caber um novo número de linha
        int *temp = (int *)realloc(tabela->lineNumbers, (tabela->lineCount + 1) * sizeof(int));

        tabela->lineNumbers = temp;
    }

    // Adicione a nova linha e incremente lineCount
    tabela->lineNumbers[tabela->lineCount] = lineToAdd;
    tabela->lineCount++;
}

bool isDeclaracao(type nodeType)
{
    switch (nodeType)
    {
    case R_var_declaracao:
    case R_var_declaracao_vet:
    case R_fun_declaracao:
    case R_params:
    case R_param_int:
    case R_param_vet:
    case R_selecao_decl:
    case R_iteracao_decl:
    case R_retorno_decl_int:
    case R_retorno_decl_void:
        return true;
    default:
        return false;
    }
}

bool isExpressao(type nodeType)
{
    switch (nodeType)
    {
    case R_expressao:
    case R_var_id:
    case R_var_vet:
    case R_simples_expressao:
    case R_soma_expressao:
    case R_termo:
    case R_fator:
    case R_ativacao:
        return true;
    default:
        return false;
    }
}

void searchTree(ASTNode *node, char *scope)
{
    char *auxScope = NULL;

    auxScope = (char *)malloc(30 * sizeof(char));

    strcpy(auxScope, scope);

    if (node == NULL)
        return;

    ASTNode *nodeAux = NULL;
    int auxTipo;

    if (node->type == R_var_declaracao || node->type == R_var_declaracao_vet)
    {
        handleVarDeclaration(node, auxScope);
    }

    else if ((node->type == R_fun_declaracao))
    {
        handleFunctionDeclaration(node, auxScope);
    }

    if (node->type == R_var_id)
    {
        handleVarIdDeclaration(node, scope);
    }

    else if (node->type == R_var_vet)
    {
        handleVarVetDeclaration(node, scope);
    }

    else if (node->type == R_ativacao)
    {
        handleFunctionActivation(node, scope);
    }

    else if (node->type == R_expressao)
    {
        handleExpression(node);
    }

    if (node->type != R_ativacao)
    {
        if (node->left)
            searchTree(node->left, auxScope);
        if (node->middle)
            searchTree(node->middle, auxScope);
        if (node->right)
            searchTree(node->right, auxScope);
    }

    searchTree(node->sibling, scope);
}

bool isValidType(type nodeType)
{
    switch (nodeType)
    {
    case R_var_declaracao:
    case R_var_declaracao_vet:
    case R_param_int:
    case R_param_vet:
        return true;
    default:
        return false;
    }
}

int searchTabela(ASTNode *node, int position, char *scope)
{
    struct tabelaSimbolos *tabelaAux = NULL;
    ASTNode *auxNode = NULL;

    if (position == 0)
        auxNode = node->left;

    if (position == 1)
        auxNode = node->middle;

    if (position == 2)
        auxNode = node->right;

    unsigned int indice = getHash(auxNode->lexema->lexemaBuffer);

    struct tabelaSimbolos *aux = tabela[indice];

    if (node->type == R_fun_declaracao)
    {
        while (aux)
        {
            if (strcmp(auxNode->lexema->lexemaBuffer, aux->ID) == 0)
                break;

            aux = aux->next;
        }
        tabelaAux = aux;
    }
    else
    {
        while (aux)
        {
            // printf("ID: %s %s %d\n", auxNode->lexema->lexemaBuffer, aux->ID, auxNode->lexema->linha);

            if (strcmp(auxNode->lexema->lexemaBuffer, aux->ID) == 0)
            {
                if ((strcmp(scope, aux->scope) == 0 || strcmp(aux->scope, "global") == 0))
                {
                    // printf("Scopo: %s %s\n", scope, aux->scope);
                    break;
                }

                if (aux->typeId == R_fun_declaracao)
                    break;
            }
            aux = aux->next;
        }

        tabelaAux = aux;
    }

    return verifyErrors(tabelaAux, node, auxNode, scope);
}

int verifyErrors(struct tabelaSimbolos *tabelaAux, struct ASTNode *node, struct ASTNode *auxNode, const char *scope)
{
    if (tabelaAux == NULL)
        return 1;

    if (tabelaAux->typeId == R_fun_declaracao && node->type == R_fun_declaracao)
    {
        printf("Erro: Função '%s' já foi declarada anteriormente.\n", auxNode->lexema->lexemaBuffer);
        return 0;
    }

    if (isValidType(tabelaAux->typeId) && isValidType(node->type))
    {
        if ((strcmp(tabelaAux->scope, scope) != 0) && (strcmp(tabelaAux->scope, "global") != 0))
            return 1;

        printf("Erro: Identificador '%s' já foi declarado em um escopo diferente.\n", auxNode->lexema->lexemaBuffer);
        return 0;
    }

    if (isValidType(tabelaAux->typeId) && node->type == R_fun_declaracao)
    {
        printf("Erro: Identificador '%s' já foi declarado em um escopo diferente.\n", auxNode->lexema->lexemaBuffer);
        return 0;
    }

    if (tabelaAux->typeId == R_fun_declaracao && isValidType(node->type))
    {
        printf("Erro: Identificador '%s' usado para variável ou vetor já existe como função.\n", auxNode->lexema->lexemaBuffer);
        return 0;
    }

    return 0;
}

const char *getTypeName(type typeId)
{
    switch (typeId)
    {
    case R_default:
        return "Default";
    case R_programa:
        return "Programa";
    case R_declaracao_lista:
        return "Lista de Declaração";
    case R_declaracao:
        return "Declaração";
    case R_var_declaracao:
        return "Declaração de Variável";
    case R_var_declaracao_vet:
        return "Declaração de Vetor";
    case R_tipo_especificador:
        return "Especificador de Tipo";
    case R_fun_declaracao:
        return "Declaração de Função";
    case R_params:
        return "Parâmetros";
    case R_param_lista:
        return "Lista de Parâmetros";
    case R_param_int:
        return "Parâmetro Int";
    case R_param_vet:
        return "Parâmetro Vetor";
    case R_composto_decl:
        return "Declaração Composta";
    case R_local_declaracoes:
        return "Declarações Locais";
    case R_statement_lista:
        return "Lista de Statements";
    case R_statement:
        return "Statement";
    case R_expressao_decl:
        return "Declaração de Expressão";
    case R_selecao_decl:
        return "Declaração de Seleção";
    case R_iteracao_decl:
        return "Declaração de Iteração";
    case R_retorno_decl_int:
        return "Declaração de Retorno Int";
    case R_retorno_decl_void:
        return "Declaração de Retorno Void";
    case R_expressao:
        return "Expressão";
    case R_var_id:
        return "ID de Variável";
    case R_var_vet:
        return "Vetor de Variável";
    case R_simples_expressao:
        return "Expressão Simples";
    case R_relacional:
        return "Operação Relacional";
    case R_soma_expressao:
        return "Expressão de Soma";
    case R_soma:
        return "Soma";
    case R_termo:
        return "Termo";
    case R_mult:
        return "Multiplicação";
    case R_fator:
        return "Fator";
    case R_ativacao:
        return "Ativação";
    case R_args:
        return "Argumentos";
    case R_arg_lista:
        return "Lista de Argumentos";
    default:
        return "Desconhecido";
    }
}

const char *getDataTypeName(int dataType)
{
    switch (dataType)
    {
    case 0:
        return "TYPE_INT";
    case 1:
        return "TYPE_VOID";
    default:
        return "Desconhecido";
    }
}

void printSemanticTable()
{
    printf("Tabela Semântica:\n");
    printf("| %-20s | %-10s | %-10s | %-10s | %-10s |\n", "ID", "Escopo", "Tipo ID", "Tipo Dado", "Linhas");

    for (int i = 0; i < 250; ++i)
    {
        tabelaSimbolos *current = tabela[i];
        while (current != NULL)
        {
            // Imprime os detalhes do ID atual.
            printf("| %-20s | %-10s | %-10s | %-10s | ",
                   current->ID,
                   current->scope,
                   getTypeName(current->typeId),
                   getDataTypeName(current->dataType)); // Usa a função auxiliar para o tipo de dado

            // Imprime todas as linhas onde o ID aparece.
            for (int j = 0; j < current->lineCount; ++j)
            {
                printf("%d ", current->lineNumbers[j]);
            }
            printf("|\n");
            current = current->next; // Vai para o próximo item na lista ligada.
        }
    }
}
