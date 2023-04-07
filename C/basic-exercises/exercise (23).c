#include <stdio.h>

int main()
{
    short int n, dentro = 0, fora = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite um valor: ");
        scanf("%hd", &n);
        if (10 <= n && n <= 50)
            dentro += 1;
        else
            fora += 1;
    }

    printf("\nEntre 10 e 50: %d\nFora: %d\n", dentro, fora);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}