#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    const char *filename = "vet.dat";
    FILE *arq;
    int numeros[100];
    int cont = 0;
    int num;

    arq = fopen(filename, "rb");
    if (arq != NULL)
    {
        int qtd;
        if (fread(&qtd, sizeof(int), 1, arq) == 1) // já avança o ponteiro do arq binário
        {
            if (qtd > 0)
            {
                printf("O arq vet.dat contém:\n");

                int numero_lido;
                for (int i = 0; i < qtd; i++)
                {
                    if (fread(&numero_lido, sizeof(int), 1, arq) == 1) // ponteiro já leu o inteiro responsável pela quantidade de elementos
                    {
                        printf("%d ", numero_lido);
                    }
                    else
                    {
                        fprintf(stderr, "Erro ao ler dado do arq %s existente.\n", filename);
                        break;
                    }
                }
                printf("\n");
            }
        }
        fclose(arq);
    }

    // Se arq == NULL
    printf("Digite números (zero para encerrar):\n");
    while (cont < 100)
    {
        if (scanf("%d", &num) != 1) // concatenado para tratamento de entrada -> mais otimizado que as versões anteriores
        {
            printf("Entrada inválida. Por favor, digite um número inteiro.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (num == 0)
        {
            break;
        }

        numeros[cont] = num;
        cont++;
    }

    arq = fopen(filename, "wb");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arq vet.dat para escrita");
        return 1;
    }

    // Escreve a quantidade de números (pode ser 0 se nenhum número válido foi digitado)
    if (fwrite(&cont, sizeof(int), 1, arq) != 1) // já avança o ponteiro do arq binário
    {
        fprintf(stderr, "Erro ao escrever a quantidade no arq %s.\n", filename);
        fclose(arq);
        return 1;
    }

    for (int i = 0; i < cont; i++)
    {
        if (fwrite(&numeros[i], sizeof(int), 1, arq) != 1)
        {
            fprintf(stderr, "Erro ao escrever o número %d no arq %s.\n", i + 1, filename);
            fclose(arq);
            return 1;
        }
    }

    printf("%d números foram armazenados em vet.dat.\n", cont);
    fclose(arq);

    return 0;
}
