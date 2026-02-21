#ifndef CATALOG_H
#define CATALOG_H

// Estrutura para armazenar os dados de um filme
typedef struct
{
    char nome[101]; // 100 caracteres + 1 para o terminador nulo
    int ano;
    char categoria[51]; // 50 caracteres + 1 para o terminador nulo
} Filme;

// O nó da nossa lista encadeada,
typedef struct CatalogoNode
{
    Filme dados;
    struct CatalogoNode *proximo;
} CatalogoNode;

void catalogo_adicionar(CatalogoNode **cabeca, const char *nome, int ano, const char *categoria); // Adiciona um novo título ao catálogo (no início da lista)
void catalogo_buscar_por_categoria(CatalogoNode *cabeca, const char *categoria); // Busca e exibe todos os títulos de uma determinada categoria
void catalogo_listar_ordenado_por_ano(CatalogoNode *cabeca); // Cria uma cópia da lista, ordena e exibe os títulos por ano de lançamento
void catalogo_exibir_todos(CatalogoNode *cabeca);
void catalogo_liberar(CatalogoNode **cabeca);

#endif