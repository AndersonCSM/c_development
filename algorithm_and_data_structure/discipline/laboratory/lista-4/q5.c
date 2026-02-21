#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    FILE *arq = fopen("texto.txt", "r");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo alunos.txt");
        return 1;
    }

    long tot_char = 0;
    long vogais = 0;
    long consoantes = 0;
    long outros = 0;
    int ch_int; // fgetc retorna int para poder representar EOF

    // Loop para ler caractere a caractere ateo fim do arquivo (EOF)
    while ((ch_int = fgetc(arq)) != EOF)
    {
        tot_char++; // Incrementa o total de caracteres lidos

        char ch = (char)ch_int;      // Converte o int lido para char
        char ch_lower = tolower(ch); // Converte para minusculo

        if (isalpha(ch_lower)) // Verifica se e uma letra do alfabeto
        {
            if (ch_lower == 'a' || ch_lower == 'e' || ch_lower == 'i' || ch_lower == 'o' || ch_lower == 'u')
            {
                vogais++;
            }
            else
            {
                consoantes++;
            }
        }
        else if (ch_lower != ' ')
        {
            outros++;
        }
    }

    fclose(arq);

    printf("Total de caracteres: %ld\n", tot_char);
    printf("Vogais: %ld\n", vogais);
    printf("Consoantes: %ld\n", consoantes);
    printf("Outros caracteres: %ld\n", outros);

    return 0;
}