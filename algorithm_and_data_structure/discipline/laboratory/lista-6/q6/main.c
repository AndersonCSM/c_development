#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{
    Queue q1;
    queue_init(&q1);

    queue_enqueue(&q1, "Joao");
    queue_enqueue(&q1, "Victor");

    printf("Fila atual: ");
    queue_display(&q1);

    printf("Atendendo %s\n", queue_dequeue(&q1));
    queue_enqueue(&q1, "Caio");

    printf("Fila atual: ");
    queue_display(&q1);

    return 0;
}
