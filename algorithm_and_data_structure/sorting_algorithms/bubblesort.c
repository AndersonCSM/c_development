#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int *vet, int n)
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
