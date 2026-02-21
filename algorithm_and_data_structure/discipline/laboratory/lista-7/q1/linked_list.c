#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

SNode *slist_create_node(int valor)
{
    SNode *novo = malloc(sizeof(SNode));
    if (novo)
    {
        novo->data = valor;
        novo->next = NULL;
    }
    return novo;
}

void slist_insert_init(SNode **cabeca, int valor)  // endereço do ponteiro da cabeça
{
    SNode *novo = slist_create_node(valor);
    if (novo)
    {
        novo->next = *cabeca; // o novo nó aponta para o que era a antiga cabeça
        *cabeca = novo; // o ponteiro cabeço agora é o novo nó
    }
}

void slist_insert_end(SNode **cabeca, int valor)  // endereço do ponteiro da cabeça
{
    SNode *novo = slist_create_node(valor);
    if (!*cabeca) // se a cabeça é nula
    {
        *cabeca = novo;  // o novo nó é a cabeça
        return;
    }
    SNode *atual = *cabeca;
    while (atual->next) // percorre a lista até achar o último nó
    {
        atual = atual->next;
    }
    atual->next = novo; // atualiza o último nó para apontar para o que será o novo último nó
}

void slist_pop_node(SNode **cabeca, int chave)  // endereço do ponteiro da cabeça
{
    if (!*cabeca)
        return;

    SNode *temp = *cabeca; // nó atual
    SNode *anterior = NULL; // nó anterior

    if (temp->data == chave) // se o valor for o que está na cabeça
    {
        *cabeca = temp->next; // a cabeça será atualizada para o nó next, de temp (cabeça antiga)
        free(temp); // libera temp (cabeçca antiga)
        return;
    }

    while (temp && temp->data != chave) // percorre a lista até encontrar a chave
    {
        anterior = temp; // salva o valor anterior
        temp = temp->next; // atualiza temp a cada iteração até achar o valor requerido
    }

    if (!temp) // não achou o valor para remover
        return;

    anterior->next = temp->next; // realiza a costura entre os nós 
    // |anterior| -> |temp| -> |next|
    // anterior->next deve apontar para |next|, logo deve ser atualizado com o valor de temp->next
    free(temp); // libera temp
}

void slist_get(SNode **cabeca, int chave) // endereço do ponteiro da cabeça
{
    if (!*cabeca)
        return;

    SNode *temp = *cabeca; // ponteiro linear começando da cabeça
    while (temp && temp->data != chave)
    {
        temp = temp->next;
    }

    if (!temp) // ! NULL
    {
        printf("Valor %d nao esta presente na lista simples\n", chave);
    }
    else
    {
        printf("Valor %d esta presente na lista simples\n", chave);
    }
}

void slist_exibir(SNode **cabeca)  // endereço do ponteiro da cabeça
{
    if (!*cabeca)
    {
        printf("Lista simples vazia\n");
        return;
    }
    SNode *atual = *cabeca;
    while (atual)
    {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}
