#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define arrLen(arr) (sizeof(arr) / sizeof(arr[0]))

void fill(int lin, int col, int m[lin][col])
{
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
            m[i][j] = 10 - rand() % 20;
}

void show(int lin, int col, int m[lin][col])
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }
}

void zeroLin(int lin, int col, int m[lin][col])
{

    for (int i = 0; i < lin; i++)
    {
        int total = 0;
        for (int j = 0; j < col; j++)
            if (m[i][j] == 0)
                total++;
        printf("O total de 0's na linha %d é: %d\n", i + 1, total);
    }
    printf("\n");
}

void zeroCol(int lin, int col, int m[lin][col])
{
    for (int i = 0; i < lin; i++)
    {
        int total = 0;
        for (int j = 0; j < col; j++)
            if (m[j][i] == 0)
                total++;
        printf("O total de 0's na coluna %d é: %d\n", i + 1, total);
    }
    printf("\n");
}

void evenLin(int lin, int col, int m[lin][col])
{
    int chosenLin, totalEven = 0;
    printf("Informe uma linha de 1 à %d: ", lin);
    scanf("%d", &chosenLin);
    chosenLin--;

    for (int i = 0; i < col; i++)
        if (m[chosenLin][i] % 2 == 0)
            totalEven++;
    printf("O número de elementos pares na linha %d é: %d\n\n", chosenLin + 1, totalEven);
}

void evenCol(int lin, int col, int m[lin][col])
{
    int chosenCol, totalEven = 0;
    printf("Informe uma coluna de 1 à %d: ", col);
    scanf("%d", &chosenCol);
    chosenCol--;

    for (int i = 0; i < lin; i++)
        if (m[i][chosenCol] % 2 == 0)
            totalEven++;
    printf("O número de elementos pares na linha %d é: %d\n\n", chosenCol + 1, totalEven);
}

void meanLin(int lin, int col, int m[lin][col], float v[lin])
{
    for (int i = 0; i < lin; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
            sum += m[i][j];
        v[i] = (float)sum / col;
    }
}

int biggerMeanLin(float mean[], int size)
{
    float biggerNum = mean[0];
    int biggerPos = 0;
    for (int i = 1; i < size; i++)
        if (mean[i] > biggerNum)
        {
            biggerNum = mean[i];
            biggerPos = i;
        }
    return biggerPos + 1;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    const int lin = 3;
    const int col = 3;
    int m[lin][col];
    float meanL[lin];
    fill(lin, col, m);
    printf("Matriz M:\n");
    show(lin, col, m);

    zeroLin(lin, col, m);
    zeroCol(lin, col, m);
    evenLin(lin, col, m);
    evenCol(lin, col, m);
    meanLin(lin, col, m, meanL);
    printf("Médias das linhas:\n");
    for (int i = 0; i < lin; i++)
        printf("%.2f ", meanL[i]);
    printf("\n\n");
    printf("A linha com a maior média é: %d", biggerMeanLin(meanL, arrLen(meanL)));

    getchar();
    return 0;
}
