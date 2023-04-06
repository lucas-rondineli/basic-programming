#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int v[10];
    const int multiplier = 15;

    printf("Digite 10 valores: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &v[i]);
        if (i % 2 == 1)
            v[i] *= multiplier;
    }

    printf("Vetor: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", v[i]);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
