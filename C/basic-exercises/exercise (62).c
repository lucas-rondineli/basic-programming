#include <stdio.h>
#include <locale.h>
#define arr_len(arr) (sizeof(arr) / sizeof(arr[0]))

int main()
{
    setlocale(LC_ALL, "portuguese");

    int v[10], s = 0, above_average = 0;
    float v_mean = 0;

    printf("Digite 10 valores: ");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &v[i]);
        s += v[i];
    }
    v_mean = (float)s / arr_len(v);

    printf("A média foi de: %.2f\n", v_mean);

    for (int i = 0; i < 10; i++)
        if (v[i] > v_mean)
            above_average++;

    printf("Números acima da média: %d\n", above_average);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
