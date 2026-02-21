// implementar o algoritmo de ordenacao quicksort

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *vetor, int inicio, int fim)
{
    // abordagem de hoare
    int i, j, pivo, aux;
    i = inicio;                       // i e o primeiro indice do vetor
    j = fim - 1;                      // j e o ultimo indice do vetor
    pivo = vetor[(inicio + fim) / 2]; // pivo e o elemento do meio

    while (i <= j)
    { // Enquanto i e j nao se cruzarem
        // busca o primeiro elemento menor que o pivo a partir de i
        while (vetor[i] < pivo && i < fim)
        {
            i++;
        }
        // busca o primeiro elemento maior que o pivo a partir de j
        while (vetor[j] > pivo && j > inicio)
        {
            j--;
        }
        if (i <= j)
        { // Enquanto i e j nao se cruzarem
            // troca os elementos encontrados
            // aux = vetor[i];
            // vetor[i] = vetor[j];
            // vetor[j] = aux;
            swap(&vetor[i], &vetor[j]);
            // move os ponteiros i e j para continuar a busca
            i++;
            j--;
        }
    }
    // Chamada recursiva para ordenar as duas metades
    // j esta a esquerda de i.
    if (j > inicio)
    {
        quickSort(vetor, inicio, j + 1);
    }
    if (i < fim)
    {
        quickSort(vetor, i, fim);
    }
}
