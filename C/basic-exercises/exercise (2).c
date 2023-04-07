#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define arrLen(arr) (sizeof(arr) / sizeof(arr[0]))

void fill(int v[], int size)
{
    for (int i = 0; i < size; i++)
        v[i] = rand() % 10;
}

void show(int v[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%4d", v[i]);
    printf("\n\n");
}

void vetRs(int v1[], int v2[], int vr1[], int *sizeVr1, int vr2[], int *sizeVr2)
{
    *sizeVr1 = 0;
    *sizeVr2 = 0;
    int v2Sum = 0;
    for (int i = 0; i < 5; i++)
        v2Sum += v2[i];
    for (int i = 0; i < 10; i++)
        if ((v1[i] + v2Sum) % 2 == 0)
            vr1[(*sizeVr1)++] = v1[i] + v2Sum;
        else
            vr2[(*sizeVr2)++] = v1[i] + v2Sum;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int v1[10], v2[5], vr1[10], sizeVr1, vr2[10], sizeVr2;
    fill(v1, arrLen(v1));
    fill(v2, arrLen(v2));

    printf("Vetor V1: ");
    show(v1, arrLen(v1));

    printf("Vetor V2: ");
    show(v2, arrLen(v2));

    vetRs(v1, v2, vr1, &sizeVr1, vr2, &sizeVr2);

    printf("Vetor Resultante 1: ");
    show(vr1, sizeVr1);

    printf("Vetor Resultante 2: ");
    show(vr2, sizeVr2);

    getchar();
    return 0;
}
