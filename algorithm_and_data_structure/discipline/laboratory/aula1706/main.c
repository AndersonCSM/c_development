#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main()
{
    Pessoa *p = cria_pessoa("Guilherme Luva", 21);

    Pessoa *p2 = cria_pessoa("Guilherme M", 20);

    imprime_pessoa(p);
    imprime_pessoa(p2);

    editar_pessoa(p2, "Big dog", 23);

    imprime_pessoa(p2);

    free(p);
    free(p2);
    return 0;
}