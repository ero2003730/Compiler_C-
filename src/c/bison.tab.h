/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_C_BISON_TAB_H_INCLUDED
# define YY_YY_SRC_C_BISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_INT = 1,                 /* TOKEN_INT  */
    TOKEN_IF = 2,                  /* TOKEN_IF  */
    TOKEN_RETURN = 3,              /* TOKEN_RETURN  */
    TOKEN_ELSE = 4,                /* TOKEN_ELSE  */
    TOKEN_VOID = 5,                /* TOKEN_VOID  */
    TOKEN_WHILE = 6,               /* TOKEN_WHILE  */
    TOKEN_ID = 7,                  /* TOKEN_ID  */
    TOKEN_NUM = 8,                 /* TOKEN_NUM  */
    TOKEN_PLUS = 9,                /* TOKEN_PLUS  */
    TOKEN_MINUS = 10,              /* TOKEN_MINUS  */
    TOKEN_MULTIPLY = 11,           /* TOKEN_MULTIPLY  */
    TOKEN_DIVIDE = 12,             /* TOKEN_DIVIDE  */
    TOKEN_EQUALS = 13,             /* TOKEN_EQUALS  */
    TOKEN_GT = 14,                 /* TOKEN_GT  */
    TOKEN_RPAREN = 15,             /* TOKEN_RPAREN  */
    TOKEN_LPAREN = 16,             /* TOKEN_LPAREN  */
    TOKEN_SEMICOLON = 17,          /* TOKEN_SEMICOLON  */
    TOKEN_ASSIGN = 18,             /* TOKEN_ASSIGN  */
    TOKEN_LT = 19,                 /* TOKEN_LT  */
    TOKEN_LE = 20,                 /* TOKEN_LE  */
    TOKEN_GE = 21,                 /* TOKEN_GE  */
    TOKEN_COMMA = 22,              /* TOKEN_COMMA  */
    TOKEN_OPENBRACKET = 23,        /* TOKEN_OPENBRACKET  */
    TOKEN_CLOSEBRACKET = 24,       /* TOKEN_CLOSEBRACKET  */
    TOKEN_OPENBRACE = 25,          /* TOKEN_OPENBRACE  */
    TOKEN_CLOSEBRACE = 26,         /* TOKEN_CLOSEBRACE  */
    TOKEN_NET = 27                 /* TOKEN_NET  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "./src/bison/bison.y"

    struct Lexema *lexema;
    ASTNode *astNode;

#line 98 "./src/c/bison.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_C_BISON_TAB_H_INCLUDED  */
