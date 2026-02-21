#include <stdio.h>
#include <locale.h>

struct peixe
{
    char tipo[20];   // String -> array de char
    float peso;      // ponto flutuante
    int comprimento; // comprimento tipo inteiro
};

void exibirPeixe(struct peixe p);
void exibirPeixeP(struct peixe *ptr);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct peixe peixe1 = {"Baiacu", 0.100, 15}; // criando uma variável chamada peixe1 do tipo peixe

    struct peixe *ptr = &peixe1; // Criando um ponteiro chamado ptr do tipo struct peixe e passando o endereço da variável peixe1
    printf("%p \n", ptr);

    exibirPeixe(peixe1);
    exibirPeixeP(ptr);
    return 0;
}

void exibirPeixe(struct peixe p)
{
    printf("Tipo: %s\n", p.tipo);
    printf("Peso: %f\n", p.peso);
    printf("Comprimento: %d\n", p.comprimento);
}

void exibirPeixeP(struct peixe *ptr)
{
    printf("\n");
    printf("Tipo: %s\n", ptr->tipo);
    printf("Peso: %f\n", ptr->peso);
    printf("Comprimento: %d\n", ptr->comprimento);
}