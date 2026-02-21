#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    FILE *fin, *fout;
    char palavra[256];
    char *endptr; // Para strtol, aponta para o primeiro caractere não convertido
    long num;

    fin = fopen("q2_input.txt", "r");
    fout = fopen("q2_output.txt", "w");

    // Loop para ler as palavras(sequências de caracteres separadas por espaço/nova linha)
    while (fscanf(fin, "%255s", palavra) == 1)
    {
        num = strtol(palavra, &endptr, 10); // Tenta converter a 'palavra' para long int strtol(palavra, ponteiro parao o 1 caractere que não converte, base decimal)

        // 1. endptr != palavra: Garante que pelo menos um caractere foi processado por strtol. Se nenhum caractere pudesse formar um número, endptr seria igual a palavra.
        // 2. *endptr == '\0': Garante que strtol processou a string 'palavra' inteira, ou seja, não havia caracteres não numéricos após a parte numérica.
        if (endptr != palavra && *endptr == '\0')
        {
            fprintf(fout, "%ld\n", num);
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}