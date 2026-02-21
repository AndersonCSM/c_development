#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo = fopen("pescado.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char nome[100];
    int peso = 0, comprimento = 0;
    int peso_tot = 0;

    // Cabeçalho da tabela formatado
    printf("%-20s | %-10s | %-18s\n", "Nome do Peixe", "Peso (g)", "Comprimento (cm)");
    printf("=====================|============|====================\n");
    while (fscanf(arquivo, "%99s %d %d", nome, &peso, &comprimento) == 3)
    {
        peso_tot += peso;
        printf("%-20s | %-10d | %-18d\n", nome, peso, comprimento);
    }

    fclose(arquivo);

    printf("=====================|============|====================\n");
    printf("\n");

    fclose(arquivo);

    printf("Peso total: %.2f kg\n", peso_tot / 1000.00);
    return 0;
}