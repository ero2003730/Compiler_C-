#include "../h/funcs.h"
struct tabelaSimbolos **tabela;

// Função para alocar e inicializar uma nova entrada na tabela de símbolos.
struct tabelaSimbolos *allocateTabela(char *scope, int dataType, char *ID, type typeId, int linha)
{
    // Aloca memória para a nova entrada na tabela de símbolos.
    struct tabelaSimbolos *tabelaAux = (struct tabelaSimbolos *)malloc(sizeof(struct tabelaSimbolos));

    // Verifica se a alocação de memória foi bem-sucedida.
    if (tabelaAux == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória para tabelaSimbolos\n");
        return NULL;
    }

    // Inicializa os campos da entrada na tabela de símbolos.
    tabelaAux->ID = strdup(ID);       // Copia o identificador.
    tabelaAux->scope = strdup(scope); // Copia o escopo.
    tabelaAux->dataType = dataType;   // Define o tipo de dados.
    tabelaAux->typeId = typeId;       // Define o tipo de identificador.
    tabelaAux->lineCount = 0;         // Inicializa a contagem de linhas.
    tabelaAux->next = NULL;           // Inicializa o próximo como nulo.
    tabelaAux->last = NULL;           // Inicializa o último como nulo.

    // Aloca memória para o array de números de linha.
    tabelaAux->lineNumbers = (int *)malloc(sizeof(int));

    // Verifica se a alocação de memória para lineNumbers foi bem-sucedida.
    if (tabelaAux->lineNumbers == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para lineNumbers\n");

        // Libera a memória alocada para ID, scope e a própria entrada da tabela.
        free(tabelaAux->ID);
        free(tabelaAux->scope);
        free(tabelaAux);

        return NULL;
    }

    // Adiciona a linha atual ao array de números de linha e incrementa a contagem de linhas.
    tabelaAux->lineNumbers[0] = linha;
    tabelaAux->lineCount = 1;

    return tabelaAux;
}

// Função para inicializar a tabela de símbolos
void initTabela()
{
    int i;
    // Aloca memória para um array de ponteiros para struct tabelaSimbolos
    tabela = (struct tabelaSimbolos **)malloc(250 * sizeof(struct tabelaSimbolos *));

    // Verifica se a alocação de memória foi bem-sucedida.
    if (tabela == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para a tabela de símbolos\n");
        return;
    }

    // Inicializa todos os elementos do array com NULL.
    for (i = 0; i < 250; i++)
    {
        tabela[i] = NULL;
    }
}

// Função para verificar a existência de um identificador na tabela de símbolos e adicionar a linha correspondente
bool checkAndAddLine(int indice, char *identificador, char *escopo, int numeroLinha)
{
    // Acessa a lista de símbolos no índice hash especificado
    struct tabelaSimbolos *atual = tabela[indice];

    // Itera sobre a lista de símbolos no índice especificado
    while (atual)
    {
        // Verifica se o símbolo atual corresponde ao identificador e escopo fornecidos
        if (strcmp(atual->ID, identificador) == 0 &&
            (strcmp(atual->scope, escopo) == 0 || strcmp(atual->scope, "global") == 0))
        {
            // Se o símbolo ainda não tiver um registro de linhas, aloca espaço para ele
            if (atual->lineNumbers == NULL)
            {
                atual->lineNumbers = (int *)malloc(sizeof(int));
                atual->lineCount = 0;
            }
            // Se já existir um registro, realoca o espaço para acomodar a nova linha
            else
            {
                int *temp = (int *)realloc(atual->lineNumbers, (atual->lineCount + 1) * sizeof(int));
                atual->lineNumbers = temp;
            }
            // Adiciona o número da nova linha ao registro e incrementa a contagem de linhas
            atual->lineNumbers[atual->lineCount] = numeroLinha;
            atual->lineCount++;

            // Retorna false indicando que o símbolo já existe e não é necessário inserir um novo
            return false;
        }
        // Passa para o próximo símbolo na lista
        atual = atual->next;
    }
    // Retorna true indicando que o símbolo não foi encontrado e um novo deve ser inserido
    return true;
}

// Função para adicionar um novo símbolo na tabela de símbolos
void addNewSymbolToTable(int indice, char *escopo, int tipoDados, char *identificador, type tipoId, int numeroLinha)
{
    // Cria um novo símbolo com os dados fornecidos e aloca espaço para ele
    struct tabelaSimbolos *novoSimbolo = allocateTabela(escopo, tipoDados, identificador, tipoId, numeroLinha);

    // Verifica se o novo símbolo foi criado com sucesso
    if (novoSimbolo)
    {
        // Procura o último símbolo na lista de símbolos para o índice hash fornecido
        struct tabelaSimbolos *ultimo = tabela[indice];
        while (ultimo && ultimo->next)
        {
            ultimo = ultimo->next;
        }

        // Se encontrou um último símbolo, adiciona o novo símbolo após ele
        if (ultimo)
        {
            ultimo->next = novoSimbolo;
            novoSimbolo->last = ultimo; // Configura o ponteiro 'last' do novo símbolo para apontar para o anterior
        }
        // Se não encontrou um último símbolo, significa que é o primeiro símbolo para esse índice
        else
        {
            tabela[indice] = novoSimbolo;
        }
    }
}

// Função para inserir um novo símbolo ou atualizar um existente na tabela de símbolos
void pushTabela(type tipoId, int tipoDados, char *identificador, char *escopo, int numeroLinha)
{
    // Calcula o índice hash para o identificador fornecido
    int indice = getHash(identificador);

    // Verifica se já existe um símbolo no índice hash calculado
    if (tabela[indice])
    {
        // Se existir, verifica se é necessário adicionar uma nova linha ao símbolo existente
        // A função checkAndAddLine retorna true se um novo símbolo precisa ser adicionado
        if (checkAndAddLine(indice, identificador, escopo, numeroLinha))
        {
            // Se for necessário adicionar um novo símbolo, chama a função addNewSymbolToTable
            addNewSymbolToTable(indice, escopo, tipoDados, identificador, tipoId, numeroLinha);
        }
    }
    else
    {
        // Se não existir nenhum símbolo no índice, adiciona um novo símbolo na tabela
        addNewSymbolToTable(indice, escopo, tipoDados, identificador, tipoId, numeroLinha);
    }
}

// Função para calcular o hash de uma string
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

// Função para adicionar uma linha à lista de números de linha de uma entrada na tabela de símbolos
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

        // Verifique se o realocamento foi bem-sucedido
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

// Função para verificar se um tipo de nó corresponde a uma declaração
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
        return true; // O tipo de nó corresponde a uma declaração
    default:
        return false; // O tipo de nó não corresponde a uma declaração
    }
}

// Função para verificar se um tipo de nó corresponde a uma expressão
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
        return true; // O tipo de nó corresponde a uma expressão
    default:
        return false; // O tipo de nó não corresponde a uma expressão
    }
}

// Função para percorrer a árvore de análise sintática e processar os nós
void searchTree(ASTNode *node, char *scope)
{
    char *auxScope = NULL;

    // Aloca memória para uma cópia do escopo atual
    auxScope = (char *)malloc(30 * sizeof(char));

    // Copia o escopo atual para a variável auxiliar
    strcpy(auxScope, scope);

    // Verifica se o nó é nulo
    if (node == NULL)
        return;

    ASTNode *nodeAux = NULL;
    int auxTipo;

    // Verifica o tipo de nó e executa a função apropriada com base no tipo
    if (node->type == R_var_declaracao || node->type == R_var_declaracao_vet)
    {
        handleVarDeclaration(node, auxScope); // Processa declaração de variável
    }

    else if ((node->type == R_fun_declaracao))
    {
        handleFunctionDeclaration(node, auxScope); // Processa declaração de função
    }

    if (node->type == R_var_id)
    {
        handleVarIdDeclaration(node, scope); // Processa identificador de variável
    }

    else if (node->type == R_var_vet)
    {
        handleVarVetDeclaration(node, scope); // Processa identificador de vetor
    }

    else if (node->type == R_ativacao)
    {
        handleFunctionActivation(node, scope); // Processa ativação de função
    }

    else if (node->type == R_expressao)
    {
        handleExpression(node); // Processa expressão
    }

    // Verifica se o nó não é uma ativação de função
    if (node->type != R_ativacao)
    {
        // Percorre os filhos do nó
        if (node->left)
            searchTree(node->left, auxScope);
        if (node->middle)
            searchTree(node->middle, auxScope);
        if (node->right)
            searchTree(node->right, auxScope);
    }

    // Continua a busca na árvore pelos irmãos do nó atual
    searchTree(node->sibling, scope);

    // Libera a memória alocada para o escopo auxiliar
    freeAuxScope(auxScope);
}

// Função para verificar se um tipo de nó é válido para declaração
bool isValidType(type nodeType)
{
    // Inicia um switch case para o tipo do nó
    switch (nodeType)
    {
    // Casos em que o tipo do nó é considerado válido
    case R_var_declaracao:
    case R_var_declaracao_vet:
    case R_param_int:
    case R_param_vet:
        return true; // Retorna verdadeiro para tipos válidos
    default:
        return false; // Retorna falso para tipos inválidos
    }
}

// Função para procurar na tabela de símbolos ao declarar uma função
struct tabelaSimbolos *procurarNaTabelaParaDeclaracaoFuncao(ASTNode *auxNode)
{
    // Calcula o índice hash com base no nome do identificador da função
    unsigned int indice = getHash(auxNode->lexema->lexemaBuffer);

    // Obtém o ponteiro para a lista de símbolos no índice calculado
    struct tabelaSimbolos *aux = tabela[indice];

    // Percorre a lista de símbolos no índice
    while (aux)
    {
        // Compara o nome do identificador da função com o nome na tabela de símbolos
        if (strcmp(auxNode->lexema->lexemaBuffer, aux->ID) == 0)
            return aux; // Retorna o ponteiro para o símbolo se encontrado

        // Avança para o próximo símbolo na lista
        aux = aux->next;
    }

    return NULL; // Retorna NULL se o símbolo não for encontrado na tabela
}

// Função para procurar na tabela de símbolos em outros casos
struct tabelaSimbolos *procurarNaTabelaParaOutrosCasos(ASTNode *auxNode, char *scope)
{
    // Calcula o índice hash com base no nome do identificador em auxNode
    unsigned int indice = getHash(auxNode->lexema->lexemaBuffer);

    // Obtém o ponteiro para a lista de símbolos no índice calculado
    struct tabelaSimbolos *aux = tabela[indice];

    // Percorre a lista de símbolos no índice
    while (aux)
    {
        // Compara o nome do identificador em auxNode com o nome na tabela de símbolos
        if (strcmp(auxNode->lexema->lexemaBuffer, aux->ID) == 0)
        {
            // Verifica se o escopo corresponde ao escopo atual ou é "global"
            if (strcmp(scope, aux->scope) == 0 || strcmp(aux->scope, "global") == 0)
                return aux; // Retorna o ponteiro para o símbolo se encontrado

            // Verifica se o tipo de símbolo é uma função, se sim, também retorna o ponteiro
            if (aux->typeId == R_fun_declaracao)
                return aux;
        }

        // Avança para o próximo símbolo na lista
        aux = aux->next;
    }

    return NULL; // Retorna NULL se o símbolo não for encontrado na tabela
}

// Função para buscar um identificador na tabela de símbolos
int searchTabela(ASTNode *node, int position, char *scope)
{
    ASTNode *auxNode = NULL;

    // Determina qual filho (left, middle, ou right) do nó atual será examinado com base em 'position'
    if (position == 0)
        auxNode = node->left;
    else if (position == 1)
        auxNode = node->middle;
    else if (position == 2)
        auxNode = node->right;

    struct tabelaSimbolos *tabelaAux = NULL;

    // Verifica se o nó atual é uma declaração de função ou outro caso (variável, vetor, etc.)
    if (node->type == R_fun_declaracao)
        tabelaAux = procurarNaTabelaParaDeclaracaoFuncao(auxNode);
    else
        tabelaAux = procurarNaTabelaParaOutrosCasos(auxNode, scope);

    // Chama a função verifyErrors para verificar e lidar com erros relacionados ao identificador
    return verifyErrors(tabelaAux, node, auxNode, scope);
}

// Função para verificar e lidar com erros relacionados a identificadores na tabela de símbolos
int verifyErrors(struct tabelaSimbolos *tabelaAux, struct ASTNode *node, struct ASTNode *auxNode, const char *scope)
{
    // Verifica se o identificador não foi encontrado na tabela de símbolos
    if (tabelaAux == NULL)
        return 1;

    // Verifica se o identificador já foi declarado como uma função e o nó atual também é uma declaração de função
    if (tabelaAux->typeId == R_fun_declaracao && node->type == R_fun_declaracao)
    {
        printf("\033[1;31mErro: Função '%s' já foi declarada anteriormente.\n\033[0m", auxNode->lexema->lexemaBuffer);
        return 0;
    }

    // Verifica se o identificador é de um tipo válido (por exemplo, variável, vetor, parâmetro)
    if (isValidType(tabelaAux->typeId))
    {
        if (isValidType(node->type))
        {
            // Verifica se o identificador foi declarado em um escopo diferente
            if ((strcmp(tabelaAux->scope, scope) != 0) && (strcmp(tabelaAux->scope, "global") != 0))
                return 1;

            printf("\033[1;31mErro: Identificador '%s' já foi declarado em um escopo diferente.\n\033[0m", auxNode->lexema->lexemaBuffer);
            return 0;
        }
        else if (node->type == R_fun_declaracao)
        {
            printf("\033[1;31mErro: Identificador '%s' já foi declarado em um escopo diferente.\n\033[0m", auxNode->lexema->lexemaBuffer);
            return 0;
        }
    }

    // Verifica se o identificador é uma função e o nó atual tenta usá-lo como variável ou vetor
    if (tabelaAux->typeId == R_fun_declaracao && isValidType(node->type))
    {
        if (isValidType(node->type))
        {
            printf("\033[1;31mErro: Identificador '%s' usado para variável ou vetor já existe como função.\n\033[0m", auxNode->lexema->lexemaBuffer);
            return 0;
        }
    }

    return 0;
}

// Função para retornar o tipo da regra
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

// Função para retornar o tipo da vairavel
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

// Função para printar a tabela
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

void freeTabela()
{
    if (tabela == NULL)
    {
        return; // A tabela já está desalocada ou nunca foi alocada
    }

    for (int i = 0; i < 250; i++)
    { // Assumindo que a tabela tem 250 entradas, como no initTabela
        struct tabelaSimbolos *current = tabela[i];
        while (current != NULL)
        {
            struct tabelaSimbolos *next = current->next;

            // Libera a memória de cada campo alocado dinamicamente
            free(current->ID);
            free(current->scope);
            free(current->lineNumbers);

            // Libera a memória da estrutura atual
            free(current);

            current = next; // Avança para o próximo elemento
        }
    }

    // Libera a memória do array de ponteiros
    free(tabela);
    tabela = NULL; // Evita dangling pointers
}

void freeAuxScope(char *auxScope)
{
    free(auxScope);
}