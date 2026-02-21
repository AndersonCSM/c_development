#include <stdio.h>
#include <stdlib.h>

#include "circular_list.h"

CNode *clist_create_node(int valor)
{
    CNode *novo = malloc(sizeof(CNode));
    if (novo)
    {
        novo->dado = valor;
        novo->proximo = NULL;
    }
    return novo;
}

void clist_insert_init(CNode **cabeca, int valor)
{
    CNode *novo = clist_create_node(valor);
    if (!novo)
        return;

    if (!*cabeca) // se não existir head, o novo será a head
    {
        novo->proximo = novo;
        *cabeca = novo;
    }
    else
    {
        CNode *atual = *cabeca;
        while (atual->proximo != *cabeca)
        {
            atual = atual->proximo;
        }
        novo->proximo = *cabeca; // a antiga head será o valor em sequencia a nova head (novo)
        atual->proximo = novo; // como é circular o ultimo elemento chamado de atual, deve aponta para a nova head (novo)
        *cabeca = novo; // novo passa a ser nova head
    }
}

void clist_insert_end(CNode **cabeca, int valor)
{
    CNode *novo = clist_create_node(valor);
    if (!novo)
        return;

    if (!*cabeca) // se estiver vazia
    {
        novo->proximo = novo;
        *cabeca = novo;
    }
    else
    {
        CNode *atual = *cabeca;
        while (atual->proximo != *cabeca) // busca o ultimo elemento que não seja a head
        {
            atual = atual->proximo;
        }
        atual->proximo = novo; // o antigo ultimo elemento (atual) agora aponta para o novo ultimo elemento (novo)
        novo->proximo = *cabeca; // o ultimo elemento (novo) aponta para a head para fechar a lista circular
    }
}

void clist_pop_node(CNode **cabeca, int chave)
{
    if (!*cabeca)
        return;

    CNode *temp = *cabeca;
    CNode *anterior = NULL;

    do // busca o nó que se deseja remover
    {
        if (temp->dado == chave)
            break;
        anterior = temp; // salva o no anterior ao que deseja remover
        temp = temp->proximo; // atualiza temp como o endereço proximo a ser modificado
    } while (temp != *cabeca);

    if (temp->dado != chave)
        return;

    if (temp->proximo == temp) // se for o unico no na lista
    {
        free(temp);
        *cabeca = NULL; // lista vazia
        return;
    }

    if (temp == *cabeca) // se quisermos remover a head da lista
    {
        CNode *ultimo = *cabeca;
        while (ultimo->proximo != *cabeca) // busca o ultimo elemento
        {
            ultimo = ultimo->proximo;
        }
        *cabeca = temp->proximo; // a head da lista passa a ser o valor proximo armazenado em temp (que é a proria head)
        ultimo->proximo = *cabeca; // atualiza o valor do proximo do ultimo elemento para apontar para a head
        free(temp);
    }
    else // remover um no no meio ou fim da lista
    {
        anterior->proximo = temp->proximo; // atualiza o nó anterior (proximo) para que aponte corretamente para o novo nó temp(proximo)
        free(temp);
    }
}

void clist_get(CNode **cabeca, int chave)
{
    if (!*cabeca)
        return;

    CNode *atual = *cabeca;
    do
    {
        if (atual->dado == chave)
        {
            printf("Valor %d esta presente na lista circular\n", chave);
            return;
        }
        atual = atual->proximo;
    } while (atual != *cabeca);
    printf("Valor %d nao esta presente na lista circular\n", chave);
}

void clist_exibir(CNode **cabeca)
{
    if (!*cabeca)
    {
        printf("Lista circular vazia\n");
        return;
    }
    CNode *atual = *cabeca;
    do
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    } while (atual != *cabeca);
    printf("\n");
}

