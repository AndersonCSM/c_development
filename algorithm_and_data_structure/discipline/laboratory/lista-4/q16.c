#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_NOME 51
#define ARQUIVO "soldado.dat"

struct Soldado
{
    char nome[MAX_NOME];
    int eliminacoes;
    int mortes;
    float taxa_em;
    int partidas_jogadas;
};

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Funcao para criar um novo soldado (CREATE)
struct Soldado create_s()
{
    struct Soldado novo_s;

    printf("\n--- Criar Novo Soldado ---\n");
    printf("Nome do Soldado (max %d caracteres): ", MAX_NOME - 1);
    if (fgets(novo_s.nome, MAX_NOME, stdin) == NULL)
    {
        fprintf(stderr, "Erro ao ler o nome. Saindo da criacao.\n");
        strcpy(novo_s.nome, "INDEFINIDO");
        novo_s.eliminacoes = 0;
        novo_s.mortes = 0;
        novo_s.partidas_jogadas = 0;
        novo_s.taxa_em = 0;
        return novo_s;
    }

    novo_s.nome[strcspn(novo_s.nome, "\n")] = 0; // Remove newline
    if (strlen(novo_s.nome) == 0)
    {
        fprintf(stderr, "Nome não pode ser vazio. Usando 'Soldado Sem Nome'.\n");
        strcpy(novo_s.nome, "Soldado Sem Nome");
    }

    printf("Eliminações: ");
    if (scanf("%d", &novo_s.eliminacoes) != 1 || novo_s.eliminacoes < 0)
    {
        fprintf(stderr, "Entrada inválida para eliminações. Usando 0.\n");
        novo_s.eliminacoes = 0;
    }
    limpar_buffer();

    printf("Mortes: ");
    if (scanf("%d", &novo_s.mortes) != 1 || novo_s.mortes < 0)
    {
        fprintf(stderr, "Entrada inválida para mortes. Usando 0.\n");
        novo_s.mortes = 0;
    }
    limpar_buffer();

    printf("Partidas Jogadas: ");
    if (scanf("%d", &novo_s.partidas_jogadas) != 1 || novo_s.partidas_jogadas < 0)
    {
        fprintf(stderr, "Entrada inválida para partidas jogadas. Usando 0.\n");
        novo_s.partidas_jogadas = 0;
    }
    limpar_buffer();

    novo_s.taxa_em = (novo_s.mortes > 0) ? (float)((float)novo_s.eliminacoes / (float)novo_s.mortes) : (float)novo_s.eliminacoes;
    printf("Novo soldado '%s' pronto para ser salvo.\n", novo_s.nome);
    return novo_s;
}

void view_s(struct Soldado s)
{
    printf("\n--- Estatísticas do Soldado ---\n");
    printf("Nome: %s\n", s.nome);
    printf("Eliminações: %d\n", s.eliminacoes);
    printf("Mortes: %d\n", s.mortes);
    printf("Taxa E/M: %.2f\n", s.taxa_em);
    printf("Partidas Jogadas: %d\n", s.partidas_jogadas);
    printf("-------------------------------\n");
}

// Funcao para atualizar um soldado existente (UPDATE)
struct Soldado update_s(struct Soldado s_atual)
{
    struct Soldado s_aux = s_atual;
    char buffer_nome[MAX_NOME + 2];

    printf("\n--- Atualizar Soldado: %s ---\n", s_atual.nome);

    printf("Novo Nome (atual: %s, deixe em branco e pressione Enter para manter): ", s_atual.nome);
    if (fgets(buffer_nome, sizeof(buffer_nome), stdin) == NULL)
    {
        fprintf(stderr, "Erro ao ler o novo nome. Nome não alterado.\n");
    }
    else
    {
        buffer_nome[strcspn(buffer_nome, "\n")] = 0; // Remove newline

        if (strlen(buffer_nome) > 0)
        { // Se algo foi digitado
            strcpy(s_aux.nome, buffer_nome);
        }
    }

    printf("Eliminações (atual: %d): ", s_atual.eliminacoes);
    if (scanf("%d", &s_aux.eliminacoes) != 1 || s_aux.eliminacoes < 0)
    {
        fprintf(stderr, "Entrada inválida. Mantendo valor atual.\n");
        s_aux.eliminacoes = s_atual.eliminacoes;
    }
    limpar_buffer();

    printf("Mortes (atual: %d): ", s_atual.mortes);
    if (scanf("%d", &s_aux.mortes) != 1 || s_aux.mortes < 0)
    {
        fprintf(stderr, "Entrada inválida. Mantendo valor atual.\n");
        s_aux.mortes = s_atual.mortes;
    }
    limpar_buffer();

    printf("Partidas (atual: %d): ", s_atual.partidas_jogadas);
    if (scanf("%d", &s_aux.partidas_jogadas) != 1 || s_aux.partidas_jogadas < 0)
    {
        fprintf(stderr, "Entrada inválida. Mantendo valor atual.\n");
        s_aux.partidas_jogadas = s_atual.partidas_jogadas;
    }
    limpar_buffer();

    s_aux.taxa_em = (s_aux.mortes > 0) ? (float)((float)s_aux.eliminacoes / (float)s_aux.mortes) : (float)s_aux.eliminacoes;
    printf("Soldado '%s' atualizado.\n", s_aux.nome);
    return s_aux;
}

// Funcao para gravar os dados de um soldado no arquivo binario
void write_s(struct Soldado s, const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir arquivo para gravacao");
        return;
    }
    if (fwrite(&s, sizeof(struct Soldado), 1, arquivo) != 1)
    {
        fprintf(stderr, "Erro ao gravar dados do soldado no arquivo.\n");
    }
    fclose(arquivo);
}

// Retorna 1 se sucesso, 0 se arquivo não existe ou erro de leitura
int read_s(struct Soldado *s, const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL)
    {
        return 0;
    }
    if (fread(s, sizeof(struct Soldado), 1, arquivo) != 1)
    {
        fprintf(stderr, "Erro ao ler dados do soldado do arquivo ou arquivo corrompido.\n");
        fclose(arquivo);
        return 0;
    }
    fclose(arquivo);
    return 1;
}

int main()
{
    struct Soldado soldado_aux;
    int soldado_existe = 0;
    char opc;

    if (read_s(&soldado_aux, ARQUIVO))
    {
        printf("Dados do soldado '%s' carregados do arquivo.\n", soldado_aux.nome);
        soldado_existe = 1;
    }
    else
    {
        printf("Arquivo '%s' não encontrado ou vazio.\n", ARQUIVO);
        printf("Por favor, crie um novo soldado.\n");
        soldado_aux = create_s();
        write_s(soldado_aux, ARQUIVO);
        soldado_existe = 1;
    }

    do
    {
        printf("\n--- Menu Soldado ---\n");
        printf("[N] Novo Soldado\n");
        printf("[A] Atualizar Soldado\n");
        printf("[E] Exibir Soldado\n");
        printf("[S] Sair\n");
        printf("--------------------\n");
        printf("Opcao: ");

        if (scanf(" %c", &opc) != 1)
        {
            fprintf(stderr, "Erro ao ler a opcao.\n");
            limpar_buffer();
            opc = ' ';
            continue;
        }
        limpar_buffer();
        opc = toupper(opc);

        switch (opc)
        {
        case 'N':
            soldado_aux = create_s(soldado_aux, 1);
            write_s(soldado_aux, ARQUIVO);
            soldado_existe = 1;
            break;
        case 'A':
            if (!soldado_existe)
            {
                printf("Nenhum soldado carregado para atualizar. Crie um novo primeiro (Opcao N).\n");
            }
            else
            {
                soldado_aux = update_s(soldado_aux);
                write_s(soldado_aux, ARQUIVO);
            }
            break;
        case 'E':
            if (!soldado_existe)
            {
                printf("Nenhum soldado carregado para exibir. Crie um novo primeiro (Opcao N).\n");
            }
            else
            {
                view_s(soldado_aux);
            }
            break;
        case 'S':
            break; // sai do programa
        default:
            printf("Opcao invalida.\n");
        }
    } while (opc != 'S');

    return 0;
}