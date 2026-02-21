#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void escalonador_round_robin(Queue *fila_processos, int quantum)
{
    printf("Escalonador Round-Robin (Quantum: %ds)\n", quantum);

    // Continua enquanto houver processos na fila
    while (!queue_is_empty(fila_processos))
    {
        // Pega o próximo processo da fila
        Processo processo_atual = queue_dequeue(fila_processos);

        // Determina quanto tempo este processo vai executar nesta rodada
        int tempo_exec = (processo_atual.resting_time < quantum)
                             ? processo_atual.resting_time
                             : quantum;

        printf("Executando %s por %ds... \n", processo_atual.nome, tempo_exec);

        // Atualiza o tempo restante do processo
        processo_atual.resting_time -= tempo_exec;

        // Verifica se o processo terminou
        if (processo_atual.resting_time > 0)
        {
            // Se não terminou, volta para o final da fila
            printf("(restam %ds)\n", processo_atual.resting_time);
            queue_enqueue(fila_processos, processo_atual.nome, processo_atual.resting_time);
        }
        else
        {
            // Se terminou, é descartado (não volta para a fila)
            printf("(finalizado)\n");
        }

        // Exibe o estado da fila após cada rodada
        queue_display(fila_processos);
        printf("--------------------------------------------------------\n");
    }
    printf("Os processos foram concluidos\n");
}

int main()
{
    Queue fila;
    queue_init(&fila);
    int quantum = 3;

    // Adiciona os processos iniciais à fila
    printf("Adicionando processos a fila...\n");
    queue_enqueue(&fila, "Processo A", 8);
    queue_enqueue(&fila, "Processo B", 4);
    queue_enqueue(&fila, "Processo C", 6);
    printf("\n");

    printf("Processos: ");
    queue_display(&fila);
    printf("\n");

    escalonador_round_robin(&fila, quantum);

    return 0;
}
