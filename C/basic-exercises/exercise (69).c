#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int v[16];

    printf("Digite 16 valores: ");
    for (int i = 0; i < 16; i++)
        scanf("%d", &v[i]);

    for (int i = 0; i < 8; i++)
    {
        v[i] += v[i + 8];
        v[i + 8] = v[i] - v[i + 8];
        v[i] = v[i] - v[i + 8];
    }

    printf("Vetor: ");
    for (int i = 0; i < 16; i++)
        printf("%d ", v[i]);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
