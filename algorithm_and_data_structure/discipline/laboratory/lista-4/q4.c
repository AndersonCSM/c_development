#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    // setlocale(LC_ALL, "Portuguese"); // o uso do setlocale muda o caractere marcado do tipo float ao ler um arquivo, isso interfere no código

    FILE *arq_inp = fopen("alunos.txt", "r");
    FILE *arq_out = fopen("alunos_status.txt", "w");

    if (arq_inp == NULL)
    {
        perror("Erro ao abrir o arquivo de entrada (alunos.txt)");
        return 1;
    }
    if (arq_out == NULL)
    {
        perror("Erro ao abrir o arquivo de saída (alunos_situacao.txt)");
        return 1;
    }

    char nome[100];
    float n1 = 0, n2 = 0, n3 = 0;
    float media = 0;
    char situacao[20];

    while (fscanf(arq_inp, "%99s %f %f %f", nome, &n1, &n2, &n3) == 4)
    {
        media = (n1 + n2 + n3) / 3.0;

        if (media >= 7.0)
        {
            strcpy(situacao, "Aprovado"); // copiar string
        }
        else if (media >= 3.0 && media < 7.0)
        {
            strcpy(situacao, "Quarta prova"); // copiar string
        }
        else
        {
            strcpy(situacao, "Reprovado"); // copiar string
        }

        // Escreve os dados lidos e a situacao calculada no arquivo de SAIDA
        fprintf(arq_out, "%-20s %-15s\n", nome, situacao);
    }

    fclose(arq_inp);
    fclose(arq_out);

    return 0;
}