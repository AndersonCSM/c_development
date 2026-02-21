#include <stdio.h>
#include <string.h> // Para strcmp
#include <stdlib.h> // Para malloc e free no mergeSort
#include <stdio.h>
#include <string.h> // Necessário para strcmp

#include "../include/sorting-algorithms.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_char(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *vet, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                swap(&vet[j], &vet[j + 1]);
            }
        }
    }
}

void insertionSort(int *vet, int n)
{
    if (n <= 1)
    {
        return;
    }

    int i, j;
    // O loop externo itera do segundo elemento ao final do array
    for (i = 1; i < n; i++)
    {
        j = i;

        // O loop interno move o elemento vet[j] para a esquerda
        // enquanto vet[j] for menor que vet[j-1]
        // e 'j' nao for o primeiro elemento do array (j > 0)
        while (j > 0 && vet[j] < vet[j - 1])
        {
            swap(&vet[j], &vet[j - 1]);
            j--; // J para a esquerda
        }
    }
}

void merge(int *vet, int inicio, int meio, int fim)
{
    // Arrays temporarios para as duas metades
    int i, j, k;
    int n1 = meio - inicio + 1; // tamanho da parte esquerda
    int n2 = fim - meio;        // tamanho da parte direita
    int left[n1], right[n2];    // vetores temporarios

    // Copia os dados para os arrays temporarios
    for (i = 0; i < n1; i++)
    {
        left[i] = vet[inicio + i];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = vet[meio + 1 + j];
    }

    i = 0;      // reset o indice para left
    j = 0;      // reset o indice para right
    k = inicio; // indice para inserir em vet

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j]) // se vetor a esquerda for menor
        {
            vet[k] = left[i]; // vet original na pos k é o menor
            i++;              // avanca
        }
        else
        {
            vet[k] = right[j]; // vet original na pos k é o menor, mas do vetor right
            j++;               // avanca em right
        }
        k++; // avanca no proximo da lista vet
    }

    while (i < n1) // copia os elementos restantes do array esquerdo
    {
        vet[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) // copia os elementos restantes do array direito
    {
        vet[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *vet, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vet, inicio, meio);  // Ordena a metade esquerda
        mergeSort(vet, meio + 1, fim); // Ordena a metade direita
        merge(vet, inicio, meio, fim); // Mescla as duas metades ordenadas
    }
}

void quickSort(int *vetor, int inicio, int fim)
{
    // abordagem de hoare
    int i, j, pivo;
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

// Char
void bubbleSort_c(char *vet, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                swap_char(&vet[j], &vet[j + 1]);
            }
        }
    }
}

void insertionSort_c(char *vet, int n)
{
    if (n <= 1)
    {
        return;
    }

    int i, j;
    // O loop externo itera do segundo elemento ao final do array
    for (i = 1; i < n; i++)
    {
        j = i;

        // O loop interno move o elemento vet[j] para a esquerda
        // enquanto vet[j] for menor que vet[j-1]
        // e 'j' nao for o primeiro elemento do array (j > 0)
        while (j > 0 && vet[j] < vet[j - 1])
        {
            swap_char(&vet[j], &vet[j - 1]);
            j--; // J para a esquerda
        }
    }
}

void merge_c(char *vet, int inicio, int meio, int fim)
{
    // Arrays temporarios para as duas metades
    int i, j, k;
    int n1 = meio - inicio + 1; // tamanho da parte esquerda
    int n2 = fim - meio;        // tamanho da parte direita
    int left[n1], right[n2];    // vetores temporarios

    // Copia os dados para os arrays temporarios
    for (i = 0; i < n1; i++)
    {
        left[i] = vet[inicio + i];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = vet[meio + 1 + j];
    }

    i = 0;      // reset o indice para left
    j = 0;      // reset o indice para right
    k = inicio; // indice para inserir em vet

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j]) // se vetor a esquerda for menor
        {
            vet[k] = left[i]; // vet original na pos k é o menor
            i++;              // avanca
        }
        else
        {
            vet[k] = right[j]; // vet original na pos k é o menor, mas do vetor right
            j++;               // avanca em right
        }
        k++; // avanca no proximo da lista vet
    }

    while (i < n1) // copia os elementos restantes do array esquerdo
    {
        vet[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) // copia os elementos restantes do array direito
    {
        vet[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort_c(char *vet, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort_c(vet, inicio, meio);  // Ordena a metade esquerda
        mergeSort_c(vet, meio + 1, fim); // Ordena a metade direita
        merge_c(vet, 
            inicio, meio, fim); // Mescla as duas metades ordenadas
    }
}

void quickSort_c(char *vetor, int inicio, int fim)
{
    // abordagem de hoare
    int i, j;
    char pivo;
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
            swap_char(&vetor[i], &vetor[j]);
            // move os ponteiros i e j para continuar a busca
            i++;
            j--;
        }
    }
    // Chamada recursiva para ordenar as duas metades
    // j esta a esquerda de i.
    if (j > inicio)
    {
        quickSort_c(vetor, inicio, j + 1);
    }
    if (i < fim)
    {
        quickSort_c(vetor, i, fim);
    }
}

// quick do string
void quickSortStrings(char *arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        char *pivo = arr[fim];
        int i = (inicio - 1);

        for (int j = inicio; j <= fim - 1; j++)
        {
            if (strcmp(arr[j], pivo) < 0)
            {
                i++;
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        char *temp = arr[i + 1];
        arr[i + 1] = arr[fim];
        arr[fim] = temp;

        int pi = i + 1;
        quickSortStrings(arr, inicio, pi - 1);
        quickSortStrings(arr, pi + 1, fim);
    }
}