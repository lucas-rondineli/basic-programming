#include <stdio.h>
#include <locale.h>

long double soma(short unsigned int n)
{
    long double s = 1;
    long double mult = 1;
    for (int i = 1; i <= n; i++)
    {
        mult *= i;
        s += 1.0 / mult;
    }

    return s;
}


int main()
{
    setlocale(LC_ALL, "portuguese");

    short unsigned int n;
    printf("Digite o valor de N: ");
    scanf("%hu", &n);

    printf("O valor de S é: %.20Lf", soma(n));

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}