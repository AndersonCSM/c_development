#include <stdio.h>

#include "playlist.h"

int main()
{
    Playlist *minha_playlist = playlist_criar();

    playlist_adicionar_musica(minha_playlist, "Bohemian Rhapsody", "Queen", 355);
    playlist_adicionar_musica(minha_playlist, "Stairway to Heaven", "Led Zeppelin", 482);
    playlist_adicionar_musica(minha_playlist, "Hotel California", "Eagles", 391);
    playlist_adicionar_musica(minha_playlist, "Like a Rolling Stone", "Bob Dylan", 369);
    playlist_adicionar_musica(minha_playlist, "Smells Like Teen Spirit", "Nirvana", 301);

    playlist_exibir(minha_playlist);

    // Navegando na playlist
    playlist_tocar_proxima(minha_playlist);
    playlist_exibir(minha_playlist);

    playlist_tocar_anterior(minha_playlist);
    playlist_tocar_anterior(minha_playlist);
    playlist_exibir(minha_playlist);

    printf("\n");
    playlist_remover_musica(minha_playlist, "Hotel California");
    playlist_exibir(minha_playlist);

    printf("\n");
    playlist_reorganizar(minha_playlist, "Bohemian Rhapsody", 4);
    playlist_exibir(minha_playlist);

    playlist_liberar(&minha_playlist);

    return 0;
}
