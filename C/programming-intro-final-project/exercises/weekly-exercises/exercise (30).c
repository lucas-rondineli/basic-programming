#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    short unsigned int n1 = 2, n2 = 7, n3 = 3, n, r;

    printf("Informe o número de termos a serem mostrados: ");
    scanf("%hu", &n);

    r = n % 3;
    n /= 3;

    for (int i = 0; i < n; i++)
    {
        printf("%u %u %u ", n1, n2, n3);
        n1 *= 2;
        n2 *= 3;
        n3 *= 4;
    }

    switch (r)
    {
    case 0:
        break;
    case 1:
        printf("%u", n1);
        break;
    case 2:
        printf("%u %u", n1, n2);
        break;
    default:
    }

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}