%{
    #include <stdio.h>
    #include <stddef.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include "funcs.h" 

    int yylex();
    int yyparse();
    void yyerror(char *s);
%}

%union {
    struct Lexema *lexema;
    ASTNode *astNode;
}


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


%type <astNode> programa
%type <astNode> declaracao_lista
%type <astNode> declaracao
%type <astNode> var_declaracao
%type <astNode> tipo_especificador
%type <astNode> fun_declaracao
%type <astNode> fun_id
%type <astNode> params
%type <astNode> param_lista
%type <astNode> param
%type <astNode> composto_decl
%type <astNode> local_declaracoes
%type <astNode> statement_lista
%type <astNode> statement
%type <astNode> expressao_decl
%type <astNode> selecao_decl
%type <astNode> fat_else
%type <astNode> iteracao_decl
%type <astNode> retorno_decl
%type <astNode> expressao
%type <astNode> var
%type <astNode> simples_expressao
%type <astNode> relacional
%type <astNode> soma_expressao
%type <astNode> soma
%type <astNode> termo
%type <astNode> mult
%type <astNode> fator
%type <astNode> ativacao
%type <astNode> args
%type <astNode> arg_lista


%%

        programa
            : declaracao_lista 
            { 
                raizDaArvore = $1; 
            } 

        declaracao_lista : declaracao_lista declaracao
            {
                if ($1 != NULL)
                {
                    $$ = $1;
                    addSibling($$, $2);
                    
                }
                else $$ = $2;
            }
            | declaracao { $$ = $1; } ;

        declaracao : var_declaracao { $$ = $1; }
                | fun_declaracao { $$ = $1; } ;

        var_declaracao : tipo_especificador TOKEN_ID TOKEN_SEMICOLON
            {
                //printf("DECLARACAO RECONHECIDA\n");

                $$ = $1; // Reutiliza o nó do tipo especificador
                $$->type = R_var_declaracao; // Define o tipo do nó
                
                ASTNode *son = createNode(R_default, idLexema); 

                son->lexema = popLexema(listLexema);

                //printf("Lexema son é: %s\n", son->lexema->lexemaBuffer);

                addSon($$, son);

                //printf("Lexema é: %s\n", $$->lexema->lexemaBuffer);

                //printf("DECLARACAO RECONHECIDA ACABOU\n");
            }
            | tipo_especificador TOKEN_ID TOKEN_OPENBRACKET TOKEN_NUM TOKEN_CLOSEBRACKET TOKEN_SEMICOLON 
            {
                //printf("DECLARACAO VAR RECONHECIDA\n");
                $$ = $1; // Reutiliza o nó do tipo_especificador
                $$->type = R_var_declaracao_vet; // Define o tipo do nó
                // Supondo que o número da linha já esteja definido em tipo_especificador

                ASTNode *son1 = createNode(R_default, idLexema); // Cria um nó auxiliar para o identificador
                son1->lexema = popLexema(listLexema);
                
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho aux 1 é: %s\n", son1->lexema->lexemaBuffer);

                ASTNode *son2 = createNode(R_default, numLexema); // Cria um nó auxiliar para o número (tamanho do array)
                son2->lexema = popLexema(listLexema);

                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho aux 2 é: %s\n", son2->lexema->lexemaBuffer);

                addSon($$, son2); // Adiciona o segundo nó auxiliar como filho
                addSon($$, son1); // Adiciona o primeir nó auxiliar como filho

                //printf("DECLARACAO VAR RECONHECIDA ACABOU\n");
            };

        tipo_especificador : TOKEN_INT
            {
                //printf("TIPO ESPECIFICADOR RECONHECIDO\n");
                $$ = createNode(R_tipo_especificador, intLexema); // Usando intLexema
                //printf("Int: %s\n", $$->lexema->lexemaBuffer);
                //printf("TIPO ESPECIFICADOR RECONHECIDO ACABOU\n");
            }
            | TOKEN_VOID 
            {
                //printf("TIPO ESPECIFICADOR RECONHECIDO VOID\n");
                $$ = createNode(R_tipo_especificador, voidLexema); // Usando voidLexema
                //printf("Void: %s\n", $$->lexema->lexemaBuffer);
                //printf("TIPO ESPECIFICADOR RECONHECIDO ACABOU\n");
                //strcpy($$->lexema->lexemaBuffer, "VOID");
            };

        fun_declaracao : tipo_especificador fun_id TOKEN_LPAREN params TOKEN_RPAREN composto_decl 
            {
                //printf("DECLARACAO FUN RECONHECIDA\n");
                $$ = $1;
                $$->type = R_fun_declaracao;

                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                
                addSon($$, $4); 
                //printf("Filho 1 é: %s\n", $4->lexema->lexemaBuffer);
                addSon($$, $2); 
                //printf("Filho 2 é: %s\n", $2->lexema->lexemaBuffer);
                $2 = addSon($2, $6); 
                //printf("Filho 3 é: %s\n", $6->lexema->lexemaBuffer);

                //printf("DECLARACAO FUN RECONHECIDA ACABOU\n");    
            };
        
        fun_id : TOKEN_ID
            {
                //printf("ID FUN RECONHECIDO\n");
                $$ = createNode(R_default, idLexema);
                //printf("Pai antes: %s\n", $$->lexema->lexemaBuffer);
                ASTNode *node = createNode(R_default, NULL); // Cria um nó auxiliar para o identificador
                node->lexema = popLexema(listLexema);

                $$->lexema = node->lexema;

                //printf("Pai depois: %s\n", $$->lexema->lexemaBuffer);
                //printf("ID FUN RECONHECIDO ACABOU\n");
            }

        params : param_lista { $$ = $1; }
            | TOKEN_VOID 
            {
                //printf("PARAMS RECONHECIDO\n");
                $$ = createNode(R_params, voidLexema); // Usando voidLexema
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("PARAMS RECONHECIDO\n");
            };

        param_lista : param_lista TOKEN_COMMA param
            {
                if ($1 != NULL)
                {
                    $$ = $1;
                    addSibling($$, $3); 
                    
                }
                else $$ = $3;
                }
            | param  {$$ = $1;} ;

        param : tipo_especificador TOKEN_ID
            {
                //printf("PARAM RECONHECIDO\n");
                $$ = $1;
                $$->type = R_param_int;
                ASTNode *son = createNode(R_default, idLexema);

                son->lexema = popLexema(listLexema);
                 
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho son 1 é: %s\n", son->lexema->lexemaBuffer);

                addSon($$, son);
                //printf("PARAM RECONHECIDO ACABOOU\n");
            }
            | tipo_especificador TOKEN_ID TOKEN_OPENBRACKET TOKEN_CLOSEBRACKET 
            {
                //printf("PARAM RECONHECIDO\n");
                $$ = $1;
                $$->type = R_param_vet;
                ASTNode *son = createNode(R_default, idLexema);

                son->lexema = popLexema(listLexema);

                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho son 1 é: %s\n", son->lexema->lexemaBuffer);

                addSon($$, son);
                //printf("PARAM RECONHECIDO ACABOU\n");  
            };

        composto_decl : TOKEN_OPENBRACE local_declaracoes statement_lista TOKEN_CLOSEBRACE 
            {
                if ($2 != NULL)
                {
                    $$ = $2;
                    addSibling($$, $3);
                }
                else if ($2 == NULL) $$ = $3;
            };

        local_declaracoes : local_declaracoes var_declaracao
            {
                if ($1 != NULL)
                {
                    $$ = $1;
                    addSibling($$, $2);
                }
                else $$ = $2;
            }
            | /* vazio */ { $$ = NULL; };

        statement_lista : statement_lista statement
            {
                if ($1 != NULL)
                {
                    $$ = $1;
                    //printf("Entrei aqui\n");
                    addSibling($$, $2);
                }
                else 
                {
                    $$ = $2;
                    //printf("Entrei aqui 2\n");
                }
            }
            | /* vazio */ 
            { $$ = NULL; };

        statement : expressao_decl { $$ = $1; }
                | composto_decl { $$ = $1; }
                | selecao_decl { $$ = $1; }
                | iteracao_decl { $$ = $1; }
                | retorno_decl { $$ = $1; };

        expressao_decl : expressao TOKEN_SEMICOLON { $$ = $1; }
                | TOKEN_SEMICOLON { $$ = NULL; };


        selecao_decl : TOKEN_IF TOKEN_LPAREN expressao TOKEN_RPAREN statement fat_else
        {
            $$ = createNode(R_selecao_decl, ifLexema); // Usando ifLexema
            //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
            addSon($$, $3);
            //printf("Filho 1: %s\n", $3->lexema->lexemaBuffer);
            addSon($$, $5);
            //printf("Filho 2: %s\n", $5->lexema->lexemaBuffer);
            if ($6) 
            {
                addSon($$, $6);
                //printf("Filho 3: %s\n", $6->lexema->lexemaBuffer);
            }
        } ;
    
        fat_else : TOKEN_ELSE statement
        {
            $$ = createNode(R_selecao_decl, elseLexema);  

            //printf("Pai: %s\n", $$->lexema->lexemaBuffer); 
            //printf("Filho: %s\n", $2->lexema->lexemaBuffer);  

            addSon($$,$2);  
        } | /* vazio */ { $$ = NULL; } ;

        iteracao_decl : TOKEN_WHILE TOKEN_LPAREN expressao TOKEN_RPAREN statement 
            {
                $$ = createNode(R_iteracao_decl, whileLexema); // Usando whileLexema
                
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho 1: %s\n", $3->lexema->lexemaBuffer);  
                //printf("Filho 2: %s\n", $5->lexema->lexemaBuffer);  

                addSon($$, $3);
                addSon($$, $5);
            };

        retorno_decl : TOKEN_RETURN TOKEN_SEMICOLON
            {
                $$ = createNode(R_retorno_decl_int, returnLexema); // Usando returnLexema
                //printf("Pai: %s\n", returnLexema->lexemaBuffer);
            }
            | TOKEN_RETURN expressao TOKEN_SEMICOLON 
            {
                $$ = createNode(R_retorno_decl_void, returnLexema); // Usando returnLexema
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho: %s\n", $2->lexema->lexemaBuffer);

                addSon($$, $2);
            };

        expressao : var TOKEN_ASSIGN expressao
            {
                $$ = createNode(R_expressao, assignLexema); // Usando assignLexema
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho 1: %s\n", $1->lexema->lexemaBuffer);
                //printf("Filho 2: %s\n", $3->lexema->lexemaBuffer);

                addSon($$, $1);
                addSon($$, $3);
            }
            | simples_expressao { $$ = $1; };

        var : TOKEN_ID
            {
                
                $$ = createNode(R_var_id, idLexema); // Usando idLexema

                ASTNode *son = createNode(R_default, NULL);

                son->lexema = popLexema(listLexema);

                //printf("$$ antes: %s\n", $$->lexema->lexemaBuffer);

                $$->lexema = son->lexema;

                //printf("$$ depois: %s\n", $$->lexema->lexemaBuffer); 
            }
            | TOKEN_ID TOKEN_OPENBRACKET expressao TOKEN_CLOSEBRACKET 
            {
                $$ = createNode(R_var_vet, idLexema); // Usando idLexema

                ASTNode *son = createNode(R_default, NULL);

                son->lexema = popLexema(listLexema);

                //printf("$$ antes: %s\n", $$->lexema->lexemaBuffer);

                $$->lexema = son->lexema;

                //printf("$$ depos: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho: %s\n", $3->lexema->lexemaBuffer);

                addSon($$, $3);    
            };

        simples_expressao : soma_expressao relacional soma_expressao
            {
                $$ = $2; 
                $$->type = R_simples_expressao;
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho 1: %s\n", $1->lexema->lexemaBuffer);
                addSon($$, $1);
                //printf("Filho 3: %s\n", $3->lexema->lexemaBuffer);
                addSon($$, $3);
            }
            | soma_expressao { $$ = $1; };

        relacional : 
            TOKEN_LE { $$ = createNode(R_relacional, leLexema); }
            | TOKEN_LT { $$ = createNode(R_relacional, ltLexema); }
            | TOKEN_GT { $$ = createNode(R_relacional, gtLexema); }
            | TOKEN_GE  { $$ = createNode(R_relacional, geLexema); }
            | TOKEN_EQUALS { $$ = createNode(R_relacional, equalsLexema); }
            | TOKEN_NET { $$ = createNode(R_relacional, netLexema); };

        soma_expressao : soma_expressao soma termo
            {
                $$ = $2;
                $$->type = R_soma_expressao;
                addSon($$, $1);
                addSon($$, $3); 
            }
            | termo { $$ = $1; } ;

        soma : TOKEN_PLUS 
            { 
                $$ = createNode(R_soma, plusLexema); 
            }
            | TOKEN_MINUS 
            { 
                $$ = createNode(R_soma, minusLexema); 
            } ;

        termo : termo mult fator
            {
                $$ = $2;
                $$->type = R_termo;
                addSon($$, $1);
                addSon($$, $3);    
            }
            | fator { $$ = $1; } ;

        mult : TOKEN_MULTIPLY 
            {
                $$ = createNode(R_mult, multiplyLexema);  
            }
            | TOKEN_DIVIDE 
            {
                $$ = createNode(R_mult, divideLexema); 
                
            };

        fator : TOKEN_LPAREN expressao TOKEN_RPAREN { $$ = $2; }
            | var { $$ = $1; }
            | TOKEN_NUM 
            {
                $$ = createNode(R_fator, numLexema);

                ASTNode *son = createNode(R_default, NULL);

                son->lexema = popLexema(listLexema);

                $$->lexema = son->lexema;
            } 
            | ativacao { $$ = $1; }
            ;
            
        ativacao : fun_id TOKEN_LPAREN args TOKEN_RPAREN 
            {
                $$ = $1;
                $$->type = R_ativacao;
                addSon($$, $3);           
            };

        args : arg_lista { $$ = $1; }
            | /* vazio */ { $$ = NULL; } ;

        arg_lista : arg_lista TOKEN_COMMA expressao
            {
                if ($1 != NULL)
                {
                    $$ = $1;
                    addSibling($$, $3);
                }
                else $$ = $3;
            }
            | expressao 
            {
                $$ = $1;
            };


%%


void yyerror(char *s) 
{
    fprintf(stderr, "ERRO SINTÁTICO: %s, Lexema: '%s', na linha: %d\n", s, ultimoLexema, ultimaLinha);
}

int parse()
{
    yyparse();
}

int yylex()
{
    static int count = 0; // Contador para chamadas de yylex

    // Checa se o final do arquivo foi atingido
    if (final == 1 || final == -1) 
    {
        

        return 0; // Retorna 0 para indicar o final do arquivo
    }

    // Obtém o próximo token
    get_token();

    // Checa se há um token válido
    if (lexema[aux].token != 0) 
    {
        
        printf("Lexema: %s, Token: %s, Token num: %d, Linha: %d\n", 
               lexema[aux].lexemaBuffer, 
               return_Token(lexema[aux].token),
               lexema[aux].token, 
               lexema[aux].linha);
        

        if (lexema[aux].token == 7) 
        {
            idLexema = &lexema[aux];
            pushLexema(listLexema, idLexema);
        }
        else if (lexema[aux].token == 8) 
        {
            numLexema = &lexema[aux];
            pushLexema(listLexema, numLexema);
        }
        else if (lexema[aux].token == 1) intLexema = &lexema[aux];
        else if (lexema[aux].token == 2) ifLexema = &lexema[aux];
        else if (lexema[aux].token == 3) returnLexema = &lexema[aux];
        else if (lexema[aux].token == 4) elseLexema = &lexema[aux];
        else if (lexema[aux].token == 5) voidLexema = &lexema[aux];
        else if (lexema[aux].token == 6) whileLexema = &lexema[aux];
        else if (lexema[aux].token == 9) plusLexema = &lexema[aux];
        else if (lexema[aux].token == 10) minusLexema = &lexema[aux];
        else if (lexema[aux].token == 11) multiplyLexema = &lexema[aux];
        else if (lexema[aux].token == 12) divideLexema = &lexema[aux];
        else if (lexema[aux].token == 13) equalsLexema = &lexema[aux];
        else if (lexema[aux].token == 14) gtLexema = &lexema[aux];
        else if (lexema[aux].token == 18) assignLexema = &lexema[aux];
        else if (lexema[aux].token == 19) ltLexema = &lexema[aux];
        else if (lexema[aux].token == 20) leLexema = &lexema[aux];
        else if (lexema[aux].token == 21) geLexema = &lexema[aux];
        else if (lexema[aux].token == 27) netLexema = &lexema[aux];
   
        // Prepara o valor de retorno para o Bison/Yacc
        int currentToken = lexema[aux].token;
        // Atualiza o último lexema processado
        ultimoLexema = strdup(lexema[aux].lexemaBuffer);
        ultimaLinha = lexema[aux].linha;
        
        //yylval.lexema = &lexema[aux];

        //pushLexema(listLexema, &lexema[aux]);

        aux++; // Incrementa o índice do array de lexemas

        return currentToken; // Retorna o token atual para o Bison/Yacc
    }

    

    // Caso não encontre um token válido, chama yylex novamente
    return yylex();
}


