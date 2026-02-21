#ifndef QUEUE_H
#define QUEUE_H

typedef struct Processo
{
    char nome[101];
    int resting_time;
} Processo;

typedef struct QNode
{
    Processo data;
    struct QNode *next;
} QNode;

typedef struct Queue
{
    QNode *front;
    QNode *tail;
} Queue;

// Protótipos com os novos nomes
void queue_init(Queue *queue);
int queue_is_empty(Queue *queue);
void queue_enqueue(Queue *queue, const char *nome, int tempo);
Processo queue_dequeue(Queue *queue);
char *queue_front(Queue *queue);
void queue_display(Queue *queue);

#endif