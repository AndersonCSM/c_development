#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct SNode {
    int data;
    struct SNode* next;
} SNode;

// Protótipos com os novos nomes
void slist_insert_init(SNode **cabeca, int valor);
void slist_insert_end(SNode **cabeca, int valor);
void slist_pop_node(SNode **cabeca, int chave);
void slist_get(SNode **cabeca, int chave);
void slist_exibir(SNode **cabeca);

#endif