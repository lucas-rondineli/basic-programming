#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(int m[][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m[i][j] = rand() % 100;
    return;
}

void show(int m[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }
}

int diagSum(int m[3][3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
        sum += m[i][2 - i];
    return sum;
}

void storeDiag(int mo[3][3], int md[])
{
    for (int i = 0; i < 3; i++)
        md[i] = mo[i][2 - i];
    return;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int a[3][3], d[3];
    fill(a);
    printf("Matriz A:\n");
    show(a);

    printf("A soma dos elementos da diagonal secundária de A é: %d\n", diagSum(a));

    storeDiag(a, d);
    printf("Elementos de D: ");
    for (int i = 0; i < 3; i++)
        printf("%d ", d[i]);

    getchar();
    return 0;
}