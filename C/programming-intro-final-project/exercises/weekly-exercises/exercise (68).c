#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int r[4][5], mNum, mLin = 0, mCol = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            r[i][j] = rand() % 100;
    mNum = r[0][0];

    printf("Para a matriz:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%3d ", r[i][j]);
        printf("\n");
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (r[i][j] > mNum)
            {
                mNum = r[i][j];
                mLin = i;
                mCol = j;
            }
    printf("O maior elemento é: %d. Ele está na linha %d e na coluna %d", mNum, mLin + 1, mCol + 1);

    getchar();
    return 0;
}