#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

typedef struct Dnode{
    int dado;
    struct Dnode* anterior;
    struct Dnode* proximo;
} Dnode;

void dlist_insert_init(Dnode** cabeca, int valor);
void dlist_insert_end(Dnode** cabeca, int valor);
void dlist_remove_dnode(Dnode** cabeca, int chave);
void dlist_get(Dnode** cabeca, int chave);
void dlist_exibir(Dnode** cabeca);

#endif