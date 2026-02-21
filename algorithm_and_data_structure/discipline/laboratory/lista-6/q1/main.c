#include <stdio.h>
#include <string.h>

#include "stack.h"

int load_balancer(const char *expr)
{
    Stack pilha;
    stack_init(&pilha);
    int size = strlen(expr);

    for (int i = 0; i < size; i++)
    {
        char atual = expr[i];

        // Se for um símbolo de abertura, empilha
        if (atual == '(' || atual == '{' || atual == '[')
        {
            stack_push(&pilha, atual);
        }

        // Se for um símbolo de fechamento | NAO adiciona novos elementos a pilha
        else if (atual == ')' || atual == '}' || atual == ']')
        {
            // Se a pilha estiver vazia, desbalanceado e tem um simbolo de fechamento está desbalanceada
            if (stack_is_empty(&pilha))
            {
                return 0;
            }

            // Desempilha o último símbolo da pilha opcs serão: ([{
            char topo = stack_pop(&pilha);

            // Verifica se o par corresponde, ou seja, o simbolo atual (fechamento) é par do simbolo da pilha (abertura)
            if ((atual == ')' && topo != '(') || // se não for par de ()
                (atual == '}' && topo != '{') || // se não for par de {}
                (atual == ']' && topo != '['))   // se não for par de []
            {
                return 0; // Falso: pares não correspondem, desbalanceado
            }
        }
    }

    return stack_is_empty(&pilha);
}

int main()
{
    const char *teste1 = "{[()()]}";
    const char *teste2 = "{[(])}";
    const char *teste3 = "()[]{}";
    const char *teste4 = "([)]";

    printf("Entrada: %s\n", teste1);
    if (load_balancer(teste1))
    {
        printf("Entrada Balanceada\n");
        printf("\n");
    }
    else
    {
        printf("nao Balanceada\n");
        printf("\n");
    }

    printf("Entrada: %s\n", teste2);
    if (load_balancer(teste2))
    {
        printf("Entrada Balanceada\n");
        printf("\n");
    }
    else
    {
        printf("Entrada nao Balanceada\n");
        printf("\n");
    }

    printf("Entrada: %s\n", teste3);
    if (load_balancer(teste3))
    {
        printf("Entrada Balanceada\n");
        printf("\n");
    }
    else
    {
        printf("Entrada nao Balanceada\n");
        printf("\n");
    }

    printf("Entrada: %s\n", teste4);
    if (load_balancer(teste4))
    {
        printf("Entrada Balanceada\n");
        printf("\n");
    }
    else
    {
        printf("Entrada nao Balanceada\n");
        printf("\n");
    }

    return 0;
}
