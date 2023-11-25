%{
    #include <stdio.h>
    #include <stddef.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include "funcs.h" 
    #define YYSTYPE struct Lexema *

    int yylex();
    int yyparse();
    void yyerror(char *s);
%}

    %token TOKEN_INT 1
    %token TOKEN_IF 2
    %token TOKEN_RETURN 3
    %token TOKEN_ELSE 4
    %token TOKEN_VOID 5
    %token TOKEN_WHILE 6
    %token TOKEN_ID 7
    %token TOKEN_NUM 8
    %token TOKEN_PLUS 9
    %token TOKEN_MINUS 10
    %token TOKEN_MULTIPLY 11
    %token TOKEN_DIVIDE 12
    %token TOKEN_EQUALS 13
    %token TOKEN_GT 14
    %token TOKEN_RPAREN 15
    %token TOKEN_LPAREN 16
    %token TOKEN_SEMICOLON 17
    %token TOKEN_ASSIGN 18
    %token TOKEN_LT 19
    %token TOKEN_LE 20
    %token TOKEN_GE 21
    %token TOKEN_COMMA 22
    %token TOKEN_OPENBRACKET 23
    %token TOKEN_CLOSEBRACKET 24
    %token TOKEN_OPENBRACE 25
    %token TOKEN_CLOSEBRACE 26
    %token TOKEN_NET 27

%%

    programa : declaracao_lista ;

    declaracao_lista : declaracao_lista declaracao
                    | declaracao ;

    declaracao : var_declaracao
            | fun_declaracao ;

    var_declaracao : tipo_especificador TOKEN_ID TOKEN_SEMICOLON
                | tipo_especificador TOKEN_ID TOKEN_OPENBRACKET TOKEN_NUM TOKEN_CLOSEBRACKET TOKEN_SEMICOLON ;

    tipo_especificador : TOKEN_INT
                    | TOKEN_VOID ;

    fun_declaracao : tipo_especificador TOKEN_ID TOKEN_LPAREN params TOKEN_RPAREN composto_decl ;

    params : param_lista
        | TOKEN_VOID ;

    param_lista : param_lista TOKEN_COMMA param
                | param ;

    param : tipo_especificador TOKEN_ID
        | tipo_especificador TOKEN_ID TOKEN_OPENBRACKET TOKEN_CLOSEBRACKET ;

    composto_decl : TOKEN_OPENBRACE local_declaracoes statement_lista TOKEN_CLOSEBRACE ;

    local_declaracoes : local_declaracoes var_declaracao
                    | /* vazio */ ;

    statement_lista : statement_lista statement
                    | /* vazio */ ;

    statement : expressao_decl
            | composto_decl
            | selecao_decl
            | iteracao_decl
            | retorno_decl ;

    expressao_decl : expressao TOKEN_SEMICOLON
                | TOKEN_SEMICOLON ;

    selecao_decl : TOKEN_IF TOKEN_LPAREN expressao TOKEN_RPAREN statement
                | TOKEN_IF TOKEN_LPAREN expressao TOKEN_RPAREN statement TOKEN_ELSE statement ;

    iteracao_decl : TOKEN_WHILE TOKEN_LPAREN expressao TOKEN_RPAREN statement ;

    retorno_decl : TOKEN_RETURN TOKEN_SEMICOLON
                | TOKEN_RETURN expressao TOKEN_SEMICOLON ;

    expressao : var TOKEN_ASSIGN expressao
            | simples_expressao ;

    var : TOKEN_ID
        | TOKEN_ID TOKEN_OPENBRACKET expressao TOKEN_CLOSEBRACKET ;

    simples_expressao : soma_expressao relacional soma_expressao
                    | soma_expressao ;

    relacional : TOKEN_LE | TOKEN_LT | TOKEN_GT | TOKEN_GE | TOKEN_EQUALS | TOKEN_NET ;

    soma_expressao : soma_expressao soma termo
                | termo ;

    soma : TOKEN_PLUS | TOKEN_MINUS ;

    termo : termo mult fator
        | fator ;

    mult : TOKEN_MULTIPLY | TOKEN_DIVIDE ;

    fator : TOKEN_LPAREN expressao TOKEN_RPAREN
        | var
        | ativacao
        | TOKEN_NUM ;
    
    ativacao : TOKEN_ID TOKEN_LPAREN args TOKEN_RPAREN ;

    args : arg_lista
     | /* vazio */ ;

    arg_lista : arg_lista TOKEN_COMMA expressao
            | expressao ;


%%


void yyerror(char *s) 
{
    fprintf(stderr, "ERRO SINTÁTICO: %s, No lexema: '%s', na linha: %d\n", s, ultimoLexema, ultimaLinha);
}

int parse()
{
    yyparse();
}

int yylex()
{
    static int count = 0; // Contador para chamadas de yylex

    // Checa se o final do arquivo foi atingido
    if (final == 1 || final == -1) {
        return 0; // Retorna 0 para indicar o final do arquivo
    }

    // Obtém o próximo token
    get_token();

    // Checa se há um token válido
    if (lexema[aux].token != 0) 
    {
        printf("ANALISADOR LÉXICO: Lexema: %s, Token: %s, Linha: %d\n", 
               lexema[aux].lexemaBuffer, 
               return_Token(lexema[aux].token), 
               lexema[aux].linha);

        // Prepara o valor de retorno para o Bison/Yacc
        int currentToken = lexema[aux].token;
        // Atualiza o último lexema processado
        ultimoLexema = lexema[aux].lexemaBuffer;
        ultimaLinha = lexema[aux].linha;
        
        yylval = &lexema[aux]; // Dependendo da sua implementação

        aux++; // Incrementa o índice do array de lexemas

        return currentToken; // Retorna o token atual para o Bison/Yacc
    }

    // Caso não encontre um token válido, chama yylex novamente
    return yylex();
}


