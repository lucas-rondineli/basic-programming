#include <stdio.h>

int main()
{
    short unsigned int n, k;
    long double x;

    printf("Digite o N e o K: ");
    scanf("%hu%hu", &n, &k);
    x = k;

    for (int i = 1; i <= n; i++)
    {
        printf("%u elevado a %d = %.0Lf\n", k, i, x);
        x *= k;
    }

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}