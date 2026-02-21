#include <stdio.h>
#include <stdlib.h>

#include "binary_tree/binary_search_tree.h"

int main()
{
    int list1[] = {10, 5, 3, 7, 15, 12, 18};

    Node *tree = createTree(list1, 7, NULL);

    printf("Arvore original: ");
    order(tree);

    printf("\nAlterando a chave 15 para 17\n");
    tree = changeKey(tree, 15, 17);

    printf("\nArvore modificada (em ordem): ");
    order(tree);

    freeTree(tree);

    return 0;
}

