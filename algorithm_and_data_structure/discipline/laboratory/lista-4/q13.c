#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define MAX_TEXTO 81
#define NOME_ARQUIVO "mensagem_colorida.dat"

struct MensagemColorida
{
    char texto[MAX_TEXTO];
    int cor_texto;
    int cor_fundo;
};

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void armazenar_mensagem()
{
    struct MensagemColorida msg;
    FILE *arquivo;

    printf("Sua mensagem: ");
    if (fgets(msg.texto, MAX_TEXTO, stdin) == NULL)
    {
        fprintf(stderr, "Erro ao ler a mensagem.\n");
        return;
    }
    msg.texto[strcspn(msg.texto, "\n")] = 0;

    printf("Cor do texto: ");
    if (scanf("%d", &msg.cor_texto) != 1)
    {
        fprintf(stderr, "Cor do texto inv�lida. Deve ser entre 000 e 255.\n");
        limpar_buffer(); // Limpa o buffer em caso de entrada inv�lida
        return;
    }
    limpar_buffer(); // Limpa o '\n' deixado por scanf

    printf("Cor do fundo: ");
    if (scanf("%d", &msg.cor_fundo) != 1)
    {
        fprintf(stderr, "Cor do fundo invalida. Deve ser entre 000 e 255.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    arquivo = fopen(NOME_ARQUIVO, "wb"); // Abre para escrita bin�ria (sobrescreve)
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para armazenamento");
        return;
    }

    if (fwrite(&msg, sizeof(struct MensagemColorida), 1, arquivo) != 1)
    {
        fprintf(stderr, "Erro ao escrever a mensagem no arquivo.\n");
    }
    else
    {
        printf("Texto colorido foi armazenado.\n");
    }

    fclose(arquivo);
}

// Funcao para exibir a mensagem do arquivo
void exibir_mensagem()
{
    struct MensagemColorida msg;
    FILE *arquivo;

    arquivo = fopen(NOME_ARQUIVO, "rb");
    if (arquivo == NULL)
    {
        printf("Nenhuma mensagem armazenada ainda.\n");
        perror("Erro ao abrir o arquivo para exibi��o");
        return;
    }

    if (fread(&msg, sizeof(struct MensagemColorida), 1, arquivo) != 1)
    {
        printf("Nenhuma mensagem v�lida encontrada no arquivo ou erro de leitura.\n");
    }
    else
    {
        // Monta a string de escape ANSI
        // \033[38;5;{COR_TEXTO}m para cor do texto
        // \033[48;5;{COR_FUNDO}m para cor do fundo
        // \033[0m para resetar as cores
        printf("\nExibindo mensagem armazenada:\n");
        printf("\033[38;5;%03dm\033[48;5;%03dm%s\033[0m\n", msg.cor_texto, msg.cor_fundo, msg.texto);
    }

    fclose(arquivo);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char opc;
    do
    {
        printf("\nMensagens Coloridas\n");
        printf("------------------------\n");
        printf("[A]rmazenar\n");
        printf("[E]xibir\n");
        printf("[S]air\n");
        printf("-----------------------\n");
        printf("Op��o: ");

        if (scanf(" %c", &opc) != 1)
        { // Espa�o antes de %c para consumir newlines pendentes
            fprintf(stderr, "Erro ao ler a op��o.\n");
            limpar_buffer();
            opc = ' '; // For�a a repeti��o do loop
            continue;
        }
        limpar_buffer();

        opc = toupper(opc);
        switch (opc)
        {
        case 'A':
            armazenar_mensagem();
            break;
        case 'E':
            exibir_mensagem();
            break;
        case 'S':
            break;
        default:
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opc != 'S');

    return 0;
}