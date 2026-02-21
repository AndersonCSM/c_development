#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int valor = 10, *temp, soma = 0;
    temp = &valor;
    *temp = 20;

    temp = &soma;
    *temp = valor;

    printf("valor: %d\n soma: %d\n", valor, soma);

    return 0;
}
