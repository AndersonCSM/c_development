#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");

    FILE *fin;
    fin = fopen("intro.txt", "r");

    char palavra[100];
    
    fscanf(fin, "%99s", palavra);
    fclose(fin);
    printf("%s\n", palavra);
    return 0;
}