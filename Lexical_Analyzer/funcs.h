#ifndef FUNCS_H
#define FUNCS_H

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

typedef enum
{
    T_INIC,         // INICIO
    T_INT,          // INT
    T_IF,           // IF
    T_RETURN,       // RETURN
    T_ELSE,         // ELSE
    T_VOID,         // VOID
    T_WHILE,        // WHILE
    T_ID,           // ID
    T_NUM,          // NUM
    T_PLUS,         // SUM
    T_MINUS,        // MINUS
    T_MULTIPLY,     // MULTIPLY
    T_DIVIDE,       // BAR
    T_EQUALS,       // EQUAL
    T_GT,           // GREATER (Greater Than)
    T_RPAREN,       // PARENTHESIS_RIGHT
    T_LPAREN,       // PARENTHESIS_LEFT
    T_SEMICOLON,    // SEMICOMMA
    T_ASSIGN,       // ATRIBUTION
    T_LT,           // LESSER (Less Than)
    T_LE,           // EQUALorLESSER (Less or Equal)
    T_GE,           // EQUALorGREATER (Greater or Equal)
    T_COMMA,        // COMMA
    T_OPENBRACKET,  // OPEN BRACKET
    T_CLOSEBRACKET, // CLOSE BRACKET
    T_OPENBRACE,    // OPEN BRACE
    T_CLOSEBRACE,   // CLOSE BRACE
    T_NET,          // NOT EQUAL
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
void analisadorSintatico();                                                        // Printando
void deallocate_buffer();                                                          // Função para desalocar memória
BSTNode *initBST();                                                                // Função para iniciar a árvore de busca binária
token searchInBST(BSTNode *node, char *keyword);                                   // Função que irá procurar a palavra reservada
BSTNode *newBSTNode(char *keyword, token tok);                                     // Função do novo nó
BSTNode *insertIntoBST(BSTNode *node, char *keyword, token tok);                   // Função para inserir no nó
void identify_keyword_or_id_using_bst(char *lexemaBuffer, int aux, BSTNode *root); // Função para chamar a busca

#endif
