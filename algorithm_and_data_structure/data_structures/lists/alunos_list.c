#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "generic_list.h"

typedef struct student
{
    char *name;
    int id;
} Student;

int compare_student(void *a, void *b) // callback para comparar alunos
{
    Student *student_a = (Student *)a; // realiza o cast do dado generico para o tipo estudante
    Student *student_b = (Student *)b;

    return student_a->id - student_b->id; // compara o id dos alunos
}

void free_student(void *data) // callback para liberar aluno
{
    Student *student_ptr = (Student *)data; // ponteiro generico

    if (student_ptr == NULL)
        return;

    if (student_ptr->name != NULL) // libera o nome do estudante
        free(student_ptr->name);

    free(student_ptr); // libera o ponteiro generico usando na função
}

Student *create_student(const char *name, int id)
{
    Student *new_student = (Student *)malloc(sizeof(Student)); // ponteiro generico
    if (new_student == NULL)
    {
        fprintf(stderr, "Erro ao alocar Student\n");
        return 1;
    }

    new_student->id = id;

    // strdup faz o malloc interno e a cópia.
    /*
    char *new_name = malloc(strlen(name) + 1);
    strcpy(new_name, name);
    */
    new_student->name = strdup(name);
    if (new_student->name == NULL)
    {
        free(new_student); // Limpeza em caso de falha de alocação do nome
        fprintf(stderr, "Erro ao alocar nome\n");
        return 1;
    }

    return new_student;
}

int main()
{

    // Criar um  lista de alunos
    List *list = list_create(sizeof(Student), free_student, compare_student);

    // Nomes e IDs
    const char *names[] = {"Alice", "Bob", "Charlie", "Diana"};
    int ids[] = {101, 205, 303, 408};

    // Adicionar elementos
    for (int i = 0; i < 4; i++)
    {
        Student *s = create_student(names[i], ids[i]);
        list_add(list, s);
    }

    // Verificar se um aluno está na lista
    Student search_key = {.name = NULL, .id = 303};

    printf("Procurando aluno com ID: %d...\n", search_key.id);

    if (list_contains(list, &search_key)) // espera um ponteiro da chave de busca
        printf("-> Sucesso: Aluno ID %d encontrado!\n", search_key.id);
    else
        printf("-> Falha: Aluno ID %d não encontrado.\n", search_key.id);

    printf("----------------------------------------\n");

    // Destruir a lista
    list_destroy(list);
    list = NULL;

    return 0;
}
