#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a + b;
}

int prod(int a, int b)
{
    return a * b;
}

double median(double n1, double n2, double n3)
{
    return (n1 + n2 + n3) / 3;
}

void swap(int *n1, int *n2)
{
    int aux = 0;

    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

int main()
{
    int n1 = 5;
    int n2 = 10;

    printf("%d \n", n1);
    printf("%d \n", n2);
    printf("\n");

    swap(&n1, &n2);

    printf("%d \n", n1);
    printf("%d \n", n2);
    printf("\n");

    int (*ptr)(int, int) = sum;
    printf("soma: %d\n", ptr(n1, n2));
    ptr = prod;
    printf("soma: %d\n", ptr(n1, n2));

    double (*ptr2)(double, double, double) = median;

    return 0;
}