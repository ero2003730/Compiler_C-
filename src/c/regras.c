#include "../h/funcs.h"

void handleVarDeclaration(ASTNode *node, char *auxScope)
{
    // Suponha que a função searchTabela e pushTabela estejam definidas em algum lugar do seu código.
    if (searchTabela(node, 0, auxScope) == 1)
    {
        if (node->lexema->token == T_INT)
        {
            pushTabela(node->type, 0, node->left->lexema->lexemaBuffer, auxScope, node->lexema->linha);
        }
        else
        {
            printf("Erro: declaração não é do tipo INT\n");
        }
    }
}

void handleFunctionDeclaration(ASTNode *node, char *auxScope)
{
    // Suponha que as funções searchTabela e pushTabela estejam definidas em algum lugar do seu código.
    int auxTipo;
    ASTNode *nodeAux;

    if (node->lexema->token == T_INT)
        auxTipo = 0;
    else if (node->lexema->token == T_VOID)
        auxTipo = 1;
    else
        printf("Erro\n");

    strcpy(auxScope, node->middle->lexema->lexemaBuffer);

    if (searchTabela(node, 1, auxScope) == 1)
        pushTabela(node->type, auxTipo, node->middle->lexema->lexemaBuffer, auxScope, node->lexema->linha);

    if (node->left->type != R_params)
    {
        nodeAux = node->left;
        while (nodeAux)
        {
            if (searchTabela(nodeAux, 0, auxScope) == 1)
            {
                if (nodeAux->lexema->token == T_INT)
                {
                    strcpy(auxScope, node->middle->lexema->lexemaBuffer);
                    pushTabela(nodeAux->type, 0, nodeAux->left->lexema->lexemaBuffer, auxScope, nodeAux->lexema->linha);
                }
                else
                {
                    printf("Parâmetro não é do tipo inteiro\n");
                }
            }
            nodeAux = nodeAux->sibling;
        }
    }
}

void handleVarIdDeclaration(ASTNode *node, char *scope)
{
    unsigned int indice = getHash(node->lexema->lexemaBuffer);
    struct tabelaSimbolos *aux = tabela[indice];
    struct tabelaSimbolos *tabelaAux = NULL;
    type typeDeclara;

    if (node->type == R_var_vet)
        typeDeclara = R_var_declaracao_vet;
    else
        typeDeclara = R_var_declaracao;

    while (aux)
    {
        if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0)
        {
            if (typeDeclara == R_var_declaracao_vet)
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
            if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0 && aux->typeId == R_fun_declaracao)
                break;
            aux = aux->next;
        }
        tabelaAux = aux;
        if (tabelaAux != NULL)
        {
            printf("Erro: Identificador '%s' encontrado, mas usado de forma inconsistente ou inesperada na linha %d.\n",
                   node->lexema->lexemaBuffer, node->lexema->linha);
        }
        else
        {
            printf("Erro: Identificador '%s' não declarado ou não encontrado no escopo atual na linha %d.\n",
                   node->lexema->lexemaBuffer, node->lexema->linha);
        }
    }
    else
    {
        addLine(tabelaAux, node->lexema->linha);
    }
}

void handleVarVetDeclaration(ASTNode *node, char *scope)
{
    unsigned int indice = getHash(node->lexema->lexemaBuffer);
    struct tabelaSimbolos *aux = tabela[indice];
    struct tabelaSimbolos *tabelaAux = NULL;
    type typeDeclara;

    if (node->type == R_var_vet)
        typeDeclara = R_var_declaracao_vet;
    else
        typeDeclara = R_var_declaracao;

    while (aux)
    {
        if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0)
        {
            if (typeDeclara == R_var_declaracao_vet)
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

void handleFunctionActivation(ASTNode *node, char *scope)
{
    unsigned int indice = getHash(node->lexema->lexemaBuffer);
    struct tabelaSimbolos *aux = tabela[indice];
    struct tabelaSimbolos *tabelaAux = NULL;

    while (aux)
    {
        if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0 && aux->typeId == R_fun_declaracao)
            break;

        aux = aux->next;
    }
    tabelaAux = aux;

    if (tabelaAux == NULL)
    {
        printf("Erro: Função '%s' não declarada ou não reconhecida no escopo atual na linha %d.\n", node->lexema->lexemaBuffer, node->lexema->linha);
    }
    else
    {
        addLine(tabelaAux, node->lexema->linha);
    }

    struct ASTNode *filhoAux = node->left;
    while (filhoAux)
    {
        if (filhoAux->left)
            searchTree(filhoAux, scope);
        else
        {
            // Conteúdo original da função chamadaFunc implementado diretamente aqui
            struct tabelaSimbolos *tabelaAux = NULL;

            if (filhoAux->type == R_ativacao)
            {
                unsigned int indice = getHash(filhoAux->lexema->lexemaBuffer);
                struct tabelaSimbolos *aux = tabela[indice];

                while (aux)
                {
                    if (strcmp(filhoAux->lexema->lexemaBuffer, aux->ID) == 0 && aux->typeId == R_fun_declaracao)
                        break;

                    aux = aux->next;
                }
                tabelaAux = aux;

                if (tabelaAux == NULL)
                    printf("Erro: Função '%s' não declarada ou não reconhecida no escopo atual na linha %d.\n", filhoAux->lexema->lexemaBuffer, filhoAux->lexema->linha);
                else
                    addLine(tabelaAux, filhoAux->lexema->linha);
            }
            else if (filhoAux->type == R_var_id)
            {
                unsigned int indice = getHash(filhoAux->lexema->lexemaBuffer);
                tabelaAux = tabela[indice];

                while (tabelaAux)
                {
                    if (strcmp(tabelaAux->ID, filhoAux->lexema->lexemaBuffer) == 0 && tabelaAux->typeId == R_fun_declaracao)
                    {
                        printf("Erro: Identificador '%s' é uma função, não pode ser usado como variável na linha %d.\n", filhoAux->lexema->lexemaBuffer, filhoAux->lexema->linha);
                        break;
                    }
                    if ((strcmp(tabelaAux->ID, filhoAux->lexema->lexemaBuffer) == 0) && (strcmp(tabelaAux->scope, scope) == 0 || strcmp(tabelaAux->scope, "global") == 0))
                    {
                        addLine(tabelaAux, filhoAux->lexema->linha);
                        break;
                    }
                    tabelaAux = tabelaAux->next;
                }
                if (tabelaAux == NULL)
                    printf("Erro: Variável '%s' não declarada ou fora de escopo na linha %d.\n", filhoAux->lexema->lexemaBuffer, filhoAux->lexema->linha);
            }
        }

        filhoAux = filhoAux->sibling;
    }
}

void handleExpression(ASTNode *node)
{
    if (node->middle->type == R_ativacao)
    {
        unsigned int indice = getHash(node->lexema->lexemaBuffer);
        struct tabelaSimbolos *aux = tabela[indice];
        struct tabelaSimbolos *tabelaAux = NULL;

        while (aux)
        {
            if (strcmp(node->middle->lexema->lexemaBuffer, aux->ID) == 0 && aux->typeId == R_fun_declaracao)
                break;

            aux = aux->next;
        }
        tabelaAux = aux;

        if (tabelaAux)
        {
            if (tabelaAux->dataType == 1)
            {
                printf("Erro: Função '%s' do tipo 'void' está sendo usada como uma expressão na linha %d.\n", node->lexema->lexemaBuffer, node->lexema->linha);
            }
        }
    }
}
