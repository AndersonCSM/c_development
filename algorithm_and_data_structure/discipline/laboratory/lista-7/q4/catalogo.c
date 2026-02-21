#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "catalogo.h"

// Função para criar um novo nó do catálogo
CatalogoNode *catalogo_criar_no(const char *nome, int ano, const char *categoria)
{
    CatalogoNode *novo_no = (CatalogoNode *)malloc(sizeof(CatalogoNode));
    if (!novo_no)
    {
        printf("Erro de alocacao de memoria!\n");
        return NULL;
    }

    // Copia os dados para a estrutura do novo nó
    strncpy(novo_no->dados.nome, nome, 100);
    novo_no->dados.nome[100] = '\0';

    novo_no->dados.ano = ano;

    strncpy(novo_no->dados.categoria, categoria, 50);
    novo_no->dados.categoria[50] = '\0';

    novo_no->proximo = NULL;
    return novo_no;
}

void catalogo_adicionar(CatalogoNode **cabeca, const char *nome, int ano, const char *categoria)
{
    CatalogoNode *novo_no = catalogo_criar_no(nome, ano, categoria);
    if (novo_no)
    {
        novo_no->proximo = *cabeca;
        *cabeca = novo_no;
    }
}

// Buscar por categoria
void catalogo_buscar_por_categoria(CatalogoNode *cabeca, const char *categoria)
{
    printf("\nBuscando titulos na categoria: %s\n", categoria);

    CatalogoNode *atual = cabeca;
    int encontrados = 0;

    while (atual != NULL)
    {
        if (strcmp(atual->dados.categoria, categoria) == 0)
        {
            printf("  - Nome: %s, Ano: %d\n", atual->dados.nome, atual->dados.ano);
            encontrados++;
        }
        atual = atual->proximo;
    }

    if (encontrados == 0)
    {
        printf("Nenhum titulo encontrado nesta categoria.\n");
    }
}

// ordenar por ano
int comparar_titulos_por_ano(const void *a, const void *b)
{
    Filme *tituloA = (Filme *)a;
    Filme *tituloB = (Filme *)b;
    return (tituloA->ano - tituloB->ano); // Ordem crescente
}

// Listar os títulos ordenados pelo ano de lançamento
void catalogo_listar_ordenado_por_ano(CatalogoNode *cabeca)
{
    printf("\nCatalogo ordenado por ano de lancamento\n");
    if (!cabeca)
    {
        return;
    }

    // Contar o número de elementos na lista
    int contador = 0;
    CatalogoNode *atual = cabeca;

    while (atual != NULL)
    {
        contador++;
        atual = atual->proximo;
    }

    // Criar um array de Títulos para armazenar os dados
    Filme *array_titulos = (Filme *)malloc(contador * sizeof(Filme));

    if (!array_titulos)
    {
        printf("Erro de alocacao de memoria para ordenacao!\n");
        return;
    }

    // Copiar os dados da lista para o array
    atual = cabeca;
    for (int i = 0; i < contador; i++)
    {
        array_titulos[i] = atual->dados;
        atual = atual->proximo;
    }

    // Ordenar o array usando a função qsort da biblioteca padrão
    qsort(array_titulos, contador, sizeof(Filme), comparar_titulos_por_ano);

    // Exibir o array ordenado
    for (int i = 0; i < contador; i++)
    {
        printf("  - Ano: %d, Nome: %s, Categoria: %s\n",
               array_titulos[i].ano,
               array_titulos[i].nome,
               array_titulos[i].categoria);
    }

    free(array_titulos);
}

// exibir a lista completa
void catalogo_exibir_todos(CatalogoNode *cabeca)
{
    printf("\nCatalogo Completo\n");

    CatalogoNode *atual = cabeca;
    if (!atual)
    {
        return;
    }
    while (atual != NULL)
    {
        printf("  - Nome: %s, Ano: %d, Categoria: %s\n",
               atual->dados.nome, atual->dados.ano, atual->dados.categoria);

        atual = atual->proximo;
    }
}

// Função auxiliar para liberar a memória
void catalogo_liberar(CatalogoNode **cabeca)
{
    CatalogoNode *atual = *cabeca;
    CatalogoNode *proximo_no;
    while (atual != NULL)
    {
        proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
    *cabeca = NULL;
}

