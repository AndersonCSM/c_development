#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
