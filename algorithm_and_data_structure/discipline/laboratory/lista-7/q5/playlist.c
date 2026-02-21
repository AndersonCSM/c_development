
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "playlist.h"

Playlist *playlist_criar()
{
    Playlist *nova_playlist = (Playlist *)malloc(sizeof(Playlist));
    if (nova_playlist)
    {
        nova_playlist->atual = NULL;
        nova_playlist->tamanho = 0;
    }
    return nova_playlist;
}

void playlist_adicionar_musica(Playlist *playlist, const char *titulo, const char *artista, int duracao)
{
    PlaylistNode *novo_no = (PlaylistNode *)malloc(sizeof(PlaylistNode));
    if (!novo_no)
        return;

    strncpy(novo_no->dados.titulo, titulo, 100);
    strncpy(novo_no->dados.artista, artista, 100);
    novo_no->dados.duracao_segundos = duracao;

    if (playlist->atual == NULL) // Playlist vazia
    {
        novo_no->proximo = novo_no;
        novo_no->anterior = novo_no;
        playlist->atual = novo_no;
    }
    else // Insere antes do nó atual
    {
        PlaylistNode *ultimo = playlist->atual->anterior;

        ultimo->proximo = novo_no;
        novo_no->anterior = ultimo;
        novo_no->proximo = playlist->atual;
        playlist->atual->anterior = novo_no;
    }
    playlist->tamanho++;
}

void playlist_remover_musica(Playlist *playlist, const char *titulo)
{
    if (playlist->atual == NULL)
        return;

    PlaylistNode *no_para_remover = playlist->atual;
    for (int i = 0; i < playlist->tamanho; i++)
    {
        if (strcmp(no_para_remover->dados.titulo, titulo) == 0)
        {
            if (playlist->tamanho == 1)
            {
                playlist->atual = NULL;
            }
            else
            {
                no_para_remover->anterior->proximo = no_para_remover->proximo;
                no_para_remover->proximo->anterior = no_para_remover->anterior;
                if (playlist->atual == no_para_remover)
                {
                    playlist->atual = no_para_remover->proximo;
                }
            }
            free(no_para_remover);
            playlist->tamanho--;
            printf("Musica '%s' removida.\n", titulo);
            return;
        }
        no_para_remover = no_para_remover->proximo;
    }
    printf("Musica '%s' nao encontrada.\n", titulo);
}

void playlist_exibir(Playlist *playlist)
{
    printf("\n--- Playlist Atual (%d musicas) ---\n", playlist->tamanho);
    if (playlist->atual == NULL)
    {
        printf("Playlist vazia.\n");
        return;
    }

    PlaylistNode *temp = playlist->atual;
    for (int i = 0; i < playlist->tamanho; i++)
    {
        printf("%d. '%s' - %s (%d s)", i + 1, temp->dados.titulo, temp->dados.artista, temp->dados.duracao_segundos);
        if (temp == playlist->atual)
        {
            printf(" <-- TOCANDO AGORA\n");
        }
        else
        {
            printf("\n");
        }
        temp = temp->proximo;
    }
}

void playlist_reorganizar(Playlist *playlist, const char *titulo_movido, int nova_posicao)
{
    if (playlist->tamanho <= 1 || nova_posicao < 1 || nova_posicao > playlist->tamanho)
    {
        printf("Nao e possivel reorganizar.\n");
        return;
    }

    // Encontrar o nó a ser movido
    PlaylistNode *no_movido = NULL;
    PlaylistNode *temp = playlist->atual;
    for (int i = 0; i < playlist->tamanho; i++)
    {
        if (strcmp(temp->dados.titulo, titulo_movido) == 0)
        {
            no_movido = temp;
            break;
        }
        temp = temp->proximo;
    }

    if (!no_movido)
    {
        printf("Musica '%s' nao encontrada para mover.\n", titulo_movido);
        return;
    }

    // Desconectar o nó da lista
    no_movido->anterior->proximo = no_movido->proximo;
    no_movido->proximo->anterior = no_movido->anterior;
    if (playlist->atual == no_movido)
        playlist->atual = no_movido->proximo;

    // Encontrar a nova posição e reconectar
    PlaylistNode *no_alvo = playlist->atual;
    for (int i = 1; i < nova_posicao; i++)
    {
        no_alvo = no_alvo->proximo;
    }

    PlaylistNode *anterior_alvo = no_alvo->anterior;
    anterior_alvo->proximo = no_movido;
    no_movido->anterior = anterior_alvo;
    no_movido->proximo = no_alvo;
    no_alvo->anterior = no_movido;

    printf("Musica '%s' movida para a posicao %d.\n", titulo_movido, nova_posicao);
}

void playlist_tocar_proxima(Playlist *playlist)
{
    if (playlist->atual)
    {
        playlist->atual = playlist->atual->proximo;
    }
}

void playlist_tocar_anterior(Playlist *playlist)
{
    if (playlist->atual)
    {
        playlist->atual = playlist->atual->anterior;
    }
}

void playlist_liberar(Playlist **playlist_ptr)
{
    if (!(*playlist_ptr) || !(*playlist_ptr)->atual)
    {
        free(*playlist_ptr);
        *playlist_ptr = NULL;
        return;
    }

    PlaylistNode *atual = (*playlist_ptr)->atual;
    PlaylistNode *proximo;
    for (int i = 0; i < (*playlist_ptr)->tamanho; i++)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(*playlist_ptr);
    *playlist_ptr = NULL;
}
