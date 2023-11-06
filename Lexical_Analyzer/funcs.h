#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define N 500
#define TABLE_SIZE 13 // Escolhendo um número primo para a tabela hash
#include <ctype.h>    // necessário para tolower()

// Variáveis globais que ajudarão a fazer o exercício
extern char *buffer;     // Buffer principal
extern int position;     // Contador de posição
extern int max_position; // Variável de auxílio
extern int reprocess;    // Variável estática para controlar o reprocessamento
extern int max_position; // Variável de auxílio

// extern HashItem hashTable[TABLE_SIZE];

typedef enum
{
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

struct Lexema
{
    char *lexemaBuffer;
    int linha;
    int token;
};

typedef struct HashItem
{
    char *keyword;
    token tok;
} HashItem;

int fill_buffer(FILE *file);                                                 // Função para preencher o buffer
void deallocate_buffer(struct Lexema **lexema);                              // Função para desalocar memória
char get_next_char(FILE *file);                                              // Função que irá retornar o caractere para printar
void get_lexema(char *lexemaBuffer, struct Lexema **lexema, int aux, int i); // Função que irá pegar o lexema e verificar o token
void allocate_buffer(struct Lexema **lexema);                                // Função para alocar memória
char *return_Token(int token);                                               // Função para alocar memória para o buffer
int get_position(char c);                                                    // Função que irá pegar qual a coluna da matriz]
unsigned int hashFunction(char *str);                                        // Protótipo da função hash
void insertIntoHashTable(char *keyword, token tok);                          // Protótipo para inserir na tabela hash
token searchInHashTable(char *keyword);                                      // Protótipo para buscar na tabela hash
void initHashTable();                                                        // Protótipo para inicializar a tabela hash
void identify_keyword_or_id_using_hash(char *lexemaBuffer, struct Lexema **lexema, int aux);

#endif
