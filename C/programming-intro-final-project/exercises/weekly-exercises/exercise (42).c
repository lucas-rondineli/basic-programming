#include <stdio.h>
#include <locale.h>
#include <math.h>

void raizes(float a, float b, float c)
{
    if (a == 0)
        printf("Não é uma equação de segundo grau\n");
    else
    {
        float d = b * b - 4 * a * c;

        if (d < 0)
            printf("Essa equação não possui raizes\n");
        else if (d == 0)
            printf("A única raiz da equação é: %.2f\n", -b / (2 * a));
        else
            printf("As raizes da equação são:\n\tX1 = %.2f\n\tX2 = %.2f\n", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    float a, b, c;

    printf("Digite os coeficientes da equação de segundo grau: ");
    scanf("%f%f%f", &a, &b, &c);

    raizes(a, b, c);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}