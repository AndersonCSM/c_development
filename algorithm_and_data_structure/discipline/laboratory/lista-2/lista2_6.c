#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char ltr = 'A';
    char *ptr = &ltr;

    *ptr = 'B';

    printf("%c\n", ltr);
    printf("%c\n", *ptr);

    return 0;
}
