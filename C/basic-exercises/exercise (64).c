#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int v[10];

    for (int i = 0; i < 10; i++)
        if (i % 2 == 1)
            v[i] = 1;
        else
            v[i] = 0;

    printf("Vetor: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", v[i]);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
