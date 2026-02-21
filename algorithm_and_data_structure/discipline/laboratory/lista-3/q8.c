#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n = 0;
    printf("Quantos inteiros você deseja armazenar?\n");
    scanf("%d", &n);

    int *vet = (int *)malloc(n * sizeof(int));
    if (vet == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite os %d inteiros:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Elemento %d:\n", i + 1);
        scanf("%d", &vet[i]);
    }

    printf("\nvetor preenchido:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", vet[i]);
    }
    printf("\n");

    free(vet);
    return 0;
}