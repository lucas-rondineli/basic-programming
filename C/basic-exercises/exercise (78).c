#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(int m[][8])
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            m[i][j] = rand() % 100;
    return;
}

void show(int m[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            printf("%5d ", m[i][j]);
        printf("\n");
    }
}

void sumLine(int m[][8], int sum[])
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            sum[i] += m[i][j];
    return;
}

void multiplyLine(int m[][8], int sum[])
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            m[i][j] *= sum[i];
    return;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int m[8][8], sum[8] = {0};
    fill(m);
    // Última linha se torna 1
    for (int i = 0; i < 8; i++)
        m[7][i] = 1;
    printf("Matriz M:\n");
    show(m);

    sumLine(m, sum);
    multiplyLine(m, sum);

    printf("\nNova matriz M:\n");
    show(m);

    getchar();
    return 0;
}
