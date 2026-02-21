#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void stack_init(Stack *stack)
{
    stack->top = NULL;
}

int stack_is_empty(Stack *stack)
{
    return stack->top == NULL;
}

void stack_push(Stack *stack, int value)
{
    StkNode *newNode = (StkNode *)malloc(sizeof(StkNode));
    if (!newNode)
        return;

    newNode->data = value;
    newNode->next = stack->top; // novo nó aponta para o antigo nó que era o topo da pilha
    stack->top = newNode; // atualiza o topo da pilha para o novo nó
}

int stack_pop(Stack *stack)
{
    if (stack_is_empty(stack))
        return -1;

    StkNode *temp = stack->top; // nó do topo
    int poppedValue = temp->data; // valor que será removido
    stack->top = temp->next; // move o próximo para o topo
    free(temp); // liberar o nó da pilha 
    return poppedValue;
}

int stack_top(Stack *stack)
{
    if (stack_is_empty(stack))
        return -1;
    return stack->top->data;
}

void stack_display(Stack *stack)
{
    if (stack_is_empty(stack))
    {
        printf("Pilha vazia.\n");
        return;
    }
    StkNode *temp = stack->top;
    printf("Pilha: ");
    while (temp) // enqunato temp não for nulo
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
