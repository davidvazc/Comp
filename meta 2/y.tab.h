/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "jucompiler.y"
{
    char* token;
    struct ast_node *ast;
}
/* Line 1529 of yacc.c.  */
#line 160 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

