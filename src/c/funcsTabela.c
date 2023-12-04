#include "../h/funcs.h"
struct tabelaSimbolos **tabela;

struct tabelaSimbolos *initTabela(char *scope, int dataType, char *ID, type typeId, int linha)
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
    tabelaAux->lineNumbers = NULL;
    tabelaAux->lineCount = 0;
    tabelaAux->next = NULL;
    tabelaAux->last = NULL;

    addLine(tabelaAux, linha);

    return tabelaAux;
}

void initHash()
{
    int i;
    // Aloca memória para um array de ponteiros para struct tabelaSimbolos
    tabela = (struct tabelaSimbolos **)malloc(250 * sizeof(struct tabelaSimbolos *));
    if (tabela == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para a tabela de símbolos\n");
        return;
    }

    for (i = 0; i < 250; i++)
    {
        tabela[i] = NULL;
    }
}

void pushTabela(type typeId, int dataType, char *ID, char *scope, int linha)
{
    struct tabelaSimbolos *last = NULL, *next;

    int position = longhash(ID);
    bool control = true;

    if (tabela[position])
    {
        next = tabela[position];

        while (next && control)
        {
            if (strcmp(next->ID, ID) == 0)
            {
                if (strcmp(next->scope, scope) == 0 || strcmp(next->scope, "global") == 0)
                {
                    addLine(next, linha);
                    control = false;
                }
            }
            last = next;
            next = next->next;
        }

        if (control)
        {
            struct tabelaSimbolos *aux = initTabela(scope, dataType, ID, typeId, linha);
            if (aux)
            {
                if (last)
                {
                    last->next = aux;
                    aux->last = last;
                }
                else
                {
                    // Inserção no início da lista para esta posição
                    tabela[position] = aux;
                }
            }
        }
    }
    else
    {
        tabela[position] = initTabela(scope, dataType, ID, typeId, linha);
    }
}

unsigned longhash(char *str)
{
    unsigned long hash = 0, alpha = 1;
    char c;

    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        c = str[i];
        hash += alpha * c;
        alpha = ((alpha << 4));
    }

    hash = hash % 250;

    return hash;
}

void addLine(struct tabelaSimbolos *tabela, int lineToAdd)
{
    if (tabela == NULL)
    {
        fprintf(stderr, "Item passado para addLine é NULL\n");
        return;
    }

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
        if (temp == NULL)
        {
            fprintf(stderr, "Erro ao realocar memória para lineNumbers\n");
            return; // Ou maneje o erro conforme necessário
        }
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

    if (isDeclaracao(node->type))
    {

        ASTNode *nodeAux = NULL;
        int auxTipo;

        if (node->type == R_var_declaracao || node->type == R_var_declaracao_vet)
        {
            if (buscarIgual(node, 0, auxScope) == 1)
            {
                // se a declaracao for int deu certo, se for outro tipo deu errado
                if (node->lexema->token == T_INT)
                {
                    pushTabela(node->type, 0, node->left->lexema->lexemaBuffer, auxScope, node->lexema->linha);
                }
                else
                {
                    printf("Erro declaração não é do tipo INT\n");
                }
            }
        }

        else if ((node->type == R_fun_declaracao))
        {
            if (node->lexema->token == T_INT)
                auxTipo = 0;
            else
                auxTipo = 1;

            strcpy(auxScope, node->middle->lexema->lexemaBuffer);

            if (buscarIgual(node, 1, auxScope) == 1)
                pushTabela(node->type, auxTipo, node->middle->lexema->lexemaBuffer, auxScope, node->lexema->linha);

            if (node->left->type != R_params)
            {
                nodeAux = node->left;
                while (nodeAux)
                {
                    if (buscarIgual(nodeAux, 0, auxScope) == 1)
                    {
                        if (nodeAux->lexema->token == T_INT)
                        {
                            strcpy(auxScope, node->middle->lexema->lexemaBuffer);
                            pushTabela(node->type, 0, nodeAux->left->lexema->lexemaBuffer, auxScope, nodeAux->lexema->linha);
                        }
                        else
                        {
                            printf("Parametro não é do tipo inteiro\n");
                        }
                    }
                    nodeAux = nodeAux->sibling;
                }
            }
        }
    }

    if (isExpressao(node->type))
    {
        struct tabelaSimbolos *tabelaAux = NULL;

        type nodeType = node->type;

        if (nodeType == R_var_id)
        {
            unsigned int indice = longhash(node->lexema->lexemaBuffer);
            struct tabelaSimbolos *aux = tabela[indice];

            while (aux)
            {
                if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0)
                {
                    if (node->type == R_var_declaracao_vet)
                    {
                        if (aux->typeId == R_var_declaracao_vet || aux->typeId == R_param_vet)
                        {
                            if ((strcmp(scope, aux->scope) == 0 || strcmp(aux->scope, "global") == 0))
                                break;
                        }
                    }
                    else
                    {
                        if (aux->typeId == R_var_declaracao || aux->typeId == R_param_int)
                        {
                            if ((strcmp(scope, aux->scope) == 0 || strcmp(aux->scope, "global") == 0))
                                break;
                        }
                    }
                }
                aux = aux->next;
            }
            tabelaAux = aux;

            if (tabelaAux == NULL)
            {
                aux = tabela[indice];

                while (aux)
                {
                    if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0)
                    {
                        if (node->type == R_var_declaracao_vet)
                        {
                            if (aux->typeId == R_var_declaracao_vet || aux->typeId == R_param_vet)
                            {
                                if ((strcmp(scope, aux->scope) == 0 || strcmp(aux->scope, "global") == 0))
                                    break;
                            }
                        }
                        else
                        {
                            if (aux->typeId == R_var_declaracao || aux->typeId == R_param_int)
                            {
                                if ((strcmp(scope, aux->scope) == 0 || strcmp(aux->scope, "global") == 0))
                                    break;
                            }
                        }
                    }
                    aux = aux->next;
                }
                tabelaAux = aux;

                if (tabelaAux != NULL)
                    printf("Erro: Identificador '%s' encontrado, mas usado de forma inconsistente ou inesperada na linha %d.\n", node->lexema->lexemaBuffer, node->lexema->linha);

                else
                    printf("Erro: Identificador '%s' não declarado ou não encontrado no escopo atual na linha %d.\n", node->lexema->lexemaBuffer, node->lexema->linha);
            }
            else
            {
                addLine(tabelaAux, node->lexema->linha);
            }
        }

        else if (nodeType == R_var_vet)
        {
            unsigned int indice = longhash(node->lexema->lexemaBuffer);
            struct tabelaSimbolos *aux = tabela[indice];

            while (aux)
            {
                if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0)
                {
                    if (node->type == R_var_declaracao_vet)
                    {
                        if (aux->typeId == R_var_declaracao_vet || aux->typeId == R_param_vet)
                        {
                            if ((strcmp(scope, aux->scope) == 0 || strcmp(aux->scope, "global") == 0))
                                break;
                        }
                    }
                    else
                    {
                        if (aux->typeId == R_var_declaracao || aux->typeId == R_param_int)
                        {
                            if ((strcmp(scope, aux->scope) == 0 || strcmp(aux->scope, "global") == 0))
                                break;
                        }
                    }
                }
                aux = aux->next;
            }
            tabelaAux = aux;

            if (tabelaAux == NULL)
                printf("Erro: Variável vetor '%s' não declarada ou não encontrada no escopo atual na linha %d.\n", node->lexema->lexemaBuffer, node->lexema->linha);

            else
                addLine(tabelaAux, node->lexema->linha);
        }

        else if (node->type == R_ativacao)
        {
            unsigned int indice = longhash(node->lexema->lexemaBuffer);
            struct tabelaSimbolos *aux = tabela[indice];

            while (aux)
            {
                if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0 && aux->typeId == R_fun_declaracao)
                    break;

                aux = aux->next;
            }
            tabelaAux = aux;

            if (tabelaAux == NULL)
                printf("Erro: Função '%s' não declarada ou não reconhecida no escopo atual na linha %d.\n", node->lexema->lexemaBuffer, node->lexema->linha);
            else
                addLine(tabelaAux, node->lexema->linha);

            ASTNode *filhoAux = node->left;
            while (filhoAux)
            {
                if (filhoAux->left)
                    searchTree(filhoAux, scope);
                else
                    chamadaFunc(filhoAux, scope);

                filhoAux = filhoAux->sibling;
            }
        }

        else if (node->type == R_expressao)
        {
            if (node->middle->type == R_ativacao)
            {
                unsigned int indice = longhash(node->lexema->lexemaBuffer);
                struct tabelaSimbolos *aux = tabela[indice];

                while (aux)
                {
                    if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0 && aux->typeId == R_fun_declaracao)
                        break;

                    aux = aux->next;
                }
                tabelaAux = aux;

                if (tabelaAux)
                {
                    if (tabelaAux->dataType == 1)
                        printf("Erro: Função '%s' do tipo 'void' está sendo usada como uma expressão na linha %d.\n", node->lexema->lexemaBuffer, node->lexema->linha);
                }
            }
        }
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

    if (strcmp(scope, "global") == 0)
        searchTree(node->sibling, scope);
    else
        searchTree(node->sibling, auxScope);
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

int buscarIgual(ASTNode *node, int position, char *scope)
{
    struct tabelaSimbolos *tabelaAux = NULL;
    ASTNode *auxNode = NULL;

    if (position == 0)
        auxNode = node->left;

    if (position == 1)
        auxNode = node->middle;

    if (position == 2)
        auxNode = node->right;

    unsigned int indice = longhash(auxNode->lexema->lexemaBuffer);

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
            if (strcmp(auxNode->lexema->lexemaBuffer, aux->ID) == 0)
            {
                if ((strcmp(scope, aux->scope) == 0 || strcmp(aux->scope, "global") == 0))
                    break;

                if (aux->typeId == R_fun_declaracao)
                    break;
            }
            aux = aux->next;
        }

        tabelaAux = aux;
    }
    if (tabelaAux == NULL)
        return 1;

    if (tabelaAux->typeId == R_fun_declaracao && node->type == R_fun_declaracao)
        printf("Erro: Função '%s' já foi declarada anteriormente.\n", auxNode->lexema->lexemaBuffer);

    else if (isValidType(tabelaAux->typeId) && isValidType(node->type))
    {
        if (strcmp(tabelaAux->scope, scope) != 0 && strcmp(tabelaAux->scope, "global") != 0)
            return 1;
        printf("Erro: Identificador '%s' já foi declarado em um escopo diferente.\n", auxNode->lexema->lexemaBuffer);
    }
    else if (isValidType(tabelaAux->typeId) && node->type == R_fun_declaracao)
        printf("Erro: Identificador '%s' já foi declarado em um escopo diferente.\n", auxNode->lexema->lexemaBuffer);

    else if (tabelaAux->typeId == R_fun_declaracao && isValidType(node->type))
        printf("Erro: Identificador '%s' usado para variável ou vetor já existe como função.\n", auxNode->lexema->lexemaBuffer);

    return 0;
}

void chamadaFunc(ASTNode *node, char *scope)
{
    struct tabelaSimbolos *tabelaAux = NULL;

    if (node->type == R_ativacao)
    {

        unsigned int indice = longhash(node->lexema->lexemaBuffer);
        struct tabelaSimbolos *aux = tabela[indice];

        while (aux)
        {
            if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0 && aux->typeId == R_fun_declaracao)
                break;

            aux = aux->next;
        }
        tabelaAux = aux;

        if (tabelaAux == NULL)
            printf("Erro: Função '%s' não declarada ou não reconhecida no escopo atual na linha %d.\n", node->lexema->lexemaBuffer, node->lexema->linha);
        else
            addLine(tabelaAux, node->lexema->linha);
    }
    else if (node->type == R_var_id)
    {
        int indice = longhash(node->lexema->lexemaBuffer);

        tabelaAux = tabela[indice];

        while (tabelaAux)
        {
            if (strcmp(tabelaAux->ID, node->lexema->lexemaBuffer) == 0 && tabelaAux->typeId == R_fun_declaracao)
            {
                printf("Erro: Identificador '%s' é uma função, não pode ser usado como variável na linha %d.\n", node->lexema->lexemaBuffer, node->lexema->linha);
                return;
            }
            if ((strcmp(tabelaAux->ID, node->lexema->lexemaBuffer) == 0) && (strcmp(tabelaAux->scope, scope) == 0 || strcmp(tabelaAux->scope, "global") == 0))
            {
                addLine(tabelaAux, node->lexema->linha);
                return;
            }
            tabelaAux = tabelaAux->next;
        }
        printf("Erro: Variável '%s' não declarada ou fora de escopo na linha %d.\n", node->lexema->lexemaBuffer, node->lexema->linha);
        return;
    }
}

void imprimirTabela()
{
    struct tabelaSimbolos *tabelaAux = NULL;

    for (int i = 0; i < 211; i++)
    {
        if (tabela[i] != NULL)
        {
            tabelaAux = tabela[i];
            while (tabelaAux != NULL)
            {
                printf("Nome: %s\n", tabelaAux->ID);

                if (tabelaAux->typeId != R_fun_declaracao)
                    printf("Escopo: %s\n", tabelaAux->scope);

                if (tabelaAux->dataType == 0)
                {
                    printf("Tipo de dado: INT\n");
                }
                else
                {
                    printf("Tipo de dado: VOID\n");
                }

                if (tabelaAux->typeId == R_var_declaracao)
                {
                    printf("Tipo de identificador: VAR\n");
                }
                else if (tabelaAux->typeId == R_fun_declaracao)
                {
                    printf("Tipo de identificador: FUN\n");
                }
                else if (tabelaAux->typeId == R_var_declaracao_vet)
                {
                    printf("Tipo de identificador: VET\n");
                }
                else
                {
                    printf("Tipo de identificador: PARAM\n");
                }

                printf("\n\n");
                tabelaAux = tabelaAux->next;
            }
        }
    }
}
