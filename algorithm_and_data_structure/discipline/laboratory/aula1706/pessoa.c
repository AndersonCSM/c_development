#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include <string.h>

struct pessoa
{
    char nome[50];
    int idade;
};

Pessoa *cria_pessoa(char nome[50], int idade)
{
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
    p->idade = idade;
    strcpy(p->nome, nome);
    return p;
}

void imprime_pessoa(Pessoa *p)
{
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
}

void editar_pessoa(Pessoa *p, char nome[50], int idade)
{
    if (idade > 0)
    {
        p->idade = idade;
    }

    if (nome != NULL)
    {
        strcpy(p->nome, nome);
    }
}