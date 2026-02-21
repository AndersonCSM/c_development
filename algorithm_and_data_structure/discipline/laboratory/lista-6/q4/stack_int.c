#include <stdio.h>
#include <stdlib.h>

#include "stack_int.h"

void int_stack_init(IntStack *stack)
{
    stack->top = NULL;
}

int int_stack_is_empty(IntStack *stack)
{
    return stack->top == NULL;
}

void int_stack_push(IntStack *stack, int value)
{
    IntNode *newNode = (IntNode *)malloc(sizeof(IntNode));
    if (!newNode)
        return;

    newNode->data = value;
    newNode->next = stack->top; // novo nó aponta para o antigo nó que era o topo da pilha
    stack->top = newNode;       // atualiza o topo da pilha para o novo nó
}

int int_stack_pop(IntStack *stack)
{
    if (int_stack_is_empty(stack))
        return -1;

    IntNode *temp = stack->top;   // nó do topo
    int poppedValue = temp->data; // valor que será removido
    stack->top = temp->next;      // move o próximo para o topo
    free(temp);                   // liberar o nó da pilha
    return poppedValue;
}

int int_stack_top(IntStack *stack)
{
    if (int_stack_is_empty(stack))
        return -1;
    return stack->top->data;
}

void int_stack_display(IntStack *stack)
{
    if (int_stack_is_empty(stack))
    {
        printf("Pilha vazia.\n");
        return;
    }
    IntNode *temp = stack->top;
    printf("Pilha: ");
    while (temp) // enqunato temp não for nulo
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
