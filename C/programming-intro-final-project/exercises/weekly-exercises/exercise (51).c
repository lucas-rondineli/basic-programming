#include <stdio.h>
#include <locale.h>

void tempo(int *s, int *m, int *h)
{
    *h = *s / 3600;
    *s = *s % 3600;
    *m = *s / 60;
    *s = *s % 60;

    return;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int s, m, h;

    printf("Digite um número de segundos: ");
    scanf("%d", &s);

    tempo(&s, &m, &h);
    printf("Tempo: %02d:%02d:%02d", h, m, s);

    while(getchar() != '\n')
        ;
    getchar();
    return 0;
}
