#include "generic_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// criar lista
List *list_create(size_t data_size, cb_free free_data, cb_compare compare_data)
{
    assert(data_size > 0); // testa rapidamente se a sentença é válida sem uso de if

    List *list = malloc(sizeof(List)); // aloca um ponteiro para lista do tamanho da Lista

    list->data_size = data_size;       // tamanho dos dados que serão armazenados na lista
    list->head = NULL;                 // criando a head é null
    list->free_data = free_data;       // ponteiro para função de liberar
    list->compare_data = compare_data; // ponteiro para função de comparar
    return list;
}

// adicionar elementos
void list_add(List *list, void *data)
{
    assert(list != NULL); // verifica rapidamente a sentença sem if
    assert(data != NULL); // verifica rapidamente a sentença sem if

    // aloca espaço para nmemb elementos de size bytes e INICIALIZA todos os bytes com zero.
    Node *newNode = calloc(1, sizeof(Node));

    // cria um bloco de memória para armazenar dados novos
    newNode->data = malloc(list->data_size);

    // copia byte a byte (destino, origem, tamanho)
    memcpy(newNode->data, data, list->data_size);

    newNode->next = list->head; // faz o novo nó apontar para a head antiga, garante o encadeamento
    // HEAD_ANT -> NODE_ANT ===> HEAD_NEW -> HEAD_ANT -> NODE_ANT
    list->head = newNode; // a head da lista será o novo node criado
}

static void free_node_data(cb_free free_data, void *data)
{
    /*
    Libera a memória alocada para o dado armazenado na lista
    */
    if (free_data != NULL)
    {
        free_data(data); // callback para os casos mais complexos
    }
    else
    {
        free(data);
    }
}

void list_destroy(List *list)
{
    assert(list != NULL);

    Node *node = list->head;

    while (node != NULL)
    {
        Node *next = node->next; // o next será usado na proxima iteração
        // começa com a head externa
        // libera os dados da lista genérica, pode ser qualquer coisa por isso usa a função com callback
        free_node_data(list->free_data, node->data);
        free(node);  // libera o nó
        node = next; // atualiza node com o next;
    }
    /*
    São feitos três liberações porque foram feito três alocamentos
    1 - Dados: fazem parte do nó
    2 - Nó: fazem parte da lista
    3 - Lista
    */
    free(list);
}

// buscando elemento
bool list_contains(List *list, void *data)
{
    assert(list->compare_data != NULL);

    Node *node = list->head; // resgata a head da lista
    while (node != NULL)
    { // percore a lista da head até o tail
        /*
        É usado a função de callback compare_data pois a lista é genérica, ou seja,
        além dos tipos primitivos poderiamos ter structs, union e outras estruturas de dados
        que necessitariam de uma forma de compara-las
        Se fossem inteiros apenas a == b seria suficiente
        */
        if (list->compare_data(node->data, data) == 0) // callback de comparação
            return true;                               // se achar o elemento return true
        node = node->next;                             // atualiza node
    }
    return false; // se não achar return false
}

void list_iterate(List *list, cb_iterate iterate_callback)
{
    assert(list != NULL);
    assert(iterate_callback != NULL);

    Node *current = list->head;
    int index = 0;

    // Enquanto ainda houver nós para visitar
    while (current != NULL)
    {
        // Chamamos a função de callback para o nó atual.
        bool continuar = iterate_callback(index, current->data);

        // Se a função de callback retornar 'false', paramos a iteração
        if (!continuar)
            break;

        // Avançamos para o próximo nó
        current = current->next;
        index++;
    }
}
