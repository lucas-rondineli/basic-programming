#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int n;

    printf("Digite um valor: ");
    scanf("%d", &n);

    if (n > 0)
        printf("%d é positivo", n);
    else if (n < 0)
        printf("%d é negativo", n);
    else
        printf("Ele é 0");

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}