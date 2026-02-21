#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");

    FILE *fin;
    fin = fopen("intro.txt", "r");

    char linha[256];

    while (fgets(linha, sizeof(linha), fin) != NULL)
    {
        printf("%s\n", linha);
    }
    fclose(fin);
    return 0;
}