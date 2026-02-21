#ifndef QUEUE_H
#define QUEUE_H

typedef struct Processo
{
    int id;                   // ID do processo
    int tempo_execucao_total; // Tempo original
    int tempo_restante;       // Tempo que falta
    int tempo_chegada;        // Momento que entra no sistema
} Processo;

typedef struct QNode
{
    Processo dados;
    struct QNode *next;
} QNode;

typedef struct Queue
{
    QNode *front;
    QNode *tail;
} Queue;

void queue_init(Queue *queue);
int queue_is_empty(Queue *queue);
void queue_enqueue(Queue *queue, Processo p);
Processo queue_dequeue(Queue *queue);
void queue_display(Queue *queue);

#endif