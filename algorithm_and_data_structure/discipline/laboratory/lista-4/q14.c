#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#define ARQUIVO_IMAGEM "blocos.dat"
#define MAX_DIM 50

struct Imagem
{
    int largura;
    int altura;
};

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void armazenar_imagem()
{
    struct Imagem img;
    int matriz_cores[MAX_DIM][MAX_DIM]; // Matriz para armazenar as cores temporariamente
    FILE *arquivo;

    printf("Digite a largura da imagem (1-%d): ", MAX_DIM);
    if (scanf("%d", &img.largura) != 1)
    {
        fprintf(stderr, "Largura inv�lida.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    printf("Digite a altura da imagem (1-%d): ", MAX_DIM);
    if (scanf("%d", &img.altura) != 1)
    {
        fprintf(stderr, "Altura inv�lida.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    printf("Digite os c�digos de cor (0-255) para cada linha:\n");
    for (int i = 0; i < img.altura; i++)
    {
        printf("#%d (%d cores): ", i + 1, img.largura);
        for (int j = 0; j < img.largura; j++)
        {
            if (scanf("%d", &matriz_cores[i][j]) != 1)
            {
                fprintf(stderr, "\nCor inv�lida na linha %d, coluna %d.\n", i + 1, j + 1);
                limpar_buffer(); // Limpa o resto da linha inv�lida
                i--;             // Repete a leitura para a linha inteira
                break;           // Sai do loop interno (colunas) para repetir a linha
            }
        }
        if (i < img.altura - 1 && i >= 0)
            limpar_buffer(); // Limpa o '\n' no final da linha de scanf, exceto para a �ltima linha ou se i foi decrementado
    }
    // Se a �ltima entrada foi v�lida, o �ltimo \n pode precisar ser limpo antes de futuras opera��es de menu
    // No entanto, o " %c" no scanf do menu principal geralmente lida com isso.

    arquivo = fopen(ARQUIVO_IMAGEM, "wb");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para armazenamento da imagem");
        return;
    }

    if (fwrite(&img, sizeof(struct Imagem), 1, arquivo) != 1)
    {
        fprintf(stderr, "Erro ao escrever o cabe�alho da imagem no arquivo.\n");
        fclose(arquivo);
        return;
    }

    for (int i = 0; i < img.altura; i++)
    {
        for (int j = 0; j < img.largura; j++)
        {
            if (fwrite(&matriz_cores[i][j], sizeof(int), 1, arquivo) != 1)
            {
                fprintf(stderr, "Erro ao escrever o bloco de cor (%d,%d) no arquivo.\n", i, j);
                fclose(arquivo);
                return;
            }
        }
    }

    printf("Imagem de blocos coloridos foi armazenada.\n");
    fclose(arquivo);
}

void exibir_imagem()
{
    struct Imagem img;
    int cor_bloco;
    FILE *arquivo;

    // A funcao exibir_imagem processa os dados da imagem "em fluxo" (streaming).
    // Ela le as dimensoes (cabecalho) e, em seguida, le a cor de cada bloco
    // individualmente do arquivo e a exibe imediatamente.
    // Isso evita a necessidade de carregar toda a matriz de cores para a memoria
    // de uma vez, tornando a funcao eficiente em termos de uso de memoria,
    // especialmente para imagens grandes. Apenas a cor do bloco atual e
    // mantida na memoria durante a exibicao.

    arquivo = fopen(ARQUIVO_IMAGEM, "rb");
    if (arquivo == NULL)
    {
        printf("Nenhuma imagem armazenada ainda ou arquivo nao encontrado.\n");
        return;
    }

    if (fread(&img, sizeof(struct Imagem), 1, arquivo) != 1)
    {
        fprintf(stderr, "Erro ao ler o cabe�alho da imagem do arquivo ou arquivo inv�lido.\n");
        fclose(arquivo);
        return;
    }

    if (img.largura <= 0)
    {
        fprintf(stderr, "Dimens�es da imagem inv�lidas encontradas no arquivo.\n");
        fclose(arquivo);
        return;
    }

    printf("\nExibindo imagem armazenada (%dx%d):\n", img.largura, img.altura);
    for (int i = 0; i < img.altura; i++)
    {
        for (int j = 0; j < img.largura; j++)
        {
            if (fread(&cor_bloco, sizeof(int), 1, arquivo) != 1)
            {
                fprintf(stderr, "\nErro ao ler o bloco de cor (%d,%d) do arquivo.\n", i + 1, j + 1);
                printf("\033[0m"); // Reseta cores
                fclose(arquivo);
                return;
            }
            // Imprime um espaco com a cor de fundo definida pela cor_bloco
            printf("\033[48;5;%03dm \033[0m", cor_bloco); // Um espaco para cada bloco
        }
        printf("\n");
    }
    printf("\033[0m"); // Garante que as cores sejam resetadas no final

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
        { // Espaco antes de %c para consumir newlines pendentes
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
            armazenar_imagem();
            break;
        case 'E':
            exibir_imagem();
            break;
        case 'S':
            break;
        default:
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opc != 'S');

    return 0;
}