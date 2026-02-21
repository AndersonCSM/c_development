#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *queue)
{
    queue->front = queue->rear = NULL;
}

int isEmpty(Queue *queue)
{
    return queue->front == NULL;
}
void enqueue(Queue *queue, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Erro: fila vazia!\n");
        return -1;
    }
    Node *temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}

int front(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Erro: fila vazia!\n");
        return -1;
    }
    return queue->front->data;
}

void display(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Fila vazia.\n");
        return;
    }
    Node *temp = queue->front;
    printf("Fila: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);

    printf("Elemento na frente: %d\n", front(&queue));
    printf("Desenfileirando: %d\n", dequeue(&queue));
    display(&queue);

    return 0;
}