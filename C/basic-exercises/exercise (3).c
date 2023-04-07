#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void powProva(double x, int y, double *result)
{
    double mult = 1;
    for (int i = 0; i < y; i++)
        mult *= x;
    *result = mult;
}

double calcular(double x)
{
    double s = 0;
    double exp = 0;
    for (int i = 0; i < 25; i++)
    {
        powProva(x, 25 - i, &exp);
        if (i % 2 == 0)
            s += exp / (i + 1);
        else
            s -= exp / (i + 1);
    }
    return s;
}

void show(double x)
{
    printf("S = ");
    int i = 0;
    for (i; i < 24; i++)
        if (i % 2 == 0)
            printf("{[(%.0f) ^ %d] / %d} - ", x, 25 - i, i + 1);
        else
            printf("{[(%.0f) ^ %d] / %d} + ", x, 25 - i, i + 1);
    printf("{[(%.0f) ^ %d] / %d} = ", x, 25 - i, i + 1);
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    double x;
    printf("Digite um valor para X: ");
    scanf("%lf", &x);

    show(x);
    printf("%f", calcular(x));

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
