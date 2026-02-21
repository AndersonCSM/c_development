#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n = 0;

    printf("Digite o número de alunos (mínimo 2):\n");
    scanf("%d", &n);

    if (n < 2)
    {
        printf("Número de alunos deve ser no mínimo 2.\n");
        return 1;
    }

    float *vet = (float *)malloc(n * sizeof(float));

    if (vet == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", (vet + i));
    }

    printf("\nNotas digitadas:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Aluno %d: %.2f\n", i + 1, *(vet + i));
    }

    free(vet);
    return 0;
}
