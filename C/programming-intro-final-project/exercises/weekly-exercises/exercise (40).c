#include <stdio.h>
#include <locale.h>

int soma_inteiros(int a, int b, int c)
{
    int sum = 0;
    if (b > c)
    {
        b = b + c;
        c = b - c;
        b = b - c;
    }
    for (b; b <= c; b++)
    {
        if (b % a == 0)
            sum += b;
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int a, b, c;

    printf("Digite três números: ");
    scanf("%d%d%d", &a, &b, &c);

    printf("A soma dos números divisíveis por %d entre %d e %d é: %d\n", a, b, c, soma_inteiros(a, b, c));

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}