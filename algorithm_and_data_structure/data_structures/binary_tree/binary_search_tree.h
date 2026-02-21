#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

enum method
{
    RECURR,
    ITER,
};

typedef enum method Method;

enum order
{
    PRE,
    IN,
    POS,
};

typedef enum order Order;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data);
void process(Node *node);
void preorder(Node *root);
void order(Node *root);
void posorder(Node *root);

Node *insertNode(Node *node, int key);
Node *searchNode(Node *root, int key);
Node *removeNode(Node *root, int x);
Node *getMin(Node *node);
Node *getMax(Node *node);
Node *getSucessor(Node *node);
Node *getAntecessor(Node *node);
void freeTree(Node *root);

Node *createTree(int data[], int size, Method method);

int getSize(Node *root);
int getHeight(Node *root);
float getMedian(Node *root);
Node *removeMin(Node *tree);
Node *changeKey(Node *root, int oldVal, int newVal);

int isBST(Node *node);
void insertIterative(Node **root_ptr, int data);
Node *searchNodeIterative(Node *root, int key);

void printNode(Node *node);
void traverse(Node *node, Order ord, void (*visit)(Node *node));

#endif