#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct peixe
{
    char nome[20];
    unsigned peso;
    float comp;
};

// CREATE: Adiciona um peixe ao final do arquivo binario.
// Retorna 0 em sucesso, -1 em erro.
int adicionar_peixe_arquivo(const char *filename, struct peixe p)
{
    FILE *arq = fopen(filename, "ab");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo para escrita");
        fprintf(stderr, "Arquivo: %s\n", filename);
        return -1;
    }

    size_t escritos = fwrite(&p, sizeof(struct peixe), 1, arq);
    fclose(arq);

    if (escritos < 1)
    {
        perror("Erro ao escrever peixe no arquivo");
        return -1;
    }
    return 0;
}

// READ: Le e exibe todos os peixes do arquivo binario.
// Retorna o número de peixes lidos, ou 0 se o arquivo não puder ser aberto.
int exibir_todos_os_peixes_do_arquivo(const char *filename)
{
    FILE *arq = fopen(filename, "rb");
    if (arq == NULL)
    {
        printf("Nenhum peixe cadastrado no arquivo (ou arquivo inacessível).\n");
        printf("--------------------------\n");
        return 0; // Retorna 0 peixes lidos
    }

    struct peixe p_temp;
    int contador = 0;
    printf("\n--- Peixes Cadastrados ---\n");
    while (fread(&p_temp, sizeof(struct peixe), 1, arq) == 1)
    {
        printf("Nome: %-20s | Peso: %5u g | Comprimento: %5.2f cm\n",
               p_temp.nome, p_temp.peso, p_temp.comp);
        contador++;
    }
    fclose(arq);

    if (contador == 0)
    {
        printf("Nenhum peixe cadastrado no arquivo.\n");
    }
    printf("--------------------------\n");
    return contador;
}

// UPDATE: Atualiza os dados de um peixe no arquivo (identificado pelo nome).
// Retorna 0 se atualizado, 1 se não encontrado, -1 se erro de arquivo.
int atualizar_peixe_no_arquivo(const char *filename, const char *nome_chave, struct peixe dados_atualizados)
{
    FILE *arq = fopen(filename, "rb+");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo para atualizacao");
        fprintf(stderr, "Arquivo: %s\n", filename);
        return -1;
    }

    struct peixe p_temp;
    int encontrado = 0;
    while (fread(&p_temp, sizeof(struct peixe), 1, arq) == 1)
    {
        if (strcmp(p_temp.nome, nome_chave) == 0)
        {
            // Volta para o início do registro atual para sobrescrevê-lo
            if (fseek(arq, -(long)sizeof(struct peixe), SEEK_CUR) != 0)
            {
                perror("Erro ao posicionar para atualizacao (fseek)");
                fclose(arq);
                return -1;
            }
            // Sobrescreve o registro com os novos dados
            if (fwrite(&dados_atualizados, sizeof(struct peixe), 1, arq) < 1)
            {
                perror("Erro ao escrever dados atualizados do peixe");
                fclose(arq);
                return -1;
            }
            encontrado = 1;
            break; // Peixe encontrado e atualizado
        }
    }
    fclose(arq);
    return encontrado ? 0 : 1; // 0 se sucesso, 1 se não encontrado
}

// DELETE: Exclui um peixe do arquivo (identificado pelo nome).
// Retorna 0 se excluído, 1 se não encontrado, -1 se erro.
int excluir_peixe_do_arquivo(const char *filename, const char *nome_chave)
{
    FILE *arq_original = fopen(filename, "rb");
    if (arq_original == NULL)
    {
        perror("Erro ao abrir o arquivo original para exclusão");
        fprintf(stderr, "Arquivo: %s\n", filename);
        return -1;
    }

    char temp_filename[256];
    sprintf(temp_filename, "%s_temp.bin", filename);

    FILE *arq_temp = fopen(temp_filename, "wb");
    if (arq_temp == NULL)
    {
        perror("Erro ao criar arquivo temporario para exclusao");
        fprintf(stderr, "Arquivo: %s\n", temp_filename);
        fclose(arq_original);
        return -1;
    }

    struct peixe p_temp;
    int encontrado_e_excluido = 0;
    while (fread(&p_temp, sizeof(struct peixe), 1, arq_original) == 1)
    {
        if (strcmp(p_temp.nome, nome_chave) == 0)
        {
            encontrado_e_excluido = 1; // Marca que o peixe foi encontrado (e não será copiado)
        }
        else
        {
            if (fwrite(&p_temp, sizeof(struct peixe), 1, arq_temp) < 1)
            {
                perror("Erro ao escrever no arquivo temporario");
                fclose(arq_original);
                fclose(arq_temp);
                remove(temp_filename); // Tenta remover o temporario
                return -1;
            }
        }
    }

    fclose(arq_original);
    fclose(arq_temp);

    if (remove(filename) != 0)
    {
        perror("Erro ao remover o arquivo original");
        fprintf(stderr, "Arquivo: %s\n", filename);
        remove(temp_filename); // Tenta remover o temporario
        return -1;
    }

    if (rename(temp_filename, filename) != 0)
    {
        perror("Erro ao renomear o arquivo temporario");
        fprintf(stderr, "Arquivo: %s para %s\n", temp_filename, filename);
        remove(temp_filename);
        return -1;
    }

    return encontrado_e_excluido ? 0 : 1; // 0 se excluído com sucesso, 1 se não foi encontrado
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome_arquivo_bin[100] = "peixes.bin";
    struct peixe novo_peixe;

    printf("Exibindo peixes ja cadastrados\n");
    exibir_todos_os_peixes_do_arquivo(nome_arquivo_bin);

    printf("\n--- Cadastro de Novo Peixe ---\n");
    printf("Digite o nome do peixe (max 19 caracteres): ");
    if (fgets(novo_peixe.nome, sizeof(novo_peixe.nome), stdin) != NULL)
    {
        novo_peixe.nome[strcspn(novo_peixe.nome, "\n")] = 0;
    }
    else
    {
        fprintf(stderr, "Erro ao ler nome do peixe.\n");
        return 1;
    }

    printf("Digite o peso do peixe (em gramas): ");
    if (scanf("%u", &novo_peixe.peso) != 1)
    {
        fprintf(stderr, "Entrada inválida para peso.\n");
        // Limpar buffer de entrada em caso de erro de scanf
        while (getchar() != '\n')
            ;
        return 1;
    }
    // Limpar o buffer após scanf para o próximo fgets/scanf
    while (getchar() != '\n')
        ;

    printf("Digite o comprimento do peixe (em cm): ");
    if (scanf("%f", &novo_peixe.comp) != 1)
    {
        fprintf(stderr, "Entrada inválida para comprimento.\n");
        while (getchar() != '\n')
            ;
        return 1;
    }
    // Limpar o buffer após scanf
    while (getchar() != '\n')
        ;

    if (adicionar_peixe_arquivo(nome_arquivo_bin, novo_peixe) == 0)
    {
        printf("Peixe '%s' adicionado com sucesso!\n", novo_peixe.nome);
    }
    else
    {
        printf("Falha ao adicionar o peixe '%s'.\n", novo_peixe.nome);
    }

    return 0;
}
