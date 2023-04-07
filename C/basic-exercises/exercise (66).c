#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int a[10], b[10], c[20];

    printf("Digite 10 valores para A: ");
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    printf("Digite 10 valores para B: ");
    for (int i = 0; i < 10; i++)
        scanf("%d", &b[i]);

    for (int i = 0; i < 20; i += 2)
        c[i] = a[i / 2];

    for (int i = 1; i < 20; i += 2)
        c[i] = b[i / 2];

    printf("Vetor C: ");
    for (int i = 0; i < 20; i++)
        printf("%d ", c[i]);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
