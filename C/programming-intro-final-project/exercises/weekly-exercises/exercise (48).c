#include <stdio.h>
#include <locale.h>

void MM(int *A, int *B)
{
    if (*A > *B)
    {
        *B = *B + *A;
        *A = *B - *A;
        *B = *B - *A;
    }
    return;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int x, y;

    printf("Digite dois valores: ");
    scanf("%d%d", &x, &y);

    MM(&x, &y);

    printf("Menor: %d\nMaior: %d", x, y);

    while(getchar() != '\n')
        ;
    getchar();
    return 0;
}
