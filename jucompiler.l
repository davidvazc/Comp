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
  
int line = 1, col = 1, lineError=0, colError=0, strLine=1, strCol, arg = 0;

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

0*[1-9]+([0-9_]*[0-9])*"."([0-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?      {if (arg == 0) printf("REALLIT(%s)\n",yytext); col+=yyleng;}
0*"0."([0-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?      	                  {if (arg == 0) printf("REALLIT(%s)\n",yytext); col+=yyleng;}
0*"."[0-9]+([0-9_]*[0-9])*([Ee][+-]?[0-9][0-9_]*)?      	                      {if (arg == 0) printf("REALLIT(%s)\n",yytext); col+=yyleng;}
[0-9]+([0-9_]*[0-9])*[Ee][+-]?[0-9][0-9_]*         		                          {if (arg == 0) printf("REALLIT(%s)\n",yytext); col+=yyleng;}

"/*"                                    {BEGIN COMENTARIO1; lineError=line; colError=col; col+=yyleng;}
<COMENTARIO1>{LINEBREAK}                {col=1; line++;}
<COMENTARIO1>"*/"                       {BEGIN 0; col+=yyleng;}
<COMENTARIO1>.                          {col+=yyleng;}
<COMENTARIO1><<EOF>>                    {printf("Line %d, col %d: unterminated comment\n", lineError, colError);BEGIN 0;}

"//"                                    {BEGIN COMENTARIO;col+=yyleng;}
<COMENTARIO>{LINEBREAK}                 {BEGIN 0; col=1; line++;}
<COMENTARIO>><EOF>>                     {BEGIN 0;}
<COMENTARIO>.                           {col+=yyleng;}

\"                                      {BEGIN STRING; strLine = line; strCol = col;col+=yyleng;}
<STRING>\"                              {BEGIN 0;col+=yyleng;}
<STRING>\\f|\\n|\\r|\\t|\\\\|\\\"       {col+=yyleng;}
<STRING>(\\.|\\)                        {printf("Line %d, col %d: invalid escape sequence (%s)\n",line, col, yytext);col+=yyleng;BEGIN STRING;}
<STRING>{LINEBREAK}                     {BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", strLine, strCol);col=1;line++;}
<STRING><<EOF>>                         {BEGIN 0;printf("Line %d, col %d: unterminated string literal\n", strLine, strCol);}
<STRING>.                               {col+=yyleng;}

{BOOLLIT}     {if (arg == 0){printf("BOOLLIT(%s)\n",yytext);};col+=yyleng;}
{AND}         {if (arg == 0){printf("AND\n");};col+=yyleng;}
{ASSIGN}      {if (arg == 0){printf("ASSIGN\n");};col+=yyleng;}
{STAR}        {if (arg == 0){printf("STAR\n"); };col+=yyleng;}
{COMMA}       {if (arg == 0){printf("COMMA\n");};col+=yyleng;}
{DIV}         {if (arg == 0){printf("DIV\n");};col+=yyleng;}
{EQ}          {if (arg == 0){printf("EQ\n");};col+=yyleng;}
{GE}          {if (arg == 0){printf("GE\n");};col+=yyleng;}
{GT}          {if (arg == 0){printf("GT\n");};col+=yyleng;}
{LBRACE}      {if (arg == 0){printf("LBRACE\n");};col+=yyleng;}
{LE}          {if (arg == 0){printf("LE\n");};col+=yyleng;}
{LPAR}        {if (arg == 0){printf("LPAR\n");};col+=yyleng;}
{LSQ}         {if (arg == 0){printf("LSQ\n");};col+=yyleng;}
{LT}          {if (arg == 0){printf("LT\n");};col+=yyleng;}
{MINUS}       {if (arg == 0){printf("MINUS\n");};col+=yyleng;}
{MOD}         {if (arg == 0){printf("MOD\n");};col+=yyleng;}
{NE}          {if (arg == 0){printf("NE\n");};col+=yyleng;}
{NOT}         {if (arg == 0){printf("NOT\n");};col+=yyleng;}
{OR}          {if (arg == 0){printf("OR\n");};col+=yyleng;}
{PLUS}        {if (arg == 0){printf("PLUS\n");};col+=yyleng;}
{RBRACE}      {if (arg == 0){printf("RBRACE\n");};col+=yyleng;}
{RPAR}        {if (arg == 0){printf("RPAR\n");};col+=yyleng;}
{RSQ}         {if (arg == 0){printf("RSQ\n");};col+=yyleng;}
{SEMICOLON}   {if (arg == 0){printf("SEMICOLON\n");};col+=yyleng;}
{ARROW}       {if (arg == 0){printf("ARROW\n");};col+=yyleng;}
{LSHIFT}      {if (arg == 0){printf("LSHIFT\n");};col+=yyleng;}
{RSHIFT}      {if (arg == 0){printf("RSHIFT\n");};col+=yyleng;}
{XOR}         {if (arg == 0){printf("XOR\n");};col+=yyleng;}
{BOOL}        {if (arg == 0){printf("BOOL\n");};col+=yyleng;}
{CLASS}       {if (arg == 0){printf("CLASS\n");};col+=yyleng;}
{DOTLENGTH}   {if (arg == 0){printf("DOTLENGTH\n");};col+=yyleng;}
{DOUBLE}      {if (arg == 0){printf("DOUBLE\n");};col+=yyleng;}
{ELSE}        {if (arg == 0){printf("ELSE\n");};col+=yyleng;}
{IF}          {if (arg == 0){printf("IF\n");};col+=yyleng;}
{INT}         {if (arg == 0){printf("INT\n");};col+=yyleng;}
{PRINT}       {if (arg == 0){printf("PRINT\n");};col+=yyleng;}
{PARSEINT}    {if (arg == 0){printf("PARSEINT\n");};col+=yyleng;}
{PUBLIC}      {if (arg == 0){printf("PUBLIC\n");};col+=yyleng;}
{RETURN}      {if (arg == 0){printf("RETURN\n");};col+=yyleng;}
{STATIC}      {if (arg == 0){printf("STATIC\n");};col+=yyleng;}
{STRING}      {if (arg == 0){printf("STRING\n");};col+=yyleng;}
{VOID}        {if (arg == 0){printf("VOID\n");};col+=yyleng;}
{WHILE}       {if (arg == 0){printf("WHILE\n");};col+=yyleng;}
{INTLIT}      {if (arg == 0){printf("INTLIT(%s)\n",yytext);};col+=yyleng;}
{LINEBREAK}   {line ++; col = 1;}
{ESPACO}      {col+=yyleng;}
{RESERVED}    {if (arg == 0){printf("RESERVED(%s)\n",yytext);};col+=yyleng;}
{ID}          {if (arg == 0){printf("ID(%s)\n",yytext); };col+=yyleng;}
{STRLIT}      {if (arg == 0){printf("STRLIT(%s)\n",yytext);};col+=yyleng;}
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
