#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");

    FILE *fin;
    fin = fopen("intro.txt", "r");

    char ch;

    fscanf(fin, "%c", &ch);
    fclose(fin);
    printf("%c\n", ch);
    return 0;

    return 0;
}