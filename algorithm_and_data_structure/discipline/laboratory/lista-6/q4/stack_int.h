#ifndef STACK_INT_H
#define STACK_INT_H

// Renomeado para evitar conflito
typedef struct IntNode
{
    int data;
    struct IntNode *next;
} IntNode;

// Renomeado para evitar conflito
typedef struct IntStack
{
    IntNode *top;
} IntStack;

// Protótipos renomeados
void int_stack_init(IntStack *stack);
int int_stack_is_empty(IntStack *stack);
void int_stack_push(IntStack *stack, int value);
int int_stack_pop(IntStack *stack);
int int_stack_top(IntStack *stack);

#endif