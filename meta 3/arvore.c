#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arvore.h"

int n_points;

ASTtree* createNode(char* type, char* value) {
	ASTtree* node = malloc(sizeof(struct ast_node));

	node->type = type;
    node->value = value;

	node->annotation = NULL;

	node->child = NULL;
    node->brother = NULL;

	return node;
}

int check_nr_nodes(ASTtree* node){
	int i = 0;

	while(node!=NULL){
		if (strcmp(node->type, "Empty") != 0)
			i++;
		node = node->brother;
	}
	return i;
}

void appendChild(ASTtree* child, ASTtree* node) {
	if (node != NULL) {
		if(node->child == NULL){
			node->child = child;
		}
	}
}

void appendBrother(ASTtree* brother, ASTtree* node) {
	if (node != NULL) {
		while(node->brother != NULL){
			node = node->brother;
		}
		node->brother = brother;
	}
}

ASTtree* createNode_Type(ASTtree* vartype, ASTtree* list){
    ASTtree* aux = list;
    ASTtree* new_node = NULL;
    int i = 0;

    while (aux != NULL){
        if (i == 1){
            new_node = createNode(vartype->type, "NULL");
            new_node->brother = aux->child;
            aux->child = new_node;
        }else {
            i++;
        }
        aux = aux->brother;
    }
    return list;
}

void printParseTree (ASTtree * no, int n_points) {
	int i;
	if(no == NULL){	
		return;
	}
	if(no->annotation != NULL){
		if (no->value != NULL && strcmp(no->type, "Deref") != 0)
			printf("%s(%s) - %s\n", no->type, no->value, no->annotation);
		else
			printf("%s - %s\n", no->type, no->annotation);
	} else{
		if(strcmp(no->value,"NULL") != 0 ){
			for(i=0; i< n_points; i++)
				printf(".");
			printf("%s(%s)\n", no->type, no->value);
		}
		else{
		    if (strcmp(no->type,"NULL") == 0 || strcmp(no->type,"Empty") == 0);
		    else{
			    for(i=0; i< n_points; i++)
					printf(".");	
		      	printf("%s\n", no->type);
		    }
   		}
	}

	printParseTree(no->child, n_points+2);
	printParseTree(no->brother, n_points);
}