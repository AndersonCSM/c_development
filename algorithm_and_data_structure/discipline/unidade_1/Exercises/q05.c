#include <stdio.h>
#include <stdlib.h>

#include "binary_tree/binary_search_tree.h"

int main()
{
    int list1[] = {5, 20, 10, 30};

    Node *tree = createTree(list1, 4, ITER);

    traverse(tree, IN, printNode);

    freeTree(tree);

    return 0;
}
