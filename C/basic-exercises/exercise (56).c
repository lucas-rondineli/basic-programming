#include <stdio.h>
#include <locale.h>

void concatenar(int a[], int size_a, int b[], int size_b, int c[])
{
    int size_c = size_a + size_b;

    for (int i = 0; i < size_a; i++)
        c[i] = a[i];
    
    for (int i = size_a; i < size_c; i++)
        c[i] = b[i - size_a];
    return;
}


int main()
{
    setlocale(LC_ALL, "portuguese");

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {5, 4, 3, 2, 1};
    
    int c[sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0])];
    concatenar(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]), c);

    for (int i = 0; i < sizeof(c) / sizeof(c[0]); i++)
        printf("%d ", c[i]);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
