#include <stdio.h>
#include <stdint.h>
#include <locale.h>

struct code_rgba
{
    uint8_t r, g, b, a;
};

union COR
{
    struct code_rgba rgba;
    uint32_t cod;
};

void cor_rgba(union COR *ptr)
{
    int r, g, b, a;
    printf("Informe os valores para: RGBA\n");
    scanf("%d %d %d %d", &r, &g, &b, &a);

    ptr->rgba.r = (uint8_t)r;
    ptr->rgba.g = (uint8_t)g;
    ptr->rgba.b = (uint8_t)b;
    ptr->rgba.a = (uint8_t)a;
}

void cor_cod(union COR *ptr)
{
    int codigo;
    printf("Informe o valor inteiro de 32 bits (RGBA)\n");
    scanf("%u", &codigo);

    ptr->cod = codigo;
}

void imprimir_cor(union COR *ptr)
{
    printf("Cor (R,G,B,A): (%u, %u, %u, %u)\n",
           ptr->rgba.r, ptr->rgba.g, ptr->rgba.b, ptr->rgba.a);
    printf("Valor inteiro: %u (0x%08X)\n", ptr->cod, ptr->cod);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    union COR cor, *px;
    px = &cor;

    printf("Ler cor no formato RGBA\n");
    cor_rgba(px);
    imprimir_cor(px);

    printf("Ler cor no formato inteiro\n");
    cor_cod(px);
    imprimir_cor(px);

    return 0;
}
