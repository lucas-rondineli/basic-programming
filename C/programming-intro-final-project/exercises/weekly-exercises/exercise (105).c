#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void clearBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

double fatorial(double n)
{
    if (n == 1)
        return 1.0;
    return n * fatorial(n - 1);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "portuguese");

    int a[10];
    double b[10];

    if (argc == 11)
    {
        for (int i = 0; i < 10; i++)
        {
            a[i] = atoi(argv[i + 1]);
            b[i] = fatorial((double)a[i]);
        }
        printf("Vetor A: ");
        for (int i = 0; i < 10; i++)
            printf("%d ", a[i]);
        printf("\nVetor B: ");
        for (int i = 0; i < 10; i++)
            printf("%.0f ", b[i]);
    }
    else
        printf("Erro\n");


    if (getchar() != '\n')
        clearBuffer();
    return 0;
}
