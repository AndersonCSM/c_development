#include <stdio.h>
#include <stdlib.h> // Para rand(), srand()
#include <time.h>   // Para time(), clock_t, clock(), CLOCKS_PER_SEC
#include <string.h> // Para memcpy()
#include <locale.h>

#include "../include/auxiliar.h"
#include "../include/search-algorithms.h"
#include "../include/sorting-algorithms.h"

void q1()
{
    srand(time(NULL));

    const char *metodos[] = {"BubbleSort", "InsertionSort", "MergeSort", "QuickSort"};

    int N[3] = {1000, 100000, 100000};

    FILE *arq = fopen("data/q1.txt", "w");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo q1.txt");
        return;
    }

    fprintf(arq, "Algoritmos de Ordenacao\n");

    for (int size_opc = 0; size_opc < 3; size_opc++)
    {
        int size = N[size_opc];

        int *original = malloc(size * sizeof(int));
        int *ordenado = malloc(size * sizeof(int));

        gerar_array_int(original, size);

        if (original == NULL || ordenado == NULL)
        {
            printf("Falha ao alocar memoria.\n");
            free(original);
            free(ordenado);
            return;
        }

        fprintf(arq, "Tamanho do Array: %d\n", size);
        fprintf(arq, "+-----------------+-----------------------+\n");
        fprintf(arq, "| Metodo          | Tempo (s)             |\n");
        fprintf(arq, "+-----------------+-----------------------+\n");

        for (int met_opc = 0; met_opc < 4; met_opc++)
        {
            copiar_array_int(ordenado, original, size);

            clock_t inicio_tempo = 0, fim_tempo = 0;
            double tempo_decorrido = 0;

            inicio_tempo = clock();
            sorting_switch(met_opc, ordenado, size);
            fim_tempo = clock();

            tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;

            fprintf(arq, "| %-15s | %-21.18f |\n", metodos[met_opc], tempo_decorrido);
        }

        print_array_int(arq, "Vetor original: ", original, 20);
        print_array_int(arq, "Vetor ordenado: ", ordenado, 20);

        fprintf(arq, "+-----------------+-----------------------+\n");
        free(original);
        free(ordenado);
    }

    // char
    int size_char = 255;
    fprintf(arq, "Cenario: Array de %d caracteres\n", size_char);
    fprintf(arq, "+-----------------+-----------------------+\n");
    fprintf(arq, "| Metodo          | Tempo (s)             |\n");
    fprintf(arq, "+-----------------+-----------------------+\n");

    char *original_char = (char *)malloc(size_char * sizeof(char));
    char *ordenado_char = (char *)malloc(size_char * sizeof(char));

    gerar_array_char_aleatorio(original_char, size_char);

    for (int met_opc = 0; met_opc < 4; met_opc++)
    {
        copiar_array_char(ordenado_char, original_char, size_char);

        clock_t inicio = clock();
        sorting_switch_c(met_opc, ordenado_char, size_char);
        clock_t fim = clock();

        double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        fprintf(arq, "| %-15s | %-21.18f |\n", metodos[met_opc], tempo);
    }

    print_array_char(arq, "Vetor char original: ", original_char, 20);
    print_array_char(arq, "Vetor char ordenado: ", ordenado_char, 20);

    fprintf(arq, "+-----------------+-----------------------+\n");
    free(original_char);
    free(ordenado_char);

    fclose(arq);
    printf("Questao 1 - Done\n");
}

void q2()
{
    srand(time(NULL));
    const char *metodos[] = {"linear", "binaria"};

    int N[3] = {1000, 100000, 1000000};

    FILE *arq = fopen("data/q2.txt", "w");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo q2.txt");
        return;
    }

    fprintf(arq, "Algoritmos de Busca\n");

    for (int size_opc = 0; size_opc < 3; size_opc++)
    {
        int size = N[size_opc];

        fprintf(arq, "Cenario: Array de %d inteiros\n", size);
        fprintf(arq, "+-----------------+-----------------------+\n");
        fprintf(arq, "| Metodo          | Tempo (s)             |\n");
        fprintf(arq, "+-----------------+-----------------------+\n");

        int *numeros = (int *)malloc(size * sizeof(int));

        gerar_array_int(numeros, size);
        int elemento_busca = numeros[rand() % size];

        // Busca Linear
        clock_t inicio_l = clock();
        for (int i = 0; i < 50000; i++)
        {
            busca_linear(numeros, size, elemento_busca);
        }
        clock_t fim_l = clock();

        double tempo_l = ((double)(fim_l - inicio_l)) / CLOCKS_PER_SEC;

        fprintf(arq, "| %-15s | %-21.18f |\n", metodos[0], tempo_l);

        // Busca Binária (precisa ordenar primeiro)
        quickSort(numeros, 0, size - 1);

        clock_t inicio_b = clock();
        for (int i = 0; i < 50000; i++)
        {
            busca_binaria(numeros, size, elemento_busca);
        }
        clock_t fim_b = clock();

        double tempo_b = ((double)(fim_b - inicio_b)) / CLOCKS_PER_SEC;

        fprintf(arq, "| %-15s | %-21.18f |\n", metodos[1], tempo_b);
        fprintf(arq, "+-----------------+-----------------------+\n");

        free(numeros);
    }

    // buscando texto
    const char *texto = "Era uma vez um pinguim chamado Tobias que sonhava em voar "
                        "Todos os dias ele corria pelo gelo batendo suas pequenas asas com toda a forca "
                        "Um dia eu vou voar gritava assustando as focas e fazendo os peixes darem risada "
                        "Mas Tobias era teimoso Construiu um trampolim com pedacos de madeira que encontrou em um navio naufragado "
                        "Saltou Planou por um segundo Caiu de bunda no gelo Quase disse esfregando a barriga "
                        "No dia seguinte tentou com baloes No outro com uma capa de super heroi Nada "
                        "Mas um dia uma gaivota chamada Gertrudes pousou ao seu lado e disse Voce ja pensou que talvez seu voo seja diferente "
                        "Talvez voce ja voe so que nadando Tobias mergulhou nadou como um foguete fez piruetas e pela primeira vez se sentiu livre "
                        "Desde entao voa todos os dias nao pelo ceu mas pelo mar gelado "
                        "Moral da historia Nem todo voo precisa de asas";

    int num_palavras = count_word(texto);
    // array de strings
    char **palavras = (char **)malloc(num_palavras * sizeof(char *));

    // preenche o array de palavras com as palavras do texto
    extract_word(texto, palavras, num_palavras);

    // palavra aleatoria
    const char *palavra_busca = palavras[rand() % num_palavras];

    fprintf(arq, "Cenario: Buscando a palavra '%s' em um texto com %d palavras\n", palavra_busca, num_palavras);
    fprintf(arq, "+-----------------+-----------------------+\n");
    fprintf(arq, "| Metodo          | Tempo (s)             |\n");
    fprintf(arq, "+-----------------+-----------------------+\n");

    // Busca Linear de String
    clock_t inicio_ls = clock();
    for (int i = 0; i < 50000; i++)
    {
        busca_linear_string(palavras, num_palavras, palavra_busca);
    }
    clock_t fim_ls = clock();

    double tempo_ls = ((double)(fim_ls - inicio_ls)) / CLOCKS_PER_SEC;

    fprintf(arq, "| %-15s | %-21.18f |\n", metodos[0], tempo_ls);

    // Busca Binária de String (precisa ordenar primeiro)
    quickSortStrings(palavras, 0, num_palavras - 1);

    clock_t inicio_bs = clock();
    
    for (int i = 0; i < 50000; i++)
    {
        busca_binaria_string(palavras, num_palavras, palavra_busca);
    }
    clock_t fim_bs = clock();

    double tempo_bs = ((double)(fim_bs - inicio_bs)) / CLOCKS_PER_SEC;

    fprintf(arq, "| %-15s | %-21.18f |\n", metodos[1], tempo_bs);

    fprintf(arq, "+-----------------+-----------------------+\n");

    free_word(palavras, num_palavras);
    free(palavras);

    fclose(arq);
    printf("Questao 2 - Done\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int test = 2;
    if (test == 1)
    {
        q1();
        printf("Concluido.\n");
    }
    else if (test == 2)
    {
        q2();
        printf("Concluido.\n");
    }
    else
    {
        int size = 500000;

        int *original = malloc(size * sizeof(int));
        int *ordenado = malloc(size * sizeof(int));

        gerar_array_int(original, size);

        if (original == NULL || ordenado == NULL)
        {
            printf("Falha ao alocar memoria.\n");
            free(original);
            free(ordenado);
            return 0;
        }

        printf("Tamanho do Array: %d\n", size);
        printf("+-----------------+-----------------------+\n");
        printf("| Metodo          | Tempo (s)             |\n");
        printf("+-----------------+-----------------------+\n");

        copiar_array_int(ordenado, original, size);

        clock_t inicio_tempo = 0, fim_tempo = 0;
        double tempo_decorrido = 0;

        inicio_tempo = clock();
        // quickSort(ordenado, 0, size - 1);
        mergeSort(ordenado, 0, size - 1);
        fim_tempo = clock();

        tempo_decorrido = ((double)(fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;

        printf("| %-15s | %-21.18f |\n", "quicksort", tempo_decorrido);

        for (int i = 0; i < 200; i++)
        {
            printf("%d, ", ordenado[i]);
        }

        free(original);
        free(ordenado);
    }

    return 0;
}