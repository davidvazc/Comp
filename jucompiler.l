/*
Grupo - uc2017265346_uc2008109004

Nome - David Jesus Vaz Cortesao Silva
Numero - 2008109004

Nome - António Marques Maria
Numero - 2017265346 
*/

%X COMENTARIO
%X COMENTARIO1
%X STRING

%{
  
int line = 1, col = 1, lineError=0, colError=0, strLine=1, strCol;
int arg = 0;
int semi = 0;
int i, j = 0;
char *string;
char *output;
#include <ctype.h>
#include <string.h>

%}

ILLEGAL     .
NUMERO     [0-9]
LETRA														[a-zA-Z_$]
ID          [a-zA-Z_$]([a-zA-Z_$]|[0-9])*
INTLIT      [1-9]+([0-9_]*[0-9])*|0
STRLIT      \"([^\\\n""\"""\r"]|{SEQ})*\"
SEQ		       \\(f|n|r|t|\\|\")
ESPACO			(" "|"\t"|"\f")
LINEBREAK   (\n)|(\r)|(\r\n)


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

0*[1-9]+([0-9_]*[0-9])*"."([0-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?      {if (arg == 0) printf("REALLIT(%s)\n",yytext); col+=yyleng;}
0*"0."([0-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?      	                  {if (arg == 0) printf("REALLIT(%s)\n",yytext); col+=yyleng;}
0*"."[0-9]+([0-9_]*[0-9])*([Ee][+-]?[0-9][0-9_]*)?      	                    {if (arg == 0) printf("REALLIT(%s)\n",yytext); col+=yyleng;}
[0-9]+([0-9_]*[0-9])*[Ee][+-]?[0-9][0-9_]*         		                        {if (arg == 0) printf("REALLIT(%s)\n",yytext); col+=yyleng;}

"/*"                        {BEGIN COMENTARIO1; lineError=line; colError=col; col+=yyleng;}
<COMENTARIO1>{LINEBREAK}    {col=1; line++;}
<COMENTARIO1>"*/"           {BEGIN 0; col+=yyleng;}
<COMENTARIO1>.              {col+=yyleng;}
<COMENTARIO1><<EOF>>        {printf("Line %d, col %d: unterminated comment\n", lineError, colError);BEGIN 0;}

"//"                        {BEGIN COMENTARIO;col+=yyleng;}
<COMENTARIO>{LINEBREAK}     {BEGIN 0; col=1; line++;if (semi == 1){semi = 0;}}
<COMENTARIO>><EOF>>         {BEGIN 0;if (semi == 1){semi = 0;}}
<COMENTARIO>.               {col+=yyleng;}

\"                                      {BEGIN STRING; strLine = line; strCol = col;col+=yyleng;}
<STRING>\"                              {BEGIN 0;col+=yyleng;}
<STRING>\\f|\\n|\\r|\\t|\\\\|\\\"       {col+=yyleng;}
<STRING>(\\.|\\)                        {printf("Line %d, col %d: invalid escape sequence (%s)\n",line, col, yytext);col+=yyleng;BEGIN STRING;}
<STRING>{LINEBREAK}                     {BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", strLine, strCol);col=1;line++;}
<STRING><<EOF>>                         {BEGIN 0;printf("Line %d, col %d: unterminated string literal\n", strLine, strCol);}
<STRING>.                               {col+=yyleng;}

{BOOLLIT}        {if (arg == 0){printf("BOOLLIT(%s)\n",yytext);semi = 0;};col+=yyleng;}
{AND}         {if (arg == 0){printf("AND\n");semi = 0;};col+=yyleng;}
{ASSIGN}      {if (arg == 0){printf("ASSIGN\n");semi = 0;};col+=yyleng;}
{STAR}        {if (arg == 0){printf("STAR\n");semi = 0;};col+=yyleng;}
{COMMA}       {if (arg == 0){printf("COMMA\n");semi = 0;};col+=yyleng;}
{DIV}         {if (arg == 0){printf("DIV\n");semi = 0;};col+=yyleng;}
{EQ}          {if (arg == 0){printf("EQ\n");semi = 0;};col+=yyleng;}
{GE}          {if (arg == 0){printf("GE\n");semi = 0;};col+=yyleng;}
{GT}          {if (arg == 0){printf("GT\n");semi = 0;};col+=yyleng;}
{LBRACE}      {if (arg == 0){printf("LBRACE\n");semi = 0;};col+=yyleng;}
{LE}          {if (arg == 0){printf("LE\n");semi = 0;};col+=yyleng;}
{LPAR}        {if (arg == 0){printf("LPAR\n");semi = 0;};col+=yyleng;}
{LSQ}         {if (arg == 0){printf("LSQ\n");semi = 0;};col+=yyleng;}
{LT}          {if (arg == 0){printf("LT\n");semi = 0;};col+=yyleng;}
{MINUS}       {if (arg == 0){printf("MINUS\n");semi = 0;};col+=yyleng;}
{MOD}         {if (arg == 0){printf("MOD\n");semi = 0;};col+=yyleng;}
{NE}          {if (arg == 0){printf("NE\n");semi = 0;};col+=yyleng;}
{NOT}         {if (arg == 0){printf("NOT\n");semi = 0;};col+=yyleng;}
{OR}          {if (arg == 0){printf("OR\n");semi = 0;};col+=yyleng;}
{PLUS}        {if (arg == 0){printf("PLUS\n");semi = 0;};col+=yyleng;}
{RBRACE}      {if (arg == 0){printf("RBRACE\n");semi = 1;};col+=yyleng;}
{RPAR}        {if (arg == 0){printf("RPAR\n");semi = 1;};col+=yyleng;}
{RSQ}         {if (arg == 0){printf("RSQ\n");semi = 1;};col+=yyleng;}
{SEMICOLON}   {if (arg == 0){printf("SEMICOLON\n");semi = 0;};col+=yyleng;}
{ARROW}         {if (arg == 0){printf("ARROW\n");semi = 1;};col+=yyleng;}
{LSHIFT}         {if (arg == 0){printf("LSHIFT\n");semi = 1;};col+=yyleng;}
{RSHIFT}         {if (arg == 0){printf("RSHIFT\n");semi = 1;};col+=yyleng;}
{XOR}         {if (arg == 0){printf("XOR\n");semi = 1;};col+=yyleng;}
{BOOL}         {if (arg == 0){printf("BOOL\n");semi = 1;};col+=yyleng;}
{CLASS}         {if (arg == 0){printf("CLASS\n");semi = 1;};col+=yyleng;}
{DOTLENGTH}         {if (arg == 0){printf("DOTLENGTH\n");semi = 1;};col+=yyleng;}
{DOUBLE}         {if (arg == 0){printf("DOUBLE\n");semi = 1;};col+=yyleng;}
{ELSE}        {if (arg == 0){printf("ELSE\n");semi = 0;};col+=yyleng;}
{IF}          {if (arg == 0){printf("IF\n");semi = 0;};col+=yyleng;}
{INT}         {if (arg == 0){printf("INT\n");semi = 0;};col+=yyleng;}
{PRINT}       {if (arg == 0){printf("PRINT\n");semi = 0;};col+=yyleng;}
{PARSEINT}    {if (arg == 0){printf("PARSEINT\n");semi = 0;};col+=yyleng;}
{PUBLIC}         {if (arg == 0){printf("PUBLIC\n");semi = 1;};col+=yyleng;}
{RETURN}      {if (arg == 0){printf("RETURN\n");semi = 1;};col+=yyleng;}
{STATIC}         {if (arg == 0){printf("STATIC\n");semi = 1;};col+=yyleng;}
{STRING}      {if (arg == 0){printf("STRING\n");semi = 0;};col+=yyleng;}
{VOID}         {if (arg == 0){printf("VOID\n");semi = 1;};col+=yyleng;}
{WHILE}         {if (arg == 0){printf("WHILE\n");semi = 1;};col+=yyleng;}
{INTLIT}      {if (arg == 0){printf("INTLIT(%s)\n",yytext);semi = 1;};col+=yyleng;}
{LINEBREAK}   {line ++; col = 1;if (semi == 1){semi = 0;}}
{ESPACO}      {col+=yyleng;}
{RESERVED}    {if (arg == 0){printf("RESERVED(%s)\n",yytext);semi = 0;};col+=yyleng;}
{ID}          {if (arg == 0){printf("ID(%s)\n",yytext); semi = 1;};col+=yyleng;}
{STRLIT}      {if (arg == 0){printf("STRLIT(%s)\n",yytext);semi = 1;};col+=yyleng;}
{ILLEGAL}     {printf("Line %d, col %d: illegal character (%s)\n", line, col, yytext);col+=yyleng;}

%%

int main(int argc, char *argv[]) {
  if(argc>1 &&strcmp(argv[1],"-l")==0){
		arg=0;
	}
	else{
		arg=1;	
	}
	yylex();
	return 0;
}

int yywrap() {
    return 1;
}
