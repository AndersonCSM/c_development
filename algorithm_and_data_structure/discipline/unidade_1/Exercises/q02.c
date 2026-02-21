#include <stdio.h>
#include <stdlib.h>

#include "binary_tree/binary_search_tree.h"

int main()
{
    int list1[] = {10, 5, 3, 7, 15, 12, 18};

    Node *tree = createTree(list1, 7, NULL);

    int size = getSize(tree);
    int height = getHeight(tree);
    float median = getMedian(tree);

    printf("O tamanho da arvore e: %d\n", size);
    printf("A altura da arvore e: %d\n", height);
    printf("A mediana da arvore e %f\n", median);

    freeTree(tree);

    return 0;
}
