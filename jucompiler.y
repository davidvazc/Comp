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



%start Program
%left COMMA
%right ASSIGN
%left OR
%left XOR
%left AND
%left EQ NE
%left LT GT LE GE
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%right preced
%left LBRACE LPAR LSQ RSQ RPAR RBRACE

%nonassoc NO_ELSE
%nonassoc ELSE



%type <ast> Program
%type <ast> Program_Aux
%type <ast> MethodDecl
%type <ast> FieldDecl
%type <ast> FieldDecl_aux
%type <ast> VarDecl_Aux
%type <ast> Type
%type <ast> MethodHeader
%type <ast> MethodBody_Aux
%type <ast> FormalParams
%type <ast> FormalParams_Aux
%type <ast> MethodBody
%type <ast> VarDecl
%type <ast> Statement
%type <ast> Statement_Aux
%type <ast> MethodInvocation	
%type <ast> MethodInvocation_Aux
%type <ast> Assignment	
%type <ast> ParseArgs	
%type <ast> Expr	
%type <ast> Expr_Aux



%%


Program: 
    CLASS ID LBRACE Program_Aux RBRACE                              {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("Id",$2);
                                                                        root = createNode("Program", "NULL"); 
                                                                        appendBrother($4, tmp); 
                                                                        appendChild(tmp, root); 
                                                                    }}
    | CLASS ID LBRACE RBRACE                                        {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("Id",$2);
                                                                        root = createNode("Program", "NULL");
                                                                        appendChild(tmp, root); 
                                                                    }}         
    ;


Program_Aux: 
      Program_Aux MethodDecl                                        {if(erros_sintaxe == 0) {appendBrother($2, $1); $$ = $1;}}
    | Program_Aux FieldDecl                                         {if(erros_sintaxe == 0) {appendBrother($2, $1); $$ = $1;}}
    | Program_Aux SEMICOLON                                         {if(erros_sintaxe == 0) {$$ = $1;}}
    | FieldDecl                                                     {if(erros_sintaxe == 0) {$$ = $1;}}
    | MethodDecl                                                    {if(erros_sintaxe == 0) {$$ = $1;}}
    | SEMICOLON                                                     {if(erros_sintaxe == 0) {$$ = NULL;}}
    ;

/* MethodDecl −→ PUBLIC STATIC MethodHeader MethodBody */
MethodDecl: 
    PUBLIC STATIC MethodHeader MethodBody                           {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("MethodDecl", "NULL"); 
                                                                        appendChild($3, tmp); 
                                                                        appendBrother($4, $3); 
                                                                        $$ = tmp;
                                                                    }}
    ;


/* FieldDecl -> PUBLIC STATIC Type ID { COMMA ID } SEMICOLON */ 
/* FieldDecl -> error SEMICOLON */
FieldDecl: 
    PUBLIC STATIC Type ID FieldDecl_aux SEMICOLON			        {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("FieldDecl","NULL"); 
                                                                        appendChild($3,tmp); 
                                                                        appendBrother(createNode("Id",$4),tmp->child); 
                                                                        appendBrother($5, tmp);
                                                                        createNode_Type($3,$5); 
                                                                        $$ = tmp;
                                                                    }}
	| error SEMICOLON												{if(erros_sintaxe == 0) {$$ = NULL;}}
	;


FieldDecl_aux: 
    FieldDecl_aux COMMA ID	                                        {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("FieldDecl", "NULL"); 
                                                                        appendChild(createNode("Id",$3),tmp); 
                                                                        appendBrother(tmp, $1); 
                                                                        $$ = $1;
                                                                    }}
	| /* empty */  								                    {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
	;


/*Type −→ BOOL | INT | DOUBLE*/
Type: 
    BOOL                                                             {if(erros_sintaxe == 0) {$$ = createNode("Bool", "NULL"); strcpy(ID_type,"Bool"); }}   
    | INT                                                            {if(erros_sintaxe == 0) {$$ = createNode("Int", "NULL"); strcpy(ID_type,"Int");}}                
    | DOUBLE                                                         {if(erros_sintaxe == 0) {$$ = createNode("Double", "NULL"); strcpy(ID_type,"Double");}}
    ;


/* MethodHeader -> ( Type | VOID ) ID LPAR [ FormalParams ] RPAR */
MethodHeader: 
    Type ID LPAR FormalParams RPAR                                  {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("MethodHeader", "NULL");
                                                                        appendChild($1, tmp);
                                                                        tmp1 = createNode("MethodParams","NULL");
                                                                        appendBrother(createNode("Id",$2),tmp->child);
                                                                        appendBrother(tmp1, $1);
                                                                        appendChild($4, tmp1);
                                                                        $$ = tmp;
                                                                    }}
    | Type ID LPAR RPAR                                             {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("MethodHeader", "NULL");
                                                                        appendChild($1, tmp);
                                                                        appendBrother(createNode("Id",$2),tmp->child);
                                                                        appendBrother(createNode("MethodParams", "NULL"), $1);
                                                                        $$ = tmp;
                                                                    }}
	| VOID ID LPAR FormalParams RPAR                                {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("MethodHeader", "NULL");
                                                                        appendChild(createNode("Void", "NULL"), tmp);
                                                                        tmp1 = createNode("MethodParams","NULL");
                                                                        appendBrother(createNode("Id",$2),tmp->child);
                                                                        appendBrother(tmp1, tmp->child);
                                                                        appendChild($4, tmp1);
                                                                        $$ = tmp;
                                                                    }}
    | VOID ID LPAR RPAR                                             {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("MethodHeader", "NULL");
                                                                        appendChild(createNode("Void", "NULL"), tmp);
                                                                        appendBrother(createNode("Id",$2),tmp->child);
                                                                        appendBrother(createNode("MethodParams", "NULL"), tmp->child);
                                                                        $$ = tmp;
                                                                    }}
	;


/* FormalParams -> Type ID { COMMA Type ID } */
/* FormalParams -> STRING LSQ RSQ ID */
FormalParams: 
    Type ID FormalParams_Aux                                        {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("ParamDecl", "NULL");
                                                                        appendChild($1, tmp);
                                                                        appendBrother(createNode("Id",$2),$1);
                                                                        appendBrother($3,tmp);
                                                                        $$ = tmp;
                                                                    }}
	| STRING LSQ RSQ ID                                             {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("ParamDecl", "NULL");
                                                                        appendChild(createNode("StringArray", "NULL"),tmp);
                                                                        appendBrother(createNode("Id",$4),tmp->child);
                                                                        $$ = tmp;
                                                                    }}
    | Type ID                                                       {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("ParamDecl", "NULL");
                                                                        appendChild($1, tmp);
                                                                        appendBrother(createNode("Id",$2),$1);
                                                                        $$ = tmp;
                                                                    }}
	;


FormalParams_Aux: 
    COMMA Type ID                                                   {if(erros_sintaxe == 0) {
                                                                        tmp = createNode("ParamDecl", "NULL");
                                                                        appendChild($2, tmp);
                                                                        appendBrother(createNode("Id",$3),$2);
                                                                        $$ = tmp;
                                                                    }}
	| COMMA Type ID FormalParams_Aux                                {if(erros_sintaxe == 0) {
                                                                        tmp = createNode("ParamDecl", "NULL");
                                                                        appendChild($2, tmp);
                                                                        appendBrother(createNode("Id",$3),$2);
                                                                        appendBrother($4,tmp);
                                                                        $$ = tmp;
                                                                    }}
	;


/* MethodBody -> LBRACE { Statement | VarDecl } RBRACE */
MethodBody: 
    LBRACE MethodBody_Aux RBRACE                                    {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("MethodBody", "NULL");
                                                                        appendChild($2, tmp);
                                                                        $$ = tmp;
                                                                    }}                         
    ;

MethodBody_Aux:                                     
    MethodBody_Aux Statement                                        {if(erros_sintaxe == 0) { appendBrother($2, $1); $$ = $1;}}
    | MethodBody_Aux VarDecl                                        {if(erros_sintaxe == 0) { appendBrother($2, $1); $$ = $1;}}
    |/* empty */                                                     {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
    ;


/* VarDecl -> Type ID { COMMA ID } SEMICOLON */
VarDecl: 
    Type ID VarDecl_Aux SEMICOLON                                   {if(erros_sintaxe == 0)
                                                                        {tmp = createNode("VarDecl","NULL"); 
                                                                        appendChild($1,tmp); 
                                                                        appendBrother(createNode("Id",$2),tmp->child); 
                                                                        appendBrother($3, tmp);
                                                                        createNode_Type($1,$3); 
                                                                        $$ = tmp;
                                                                    }}

    ;

VarDecl_Aux: 
	VarDecl_Aux COMMA ID  								            {if(erros_sintaxe == 0) 
                                                                        {tmp = createNode("VarDecl", "NULL"); 
                                                                        appendChild(createNode("Id",$3),tmp); 
                                                                        appendBrother(tmp, $1); 
                                                                        $$ = $1;
                                                                    }}
    | /* empty */  								                    {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}                  
	;

/*
Statement -> LBRACE { Statement } RBRACE
Statement -> IF LPAR Expr RPAR Statement [ ELSE Statement ]
Statement -> WHILE LPAR Expr RPAR Statement
Statement -> RETURN [ Expr ] SEMICOLON
Statement -> [ ( MethodInvocation | Assignment | ParseArgs ) ] SEMICOLON
Statement -> PRINT LPAR ( Expr | STRLIT ) RPAR SEMICOLON
Statement -> error SEMICOLON  */


Statement: 
    LBRACE Statement_Aux RBRACE                                     {if (erros_sintaxe == 0) {
                                                                        if ($2 != NULL){  
                                                                            if ($2->brother != NULL){
                                                                                tmp = createNode("Block","NULL");
																				appendChild($2, tmp); 
                                                                                $$ = tmp;
                                                                            } else {
                                                                                $$ = $2;
                                                                            }
                                                                        } else {                        
                                                                            $$ = $2;
                                                                        }
                                                                    }}
    | LBRACE RBRACE                                                 {if (erros_sintaxe == 0) {$$ = NULL;}}
	| IF LPAR Expr RPAR Statement %prec NO_ELSE                     {if(erros_sintaxe == 0) {    
                                                                        tmp = createNode("If","NULL");
                                                                        appendChild($3, tmp);
                                                                        if ( $5 != NULL ){
                                                                            if ( $5->brother != NULL ){
                                                                                tmp1 = createNode("Block", "NULL");
                                                                                appendBrother(tmp1, $3);
                                                                                appendChild($5, tmp1);
                                                                                tmp2 = createNode("Block","NULL");
                                                                                appendChild(tmp2, $$);
                                                                            } else {
                                                                                appendBrother($5, $3);
                                                                                tmp2 = createNode("Block","NULL");
                                                                                appendBrother(tmp2, $5);
                                                                            } 
                                                                        } else {
                                                                            tmp1 = createNode("Block", "NULL");
                                                                            appendBrother(tmp1, $3);
                                                                            tmp2 = createNode("Block","NULL");
                                                                            appendBrother(tmp2, $3);
                                                                        }
                                                                        $$ = tmp;                                                                                                                          
                                                                    }} 
    | IF LPAR Expr RPAR Statement ELSE Statement                    {if(erros_sintaxe == 0) {    
                                                                        tmp = createNode("If","NULL");
                                                                        appendChild( $3, tmp);
                                                                        if ( $5 != NULL ){
                                                                            if ( $5->brother != NULL ){
                                                                                tmp1 = createNode("Block", "NULL");
                                                                                appendBrother(tmp1, $3);
                                                                                appendChild($5, tmp1);
                                                                            } else {
                                                                                appendBrother($5, $3);
                                                                            } 
                                                                        } else {
                                                                            tmp1 = createNode("Block", "NULL");
                                                                            appendBrother(tmp1, $3);
                                                                        }
                                                                        if ( $7 != NULL ){
                                                                            if ( $7->brother != NULL ){
                                                                                tmp2 = createNode("Block", "NULL");
                                                                                appendBrother(tmp2, $3);
                                                                                appendChild($7, tmp2);
                                                                            } else {
                                                                                appendBrother($7, $3);
                                                                            } 
                                                                        } else {
                                                                            tmp1 = createNode("Block", "NULL");
                                                                            appendBrother(tmp1, $3);
                                                                        }
                                                                        
                                                                        $$ = tmp;                                                                                                                          
                                                                    }}                                        
	| WHILE LPAR Expr RPAR Statement                                {if(erros_sintaxe == 0) {    
                                                                        tmp = createNode("While","NULL");
                                                                        appendChild( $3, tmp);
                                                                        if ( $5 != NULL){
							                                                if ($5->brother != NULL){
							                                                    tmp1 = createNode("Block","NULL");
							                                                    appendChild($5,tmp1);
							                                                    appendBrother(tmp1,$3);
							                                                } else {
							                                                    appendBrother($5,$3);
							                                                }
							                                            } else {
							                                                tmp1 = createNode("Block","NULL");
							                                                appendBrother(tmp1,$3);
							                                            }
                                                                        $$ = tmp;                                                                                            
                                                                    }}
	|   RETURN Expr SEMICOLON                                       {if(erros_sintaxe == 0) {$$ = createNode("Return", "NULL"); appendChild($2, $$);}}
    |   RETURN SEMICOLON                                            {if(erros_sintaxe == 0) {$$ = createNode("Return", "NULL");}}
	|   SEMICOLON                                                   {if(erros_sintaxe == 0) {$$ = NULL;}}
    |   MethodInvocation SEMICOLON                                  {if(erros_sintaxe == 0) {$$ = $1;}}
    |   Assignment SEMICOLON                                        {if(erros_sintaxe == 0) {$$ = $1;}}
    |   ParseArgs SEMICOLON                                         {if(erros_sintaxe == 0) {$$ = $1;}}
	|   PRINT LPAR Expr RPAR SEMICOLON                              {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("Print", "NULL");
                                                                        appendChild($3, tmp);
                                                                        $$ = tmp;
                                                                    }}     
    |   PRINT LPAR STRLIT RPAR SEMICOLON                            {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("Print", "NULL");
                                                                        appendChild(createNode("StrLit",$3), tmp);
                                                                        $$ = tmp;
                                                                    }}             
	|   error SEMICOLON										        {$$ = NULL;}
	;


Statement_Aux: Statement_Aux Statement                              {if(erros_sintaxe == 0) {
                                                                        if ( $1 != NULL){
                                                                            $$ = $1;
                                                                            appendBrother($2,$$);
                                                                        } else {
                                                                            $$ = $2;
                                                                        }
                                                                    }}
		| Statement                                                 {if (erros_sintaxe == 0) {$$ = $1;}}
		;


/* MethodInvocation -> ID LPAR [ Expr { COMMA Expr } ] RPAR */
/* MethodInvocation -> ID LPAR error RPAR */
MethodInvocation: 
    ID LPAR Expr MethodInvocation_Aux RPAR                          {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("Call", "NULL");
                                                                        appendChild(createNode("Id",$1),tmp);
                                                                        appendBrother($3, tmp->child);
                                                                        appendBrother($4, tmp->child);
                                                                        $$ = tmp; 
                                                                    }}
    | ID LPAR RPAR                                                  {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("Call", "NULL");
                                                                        appendChild(createNode("Id",$1),tmp);
                                                                        $$ = tmp; 
                                                                    }}
	| ID LPAR error RPAR								            {$$ = NULL;}
	;


MethodInvocation_Aux: 
    /* empty */                                                     {if(erros_sintaxe == 0) {$$ = createNode("NULL", "NULL");}}
	| MethodInvocation_Aux COMMA Expr                               {if (erros_sintaxe == 0) {appendBrother($3, $1); $$ = $1;}}
	;


/* Assignment -> ID ASSIGN Expr */
Assignment: 
    ID ASSIGN Expr                                                  {if(erros_sintaxe == 0) {   
                                                                        tmp = createNode("Assign", "NULL");
                                                                        appendChild(createNode("Id",$1),tmp);
                                                                        appendBrother($3, tmp->child);
                                                                        $$ = tmp;
                                                                    }}
	;


/* ParseArgs -> PARSEINT LPAR ID LSQ Expr RSQ RPAR */
/* ParseArgs -> PARSEINT LPAR error RPAR */
ParseArgs: 
    PARSEINT LPAR ID LSQ Expr RSQ RPAR                             {if(erros_sintaxe == 0) {
                                                                        tmp = createNode("ParseArgs", "NULL");
                                                                        appendChild(createNode("Id",$3),tmp);
                                                                        appendBrother($5, tmp->child);
                                                                        $$ = tmp;
                                                                    }}
	| PARSEINT LPAR error RPAR								        {if(erros_sintaxe == 0) {$$ = NULL;}} 
	;
		
		
Expr: 
    Assignment				                                        {if(erros_sintaxe == 0) {$$ = $1;}}
    | Expr_Aux					                                    {if(erros_sintaxe == 0) {$$ = $1;}}
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
Expr_Aux:   
    Expr_Aux PLUS Expr_Aux                                          {if(erros_sintaxe == 0) { tmp = createNode("Add", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr_Aux MINUS Expr_Aux                                     {if(erros_sintaxe == 0) { tmp = createNode("Sub", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr_Aux STAR Expr_Aux                                      {if(erros_sintaxe == 0) { tmp = createNode("Mul", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr_Aux DIV Expr_Aux                                       {if(erros_sintaxe == 0) { tmp = createNode("Div", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}                 
    |   Expr_Aux MOD Expr_Aux                                       {if(erros_sintaxe == 0) { tmp = createNode("Mod", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr_Aux AND Expr_Aux                                       {if(erros_sintaxe == 0) { tmp = createNode("And", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr_Aux OR Expr_Aux                                        {if(erros_sintaxe == 0) { tmp = createNode("Or", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr_Aux XOR Expr_Aux                                       {if(erros_sintaxe == 0) { tmp = createNode("Xor", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr_Aux LSHIFT Expr_Aux                                    {if(erros_sintaxe == 0) { tmp = createNode("Lshift", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr_Aux RSHIFT Expr_Aux                                    {if(erros_sintaxe == 0) { tmp = createNode("Rshift", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr_Aux EQ Expr_Aux                                        {if(erros_sintaxe == 0) { tmp = createNode("Eq", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr_Aux GE Expr_Aux                                        {if(erros_sintaxe == 0) { tmp = createNode("Ge", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr_Aux GT Expr_Aux                                        {if(erros_sintaxe == 0) { tmp = createNode("Gt", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr_Aux LE Expr_Aux                                        {if(erros_sintaxe == 0) { tmp = createNode("Le", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr_Aux LT Expr_Aux                                        {if(erros_sintaxe == 0) { tmp = createNode("Lt", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   Expr_Aux NE Expr_Aux                                        {if(erros_sintaxe == 0) { tmp = createNode("Ne", "NULL"); appendChild($1, tmp); appendBrother($3, $1); $$ = tmp;}}
    |   MINUS Expr_Aux %prec preced                                 {if(erros_sintaxe == 0) { tmp = createNode("Minus", "NULL"); appendChild($2, tmp); $$ = tmp;}}
    |   NOT Expr_Aux %prec preced                                   {if(erros_sintaxe == 0) { tmp = createNode("Not", "NULL"); appendChild($2, tmp); $$ = tmp;}}                                
    |   PLUS Expr_Aux %prec preced                                  {if(erros_sintaxe == 0) { tmp = createNode("Plus", "NULL"); appendChild($2, tmp); $$ = tmp;}}
    |   LPAR Expr RPAR                                              {if(erros_sintaxe == 0) {$$ = $2;}}
    |   MethodInvocation                                            {if(erros_sintaxe == 0) {$$ = $1;}}
    |   ParseArgs                                                   {if(erros_sintaxe == 0) {$$ = $1;}}
    |   ID                                                          {if(erros_sintaxe == 0) {tmp = createNode("Id",$1); $$ = tmp;}}
    |   ID DOTLENGTH                                                {if(erros_sintaxe == 0) {tmp = createNode("Length","NULL"); appendChild(createNode("Id",$1),tmp); $$ = tmp;}}
    |   INTLIT                                                      {if(erros_sintaxe == 0) {tmp = createNode("DecLit",$1); $$ = tmp;}}
    |   REALLIT                                                     {if(erros_sintaxe == 0) {tmp = createNode("RealLit",$1); $$ = tmp;}}
    |   BOOLLIT                                                     {if(erros_sintaxe == 0) {tmp = createNode("BoolLit",$1); $$ = tmp;}}
    |   LPAR error RPAR                                             {if(erros_sintaxe == 0) {$$ = NULL;}}
    ;

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
