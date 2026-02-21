#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

#include <stdbool.h>
#include <stddef.h>


// callbacks
typedef void (*cb_free)(void *);             // usado para liberar o conteúdo de um elemento
typedef int (*cb_compare)(void *a, void *b); // compara dois elementos
typedef bool(*cb_iterate)(int index, void *data); // usada para iterar sobre a lista

typedef struct node // nó genérico
{ 
    void *data; // ponteiro de dado genérico
    struct node *next; // ponteiro para o próximo nó
} Node;

typedef struct
{                     // Lista genérica
    size_t data_size; // tamanho dos dados que serão armazeandos
    Node *head;       // hrad da lista

    // funções de callback para o tipo de dado
    cb_free free_data;
    cb_compare compare_data;
} List;

// protótipos de funções
List *list_create(size_t data_size, cb_free free_data, cb_compare compare_data);
void list_destroy(List *list);
void list_add(List *list, void *data);
bool list_contains(List *list, void *data);
void list_iterate(List *list, cb_iterate iterate_callback);
#endif