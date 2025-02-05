#ifndef SEMANTICS_H
#define SEMANTICS_H


// Params

typedef struct params
{
    char* type;
    char* id;
    struct params* next;
}param_h;


// Simbols

typedef struct sym_table
{
    char* id;
    char* type;
    char* flag;

    param_h* params;

    struct sym_table* next;

}sym_table_node;


// table_header

typedef struct table_h
{
    char* head;
    sym_table_node* lista_sym;
    param_h* l_params;

    struct table_h* next;

}table_header;

table_header* root_pointer;


sym_table_node* create_symbol(char*, param_h*, char*, char*);
table_header* create_table(char*, param_h*);
void add_table(table_header*, char*, param_h*);
void print_table(table_header* root);
void ast_to_sym_table(ASTtree* root, table_header*);
void add_sym_to_table(table_header*, char*, char*, param_h*, char*, int, int);
param_h* get_params(ASTtree* node);
param_h* create_param(char*, char*);
char* troca(char*);
void printlocaltable(table_header*);
void add_annotations(ASTtree*, table_header*, table_header*);
char* search_symbol_type(ASTtree*, table_header*, table_header*);
table_header* search_symbol_table(char*, table_header*, table_header*,param_h*);
char* checkCall(ASTtree*, table_header*, table_header*);
char* checkNot(ASTtree*);
char* checkEquality(ASTtree*);
char* checkRelational(ASTtree*);
char* checkLogical(ASTtree*);
char* checkMultiplicative(ASTtree*);
char* checkUnary(ASTtree*);
char* checkAdd(ASTtree*);
char* checkSub(ASTtree*);
char* checkAssign(ASTtree*);
char* checkParseArgs(ASTtree*);
void check_errors(ASTtree*, table_header*, table_header*);
void check_annotations(ASTtree*, table_header*, table_header*);
void checkCall2(ASTtree*, table_header*, table_header*);
void checkNot2(ASTtree*);
void checkEquality2(ASTtree*);
void checkRelational2(ASTtree*);
void checkLogical2(ASTtree*);
void checkMultiplicative2(ASTtree*);
void checkUnary2(ASTtree*);
void checkAdd2(ASTtree*);
void checkSub2(ASTtree*);
void checkAssign2(ASTtree*);
void checkParseArgs2(ASTtree*);
char* search_function_type(char*, table_header*, param_h*);
char* compare_params(char*, sym_table_node*, param_h*);
int n_params_on_func(table_header *);
int getCount(param_h*);
void printLista(param_h *);

#endif
