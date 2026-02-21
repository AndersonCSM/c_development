#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

void round_robin(Processo *processos, int tot_processos, int timer)
{
    Queue fila_prontos;
    queue_init(&fila_prontos);

    int tempo_atual = 0;
    int processos_concluidos = 0;
    int processo_next_indice = 0;

    printf("Iniciando Simulacao (Quantum: %ds)\n", timer);

    // O loop principal continua enquanto houver processos a chegar ou na fila
    while (processos_concluidos < tot_processos)
    {
        // VERIFICAR CHEGADAS
        // Adiciona à fila de prontos todos os processos que chegaram neste instante de tempo
        while (processo_next_indice < tot_processos &&
               processos[processo_next_indice].tempo_chegada <= tempo_atual)
        {
            printf("[Tempo %d] Chegada: Processo %d (Execucao: %ds)\n",
                   tempo_atual,
                   processos[processo_next_indice].id,
                   processos[processo_next_indice].tempo_execucao_total);

            queue_enqueue(&fila_prontos, processos[processo_next_indice]);
            processo_next_indice++;
        }

        // EXECUTAR PROCESSO
        if (!queue_is_empty(&fila_prontos))
        {
            Processo processo_atual = queue_dequeue(&fila_prontos);

            // Determina quanto tempo este processo vai executar nesta rodada
            int tempo_de_execucao = (processo_atual.tempo_restante < timer)
                                        ? processo_atual.tempo_restante
                                        : timer;
            printf("[Tempo %d] Executando Processo %d por %ds...\n", tempo_atual, processo_atual.id, tempo_de_execucao);

            // Avança o relógio da simulação
            tempo_atual += tempo_de_execucao;
            processo_atual.tempo_restante -= tempo_de_execucao;

            // Verifica se o processo terminou
            if (processo_atual.tempo_restante > 0)
            {
                // Se não terminou volta para a fila
                // verifica se novos processos chegaram enquanto este executava
                while (processo_next_indice < tot_processos &&
                       processos[processo_next_indice].tempo_chegada <= tempo_atual)
                {
                    printf("[Tempo %d] Chegada: Processo %d (Execucao: %ds)\n",
                           processos[processo_next_indice].tempo_chegada,
                           processos[processo_next_indice].id,
                           processos[processo_next_indice].tempo_execucao_total);
                    queue_enqueue(&fila_prontos, processos[processo_next_indice]);
                    processo_next_indice++;
                }
                //  o processo atual volta para o fim da fila
                queue_enqueue(&fila_prontos, processo_atual);
            }
            else
            {
                printf("[Tempo %d] Finalizado: Processo %d\n", tempo_atual, processo_atual.id);
                processos_concluidos++;
            }
            queue_display(&fila_prontos);
            printf("--------------------------------------------\n");
        }
        else
        {
            // Se a fila está vazia, mas ainda há processos para chegar, avança o tempo.
            printf("[Tempo %d] CPU Ociosa...\n", tempo_atual);
            tempo_atual++;
        }
    }
    printf("\nSimulacao concluida em %d segundos.\n", tempo_atual);
}

int main()
{
    Processo processos[] = {
        {1, 8, 8, 0}, // id, tempo_exec, tempo_restante, tempo_chegada
        {2, 4, 4, 2},
        {3, 6, 6, 4},
        {4, 2, 2, 7}};

    int tot_processos = sizeof(processos) / sizeof(Processo);
    int timer = 3;

    round_robin(processos, tot_processos, timer);

    return 0;
}

