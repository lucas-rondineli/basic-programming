#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    float he, hf, h;

    printf("Informe as horas extras: ");
    scanf("%f", &he);
    he *= 60;
    printf("Informe as horas faltantes: ");
    scanf("%f", &hf);
    hf *= 60;

    h = he - (2.0 / 3) * hf;

    if (h < 600)
        printf("Prêmio: R$100,00\n");
    else if (h < 1200)
        printf("Prêmio: R$200,00\n");
    else if (h < 1800)
        printf("Prêmio: R$300,00\n");
    else if (h < 2400)
        printf("Prêmio: R$400,00\n");
    else if (h >= 2400)
        printf("Prêmio: R$500,00\n");

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
