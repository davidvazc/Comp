#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ast_node{
    int line_y;
    int col_y;
    char *type;
    char* value;
    char *annotation;
    struct ast_node* brother;
    struct ast_node* child;
}ASTtree;

ASTtree* createNode(int, int, char* key, char* value);
int check_nr_nodes(ASTtree* node);
void appendChild(ASTtree* child, ASTtree* node);
void appendBrother(ASTtree* brother, ASTtree* node);
ASTtree* createNode_Type(int,int,ASTtree* vartype, ASTtree* list);
void printParseTree (ASTtree* no, int n_points);
