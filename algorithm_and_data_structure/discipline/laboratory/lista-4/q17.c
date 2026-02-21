#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_SENHA 51
#define ALFA 1
#define NUMERICA 2
#define FILE_SENHA "senha_segura.dat"

union Senha
{
    char alfanumerica[MAX_SENHA];
    int numerica;
};

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void write_senha()
{
    union Senha minha_senha;
    int tipo_senha;
    FILE *arquivo;

    printf("\n--- Gravar Nova Senha ---\n");
    printf("Qual tipo de senha deseja criar?\n");
    printf("1. Alfanumérica\n");
    printf("2. Numérica\n");
    printf("Opção: ");

    if (scanf("%d", &tipo_senha) != 1 || (tipo_senha != ALFA && tipo_senha != NUMERICA)) // versão melhorada garanti opc 1 e 2
    {
        fprintf(stderr, "Opção de tipo inválida.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    if (tipo_senha == ALFA)
    {
        printf("Digite a senha alfanumérica (max %d caracteres): ", MAX_SENHA - 1);
        if (fgets(minha_senha.alfanumerica, MAX_SENHA, stdin) == NULL)
        {
            fprintf(stderr, "Erro ao ler a senha alfanumérica.\n");
            return;
        }
        minha_senha.alfanumerica[strcspn(minha_senha.alfanumerica, "\n")] = 0;
    }
    else
    { // tipo_senha == NUMERICA
        printf("Digite a senha numérica: ");
        if (scanf("%d", &minha_senha.numerica) != 1)
        {
            fprintf(stderr, "Entrada inválida para senha numérica.\n");
            limpar_buffer();
            return;
        }
        limpar_buffer();
    }

    arquivo = fopen(FILE_SENHA, "wb");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para gravação");
        return;
    }

    if (fwrite(&tipo_senha, sizeof(int), 1, arquivo) != 1)
    {
        fprintf(stderr, "Erro ao gravar o tipo da senha no arquivo.\n");
        fclose(arquivo);
        return;
    }

    if (fwrite(&minha_senha, sizeof(union Senha), 1, arquivo) != 1)
    {
        fprintf(stderr, "Erro ao gravar os dados da senha no arquivo.\n");
        fclose(arquivo);
        return;
    }

    printf("Senha gravada com sucesso no arquivo '%s'.\n", FILE_SENHA);
    fclose(arquivo);
}

void exibir()
{
    union Senha senha_lida;
    int tipo_senha;
    FILE *arquivo;

    arquivo = fopen(FILE_SENHA, "rb");
    if (arquivo == NULL)
    {
        printf("Arquivo de senha não encontrado ou não pôde ser aberto.\n");
        return;
    }

    if (fread(&tipo_senha, sizeof(int), 1, arquivo) != 1)
    {
        fprintf(stderr, "Erro ao ler o tipo da senha do arquivo ou arquivo corrompido/vazio.\n");
        fclose(arquivo);
        return;
    }

    if (fread(&senha_lida, sizeof(union Senha), 1, arquivo) != 1)
    {
        fprintf(stderr, "Erro ao ler os dados da senha do arquivo ou arquivo corrompido.\n");
        fclose(arquivo);
        return;
    }

    printf("Senha armazenada:\n");
    if (tipo_senha == ALFA)
    {
        printf("Tipo: Alfanumérica\n");
        printf("Senha: %s\n", senha_lida.alfanumerica);
    }
    else if (tipo_senha == NUMERICA)
    {
        printf("Tipo: Numérica\n");
        printf("Senha: %d\n", senha_lida.numerica);
    }

    fclose(arquivo);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char opc;

    do
    {
        printf("\n--- Gerenciador de Senhas ---\n");
        printf("[G]ravar nova senha\n");
        printf("[E]xibir senha armazenada\n");
        printf("[S]air\n");
        printf("-----------------------------\n");
        printf("Opção: ");

        if (scanf(" %c", &opc) != 1)
        { // Espaço antes de %c para consumir newlines pendentes
            fprintf(stderr, "Erro ao ler a opção do menu.\n");
            limpar_buffer();
            opc = ' ';
            continue;
        }
        limpar_buffer();

        opc = toupper(opc);

        switch (opc)
        {
        case 'G':
            write_senha();
            break;
        case 'E':
            exibir();
            break;
        case 'S':
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opc != 'S');

    return 0;
}