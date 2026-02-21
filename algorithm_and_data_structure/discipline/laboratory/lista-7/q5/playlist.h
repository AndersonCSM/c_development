#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct
{
    char titulo[101];
    char artista[101];
    int duracao_segundos;
} Music;

typedef struct PlaylistNode
{
    Music dados;
    struct PlaylistNode *proximo;
    struct PlaylistNode *anterior;
} PlaylistNode;

// Estrutura que gerencia a playlist
typedef struct
{
    PlaylistNode *atual; // Ponteiro para a música "tocando" no momento
    int tamanho;         // Número de músicas na playlist
} Playlist;

Playlist *playlist_criar();

void playlist_adicionar_musica(Playlist *playlist, const char *titulo, const char *artista, int duracao);
void playlist_remover_musica(Playlist *playlist, const char *titulo);
void playlist_exibir(Playlist *playlist);

void playlist_reorganizar(Playlist *playlist, const char *titulo_movido, int nova_posicao);
void playlist_tocar_proxima(Playlist *playlist);
void playlist_tocar_anterior(Playlist *playlist);

void playlist_liberar(Playlist **playlist);

#endif