#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Funcao para obter o tamanho de um arquivo em bytes
long size_file(const char *filename)
{
    FILE *f = fopen(filename, "rb"); // Abrir em modo bin�rio para obter o tamanho corretamente
    if (f == NULL)
    {
        perror("Erro ao abrir arquivo para obter tamanho");
        fprintf(stderr, "Arquivo: %s\n", filename);
        return -1;
    }
    fseek(f, 0, SEEK_END);   // Vai para o final do arquivo
    long tamanho = ftell(f); // Pega a posi��o atual (tamanho)
    fclose(f);
    return tamanho;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    const char *arquivo_texto_nome = "naturais.txt";
    const char *arquivo_binario_nome = "naturais.bin";

    FILE *arq_texto;
    FILE *arq_binario;
    int i;
    int n_bin;

    arq_texto = fopen(arquivo_texto_nome, "w");
    if (arq_texto == NULL)
    {
        perror("Erro ao criar/abrir o arquivo texto para escrita");
        return 1;
    }

    arq_binario = fopen(arquivo_binario_nome, "wb");
    if (arq_binario == NULL)
    {
        perror("Erro ao criar/abrir o arquivo bin�rio para escrita");
        fclose(arq_texto);
        return 1;
    }

    for (i = 1; i <= 100; i++)
    {
        if (fprintf(arq_texto, "%d\n", i) < 0)
        { // se for bem sucedido, o num tot de caracteres sempre ser� maior que 0 e n�o entrar� no if
            fprintf(stderr, "Erro ao escrever no arquivo texto.\n");
            fclose(arq_texto);
            fclose(arq_binario);
            return 1;
        }

        n_bin = i; // Atribui o valor de i
        if (fwrite(&n_bin, sizeof(int), 1, arq_binario) != 1)
        { // se for bem sucedido retornar� 1 e n�o entrar� no if
            fprintf(stderr, "Erro ao escrever no arquivo bin�rio.\n");
            fclose(arq_texto);
            fclose(arq_binario);
            return 1;
        }
    }

    printf("Grava��o conclu�da.\n\n");

    fclose(arq_texto);
    fclose(arq_binario);

    // Comparar os tamanhos dos arquivos
    long tamanho_texto = size_file(arquivo_texto_nome);
    long tamanho_binario = size_file(arquivo_binario_nome);

    printf("Tamanho do arquivo texto: %ld bytes\n", tamanho_texto);
    printf("Tamanho do arquivo bin�rio: %ld bytes\n", tamanho_binario);

    return 0;
}