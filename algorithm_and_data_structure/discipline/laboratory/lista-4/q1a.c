#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");

    FILE *fin;
    fin = fopen("intro.txt", "r");

    char ch;

    fseek(fin, 7, SEEK_SET);
    fscanf(fin, "%c", &ch);
    fclose(fin);
    printf("%c\n", ch);
    return 0;
}