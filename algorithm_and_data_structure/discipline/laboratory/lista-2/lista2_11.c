#include <stdio.h>

int main()
{
    const char *estados[] = {"cheia", "vazia"};
    int indice = 1;

    // Formas equivalentes:
    printf("%s\n", estados[indice]);         // Forma comum
    printf("%s\n", *(estados + indice));     // Aritmética de ponteiro
    printf("%s\n", *(&estados[0] + indice)); // Também válido
    printf("%s\n", 1 [estados]);             // Sim! Isso é válido em C
    // a[b] ≡ *(a + b) ≡ *(b + a) ≡ b[a]
}
