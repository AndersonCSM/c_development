#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void queue_init(Queue *queue)
{
    queue->front = queue->tail = NULL;
}

int queue_is_empty(Queue *queue)
{
    return queue->front == NULL;
}

void queue_enqueue(Queue *queue, int value)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    if (!newNode)
        return;

    newNode->data = value; // novo valor do nó
    newNode->next = NULL;  // como ele é o último da fila, ele aponta para NULL

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

int queue_dequeue(Queue *queue)
{
    if (queue_is_empty(queue))
        return -1;

    QNode *temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = temp->next; // o novo primeiro da fila é o próximo de temp
    if (queue->front == NULL) // fila vazia
    {
        queue->tail = NULL;
    }
    free(temp);
    return dequeuedValue;
}

int queue_front(Queue *queue)
{
    if (queue_is_empty(queue))
        return -1;
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
