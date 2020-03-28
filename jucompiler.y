%{
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
%type <ast> FieldDecl
%type <ast> Comma_Id_0_more
%type <ast> Type
%type <ast> MethodHeader
%type <ast> FormalParams
%type <ast> Params_type
%type <ast> Params_type2
%type <ast> MethodBody
%type <ast> VarDecl
%type <ast> Statement
%type <ast> Stm_0_more
%type <ast> Expr_optional
%type <ast> Method_assign_parse_optional	
%type <ast> Expr_strlit_or	
%type <ast> MethodInvocation	
%type <ast> Expr_comma_expr_0_more_opt
%type <ast> Comma_expr_0_more	
%type <ast> Assignment	
%type <ast> ParseArgs	
%type <ast> Expr
%type <ast> Term_ID


%%

/* [...] -> Opcional e {...} -> zero ou mais repetições */
Start:  Program                                                         {if (erros_sintaxe == 0){root = $$;}}                                                                            
    ; 


/* Program −→ CLASS ID LBRACE { MethodDecl | FieldDecl | SEMICOLON } RBRACE */ 
Program: CLASS Term_ID LBRACE MethodDecl RBRACE                         {if(erros_sintaxe == 0){tmp = createNode("Program", "NULL"); appendChild($4, tmp); $$ = tmp;}}
    |   CLASS Term_ID LBRACE FieldDecl RBRACE                           {if(erros_sintaxe == 0){tmp = createNode("Program", "NULL"); appendChild($4, tmp); $$ = tmp;}}
    |   CLASS Term_ID LBRACE SEMICOLON RBRACE                           {if(erros_sintaxe == 0){tmp = createNode("Program", "NULL"); appendChild($4, tmp); $$ = tmp;}}
    ;


/* MethodDecl −→ PUBLIC STATIC MethodHeader MethodBody */
MethodDecl: PUBLIC STATIC MethodHeader MethodBody                       {if(erros_sintaxe == 0) { appendBrother($4, $3); $$ = $1;}}
    ;


/*---------------Acho q e assim nao?---------------------*/
/* FieldDecl -> PUBLIC STATIC Type ID { COMMA ID } SEMICOLON */  
FieldDecl: PUBLIC STATIC Type Term_ID Comma_Id_0_more SEMICOLON		    {if(erros_sintaxe == 0) {tmp = createNode("FieldDecl", "NULL"); appendChild($3, tmp); appendBrother($4, $3); appendBrother($5, tmp); createNode_TypeSpec($3, $4); $$ = tmp;}} 
		;


Comma_Id_0_more: /*epsilon*/										    {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
		| Comma_Id_0_more COMMA Term_ID								    {if(erros_sintaxe == 0) {tmp = createNode("FieldDecl", "NULL");  appendChild($3, tmp); appendBrother(tmp, $1); $$ = $1;}}
		;


/*Type −→ BOOL | INT | DOUBLE*/
Type: BOOL                                                              {if(erros_sintaxe == 0) {$$ = createNode("Bool", "NULL"); }}   
    | INT                                                               {if(erros_sintaxe == 0) {$$ = createNode("Int", "NULL");}}                
    | DOUBLE                                                            {if(erros_sintaxe == 0) {$$ = createNode("Double", "NULL");}}
    ;


/* MethodHeader -> ( Type | VOID ) ID LPAR [ FormalParams ] RPAR */
MethodHeader: Type Term_ID LPAR FormalParams RPAR                    
	| VOID Term_ID LPAR FormalParams RPAR
	;


/* FormalParams -> Type ID { COMMA Type ID } */
/* FormalParams -> STRING LSQ RSQ ID */
FormalParams: /*epsilon*/                                               {if(erros_sintaxe == 0) {$$ = createNode("FormalParams", "NULL");}} 
		| Type Term_ID Params_type                                      {if(erros_sintaxe == 0) {   tmp = createNode("FuncParams", "NULL");
                                                                                                    tmp1 = createNode("ParamDecl", "NULL");
                                                                                                    appendChild(tmp1, tmp);
                                                                                                    appendBrother($3, tmp1);
                                                                                                    appendChild($1, tmp1);
                                                                                                    appendBrother($2, $2);
                                                                                                    $$ = tmp;
                                                                        }}
		| STRING LSQ RSQ Term_ID                                        {if(erros_sintaxe == 0) {$$ = $4;}}
		;


Params_type: /*epsilon*/                                                {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
		| Params_type Params_type2                                      {if(erros_sintaxe == 0) { appendBrother($2, $1); $$ = $1;}}
		;


Params_type2: COMMA Type Term_ID                                        {if(erros_sintaxe == 0) {   tmp = createNode("ParamDecl", "NULL");
                                                                                                    appendChild($2, tmp);
                                                                                                    appendBrother($3, $2);
                                                                                                    $$ = tmp;
                                                                        }} 


/* MethodBody -> LBRACE { Statement | VarDecl } RBRACE */
MethodBody: /*epsilon*/                                                   {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL"); }}
        |   MethodBody LBRACE Statement RBRACE                          {if(erros_sintaxe == 0) {appendBrother($3, $1); $$ = $1;}}
        |   MethodBody LBRACE VarDecl RBRACE                            {if(erros_sintaxe == 0) {appendBrother($3, $1); $$ = $1;}}
        ;                     




/* VarDecl -> Type ID { COMMA ID } SEMICOLON */
VarDecl: /*epsilon*/                                                      {if(erros_sintaxe == 0) {$$ = createNode("BodyVarDecl", "NULL");}}
        |   Type Term_ID Comma_Id_0_more SEMICOLON                      {if(erros_sintaxe == 0) {   tmp = createNode("FuncParams", "NULL");
        ;                                                                                           tmp1 = createNode("ParamDecl", "NULL");
                                                                                                    appendChild(tmp1, tmp);
                                                                                                    appendBrother($3, tmp1);
                                                                                                    appendChild($1, tmp1);
                                                                                                    appendBrother($2, $1);
                                                                                                    $$ = tmp;
                                                                        }}

/*
Statement -> LBRACE { Statement } RBRACE
Statement -> IF LPAR Expr RPAR Statement [ ELSE Statement ]
Statement -> WHILE LPAR Expr RPAR Statement
Statement -> RETURN [ Expr ] SEMICOLON
Statement -> [ ( MethodInvocation | Assignment | ParseArgs ) ] SEMICOLON
Statement -> PRINT LPAR ( Expr | STRLIT ) RPAR SEMICOLON  */


Statement: LBRACE Stm_0_more RBRACE                                     {if(erros_sintaxe == 0) {  if (check_nr_nodes($2) == 3){
                                                                                                        tmp = createNode("Block","NULL");
																										appendChild($2, tmp); 
                                                                                                        $$ = tmp;
                                                                                                    } else {
                                                                                                        $$ = $2;
                                                                                                    }
                                                                        }}
		| IF LPAR Expr RPAR Statement       %prec NO_ELSE       {if(erros_sintaxe == 0) {    tmp = createNode("If","NULL");
                                                                                                    appendChild( $3, tmp);
                                                                                                    $$ = tmp;
                                                                                                    tmp1 = createNode("Block","NULL");
                                                                                                    
                                                                                                    tmp = createNode("Block", "NULL");
                                                                                                    appendBrother(tmp1, tmp);
                                                                                                    appendBrother(tmp, $3);
                                                                                                    appendChild($5, tmp);                                                                                            
                                                                }} 
        | IF LPAR Expr RPAR Statement ELSE Statement            {if(erros_sintaxe == 0) {tmp = createNode("If","NULL");
                                                                                                        appendChild( $3, tmp);
                                                                                                        $$ = tmp;
                                                                                                        tmp1 = createNode("Block","NULL");

                                                                                                        tmp2 = createNode("Block","NULL");
                                                                                                        appendBrother(tmp2, $3);
                                                                                                        appendChild($7, tmp2);
                                                                                                                                                 
                                                                }}                                        
		| WHILE LPAR Expr RPAR Statement /*AMBIGUA A DIREITA AQUI HELP <----------------------------------------------------------------------------- */
		| RETURN Expr_optional SEMICOLON
		| Method_assign_parse_optional SEMICOLON
		| PRINT LPAR Expr_strlit_or RPAR SEMICOLON
		;


Stm_0_more: /*epsilon*/                                                 {if(erros_sintaxe == 0) {$$ = createNode("Empty", "NULL");}}
		| Stm_0_more Statement                                          {if (erros_sintaxe == 0) {appendBrother($2, $1); $$ = $1;}}
		;


Expr_optional: /*epsilon*/
		| Expr
		;

Method_assign_parse_optional: /*epsilon*/
		| MethodInvocation
		| Assignment
		| ParseArgs
		;

Expr_strlit_or: Expr
		| STRLIT
		;






/* MethodInvocation -> ID LPAR [ Expr { COMMA Expr } ] RPAR */
MethodInvocation: Term_ID LPAR Expr_comma_expr_0_more_opt RPAR
		;

Expr_comma_expr_0_more_opt: /*epsilon*/
		| Expr Comma_expr_0_more
		;

Comma_expr_0_more: /*epsilon*/
		| Comma_expr_0_more COMMA Expr
		;





/* Assignment -> ID ASSIGN Expr */
Assignment: Term_ID ASSIGN Expr
		;







/* ParseArgs -> PARSEINT LPAR ID LSQ Expr RSQ RPAR */
ParseArgs: PARSEINT LPAR Term_ID LSQ Expr RSQ RPAR
		;






/* Expr −→ Expr (PLUS | MINUS | STAR | DIV | MOD) Expr */
/* Expr −→ Expr (AND | OR | XOR | LSHIFT | RSHIFT) Expr */
/* Expr −→ Expr ( EQ | GE | GT | LE | LT | NE ) Expr */
/* Expr −→ ( MINUS | NOT | PLUS ) Expr */
/* Expr −→ LPAR Expr RPAR */
/* Expr −→ MethodInvocation | Assignment | ParseArgs */
/*------------------------------> aqui so tenho o id e nao id[ID [ DOTLENGTH ]]     <---------------------------- FALTA A ARVORE*/
/* Expr −→ ID [ DOTLENGTH ] */
/* Expr −→ INTLIT | REALLIT | BOOLLIT */
Expr:   Expr PLUS Expr                                                  {if(erros_sintaxe == 0) { tmp = createNode("Add", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr MINUS Expr                                                 {if(erros_sintaxe == 0) { tmp = createNode("Sub", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr STAR Expr                                                  {if(erros_sintaxe == 0) { tmp = createNode("Mul", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr DIV Expr                                                   {if(erros_sintaxe == 0) { tmp = createNode("Div", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr MOD Expr                                                   {if(erros_sintaxe == 0) { tmp = createNode("Mod", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr AND Expr                                                   {if(erros_sintaxe == 0) { tmp = createNode("And", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr OR Expr                                                    {if(erros_sintaxe == 0) { tmp = createNode("Or", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr XOR Expr                                                   {if(erros_sintaxe == 0) { tmp = createNode("Xor", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr LSHIFT Expr                                                {if(erros_sintaxe == 0) { tmp = createNode("Lshift", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr RSHIFT Expr                                                {if(erros_sintaxe == 0) { tmp = createNode("Rshift", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr EQ Expr                                                    {if(erros_sintaxe == 0) { tmp = createNode("Eq", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr GE Expr                                                    {if(erros_sintaxe == 0) { tmp = createNode("Ge", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr GT Expr                                                    {if(erros_sintaxe == 0) { tmp = createNode("Gt", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr LE Expr                                                    {if(erros_sintaxe == 0) { tmp = createNode("Le", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr LT Expr                                                    {if(erros_sintaxe == 0) { tmp = createNode("Lt", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr NE Expr                                                    {if(erros_sintaxe == 0) { tmp = createNode("Ne", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   MINUS Expr              %prec preced                            {if(erros_sintaxe == 0) { tmp = createNode("Minus", "NULL"); appendChild($2, tmp); $$ = tmp;}}
    |   NOT Expr                %prec preced                            {if(erros_sintaxe == 0) { tmp = createNode("Not", "NULL"); appendChild($2, tmp); $$ = tmp;}}                                
    |   PLUS Expr               %prec preced                            {if(erros_sintaxe == 0) { tmp = createNode("Plus", "NULL"); appendChild($2, tmp); $$ = tmp;}}
    |   LPAR Expr RPAR                                                  {if(erros_sintaxe == 0) {$$ = $2;}}
    |   MethodInvocation                                                {if(erros_sintaxe == 0) {$$ = $1;}}
    |   Assignment                                                      {if(erros_sintaxe == 0) {$$ = $1;}}
    |   ParseArgs                                                       {if(erros_sintaxe == 0) {$$ = $1;}}
    |   Term_ID Dotlength_optional                                      {if(erros_sintaxe == 0) {$$ = $1;}}
    |   INTLIT                                                          {if(erros_sintaxe == 0) {$$ = createNode("IntLit", $1);}}
    |   REALLIT                                                         {if(erros_sintaxe == 0) {$$ = createNode("RealLit", $1);}}
    |   BOOLLIT                                                         {if(erros_sintaxe == 0) {$$ = createNode("BoolLit", $1);}}
    ;

Dotlength_optional: /*epsilon*/
	| DOTLENGTH
	;


Term_ID:    ID                                                          {if(erros_sintaxe == 0) {$$ = createNode("Id", $1);}}
%%


void yyerror(char* s)
{
    erros_sintaxe = 1;
    printf("Line %d, col %d: %s: %s\n", line_y, col_y, s, yytext);
}

int main(int argc, char* argv[]){
    if (argc >1)    {
        /*realizar a análise lexical, emitir o resultado para o stdout (é isto?)*/
        if(strncmp(argv[1],"-l",2 || strncmp(argv[1],"-e1",2)==0){
            arg = 0;
            yylex();
            /*falta no caso da opção -l também os tokens encontrados*/
        }else if(strncmp(argv[1], "-t",2)==0){
            arg = 1;
            yyparse();  
            if (erros_sintaxe == 0)
                printParseTree (root,0);
        /* aqui falta a opcao "-e2 em que deve escrever */
        /*no stdout apenas as mensagens de erro relativas aos erros sintáticos e lexicais */
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