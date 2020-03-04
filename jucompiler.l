%X COMENTARIO COMENTARIO2 STRING
%%
"//"						{BEGIN COMENTARIO;}
"/*"						{BEGIN COMENTARIO2;}
<COMENTARIO>"\n$"			{BEGIN 0; printf("\n");}
<COMENTARIO2>"*/"			{BEGIN 0; printf("\n");}
[a-zA-Z]+					{BEGIN STRING; printf("ID(");}
<STRING>"\n$"				{BEGIN 0; printf(")\n");}
<STRING>.					{printf("%c", yytext[0]);}
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