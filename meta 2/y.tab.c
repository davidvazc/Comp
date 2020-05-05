/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOLLIT = 258,
     AND = 259,
     ASSIGN = 260,
     STAR = 261,
     COMMA = 262,
     DIV = 263,
     EQ = 264,
     GE = 265,
     GT = 266,
     LBRACE = 267,
     LE = 268,
     LPAR = 269,
     LSQ = 270,
     LT = 271,
     MINUS = 272,
     MOD = 273,
     NE = 274,
     NOT = 275,
     OR = 276,
     PLUS = 277,
     RBRACE = 278,
     RPAR = 279,
     RSQ = 280,
     SEMICOLON = 281,
     ARROW = 282,
     LSHIFT = 283,
     RSHIFT = 284,
     XOR = 285,
     BOOL = 286,
     CLASS = 287,
     DOTLENGTH = 288,
     DOUBLE = 289,
     ELSE = 290,
     IF = 291,
     INT = 292,
     PRINT = 293,
     PARSEINT = 294,
     PUBLIC = 295,
     RETURN = 296,
     STATIC = 297,
     STRING = 298,
     VOID = 299,
     WHILE = 300,
     RESERVED = 301,
     ID = 302,
     EXP = 303,
     REALLIT = 304,
     INTLIT = 305,
     STRLIT = 306,
     preced = 307,
     NO_ELSE = 308
   };
#endif
/* Tokens.  */
#define BOOLLIT 258
#define AND 259
#define ASSIGN 260
#define STAR 261
#define COMMA 262
#define DIV 263
#define EQ 264
#define GE 265
#define GT 266
#define LBRACE 267
#define LE 268
#define LPAR 269
#define LSQ 270
#define LT 271
#define MINUS 272
#define MOD 273
#define NE 274
#define NOT 275
#define OR 276
#define PLUS 277
#define RBRACE 278
#define RPAR 279
#define RSQ 280
#define SEMICOLON 281
#define ARROW 282
#define LSHIFT 283
#define RSHIFT 284
#define XOR 285
#define BOOL 286
#define CLASS 287
#define DOTLENGTH 288
#define DOUBLE 289
#define ELSE 290
#define IF 291
#define INT 292
#define PRINT 293
#define PARSEINT 294
#define PUBLIC 295
#define RETURN 296
#define STATIC 297
#define STRING 298
#define VOID 299
#define WHILE 300
#define RESERVED 301
#define ID 302
#define EXP 303
#define REALLIT 304
#define INTLIT 305
#define STRLIT 306
#define preced 307
#define NO_ELSE 308




/* Copy the first part of user declarations.  */
#line 1 "jucompiler.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int yylex(void);
void yyerror(char* s);

extern int line_y, col_y;
extern int arg;
extern char* yytext;
int erros_sintaxe = 0;
char ID_type[10];
ASTtree* root = NULL, *tmp = NULL, *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL, *tmp4 = NULL;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "jucompiler.y"
{
    char* token;
    struct ast_node *ast;
}
/* Line 193 of yacc.c.  */
#line 225 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 238 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   411

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    14,    17,    20,    23,    25,    27,
      29,    34,    41,    44,    48,    49,    51,    53,    55,    61,
      66,    72,    77,    81,    86,    89,    93,    98,   102,   105,
     108,   109,   114,   118,   119,   123,   126,   132,   140,   146,
     150,   153,   155,   158,   161,   164,   170,   176,   179,   182,
     184,   190,   194,   199,   200,   204,   208,   216,   221,   223,
     225,   229,   233,   237,   241,   245,   249,   253,   257,   261,
     265,   269,   273,   277,   281,   285,   289,   292,   295,   298,
     302,   304,   306,   308,   311,   313,   315,   317
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    32,    47,    12,    56,    23,    -1,    32,
      47,    12,    23,    -1,    56,    57,    -1,    56,    58,    -1,
      56,    26,    -1,    58,    -1,    57,    -1,    26,    -1,    40,
      42,    61,    64,    -1,    40,    42,    60,    47,    59,    26,
      -1,     1,    26,    -1,    59,     7,    47,    -1,    -1,    31,
      -1,    37,    -1,    34,    -1,    60,    47,    14,    62,    24,
      -1,    60,    47,    14,    24,    -1,    44,    47,    14,    62,
      24,    -1,    44,    47,    14,    24,    -1,    60,    47,    63,
      -1,    43,    15,    25,    47,    -1,    60,    47,    -1,     7,
      60,    47,    -1,     7,    60,    47,    63,    -1,    12,    65,
      23,    -1,    65,    68,    -1,    65,    66,    -1,    -1,    60,
      47,    67,    26,    -1,    67,     7,    47,    -1,    -1,    12,
      69,    23,    -1,    12,    23,    -1,    36,    14,    74,    24,
      68,    -1,    36,    14,    74,    24,    68,    35,    68,    -1,
      45,    14,    74,    24,    68,    -1,    41,    74,    26,    -1,
      41,    26,    -1,    26,    -1,    70,    26,    -1,    72,    26,
      -1,    73,    26,    -1,    38,    14,    74,    24,    26,    -1,
      38,    14,    51,    24,    26,    -1,     1,    26,    -1,    69,
      68,    -1,    68,    -1,    47,    14,    74,    71,    24,    -1,
      47,    14,    24,    -1,    47,    14,     1,    24,    -1,    -1,
      71,     7,    74,    -1,    47,     5,    74,    -1,    39,    14,
      47,    15,    74,    25,    24,    -1,    39,    14,     1,    24,
      -1,    72,    -1,    75,    -1,    75,    22,    75,    -1,    75,
      17,    75,    -1,    75,     6,    75,    -1,    75,     8,    75,
      -1,    75,    18,    75,    -1,    75,     4,    75,    -1,    75,
      21,    75,    -1,    75,    30,    75,    -1,    75,    28,    75,
      -1,    75,    29,    75,    -1,    75,     9,    75,    -1,    75,
      10,    75,    -1,    75,    11,    75,    -1,    75,    13,    75,
      -1,    75,    16,    75,    -1,    75,    19,    75,    -1,    17,
      75,    -1,    20,    75,    -1,    22,    75,    -1,    14,    74,
      24,    -1,    70,    -1,    73,    -1,    47,    -1,    47,    33,
      -1,    50,    -1,    49,    -1,     3,    -1,    14,     1,    24,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   132,   141,   142,   143,   144,   145,   146,
     151,   163,   171,   176,   182,   188,   189,   190,   196,   205,
     212,   221,   234,   241,   247,   257,   263,   275,   283,   284,
     285,   291,   303,   309,   323,   336,   337,   360,   390,   407,
     408,   409,   410,   411,   412,   413,   418,   423,   427,   435,
     442,   449,   454,   459,   460,   466,   478,   484,   489,   490,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLLIT", "AND", "ASSIGN", "STAR",
  "COMMA", "DIV", "EQ", "GE", "GT", "LBRACE", "LE", "LPAR", "LSQ", "LT",
  "MINUS", "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE", "RPAR", "RSQ",
  "SEMICOLON", "ARROW", "LSHIFT", "RSHIFT", "XOR", "BOOL", "CLASS",
  "DOTLENGTH", "DOUBLE", "ELSE", "IF", "INT", "PRINT", "PARSEINT",
  "PUBLIC", "RETURN", "STATIC", "STRING", "VOID", "WHILE", "RESERVED",
  "ID", "EXP", "REALLIT", "INTLIT", "STRLIT", "preced", "NO_ELSE",
  "$accept", "Program", "Program_Aux", "MethodDecl", "FieldDecl",
  "FieldDecl_aux", "Type", "MethodHeader", "FormalParams",
  "FormalParams_Aux", "MethodBody", "MethodBody_Aux", "VarDecl",
  "VarDecl_Aux", "Statement", "Statement_Aux", "MethodInvocation",
  "MethodInvocation_Aux", "Assignment", "ParseArgs", "Expr", "Expr_Aux", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    59,    59,    60,    60,    60,    61,    61,
      61,    61,    62,    62,    62,    63,    63,    64,    65,    65,
      65,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    70,    70,    71,    71,    72,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     2,     2,     2,     1,     1,     1,
       4,     6,     2,     3,     0,     1,     1,     1,     5,     4,
       5,     4,     3,     4,     2,     3,     4,     3,     2,     2,
       0,     4,     3,     0,     3,     2,     5,     7,     5,     3,
       2,     1,     2,     2,     2,     5,     5,     2,     2,     1,
       5,     3,     4,     0,     3,     3,     7,     4,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     3,
       1,     1,     1,     2,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     3,     9,     0,
       0,     8,     7,    12,     0,     2,     6,     4,     5,    15,
      17,    16,     0,     0,     0,     0,    14,    30,    10,     0,
       0,     0,     0,    21,     0,     0,     0,    19,     0,     0,
      11,     0,     0,    27,    41,     0,     0,     0,     0,     0,
       0,     0,    29,    28,     0,     0,     0,     0,    24,    20,
      18,    13,    47,    35,    49,     0,     0,     0,     0,    86,
       0,     0,     0,     0,    40,    82,    85,    84,    80,    58,
      81,     0,    59,     0,     0,     0,    33,    42,    43,    44,
       0,     0,    22,    34,    48,     0,     0,     0,     0,     0,
       0,     0,    82,    76,    77,    78,    83,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    51,    53,     0,
      23,     0,     0,     0,     0,    57,     0,    87,    79,    65,
      62,    63,    70,    71,    72,    73,    74,    61,    64,    75,
      66,    60,    68,    69,    67,     0,    52,     0,     0,    31,
      25,    36,    46,    45,     0,    38,     0,    50,    32,    26,
       0,     0,    54,    37,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    11,    12,    31,    35,    24,    36,    92,
      28,    32,    52,   129,    53,    65,    78,   157,    79,    80,
      81,    82
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int16 yypact[] =
{
     -16,   -20,    31,    28,   -63,     6,    15,   -63,   -63,     0,
      47,   -63,   -63,   -63,   121,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,    -4,     2,    35,    54,    58,   -63,   -63,   168,
     220,    10,   183,   -63,    61,    33,    51,   -63,    72,    48,
     -63,    73,   200,   -63,   -63,    84,    91,    92,   147,    94,
      25,    62,   -63,   -63,    93,   101,   103,    95,   128,   -63,
     -63,   -63,   -63,   -63,   -63,   217,    64,   131,    19,   -63,
     127,   140,   140,   140,   -63,     4,   -63,   -63,   -63,   -63,
     -63,   110,   274,    64,    64,    68,   -63,   -63,   -63,   -63,
      90,    60,   -63,   -63,   -63,   118,   122,   132,   135,   148,
     144,   151,     5,   -63,   -63,   -63,   -63,   -63,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   159,   -63,   161,   -63,   -63,    18,
     -63,   124,   234,   146,   162,   -63,    64,   -63,   -63,   352,
     -63,   -63,   376,   104,   104,   104,   104,    71,   -63,   376,
     301,    71,   389,   389,   328,   234,   -63,    21,   153,   -63,
     128,   156,   -63,   -63,   173,   -63,    64,   -63,   -63,   -63,
     234,   169,   -63,   -63,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   -63,   193,   194,   -63,    -8,   -63,   177,    50,
     -63,   -63,   -63,   -63,   -39,   -63,   -32,   -63,   -31,   -30,
     -62,   -58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      54,    55,    56,    64,    95,    97,    23,     6,   101,    84,
      54,    55,    56,   103,   104,   105,     1,    39,    85,    85,
      98,   124,   125,   128,    51,   158,    94,     3,   166,     7,
      84,     4,     8,    54,    55,    56,    40,   106,   106,    85,
       5,    13,    14,    25,   159,   167,     9,    27,     6,    26,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    99,    69,    29,   126,
      15,    69,    30,    16,   164,    59,    57,   109,    70,   110,
      58,    71,    70,   131,    72,    71,    73,     9,    72,   117,
      73,    19,   127,   161,    20,    61,    60,    21,    66,    62,
      54,    55,    56,    47,   172,    67,    68,    47,    83,    86,
     109,    75,   110,    76,    77,    75,   165,    76,    77,    87,
      90,   116,   117,    54,    55,    56,   120,    88,   100,    89,
      69,   173,   121,   122,    69,    91,   107,   130,    54,    55,
      56,    70,   132,    69,    71,    70,   133,    72,    71,    73,
      69,    72,    19,    73,    70,    20,   134,    71,    21,   135,
      72,    70,    73,   136,    71,    22,    47,    72,   137,    73,
      47,   160,   162,    74,    75,   138,    76,    77,    75,    47,
      76,    77,    96,   155,    41,   156,    47,   102,   163,    76,
      77,   170,    33,   174,    75,    42,    76,    77,   171,    19,
     168,    41,    20,    17,    18,    21,    43,    38,     0,    44,
     169,    34,    42,     0,    19,     0,     0,    20,    41,    45,
      21,    46,    47,    63,    48,     0,    44,     0,    49,    42,
      50,     0,     0,     0,     0,    41,    45,     0,    46,    47,
      93,    48,     0,    44,    37,    49,    42,    50,     0,     0,
       0,    19,     0,    45,    20,    46,    47,    21,    48,     0,
      44,     0,    49,    34,    50,     0,     0,     0,     0,     0,
      45,     0,    46,    47,     0,    48,     0,     0,   108,    49,
     109,    50,   110,   111,   112,   113,     0,   114,     0,     0,
     115,   116,   117,   118,     0,   119,   120,     0,     0,     0,
       0,     0,   121,   122,   123,   108,     0,   109,     0,   110,
     111,   112,   113,     0,   114,     0,     0,   115,   116,   117,
     118,     0,     0,   120,     0,     0,     0,     0,     0,   121,
     122,   123,   108,     0,   109,     0,   110,   111,   112,   113,
       0,   114,     0,     0,   115,   116,   117,   118,     0,     0,
     120,     0,     0,     0,     0,     0,   121,   122,   109,     0,
     110,   111,   112,   113,     0,   114,     0,     0,   115,   116,
     117,   118,     0,     0,   120,     0,     0,     0,     0,     0,
     121,   122,   109,     0,   110,     0,   112,   113,     0,   114,
       0,     0,   115,   116,   117,   109,     0,   110,   120,     0,
       0,     0,     0,     0,   121,   122,   116,   117,     0,     0,
       0,   120
};

static const yytype_int16 yycheck[] =
{
      32,    32,    32,    42,    66,    67,    14,     1,    70,     5,
      42,    42,    42,    71,    72,    73,    32,     7,    14,    14,
       1,    83,    84,    85,    32,     7,    65,    47,     7,    23,
       5,     0,    26,    65,    65,    65,    26,    33,    33,    14,
      12,    26,    42,    47,    26,    24,    40,    12,     1,    47,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    47,     3,    14,     1,
      23,     3,    14,    26,   136,    24,    15,     6,    14,     8,
      47,    17,    14,    91,    20,    17,    22,    40,    20,    18,
      22,    31,    24,   132,    34,    47,    24,    37,    14,    26,
     132,   132,   132,    39,   166,    14,    14,    39,    14,    47,
       6,    47,     8,    49,    50,    47,   155,    49,    50,    26,
      25,    17,    18,   155,   155,   155,    22,    26,     1,    26,
       3,   170,    28,    29,     3,     7,    26,    47,   170,   170,
     170,    14,    24,     3,    17,    14,    24,    20,    17,    22,
       3,    20,    31,    22,    14,    34,    24,    17,    37,    24,
      20,    14,    22,    15,    17,    44,    39,    20,    24,    22,
      39,    47,    26,    26,    47,    24,    49,    50,    47,    39,
      49,    50,    51,    24,     1,    24,    39,    47,    26,    49,
      50,    35,    24,    24,    47,    12,    49,    50,    25,    31,
      47,     1,    34,    10,    10,    37,    23,    30,    -1,    26,
     160,    43,    12,    -1,    31,    -1,    -1,    34,     1,    36,
      37,    38,    39,    23,    41,    -1,    26,    -1,    45,    12,
      47,    -1,    -1,    -1,    -1,     1,    36,    -1,    38,    39,
      23,    41,    -1,    26,    24,    45,    12,    47,    -1,    -1,
      -1,    31,    -1,    36,    34,    38,    39,    37,    41,    -1,
      26,    -1,    45,    43,    47,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    39,    -1,    41,    -1,    -1,     4,    45,
       6,    47,     8,     9,    10,    11,    -1,    13,    -1,    -1,
      16,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,     4,    -1,     6,    -1,     8,
       9,    10,    11,    -1,    13,    -1,    -1,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,     4,    -1,     6,    -1,     8,     9,    10,    11,
      -1,    13,    -1,    -1,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,     6,    -1,
       8,     9,    10,    11,    -1,    13,    -1,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,     6,    -1,     8,    -1,    10,    11,    -1,    13,
      -1,    -1,    16,    17,    18,     6,    -1,     8,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    17,    18,    -1,    -1,
      -1,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    55,    47,     0,    12,     1,    23,    26,    40,
      56,    57,    58,    26,    42,    23,    26,    57,    58,    31,
      34,    37,    44,    60,    61,    47,    47,    12,    64,    14,
      14,    59,    65,    24,    43,    60,    62,    24,    62,     7,
      26,     1,    12,    23,    26,    36,    38,    39,    41,    45,
      47,    60,    66,    68,    70,    72,    73,    15,    47,    24,
      24,    47,    26,    23,    68,    69,    14,    14,    14,     3,
      14,    17,    20,    22,    26,    47,    49,    50,    70,    72,
      73,    74,    75,    14,     5,    14,    47,    26,    26,    26,
      25,     7,    63,    23,    68,    74,    51,    74,     1,    47,
       1,    74,    47,    75,    75,    75,    33,    26,     4,     6,
       8,     9,    10,    11,    13,    16,    17,    18,    19,    21,
      22,    28,    29,    30,    74,    74,     1,    24,    74,    67,
      47,    60,    24,    24,    24,    24,    15,    24,    24,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    24,    24,    71,     7,    26,
      47,    68,    26,    26,    74,    68,     7,    24,    47,    63,
      35,    25,    74,    68,    24
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 126 "jucompiler.y"
    {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("Id",(yyvsp[(2) - (5)].token));
                                                                        root = createNode("Program", "NULL"); 
                                                                        appendBrother((yyvsp[(4) - (5)].ast), tmp); 
                                                                        appendChild(tmp, root); 
                                                                    }}
    break;

  case 3:
#line 132 "jucompiler.y"
    {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("Id",(yyvsp[(2) - (4)].token));
                                                                        root = createNode("Program", "NULL");
                                                                        appendChild(tmp, root); 
                                                                    }}
    break;

  case 4:
#line 141 "jucompiler.y"
    {if(erros_sintaxe == 0) {appendBrother((yyvsp[(2) - (2)].ast), (yyvsp[(1) - (2)].ast)); (yyval.ast) = (yyvsp[(1) - (2)].ast);}}
    break;

  case 5:
#line 142 "jucompiler.y"
    {if(erros_sintaxe == 0) {appendBrother((yyvsp[(2) - (2)].ast), (yyvsp[(1) - (2)].ast)); (yyval.ast) = (yyvsp[(1) - (2)].ast);}}
    break;

  case 6:
#line 143 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(1) - (2)].ast);}}
    break;

  case 7:
#line 144 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(1) - (1)].ast);}}
    break;

  case 8:
#line 145 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(1) - (1)].ast);}}
    break;

  case 9:
#line 146 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = NULL;}}
    break;

  case 10:
#line 151 "jucompiler.y"
    {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("MethodDecl", "NULL"); 
                                                                        appendChild((yyvsp[(3) - (4)].ast), tmp); 
                                                                        appendBrother((yyvsp[(4) - (4)].ast), (yyvsp[(3) - (4)].ast)); 
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 11:
#line 163 "jucompiler.y"
    {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("FieldDecl","NULL"); 
                                                                        appendChild((yyvsp[(3) - (6)].ast),tmp); 
                                                                        appendBrother(createNode("Id",(yyvsp[(4) - (6)].token)),tmp->child); 
                                                                        appendBrother((yyvsp[(5) - (6)].ast), tmp);
                                                                        createNode_Type((yyvsp[(3) - (6)].ast),(yyvsp[(5) - (6)].ast)); 
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 12:
#line 171 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = NULL;}}
    break;

  case 13:
#line 176 "jucompiler.y"
    {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("FieldDecl", "NULL"); 
                                                                        appendChild(createNode("Id",(yyvsp[(3) - (3)].token)),tmp); 
                                                                        appendBrother(tmp, (yyvsp[(1) - (3)].ast)); 
                                                                        (yyval.ast) = (yyvsp[(1) - (3)].ast);
                                                                    }}
    break;

  case 14:
#line 182 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = createNode("NULL", "NULL");}}
    break;

  case 15:
#line 188 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = createNode("Bool", "NULL"); strcpy(ID_type,"Bool"); }}
    break;

  case 16:
#line 189 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = createNode("Int", "NULL"); strcpy(ID_type,"Int");}}
    break;

  case 17:
#line 190 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = createNode("Double", "NULL"); strcpy(ID_type,"Double");}}
    break;

  case 18:
#line 196 "jucompiler.y"
    {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("MethodHeader", "NULL");
                                                                        appendChild((yyvsp[(1) - (5)].ast), tmp);
                                                                        tmp1 = createNode("MethodParams","NULL");
                                                                        appendBrother(createNode("Id",(yyvsp[(2) - (5)].token)),tmp->child);
                                                                        appendBrother(tmp1, (yyvsp[(1) - (5)].ast));
                                                                        appendChild((yyvsp[(4) - (5)].ast), tmp1);
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 19:
#line 205 "jucompiler.y"
    {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("MethodHeader", "NULL");
                                                                        appendChild((yyvsp[(1) - (4)].ast), tmp);
                                                                        appendBrother(createNode("Id",(yyvsp[(2) - (4)].token)),tmp->child);
                                                                        appendBrother(createNode("MethodParams", "NULL"), (yyvsp[(1) - (4)].ast));
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 20:
#line 212 "jucompiler.y"
    {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("MethodHeader", "NULL");
                                                                        appendChild(createNode("Void", "NULL"), tmp);
                                                                        tmp1 = createNode("MethodParams","NULL");
                                                                        appendBrother(createNode("Id",(yyvsp[(2) - (5)].token)),tmp->child);
                                                                        appendBrother(tmp1, tmp->child);
                                                                        appendChild((yyvsp[(4) - (5)].ast), tmp1);
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 21:
#line 221 "jucompiler.y"
    {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("MethodHeader", "NULL");
                                                                        appendChild(createNode("Void", "NULL"), tmp);
                                                                        appendBrother(createNode("Id",(yyvsp[(2) - (4)].token)),tmp->child);
                                                                        appendBrother(createNode("MethodParams", "NULL"), tmp->child);
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 22:
#line 234 "jucompiler.y"
    {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("ParamDecl", "NULL");
                                                                        appendChild((yyvsp[(1) - (3)].ast), tmp);
                                                                        appendBrother(createNode("Id",(yyvsp[(2) - (3)].token)),(yyvsp[(1) - (3)].ast));
                                                                        appendBrother((yyvsp[(3) - (3)].ast),tmp);
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 23:
#line 241 "jucompiler.y"
    {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("ParamDecl", "NULL");
                                                                        appendChild(createNode("StringArray", "NULL"),tmp);
                                                                        appendBrother(createNode("Id",(yyvsp[(4) - (4)].token)),tmp->child);
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 24:
#line 247 "jucompiler.y"
    {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("ParamDecl", "NULL");
                                                                        appendChild((yyvsp[(1) - (2)].ast), tmp);
                                                                        appendBrother(createNode("Id",(yyvsp[(2) - (2)].token)),(yyvsp[(1) - (2)].ast));
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 25:
#line 257 "jucompiler.y"
    {if(erros_sintaxe == 0) {
                                                                        tmp = createNode("ParamDecl", "NULL");
                                                                        appendChild((yyvsp[(2) - (3)].ast), tmp);
                                                                        appendBrother(createNode("Id",(yyvsp[(3) - (3)].token)),(yyvsp[(2) - (3)].ast));
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 26:
#line 263 "jucompiler.y"
    {if(erros_sintaxe == 0) {
                                                                        tmp = createNode("ParamDecl", "NULL");
                                                                        appendChild((yyvsp[(2) - (4)].ast), tmp);
                                                                        appendBrother(createNode("Id",(yyvsp[(3) - (4)].token)),(yyvsp[(2) - (4)].ast));
                                                                        appendBrother((yyvsp[(4) - (4)].ast),tmp);
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 27:
#line 275 "jucompiler.y"
    {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("MethodBody", "NULL");
                                                                        appendChild((yyvsp[(2) - (3)].ast), tmp);
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 28:
#line 283 "jucompiler.y"
    {if(erros_sintaxe == 0) { appendBrother((yyvsp[(2) - (2)].ast), (yyvsp[(1) - (2)].ast)); (yyval.ast) = (yyvsp[(1) - (2)].ast);}}
    break;

  case 29:
#line 284 "jucompiler.y"
    {if(erros_sintaxe == 0) { appendBrother((yyvsp[(2) - (2)].ast), (yyvsp[(1) - (2)].ast)); (yyval.ast) = (yyvsp[(1) - (2)].ast);}}
    break;

  case 30:
#line 285 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = createNode("NULL", "NULL");}}
    break;

  case 31:
#line 291 "jucompiler.y"
    {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("VarDecl","NULL"); 
                                                                        appendChild((yyvsp[(1) - (4)].ast),tmp); 
                                                                        appendBrother(createNode("Id",(yyvsp[(2) - (4)].token)),tmp->child); 
                                                                        appendBrother((yyvsp[(3) - (4)].ast), tmp);
                                                                        createNode_Type((yyvsp[(1) - (4)].ast),(yyvsp[(3) - (4)].ast)); 
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 32:
#line 303 "jucompiler.y"
    {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("VarDecl", "NULL"); 
                                                                        appendChild(createNode("Id",(yyvsp[(3) - (3)].token)),tmp); 
                                                                        appendBrother(tmp, (yyvsp[(1) - (3)].ast)); 
                                                                        (yyval.ast) = (yyvsp[(1) - (3)].ast);
                                                                    }}
    break;

  case 33:
#line 309 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = createNode("NULL", "NULL");}}
    break;

  case 34:
#line 323 "jucompiler.y"
    {if (erros_sintaxe == 0) {
                                                                        if ((yyvsp[(2) - (3)].ast) != NULL){  
                                                                            if ((yyvsp[(2) - (3)].ast)->brother != NULL){
                                                                                tmp = createNode("Block","NULL");
																				appendChild((yyvsp[(2) - (3)].ast), tmp); 
                                                                                (yyval.ast) = tmp;
                                                                            } else {
                                                                                (yyval.ast) = (yyvsp[(2) - (3)].ast);
                                                                            }
                                                                        } else {                        
                                                                            (yyval.ast) = (yyvsp[(2) - (3)].ast);
                                                                        }
                                                                    }}
    break;

  case 35:
#line 336 "jucompiler.y"
    {if (erros_sintaxe == 0) {(yyval.ast) = NULL;}}
    break;

  case 36:
#line 337 "jucompiler.y"
    {if(erros_sintaxe == 0) {    
                                                                        tmp = createNode("If","NULL");
                                                                        appendChild((yyvsp[(3) - (5)].ast), tmp);
                                                                        if ( (yyvsp[(5) - (5)].ast) != NULL ){
                                                                            if ( (yyvsp[(5) - (5)].ast)->brother != NULL ){
                                                                                tmp1 = createNode("Block", "NULL");
                                                                                appendBrother(tmp1, (yyvsp[(3) - (5)].ast));
                                                                                appendChild((yyvsp[(5) - (5)].ast), tmp1);
                                                                                tmp2 = createNode("Block","NULL");
                                                                                appendChild(tmp2, (yyval.ast));
                                                                            } else {
                                                                                appendBrother((yyvsp[(5) - (5)].ast), (yyvsp[(3) - (5)].ast));
                                                                                tmp2 = createNode("Block","NULL");
                                                                                appendBrother(tmp2, (yyvsp[(5) - (5)].ast));
                                                                            } 
                                                                        } else {
                                                                            tmp1 = createNode("Block", "NULL");
                                                                            appendBrother(tmp1, (yyvsp[(3) - (5)].ast));
                                                                            tmp2 = createNode("Block","NULL");
                                                                            appendBrother(tmp2, (yyvsp[(3) - (5)].ast));
                                                                        }
                                                                        (yyval.ast) = tmp;                                                                                                                          
                                                                    }}
    break;

  case 37:
#line 360 "jucompiler.y"
    {if(erros_sintaxe == 0) {    
                                                                        tmp = createNode("If","NULL");
                                                                        appendChild( (yyvsp[(3) - (7)].ast), tmp);
                                                                        if ( (yyvsp[(5) - (7)].ast) != NULL ){
                                                                            if ( (yyvsp[(5) - (7)].ast)->brother != NULL ){
                                                                                tmp1 = createNode("Block", "NULL");
                                                                                appendBrother(tmp1, (yyvsp[(3) - (7)].ast));
                                                                                appendChild((yyvsp[(5) - (7)].ast), tmp1);
                                                                            } else {
                                                                                appendBrother((yyvsp[(5) - (7)].ast), (yyvsp[(3) - (7)].ast));
                                                                            } 
                                                                        } else {
                                                                            tmp1 = createNode("Block", "NULL");
                                                                            appendBrother(tmp1, (yyvsp[(3) - (7)].ast));
                                                                        }
                                                                        if ( (yyvsp[(7) - (7)].ast) != NULL ){
                                                                            if ( (yyvsp[(7) - (7)].ast)->brother != NULL ){
                                                                                tmp2 = createNode("Block", "NULL");
                                                                                appendBrother(tmp2, (yyvsp[(3) - (7)].ast));
                                                                                appendChild((yyvsp[(7) - (7)].ast), tmp2);
                                                                            } else {
                                                                                appendBrother((yyvsp[(7) - (7)].ast), (yyvsp[(3) - (7)].ast));
                                                                            } 
                                                                        } else {
                                                                            tmp1 = createNode("Block", "NULL");
                                                                            appendBrother(tmp1, (yyvsp[(3) - (7)].ast));
                                                                        }
                                                                        
                                                                        (yyval.ast) = tmp;                                                                                                                          
                                                                    }}
    break;

  case 38:
#line 390 "jucompiler.y"
    {if(erros_sintaxe == 0) {    
                                                                        tmp = createNode("While","NULL");
                                                                        appendChild( (yyvsp[(3) - (5)].ast), tmp);
                                                                        if ( (yyvsp[(5) - (5)].ast) != NULL){
							                                                if ((yyvsp[(5) - (5)].ast)->brother != NULL){
							                                                    tmp1 = createNode("Block","NULL");
							                                                    appendChild((yyvsp[(5) - (5)].ast),tmp1);
							                                                    appendBrother(tmp1,(yyvsp[(3) - (5)].ast));
							                                                } else {
							                                                    appendBrother((yyvsp[(5) - (5)].ast),(yyvsp[(3) - (5)].ast));
							                                                }
							                                            } else {
							                                                tmp1 = createNode("Block","NULL");
							                                                appendBrother(tmp1,(yyvsp[(3) - (5)].ast));
							                                            }
                                                                        (yyval.ast) = tmp;                                                                                            
                                                                    }}
    break;

  case 39:
#line 407 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = createNode("Return", "NULL"); appendChild((yyvsp[(2) - (3)].ast), (yyval.ast));}}
    break;

  case 40:
#line 408 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = createNode("Return", "NULL");}}
    break;

  case 41:
#line 409 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = NULL;}}
    break;

  case 42:
#line 410 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(1) - (2)].ast);}}
    break;

  case 43:
#line 411 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(1) - (2)].ast);}}
    break;

  case 44:
#line 412 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(1) - (2)].ast);}}
    break;

  case 45:
#line 413 "jucompiler.y"
    {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("Print", "NULL");
                                                                        appendChild((yyvsp[(3) - (5)].ast), tmp);
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 46:
#line 418 "jucompiler.y"
    {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("Print", "NULL");
                                                                        appendChild(createNode("StrLit",(yyvsp[(3) - (5)].token)), tmp);
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 47:
#line 423 "jucompiler.y"
    {(yyval.ast) = NULL;}
    break;

  case 48:
#line 427 "jucompiler.y"
    {if(erros_sintaxe == 0) {
                                                                        if ( (yyvsp[(1) - (2)].ast) != NULL){
                                                                            (yyval.ast) = (yyvsp[(1) - (2)].ast);
                                                                            appendBrother((yyvsp[(2) - (2)].ast),(yyval.ast));
                                                                        } else {
                                                                            (yyval.ast) = (yyvsp[(2) - (2)].ast);
                                                                        }
                                                                    }}
    break;

  case 49:
#line 435 "jucompiler.y"
    {if (erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(1) - (1)].ast);}}
    break;

  case 50:
#line 442 "jucompiler.y"
    {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("Call", "NULL");
                                                                        appendChild(createNode("Id",(yyvsp[(1) - (5)].token)),tmp);
                                                                        appendBrother((yyvsp[(3) - (5)].ast), tmp->child);
                                                                        appendBrother((yyvsp[(4) - (5)].ast), tmp->child);
                                                                        (yyval.ast) = tmp; 
                                                                    }}
    break;

  case 51:
#line 449 "jucompiler.y"
    {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("Call", "NULL");
                                                                        appendChild(createNode("Id",(yyvsp[(1) - (3)].token)),tmp);
                                                                        (yyval.ast) = tmp; 
                                                                    }}
    break;

  case 52:
#line 454 "jucompiler.y"
    {(yyval.ast) = NULL;}
    break;

  case 53:
#line 459 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = createNode("NULL", "NULL");}}
    break;

  case 54:
#line 460 "jucompiler.y"
    {if (erros_sintaxe == 0) {appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = (yyvsp[(1) - (3)].ast);}}
    break;

  case 55:
#line 466 "jucompiler.y"
    {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("Assign", "NULL");
                                                                        appendChild(createNode("Id",(yyvsp[(1) - (3)].token)),tmp);
                                                                        appendBrother((yyvsp[(3) - (3)].ast), tmp->child);
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 56:
#line 478 "jucompiler.y"
    {if(erros_sintaxe == 0) {
                                                                        tmp = createNode("ParseArgs", "NULL");
                                                                        appendChild(createNode("Id",(yyvsp[(3) - (7)].token)),tmp);
                                                                        appendBrother((yyvsp[(5) - (7)].ast), tmp->child);
                                                                        (yyval.ast) = tmp;
                                                                    }}
    break;

  case 57:
#line 484 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = NULL;}}
    break;

  case 58:
#line 489 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(1) - (1)].ast);}}
    break;

  case 59:
#line 490 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(1) - (1)].ast);}}
    break;

  case 60:
#line 504 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Add", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 61:
#line 505 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Sub", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 62:
#line 506 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Mul", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 63:
#line 507 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Div", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 64:
#line 508 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Mod", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 65:
#line 509 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("And", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 66:
#line 510 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Or", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 67:
#line 511 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Xor", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 68:
#line 512 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Lshift", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 69:
#line 513 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Rshift", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 70:
#line 514 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Eq", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 71:
#line 515 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Ge", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 72:
#line 516 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Gt", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 73:
#line 517 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Le", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 74:
#line 518 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Lt", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 75:
#line 519 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Ne", "NULL"); appendChild((yyvsp[(1) - (3)].ast), tmp); appendBrother((yyvsp[(3) - (3)].ast), (yyvsp[(1) - (3)].ast)); (yyval.ast) = tmp;}}
    break;

  case 76:
#line 520 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Minus", "NULL"); appendChild((yyvsp[(2) - (2)].ast), tmp); (yyval.ast) = tmp;}}
    break;

  case 77:
#line 521 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Not", "NULL"); appendChild((yyvsp[(2) - (2)].ast), tmp); (yyval.ast) = tmp;}}
    break;

  case 78:
#line 522 "jucompiler.y"
    {if(erros_sintaxe == 0) { tmp = createNode("Plus", "NULL"); appendChild((yyvsp[(2) - (2)].ast), tmp); (yyval.ast) = tmp;}}
    break;

  case 79:
#line 523 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(2) - (3)].ast);}}
    break;

  case 80:
#line 524 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(1) - (1)].ast);}}
    break;

  case 81:
#line 525 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = (yyvsp[(1) - (1)].ast);}}
    break;

  case 82:
#line 526 "jucompiler.y"
    {if(erros_sintaxe == 0) {tmp = createNode("Id",(yyvsp[(1) - (1)].token)); (yyval.ast) = tmp;}}
    break;

  case 83:
#line 527 "jucompiler.y"
    {if(erros_sintaxe == 0) {tmp = createNode("Length","NULL"); appendChild(createNode("Id",(yyvsp[(1) - (2)].token)),tmp); (yyval.ast) = tmp;}}
    break;

  case 84:
#line 528 "jucompiler.y"
    {if(erros_sintaxe == 0) {tmp = createNode("DecLit",(yyvsp[(1) - (1)].token)); (yyval.ast) = tmp;}}
    break;

  case 85:
#line 529 "jucompiler.y"
    {if(erros_sintaxe == 0) {tmp = createNode("RealLit",(yyvsp[(1) - (1)].token)); (yyval.ast) = tmp;}}
    break;

  case 86:
#line 530 "jucompiler.y"
    {if(erros_sintaxe == 0) {tmp = createNode("BoolLit",(yyvsp[(1) - (1)].token)); (yyval.ast) = tmp;}}
    break;

  case 87:
#line 531 "jucompiler.y"
    {if(erros_sintaxe == 0) {(yyval.ast) = NULL;}}
    break;


/* Line 1267 of yacc.c.  */
#line 2279 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 534 "jucompiler.y"



void yyerror(char* s)
{
    erros_sintaxe = 1;
    printf("Line %d, col %d: %s: %s\n", line_y, col_y, s, yytext);
}

int main(int argc, char* argv[]){
    if (argc >1)    {
        /*realizar a análise lexical, emitir o resultado para o stdout(erros lexicais e tokens)*/
        if(strncmp(argv[1],"-l",2)==0){
            arg = 0;
            yylex();
        }
        //Erros Lexicais Meta1
        else if(strncmp(argv[1],"-e1",3)==0){
        	arg=2;
        	yylex();
        }

        /* Imprimir a arvore */
        else if(strncmp(argv[1], "-t",2)==0){
            arg = 1;
            yyparse();  
            if (erros_sintaxe == 0)
                printParseTree (root,0);
         }
        /*no stdout apenas as mensagens de erro relativas aos erros sintáticos e lexicais */
        else if(strncmp(argv[1], "-e2",3)==0){
            arg = 1;
            yyparse();
        }
        else{
            arg = 1;
            yyparse();
        }
    /* Igual a "-e2" */
    }else{
        arg = 1;
        yyparse();
    }

  return 0;
}

