#include <stdio.h>
#include <stdlib.h>

#include "binary_tree/binary_search_tree.h"

int main()
{
    int list1[] = {10, 5, 3, 7, 15, 12, 18};

    Node *tree = createTree(list1, 7, ITER);

    Node *node = searchNodeIterative(tree, 12);

    printNode(node);

    freeTree(tree);

    return 0;
}
