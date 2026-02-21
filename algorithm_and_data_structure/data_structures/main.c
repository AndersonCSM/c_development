#include <stdio.h>
#include <stdlib.h>

#include "lists/circular_list.h"
#include "lists/d_linked_list.h"
#include "lists/linked_list.h"
#include "queue/queue.h"
#include "stack/stack.h"

int main()
{

    int target = 0;

    switch (target)
    {
    case 0: // Teste para CircularList
    {
        printf("--- Testando Lista Circular ---\n");
        CNode *listaCircular = NULL;
        clist_insert_init(&listaCircular, 30);
        clist_insert_init(&listaCircular, 20);
        clist_insert_end(&listaCircular, 40);

        printf("Lista Original: ");
        clist_exibir(&listaCircular);

        clist_get(&listaCircular, 20);
        clist_get(&listaCircular, 50);

        printf("Removendo o no 20...\n");
        clist_pop_node(&listaCircular, 20);
        clist_exibir(&listaCircular);
        break;
    }
    case 1: // Teste para DLinkedList
    {
        printf("--- Testando Lista Duplamente Encadeada ---\n");
        Dnode *listaDuplamenteEncadeada = NULL;
        dlist_insert_init(&listaDuplamenteEncadeada, 30);
        dlist_insert_init(&listaDuplamenteEncadeada, 20);
        dlist_insert_end(&listaDuplamenteEncadeada, 40);

        printf("Lista Original: ");
        dlist_exibir(&listaDuplamenteEncadeada);

        dlist_get(&listaDuplamenteEncadeada, 30);
        dlist_get(&listaDuplamenteEncadeada, 99);

        printf("Removendo o no 30...\n");
        dlist_remove_dnode(&listaDuplamenteEncadeada, 30);
        dlist_exibir(&listaDuplamenteEncadeada);
        break;
    }
    case 2: // Teste para LinkedList
    {
        printf("--- Testando Lista Simplesmente Encadeada ---\n");
        SNode *lista = NULL;
        slist_insert_init(&lista, 30);
        slist_insert_init(&lista, 20);
        slist_insert_end(&lista, 40);

        printf("Lista Original: ");
        slist_exibir(&lista);

        slist_get(&lista, 40);
        slist_get(&lista, 15);

        printf("Removendo o no 40...\n");
        slist_pop_node(&lista, 40);
        slist_exibir(&lista);
        break;
    }
    case 3: // Teste para Queue
    {
        printf("--- Testando Fila ---\n");
        Queue queue;
        queue_init(&queue);

        queue_enqueue(&queue, 10);
        queue_enqueue(&queue, 20);
        queue_enqueue(&queue, 30);
        queue_display(&queue);

        printf("Elemento na frente: %d\n", queue_front(&queue));
        printf("Desenfileirando: %d\n", queue_dequeue(&queue));
        queue_display(&queue);
        break;
    }
    case 4: // Teste para Stack
    {
        printf("--- Testando Pilha ---\n");
        Stack stack;
        stack_init(&stack);

        stack_push(&stack, 10);
        stack_push(&stack, 20);
        stack_push(&stack, 30);
        stack_display(&stack);

        printf("Desempilhando: %d\n", stack_pop(&stack));
        stack_display(&stack);

        printf("Adicionando 40...\n");
        stack_push(&stack, 40);
        stack_display(&stack);

        printf("Elemento no topo: %d\n", stack_top(&stack));
        printf("Desempilhando: %d\n", stack_pop(&stack));
        stack_display(&stack);
        break;
    }
    default:
        printf("Opcao invalida! Mude a variavel 'target' no codigo.\n");
    }

    return 0;
}
