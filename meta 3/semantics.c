#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arvore.h"
#include "semantics.h"


sym_table_node* create_symbol(char* id, param_h* paramtype, char* type, char* flag)
{
    sym_table_node* new_symb = (sym_table_node*)malloc(sizeof(sym_table_node));

    new_symb->id = (char*)malloc(strlen(id) * sizeof(char) + 1);
    new_symb->type = (char*)malloc(strlen(type) * sizeof(char));
    new_symb->flag = (char*)malloc(strlen(flag) * sizeof(char));

    strcpy(new_symb->id, id);
    strcpy(new_symb->type, type);
    strcpy(new_symb->flag, flag);

    new_symb->params = paramtype;
    new_symb->next = NULL;

    return new_symb;

}

table_header* create_table(char* name, param_h* paramtype)
{

    table_header* new_table = (table_header*)malloc(sizeof(table_header));
    new_table->head = (char*)malloc(strlen(name) * sizeof(char) + 1);
    strcpy(new_table->head, name);
    new_table->l_params = paramtype;
    new_table->lista_sym = NULL;
    new_table->next = NULL;

    return new_table;
}

void add_table(table_header* root, char* name, param_h* paramtype_aux)
{
    table_header* aux_table = root;

    while (aux_table->next != NULL)
    {
        aux_table = aux_table->next;
    }
    //printf("-->>> %s\n",paramtype_aux->id);
    aux_table->next = create_table(name, paramtype_aux);
}

void add_sym_to_table(table_header* root, char* id, char* type, param_h* paramtype, char* flag, int n_table, int f)
{
    table_header* root_aux = root;
    sym_table_node* aux;
    param_h* params_aux;
    if (n_table == 1)
    {
        if (root_aux != NULL)
        {
            aux = root_aux->lista_sym;
            if (aux == NULL)
            {
                if (paramtype == NULL && f == 0)
                {
                    params_aux = create_param("", "");
                    root_aux->lista_sym = create_symbol(id, params_aux, type, flag);
                }
                else
                {
                    root_aux->lista_sym = create_symbol(id, paramtype, type, flag);
                }
            }
            else
            {
                while (aux->next != NULL)
                    aux = aux->next;

                if (paramtype == NULL && f == 0)
                {
                    params_aux = create_param("", "");
                    aux->next = create_symbol(id, params_aux, type, flag);
                }
                else
                {
                    aux->next = create_symbol(id, paramtype, type, flag);
                }
            }
        }
    }
    else
    {
        while (root_aux->next)
            root_aux = root_aux->next;
        aux = root_aux->lista_sym;
        if (aux == NULL)
        {
            root_aux->lista_sym = create_symbol(id, paramtype, type, flag);
            //root_aux->l_params = paramtype;
        }
        else
        {
            while (aux->next != NULL)
                aux = aux->next;
            aux->next = create_symbol(id, paramtype, type, flag);

        }

    }
}


/*Escrever o tipo correto na arvore anotada*/
char* troca(char* tipo) {
    if (strcmp(tipo, "Int") == 0) {
        return ("int");
    }
    if (strcmp(tipo, "StringArray") == 0) {
        return ("String[]");
    }
    if (strcmp(tipo, "Bool") == 0) {
        return ("boolean");
    }
    if (strcmp(tipo, "Double") == 0) {
        return ("double");
    }
    if (strcmp(tipo, "Void") == 0) {
        return ("void");
    }
    //adicionar os outros tipos
    return tipo;
}



/*Pesquisar um simbolo na tabela local e de seguida na gloval*/
char* search_symbol_type(ASTtree* node, table_header* table, table_header* root) {
    int i, j;
    char resp[40] = "(";
    char right[] = ")";
    char* aux;
    sym_table_node* local_table;
    //printlocaltable(table);
    local_table = table->lista_sym;

    while (local_table != NULL) {
        /*
        printf("TABELA Type: %sId: %s\n",local_table->type,local_table->id);
        printf("NODE Type: %sID: %s\n",node->type,node->value);*/
        if (strcmp(local_table->id, node->value) == 0) {
            if (table == root) {
                strcat(resp, troca(local_table->type));
                strcat(resp, right);
                aux = strdup(resp);
                return (aux);
            }
            return troca(local_table->type);
        }
        local_table = local_table->next;
    }
    if (table != root) {
        return strdup(search_symbol_type(node, root, root));
    }
    return strdup("undef");
}


/*Pesquisar o nome de uma tabela para ver se e funcao*/
table_header* search_symbol_table(char* id, table_header* table, table_header* root) {
    //printlocaltable(table);

    while (table != NULL) {
        /*
        printf("TABELA Type: %sId: %s\n",local_table->type,local_table->id);
        printf("NODE Type: %sID: %s\n",node->type,node->value);*/
        if (strcmp(table->head, id) == 0) {
            return table;
        }
        table = table->next;
    }
    return NULL;
}

void check_errors(ASTtree *bro_aux, table_header *table, table_header *root)
{
    char *aux;
    if (bro_aux != NULL){
        if (strcmp(bro_aux->type, "VarDecl") == 0){
            check_errors(bro_aux->brother, table, root);
        }

        else if (strcmp(bro_aux->type, "Call") == 0)
        {
            check_errors(bro_aux->brother, table, root);
            checkCall2(bro_aux, table, root);
        }

        else if (strcmp(bro_aux->type, "Not") == 0)
        {
            check_errors(bro_aux->brother, table, root);
            checkNot2(bro_aux); //retorna tipo do filho
        }

        else if (strcmp(bro_aux->type, "Eq") == 0 || strcmp(bro_aux->type, "Ne") == 0)
        {
            check_errors(bro_aux->brother, table, root);
            checkEquality2(bro_aux); //retorna boolean
        }
        else if (strcmp(bro_aux->type, "Lt") == 0 || strcmp(bro_aux->type, "Gt") == 0 || strcmp(bro_aux->type, "Le") == 0 || strcmp(bro_aux->type, "Ge") == 0)
        {
            check_errors(bro_aux->brother, table, root);
            checkRelational2(bro_aux); //retorna boolean
        }
        else if (strcmp(bro_aux->type, "Or") == 0 || strcmp(bro_aux->type, "And") == 0 || strcmp(bro_aux->type, "Xor") == 0)
        {
            check_errors(bro_aux->brother, table, root);
            checkLogical2(bro_aux); //retorna boolean
        }
        else if (strcmp(bro_aux->type, "Mul") == 0 || strcmp(bro_aux->type, "Div") == 0 || strcmp(bro_aux->type, "Mod") == 0)
        {
            check_errors(bro_aux->brother, table, root);
            checkMultiplicative2(bro_aux); //retorna o tipo da expressao a ser multiplicada
        }

        else if (strcmp(bro_aux->type, "Plus") == 0 || strcmp(bro_aux->type, "Minus") == 0)
        {
            check_errors(bro_aux->brother, table, root);
            checkUnary2(bro_aux); //retorna o tipo da expressao a ser convertida
        }
        else if (strcmp(bro_aux->type, "Add") == 0)
        {
            check_errors(bro_aux->brother, table, root);
            checkAdd2(bro_aux); //retorna o tipo da expressao a ser adicionada
        }
        else if (strcmp(bro_aux->type, "Sub") == 0)
        {
            check_errors(bro_aux->brother, table, root);
            checkSub2(bro_aux); //retorna o tipo da expressao a ser subtraida
        }
        else if (strcmp(bro_aux->type, "Assign") == 0)
        {
            check_errors(bro_aux->brother, table, root);
            checkAssign2(bro_aux); //retorna o tipo da expressao a ser atribuida
        }
        else if (strcmp(bro_aux->type, "ParseArgs") == 0)
        {
            check_errors(bro_aux->brother, table, root);
            checkParseArgs2(bro_aux); //retorna int
        }
        /* FUNCOES DE ERRO
        else if (strcmp(bro_aux->type, "If") == 0) {
            add_annotations(bro_aux->children, table);
            checkIf(bro_aux);

        }
        else if (strcmp(bro_aux->type, "Return") == 0) {
            add_annotations(bro_aux->children, table);
            checkReturn(bro_aux, table);

        }
        NOS PRECISAMOS DE IMPLEMENTAR
        else if (strcmp(bro_aux->type, "While") == 0) {
            add_annotations(bro_aux->children, table);
            checkWhile(bro_aux);

        }
        else if (strcmp(bro_aux->type, "Lshift") == 0 || strcmp(bro_aux->type, "Rshift") == 0) {
            add_annotations(bro_aux->children, table);
            checkShift(bro_aux);

        }
        else if (strcmp(bro_aux->type, "Length") == 0) {
            add_annotations(bro_aux->children, table);
            checkLength(bro_aux);

        }
        Assign(2) Or(2) And(2) Eq(2) Ne(2) Lt(2) Gt(2) Le(2) Ge(2) Add(2)
Sub(2) Mul(2) Div(2) Mod(2) Lshift(2) Rshift(2) Xor(2) Not(1) Minus(1)
Plus(1) Length(1) Call(>=1) ParseArgs(2)
*/
        else
        {
            check_errors(bro_aux->child, table, root);
        }
        check_errors(bro_aux->brother, table, root);
    }
}

/*Escrever as anotaçoes na arvore*/
void add_annotations(ASTtree* bro_aux, table_header* table, table_header* root) {
    char* aux;
    if (bro_aux != NULL)
    {
        //printf("Type: %s\nId: %s\n",bro_aux->type,bro_aux->value);
        if (strcmp(bro_aux->type, "DecLit") == 0) {
            bro_aux->annotation = strdup("int");

        }
        else if (strcmp(bro_aux->type, "RealLit") == 0) {
            bro_aux->annotation = strdup("double");

        }
        else if (strcmp(bro_aux->type, "BoolLit") == 0) {
            bro_aux->annotation = strdup("boolean");

        }
        else if (strcmp(bro_aux->type, "Id") == 0) {
            aux = search_symbol_type(bro_aux, table, root);
            bro_aux->annotation = strdup(aux);

        }
        else if (strcmp(bro_aux->type, "VarDecl") == 0) {
            add_annotations(bro_aux->brother, table, root);

        }

        else if (strcmp(bro_aux->type, "Call") == 0) {
            add_annotations(bro_aux->child, table, root);
            bro_aux->annotation = checkCall(bro_aux, table, root); //retorna tipo da funcao

        }

        else if (strcmp(bro_aux->type, "Not") == 0) {
            add_annotations(bro_aux->child, table, root);
            bro_aux->annotation = checkNot(bro_aux); //retorna tipo do filho

        }

        else if (strcmp(bro_aux->type, "Eq") == 0 || strcmp(bro_aux->type, "Ne") == 0) {
            add_annotations(bro_aux->child, table, root);
            bro_aux->annotation = checkEquality(bro_aux);  //retorna boolean

        }
        else if (strcmp(bro_aux->type, "Lt") == 0 || strcmp(bro_aux->type, "Gt") == 0 || strcmp(bro_aux->type, "Le") == 0 || strcmp(bro_aux->type, "Ge") == 0) {
            add_annotations(bro_aux->child, table, root);
            bro_aux->annotation = checkRelational(bro_aux); //retorna boolean

        }
        else if (strcmp(bro_aux->type, "Or") == 0 || strcmp(bro_aux->type, "And") == 0 || strcmp(bro_aux->type, "Xor") == 0) {
            add_annotations(bro_aux->child, table, root);
            bro_aux->annotation = checkLogical(bro_aux);  //retorna boolean

        }
        else if (strcmp(bro_aux->type, "Mul") == 0 || strcmp(bro_aux->type, "Div") == 0 || strcmp(bro_aux->type, "Mod") == 0) {
            add_annotations(bro_aux->child, table, root);
            bro_aux->annotation = checkMultiplicative(bro_aux); //retorna o tipo da expressao a ser multiplicada

        }

        else if (strcmp(bro_aux->type, "Plus") == 0 || strcmp(bro_aux->type, "Minus") == 0) {
            add_annotations(bro_aux->child, table, root);
            bro_aux->annotation = checkUnary(bro_aux);  //retorna o tipo da expressao a ser convertida

        }
        else if (strcmp(bro_aux->type, "Add") == 0) {
            add_annotations(bro_aux->child, table, root);
            bro_aux->annotation = checkAdd(bro_aux);  //retorna o tipo da expressao a ser adicionada

        }
        else if (strcmp(bro_aux->type, "Sub") == 0) {
            add_annotations(bro_aux->child, table, root);
            bro_aux->annotation = checkSub(bro_aux); //retorna o tipo da expressao a ser subtraida

        }
        else if (strcmp(bro_aux->type, "Assign") == 0) {
            add_annotations(bro_aux->child, table, root);
            bro_aux->annotation = checkAssign(bro_aux); //retorna o tipo da expressao a ser atribuida

        }
        else if (strcmp(bro_aux->type, "ParseArgs") == 0) {
            add_annotations(bro_aux->child, table, root);
            bro_aux->annotation = checkParseArgs(bro_aux); //retorna int

        }
        /* FUNCOES DE ERRO
        else if (strcmp(bro_aux->type, "If") == 0) {
            add_annotations(bro_aux->children, table);
            checkIf(bro_aux);

        }
        else if (strcmp(bro_aux->type, "Return") == 0) {
            add_annotations(bro_aux->children, table);
            checkReturn(bro_aux, table);

        }
        NOS PRECISAMOS DE IMPLEMENTAR
        else if (strcmp(bro_aux->type, "While") == 0) {
            add_annotations(bro_aux->children, table);
            checkWhile(bro_aux);

        }
        else if (strcmp(bro_aux->type, "Lshift") == 0 || strcmp(bro_aux->type, "Rshift") == 0) {
            add_annotations(bro_aux->children, table);
            checkShift(bro_aux);

        }
        else if (strcmp(bro_aux->type, "Length") == 0) {
            add_annotations(bro_aux->children, table);
            checkLength(bro_aux);

        }
        Assign(2) Or(2) And(2) Eq(2) Ne(2) Lt(2) Gt(2) Le(2) Ge(2) Add(2)
Sub(2) Mul(2) Div(2) Mod(2) Lshift(2) Rshift(2) Xor(2) Not(1) Minus(1)
Plus(1) Length(1) Call(>=1) ParseArgs(2)
*/
        else {
            add_annotations(bro_aux->child, table, root);

        }
        add_annotations(bro_aux->brother, table, root);
    }
}



void ast_to_sym_table(ASTtree* root, table_header* table_root)
{
    ASTtree *root_aux;
    root_aux = root->child;
    ASTtree* child_aux;
    ASTtree* bro_aux;
    table_header* table_aux = table_root;
    char head[100];
    char type[10];
    char return_id[10];
    param_h* params;
    param_h* params_aux;

    while (root_aux)
    {
        if (strcmp(root_aux->type, "NULL") != 0)
        {
            if (strcmp(root_aux->type, "FieldDecl") == 0)
            {
                child_aux = root_aux->child;
                //printf("Type: %s\nId: %s\n",child_aux->type,child_aux->brother->value);
                add_sym_to_table(table_root, child_aux->brother->value, child_aux->type, NULL, "", 1, 1);


            }
            else if (strcmp(root_aux->type, "MethodDecl") == 0)
            {
                // Actualizar tbm na tabela global
                // Header -> nome da tabelas
                // Body -> variaveis
                child_aux = root_aux->child;
                if (strcmp(child_aux->type, "MethodHeader") == 0)
                {
                    strcpy(head, child_aux->child->brother->value);
                    strcpy(type, child_aux->child->type);
                    strcpy(return_id, type);

                    child_aux = child_aux->child;
                    while (child_aux)
                    {
                        if (strcmp(child_aux->type, "MethodParams") == 0)
                            break;
                        child_aux = child_aux->brother;
                    }
                    params = get_params(child_aux);
                    add_sym_to_table(table_root, head, type, params, "", 1, 0);
                    //printf("Type: %s\nId: %s\n",type,head);
                    add_table(table_root, head, params);

                }
                bro_aux = root_aux->child->brother;
                if (strcmp(bro_aux->type, "MethodBody") == 0)
                {
                    while (table_aux->next != NULL)
                        table_aux = table_aux->next;
                    if (table_aux->l_params != NULL)
                    {
                        params_aux = table_aux->l_params;
                        add_sym_to_table(table_root, "return", return_id, NULL, "", 2, 1);
                        while (params_aux)
                        {
                            add_sym_to_table(table_root, params_aux->id, params_aux->type, NULL, "param", 2, 1);
                            //printf("Type: %s\nId: %s\n",params_aux->type,params_aux->id);
                            params_aux = params_aux->next;
                        }
                    }
                    else
                        add_sym_to_table(table_root, "return", return_id, NULL, "", 2, 1);
                    bro_aux = bro_aux->child;
                    while (bro_aux)
                    {
                        if (strcmp(bro_aux->type, "VarDecl") == 0)
                        {
                            add_sym_to_table(table_root, bro_aux->child->brother->value, bro_aux->child->type, NULL, "", 2, 1);
                            //printf("Type: %s\nId: %s\n",bro_aux->child->type,bro_aux->child->brother->value); 
                        }
                        add_annotations(bro_aux, table_aux, table_root);
                        bro_aux = bro_aux->brother;
                    }
                }
            }
        }
        root_aux = root_aux->brother;
    }
    check_errors(root, table_aux, table_root);
}

param_h* create_param(char* id, char* type)
{
    //TODO: converter as cenas do String[] e cenas para minuscula
    param_h* params = (param_h*)malloc(sizeof(param_h));
    params->id = (char*)malloc(strlen(id) * sizeof(char) + 1);
    params->type = (char*)malloc(strlen(type) * sizeof(char));


    strcpy(params->id, id);
    strcpy(params->type, type);
    params->next = NULL;

    return params;

}

param_h* get_params(ASTtree* node)
{
    param_h* param = NULL;
    param_h* aux;
    if (node->child == NULL)
        return NULL;
    ASTtree* aux_node = node->child;

    param = create_param(aux_node->child->brother->value, aux_node->child->type);
    aux = param;
    aux_node = aux_node->brother;
    if (aux_node == NULL)
        return param;
    else
    {
        while (aux_node)
        {
            aux->next = create_param(aux_node->child->brother->value, aux_node->child->type);
            aux_node = aux_node->brother;
            aux = aux->next;

        }
    }
    return param;
}



//========================== FUNCOES PRINT =================================================


void printlocaltable(table_header* root) {
    table_header* root_aux = root;
    sym_table_node* sym_aux;
    param_h* paramtype;
    int aux = 0;
    int i = 0;
    printf("===== ");
    if (i == 0)
        printf("Class ");
    else
        printf("Method ");
    printf("%s", root_aux->head);
    paramtype = root_aux->l_params;
    if (paramtype != NULL)
    {
        printf("(");
        while (paramtype)
        {
            if (paramtype->next != NULL)
            {
                if (strcmp(paramtype->type, "StringArray") == 0)
                    printf("String[]");
                else if (strcmp(paramtype->type, "Bool") == 0)
                    printf("boolean");
                else
                {
                    printf("%s", troca(paramtype->type));

                }
                printf(",");

            }
            else
            {
                if (strcmp(paramtype->type, "StringArray") == 0)
                    printf("String[]");
                else if (strcmp(paramtype->type, "Bool") == 0)
                    printf("boolean");
                else
                {
                    printf("%s", troca(paramtype->type));

                }
                printf(")");
            }

            paramtype = paramtype->next;
        }

    }
    else
    {
        if (i != 0)
            printf("()");
    }
    printf(" Symbol Table =====\n");


    sym_aux = root_aux->lista_sym;
    while (sym_aux)
    {
        printf("%s\t", sym_aux->id);
        paramtype = sym_aux->params;
        while (paramtype)
        {
            if (aux == 1)
            {
                printf(",");
            }
            if (aux == 0)
            {
                printf("(");
                aux = 1;
            }
            if (strcmp(paramtype->type, "StringArray") == 0)
                printf("String[]");
            else if (strcmp(paramtype->type, "Bool") == 0)
                printf("boolean");
            else
                printf("%s", troca(paramtype->type));

            paramtype = paramtype->next;
        }
        if (aux != 0)
        {
            printf(")");
            aux = 0;
        }
        if (strcmp(sym_aux->type, "Bool") == 0)
            printf("\tboolean");
        else if (strcmp(sym_aux->type, "StringArray") == 0)
            printf("\tString[]");
        else
            printf("\t%s", troca(sym_aux->type));

        if (strcmp(sym_aux->flag, "") != 0)
        {
            printf("\t%s", sym_aux->flag);
        }
        sym_aux = sym_aux->next;
        printf("\n");
    }
}


void print_table(table_header* root)
{
    table_header* root_aux = root;
    sym_table_node* sym_aux;
    param_h* paramtype;
    int aux = 0;
    int i = 0;


    while (root_aux)
    {

        printf("===== ");
        if (i == 0)
            printf("Class ");
        else
            printf("Method ");
        printf("%s", root_aux->head);
        paramtype = root_aux->l_params;
        if (paramtype != NULL)
        {
            printf("(");
            while (paramtype)
            {
                if (paramtype->next != NULL)
                {
                    printf("%s", troca(paramtype->type));
                    printf(",");

                }
                else
                {

                    printf("%s", troca(paramtype->type));
                    printf(")");
                }

                paramtype = paramtype->next;
            }

        }
        else
        {
            if (i != 0)
                printf("()");
        }
        printf(" Symbol Table =====\n");


        sym_aux = root_aux->lista_sym;
        while (sym_aux)
        {
            printf("%s\t", sym_aux->id);
            paramtype = sym_aux->params;
            while (paramtype)
            {
                if (aux == 1)
                {
                    printf(",");
                }
                if (aux == 0)
                {
                    printf("(");
                    aux = 1;
                }
                printf("%s", troca(paramtype->type));

                paramtype = paramtype->next;
            }
            if (aux != 0)
            {
                printf(")");
                aux = 0;
            }
            printf("\t%s", troca(sym_aux->type));

            if (strcmp(sym_aux->flag, "") != 0)
            {
                printf("\t%s", sym_aux->flag);
            }
            sym_aux = sym_aux->next;
            printf("\n");
        }
        printf("\n");

        root_aux = root_aux->next;
        i++;
    }
}





//======================FUNCOES CHECK ANOTACOES=================================================


char* checkCall(ASTtree* node, table_header* table, table_header* root) {
    ASTtree* id_call = node->child;
    char* return_type;
    int func_params, node_params = 0, error = 0;
    ASTtree* params;
    sym_table_node* simbolos;

    table = search_symbol_table(id_call->value, root, root);

    if (table != NULL) {

        simbolos = table->lista_sym;
        node = id_call->brother; /* NODE APONTA PARA O 1º PARAMETRO */
        return_type = simbolos->type; /* TIPO DO RETURN DA FUNÇÃO */
        simbolos = simbolos->next; /* TABLE APONTA PARA DEPOIS DE RETURN */
        params = node;
        while (params != NULL) {
            node_params++;
            params = params->brother;
        }
    }
    //FALTA VERIFICAR ERROS

    if (error == 0) {
        return troca(strdup(return_type));
    }

    return strdup("undef");
}






char* checkNot(ASTtree* node) {

    char type[1024];

    strcpy(type, (node->child)->annotation);

    if (strcmp(type, "int") == 0 || strcmp(type, "double") == 0 || strcmp(type, "boolean") == 0) {
        return troca(strdup(type));
    }
    else {
        
        return strdup("undef");
    }
}






char* checkEquality(ASTtree* node) {

        return strdup("boolean");
    

}





char* checkRelational(ASTtree* node) {

        return strdup("boolean");
    
}



char* checkLogical(ASTtree* node) {

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);

    return strdup("boolean");
}




char* checkMultiplicative(ASTtree* node) {

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);

    return troca(strdup(first_annotation));
}




char* checkUnary(ASTtree* node) {
    char first_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);

    return troca(strdup(first_annotation));
}




char* checkAdd(ASTtree* node) {

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);

    return troca(strdup(first_annotation));
}



char* checkSub(ASTtree* node) {

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);

    return troca(strdup(first_annotation));
}


char* checkAssign(ASTtree* node) {

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);

    return troca(strdup(first_annotation));
}



char* checkParseArgs(ASTtree* node) {


    return strdup("int");
}

//======================FUNCOES CHECK ERROS=================================================

void checkCall2(ASTtree *node, table_header *table, table_header *root)
{
    ASTtree *id_call = node->child;
    char *return_type;
    int func_params, node_params = 0, error = 0;
    ASTtree *params;
    sym_table_node *simbolos;

    table = search_symbol_table(id_call->value, root, root);

    if (table != NULL)
    {

        simbolos = table->lista_sym;
        node = id_call->brother;      /* NODE APONTA PARA O 1º PARAMETRO */
        return_type = simbolos->type; /* TIPO DO RETURN DA FUNÇÃO */
        simbolos = simbolos->next;    /* TABLE APONTA PARA DEPOIS DE RETURN */
        params = node;
        while (params != NULL)
        {
            node_params++;
            params = params->brother;
        }
    }
    //FALTA VERIFICAR ERROS

   
}

void checkNot2(ASTtree *node)
{

    char type[1024];

    strcpy(type, (node->child)->annotation);

    if (strcmp(type, "int") == 0 || strcmp(type, "double") == 0 || strcmp(type, "boolean") == 0)
    {
        return;
    }
    else
    {
        printf("Line %d, col %d: Operator ! cannot be applied to type %s\n", node->line_y, node->col_y, (node->child)->annotation);
        
    }
}

void checkEquality2(ASTtree *node)
{

    /* NOTE: The rules are slightly different from those of the relational operators */

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);
    //FALTA VERIFICAR ERROS

    /* checks if the first operand has integral type */
    if (strcmp(first_annotation, "int") == 0 || strcmp(first_annotation, "double") == 0 || strcmp(first_annotation, "boolean") == 0)
    {

        /* checks if the second operand also has integral type */
        if (strcmp(second_annotation, "int") == 0 || strcmp(second_annotation, "double") == 0 || strcmp(second_annotation, "boolean") == 0)
        {

            /* checks if the operands are of the same type */
            if (strcmp(first_annotation, second_annotation) == 0)
            {
                is_valid = 1;
            }
        }
    }

    //Se for valido imprime o tipo
    if (is_valid)
    {

        return ;
    }

    //Caso contrario, imprime mensagem de erro e retorna o tipo
    else
    {

        if (strcmp(node->type, "Eq") == 0)
        {
            printf("Line %d, col %d: Operator == cannot be applied to types %s, %s\n", node->line_y, node->col_y, first_annotation, second_annotation);
        }
        else
        {
            printf("Line %d, col %d: Operator != cannot be applied to types %s, %s\n", node->line_y, node->col_y, first_annotation, second_annotation);
        }

        
    }
}

void checkRelational2(ASTtree *node)
{

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);
    //FALTA VERIFICAR ERROS

    /* checks if the first operand has integral type */
    if (strcmp(first_annotation, "int") == 0 || strcmp(first_annotation, "double") == 0)
    {

        /* checks if the second operand also has integral type */
        if (strcmp(second_annotation, "int") == 0 || strcmp(second_annotation, "double") == 0)
        {
            is_valid = 1;
        }
    }

    if (is_valid)
    {

        return ;
    }

    else
    {
        /* otherwise the operator cannot be applied to the operands */
        if (strcmp(node->type, "Lt") == 0)
        {
            printf("Line %d, col %d: Operator < cannot be applied to types %s, %s\n", node->line_y, node->col_y, first_annotation, second_annotation);
        }
        else if (strcmp(node->type, "Gt") == 0)
        {
            printf("Line %d, col %d: Operator > cannot be applied to types %s, %s\n", node->line_y, node->col_y, first_annotation, second_annotation);
        }
        else if (strcmp(node->type, "Le") == 0)
        {
            printf("Line %d, col %d: Operator <= cannot be applied to types %s, %s\n", node->line_y, node->col_y, first_annotation, second_annotation);
        }
        else if (strcmp(node->type, "Ge") == 0)
        {
            printf("Line %d, col %d: Operator >= cannot be applied to types %s, %s\n", node->line_y, node->col_y, first_annotation, second_annotation);
        }

        
    }
}

void checkLogical2(ASTtree *node)
{

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);

    
}

void checkMultiplicative2(ASTtree *node)
{

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);

    
}

void checkUnary2(ASTtree *node)
{
    char first_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);

    
}

void checkAdd2(ASTtree *node)
{

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);

    
}

void checkSub2(ASTtree *node)
{

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);

   
}

void checkAssign2(ASTtree *node)
{

    int is_valid = 0;

    char first_annotation[1024];
    char second_annotation[1024];

    strcpy(first_annotation, (node->child)->annotation);
    strcpy(second_annotation, ((node->child)->brother)->annotation);

    
}

void checkParseArgs2(ASTtree *node)
{

    return ;
}