#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "stack_char.h"

int precedencia(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0; // Para parênteses
    }
}

void conv_expr(const char *infixa, char *posfixa) // Converte uma expressão infixa para pós-fixa
{
    Stack pilha_op; // pilha de char
    stack_init(&pilha_op);

    int j = 0; // Índice para a string pós-fixa

    for (int i = 0; infixa[i] != '\0'; i++) // o ultimo char será a condição de saida
    {
        char caractere = infixa[i];

        if (caractere == ' ') // Ignora espaços
            continue;

        // algoritmo Shunting-yard

        // Se for um número vai direto pro array
        if (isdigit(caractere))
        {
            posfixa[j++] = caractere; // Adiciona o número e já incrementa o indice da pos fixe para o proximo caractere
            posfixa[j++] = ' ';       // Adiciona um espaço para separar os números e já incrementa o indice da pos fixe para o proximo caractere
        }
        // Se for um parêntese de abertura
        else if (caractere == '(')
        {
            stack_push(&pilha_op, caractere); // adiciona parentese para indicar prioridade de expressao
        }
        // Se for um parêntese de fechamento
        else if (caractere == ')') // adicionar parentese para indicar o fechamento de uma expressao de prioridade
        {
            while (!stack_is_empty(&pilha_op) && stack_top(&pilha_op) != '(') // começa a desempilhar os operadores até fechar a sub-expressão
            {
                posfixa[j++] = stack_pop(&pilha_op); // desempilha os operadores e adiciona na expr_final, já incrementado j++
                posfixa[j++] = ' ';                  // espaço pos add operador
            }
            stack_pop(&pilha_op); // Remove o '(' da pilha, finalizando a sub-expressão
        }
        else // operadores
        {
            while (!stack_is_empty(&pilha_op) && precedencia(stack_top(&pilha_op)) >= precedencia(caractere))
            // enquanto não tiver vazia e a precedencia do operador no top da stack for maior que o operador (caractere) atual
            {
                posfixa[j++] = stack_pop(&pilha_op); // adiciona o operador de maior prioridade
                posfixa[j++] = ' ';
            }
            // Depois que todos os operadores de maior ou igual precedência foram movidos
            // para a saída, a pilha está pronta para receber o operador atual.
            stack_push(&pilha_op, caractere);
        }
    }

    // Desempilha todos os operadores restantes que não tiveram prioridade
    while (!stack_is_empty(&pilha_op))
    {
        posfixa[j++] = stack_pop(&pilha_op);
        posfixa[j++] = ' ';
    }

    posfixa[j] = '\0'; // Finaliza a string
}

int main()
{
    const char *entrada = "( 3 + 4 ) * 2";
    char saida[100];

    conv_expr(entrada, saida);
    printf("Entrada Infixa: %s\n", entrada);
    printf("Saida Pos-fixa: %s\n", saida);

    return 0;
}
