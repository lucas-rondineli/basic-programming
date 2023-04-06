#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    float numerador = 480, sum = 0;

    for (int i = 10; i < 40; i++)
    {
        if (i % 2 == 0)
            sum += numerador / i;
        else
            sum -= numerador / i;
        numerador -= 5;
    }

    printf("A soma dos primeiros 30 termos é igual a: %.2f", sum);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}