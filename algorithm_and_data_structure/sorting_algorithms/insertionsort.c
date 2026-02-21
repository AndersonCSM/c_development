#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionsort(int *vet, int n)
{
    if (n > 1)
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

void printv(int *vet, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", vet[i]);
    }
}

int main()
{
    return 0;
}
