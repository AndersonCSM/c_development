#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct balao
{
    float diametro;
    char marca[20];
    int modelo;
};

void preencher(int i, struct balao *vetor)
{
    printf("Informe o diametro do balão\n");
    scanf("%f", &(vetor + i)->diametro);

    printf("Informe a marca do balão\n");
    scanf("%s", &(vetor + i)->marca);

    printf("Informe o modelo do balão\n");
    scanf("%i", &(vetor + i)->modelo);
}

void exibir(struct balao *ptr)
{
    printf("Diâmetro: %.2f\n", ptr->diametro);
    printf("marca: %s\n", ptr->marca);
    printf("modelo: %d\n", ptr->modelo);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n;
    printf("Informe a quantidade de balões:\n");
    scanf("%d", &n);

    // Aloca memória para os balões
    struct balao *vet = (struct balao *)malloc(n * sizeof(struct balao));
    if (vet == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        preencher(i, vet);
    }

    for (int i = 0; i < n; i++)
    {
        exibir((vet + i));
    }

    free(vet);
    return 0;
}