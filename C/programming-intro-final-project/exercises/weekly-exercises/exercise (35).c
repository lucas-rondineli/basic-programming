#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int n, sum = 0;

    printf("Informe um número inteiro: ");
    scanf("%d", &n);

    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            sum += i;
    }

    if (n == sum)
        printf("%d é um número perfeito", n);
    else
        printf("%d não é um número perfeito", n);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
