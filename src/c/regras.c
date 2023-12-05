#include "../h/funcs.h"

// Esta função lida com a declaração de variáveis no compilador.
void handleVarDeclaration(ASTNode *node, char *scope)
{

    // Primeiro, verifica se o nó em questão já foi declarado no escopo atual.
    // searchTabela é uma função que procura o nó na tabela de símbolos.
    // Se o nó não for encontrado na tabela de símbolos, searchTabela retorna 1.
    if (searchTabela(node, 0, scope) == 1)
    {
        // Se o token do lexema do nó for do tipo inteiro (T_INT),
        // então a variável é adicionada à tabela de símbolos.
        if (node->lexema->token == T_INT)
            // pushTabela insere o nó na tabela de símbolos.
            // Os parâmetros incluem o tipo do nó, o tipo de dados (0 para int),
            // o identificador da variável, o escopo e a linha onde a variável é declarada.
            pushTabela(node->type, 0, node->left->lexema->lexemaBuffer, scope, node->lexema->linha);
        else
            // Se o token não for do tipo inteiro, é exibido um erro.
            printf("\033[1;31mErro: declaração não é do tipo INT\n\033[0m");
    }
}

// Função auxiliar para processar parâmetros da função
void processarParametrosFuncao(ASTNode *node, char *auxScope)
{
    // nodeAux é inicializado como o filho esquerdo do nó atual,
    // assumindo que os parâmetros da função estão nesta posição na árvore.
    ASTNode *nodeAux = node->left;

    // Se o tipo do nó auxiliar for 'R_params', isso indica que não há parâmetros para processar,
    // e a função retorna imediatamente.
    if (nodeAux->type == R_params)
    {
        return;
    }

    // Itera sobre os nós irmãos para processar cada parâmetro.
    while (nodeAux)
    {
        // Verifica se o parâmetro já existe na tabela de símbolos.
        // Se searchTabela retornar diferente de 1, o parâmetro já existe ou há outro erro.
        if (searchTabela(nodeAux, 0, auxScope) != 1)
        {
            // Pula para o próximo parâmetro (irmão do nó atual).
            nodeAux = nodeAux->sibling;
            continue;
        }

        // Verifica se o tipo do token do parâmetro é um inteiro.
        // Se não for, emite um erro e pula para o próximo parâmetro.
        if (nodeAux->lexema->token != T_INT)
        {
            printf("\033[1;31mErro: Parâmetro não é do tipo inteiro.\n\033[0m");
            nodeAux = nodeAux->sibling;
            continue;
        }

        // Adiciona o parâmetro à tabela de símbolos se passar nas verificações anteriores.
        // Os argumentos incluem o tipo do nó, tipo de dado (0 para int), identificador, escopo e a linha.
        pushTabela(nodeAux->type, 0, nodeAux->left->lexema->lexemaBuffer, auxScope, nodeAux->lexema->linha);
        // Pula para o próximo parâmetro (irmão do nó atual).
        nodeAux = nodeAux->sibling;
    }
}

// Função para lidar com a declaração de funções na árvore de sintaxe abstrata (AST).
void handleFunctionDeclaration(ASTNode *node, char *auxScope)
{
    // Copia o nome da função (assumindo estar no filho do meio do nó) para a variável auxScope.
    // Isso define o escopo atual para o nome da função.
    strcpy(auxScope, node->middle->lexema->lexemaBuffer);

    // Verifica se a função já existe na tabela de símbolos.
    // Se não existir (searchTabela retorna 1), a função é adicionada à tabela.
    if (searchTabela(node, 1, auxScope) == 1)
    {
        // Adiciona a função à tabela de símbolos com informações como tipo do nó,
        // tipo de token (podendo ser tipo de retorno), nome (escopo), e a linha do lexema.
        pushTabela(node->type, node->lexema->token, auxScope, auxScope, node->lexema->linha);
    }
    // Chama a função para processar os parâmetros da função.
    // Esta função lida com a adição dos parâmetros da função à tabela de símbolos.
    processarParametrosFuncao(node, auxScope);
}

// Função para procurar uma declaração existente na tabela de símbolos.
struct tabelaSimbolos *procurarDeclaracaoExistente(ASTNode *node, char *scope, type typeDeclara)
{
    // Calcula o índice na tabela de símbolos usando a função de hash com base no lexema do nó.
    unsigned int indice = getHash(node->lexema->lexemaBuffer);

    // Acessa a tabela de símbolos no índice calculado.
    struct tabelaSimbolos *aux = tabela[indice];

    // Itera sobre os elementos na posição do índice até encontrar uma correspondência ou chegar ao fim da lista.
    while (aux)
    {
        // Verifica se o identificador do nó corresponde ao da tabela de símbolos.
        // Além disso, verifica se o tipo de declaração do nó corresponde ao tipo na tabela de símbolos.
        // Por fim, confirma se o escopo do nó corresponde ao da tabela de símbolos ou se está no escopo global.
        if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0 &&
            ((typeDeclara == R_var_declaracao_vet && (aux->typeId == R_var_declaracao_vet || aux->typeId == R_param_vet)) ||
             (typeDeclara == R_var_declaracao && (aux->typeId == R_var_declaracao || aux->typeId == R_param_int))) &&
            (strcmp(scope, aux->scope) == 0 || strcmp(aux->scope, "global") == 0))
        {
            // Retorna o elemento da tabela de símbolos que corresponde à busca.
            return aux;
        }
        // Se o item atual não for uma correspondência, passa para o próximo item na lista.
        aux = aux->next;
    }

    // Se não encontrar nenhuma correspondência, retorna NULL.
    return NULL;
}

// Função para tratar declarações ou imprimir um erro se a declaração não existir.
void tratarDeclaracaoOuErro(struct tabelaSimbolos *tabelaAux, ASTNode *node)
{
    // Verifica se existe uma entrada correspondente na tabela de símbolos.
    if (tabelaAux != NULL)
    {
        // Se a entrada na tabela de símbolos existir, adiciona a linha atual à lista de linhas onde a declaração é referenciada.
        addLine(tabelaAux, node->lexema->linha);
        // Sai da função, pois a declaração foi tratada com sucesso.
        return;
    }

    // Se a entrada na tabela de símbolos for NULL, significa que a declaração do identificador não foi encontrada.
    // Portanto, imprime uma mensagem de erro indicando que o identificador não foi declarado ou não está no escopo atual.
    // A mensagem inclui o identificador e a linha onde o erro ocorreu.
    printf("\033[1;31mErro: Identificador '%s' não declarado ou não encontrado no escopo atual na linha %d.\n\033[0m",
           node->lexema->lexemaBuffer, node->lexema->linha);
}

// Função para verificar se um identificador está sendo usado de maneira inconsistente em relação à sua declaração como função.
void verificarUsoEmFuncao(ASTNode *node, unsigned int indice)
{
    // Acessa a entrada na tabela de símbolos correspondente ao índice calculado.
    struct tabelaSimbolos *aux = tabela[indice];

    // Itera sobre as entradas da tabela de símbolos com o mesmo índice de hash.
    while (aux)
    {
        // Verifica se o identificador do nó atual corresponde ao ID na tabela de símbolos
        // e se esse ID é declarado como uma função.
        if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0 && aux->typeId == R_fun_declaracao)
        {
            // Se o identificador for uma função, imprime um erro, pois está sendo usado de maneira inconsistente,
            // por exemplo, como uma variável, o que não é permitido.
            printf("\033[1;31mErro: Identificador '%s' encontrado, mas usado de forma inconsistente ou inesperada na linha %d.\n\033[0m",
                   node->lexema->lexemaBuffer, node->lexema->linha);
            // Sai da função após imprimir a mensagem de erro.
            return;
        }
        // Se a entrada atual não corresponder ou não for uma função, passa para a próxima entrada na lista encadeada.
        aux = aux->next;
    }
}

// Função para lidar com a declaração de identificadores de variáveis ou vetores.
void handleVarIdDeclaration(ASTNode *node, char *scope)
{
    // Determina o tipo de declaração (variável ou vetor) com base no tipo do nó.
    type typeDeclara = (node->type == R_var_vet) ? R_var_declaracao_vet : R_var_declaracao;

    // Procura na tabela de símbolos por uma declaração existente do identificador no escopo atual.
    struct tabelaSimbolos *tabelaAux = procurarDeclaracaoExistente(node, scope, typeDeclara);

    // Se a declaração existente for encontrada na tabela de símbolos:
    if (tabelaAux != NULL)
    {
        // Adiciona a linha atual ao registro de linhas da declaração encontrada.
        addLine(tabelaAux, node->lexema->linha);
        // Finaliza a função, pois a declaração foi processada corretamente.
        return;
    }

    // Calcula o índice na tabela de hash para o identificador do nó.
    unsigned int indice = getHash(node->lexema->lexemaBuffer);

    // Verifica se o identificador está sendo usado de forma inconsistente, como em uma função.
    verificarUsoEmFuncao(node, indice);

    // Se não encontrar uma declaração válida, imprime uma mensagem de erro.
    printf("\033[1;31mErro: Identificador '%s' não declarado ou não encontrado no escopo atual na linha %d.\n\033[0m",
           node->lexema->lexemaBuffer, node->lexema->linha);
}

// Função para lidar com a declaração de identificadores de vetores.
void handleVarVetDeclaration(ASTNode *node, char *scope)
{
    // Calcula o índice na tabela de hash para o identificador do nó.
    unsigned int indice = getHash(node->lexema->lexemaBuffer);

    // Aponta para a entrada na tabela de símbolos correspondente ao índice.
    struct tabelaSimbolos *aux = tabela[indice];

    // Inicializa uma variável para armazenar a entrada válida da tabela de símbolos.
    struct tabelaSimbolos *tabelaAux = NULL;

    // Determina o tipo de declaração (variável ou vetor) com base no tipo do nó.
    type typeDeclara = (node->type == R_var_vet) ? R_var_declaracao_vet : R_var_declaracao;

    // Procura na tabela de símbolos pela entrada correspondente ao identificador.
    while (aux)
    {
        // Verifica se o identificador e o tipo (variável ou vetor) correspondem.
        if (strcmp(node->lexema->lexemaBuffer, aux->ID) == 0 &&
            ((typeDeclara == R_var_declaracao_vet && (aux->typeId == R_var_declaracao_vet || aux->typeId == R_param_vet)) ||
             (typeDeclara == R_var_declaracao && (aux->typeId == R_var_declaracao || aux->typeId == R_param_int))))
        {
            // Verifica se o escopo da entrada na tabela corresponde ao escopo atual ou se é global.
            if (strcmp(scope, aux->scope) == 0 || strcmp(aux->scope, "global") == 0)
            {
                // Se encontrada uma entrada válida, armazena em tabelaAux e interrompe a procura.
                tabelaAux = aux;
                break;
            }
        }
        // Avança para a próxima entrada na lista ligada da tabela de hash.
        aux = aux->next;
    }

    // Se tabelaAux permanece NULL, indica que a variável vetor não foi encontrada ou declarada.
    if (tabelaAux == NULL)
    {
        // Imprime uma mensagem de erro indicando que a variável vetor não foi declarada ou está fora de escopo.
        printf("\033[1;31mErro: Variável vetor '%s' não declarada ou não encontrada no escopo atual na linha %d.\n\033[0m",
               node->lexema->lexemaBuffer, node->lexema->linha);
        return;
    }

    // Adiciona a linha atual ao registro de linhas da variável vetor na tabela de símbolos.
    addLine(tabelaAux, node->lexema->linha);
}

// Função auxiliar para lidar com a ativação (chamada) de funções.
void handleFunctionCall(struct ASTNode *node, char *scope)
{
    // Calcula o índice na tabela de hash para o identificador da função.
    unsigned int indice = getHash(node->lexema->lexemaBuffer);

    // Aponta para a entrada na tabela de símbolos correspondente ao índice.
    struct tabelaSimbolos *tabelaAux = tabela[indice];

    // Itera através da lista ligada na posição do índice para encontrar a declaração da função.
    while (tabelaAux)
    {
        // Verifica se o identificador na tabela de símbolos corresponde ao da função chamada e se é uma função.
        if (strcmp(tabelaAux->ID, node->lexema->lexemaBuffer) == 0 && tabelaAux->typeId == R_fun_declaracao)
        {
            // Adiciona a linha atual ao registro de linhas da função na tabela de símbolos.
            addLine(tabelaAux, node->lexema->linha);
            return; // Retorna com sucesso ao encontrar a função correspondente.
        }
        // Avança para a próxima entrada na lista ligada da tabela de hash.
        tabelaAux = tabelaAux->next;
    }

    // Se a função não for encontrada na tabela de símbolos, imprime uma mensagem de erro.
    printf("\033[1;31mErro: Função '%s' não declarada ou não reconhecida no escopo atual na linha %d.\n\033[0m",
           node->lexema->lexemaBuffer, node->lexema->linha);
}

// Função auxiliar para lidar com variáveis identificadoras.
void handleVarID(struct ASTNode *node, char *scope)
{
    // Calcula o índice na tabela de hash para o identificador da variável.
    unsigned int indice = getHash(node->lexema->lexemaBuffer);

    // Aponta para a entrada na tabela de símbolos correspondente ao índice.
    struct tabelaSimbolos *tabelaAux = tabela[indice];

    // Itera através da lista ligada na posição do índice para verificar o uso do identificador.
    while (tabelaAux)
    {
        // Verifica se o identificador na tabela de símbolos corresponde a uma função.
        if (strcmp(tabelaAux->ID, node->lexema->lexemaBuffer) == 0 && tabelaAux->typeId == R_fun_declaracao)
        {
            // Se for uma função, exibe uma mensagem de erro informando que não pode ser usado como variável.
            printf("\033[1;31mErro: Identificador '%s' é uma função, não pode ser usado como variável na linha %d.\n\033[0m",
                   node->lexema->lexemaBuffer, node->lexema->linha);
            return;
        }

        // Verifica se o identificador na tabela de símbolos corresponde ao escopo atual.
        if (strcmp(tabelaAux->ID, node->lexema->lexemaBuffer) == 0 && (strcmp(tabelaAux->scope, scope) == 0 || strcmp(tabelaAux->scope, "global") == 0))
        {
            // Adiciona a linha atual ao registro de linhas da variável na tabela de símbolos.
            addLine(tabelaAux, node->lexema->linha);
            return; // Retorna com sucesso ao encontrar a variável correspondente.
        }

        // Avança para a próxima entrada na lista ligada da tabela de hash.
        tabelaAux = tabelaAux->next;
    }

    // Se a variável não for encontrada na tabela de símbolos, imprime uma mensagem de erro.
    printf("\033[1;31mErro: Variável '%s' não declarada ou fora de escopo na linha %d.\n\033[0m",
           node->lexema->lexemaBuffer, node->lexema->linha);
}

// Função principal reestruturada para lidar com a ativação de funções e variáveis identificadoras.
void handleFunctionActivation(ASTNode *node, char *scope)
{
    // Chama a função auxiliar para lidar com a chamada de função principal.
    handleFunctionCall(node, scope);

    // Itera através dos filhos do nó atual.
    struct ASTNode *filhoAux = node->left;
    while (filhoAux)
    {
        if (filhoAux->left)
            // Se o filho tiver subárvores à esquerda, chama a função de busca recursiva.
            searchTree(filhoAux, scope);
        else if (filhoAux->type == R_ativacao)
            // Se o filho for uma ativação de função, chama a função auxiliar para lidar com a chamada de função.
            handleFunctionCall(filhoAux, scope);
        else if (filhoAux->type == R_var_id)
            // Se o filho for uma variável identificadora, chama a função auxiliar para lidar com a variável identificadora.
            handleVarID(filhoAux, scope);

        // Avança para o próximo filho na lista de filhos.
        filhoAux = filhoAux->sibling;
    }
}

// Função para lidar com expressões que envolvem chamadas de função.
void handleExpression(ASTNode *node)
{
    // Verifica se o tipo do nó intermediário não é uma ativação de função.
    if (node->middle->type != R_ativacao)
        return; // Se não for, retorna sem fazer nada.

    // Calcula o índice na tabela de símbolos com base no nome da função.
    unsigned int indice = getHash(node->lexema->lexemaBuffer);
    struct tabelaSimbolos *aux = tabela[indice];

    // Procura na tabela de símbolos pela função com o mesmo nome.
    while (aux && (strcmp(node->middle->lexema->lexemaBuffer, aux->ID) != 0 || aux->typeId != R_fun_declaracao))
        aux = aux->next;

    // Se a função foi encontrada e seu tipo de retorno é 'void', emite um erro.
    if (aux && aux->dataType == 1)
        printf("\033[1;31mErro: Função '%s' do tipo 'void' está sendo usada como uma expressão na linha %d.\n\033[0m", node->lexema->lexemaBuffer, node->lexema->linha);
}
