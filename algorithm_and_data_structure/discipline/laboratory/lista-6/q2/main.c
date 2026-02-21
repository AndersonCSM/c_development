#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

char *reverse(const char *expr)
{

    Stack pilha;
    stack_init(&pilha);
    int size = strlen(expr); // nao conta o \0

    char *word = (char *)malloc(size + 1); // +1 de \0
    if (!word)
    {
        return NULL; // Falha na alocação de memória
    }

    for (int i = 0; i < size; i++)
    {
        stack_push(&pilha, expr[i]);
    }

    int i = 0;
    while (!stack_is_empty(&pilha))
    {
        word[i] = stack_pop(&pilha);
        i++;
    }

    word[i] = '\0';

    return word;
}

int main()
{
    const char *teste1 = "Ao contrario";
    char *saida1 = reverse(teste1);

    printf("Entrada: %s\n", teste1);
    printf("Saida: %s\n", saida1);

    free(saida1);
    return 0;
}
