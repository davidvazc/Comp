%X COMENTARIO COMENTARIO2
%{
	int line=1;
	int col=1;
	int start_line=1;
	int start_col=1;
	int flag;
%}
numero														[0-9]
letra														[a-zA-Z_$]
escape														\\(f|n|r|t|\\|\")
letras_escape												(f|n|r|t|\|")
%%
"//"														{BEGIN COMENTARIO;}
"/*"														{BEGIN COMENTARIO2; start_line=line; start_col=col; col+=yyleng;}
<COMENTARIO>\n$												{BEGIN 0; col+=yyleng;}
<COMENTARIO>.												{col+=yyleng;}
<COMENTARIO2>"*/"											{BEGIN 0; col+=yyleng;}
<COMENTARIO2>.												{col+=yyleng;}
<COMENTARIO2>\n												{line++;col=1;}
<COMENTARIO2><<EOF>>										{printf("Line %d, col%d: unterminated comment\n", start_line, start_col); yyterminate();}
[1-9]+([{numero}_]*{numero})*								{if(flag) printf("INTLIT(%s)\n",yytext); col+=yyleng;}
0															{if(flag) printf("INTLIT(%s)\n",yytext); col+=yyleng;}
[1-9]+([0-9_]*[0-9])*"."([1-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?      {if(flag) printf("REALLIT(%s)\n",yytext); col+=yyleng;}
"0."([1-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?      	{if(flag) printf("REALLIT(%s)\n",yytext); col+=yyleng;}
"."([1-9]+([0-9_]*[0-9])*)?([Ee][+-]?[0-9][0-9_]*)?      	{if(flag) printf("REALLIT(%s)\n",yytext); col+=yyleng;}
[1-9]+([0-9_]*[0-9])*[Ee][+-]?[0-9][0-9_]*         		{if(flag) printf("REALLIT(%s)\n",yytext); col+=yyleng;}
\"([^\n\"\\]|{escape})*\"(\n)$               				{if(flag) printf("STRLIT(%s)\n",yytext); col+=yyleng;}
"true"|"false"												{if(flag) printf("BOOLLIT\n"); col+=yyleng;}
"&&"														{if(flag) printf("AND\n"); col+=yyleng;}
"="															{if(flag) printf("ASSIGN\n"); col+=yyleng;}
"*"															{if(flag) printf("STAR\n"); col+=yyleng;}
","															{if(flag) printf("COMMA\n"); col+=yyleng;}
"/"															{if(flag) printf("DIV\n"); col+=yyleng;}
"=="														{if(flag) printf("EQ\n"); col+=yyleng;}
">="														{if(flag) printf("GE\n"); col+=yyleng;}
">"															{if(flag) printf("GT\n"); col+=yyleng;}
"{"															{if(flag) printf("LBRACE\n"); col+=yyleng;}
"<="														{if(flag) printf("LE\n"); col+=yyleng;}
"("															{if(flag) printf("LPAR\n"); col+=yyleng;}
"["															{if(flag) printf("LSQ\n"); col+=yyleng;}
"<"															{if(flag) printf("LT\n"); col+=yyleng;}
"-"															{if(flag) printf("MINUS\n"); col+=yyleng;}
"%"															{if(flag) printf("MOD\n"); col+=yyleng;}
"!="														{if(flag) printf("NE\n"); col+=yyleng;}
"!"															{if(flag) printf("NOT\n"); col+=yyleng;}
"||"														{if(flag) printf("OR\n"); col+=yyleng;}
"+"															{if(flag) printf("PLUS\n"); col+=yyleng;}
"}"															{if(flag) printf("RBRACE\n"); col+=yyleng;}
")"															{if(flag) printf("RPAR\n"); col+=yyleng;}
"]"															{if(flag) printf("RSQ\n"); col+=yyleng;}
";"															{if(flag) printf("SEMICOLON\n"); col+=yyleng;}
"->"														{if(flag) printf("ARROW\n"); col+=yyleng;}
"<<"														{if(flag) printf("LSHIFT\n"); col+=yyleng;}
">>"														{if(flag) printf("RSHIFT\n"); col+=yyleng;}
"^"															{if(flag) printf("XOR\n"); col+=yyleng;}
"boolean"													{if(flag) printf("BOOL\n"); col+=yyleng;}
"class"														{if(flag) printf("CLASS\n"); col+=yyleng;}
".length"													{if(flag) printf("DOTLENGTH\n"); col+=yyleng;}
"double"													{if(flag) printf("DOUBLE\n"); col+=yyleng;}
"else"														{if(flag) printf("ELSE\n"); col+=yyleng;}
"if"														{if(flag) printf("IF\n"); col+=yyleng;}
"int"														{if(flag) printf("INT\n"); col+=yyleng;}
"System.out.print"											{if(flag) printf("PRINT\n"); col+=yyleng;}
"Integer.parseInt"											{if(flag) printf("PARSEINT\n"); col+=yyleng;}
"public"													{if(flag) printf("PUBLIC\n"); col+=yyleng;}
"return"													{if(flag) printf("RETURN\n"); col+=yyleng;}
"static"													{if(flag) printf("STATIC\n"); col+=yyleng;}
"String"													{if(flag) printf("STRING\n"); col+=yyleng;}
"void"														{if(flag) printf("VOID\n"); col+=yyleng;}
"while"														{if(flag) printf("WHILE\n"); col+=yyleng;}
"++"|"--"|"null"|"System"|"Integer"							{if(flag) printf("RESERVED(%s)\n",yytext); col+=yyleng;}
{letra}({letra}|{numero})*									{if(flag) printf("ID(%s)\n",yytext); col+=yyleng;}
\"([^\n\"\\]|{escape})*\"               					{printf("Line %d, col %d: unterminated string literal\n", line, col); col+=yyleng;}
\\\"([^{letras_escape}])*\"									{printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col, yytext); col+=yyleng;}
" "|\t														{col+=yyleng;}
"\n"															{line+=1; col=1;}
.															{printf("Line %d, col %d: illegal character(%s)\n", line, col, yytext); col+=yyleng;}
%%

int main(int argc, char* argv[])
{
	if(argc>1 &&strcmp(argv[1],"-l")==0){
		flag=1;
	}
	else{
		flag=0;	
	}
	yylex();
	return 0;
}


int yywrap()
{
	return 1;
}
