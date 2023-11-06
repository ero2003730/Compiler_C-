#include "funcs.h"

// Variáveis globais que ajudarão a fazer o exercício
char *buffer = NULL;
int position = 0;
int max_position = 0;
int reprocess = 0;
char last_char;
// Definição da tabela hash
HashItem hashTable[TABLE_SIZE];

// Função para alocar memória para o buffer
void allocate_buffer(struct Lexema **lexema)
{
    buffer = (char *)malloc(sizeof(char) * 1000);                   // Aloca espaço para o buffer
    (*lexema) = (struct Lexema *)malloc(N * sizeof(struct Lexema)); // Aloca espaço para a estrutura Lexema
    for (int i = 0; i < N; i++)
    {
        (*lexema)[i].lexemaBuffer = (char *)malloc(64 * sizeof(char)); // Aloca espaço para o buffer do lexema
    }
}

// Função para desalocar memória do buffer
void deallocate_buffer(struct Lexema **lexema)
{
    free(buffer); // Libera a memória alocada para a estrutura do Buffer
    for (int i = 0; i < N; i++)
    {
        free((*lexema)[i].lexemaBuffer); // Libera a memória alocada para lexemaBuffer
    }
    free(*lexema); // Libera a memória alocada para a estrutura Lexema
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
void get_lexema(char *lexemaBuffer, struct Lexema **lexema, int aux, int i)
{
    // Para todos os lexemas verificar se o que tiver no buffer é uma palavra reservada, caso for
    // colocar o respectivo token que representa esse lexema e alinha, depois printar
    if (isdigit(lexemaBuffer[0]))
    {
        (*lexema)[aux].token = T_NUM;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '<' && i > 1 && lexemaBuffer[1] == '=')
    {
        (*lexema)[aux].token = T_LE;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '<')
    {
        (*lexema)[aux].token = T_LT;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '>' && i > 1 && lexemaBuffer[1] == '=')
    {
        (*lexema)[aux].token = T_GE;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '>')
    {
        (*lexema)[aux].token = T_GT;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '=')
    {
        if (i == 1)
        {
            (*lexema)[aux].token = T_ASSIGN;
            printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
            return;
        }
        else
        {
            (*lexema)[aux].token = T_EQUALS;
            printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
            return;
        }
    }

    else if (lexemaBuffer[0] == '+')
    {
        (*lexema)[aux].token = T_PLUS;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '-')
    {
        (*lexema)[aux].token = T_MINUS;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '*')
    {
        (*lexema)[aux].token = T_MULTIPLY;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == ';')
    {
        (*lexema)[aux].token = T_SEMICOLON;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == ',')
    {
        (*lexema)[aux].token = T_COMMA;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '(')
    {
        (*lexema)[aux].token = T_LPAREN;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == ')')
    {
        (*lexema)[aux].token = T_RPAREN;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '[')
    {
        (*lexema)[aux].token = T_OPENBRACKET;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == ']')
    {
        (*lexema)[aux].token = T_CLOSEBRACKET;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '{')
    {
        (*lexema)[aux].token = T_OPENBRACE;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '}')
    {
        (*lexema)[aux].token = T_CLOSEBRACE;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
        return;
    }

    else if (lexemaBuffer[0] == '!')
    {
        if (i == 2 && lexemaBuffer[1] == '=')
        {
            (*lexema)[aux].token = T_NET;
            printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
            return;
        }
    }

    else if (lexemaBuffer[0] == '/')
    {
        (*lexema)[aux].token = T_DIVIDE;
        printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
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
        return "Int";
    case 1:
        return "If";
    case 2:
        return "Return";
    case 3:
        return "Else";
    case 4:
        return "Void";
    case 5:
        return "While";
    case 6:
        return "ID";
    case 7:
        return "Num";
    case 8:
        return "Plus";
    case 9:
        return "Minus";
    case 10:
        return "Multiply";
    case 11:
        return "Divide";
    case 12:
        return "Equals";
    case 13:
        return "Greater";
    case 14:
        return "Right Parenthesis";
    case 15:
        return "Left Parenthesis";
    case 16:
        return "Semicolon";
    case 17:
        return "Assign";
    case 18:
        return "Less";
    case 19:
        return "Less or Equal";
    case 20:
        return "Greater or Equal";
    case 21:
        return "Comma";
    case 22:
        return "Open Bracket";
    case 23:
        return "Close Bracket";
    case 24:
        return "Open Brace";
    case 25:
        return "Close Brace";
    case 26:
        return "Not Equal";
    }
}

unsigned int hashFunction(char *str)
{
    unsigned int hashValue = 0;
    while (*str)
    {
        hashValue = (hashValue << 5) + *str++; // Função hash simples usando deslocamento
    }
    return hashValue % TABLE_SIZE;
}

void insertIntoHashTable(char *keyword, token tok)
{
    unsigned int index = hashFunction(keyword);
    while (hashTable[index].keyword != NULL && strcmp(hashTable[index].keyword, keyword) != 0)
    {
        index = (index + 1) % TABLE_SIZE; // Probing linear
    }
    hashTable[index].keyword = keyword;
    hashTable[index].tok = tok;
}

token searchInHashTable(char *keyword)
{
    unsigned int index = hashFunction(keyword);
    while (hashTable[index].keyword != NULL)
    {
        if (strcmp(hashTable[index].keyword, keyword) == 0)
        {
            return hashTable[index].tok;
        }
        index = (index + 1) % TABLE_SIZE; // Probing linear
    }
    return T_ID; // Se a palavra-chave não for encontrada, retorne T_ID
}

void initHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].keyword = NULL;
        hashTable[i].tok = T_ID;
    }

    insertIntoHashTable("else", T_ELSE);
    insertIntoHashTable("if", T_IF);
    insertIntoHashTable("int", T_INT);
    insertIntoHashTable("return", T_RETURN);
    insertIntoHashTable("void", T_VOID);
    insertIntoHashTable("while", T_WHILE);
}

void identify_keyword_or_id_using_hash(char *lexemaBuffer, struct Lexema **lexema, int aux)
{
    (*lexema)[aux].token = searchInHashTable(lexemaBuffer);
    printf("Linha: %d, Lexema: %s, Token: %s\n", (*lexema)[aux].linha, (*lexema)[aux].lexemaBuffer, return_Token((*lexema)[aux].token));
}
