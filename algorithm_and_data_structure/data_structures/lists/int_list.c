#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "generic_list.h"

// Callback para comparar dois inteiros
int compare_int(void *a, void *b)
{
    /*
    O padrão é que seja retornado 0 se ambos forem iguais
    */

    int x = *(int *)a; // como a lista é genérica, é realizado um cast para inteiro
    int y = *(int *)b;
    return x - y;
}

// Callback para iterar e imprimir
bool print_int(int index, void *data)
{
    int value = *(int *)data;
    printf("[%d]: %d\n", index, value);
    return true; // continuar a iteração
}

int main()
{
    // ponteiro da lista, sendo repassado (tamanho do dado, callback de free, callback de comparação)
    List *list = list_create(sizeof(int), NULL, compare_int);
    int itens[5] = {2, 5, 3, 8, 9};

    for (int i = 0; i < 5; i++)
    {
        int *data = malloc(sizeof(int)); // ponteiro para os dados genéricos da lista
        *data = itens[i];                // os dados genericos serão os inteiros da lista
        list_add(list, data);            // adiciona o dado a lista, o dado será um node da lista
        free(data);                      // libera a memoria da variavel generica data usada para preencher a lista
    }

    int search_key = 8;

    printf("Procurando nó com chave: %d...\n", search_key);

    if (list_contains(list, &search_key)) // list_contains espera receber um ponteiro da chave
        printf("-> Sucesso: Chave %d encontrada!\n", search_key);
    else
        printf("-> Falha: Chave %d não encontrada.\n", search_key);

    printf("----------------------------------------\n");

    // Destruir a lista
    list_destroy(list);
    list = NULL;

    return 0;
}

