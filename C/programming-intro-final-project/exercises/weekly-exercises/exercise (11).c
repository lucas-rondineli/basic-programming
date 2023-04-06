#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    float a, b, c, d, x1, x2;
    printf("Digite os coeficientes da equação de segundo grau: ");
    scanf("%f%f%f", &a, &b, &c);
    d = b * b - 4 * a * c;

    if (a == 0)
        printf("Não é uma equação de segundo grau");
    else if (d < 0)
        printf("Essa equação não possui raízes");
    else if (d == 0)
    {
        x1 = -b / (2 * a);
        printf("A única raiz é: %.2f", x1);
    }
    else
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("1° raiz: %.2f\n", x1);
        printf("2° raiz: %.2f\n", x2);
    }

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}