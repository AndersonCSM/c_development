#ifndef QUEUE_H
#define QUEUE_H

typedef struct QNode{
    int data;
    struct QNode* next;
} QNode;

typedef struct Queue{
    QNode *front;
    QNode *tail;
} Queue;

// Protótipos com os novos nomes
void queue_init(Queue *queue);
int queue_is_empty(Queue *queue);
void queue_enqueue(Queue *queue, int value);
int queue_dequeue(Queue *queue);
int queue_front(Queue *queue);
void queue_display(Queue *queue);

#endif