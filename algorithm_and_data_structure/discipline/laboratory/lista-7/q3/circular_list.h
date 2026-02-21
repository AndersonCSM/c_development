#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

typedef struct CNode {
    int dado;
    struct CNode* proximo;
} CNode;

void clist_insert_init(CNode **cabeca, int valor);
void clist_insert_end(CNode **cabeca, int valor);
void clist_pop_node(CNode **cabeca, int chave);
void clist_get(CNode **cabeca, int chave);
void clist_exibir(CNode **cabeca);

#endif