#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"
#include "tree.h"
#include "transform.h"

bool is_op(Tree t, char op){
    return t->node.type == OPERATOR && t->node.data.operator_name == op && t->left && t->right;
}

Tree copy(Tree t){
    Tree ct = NULL;
    if(t != NULL){
        ct = (Tree)malloc(sizeof(struct _tree_node));
        ct->node.type = t->node.type;
        ct->node.data = t->node.data;
        ct->right = copy(t->right);
        ct->left = copy(t->left);
    }
    return ct;
}

void tree_transform(Tree t){
    if(t != NULL){
        tree_transform(t->left);
        tree_transform(t->right);

        if((is_op(t, '*'))
                            && (is_op(t->left, '^') && is_op(t->right, '^'))){
            char op = t->node.data.operator_name;
            Tree a = t->left->left, b = t->left->right, c = t->right->left, d = t->right->right;
            Tree op1 = t->right;
            
            
            if( a->node.data.operator_name == c->node.data.operator_name){

                t->node.data.operator_name = '^';
                t->left = copy(a);
                op1->node.data.operator_name = '+';
                op1->right = copy(b);
                op1->left = copy(d);
            }

                
            
        }
    }
}

