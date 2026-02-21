#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

typedef struct
{
    char nome[100];
    int turma;
    char turno;
} aluno;

void exibir_alunos(const aluno *lista_alunos, int num_alunos)
{
    char turnos[] = {'M', 'T'};
    int series[] = {6, 7, 8};

    for (int i = 0; i < sizeof(turnos) / sizeof(char); i++)
    {
        char turno_att = turnos[i];
        const char *nome_turno = (turno_att == 'M' ? "Matutino" : "Vespertino");

        for (int j = 0; j < sizeof(series) / sizeof(int); j++)
        {
            int serie_att = series[j];
            int contador = 0;
            for (int k = 0; k < num_alunos; k++)
            {
                if (lista_alunos[k].turno == turno_att && lista_alunos[k].turma == serie_att)
                {
                    contador++;
                    break;
                }
            }

            if (contador > 0)
            {
                printf("%s %da Serie\n", nome_turno, serie_att);
                printf("-----------------------------------------------------\n");

                for (int k = 0; k < num_alunos; k++)
                {
                    if (lista_alunos[k].turno == turno_att && lista_alunos[k].turma == serie_att)
                    {
                        printf("%-30s %c%d\n", lista_alunos[k].nome, lista_alunos[k].turno, lista_alunos[k].turma);
                    }
                }
                printf("\n");
            }
        }
    }
}

int main()
{
    char nome_arquivo[100] = "inter.txt";
    aluno *lista_alunos = NULL;
    int n = 0;
    int capacidade_alunos = 0;

    char pri_nome[50];
    char seg_nome[50];
    char codigo_str[10];
    char turno_aluno;
    int serie_aluno;

    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo");
        fprintf(stderr, "Arquivo: %s\n", nome_arquivo);
        return 1;
    }

    while (fscanf(arq, "%49s %49s %9s", pri_nome, seg_nome, codigo_str) == 3)
    {
        // Aumentar a capacidade do vetor de alunos se necessario
        if (n >= capacidade_alunos)
        {
            capacidade_alunos = (capacidade_alunos == 0) ? 10 : capacidade_alunos * 2;
            aluno *temp = realloc(lista_alunos, capacidade_alunos * sizeof(aluno));
            if (temp == NULL)
            {
                perror("Erro ao realocar memoria para lista_alunos");
                free(lista_alunos);
                fclose(arq);
                return 1;
            }
            lista_alunos = temp;
        }

        // Montar o nome completo
        snprintf(lista_alunos[n].nome, sizeof(lista_alunos[n].nome), "%s %s", pri_nome, seg_nome);
        if (strlen(codigo_str) >= 2 && (codigo_str[0] == 'M' || codigo_str[0] == 'T'))
        {
            turno_aluno = codigo_str[0];
            serie_aluno = atoi(&codigo_str[1]); // Converte o numero da serie para int
        }
        else
        {
            fprintf(stderr, "Codigo de turma/turno invalido '%s' para o aluno '%s'. Pulando.\n", codigo_str, lista_alunos[n].nome);
            continue; // Nao incrementa n
        }

        lista_alunos[n].turno = turno_aluno;
        lista_alunos[n].turma = serie_aluno;
        n++;
    }
    fclose(arq);

    exibir_alunos(lista_alunos, n);

    free(lista_alunos);

    return 0;
}