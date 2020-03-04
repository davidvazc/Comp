%X COMENTARIO COMENTARIO2
numero				[0-9]
letra				[a-zA-Z_$]
%%
"//"						{BEGIN COMENTARIO;}
"/*"						{BEGIN COMENTARIO2;}
<COMENTARIO>\n$				{BEGIN 0; printf("\n");}
<COMENTARIO>.				;
<COMENTARIO2>"*/"			{BEGIN 0; printf("\n");}
<COMENTARIO2>.				;
^[1-9]+([{numero}_]*{numero})*				{printf("INTLIT(%s)\n",yytext);}
^[1-9]+([0-9_]*[0-9])*"."([1-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?      {printf("REALLIT(%s)\n",yytext);}
"0."([1-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?      {printf("REALLIT(%s)\n",yytext);}
"."([1-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?      {printf("REALLIT(%s)\n",yytext);}
^[1-9]+([0-9_]*[0-9])*[Ee][+-]?[0-9][0-9_]*         {printf("REALLIT(%s)\n",yytext);}
\"(\\.|[^"\\])*\"               {printf("STRLIT(%s)\n",yytext);}
"true"|"false"				{printf("BOOLLIT\n");}
"&&"						{printf("AND\n");}
"="							{printf("ASSIGN\n");}
"*"							{printf("STAR\n");}
","							{printf("COMMA\n");}
"/"							{printf("DIV\n");}
"=="						{printf("EQ\n");}
">="						{printf("GE\n");}
">"							{printf("GT\n");}
"{"							{printf("LBRACE\n");}
"<="						{printf("LE\n");}
"("							{printf("LPAR\n");}
"["							{printf("LSQ\n");}
"<"							{printf("LT\n");}
"-"							{printf("MINUS\n");}
"%"							{printf("MOD\n");}
"!="						{printf("NE\n");}
"!"							{printf("NOT\n");}
"||"						{printf("OR\n");}
"+"							{printf("PLUS\n");}
"}"							{printf("RBRACE\n");}
")"							{printf("RPAR\n");}
"]"							{printf("RSQ\n");}
";"							{printf("SEMICOLON\n");}
"->"						{printf("ARROW\n");}
"<<"						{printf("LSHIFT\n");}
">>"						{printf("RSHIFT\n");}
"^"							{printf("XOR\n");}
"boolean"					{printf("BOOL\n");}
"class"						{printf("CLASS\n");}
".length"					{printf("DOTLENGTH\n");}
"double"					{printf("DOUBLE\n");}
"else"						{printf("ELSE\n");}
"if"						{printf("IF\n");}
"int"						{printf("INT\n");}
"System.out.print"			{printf("PRINT\n");}
"Integer.parseInt"			{printf("PARSEINT\n");}
"public"					{printf("PUBLIC\n");}
"return"					{printf("RETURN\n");}
"static"					{printf("STATIC\n");}
"String"					{printf("STRING\n");}
"void"						{printf("VOID\n");}
"while"						{printf("WHILE\n");}
("++"|"--"|"null"|"System"|"Integer")	{printf("RESERVED(%s)",yytext);}
{letra}({letra}|{numero})*					{printf("ID(%s)\n",yytext);}
.							;
\n							;
%%

int main()
{
yylex();
return 0;
}


int yywrap()
{
return 1;
}