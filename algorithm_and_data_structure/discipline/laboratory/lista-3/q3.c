#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct carro
{
    char modelo[100];
    int ano;
    float preco;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct carro vet[10] = {
        {"Vectra", 2009, 58000},
        {"Polo", 2008, 45000}};

    struct carro *ptr = vet; // vet já é o endereço do primeiro elemento do array.
    printf("%s\n", (ptr + 1)->modelo);
    printf("%d\n", (ptr + 1)->ano);
    printf("R$ %.2f\n", (ptr + 1)->preco);
    printf("\n");

    printf("%s\n", (vet + 1)->modelo);
    printf("%d\n", (vet + 1)->ano);
    printf("R$ %.2f\n", (vet + 1)->preco);
    return 0;
}
