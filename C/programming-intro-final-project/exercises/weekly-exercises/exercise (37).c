#include <stdio.h>
#include <locale.h>

float maior(float a, float b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    float n1, n2;

    printf("Digite dois números: ");
    scanf("%f%f", &n1, &n2);

    printf("Entre %.2f e %.2f o maior valor é: %.2f", n1, n2, maior(n1, n2));

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}