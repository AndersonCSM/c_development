#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef enum
{
    APROVADO,
    TRANCADO,
    REPROVADO
} situacao;

typedef struct
{
    char nome[100];
    unsigned cod_disciplina;
    situacao sit_aluno;
} aluno;

const char *situacao_str(situacao s)
{
    switch (s)
    {
    case APROVADO:
        return "Aprovado";
    case TRANCADO:
        return "Trancado";
    case REPROVADO:
        return "Reprovado";
    default:
        return "Desconhecido";
    }
}

void exibir(int n, aluno *vetor)
{
    printf("Nome: %s\n", (vetor + n)->nome);
    printf("Código da disciplina: %d\n", (vetor + n)->cod_disciplina);
    printf("Situação do aluno: %s\n", situacao_str((vetor + n)->sit_aluno));
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n = 0;
    char sit_str[20];

    printf("Informe a quantidade de alunos: ");
    scanf("%d", &n);

    aluno *vet_aluno = (aluno *)malloc(n * sizeof(aluno));
    if (vet_aluno == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Informe os valores do primeiro aluno (NOME | CÓDIGO_DISCIPLINA | SITUAÇÃO)\n");
    scanf("%s %d %s", vet_aluno->nome, &vet_aluno->cod_disciplina, sit_str);

    // Conversão da string para enum
    if (strcmp(sit_str, "APROVADO") == 0)
        vet_aluno->sit_aluno = APROVADO;
    else if (strcmp(sit_str, "TRANCADO") == 0)
        vet_aluno->sit_aluno = TRANCADO;
    else
        vet_aluno->sit_aluno = REPROVADO;

    exibir(0, vet_aluno);

    free(vet_aluno);
    return 0;
}
