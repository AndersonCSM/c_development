#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome_arquivo[100];
    char palavra[100];
    char target[100];
    int encontrada = 0;

    printf("Nome do arquivo: ");
    fgets(nome_arquivo, sizeof(nome_arquivo), stdin); // Remove o caractere de nova linha, se presente
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;

    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    else
    {
        printf("Palavra: ");
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\n")] = 0;

        while (fscanf(arq, "%99s", target) != EOF)
        {
            if (strcspn(palavra, target) == 0)
            {
                printf("A palavra \"%s\" está presente no texto", palavra);
                encontrada = 1;
                break;
            }
        }
    }

    if (!encontrada) // Se a flag ainda for falsa após o loop
    {
        printf("A palavra \"%s\" NÃO está presente no texto.\n", palavra);
    }

    fclose(arq);
    return 0;
}