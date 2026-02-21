#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct peixe
{
    char nome[20];
    unsigned peso;
    float comp;
};

// CREATE: Adiciona um peixe ao final do arquivo binário.
int adicionar_peixe_arquivo(const char *filename, struct peixe p)
{
    FILE *arq = fopen(filename, "ab");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo binário para escrita (adicionar_peixe_arquivo)");
        fprintf(stderr, "Arquivo: %s\n", filename);
        return -1;
    }

    size_t escritos = fwrite(&p, sizeof(struct peixe), 1, arq);
    fclose(arq);

    if (escritos < 1)
    {
        perror("Erro ao escrever peixe no arquivo binário");
        return -1;
    }
    return 0;
}

// READ: Lê e exibe todos os peixes do arquivo binário.
int exibir_todos_os_peixes_do_arquivo(const char *filename)
{
    FILE *arq = fopen(filename, "rb");
    if (arq == NULL)
    {
        printf("\n--- Peixes Cadastrados (Arquivo Binário) ---\n");
        printf("Nenhum peixe cadastrado no arquivo binário (ou arquivo inacessível).\n");
        printf("--------------------------------------------\n");
        return 0;
    }

    struct peixe p_temp;
    int contador = 0;
    printf("\n--- Peixes Cadastrados (Arquivo Binário) ---\n");
    while (fread(&p_temp, sizeof(struct peixe), 1, arq) == 1)
    {
        printf("Nome: %-20s | Peso: %5u g | Comprimento: %5.2f cm\n",
               p_temp.nome, p_temp.peso, p_temp.comp);
        contador++;
    }
    fclose(arq);

    if (contador == 0)
    {
        printf("Nenhum peixe cadastrado no arquivo binário.\n");
    }
    printf("--------------------------------------------\n");
    return contador;
}

int write_txt_to_bin(const char *filetxt, const char *filebin)
{
    struct peixe p_temp;
    int peixes_lidos_txt = 0;

    FILE *arq_txt = fopen(filetxt, "r");
    if (arq_txt == NULL)
    {
        perror("Erro ao abrir o arquivo texto para leitura");
        fprintf(stderr, "Arquivo: %s\n", filetxt);
        return -1;
    }

    while (fscanf(arq_txt, " %19s %u %f", p_temp.nome, &p_temp.peso, &p_temp.comp) == 3)
    {
        if (adicionar_peixe_arquivo(filebin, p_temp) != 0)
        {
            fprintf(stderr, "Erro ao adicionar o peixe '%s' ao arquivo binário.\n", p_temp.nome);
            fclose(arq_txt);
            return -2;
        }
        peixes_lidos_txt++;
    }

    fclose(arq_txt);

    if (peixes_lidos_txt > 0)
    {
        printf("%d peixe(s) repassado(s) do arquivo texto para o arquivo binario!\n", peixes_lidos_txt);
    }

    return peixes_lidos_txt;
}

long size_file(const char *filename)
{
    FILE *arq = fopen(filename, "rb");
    if (arq == NULL)
    {
        return -1;
    }
    fseek(arq, 0, SEEK_END);
    long tamanho = ftell(arq);
    fclose(arq);
    return tamanho;
}

int main()
{
    // REMOVIDO: setlocale(LC_ALL, "Portuguese");
    // O programa agora usará o locale padrão "C".
    // Para acentuação correta no console Windows, execute 'chcp 65001' antes de rodar o programa.

    char nome_arquivo_bin[100] = "peixes.bin";
    char nome_arquivo_txt[100] = "peixes.txt";

    exibir_todos_os_peixes_do_arquivo(nome_arquivo_bin);
    int num_processados = write_txt_to_bin(nome_arquivo_txt, nome_arquivo_bin);
    exibir_todos_os_peixes_do_arquivo(nome_arquivo_bin);


    long size_txt = size_file(nome_arquivo_txt);
    long size_bin = size_file(nome_arquivo_bin);

    printf("Tamanho do arquivo texto ('%s'): %ld bytes\n", nome_arquivo_txt, size_txt);
    printf("Tamanho do arquivo binário ('%s'): %ld bytes\n", nome_arquivo_bin, size_bin);

    return 0;
}