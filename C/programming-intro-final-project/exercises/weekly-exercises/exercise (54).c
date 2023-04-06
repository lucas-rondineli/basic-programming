#include <stdio.h>
#include <locale.h>

int find(int v[], int number, int size_v)
{
    for (int i = 0; i < size_v; i++)
        if (v[i] == number)
            return i;
    
    printf("Número não encontrado.\n");
    return -1;
}


int main()
{
    setlocale(LC_ALL, "portuguese");

    int v[] = {1, 2, 3, 4, 5};
    int number = 6;

    printf("Posição do número %d: %d\n", number, find(v, number, sizeof(v) / sizeof(v[0])));

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
