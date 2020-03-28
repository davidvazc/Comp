/*
Grupo - uc2017265346_uc2008109004

Nome - David Jesus Vaz Cortesao Silva
Numero - 2008109004

Nome - António Marques Maria
Numero - 2017265346 
*/

%X COMENTARIO
%X COMENTARIO1
%X COMENTARIO2

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "arvore.h"
  
int line = 1, col = 1, lineError=0, colError=0, strLine=1, strCol, arg = 0;
int line_y = 1, col_y = 1;
#define RETURN_TOKEN(token_yacc)   {yylval.token = strdup(yytext); line_y=line; col_y=col; col+=yyleng; return token_yacc;}

%}

ILLEGAL             .
NUMERO              [0-9]
LETRA								[a-zA-Z_$]
ID                  [a-zA-Z_$]([a-zA-Z_$]|[0-9])*
INTLIT              [1-9]+([0-9_]*[0-9])*|0
STRLIT              \"([^\\\n""\"""\r"]|{SEQ})*\"
SEQ		              \\(f|n|r|t|\\|\")
ESPACO			        (" "|"\t"|"\f")
LINEBREAK           (\n)|(\r)|(\r\n)


BOOLLIT             ("true"|"false")
AND                 "&&"
ASSIGN              "="
STAR                "*"
COMMA               ","
DIV                 "/"
EQ                  "=="
GE                  ">="
GT                  ">"
LBRACE              "{"
LE                  "<="
LPAR                "("
LSQ                 "["
LT                  "<"
MINUS               "-"
MOD                 "%"
NE                  "!="
NOT                 "!"
OR                  "||"
PLUS                "+"
RBRACE              "}"
RPAR                ")"
RSQ                 "]"
SEMICOLON           ";"
ARROW               "->"
LSHIFT              "<<"
RSHIFT              ">>"
XOR                 "^"
BOOL                "boolean"
CLASS               "class"
DOTLENGTH           ".length"
DOUBLE              "double"
ELSE                "else"
IF                  "if"
INT                 "int"
PRINT               "System.out.print"
PARSEINT            "Integer.parseInt"
PUBLIC              "public"
RETURN              "return"
STATIC              "static"
STRING              "String"
VOID                "void"
WHILE               "while"
RESERVED            ("++"|"--"|"null"|"Integer"|"System"|"break"|"byte"|"case"|"catch"|"char"|"const"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"protected"|"short"|"strictfp"|"super"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"|"abstract"|"continue"|"volatile"|"switch"|"assert"|"default"|"package"|"synchronized"|"synchronized"|"do"|"goto"|"private")

%%

0*[1-9]+([0-9_]*[0-9])*"."([0-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?        {if (arg == 0) printf("REALLIT(%s)\n",yytext); if (arg == 1) {RETURN_TOKEN(REALLIT);}; col+=yyleng;}
0*"0."([0-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?      	                  {if (arg == 0) printf("REALLIT(%s)\n",yytext); if (arg == 1) {RETURN_TOKEN(REALLIT);}; col+=yyleng;}
0*"."[0-9]+([0-9_]*[0-9])*([Ee][+-]?[0-9][0-9_]*)?      	                      {if (arg == 0) printf("REALLIT(%s)\n",yytext); if (arg == 1) {RETURN_TOKEN(REALLIT);}; col+=yyleng;}
[0-9]+([0-9_]*[0-9])*[Ee][+-]?[0-9][0-9_]*         		                          {if (arg == 0) printf("REALLIT(%s)\n",yytext); if (arg == 1) {RETURN_TOKEN(REALLIT);}; col+=yyleng;}

"/*"                                    		{BEGIN COMENTARIO1; lineError=line; colError=col; col+=yyleng;}
<COMENTARIO1>{LINEBREAK}                		{col_y = col=1; line++;}
<COMENTARIO1>"*/"                       		{BEGIN 0; col+=yyleng;}
<COMENTARIO1>.                          		{col+=yyleng;}
<COMENTARIO1><<EOF>>                    		{printf("Line %d, col %d: unterminated comment\n", lineError, colError);BEGIN 0;}

"//"                                    		{BEGIN COMENTARIO;col+=yyleng;}
<COMENTARIO>{LINEBREAK}                 		{BEGIN 0; col_y = col=1; line_y = line++;}
<COMENTARIO>><EOF>>                     		{BEGIN 0;}
<COMENTARIO>.                           		{col+=yyleng;}

\"                                      	 	{BEGIN COMENTARIO2; strLine = line; strCol = col;col+=yyleng;}
<COMENTARIO2>\"                              	{BEGIN 0;col+=yyleng;}
<COMENTARIO2>\\f|\\n|\\r|\\t|\\\\|\\\"       	{col+=yyleng;}
<COMENTARIO2>(\\.|\\)                        	{printf("Line %d, col %d: invalid escape sequence (%s)\n",line, col, yytext);col+=yyleng;BEGIN COMENTARIO2;}
<COMENTARIO2>{LINEBREAK}                     	{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", strLine, strCol);col=1;line++;}
<COMENTARIO2><<EOF>>                         	{BEGIN 0;printf("Line %d, col %d: unterminated string literal\n", strLine, strCol);}
<COMENTARIO2>.                               	{col+=yyleng;}

{BOOLLIT}     {if (arg == 0){printf("BOOLLIT(%s)\n",yytext);} 	if (arg == 1) {RETURN_TOKEN(BOOLLIT);}; 	col+=yyleng;}
{AND}         {if (arg == 0){printf("AND\n");} 				  	if (arg == 1) {RETURN_TOKEN(AND);};			col+=yyleng;}
{ASSIGN}      {if (arg == 0){printf("ASSIGN\n");}			  	if (arg == 1) {RETURN_TOKEN(ASSIGN);};		col+=yyleng;}
{STAR}        {if (arg == 0){printf("STAR\n"); }				if (arg == 1) {RETURN_TOKEN(STAR);};		col+=yyleng;}
{COMMA}       {if (arg == 0){printf("COMMA\n");}				if (arg == 1) {RETURN_TOKEN(COMMA);};		col+=yyleng;}
{DIV}         {if (arg == 0){printf("DIV\n");}					if (arg == 1) {RETURN_TOKEN(DIV);};			col+=yyleng;}
{EQ}          {if (arg == 0){printf("EQ\n");}					if (arg == 1) {RETURN_TOKEN(EQ);};			col+=yyleng;}
{GE}          {if (arg == 0){printf("GE\n");}					if (arg == 1) {RETURN_TOKEN(GE);};			col+=yyleng;}
{GT}          {if (arg == 0){printf("GT\n");}					if (arg == 1) {RETURN_TOKEN(GT);};			col+=yyleng;}
{LBRACE}      {if (arg == 0){printf("LBRACE\n");}				if (arg == 1) {RETURN_TOKEN(LBRACE);};		col+=yyleng;}
{LE}          {if (arg == 0){printf("LE\n");}					if (arg == 1) {RETURN_TOKEN(LE);};			col+=yyleng;}
{LPAR}        {if (arg == 0){printf("LPAR\n");}					if (arg == 1) {RETURN_TOKEN(LPAR);};		col+=yyleng;}
{LSQ}         {if (arg == 0){printf("LSQ\n");}					if (arg == 1) {RETURN_TOKEN(LSQ);};			col+=yyleng;}
{LT}          {if (arg == 0){printf("LT\n");}					if (arg == 1) {RETURN_TOKEN(LT);};			col+=yyleng;}
{MINUS}       {if (arg == 0){printf("MINUS\n");}				if (arg == 1) {RETURN_TOKEN(MINUS);};		col+=yyleng;}
{MOD}         {if (arg == 0){printf("MOD\n");}					if (arg == 1) {RETURN_TOKEN(MOD);};			col+=yyleng;}
{NE}          {if (arg == 0){printf("NE\n");}					if (arg == 1) {RETURN_TOKEN(NE);};			col+=yyleng;}
{NOT}         {if (arg == 0){printf("NOT\n");}					if (arg == 1) {RETURN_TOKEN(NOT);};			col+=yyleng;}
{OR}          {if (arg == 0){printf("OR\n");}					if (arg == 1) {RETURN_TOKEN(OR);};			col+=yyleng;}
{PLUS}        {if (arg == 0){printf("PLUS\n");}					if (arg == 1) {RETURN_TOKEN(PLUS);};		col+=yyleng;}
{RBRACE}      {if (arg == 0){printf("RBRACE\n");}				if (arg == 1) {RETURN_TOKEN(RBRACE);};		col+=yyleng;}
{RPAR}        {if (arg == 0){printf("RPAR\n");}					if (arg == 1) {RETURN_TOKEN(RPAR);};		col+=yyleng;}
{RSQ}         {if (arg == 0){printf("RSQ\n");}					if (arg == 1) {RETURN_TOKEN(RSQ);};			col+=yyleng;}
{SEMICOLON}   {if (arg == 0){printf("SEMICOLON\n");}			if (arg == 1) {RETURN_TOKEN(SEMICOLON);};	col+=yyleng;}
{ARROW}       {if (arg == 0){printf("ARROW\n");}				if (arg == 1) {RETURN_TOKEN(ARROW);};		col+=yyleng;}
{LSHIFT}      {if (arg == 0){printf("LSHIFT\n");}				if (arg == 1) {RETURN_TOKEN(LSHIFT);};		col+=yyleng;}
{RSHIFT}      {if (arg == 0){printf("RSHIFT\n");}				if (arg == 1) {RETURN_TOKEN(RSHIFT);};		col+=yyleng;}
{XOR}         {if (arg == 0){printf("XOR\n");}					if (arg == 1) {RETURN_TOKEN(XOR);};			col+=yyleng;}
{BOOL}        {if (arg == 0){printf("BOOL\n");}					if (arg == 1) {RETURN_TOKEN(BOOL);};		col+=yyleng;}
{CLASS}       {if (arg == 0){printf("CLASS\n");}				if (arg == 1) {RETURN_TOKEN(CLASS);};		col+=yyleng;}
{DOTLENGTH}   {if (arg == 0){printf("DOTLENGTH\n");}			if (arg == 1) {RETURN_TOKEN(DOTLENGTH);};	col+=yyleng;}
{DOUBLE}      {if (arg == 0){printf("DOUBLE\n");}				if (arg == 1) {RETURN_TOKEN(DOUBLE);};		col+=yyleng;}
{ELSE}        {if (arg == 0){printf("ELSE\n");}					if (arg == 1) {RETURN_TOKEN(ELSE);};		col+=yyleng;}
{IF}          {if (arg == 0){printf("IF\n");}					if (arg == 1) {RETURN_TOKEN(IF);};			col+=yyleng;}
{INT}         {if (arg == 0){printf("INT\n");}					if (arg == 1) {RETURN_TOKEN(INT);};			col+=yyleng;}
{PRINT}       {if (arg == 0){printf("PRINT\n");}				if (arg == 1) {RETURN_TOKEN(PRINT);};		col+=yyleng;}
{PARSEINT}    {if (arg == 0){printf("PARSEINT\n");}				if (arg == 1) {RETURN_TOKEN(PARSEINT);};	col+=yyleng;}
{PUBLIC}      {if (arg == 0){printf("PUBLIC\n");}				if (arg == 1) {RETURN_TOKEN(PUBLIC);};		col+=yyleng;}
{RETURN}      {if (arg == 0){printf("RETURN\n");}				if (arg == 1) {RETURN_TOKEN(RETURN);};		col+=yyleng;}
{STATIC}      {if (arg == 0){printf("STATIC\n");}				if (arg == 1) {RETURN_TOKEN(STATIC);};		col+=yyleng;}
{STRING}      {if (arg == 0){printf("STRING\n");}				if (arg == 1) {RETURN_TOKEN(STRING);};		col+=yyleng;}
{VOID}        {if (arg == 0){printf("VOID\n");}					if (arg == 1) {RETURN_TOKEN(VOID);};		col+=yyleng;}
{WHILE}       {if (arg == 0){printf("WHILE\n");}				if (arg == 1) {RETURN_TOKEN(WHILE);};		col+=yyleng;}
{INTLIT}      {if (arg == 0){printf("INTLIT(%s)\n",yytext);}	if (arg == 1) {RETURN_TOKEN(INTLIT);};		col+=yyleng;}
{LINEBREAK}   {line ++; col = 1;}
{ESPACO}      {col+=yyleng;}
{RESERVED}    {if (arg == 0) {printf("RESERVED(%s)\n",yytext);} if (arg == 1){ RETURN_TOKEN(RESERVED);}; 	col+=yyleng;}
{ID}          {if (arg == 0) {printf("ID(%s)\n",yytext);}       if (arg == 1) {RETURN_TOKEN(ID);}; 			col+=yyleng;}
{STRLIT}      {if (arg == 0) {printf("STRLIT(%s)\n",yytext);}   if (arg == 1) {RETURN_TOKEN(STRLIT);}; 		col+=yyleng;}
{ILLEGAL}     {printf("Line %d, col %d: illegal character (%s)\n", line, col, yytext);col+=yyleng;}

%%


int yywrap() {
    return 1;
}
