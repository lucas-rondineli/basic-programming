#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    short unsigned int n;

    printf("Digite um valor: ");
    scanf("%hu", &n);

    if (n % 2 == 0)
        printf("Par");
    else
        printf("Impar");

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}