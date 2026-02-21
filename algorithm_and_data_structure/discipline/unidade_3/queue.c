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

void queue_enqueue(Queue *queue, Processo p)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    if (!newNode)
        return;

    newNode->dados = p;
    newNode->next = NULL;

    if (queue->tail == NULL)
    {
        queue->front = queue->tail = newNode;
    }
    else
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

Processo queue_dequeue(Queue *queue)
{
    if (queue_is_empty(queue))
    {
        // Retorna um processo com ID inválido (-1) para indicar erro
        Processo processo_vazio = {-1, -1, -1, -1};
        return processo_vazio;
    }

    QNode *temp = queue->front;
    Processo processo_removido = temp->dados;

    queue->front = temp->next;
    if (queue->front == NULL)
    {
        queue->tail = NULL;
    }
    free(temp);

    return processo_removido;
}

void queue_display(Queue *queue)
{
    if (queue_is_empty(queue))
    {
        printf("Fila de prontos esta vazia.\n");
        return;
    }
    QNode *temp = queue->front;
    printf("Fila de Prontos: ");
    while (temp)
    {
        printf("[ID:%d (resta:%ds)] ", temp->dados.id, temp->dados.tempo_restante);
        temp = temp->next;
    }
    printf("\n");
}
