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

void minimalMultiply(int mo[][3], int md[][3])
{
    int min = mo[0][0];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (min > mo[i][j])
                min = mo[i][j];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            md[i][j] = mo[i][j] * min;
    return;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int m[3][3], r[3][3];
    fill(m);
    printf("Matriz M:\n");
    show(m);

    minimalMultiply(m, r);

    printf("Matriz R:\n");
    show(r);

    getchar();
    return 0;
}
