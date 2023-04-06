#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int a[20], b[20];

    printf("Digite 20 valores: ");
    for (int i = 0; i < 20; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < 20; i++)
        b[i] = a[19 - i];

    printf("Vetor B: ");
    for (int i = 0; i < 20; i++)
        printf("%d ", b[i]);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
