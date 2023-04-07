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

void transpost(int mo[][3], int md[][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            md[i][j] = mo[j][i];
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int a[3][3], t[3][3];
    fill(a);
    printf("Matriz A:\n");
    show(a);
    transpost(a, t);
    printf("\nMatriz T:\n");
    show(t);

    getchar();
    return 0;
}
