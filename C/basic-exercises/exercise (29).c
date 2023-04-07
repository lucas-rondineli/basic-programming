#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    short int i = 0, totn = 0;
    int n;

    while (i < 5)
    {
        printf("Escreva um número: ");
        scanf("%d", &n);
        if (n < 0)
            totn++;
        i++;
    }

    printf("%d dos números informados são negativos", totn);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}