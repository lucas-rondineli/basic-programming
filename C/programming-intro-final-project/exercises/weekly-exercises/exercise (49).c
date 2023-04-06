#include <stdio.h>
#include <locale.h>

void medidasDoRetangulo(float *b, float *h)
{
    float p = 2 * ((*b) + (*h));

    *b = (*b) * (*h);
    *h = p;

    return;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    float b, h;

    printf("Digite a base e a altura do retângulo: ");
    scanf("%f%f", &b, &h);

    medidasDoRetangulo(&b, &h);

    printf("Área: %.2f\nPerímetro: %.2f", b, h);

    while(getchar() != '\n')
        ;
    getchar();
    return 0;
}
