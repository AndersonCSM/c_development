#include <stdio.h>
#include <stdlib.h>

#include "binary_tree/binary_search_tree.h"

int main()
{
    int list1[] = {10, 5, 3, 7, 15, 12, 18};
    //int list2[] = {2, 5, 8, 12, 15, 20};
    //int list3[] = {25, 20, 15, 10, 5};
    //int list4[] = {20, 10, 30, 5, 15, 25, 35, 12};
    //int list5[] = {10, 5, 20, 3, 7, 15, 30, 18, 25, 35};

    //int *lists[] = {list1, list2, list3, list4, list5};
    //int sizes[] = {7, 6, 5, 8, 10};

    //Node *treeList[5];

    Node *tree = createTree(list1, 7, NULL);

    Node *min = getMin(tree);
    Node *minSuc = getSucessor(min);

    printf("O menor valor da lista e: %d\n", min->data);

    if (minSuc != NULL)
    {
        printf("O sucessor do menor elemento é: %d\n", minSuc->data);
    }
    else
    {
        printf("O menor elemento nao possui um sucessor direto na sub-arvore.\n");
    }

    /*
        for (int i = 0; i < 5; i++)
        {
            treeList[i] = createTree(lists[i], sizes[i]);

            printf("=== Lista %d ===\n", i + 1);
            printf("Pre-ordem: ");
            preorder(treeList[i]);
            printf("\nEm ordem: ");
            order(treeList[i]);
            printf("\nPos-ordem: ");
            posorder(treeList[i]);
            printf("\n\n");


            freeTree(treeList[i]);
        }
    */

    freeTree(tree);

    return 0;
}
