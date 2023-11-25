#include "funcs.h"

// Variáveis globais que ajudarão a fazer o exercício
char *buffer = NULL;
int position = 0;
int max_position = 0;
int reprocess = 0;
char last_char;
FILE *file;
struct Lexema *lexema;
int lines = 1; // Inicializa a contagem de linhas
int aux = 0;
int final = 0;
char *ultimoLexema = NULL; // Inicialize com NULL
int ultimaLinha = 1;

// Função para alocar memória para o buffer
void allocate_buffer()
{
    buffer = (char *)malloc(sizeof(char) * 1000);                  // Aloca espaço para o buffer
    (lexema) = (struct Lexema *)malloc(N * sizeof(struct Lexema)); // Aloca espaço para a estrutura Lexema
    for (int i = 0; i < N; i++)
    {
        (lexema)[i].lexemaBuffer = (char *)malloc(64 * sizeof(char)); // Aloca espaço para o buffer do lexema
    }
}

// Função para desalocar memória do buffer
void deallocate_buffer()
{
    free(buffer); // Libera a memória alocada para a estrutura do Buffer
    for (int i = 0; i < N; i++)
    {
        free((lexema)[i].lexemaBuffer); // Libera a memória alocada para lexemaBuffer
    }
    free(lexema); // Libera a memória alocada para a estrutura Lexema
}

// Função que irá preencher o buffer com as coisas contidas no arquivo
int fill_buffer(FILE *file)
{
    /*
    Função fgets automaticamente salva no primeiro argumento, a quantidade estipulada no segundoS
    argumento, contendo as informações no terceiro argumento, ao mesmo tempo em que é retornado
    o que for salvo no primeiro argumento
    */
    char *aux_buffer = fgets(buffer, 256, file);

    // Se estiver vzio o aux_buffer, então quer fizer que nada foi adicionado, logo, não tem nada
    // a adicionar, então apenas retornar para acabar
    if (aux_buffer == NULL)
    {
        return -1;
    }

    // Retornar o valor do aux_buffer, para auxiliar. Como buffer é uma variável global, então
    // seu valor já ta armazenado, então não precisar retorna-lo
    return strlen(aux_buffer);
}

// Função que irá retornar o próximo char
char get_next_char(FILE *file)
{

    // Quando reprocess == 1, então preciso retornar o último caractere, caso contrário, continua normalmente
    if (reprocess)
    {
        reprocess = 0;
        return buffer[position - 1];
    }

    /*
        Uma verificação de posição. No caso inicial, ambos são igual a 0, logo mandar preencher o buffer
        com as informações do arquivo. Caso max_position seja = -1, quer dizer que nada foi inserido no
        buffer, portanto, não tem nada no arquivo então apenas retornar. Depois disso, por causa da main,
        get_next_char é chamada até que o arquivo esteja vazio. Porém, como max_position recebeu o tamanho
        do buffer, quando a posição for igual a max_position, então quer dizer que chegou ao final do vetor
        do buffer, então passaria no if, então iria preencher de novo. Caso não fosse preenchido nada então
        apenas retornar (encerrar o processo), caso contrário, repetir processo
        */

    if (position == max_position)
    {
        max_position = fill_buffer(file);

        if (max_position == -1)
        {
            return EOF;
        }
        position = 0;
    }

    char c = buffer[position++];

    return c;
}

// Função que irá retornar a posição, da coluna da matriz, dos caracteres da linguagem
int get_position(char c)
{
    if (isalpha(c))
        return 0;
    if (isdigit(c))
        return 1;
    if (c == '<')
        return 2;
    if (c == '>')
        return 3;
    if (c == '=')
        return 4;
    if (c == '+')
        return 5;
    if (c == '-')
        return 6;
    if (c == '*')
        return 7;
    if (c == '/')
        return 8;
    if (c == '!')
        return 9;
    if (c == ';')
        return 10;
    if (c == ',')
        return 11;
    if (c == '(')
        return 12;
    if (c == ')')
        return 13;
    if (c == '[')
        return 14;
    if (c == ']')
        return 15;
    if (c == '{')
        return 16;
    if (c == '}')
        return 17;
    if (c == ' ')
        return 18;
    if (c == '\n')
        return 19;
    if (c == '\0')
        return 20;

    // Caso o caractere não esteja na lista, retorne um valor padrão
    return -1;
}

// Função que irá retornar o lexema, o token desse lexema e a linha do lexema
void get_lexema(char *lexemaBuffer, int aux, int i)
{
    // Para todos os lexemas verificar se o que tiver no buffer é uma palavra reservada, caso for
    // colocar o respectivo token que representa esse lexema e alinha, depois printar
    if (isdigit(lexemaBuffer[0]))
    {
        (lexema)[aux].token = T_NUM;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '<' && i > 1 && lexemaBuffer[1] == '=')
    {
        (lexema)[aux].token = T_LE;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '<')
    {
        (lexema)[aux].token = T_LT;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '>' && i > 1 && lexemaBuffer[1] == '=')
    {
        (lexema)[aux].token = T_GE;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '>')
    {
        (lexema)[aux].token = T_GT;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '=')
    {
        if (i == 1)
        {
            (lexema)[aux].token = T_ASSIGN;
            // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
            return;
        }
        else
        {
            (lexema)[aux].token = T_EQUALS;
            // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
            return;
        }
    }

    else if (lexemaBuffer[0] == '+')
    {
        (lexema)[aux].token = T_PLUS;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '-')
    {
        (lexema)[aux].token = T_MINUS;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '*')
    {
        (lexema)[aux].token = T_MULTIPLY;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == ';')
    {
        (lexema)[aux].token = T_SEMICOLON;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == ',')
    {
        (lexema)[aux].token = T_COMMA;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '(')
    {
        (lexema)[aux].token = T_LPAREN;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == ')')
    {
        (lexema)[aux].token = T_RPAREN;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '[')
    {
        (lexema)[aux].token = T_OPENBRACKET;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == ']')
    {
        (lexema)[aux].token = T_CLOSEBRACKET;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '{')
    {
        (lexema)[aux].token = T_OPENBRACE;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '}')
    {
        (lexema)[aux].token = T_CLOSEBRACE;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '!')
    {
        if (i == 2 && lexemaBuffer[1] == '=')
        {
            (lexema)[aux].token = T_NET;
            // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
            return;
        }
    }

    else if (lexemaBuffer[0] == '/')
    {
        (lexema)[aux].token = T_DIVIDE;
        // printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else
    {
        // erro
    }
}

// Função que irá retornar o token do lexema
char *return_Token(int token)
{
    switch (token)
    {
    case 0:
        break;
    case 1:
        return "Int";
    case 2:
        return "If";
    case 3:
        return "Return";
    case 4:
        return "Else";
    case 5:
        return "Void";
    case 6:
        return "While";
    case 7:
        return "ID";
    case 8:
        return "Num";
    case 9:
        return "Plus";
    case 10:
        return "Minus";
    case 11:
        return "Multiply";
    case 12:
        return "Divide";
    case 13:
        return "Equals";
    case 14:
        return "Greater";
    case 15:
        return "Right Parenthesis";
    case 16:
        return "Left Parenthesis";
    case 17:
        return "Semicolon";
    case 18:
        return "Assign";
    case 19:
        return "Less";
    case 20:
        return "Less or Equal";
    case 21:
        return "Greater or Equal";
    case 22:
        return "Comma";
    case 23:
        return "Open Bracket";
    case 24:
        return "Close Bracket";
    case 25:
        return "Open Brace";
    case 26:
        return "Close Brace";
    case 27:
        return "Not Equal";
    default:
        printf("Caso padrão alcançado em return_Token com token: %d\n", token);
        return "Token Desconhecido";
    }
}

// Função auxiliar
void analisadorSintatico()
{
    int toks = -1;
    while (final != 1 && final != -1)
    {
        get_token();

        if (lexema[aux].token != 0)
        {
            printf("Lexema: %s, Token: %s, Linha: %d\n", lexema[aux].lexemaBuffer, return_Token(lexema[aux].token), lines);
            aux++;
        }
    }
}

// Função que irá retornar o próximo token, um por um, que será analisado pelo analisador léxico
void get_token()
{
    static BSTNode *root = NULL;

    if (root == NULL)
        root = initBST();

    // Matriz principal dos estados
    int matriz[13][21] = {
        // Colunas: letra numero < > = + - * / ! ; , ( ) [ ] { } espaço \n \0
        {1, 2, 3, 3, 3, 4, 4, 4, 7, 6, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0},                       // estado q0 (inicial)
        {1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},   // estado q1
        {10, 2, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},   // estado q2
        {10, 10, 10, 10, 4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},   // estado q3
        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},  // estado q4
        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},  // estado q5
        {11, 11, 11, 11, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},  // estado q6
        {10, 10, 10, 10, 10, 10, 10, 8, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},   // estado q7
        {8, 8, 8, 8, 8, 8, 8, 9, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},                       // estado q8
        {8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},                       // estado q9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                       // estado q10 (final)
        {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},  // estado q11 (erro)
        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}}; // estado de transicao para '!=' pois estava dando erro

    // Variaveis auxiliares
    char c;
    int estado = 0, novo_estado = 0;
    int coluna = 0;
    int i = 0;

    c = get_next_char(file);

    if (c == EOF)
    {
        final = 1;
        return;
    }

    if (c == '\n')
    {
        lines++;
    }

    // Loop até encontrar um lexema válido (ou um erro)
    while (1)
    {
        // Pega a coluna em que o caractere se refere
        coluna = get_position(c);

        // Se coluna == -1, significa que não foi encontrado o caractere
        // Logo não é um caractere pertencente a linguagem C-
        if (coluna == -1)
        {
            printf("Erro: caractere: '%c', na linha %d não eh válido\n", c, lines);
            final = -1;
            return;
        }

        // Pegar o estado em que o caractere está transitando para
        novo_estado = matriz[estado][coluna];

        // Verificação de comentário, se o estado atual for = 7, e o estado que esta
        // sendo transitado para for = 8, então entramos no loop de comentario
        if (estado == 7 && novo_estado == 8)
        {
            // A primeira '/' do comentario é colocada no lexema, pois não satisfaz
            // a condição de estado = 7 e novo_estado = 8, então para não pegá-la,
            // iremos colocar um \0 para zerar
            lexema[aux].lexemaBuffer[0] = '\0';

            int comentarioFechado = 0;
            c = get_next_char(file);

            // While que ira pegar caractere por caractere dentro do comentario
            while (!comentarioFechado && c != EOF)
            {
                if (c == '\n')
                {
                    lines++;
                }

                // Caso o caractere seja = '*', então pegar o proximo char
                if (c == '*')
                {
                    c = get_next_char(file);

                    if (c == '\n')
                    {
                        lines++;
                    }

                    // Caso o próxio caractere seja igual a '/', então, acabou a
                    // condição de comentário, logo sair
                    if (c == '/')
                    {
                        comentarioFechado = 1;
                        // Pegar o caractere seguinte, pois o atual é o '/' e ele
                        // não pode ser adicionado como lexema
                        c = get_next_char(file);
                        break;
                    }
                }
                c = get_next_char(file);
            }

            // Se não encontrar o final do comentário, '*/' isso é um erro, logo printar erro
            if (!comentarioFechado)
            {
                printf("Erro: comentario nao fechado antes do fim do arquivo na linha %d\n", lines);
                final = -1;
                return;
            }
        }

        // Else para caso não satisfaça comentário
        else
        {
            // Verificar se estou no estado inicial, final ou de erro
            if (novo_estado == 0 || novo_estado == 10 || novo_estado == 11)
            {
                // Caso esteja no estado final (10), reprocessar o último caractere, para ser analisado
                if (novo_estado == 10)
                {
                    reprocess = 1;
                }

                // Dar break no loop de dentro para analisar se é estado final ou erro
                break;
            }

            // Se não for nenhum desses estados, então apenas adicionar o caractere no lexema
            lexema[aux].lexemaBuffer[i] = c;
            i++;
            c = get_next_char(file);

            // If para verificação de caso o caractere seguinte ser o EOF, então o que tiver no lexema
            // precisa ainda ser salvo
            if (c == EOF)
            {

                lexema[aux].linha = lines;

                // Se veio do estado 1, então é uma palavra, verificar, com complexidade > 0(n) se é palavra
                // reservada ou se é um identificador
                if (estado == 1)
                {
                    lexema[aux].lexemaBuffer[i] = '\0';
                    identify_keyword_or_id_using_bst(lexema[aux].lexemaBuffer, aux, root);
                }
                // Se não for um identificador apenas mandar para analisar o token
                else
                {
                    lexema[aux].lexemaBuffer[i] = '\0';
                    get_lexema(lexema[aux].lexemaBuffer, aux, i);
                }
            }

            estado = novo_estado;
        }
    }

    // Se o próximo estado for o final, então quer dizer que chegou numa condição que o lexema precisa
    // ser classificado
    if (novo_estado == 10)
    {
        int tok = -1;
        char *lex;

        lexema[aux].linha = lines;

        // Se veio do estado 1, então é uma palavra, verificar, com complexidade > 0(n) se é palavra
        // reservada ou se é um identificador
        if (estado == 1)
        {
            lexema[aux].lexemaBuffer[i] = '\0';
            identify_keyword_or_id_using_bst(lexema[aux].lexemaBuffer, aux, root);
        }
        // Se não for um identificador apenas mandar para analisar o token
        else
        {
            lexema[aux].lexemaBuffer[i] = '\0';
            get_lexema(lexema[aux].lexemaBuffer, aux, i);
        }

        // printf("Token dentro da funcao: %d\n", tok);
        // printf("Lexema dentro da funcao: %s\n", lex);
    }

    // Estado de erro. Para esse caso especifico, a unica condicao de erro da matriz é caso seja digitado
    // '!' e não seguir de '='
    else if (novo_estado == 11)
    {
        printf("Erro na linha %d: O caractere '!' foi encontrado, mas deve ser seguido imediatamente por um '=' para formar o operador '!=' válido.\n", lines);
        final = -1;
        return;
    }
}

// Função que irá criar a arvore sintatica
ASTNode *createNode(char *type, char *value, ASTNode *left, ASTNode *right)
{
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(1);
    }

    newNode->type = strdup(type);
    newNode->value = value ? strdup(value) : NULL;
    newNode->left = left;
    newNode->right = right;

    return newNode;
}

// Função para inicializar a árvore
BSTNode *initBST()
{
    BSTNode *root = NULL;

    root = insertIntoBST(root, "else", T_ELSE);
    root = insertIntoBST(root, "if", T_IF);
    root = insertIntoBST(root, "int", T_INT);
    root = insertIntoBST(root, "return", T_RETURN);
    root = insertIntoBST(root, "void", T_VOID);
    root = insertIntoBST(root, "while", T_WHILE);

    return root;
}

// Função do novo nó
BSTNode *newBSTNode(char *keyword, token tok)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->keyword = strdup(keyword);
    node->tok = tok;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para inserir novo nó
BSTNode *insertIntoBST(BSTNode *node, char *keyword, token tok)
{
    if (node == NULL)
        return newBSTNode(keyword, tok);

    if (strcmp(keyword, node->keyword) < 0)
        node->left = insertIntoBST(node->left, keyword, tok);

    else if (strcmp(keyword, node->keyword) > 0)
        node->right = insertIntoBST(node->right, keyword, tok);

    return node; // Retorna o ponteiro do nó (inalterado)
}

// Função para buscar novo nó
token searchInBST(BSTNode *node, char *keyword)
{
    if (node == NULL)
        return T_ID; // Não encontrado

    if (strcmp(keyword, node->keyword) == 0)
        return node->tok;
    if (strcmp(keyword, node->keyword) < 0)
        return searchInBST(node->left, keyword);
    else
        return searchInBST(node->right, keyword);
}

// Função para printar
void identify_keyword_or_id_using_bst(char *lexemaBuffer, int aux, BSTNode *root)
{
    (lexema)[aux].token = searchInBST(root, lexemaBuffer);
    // printf("Linha: %d, Lexema: %s, Token: %s\n", (lexema)[aux].linha, (lexema)[aux].lexemaBuffer, return_Token((lexema)[aux].token));
}
