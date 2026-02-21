#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return 1;
    }
    *ptr = 100;

    printf("Conteúdo do ponteiro: %d\n", *ptr);

    printf("Informe um novo valor inteiro para o ponteiro: \n");
    scanf("%d", ptr);

    printf("Conteúdo do ponteiro: %d\n", *ptr);

    free(ptr);
    return 0;
}
