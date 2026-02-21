#include <stdio.h>
#include <locale.h>

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
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int vet[] = {1, 2, 5, 6, 9};

    int n = sizeof(vet) / sizeof(int);
    int element = 6;

    int indice_element = busca_binaria(vet, n, element);

    printf("O elemento %d esta no indice %d\n", element, indice_element);

    return 0;
}