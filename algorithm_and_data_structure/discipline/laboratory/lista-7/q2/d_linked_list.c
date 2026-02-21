#include <stdio.h>
#include <stdlib.h>

#include "d_linked_list.h"

Dnode *dlist_create_dnode(int valor)
{
    Dnode *novo = (Dnode *)malloc(sizeof(Dnode));
    if (novo)
    {
        novo->dado = valor;
        novo->anterior = NULL;
        novo->proximo = NULL;
    }
    return novo;
}

void dlist_insert_init(Dnode **cabeca, int valor)
{
    Dnode *novo = dlist_create_dnode(valor);
    if (!*cabeca) // Se não existir
    {
        *cabeca = novo;
        return;
    }
    novo->proximo = *cabeca; // a antiga cabeça será movida, sendo o valor de proximo da nova cabeça (novo)
    (*cabeca)->anterior = novo;  // o valor anterior da antiga cabeça é o novo
    *cabeca = novo; // a cabeça passa a ser o novo elemento inserido
}

void dlist_insert_end(Dnode **cabeca, int valor)
{
    Dnode *novo = dlist_create_dnode(valor);
    if (!*cabeca) // se não existir
    {
        *cabeca = novo;
        return;
    }
    Dnode *atual = *cabeca;
    while (atual->proximo) // enquanto tiver elementos na sequencia, atualize o atual
    {
        atual = atual->proximo;
    }
    atual->proximo = novo; // o ultimo elemento(atual), terá o valor proximo atualizado, apontado para novo
    novo->anterior = atual; // e novo, passa a ter como elemento anterior o antigo ultimo elemento(atual)
}

void dlist_remove_dnode(Dnode **cabeca, int chave)
{
    if (!*cabeca)
        return;

    Dnode *atual = *cabeca;
    while (atual && atual->dado != chave)
    {
        atual = atual->proximo;
    }

    if (!atual)
        return; // Não encontrou

    if (atual->anterior) 
    {
        atual->anterior->proximo = atual->proximo; // como atual será removido, o elemento anterior a atual precisa ser acessado e ter seu valor atualizado
        // anterior->proximo = atual->proximo
    }
    else
    { // É o primeiro nó
        *cabeca = atual->proximo;
    }

    if (atual->proximo)
    {
        atual->proximo->anterior = atual->anterior; // da mesma forma, o elemento próximo precisa ter o seu ponteiro anterior atualizado
        // proximo->anterior = atual->anterior
    }

    free(atual);
}

void dlist_get(Dnode **cabeca, int chave)
{
    if (!*cabeca)
        return;

    Dnode *temp = *cabeca;
    while (temp && temp->dado != chave)
    {
        temp = temp->proximo;
    }

    if (!temp)
    {
        printf("Valor %d nao esta presente na lista dupla\n", chave);
    }
    else
    {
        printf("Valor %d esta presente na lista dupla\n", chave);
    }
}

void dlist_exibir(Dnode **cabeca)
{
    if (!*cabeca)
    {
        printf("Lista dupla vazia\n");
        return;
    }
    Dnode *atual = *cabeca;
    while (atual)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

