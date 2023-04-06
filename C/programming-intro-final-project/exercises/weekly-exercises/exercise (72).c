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

void biggerLine(int m[][3])
{
    int bigger = 0, line;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        printf("\nLinha %d: ", i);
        for (int j = 0; j < 3; j++)
        {
            printf("%3d ", m[i][j]);
            sum += m[i][j];
        }
        printf("Soma: %d", sum);
        if (sum > bigger)
        {
            bigger = sum;
            line = i;
        }
    }
    printf("\nMaior linha: %d", line);
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int b[3][3];
    fill(b);
    printf("Matriz B:\n");
    show(b);

    biggerLine(b);

    getchar();
    return 0;
}
