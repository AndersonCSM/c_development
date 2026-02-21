#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

void queue_init(Queue *queue)
{
    queue->front = queue->tail = NULL;
}

int queue_is_empty(Queue *queue)
{
    return queue->front == NULL;
}

void queue_enqueue(Queue *queue, const char *nome, int tempo)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    if (!newNode)
        return;

    strncpy(newNode->data.nome, nome, 100); // novo valor do nó
    newNode->data.nome[100] = '\0';
    newNode->data.resting_time = tempo;

    newNode->next = NULL; // como ele é o último da fila, ele aponta para NULL

    if (queue->tail == NULL) // fila vazia
    {
        queue->front = queue->tail = newNode; // o nó é a primeira e a última da fila
    }
    else
    {
        queue->tail->next = newNode; // o ultimo nó (tail) aponta (next) para o novo nó
        // conecta o último nó ao novo último novo
        queue->tail = newNode; // o último é atualizado com o novo nó
    }
}

Processo queue_dequeue(Queue *queue)
{
    if (queue_is_empty(queue))
    {
        Processo processo_vazio = {"", 0};
        return processo_vazio;
    }

    QNode *temp = queue->front;
    Processo proc_remove = temp->data;

    queue->front = temp->next;
    if (queue->front == NULL) // fila vazia
    {
        queue->tail = NULL;
    }
    free(temp);

    return proc_remove;
}

char *queue_front(Queue *queue)
{
    if (queue_is_empty(queue))
        return NULL;
    return queue->front->data.nome;
}

void queue_display(Queue *queue)
{
    if (queue_is_empty(queue))
    {
        printf("Fila Vazia.\n");
        return;
    }
    QNode *temp = queue->front;
    printf("Fila: ");
    while (temp)
    {
        printf("['%s' (t=%d)] ", temp->data.nome, temp->data.resting_time);
        temp = temp->next;
    }
    printf("\n");
}
