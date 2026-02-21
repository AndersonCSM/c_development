#include <stdio.h>

#include "catalogo.h" 

int main()
{
    CatalogoNode *catalogo = NULL;

    catalogo_adicionar(&catalogo, "Matrix", 1999, "Ficcao Cientifica");
    catalogo_adicionar(&catalogo, "O Poderoso Chefao", 1972, "Drama");
    catalogo_adicionar(&catalogo, "Interestelar", 2014, "Ficcao Cientifica");
    catalogo_adicionar(&catalogo, "Parasita", 2019, "Suspense");
    catalogo_adicionar(&catalogo, "A Origem", 2010, "Ficcao Cientifica");
    catalogo_adicionar(&catalogo, "Forrest Gump", 1994, "Drama");

    catalogo_exibir_todos(catalogo);

    catalogo_buscar_por_categoria(catalogo, "Ficcao Cientifica");
    catalogo_buscar_por_categoria(catalogo, "Drama");
    catalogo_buscar_por_categoria(catalogo, "Comedia"); // Categoria não existe

    catalogo_listar_ordenado_por_ano(catalogo);

    // Libera toda a memória
    catalogo_liberar(&catalogo);

    return 0;
}
