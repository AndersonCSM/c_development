#ifndef STACK_CHAR_H
#define STACK_CHAR_H

typedef struct StkNode
{
    char data;
    struct StkNode *next;
} StkNode;

typedef struct Stack
{
    StkNode *top;
} Stack;

// Protótipos com os novos nomes
void stack_init(Stack *stack);
char stack_is_empty(Stack *stack);
void stack_push(Stack *stack, char value);
char stack_pop(Stack *stack);
char stack_top(Stack *stack);
void stack_display(Stack *stack);

#endif