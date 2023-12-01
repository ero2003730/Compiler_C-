#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define N 500

// Variáveis globais que ajudarão a fazer o exercício
extern char *buffer;          // Buffer principal
extern int position;          // Contador de posição
extern int max_position;      // Variável de auxílio
extern int reprocess;         // Variável estática para controlar o reprocessamento
extern int max_position;      // Variável de auxílio
extern FILE *file;            // Arquivo que está sendo analisado
extern struct Lexema *lexema; // Struct do lexema
extern int lines;             // Inicializa a contagem de linhas
extern int aux;               // Posição na struct
extern int final;             // Variável final arquivo
extern char *ultimoLexema;    // Uma variável global para armazenar o último lexema processado
extern int ultimaLinha;       // Variável que irá identificar a linha do erro

typedef enum
{
    T_INIC = 0,          // INICIO
    T_INT = 1,           // INT
    T_IF = 2,            // IF
    T_RETURN = 3,        // RETURN
    T_ELSE = 4,          // ELSE
    T_VOID = 5,          // VOID
    T_WHILE = 6,         // WHILE
    T_ID = 7,            // ID
    T_NUM = 8,           // NUM
    T_PLUS = 9,          // SUM
    T_MINUS = 10,        // MINUS
    T_MULTIPLY = 11,     // MULTIPLY
    T_DIVIDE = 12,       // BAR
    T_EQUALS = 13,       // EQUAL
    T_GT = 14,           // GREATER (Greater Than)
    T_RPAREN = 15,       // PARENTHESIS_RIGHT
    T_LPAREN = 16,       // PARENTHESIS_LEFT
    T_SEMICOLON = 17,    // SEMICOMMA
    T_ASSIGN = 18,       // ATRIBUTION
    T_LT = 19,           // LESSER (Less Than)
    T_LE = 20,           // EQUALorLESSER (Less or Equal)
    T_GE = 21,           // EQUALorGREATER (Greater or Equal)
    T_COMMA = 22,        // COMMA
    T_OPENBRACKET = 23,  // OPEN BRACKET
    T_CLOSEBRACKET = 24, // CLOSE BRACKET
    T_OPENBRACE = 25,    // OPEN BRACE
    T_CLOSEBRACE = 26,   // CLOSE BRACE
    T_NET = 27,          // NOT EQUAL
} token;

// struct do Lexema, que contem cada lexema e as linhas
struct Lexema
{
    char *lexemaBuffer;
    int linha;
    token token;
};

typedef struct BSTNode
{
    char *keyword;
    token tok;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

void allocate_buffer();                                                            // Função para alocar memória
int fill_buffer(FILE *file);                                                       // Função para preencher o buffer
void get_token();                                                                  // Função para pegar o proximo token
char get_next_char(FILE *file);                                                    // Função para pegar o próximo caractere do buffer
int get_position(char c);                                                          // Função que irá pegar qual a coluna da matriz do caractere
void get_lexema(char *lexemaBuffer, int aux, int i);                               // Função que irá pegar o lexema e verificar o token
char *return_Token(int token);                                                     // Função que retorna o token (no ENUM)
BSTNode *initBST();                                                                // Função para iniciar a árvore de busca binária
token searchInBST(BSTNode *node, char *keyword);                                   // Função que irá procurar a palavra reservada
BSTNode *newBSTNode(char *keyword, token tok);                                     // Função do novo nó
BSTNode *insertIntoBST(BSTNode *node, char *keyword, token tok);                   // Função para inserir no nó
void identify_keyword_or_id_using_bst(char *lexemaBuffer, int aux, BSTNode *root); // Função para chamar a busca
void deallocate_buffer();                                                          // Função para desalocar memória
void deallocateBST(BSTNode *node);                                                 // Função para desalocar memória da árvore