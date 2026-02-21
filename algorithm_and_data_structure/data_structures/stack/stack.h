#ifndef STACK_H
#define STACK_H

typedef struct StkNode
{
    int data;
    struct StkNode *next;
} StkNode;

typedef struct Stack
{
    StkNode *top;
} Stack;

// Protótipos com os novos nomes
void stack_init(Stack *stack);
int stack_is_empty(Stack *stack);
void stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);
int stack_top(Stack *stack);
void stack_display(Stack *stack);

#endif