int main()
{
    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;

    quickSort(vetor, 0, tamanho);

    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf(" Ordenado com Quick Sort ");
    return 0;
}
