#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{
    Queue q1;
    queue_init(&q1);

    printf("Adicionando 'Documento1.pdf' a fila...\n");
    queue_enqueue(&q1, "Documento1.pdf");

    printf("Adicionando 'Relatorio.docx' a fila...\n");
    queue_enqueue(&q1, "Relatorio.docx");

    printf("Fila atual: ");
    queue_display(&q1);

    const char *documento_impresso = queue_dequeue(&q1);
    printf("Saida: Imprimindo %s\n", documento_impresso);

    printf("\nAdicionando 'Foto.png' a fila...\n");
    queue_enqueue(&q1, "Foto.png");

    printf("Saida: ");
    queue_display(&q1);

    return 0;
}
