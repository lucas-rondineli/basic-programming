#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int n, sum = 0;

    do
    {
        printf("Digite um número (0 para parar): ");
        scanf("%d", &n);
        sum += n;
    } while (n != 0);

    printf("A soma dos números digitados foi de: %d", sum);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}