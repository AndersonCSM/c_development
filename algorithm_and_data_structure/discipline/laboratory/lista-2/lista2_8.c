#include <stdio.h>
#include <locale.h>

enum estado
{
    CHEIO,
    VAZIA
};
enum tipo_food
{
    sopa,
    canja
};

struct Tigela
{
    enum estado stage;
    enum tipo_food comida;
};

void Fome(struct Tigela *ptr)
{
    ptr->stage = VAZIA;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Tigela t1 = {CHEIO, sopa};
    struct Tigela *ptr = &t1;

    const char *estados[] = {"cheia", "vazia"}; // ponteiro de vetor de array de caracteres
    const char *comidas[] = {"sopa", "canja"};  // ponteiro de vetor array de caracteres

    printf("Antes do RU: %s\n%s\n", estados[ptr->stage], comidas[ptr->comida]); 
    // acessando o elemento estado[CHEIO], o enum possui um indice integrado, logo CHEIO -> 0, VAZIO -> 1, estado -> n-1
    // acessando o elemento comida[sopa], o enum possui um indice integrado, logo sopa -> 0, canja -> 1, comida_n -> n-1

    Fome(ptr);

    printf("Pos RU: %s\n%s\n", estados[ptr->stage], comidas[ptr->comida]);

    return 0;
}
