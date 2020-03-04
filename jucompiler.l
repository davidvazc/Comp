%X COMENTARIO COMENTARIO2
%%
"//"						{BEGIN COMENTARIO;}
"/*"						{BEGIN COMENTARIO2;}
<COMENTARIO>\n$				{BEGIN 0; printf("\n");}
<COMENTARIO>.				;
<COMENTARIO2>"*/"			{BEGIN 0; printf("\n");}
<COMENTARIO2>.				;
^[a-zA-Z_$]+[a-zA-Z_$0-9]					{printf("ID(%s)",yytext);}
(^[1-9][0-9_]*[0-9]+ | ^[1-9])			{printf("INTLIT");}
((^[1-9][0-9_]*[0-9]+ | ^[0-9])"."((^[0-9][0-9_]*[0-9]+ | ^[0-9])+|[eE][+-](^[0-9][0-9_]*[0-9]+ | ^[0-9]))|(^[0-9][0-9_]*[0-9]+ | ^[0-9])[eE][+-](^[0-9][0-9_]*[0-9]+ | ^[0-9]))		{printf("REALLIT");}
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