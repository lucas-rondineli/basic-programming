#include <stdio.h>
#include <locale.h>

float maior(float a, int b)
{
    if (a > b)
        return a;
    return b;
}

float maior3(float a, float b, float c)
{
    return maior(maior(a, b), c);
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    float n1, n2, n3;

    printf("Digite três números: ");
    scanf("%f%f%f", &n1, &n2, &n3);

    printf("Entre %.2f, %.2f e %.2f o maior valor é: %.2f", n1, n2, n3, maior3(n1, n2, n3));

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}