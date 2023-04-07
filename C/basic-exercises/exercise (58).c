#include <stdio.h>
#include <locale.h>

int fact(int n)
{
    if (n == 1)
        return 1;

    return n * fact(n - 1);
}

void factorial(int a[], int b[])
{
    for (int i = 0; i < 10; i++)
        b[i] = fact(a[i]);
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int a[] = {1, 2, 3, 4, 5, 5, 5, 5, 5, 5};
    int b[10];

    factorial(a, b);

    printf("Vetor B: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", b[i]);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
