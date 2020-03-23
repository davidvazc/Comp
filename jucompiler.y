%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(char* s);

extern int line_y, col_y;
extern int arg;
extern char* yytext;
int erros_sintaxe = 0;
ASTtree* root = NULL, *tmp = NULL, *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL, *tmp4 = NULL;
char varType[10];

%}

%union{
    char* token;
    struct ast_node *ast;
}

%token precedencia
%token <token> BOOLLIT             
%token <token> AND                 
%token <token> ASSIGN              
%token <token> STAR                
%token <token> COMMA               
%token <token> DIV                 
%token <token> EQ                  
%token <token> GE                  
%token <token> GT                  
%token <token> LBRACE              
%token <token> LE                  
%token <token> LPAR                
%token <token> LSQ                 
%token <token> LT                  
%token <token> MINUS               
%token <token> MOD                 
%token <token> NE                  
%token <token> NOT                 
%token <token> OR                  
%token <token> PLUS                
%token <token> RBRACE              
%token <token> RPAR                
%token <token> RSQ                 
%token <token> SEMICOLON           
%token <token> ARROW               
%token <token> LSHIFT              
%token <token> RSHIFT              
%token <token> XOR                 
%token <token> BOOL          
%token <token> CLASS               
%token <token> DOTLENGTH     
%token <token> DOUBLE       
%token <token> ELSE                
%token <token> IF                  
%token <token> INT                 
%token <token> PRINT    
%token <token> PARSEINT 
%token <token> PUBLIC       
%token <token> RETURN       
%token <token> STATIC       
%token <token> STRING       
%token <token> VOID                
%token <token> WHILE
%token <token> RESERVED               

%token <token> ID
%token <token> EXP
%token <token> REALLIT
%token <token> INTLIT
%token <token> STRLIT

%nonassoc NO_ELSE
%nonassoc ELSE

%left COMMA
%right ASSIGN
%left OR 
%left AND
%left LT
%left GT
%left EQ
%left NE
%left LE
%left GE
%left PLUS
%left MINUS
%left STAR
%left DIV
%left MOD
%right NOT
%right precedencia

%nonassoc preced

%type <ast> Start
%type <ast> Program
%type <ast> MethodDecl

%%

/* [...] -> Opcional e {...} -> zero ou mais repetições */
Start:  Program                                                         {if (erros_sintaxe == 0){root = $$;}}                                                                            
    ;   

/*Type −→ BOOL | INT | DOUBLE*/
Type: BOOL                                                            {if(erros_sintaxe == 0) {$$ = createNode("Bool", "NULL"); }}   
    | INT                                                             {if(erros_sintaxe == 0) {$$ = createNode("Int", "NULL");}}                
    | DOUBLE                                                         {if(erros_sintaxe == 0) {$$ = createNode("Double", "NULL");}}
    ;



/* Expr −→ Expr (PLUS | MINUS | STAR | DIV | MOD) Expr */
/* Expr −→ Expr (AND | OR | XOR | LSHIFT | RSHIFT) Expr */

Expr: Expr PLUS Expr                                                  {if(erros_sintaxe == 0) { tmp = createNode("Add", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr MINUS Expr                                                 {if(erros_sintaxe == 0) { tmp = createNode("Sub", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr STAR Expr                                                  {if(erros_sintaxe == 0) { tmp = createNode("Mul", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr DIV Expr                                                   {if(erros_sintaxe == 0) { tmp = createNode("Div", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr MOD Expr                                                   {if(erros_sintaxe == 0) { tmp = createNode("Mod", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr AND Expr                                                   {if(erros_sintaxe == 0) { tmp = createNode("And", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr OR Expr                                                   {if(erros_sintaxe == 0) { tmp = createNode("Or", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr XOR Expr                                                   {if(erros_sintaxe == 0) { tmp = createNode("Xor", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr LSHIFT Expr                                                   {if(erros_sintaxe == 0) { tmp = createNode("Lshift", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr RSHIFT Expr                                                   {if(erros_sintaxe == 0) { tmp = createNode("Rshift", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    ;

Term_ID:    ID                                                         {if(erros_sintaxe == 0) {$$ = createNode("Id", $1);}}
%%


void yyerror(char* s)
{
    erros_sintaxe = 1;
    printf("Line %d, column %d: %s: %s\n", line_y, col_y, s, yytext);
}

int main(int argc, char* argv[]){
    if (argc >1)    {
        if(strncmp(argv[1],"-l",2)==0){
            arg = 0;
            yylex();
        }else if(strncmp(argv[1], "-t",2)==0){
            arg = 1;
            yyparse();  
            if (erros_sintaxe == 0)
                printParseTree (root,0);
        }else{
            arg = 1;
            yyparse();
        }
    }else{
        arg = 1;
        yyparse();
    }

  return 0;
}