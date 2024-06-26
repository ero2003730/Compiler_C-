/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./src/bison/bison.y"

    #include <stdio.h>
    #include <stddef.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include "funcs.h" 

    int yylex();
    int yyparse();
    void yyerror(char *s);

#line 83 "./src/c/bison.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_INT = 3,                  /* TOKEN_INT  */
  YYSYMBOL_TOKEN_IF = 4,                   /* TOKEN_IF  */
  YYSYMBOL_TOKEN_RETURN = 5,               /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_ELSE = 6,                 /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_VOID = 7,                 /* TOKEN_VOID  */
  YYSYMBOL_TOKEN_WHILE = 8,                /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_ID = 9,                   /* TOKEN_ID  */
  YYSYMBOL_TOKEN_NUM = 10,                 /* TOKEN_NUM  */
  YYSYMBOL_TOKEN_PLUS = 11,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 12,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULTIPLY = 13,            /* TOKEN_MULTIPLY  */
  YYSYMBOL_TOKEN_DIVIDE = 14,              /* TOKEN_DIVIDE  */
  YYSYMBOL_TOKEN_EQUALS = 15,              /* TOKEN_EQUALS  */
  YYSYMBOL_TOKEN_GT = 16,                  /* TOKEN_GT  */
  YYSYMBOL_TOKEN_RPAREN = 17,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_LPAREN = 18,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_SEMICOLON = 19,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_ASSIGN = 20,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_LT = 21,                  /* TOKEN_LT  */
  YYSYMBOL_TOKEN_LE = 22,                  /* TOKEN_LE  */
  YYSYMBOL_TOKEN_GE = 23,                  /* TOKEN_GE  */
  YYSYMBOL_TOKEN_COMMA = 24,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_OPENBRACKET = 25,         /* TOKEN_OPENBRACKET  */
  YYSYMBOL_TOKEN_CLOSEBRACKET = 26,        /* TOKEN_CLOSEBRACKET  */
  YYSYMBOL_TOKEN_OPENBRACE = 27,           /* TOKEN_OPENBRACE  */
  YYSYMBOL_TOKEN_CLOSEBRACE = 28,          /* TOKEN_CLOSEBRACE  */
  YYSYMBOL_TOKEN_NET = 29,                 /* TOKEN_NET  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_programa = 31,                  /* programa  */
  YYSYMBOL_declaracao_lista = 32,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 33,                /* declaracao  */
  YYSYMBOL_var_declaracao = 34,            /* var_declaracao  */
  YYSYMBOL_tipo_especificador = 35,        /* tipo_especificador  */
  YYSYMBOL_fun_declaracao = 36,            /* fun_declaracao  */
  YYSYMBOL_fun_id = 37,                    /* fun_id  */
  YYSYMBOL_params = 38,                    /* params  */
  YYSYMBOL_param_lista = 39,               /* param_lista  */
  YYSYMBOL_param = 40,                     /* param  */
  YYSYMBOL_composto_decl = 41,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 42,         /* local_declaracoes  */
  YYSYMBOL_statement_lista = 43,           /* statement_lista  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_expressao_decl = 45,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 46,              /* selecao_decl  */
  YYSYMBOL_fat_else = 47,                  /* fat_else  */
  YYSYMBOL_iteracao_decl = 48,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 49,              /* retorno_decl  */
  YYSYMBOL_expressao = 50,                 /* expressao  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_simples_expressao = 52,         /* simples_expressao  */
  YYSYMBOL_relacional = 53,                /* relacional  */
  YYSYMBOL_soma_expressao = 54,            /* soma_expressao  */
  YYSYMBOL_soma = 55,                      /* soma  */
  YYSYMBOL_termo = 56,                     /* termo  */
  YYSYMBOL_mult = 57,                      /* mult  */
  YYSYMBOL_fator = 58,                     /* fator  */
  YYSYMBOL_ativacao = 59,                  /* ativacao  */
  YYSYMBOL_args = 60,                      /* args  */
  YYSYMBOL_arg_lista = 61                  /* arg_lista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   99

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   257


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    90,   100,   102,   103,   105,   124,   149,
     156,   165,   183,   197,   198,   206,   216,   218,   233,   249,
     259,   268,   270,   285,   287,   288,   289,   290,   291,   293,
     294,   297,   312,   320,   322,   334,   339,   348,   358,   360,
     375,   393,   403,   406,   407,   408,   409,   410,   411,   413,
     420,   422,   426,   431,   438,   440,   444,   450,   451,   452,
     462,   465,   472,   473,   475,   484
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_INT",
  "TOKEN_IF", "TOKEN_RETURN", "TOKEN_ELSE", "TOKEN_VOID", "TOKEN_WHILE",
  "TOKEN_ID", "TOKEN_NUM", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MULTIPLY",
  "TOKEN_DIVIDE", "TOKEN_EQUALS", "TOKEN_GT", "TOKEN_RPAREN",
  "TOKEN_LPAREN", "TOKEN_SEMICOLON", "TOKEN_ASSIGN", "TOKEN_LT",
  "TOKEN_LE", "TOKEN_GE", "TOKEN_COMMA", "TOKEN_OPENBRACKET",
  "TOKEN_CLOSEBRACKET", "TOKEN_OPENBRACE", "TOKEN_CLOSEBRACE", "TOKEN_NET",
  "$accept", "programa", "declaracao_lista", "declaracao",
  "var_declaracao", "tipo_especificador", "fun_declaracao", "fun_id",
  "params", "param_lista", "param", "composto_decl", "local_declaracoes",
  "statement_lista", "statement", "expressao_decl", "selecao_decl",
  "fat_else", "iteracao_decl", "retorno_decl", "expressao", "var",
  "simples_expressao", "relacional", "soma_expressao", "soma", "termo",
  "mult", "fator", "ativacao", "args", "arg_lista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      23,   -93,   -93,     5,    23,   -93,   -93,     8,   -93,   -93,
     -93,    25,    17,   -93,    39,    54,    14,    50,    57,    51,
      45,   -93,    52,    47,    43,    23,   -93,    48,   -93,   -93,
     -93,   -93,    23,   -93,    64,     4,    25,    58,    -3,    59,
      18,   -93,    10,   -93,   -93,    60,   -93,   -93,   -93,   -93,
     -93,   -93,    56,    61,   -93,    30,    49,   -93,   -93,    10,
     -93,    63,    10,    10,    62,    10,   -93,    10,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,    10,    10,   -93,   -93,
      10,    66,   -93,    67,    65,   -93,   -93,    68,    69,   -93,
     -93,    53,    49,   -93,    29,    29,   -93,   -93,    10,    74,
     -93,   -93,    29,   -93,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,    12,     0,     7,     0,     0,     0,    10,     0,     0,
      13,    16,     0,    17,     0,     0,     8,     0,    21,    11,
      15,    18,    23,    20,     0,     0,     0,     0,     0,     0,
      39,    59,     0,    30,    19,     0,    25,    22,    24,    26,
      27,    28,     0,    58,    38,    42,    50,    54,    60,     0,
      35,     0,     0,     0,     0,    63,    29,     0,    51,    52,
      47,    45,    44,    43,    46,    48,     0,     0,    55,    56,
       0,     0,    36,     0,     0,    57,    65,     0,    62,    37,
      58,    41,    49,    53,     0,     0,    40,    61,     0,    33,
      34,    64,     0,    31,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,    82,    55,   -14,   -93,    81,   -93,   -93,
      70,    72,   -93,   -93,   -92,   -93,   -93,   -93,   -93,   -93,
     -38,   -22,   -93,   -93,    13,   -93,    15,   -93,    19,   -93,
     -93,   -93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    45,    19,    20,
      21,    46,    32,    35,    47,    48,    49,   103,    50,    51,
      52,    53,    54,    76,    55,    77,    56,    80,    57,    58,
      87,    88
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      61,    18,    99,   100,    64,     9,    40,    41,    37,    38,
     104,    18,    39,    40,    41,    42,    60,    11,    34,    40,
      41,    81,    42,    43,    83,    84,     1,    86,    42,    89,
       2,    28,    44,    37,    38,    15,   -12,    39,    40,    41,
      22,    68,    69,    63,    13,    70,    71,    42,    43,    16,
      14,    72,    73,    74,    90,    90,    28,     1,    90,    75,
     101,    17,    78,    79,    68,    69,    23,   -14,    24,    25,
      28,    26,    27,    36,    31,    66,    59,    62,    65,    85,
     102,    67,    82,    94,    95,    97,    10,    33,    12,    91,
       0,    96,    92,    98,     0,    30,    29,     0,     0,    93
};

static const yytype_int8 yycheck[] =
{
      38,    15,    94,    95,    42,     0,     9,    10,     4,     5,
     102,    25,     8,     9,    10,    18,    19,     9,    32,     9,
      10,    59,    18,    19,    62,    63,     3,    65,    18,    67,
       7,    27,    28,     4,     5,    18,    18,     8,     9,    10,
      26,    11,    12,    25,    19,    15,    16,    18,    19,    10,
      25,    21,    22,    23,    76,    77,    27,     3,    80,    29,
      98,     7,    13,    14,    11,    12,     9,    17,    17,    24,
      27,    19,    25,     9,    26,    19,    18,    18,    18,    17,
       6,    20,    19,    17,    17,    17,     4,    32,     7,    76,
      -1,    26,    77,    24,    -1,    25,    24,    -1,    -1,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     7,    31,    32,    33,    34,    35,    36,     0,
      33,     9,    37,    19,    25,    18,    10,     7,    35,    38,
      39,    40,    26,     9,    17,    24,    19,    25,    27,    41,
      40,    26,    42,    34,    35,    43,     9,     4,     5,     8,
       9,    10,    18,    19,    28,    37,    41,    44,    45,    46,
      48,    49,    50,    51,    52,    54,    56,    58,    59,    18,
      19,    50,    18,    25,    50,    18,    19,    20,    11,    12,
      15,    16,    21,    22,    23,    29,    53,    55,    13,    14,
      57,    50,    19,    50,    50,    17,    50,    60,    61,    50,
      51,    54,    56,    58,    17,    17,    26,    17,    24,    44,
      44,    50,     6,    47,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    34,    34,    35,
      35,    36,    37,    38,    38,    39,    39,    40,    40,    41,
      42,    42,    43,    43,    44,    44,    44,    44,    44,    45,
      45,    46,    47,    47,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      58,    59,    60,    60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     1,     3,     1,     2,     4,     4,
       2,     0,     2,     0,     1,     1,     1,     1,     1,     2,
       1,     6,     2,     0,     5,     2,     3,     3,     1,     1,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     4,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: declaracao_lista  */
#line 86 "./src/bison/bison.y"
            { 
                raizDaArvore = (yyvsp[0].astNode); 
            }
#line 1203 "./src/c/bison.tab.c"
    break;

  case 3: /* declaracao_lista: declaracao_lista declaracao  */
#line 91 "./src/bison/bison.y"
            {
                if ((yyvsp[-1].astNode) != NULL)
                {
                    (yyval.astNode) = (yyvsp[-1].astNode);
                    addSibling((yyval.astNode), (yyvsp[0].astNode));
                    
                }
                else (yyval.astNode) = (yyvsp[0].astNode);
            }
#line 1217 "./src/c/bison.tab.c"
    break;

  case 4: /* declaracao_lista: declaracao  */
#line 100 "./src/bison/bison.y"
                         { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1223 "./src/c/bison.tab.c"
    break;

  case 5: /* declaracao: var_declaracao  */
#line 102 "./src/bison/bison.y"
                                    { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1229 "./src/c/bison.tab.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 103 "./src/bison/bison.y"
                                 { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1235 "./src/c/bison.tab.c"
    break;

  case 7: /* var_declaracao: tipo_especificador TOKEN_ID TOKEN_SEMICOLON  */
#line 106 "./src/bison/bison.y"
            {
                //printf("DECLARACAO RECONHECIDA\n");

                (yyval.astNode) = (yyvsp[-2].astNode); // Reutiliza o nó do tipo especificador
                (yyval.astNode)->type = R_var_declaracao; // Define o tipo do nó
                
                ASTNode *son = createNode(R_default, idLexema); 

                son->lexema = popLexema(listLexema);

                //printf("Lexema son é: %s\n", son->lexema->lexemaBuffer);

                addSon((yyval.astNode), son);

                //printf("Lexema é: %s\n", $$->lexema->lexemaBuffer);

                //printf("DECLARACAO RECONHECIDA ACABOU\n");
            }
#line 1258 "./src/c/bison.tab.c"
    break;

  case 8: /* var_declaracao: tipo_especificador TOKEN_ID TOKEN_OPENBRACKET TOKEN_NUM TOKEN_CLOSEBRACKET TOKEN_SEMICOLON  */
#line 125 "./src/bison/bison.y"
            {
                //printf("DECLARACAO VAR RECONHECIDA\n");
                (yyval.astNode) = (yyvsp[-5].astNode); // Reutiliza o nó do tipo_especificador
                (yyval.astNode)->type = R_var_declaracao_vet; // Define o tipo do nó
                // Supondo que o número da linha já esteja definido em tipo_especificador

                ASTNode *son1 = createNode(R_default, idLexema); // Cria um nó auxiliar para o identificador
                son1->lexema = popLexema(listLexema);
                
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho aux 1 é: %s\n", son1->lexema->lexemaBuffer);

                ASTNode *son2 = createNode(R_default, numLexema); // Cria um nó auxiliar para o número (tamanho do array)
                son2->lexema = popLexema(listLexema);

                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho aux 2 é: %s\n", son2->lexema->lexemaBuffer);

                addSon((yyval.astNode), son2); // Adiciona o segundo nó auxiliar como filho
                addSon((yyval.astNode), son1); // Adiciona o primeir nó auxiliar como filho

                //printf("DECLARACAO VAR RECONHECIDA ACABOU\n");
            }
#line 1286 "./src/c/bison.tab.c"
    break;

  case 9: /* tipo_especificador: TOKEN_INT  */
#line 150 "./src/bison/bison.y"
            {
                //printf("TIPO ESPECIFICADOR RECONHECIDO\n");
                (yyval.astNode) = createNode(R_tipo_especificador, intLexema); // Usando intLexema
                //printf("Int: %s\n", $$->lexema->lexemaBuffer);
                //printf("TIPO ESPECIFICADOR RECONHECIDO ACABOU\n");
            }
#line 1297 "./src/c/bison.tab.c"
    break;

  case 10: /* tipo_especificador: TOKEN_VOID  */
#line 157 "./src/bison/bison.y"
            {
                //printf("TIPO ESPECIFICADOR RECONHECIDO VOID\n");
                (yyval.astNode) = createNode(R_tipo_especificador, voidLexema); // Usando voidLexema
                //printf("Void: %s\n", $$->lexema->lexemaBuffer);
                //printf("TIPO ESPECIFICADOR RECONHECIDO ACABOU\n");
                //strcpy($$->lexema->lexemaBuffer, "VOID");
            }
#line 1309 "./src/c/bison.tab.c"
    break;

  case 11: /* fun_declaracao: tipo_especificador fun_id TOKEN_LPAREN params TOKEN_RPAREN composto_decl  */
#line 166 "./src/bison/bison.y"
            {
                //printf("DECLARACAO FUN RECONHECIDA\n");
                (yyval.astNode) = (yyvsp[-5].astNode);
                (yyval.astNode)->type = R_fun_declaracao;

                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                
                addSon((yyval.astNode), (yyvsp[-2].astNode)); 
                //printf("Filho 1 é: %s\n", $4->lexema->lexemaBuffer);
                addSon((yyval.astNode), (yyvsp[-4].astNode)); 
                //printf("Filho 2 é: %s\n", $2->lexema->lexemaBuffer);
                (yyvsp[-4].astNode) = addSon((yyvsp[-4].astNode), (yyvsp[0].astNode)); 
                //printf("Filho 3 é: %s\n", $6->lexema->lexemaBuffer);

                //printf("DECLARACAO FUN RECONHECIDA ACABOU\n");    
            }
#line 1330 "./src/c/bison.tab.c"
    break;

  case 12: /* fun_id: TOKEN_ID  */
#line 184 "./src/bison/bison.y"
            {
                //printf("ID FUN RECONHECIDO\n");
                (yyval.astNode) = createNode(R_default, idLexema);
                //printf("Pai antes: %s\n", $$->lexema->lexemaBuffer);
                ASTNode *node = createNode(R_default, NULL); // Cria um nó auxiliar para o identificador
                node->lexema = popLexema(listLexema);

                (yyval.astNode)->lexema = node->lexema;

                //printf("Pai depois: %s\n", $$->lexema->lexemaBuffer);
                //printf("ID FUN RECONHECIDO ACABOU\n");
            }
#line 1347 "./src/c/bison.tab.c"
    break;

  case 13: /* params: param_lista  */
#line 197 "./src/bison/bison.y"
                             { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1353 "./src/c/bison.tab.c"
    break;

  case 14: /* params: TOKEN_VOID  */
#line 199 "./src/bison/bison.y"
            {
                //printf("PARAMS RECONHECIDO\n");
                (yyval.astNode) = createNode(R_params, voidLexema); // Usando voidLexema
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("PARAMS RECONHECIDO\n");
            }
#line 1364 "./src/c/bison.tab.c"
    break;

  case 15: /* param_lista: param_lista TOKEN_COMMA param  */
#line 207 "./src/bison/bison.y"
            {
                if ((yyvsp[-2].astNode) != NULL)
                {
                    (yyval.astNode) = (yyvsp[-2].astNode);
                    addSibling((yyval.astNode), (yyvsp[0].astNode)); 
                    
                }
                else (yyval.astNode) = (yyvsp[0].astNode);
                }
#line 1378 "./src/c/bison.tab.c"
    break;

  case 16: /* param_lista: param  */
#line 216 "./src/bison/bison.y"
                     {(yyval.astNode) = (yyvsp[0].astNode);}
#line 1384 "./src/c/bison.tab.c"
    break;

  case 17: /* param: tipo_especificador TOKEN_ID  */
#line 219 "./src/bison/bison.y"
            {
                //printf("PARAM RECONHECIDO\n");
                (yyval.astNode) = (yyvsp[-1].astNode);
                (yyval.astNode)->type = R_param_int;
                ASTNode *son = createNode(R_default, idLexema);

                son->lexema = popLexema(listLexema);
                 
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho son 1 é: %s\n", son->lexema->lexemaBuffer);

                addSon((yyval.astNode), son);
                //printf("PARAM RECONHECIDO ACABOOU\n");
            }
#line 1403 "./src/c/bison.tab.c"
    break;

  case 18: /* param: tipo_especificador TOKEN_ID TOKEN_OPENBRACKET TOKEN_CLOSEBRACKET  */
#line 234 "./src/bison/bison.y"
            {
                //printf("PARAM RECONHECIDO\n");
                (yyval.astNode) = (yyvsp[-3].astNode);
                (yyval.astNode)->type = R_param_vet;
                ASTNode *son = createNode(R_default, idLexema);

                son->lexema = popLexema(listLexema);

                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho son 1 é: %s\n", son->lexema->lexemaBuffer);

                addSon((yyval.astNode), son);
                //printf("PARAM RECONHECIDO ACABOU\n");  
            }
#line 1422 "./src/c/bison.tab.c"
    break;

  case 19: /* composto_decl: TOKEN_OPENBRACE local_declaracoes statement_lista TOKEN_CLOSEBRACE  */
#line 250 "./src/bison/bison.y"
            {
                if ((yyvsp[-2].astNode) != NULL)
                {
                    (yyval.astNode) = (yyvsp[-2].astNode);
                    addSibling((yyval.astNode), (yyvsp[-1].astNode));
                }
                else if ((yyvsp[-2].astNode) == NULL) (yyval.astNode) = (yyvsp[-1].astNode);
            }
#line 1435 "./src/c/bison.tab.c"
    break;

  case 20: /* local_declaracoes: local_declaracoes var_declaracao  */
#line 260 "./src/bison/bison.y"
            {
                if ((yyvsp[-1].astNode) != NULL)
                {
                    (yyval.astNode) = (yyvsp[-1].astNode);
                    addSibling((yyval.astNode), (yyvsp[0].astNode));
                }
                else (yyval.astNode) = (yyvsp[0].astNode);
            }
#line 1448 "./src/c/bison.tab.c"
    break;

  case 21: /* local_declaracoes: %empty  */
#line 268 "./src/bison/bison.y"
                          { (yyval.astNode) = NULL; }
#line 1454 "./src/c/bison.tab.c"
    break;

  case 22: /* statement_lista: statement_lista statement  */
#line 271 "./src/bison/bison.y"
            {
                if ((yyvsp[-1].astNode) != NULL)
                {
                    (yyval.astNode) = (yyvsp[-1].astNode);
                    //printf("Entrei aqui\n");
                    addSibling((yyval.astNode), (yyvsp[0].astNode));
                }
                else 
                {
                    (yyval.astNode) = (yyvsp[0].astNode);
                    //printf("Entrei aqui 2\n");
                }
            }
#line 1472 "./src/c/bison.tab.c"
    break;

  case 23: /* statement_lista: %empty  */
#line 285 "./src/bison/bison.y"
            { (yyval.astNode) = NULL; }
#line 1478 "./src/c/bison.tab.c"
    break;

  case 24: /* statement: expressao_decl  */
#line 287 "./src/bison/bison.y"
                                   { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1484 "./src/c/bison.tab.c"
    break;

  case 25: /* statement: composto_decl  */
#line 288 "./src/bison/bison.y"
                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1490 "./src/c/bison.tab.c"
    break;

  case 26: /* statement: selecao_decl  */
#line 289 "./src/bison/bison.y"
                               { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1496 "./src/c/bison.tab.c"
    break;

  case 27: /* statement: iteracao_decl  */
#line 290 "./src/bison/bison.y"
                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1502 "./src/c/bison.tab.c"
    break;

  case 28: /* statement: retorno_decl  */
#line 291 "./src/bison/bison.y"
                               { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1508 "./src/c/bison.tab.c"
    break;

  case 29: /* expressao_decl: expressao TOKEN_SEMICOLON  */
#line 293 "./src/bison/bison.y"
                                                   { (yyval.astNode) = (yyvsp[-1].astNode); }
#line 1514 "./src/c/bison.tab.c"
    break;

  case 30: /* expressao_decl: TOKEN_SEMICOLON  */
#line 294 "./src/bison/bison.y"
                                  { (yyval.astNode) = NULL; }
#line 1520 "./src/c/bison.tab.c"
    break;

  case 31: /* selecao_decl: TOKEN_IF TOKEN_LPAREN expressao TOKEN_RPAREN statement fat_else  */
#line 298 "./src/bison/bison.y"
        {
            (yyval.astNode) = createNode(R_selecao_decl, ifLexema); // Usando ifLexema
            //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
            addSon((yyval.astNode), (yyvsp[-3].astNode));
            //printf("Filho 1: %s\n", $3->lexema->lexemaBuffer);
            addSon((yyval.astNode), (yyvsp[-1].astNode));
            //printf("Filho 2: %s\n", $5->lexema->lexemaBuffer);
            if ((yyvsp[0].astNode)) 
            {
                addSon((yyval.astNode), (yyvsp[0].astNode));
                //printf("Filho 3: %s\n", $6->lexema->lexemaBuffer);
            }
        }
#line 1538 "./src/c/bison.tab.c"
    break;

  case 32: /* fat_else: TOKEN_ELSE statement  */
#line 313 "./src/bison/bison.y"
        {
            (yyval.astNode) = createNode(R_selecao_decl, elseLexema);  

            //printf("Pai: %s\n", $$->lexema->lexemaBuffer); 
            //printf("Filho: %s\n", $2->lexema->lexemaBuffer);  

            addSon((yyval.astNode),(yyvsp[0].astNode));  
        }
#line 1551 "./src/c/bison.tab.c"
    break;

  case 33: /* fat_else: %empty  */
#line 320 "./src/bison/bison.y"
                        { (yyval.astNode) = NULL; }
#line 1557 "./src/c/bison.tab.c"
    break;

  case 34: /* iteracao_decl: TOKEN_WHILE TOKEN_LPAREN expressao TOKEN_RPAREN statement  */
#line 323 "./src/bison/bison.y"
            {
                (yyval.astNode) = createNode(R_iteracao_decl, whileLexema); // Usando whileLexema
                
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho 1: %s\n", $3->lexema->lexemaBuffer);  
                //printf("Filho 2: %s\n", $5->lexema->lexemaBuffer);  

                addSon((yyval.astNode), (yyvsp[-2].astNode));
                addSon((yyval.astNode), (yyvsp[0].astNode));
            }
#line 1572 "./src/c/bison.tab.c"
    break;

  case 35: /* retorno_decl: TOKEN_RETURN TOKEN_SEMICOLON  */
#line 335 "./src/bison/bison.y"
            {
                (yyval.astNode) = createNode(R_retorno_decl_int, returnLexema); // Usando returnLexema
                //printf("Pai: %s\n", returnLexema->lexemaBuffer);
            }
#line 1581 "./src/c/bison.tab.c"
    break;

  case 36: /* retorno_decl: TOKEN_RETURN expressao TOKEN_SEMICOLON  */
#line 340 "./src/bison/bison.y"
            {
                (yyval.astNode) = createNode(R_retorno_decl_void, returnLexema); // Usando returnLexema
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho: %s\n", $2->lexema->lexemaBuffer);

                addSon((yyval.astNode), (yyvsp[-1].astNode));
            }
#line 1593 "./src/c/bison.tab.c"
    break;

  case 37: /* expressao: var TOKEN_ASSIGN expressao  */
#line 349 "./src/bison/bison.y"
            {
                (yyval.astNode) = createNode(R_expressao, assignLexema); // Usando assignLexema
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho 1: %s\n", $1->lexema->lexemaBuffer);
                //printf("Filho 2: %s\n", $3->lexema->lexemaBuffer);

                addSon((yyval.astNode), (yyvsp[-2].astNode));
                addSon((yyval.astNode), (yyvsp[0].astNode));
            }
#line 1607 "./src/c/bison.tab.c"
    break;

  case 38: /* expressao: simples_expressao  */
#line 358 "./src/bison/bison.y"
                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1613 "./src/c/bison.tab.c"
    break;

  case 39: /* var: TOKEN_ID  */
#line 361 "./src/bison/bison.y"
            {
                
                (yyval.astNode) = createNode(R_var_id, idLexema); // Usando idLexema

                ASTNode *son = createNode(R_default, NULL);

                son->lexema = popLexema(listLexema);

                //printf("$$ antes: %s\n", $$->lexema->lexemaBuffer);

                (yyval.astNode)->lexema = son->lexema;

                //printf("$$ depois: %s\n", $$->lexema->lexemaBuffer); 
            }
#line 1632 "./src/c/bison.tab.c"
    break;

  case 40: /* var: TOKEN_ID TOKEN_OPENBRACKET expressao TOKEN_CLOSEBRACKET  */
#line 376 "./src/bison/bison.y"
            {
                (yyval.astNode) = createNode(R_var_vet, idLexema); // Usando idLexema

                ASTNode *son = createNode(R_default, NULL);

                son->lexema = popLexema(listLexema);

                //printf("$$ antes: %s\n", $$->lexema->lexemaBuffer);

                (yyval.astNode)->lexema = son->lexema;

                //printf("$$ depos: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho: %s\n", $3->lexema->lexemaBuffer);

                addSon((yyval.astNode), (yyvsp[-1].astNode));    
            }
#line 1653 "./src/c/bison.tab.c"
    break;

  case 41: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 394 "./src/bison/bison.y"
            {
                (yyval.astNode) = (yyvsp[-1].astNode); 
                (yyval.astNode)->type = R_simples_expressao;
                //printf("Pai: %s\n", $$->lexema->lexemaBuffer);
                //printf("Filho 1: %s\n", $1->lexema->lexemaBuffer);
                addSon((yyval.astNode), (yyvsp[-2].astNode));
                //printf("Filho 3: %s\n", $3->lexema->lexemaBuffer);
                addSon((yyval.astNode), (yyvsp[0].astNode));
            }
#line 1667 "./src/c/bison.tab.c"
    break;

  case 42: /* simples_expressao: soma_expressao  */
#line 403 "./src/bison/bison.y"
                             { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1673 "./src/c/bison.tab.c"
    break;

  case 43: /* relacional: TOKEN_LE  */
#line 406 "./src/bison/bison.y"
                     { (yyval.astNode) = createNode(R_relacional, leLexema); }
#line 1679 "./src/c/bison.tab.c"
    break;

  case 44: /* relacional: TOKEN_LT  */
#line 407 "./src/bison/bison.y"
                       { (yyval.astNode) = createNode(R_relacional, ltLexema); }
#line 1685 "./src/c/bison.tab.c"
    break;

  case 45: /* relacional: TOKEN_GT  */
#line 408 "./src/bison/bison.y"
                       { (yyval.astNode) = createNode(R_relacional, gtLexema); }
#line 1691 "./src/c/bison.tab.c"
    break;

  case 46: /* relacional: TOKEN_GE  */
#line 409 "./src/bison/bison.y"
                        { (yyval.astNode) = createNode(R_relacional, geLexema); }
#line 1697 "./src/c/bison.tab.c"
    break;

  case 47: /* relacional: TOKEN_EQUALS  */
#line 410 "./src/bison/bison.y"
                           { (yyval.astNode) = createNode(R_relacional, equalsLexema); }
#line 1703 "./src/c/bison.tab.c"
    break;

  case 48: /* relacional: TOKEN_NET  */
#line 411 "./src/bison/bison.y"
                        { (yyval.astNode) = createNode(R_relacional, netLexema); }
#line 1709 "./src/c/bison.tab.c"
    break;

  case 49: /* soma_expressao: soma_expressao soma termo  */
#line 414 "./src/bison/bison.y"
            {
                (yyval.astNode) = (yyvsp[-1].astNode);
                (yyval.astNode)->type = R_soma_expressao;
                addSon((yyval.astNode), (yyvsp[-2].astNode));
                addSon((yyval.astNode), (yyvsp[0].astNode)); 
            }
#line 1720 "./src/c/bison.tab.c"
    break;

  case 50: /* soma_expressao: termo  */
#line 420 "./src/bison/bison.y"
                    { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1726 "./src/c/bison.tab.c"
    break;

  case 51: /* soma: TOKEN_PLUS  */
#line 423 "./src/bison/bison.y"
            { 
                (yyval.astNode) = createNode(R_soma, plusLexema); 
            }
#line 1734 "./src/c/bison.tab.c"
    break;

  case 52: /* soma: TOKEN_MINUS  */
#line 427 "./src/bison/bison.y"
            { 
                (yyval.astNode) = createNode(R_soma, minusLexema); 
            }
#line 1742 "./src/c/bison.tab.c"
    break;

  case 53: /* termo: termo mult fator  */
#line 432 "./src/bison/bison.y"
            {
                (yyval.astNode) = (yyvsp[-1].astNode);
                (yyval.astNode)->type = R_termo;
                addSon((yyval.astNode), (yyvsp[-2].astNode));
                addSon((yyval.astNode), (yyvsp[0].astNode));    
            }
#line 1753 "./src/c/bison.tab.c"
    break;

  case 54: /* termo: fator  */
#line 438 "./src/bison/bison.y"
                    { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1759 "./src/c/bison.tab.c"
    break;

  case 55: /* mult: TOKEN_MULTIPLY  */
#line 441 "./src/bison/bison.y"
            {
                (yyval.astNode) = createNode(R_mult, multiplyLexema);  
            }
#line 1767 "./src/c/bison.tab.c"
    break;

  case 56: /* mult: TOKEN_DIVIDE  */
#line 445 "./src/bison/bison.y"
            {
                (yyval.astNode) = createNode(R_mult, divideLexema); 
                
            }
#line 1776 "./src/c/bison.tab.c"
    break;

  case 57: /* fator: TOKEN_LPAREN expressao TOKEN_RPAREN  */
#line 450 "./src/bison/bison.y"
                                                    { (yyval.astNode) = (yyvsp[-1].astNode); }
#line 1782 "./src/c/bison.tab.c"
    break;

  case 58: /* fator: var  */
#line 451 "./src/bison/bison.y"
                  { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1788 "./src/c/bison.tab.c"
    break;

  case 59: /* fator: TOKEN_NUM  */
#line 453 "./src/bison/bison.y"
            {
                (yyval.astNode) = createNode(R_fator, numLexema);

                ASTNode *son = createNode(R_default, NULL);

                son->lexema = popLexema(listLexema);

                (yyval.astNode)->lexema = son->lexema;
            }
#line 1802 "./src/c/bison.tab.c"
    break;

  case 60: /* fator: ativacao  */
#line 462 "./src/bison/bison.y"
                       { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1808 "./src/c/bison.tab.c"
    break;

  case 61: /* ativacao: fun_id TOKEN_LPAREN args TOKEN_RPAREN  */
#line 466 "./src/bison/bison.y"
            {
                (yyval.astNode) = (yyvsp[-3].astNode);
                (yyval.astNode)->type = R_ativacao;
                addSon((yyval.astNode), (yyvsp[-1].astNode));           
            }
#line 1818 "./src/c/bison.tab.c"
    break;

  case 62: /* args: arg_lista  */
#line 472 "./src/bison/bison.y"
                         { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1824 "./src/c/bison.tab.c"
    break;

  case 63: /* args: %empty  */
#line 473 "./src/bison/bison.y"
                          { (yyval.astNode) = NULL; }
#line 1830 "./src/c/bison.tab.c"
    break;

  case 64: /* arg_lista: arg_lista TOKEN_COMMA expressao  */
#line 476 "./src/bison/bison.y"
            {
                if ((yyvsp[-2].astNode) != NULL)
                {
                    (yyval.astNode) = (yyvsp[-2].astNode);
                    addSibling((yyval.astNode), (yyvsp[0].astNode));
                }
                else (yyval.astNode) = (yyvsp[0].astNode);
            }
#line 1843 "./src/c/bison.tab.c"
    break;

  case 65: /* arg_lista: expressao  */
#line 485 "./src/bison/bison.y"
            {
                (yyval.astNode) = (yyvsp[0].astNode);
            }
#line 1851 "./src/c/bison.tab.c"
    break;


#line 1855 "./src/c/bison.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 490 "./src/bison/bison.y"



void yyerror(char *s) 
{
    fprintf(stderr, "\033[1;31mERRO SINTÁTICO: %s, Lexema: '%s', na linha: %d\033[0m\n", s, ultimoLexema, ultimaLinha);
}

int parse()
{
    yyparse();
}

int yylex()
{

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


