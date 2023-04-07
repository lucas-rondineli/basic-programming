#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int a[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
    int b[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int c[10];

    for (int i = 0; i < 10; i++)
        c[i] = a[i] + b[i];

    printf("Vetor: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", c[i]);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
