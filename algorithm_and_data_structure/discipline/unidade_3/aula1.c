#include <stdio.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

int main()
{
    Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);

    root->right->left = createNode(12);
    root->right->right = createNode(18);
}