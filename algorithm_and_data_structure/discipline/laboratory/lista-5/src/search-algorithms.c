#include <stdio.h>
#include <string.h>

#include "../include/search-algorithms.h"

int busca_linear(int *vet, int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == element)
        {
            return i;
        }
    }

    return -1;
}

int busca_binaria(int *vet, int n, int element)
{
    int pivo = 0;
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        pivo = left + (right - left) / 2;

        if (vet[pivo] == element)
        {
            return pivo;
        }
        else if (vet[pivo] < element)
        {
            left = pivo + 1;
        }
        else
        {
            right = pivo - 1;
        }
    }
    return -1;
}

// String
int busca_linear_string(char *arr[], int n, const char *palavra)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], palavra) == 0)
        {
            return i; // Encontrou
        }
    }
    return -1; // Não encontrou
}

int busca_binaria_string(char *arr[], int n, const char *palavra)
{
    int inicio = 0, fim = n - 1;
    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        int cmp = strcmp(arr[meio], palavra);
        if (cmp == 0)
        {
            return meio; // Encontrou
        }
        if (cmp < 0)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1; // Não encontrou
}