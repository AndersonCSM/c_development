#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct carro
{
    char modelo[100];
    int ano;
    float preco;
};

void preencher(int i, struct carro *vetor)
{
    printf("Informe o modelo do carro %d\n", i + 1);
    scanf("%s", &(vetor + i)->modelo);

    printf("Informe o ano do carro %d\n", i + 1);
    scanf("%d", &(vetor + i)->ano);

    printf("Informe o preco %d\n", i + 1);
    scanf("%f", &(vetor + i)->preco);
}

void exibir(int n, struct carro *vetor)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (vetor + i)->preco;
    }
    printf("O valor  e: R$ %.2f\n", sum);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n = 0;
    printf("Informe a quantidade de carros: ");
    scanf("%d", &n);

    struct carro *vet = (struct carro *)malloc(n * sizeof(struct carro));
    if (vet == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        preencher(i, vet);
        printf("\n");
    }

    exibir(n, vet);

    free(vet);
    return 0;
}
