#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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

void printv(int *vet, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main()
{
    int vet[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Array original: ");
    printv(vet, n);

    mergeSort(vet, 0, n - 1);

    printf("Array ordenado: ");
    printv(vet, n);

    return 0;
}
