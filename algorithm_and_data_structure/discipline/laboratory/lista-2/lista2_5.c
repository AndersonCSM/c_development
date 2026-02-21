#include <stdio.h>
int main()
{
    int x, *p, **q; // **q é um ponteiro para um ponteiro de int
    p = &x;         // p recebe o endereço de x
    q = &p;         // q recebe o endereço do ponteiro p. Ou seja, q aponta para p, que aponta para x.
    x = 10;
    printf("%d\n", **q);
    return 0;
}
