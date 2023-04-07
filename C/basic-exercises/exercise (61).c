#include <stdio.h>
#include <locale.h>
#define arr_len(arr) (sizeof(arr) / sizeof(arr[0]))

int main()
{
    setlocale(LC_ALL, "portuguese");

    int v[10], s = 0;

    printf("Digite 10 valores: ");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &v[i]);
        s += v[i];
    }

    printf("A média foi de: %.2f", (float)s / arr_len(v));

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
