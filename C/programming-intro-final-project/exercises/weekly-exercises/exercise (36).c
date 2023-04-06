#include <stdio.h>
#include <locale.h>

int par_impar(int x)
{
    if (x % 2 == 0)
        return 0;
    return 1;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int n;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);

    if (par_impar(n))
        printf("%d é um número ímpar", n);
    else
        printf("%d é um número par", n);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}