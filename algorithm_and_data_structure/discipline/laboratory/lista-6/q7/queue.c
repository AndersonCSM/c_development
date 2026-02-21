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

void queue_enqueue(Queue *queue, char *value)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    if (!newNode)
        return;

    strncpy(newNode->data, value, 100); // novo valor do nó

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

char *queue_dequeue(Queue *queue)
{
    if (queue_is_empty(queue))
        return NULL;

    // 'static' significa que esta variável não é destruída quando a função termina
    static char dequeuedValue[101];
    QNode *temp = queue->front;

    // Copia o dado do nó para o buffer ANTES de liberar o nó.
    strncpy(dequeuedValue, temp->data, 101);

    queue->front = temp->next;
    if (queue->front == NULL) // fila vazia
    {
        queue->tail = NULL;
    }
    free(temp);

    return dequeuedValue;
}

char *queue_front(Queue *queue)
{
    if (queue_is_empty(queue))
        return NULL;
    return queue->front->data;
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
        printf("'%s' ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
