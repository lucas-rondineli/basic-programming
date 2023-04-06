#include <stdio.h>
#include <locale.h>

double somaN(int n)
{
    double soma = 0;

    for (int i = 1; i <= n; i++)
        soma += (float)(i * i + 1) / (i + 3);
    return soma;
}

void mostraS(int n)
{
    printf("S = ");

    for (int i = 1; i < n; i++)
    {
        printf("%d/%d + ", (i * i + 1), (i + 3));
    }

    printf("%d/%d", (n * n + 1), (n + 3));
    printf(" = %f", somaN(n));

    return;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int n;

    printf("Digite o valor de N: ");
    scanf("%d", &n);

    mostraS(n);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
