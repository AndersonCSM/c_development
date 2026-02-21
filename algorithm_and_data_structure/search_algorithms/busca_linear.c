#include <stdio.h>
#include <locale.h>

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

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int vet[] = {0, 5, 2, 20, 4};

    int n = sizeof(vet) / sizeof(int);
    int element = 4;

    int indice_element = busca_linear(vet, n, element);

    printf("O elemento %d esta no indice %d\n", element, indice_element);

    return 0;
}