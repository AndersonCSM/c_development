#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define TAMANHO_MAX_PALAVRA 100

// Mantendo o nome da sua funcao
int check_palindromo(const char *word)
{
    if (word == NULL)
    {
        return 0;
    }
    int ini = 0;
    int fim = strlen(word) - 1;

    while (ini < fim)
    {
        char char_i = tolower((unsigned char)word[ini]);
        char char_f = tolower((unsigned char)word[fim]);

        if (char_i != char_f)
        {
            return 0; // Nao e palindromo
        }
        ini++;
        fim--;
    }
    return 1; // E palindromo
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int qtd = 0;
    char nome_arquivo[100] = "texto3.txt";
    char palavra[TAMANHO_MAX_PALAVRA]; // Buffer para ler cada palavra

    // Array dinamico para armazenar as palavras palindromo encontradas
    char (*lista_palindromos)[TAMANHO_MAX_PALAVRA] = NULL;
    int capacidade_lista = 0; // Capacidade atual do array lista_palindromos

    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo");
        fprintf(stderr, "Arquivo: %s\n", nome_arquivo);
        return 1;
    }

    // Le palavras do arquivo uma por uma
    while (fscanf(arq, "%99s", palavra) == 1)
    {
        if (check_palindromo(palavra))
        {
            qtd++;

            // Realoca o array lista_palindromos se necess�rio
            if (qtd > capacidade_lista)
            {
                int n = (capacidade_lista == 0) ? 10 : capacidade_lista * 2;

                // Ajusta o tipo do ponteiro tempor�rio e o sizeof para realloc
                char (*temp)[TAMANHO_MAX_PALAVRA] = realloc(lista_palindromos, n * sizeof(char[TAMANHO_MAX_PALAVRA]));

                if (temp == NULL)
                {
                    perror("Erro ao realocar mem�ria para lista de pal�ndromos");
                    free(lista_palindromos); // Libera o bloco anterior, se houver
                    fclose(arq);
                    return 1;
                }
                lista_palindromos = temp;
                capacidade_lista = n;
            }

            // Copia a palavra pal�ndromo para a lista
            strcpy(lista_palindromos[qtd - 1], palavra);
        }
    }
    fclose(arq);

    printf("Arquivo: %s\n", nome_arquivo);
    if (qtd > 0)
    {
        printf("Pal�ndromos encontrados:\n");
        for (int i = 0; i < qtd; i++)
        {
            printf("- %s\n", lista_palindromos[i]);
        }
    }
    printf("Foram encontrados %d pal�ndromos neste arquivo.\n", qtd);

    free(lista_palindromos);

    return 0;
}