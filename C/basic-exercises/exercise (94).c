#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(float v[])
{
    for (int i = 0; i < 12; i++)
        v[i] = 33 - (float)(rand() % 1100) / 100;
}

void analyseMonthTemp(float v[], int *bM, float *bT, int *sM, float *sT)
{
    *bM = 0;
    *bT = v[0];
    *sM = 0;
    *sT = v[0];

    for (int i = 0; i < 12; i++)
    {
        if (v[i] > *bT)
        {
            *bM = i;
            *bT = v[i];
        }
        if (v[i] < *sT)
        {
            *sM = i;
            *sT = v[i];
        }
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    float monthMeanTemp[12], bigTemp, smallTemp;
    int bigMonth, smallMonth;
    char bigMonthName[10], smallMonthName[10];
    char monthsNames[12][10] = {"janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

    fill(monthMeanTemp);
    printf("Temperaturas anuais:\n");
    for (int i = 0; i < 12; i++)
        printf("%02d - %.2f °C\n", i + 1, monthMeanTemp[i]);

    analyseMonthTemp(monthMeanTemp, &bigMonth, &bigTemp, &smallMonth, &smallTemp);

    printf("\nA maior temperatura foi em %s, com o valor de %.2f °C", monthsNames[bigMonth], bigTemp);
    printf("\nA menor temperatura foi em %s, com o valor de %.2f °C", monthsNames[smallMonth], smallTemp);

    getchar();
    return 0;
}
