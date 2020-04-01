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
char ID_type[10];
ASTtree* root = NULL, *tmp = NULL, *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL, *tmp4 = NULL;

%}

%union{
    char* token;
    struct ast_node *ast;
}


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
%left XOR 
%left AND
%left EQ NE
%left GT LT GE LE
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT preced



%type <ast> Start
%type <ast> Program
%type <ast> Method_Field_Semi_0_more
%type <ast> MethodDecl
%type <ast> FieldDecl
%type <ast> Comma_Id_0_more
%type <ast> Comma_Id_0_more_Var
%type <ast> Type
%type <ast> MethodHeader
%type <ast> Stm_or_VarDecl_0_more
%type <ast> FormalParams
%type <ast> Params_type
%type <ast> Params_type2
%type <ast> MethodBody
%type <ast> VarDecl
%type <ast> Statement
%type <ast> Stm_0_more
%type <ast> Expr_optional
%type <ast> Method_assign_parse_optional
%type <ast> MethodInvocation	
%type <ast> Expr_comma_expr_0_more_opt
%type <ast> Comma_expr_0_more	
%type <ast> Assignment	
%type <ast> ParseArgs	
%type <ast> Expr	
%type <ast> Expr2
%type <ast> Dotlength_optional
%type <ast> Term_ID


%%

/* [...] -> Opcional e {...} -> zero ou mais repetições */
Start:  Program                                                         {if (erros_sintaxe == 0){root = $$;}}                                                                            
    ; 


/* Program −→ CLASS ID LBRACE { MethodDecl | FieldDecl | SEMICOLON } RBRACE */ 
Program: CLASS Term_ID LBRACE Method_Field_Semi_0_more RBRACE           {if(erros_sintaxe == 0){tmp = createNode("Program", "NULL"); appendChild($2, tmp); appendBrother($4, $2); $$ = tmp;}}              
    ;


Method_Field_Semi_0_more: /*epsilon*/                                   {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL"); }}                                       
        | Method_Field_Semi_0_more MethodDecl                           {if(erros_sintaxe == 0) {appendBrother($2, $1); $$ = $1;}}
        | Method_Field_Semi_0_more FieldDecl                            {if(erros_sintaxe == 0) {appendBrother($2, $1); $$ = $1;}}
        | Method_Field_Semi_0_more SEMICOLON                            {if(erros_sintaxe == 0) {$$ = $1;}}
        ;


/* MethodDecl −→ PUBLIC STATIC MethodHeader MethodBody */
MethodDecl: PUBLIC STATIC MethodHeader MethodBody                       {if(erros_sintaxe == 0){tmp = createNode("MethodDecl", "NULL"); appendChild($3, tmp); appendBrother($4, $3); $$ = tmp;}}
        ;


/* FieldDecl -> PUBLIC STATIC Type ID { COMMA ID } SEMICOLON */ 
/* FieldDecl -> error SEMICOLON */
FieldDecl: PUBLIC STATIC Type Term_ID Comma_Id_0_more SEMICOLON			{if(erros_sintaxe == 0) {tmp = createNode("FieldDecl", "NULL"); appendChild($3, tmp); appendBrother($4, $3); appendBrother($5, tmp); createNode_TypeSpec($3, $4); $$ = tmp;}} 
		| error SEMICOLON												{if(erros_sintaxe == 0) {$$ = NULL;}}
		;


Comma_Id_0_more: /*epsilon*/										    {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
		| Comma_Id_0_more COMMA Term_ID								    {if(erros_sintaxe == 0) {tmp = createNode("VarDecl", "NULL"); 
                                                                                                    tmp1= createNode(ID_type,"NULL"); 
                                                                                                    appendChild(tmp1,tmp); 
                                                                                                    appendBrother($3, tmp1);
                                                                                                    $$ = tmp;}}
		;


/*Type −→ BOOL | INT | DOUBLE*/
Type: BOOL                                                              {if(erros_sintaxe == 0) {$$ = createNode("Bool", "NULL"); strcpy(ID_type,"Bool"); }}   
    | INT                                                               {if(erros_sintaxe == 0) {$$ = createNode("Int", "NULL"); strcpy(ID_type,"Int");}}                
    | DOUBLE                                                            {if(erros_sintaxe == 0) {$$ = createNode("Double", "NULL"); strcpy(ID_type,"Double");}}
    ;


/* MethodHeader -> ( Type | VOID ) ID LPAR [ FormalParams ] RPAR */
MethodHeader: Type Term_ID LPAR FormalParams RPAR                       {if(erros_sintaxe == 0){tmp = createNode("MethodHeader", "NULL");
                                                                                                    appendChild($1, tmp);
                                                                                                    appendBrother($2, $1);
                                                                                                    appendBrother($4, $1);
                                                                                                    $$ = tmp;}}                   
	| VOID Term_ID LPAR FormalParams RPAR                               {if(erros_sintaxe == 0) {   tmp = createNode("MethodHeader", "NULL");
                                                                                                    tmp1 = createNode("Void", "NULL");
                                                                                                    appendChild(tmp1, tmp);
                                                                                                    appendBrother($2, tmp1);
                                                                                                    appendBrother($4, tmp1);
                                                                                                    $$ = tmp;}}
	;


/* FormalParams -> Type ID { COMMA Type ID } */
/* FormalParams -> STRING LSQ RSQ ID */
FormalParams: /*epsilon*/                                               {if(erros_sintaxe == 0) {$$ = createNode("MethodParams", "NULL");}} 
		| Type Term_ID Params_type                                      {if(erros_sintaxe == 0) {   tmp = createNode("MethodParams", "NULL");
                                                                                                    tmp1 = createNode("ParamDecl", "NULL");
                                                                                                    appendChild(tmp1, tmp);
                                                                                                    appendBrother($3, tmp1);
                                                                                                    appendChild($1, tmp1);
                                                                                                    appendBrother($2, $1);
                                                                                                    $$ = tmp;
                                                                        }}
		| STRING LSQ RSQ Term_ID                                        {if(erros_sintaxe == 0) {   tmp = createNode("MethodParams", "NULL");
                                                                                                    tmp1 = createNode("ParamDecl", "NULL");
                                                                                                    tmp2 = createNode("StringArray", "NULL");
                                                                                                    appendChild(tmp1, tmp);
                                                                                                    appendChild(tmp2, tmp1);
                                                                                                    appendBrother($4, tmp2);
                                                                                                    $$ = tmp;
                                                                        }}
		;


Params_type: /*epsilon*/                                                {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
		| Params_type Params_type2                                      {if(erros_sintaxe == 0) { appendBrother($2, $1); $$ = $1;}}
		;


Params_type2: COMMA Type Term_ID                                        {if(erros_sintaxe == 0) {   tmp = createNode("ParamDecl", "NULL");
                                                                                                    appendChild($2, tmp);
                                                                                                    appendBrother($3, $2);
                                                                                                    $$ = tmp;
                                                                        }} 
        ;


/* MethodBody -> LBRACE { Statement | VarDecl } RBRACE */
MethodBody: LBRACE Stm_or_VarDecl_0_more RBRACE                         {if(erros_sintaxe == 0) {   tmp = createNode("MethodBody", "NULL");
                                                                                                    appendChild($2, tmp);
                                                                                                    $$ = tmp;
                                                                        }}                         
        ;

Stm_or_VarDecl_0_more: /*epsilon*/                                      {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
    | Stm_or_VarDecl_0_more Statement                                   {if(erros_sintaxe == 0) { appendBrother($2, $1); $$ = $1;}}
    | Stm_or_VarDecl_0_more VarDecl                                     {if(erros_sintaxe == 0) { appendBrother($2, $1); $$ = $1;}}
    ;




/* VarDecl -> Type ID { COMMA ID } SEMICOLON */
VarDecl: Type Term_ID Comma_Id_0_more_Var SEMICOLON                      {if(erros_sintaxe == 0) {   tmp = createNode("VarDecl", "NULL");
                                                                                                    appendBrother($3, tmp);
                                                                                                    appendChild($1, tmp);
                                                                                                    appendBrother($2, $1);
                                                                                                    $$ = tmp;
                                                                        }}
    ;

Comma_Id_0_more_Var: /*epsilon*/										    {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
		| Comma_Id_0_more_Var COMMA Term_ID								    {if(erros_sintaxe == 0) {tmp = createNode("VarDecl", "NULL"); tmp2=createNode(ID_type,"NULL"); appendChild(tmp2,tmp); appendBrother($3, tmp2); appendBrother(tmp, $1); $$ = $1;}}
		;

/*
Statement -> LBRACE { Statement } RBRACE
Statement -> IF LPAR Expr RPAR Statement [ ELSE Statement ]
Statement -> WHILE LPAR Expr RPAR Statement
Statement -> RETURN [ Expr ] SEMICOLON
Statement -> [ ( MethodInvocation | Assignment | ParseArgs ) ] SEMICOLON
Statement -> PRINT LPAR ( Expr | STRLIT ) RPAR SEMICOLON
Statement -> error SEMICOLON  */


Statement: LBRACE Stm_0_more RBRACE                                     {if(erros_sintaxe == 0) {  if (check_nr_nodes($2) == 3){
                                                                                                        tmp = createNode("Block","NULL");
																										appendChild($2, tmp); 
                                                                                                        $$ = tmp;
                                                                                                    } else {
                                                                                                        $$ = $2;
                                                                                                    }
                                                                        }}
		| IF LPAR Expr2 RPAR Statement       %prec NO_ELSE       {if(erros_sintaxe == 0) {    tmp = createNode("If","NULL");
                                                                                                    appendChild( $3, tmp);
                                                                                                    appendBrother($5, $3);
                                                                                                    tmp1 = createNode("Blockdoif1","NULL");
                                                                                                    appendBrother(tmp1, $5);
                                                                                                    $$ = tmp;                                                                                       
                                                                }} 
        | IF LPAR Expr2 RPAR Statement ELSE Statement            {if(erros_sintaxe == 0) {tmp = createNode("If","NULL");
                                                                                                        appendChild( $3, tmp);
                                                                                                        appendBrother($5, $3);
                                                                                                        tmp1 = createNode("Blockdo2if","NULL");
                                                                                                        appendBrother(tmp1, $5);
                                                                                                        tmp2 = createNode("Block2else","NULL");
                                                                                                        appendBrother(tmp2, tmp1);
                                                                                                        appendChild($7, tmp2);
                                                                                                        $$ = tmp;
                                                                                                                                                 
                                                                }}                                        
		| WHILE LPAR Expr2 RPAR Statement                        {if(erros_sintaxe == 0) {    tmp = createNode("While","NULL");
                                                                                                    appendChild( $3, tmp);


                                                                                                    if ( $5 != NULL)
							                                                                        {
							                                                                          if ($5->brother != NULL)
							                                                                          {
							                                                                            tmp1 = createNode("Block",NULL);
							                                                                            appendChild($5,tmp1);
							                                                                            appendBrother(tmp1,$3);
							                                                                          }
							                                                                          else
							                                                                          {
							                                                                            appendBrother($5,$3);
							                                                                          }
							                                                                        }
							                                                                        else
							                                                                        {
							                                                                          tmp1 = createNode("Block",NULL);
							                                                                          appendBrother(tmp1,$3);
							                                                                        }
                                                                                                    $$ = tmp;                                                                                            
                                                                }}
		|   RETURN Expr_optional SEMICOLON                        {if(erros_sintaxe == 0) {   tmp = createNode("Return", "NULL");
                                                                                                    appendChild($2, tmp);
                                                                                                    $$ = tmp;
                                                                }}
		|   Method_assign_parse_optional SEMICOLON              {if(erros_sintaxe == 0) {$$ = $1;}}
		|   PRINT LPAR Expr2 RPAR SEMICOLON                      {if(erros_sintaxe == 0) {   tmp = createNode("Print", "NULL");
                                                                                                    appendChild($3, tmp);
                                                                                                    $$ = tmp;
                                                                }}     
        |   PRINT LPAR STRLIT RPAR SEMICOLON                    {if(erros_sintaxe == 0) {   tmp = createNode("Print", "NULL");
                                                                                                    tmp1 = createNode("StrLit", $3);
                                                                                                    appendChild(tmp1, tmp);
                                                                                                    $$ = tmp;
                                                                }}              
		|   error SEMICOLON										{if(erros_sintaxe == 0) {$$ = NULL;}}
		;


Stm_0_more: /*epsilon*/                                         {if(erros_sintaxe == 0) {$$ = createNode("Empty", "NULL");}}
		| Stm_0_more Statement                                  {if (erros_sintaxe == 0) {appendBrother($2, $1); $$ = $1;}}
		;


Expr_optional: /*epsilon*/                                      {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
		| Expr2                                                  {if(erros_sintaxe == 0) {$$ = $1;}}
		;


Method_assign_parse_optional: /*epsilon*/                       {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
		| MethodInvocation                                      {if(erros_sintaxe == 0) {$$ = $1;}}
		| Assignment                                            {if(erros_sintaxe == 0) {$$ = $1;}}
		| ParseArgs                                             {if(erros_sintaxe == 0) {$$ = $1;}}
		;


/* MethodInvocation -> ID LPAR [ Expr { COMMA Expr } ] RPAR */
/* MethodInvocation -> ID LPAR error RPAR */
MethodInvocation: Term_ID LPAR Expr_comma_expr_0_more_opt RPAR  {if(erros_sintaxe == 0) {   tmp = createNode("Call", "NULL");
                                                                                                    appendChild($1, tmp);
                                                                                                    appendBrother($3, $1); 
                                                                                                    $$ = tmp; }} 
		| Term_ID LPAR error RPAR								{if(erros_sintaxe == 0) {$$ = NULL;}}
		;


Expr_comma_expr_0_more_opt: /*epsilon*/                         {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
		| Expr2 Comma_expr_0_more                                {if (erros_sintaxe == 0) { appendBrother($2, $1); $$ = $1;}}
		;


Comma_expr_0_more: /*epsilon*/                                  {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
		| Comma_expr_0_more COMMA Expr2                          {if(erros_sintaxe == 0) { appendBrother($3, $1); $$ = $1;}}
		;


/* Assignment -> ID ASSIGN Expr */
Assignment: Term_ID ASSIGN Expr2                                 {if(erros_sintaxe == 0) {   tmp = createNode("Assign", "NULL");
                                                                                                    appendChild($1, tmp);
                                                                                                    appendBrother($3, $1);
                                                                                                    $$ = tmp;
                                                                }}
		;


/* ParseArgs -> PARSEINT LPAR ID LSQ Expr RSQ RPAR */
/* ParseArgs -> PARSEINT LPAR error RPAR */
ParseArgs: PARSEINT LPAR Term_ID LSQ Expr2 RSQ RPAR              {if(erros_sintaxe == 0) {   tmp = createNode("ParseArgs", "NULL");
                                                                                                                    appendChild($3, tmp);
                                                                                                                    appendBrother($5, $3);
                                                                                                                    $$ = tmp;
                                                                }}
		| PARSEINT LPAR error RPAR								{if(erros_sintaxe == 0) {$$ = NULL;}} 
		;
		
		
Expr2: Assignment				{if(erros_sintaxe == 0) {$$ = $1;}}
     | Expr					{if(erros_sintaxe == 0) {$$ = $1;}}
     ;


/* Expr −→ Expr (PLUS | MINUS | STAR | DIV | MOD) Expr */
/* Expr −→ Expr (AND | OR | XOR | LSHIFT | RSHIFT) Expr */
/* Expr −→ Expr ( EQ | GE | GT | LE | LT | NE ) Expr */
/* Expr −→ ( MINUS | NOT | PLUS ) Expr */
/* Expr −→ LPAR Expr RPAR */
/* Expr −→ MethodInvocation | Assignment | ParseArgs */
/* Expr −→ ID [ DOTLENGTH ] */
/* Expr −→ INTLIT | REALLIT | BOOLLIT */
/* Expr -> LPAR error RPAR */
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
    |   MINUS Expr %prec preced                                         {if(erros_sintaxe == 0) { tmp = createNode("Minus", "NULL"); appendChild($2, tmp); $$ = tmp;}}
    |   NOT Expr                                                        {if(erros_sintaxe == 0) { tmp = createNode("Not", "NULL"); appendChild($2, tmp); $$ = tmp;}}                                
    |   PLUS Expr %prec preced                                          {if(erros_sintaxe == 0) { tmp = createNode("Plus", "NULL"); appendChild($2, tmp); $$ = tmp;}}
    |   LPAR Expr2 RPAR                                                  {if(erros_sintaxe == 0) {$$ = $2;}}
    |   MethodInvocation                                                {if(erros_sintaxe == 0) {$$ = $1;}}
    |   ParseArgs                                                       {if(erros_sintaxe == 0) {$$ = $1;}}
    |   Term_ID Dotlength_optional                                      {if(erros_sintaxe == 0) {$$ = $1;}}
    |   INTLIT                                                          {if(erros_sintaxe == 0) {$$ = createNode("DecLit", $1);}}
    |   REALLIT                                                         {if(erros_sintaxe == 0) {$$ = createNode("RealLit", $1);}}
    |   BOOLLIT                                                         {if(erros_sintaxe == 0) {$$ = createNode("BoolLit", $1);}}
    |   LPAR error RPAR                                                 {if(erros_sintaxe == 0) {$$ = NULL;}}
    ;

Dotlength_optional: /*epsilon*/                                         {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
	| DOTLENGTH                                                         {if(erros_sintaxe == 0) {$$ = createNode("DotLength", $1);}}  
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
        /*realizar a análise lexical, emitir o resultado para o stdout(erros lexicais e tokens)*/
        if(strncmp(argv[1],"-l",2)==0){
            arg = 0;
            yylex();
        }
        //Erros Lexicais Meta1
        else if(strncmp(argv[1],"-e1",3)==0){
        	arg=2;
        	yylex();
        }

        /* Imprimir a arvore */
        else if(strncmp(argv[1], "-t",2)==0){
            arg = 1;
            yyparse();  
            if (erros_sintaxe == 0)
                printParseTree (root,0);
         }
        /*no stdout apenas as mensagens de erro relativas aos erros sintáticos e lexicais */
        else if(strncmp(argv[1], "-e2",3)==0){
            arg = 1;
            yyparse();
        }
        else{
            arg = 1;
            yyparse();
        }
    /* Igual a "-e2" */
    }else{
        arg = 1;
        yyparse();
    }

  return 0;
}
