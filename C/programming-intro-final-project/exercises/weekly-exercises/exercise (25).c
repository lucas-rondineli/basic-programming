#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int n, sum = 0, tot = 0;

    do
    {
        printf("Digite um número (0 para parar): ");
        scanf("%d", &n);
        sum += n;
        tot++;
    } while (n != 0);
    tot--;

    printf("A média dos números digitados foi de: %.2f", (float)sum / tot);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}