#include <stdio.h>
#include <locale.h>
struct Horario
{
    int h;
    int min;
};

void MostrarHorario(struct Horario *ptr)
{
    printf("%02d:%02d\n", ptr->h, ptr->min);
}

// Funcao para normalizar o horario: converte minutos extras em horas
void NormalizarHorario(struct Horario *ptr)
{
    if (ptr->min >= 60)
    {
        ptr->h += ptr->min / 60;
        ptr->min = ptr->min % 60;
    }
    if (ptr->h >= 24)
    {
        ptr->h = ptr->h % 24;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Horario h1, *px;
    px = &h1;

    printf("Informe o hor�rio atual [hh:mm]\n");
    scanf("%d %d", &px->h, &px->min);

    px->h++;
    
    NormalizarHorario(px);
    MostrarHorario(px);
    return 0;
}
