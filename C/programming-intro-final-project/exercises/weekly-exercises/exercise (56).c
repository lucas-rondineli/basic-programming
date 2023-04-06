#include <stdio.h>
#include <locale.h>
#define arr_len(arr) (sizeof(arr) / sizeof(arr[0]))

int no_repeat(int x[])
{
    int pos = 0;
    for (int i = 0; i < 10; i++)
    {
        int j = 0;
        for (j; j < i; j++)
            if (x[i] == x[j])
                break;
        if (j == i)
        {
            x[pos] = x[i];
            pos++;
        }
    }
    for (int i = pos; i < 10; i++)
        x[i] = 0;
    return pos;
}

int intersection(int a[], int b[], int c[])
{
    int elements_a = no_repeat(a);
    int elements_b = no_repeat(b);

    int pos = 0;
    for (int i = 0; i < elements_a; i++)
        for (int j = 0; j < elements_b; j++)
            if (a[i] == b[j])
            {
                c[pos] = a[i];
                pos++;
                break;
            }
    return pos;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int a[] = {0, 0, 0, 1, 1, 1, 1, 1, 2, 3};
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int c[arr_len(a) + arr_len(b)] = {0};

    int elements_c = intersection(a, b, c);

    printf("Vetor A: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n\n");

    printf("Vetor B: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", b[i]);
    printf("\n\n");

    printf("Vetor C: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", c[i]);
    printf("\n\n");

    printf("Vetor Interseção: ");
    for (int i = 0; i < elements_c; i++)
        printf("%d ", c[i]);

    getchar();
    return 0;
}
