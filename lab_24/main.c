#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lexer.h"
#include "tree.h"
#include "transform.h"

int main(void)
{
    freopen("test.txt", "r", stdin);
    Token tokens[TOKEN_SIZE];
    uint32_t ind = 0;

    Token token;
    token_next(&token);

    while (token.type != FINAL) {
        tokens[ind++] = token;
        token_next(&token);
    }

    if(ind == 0) {
        fprintf(stderr, "Выражение не введено, преобразование невозможно\n");
        exit(ERROR_INPUT);
    }
    printf("\nВыражение в линейном представлении:\n");
    for (uint32_t i = 0; i < ind; ++i) {
        token_print(&tokens[i]);
    }


    printf("\nДерево выражения до преобразования:\n");
    Tree tree;
    tree = tree_create(&tokens[0], 0, ind - 1);
    tree_print(tree, 0);
    tree_transform(tree);
    printf("\nПреобразованное выражение в линейном представлении:\n");
    tree_infix(tree);
    printf("\nДерево выражения после преобразования\n");
    tree_print(tree, 0);
    

    tree_destroy(&tree);
    return 0;
}
