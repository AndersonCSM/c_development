#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct
{
    char caractere;
    int valor;
} ASCII;

ASCII *criarElementoASCII(int val, char ch)
{
    ASCII *novoElemento = (ASCII *)malloc(sizeof(ASCII));
    if (novoElemento == NULL)
    {
        printf("Erro ao alocar memoria na funcao!\n");
        return NULL;
    }
    novoElemento->valor = val;
    novoElemento->caractere = ch;
    return novoElemento;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int valor;
    char carac;

    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);
    getchar();

    printf("Digite um caractere: ");
    scanf(" %c", &carac); // espaço antes de %c para consumir newlines/espaços pendentes

    ASCII *ptr = criarElementoASCII(valor, carac);

    if (ptr != NULL)
    {
        // Exibe os valores de retorno
        printf("\nElemento ASCII criado:\n");
        printf("Caractere: %c\n", ptr->caractere);
        printf("Valor: %d\n", ptr->valor);

        // Deleta a memoria que foi alocada dentro da funcao
        free(ptr);
    }
    else
    {
        printf("Não foi possível criar o elemento ASCII.\n");
    }

    return 0;
}