#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void clearBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

int maior(int v[], int sizeV, int atual)
{
    if (atual < sizeV)
        return v[atual] > v[maior(v, sizeV, atual + 1) ? v[atual] : v[atual - 1]];
    return atual - 1;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "portuguese");

    if (argc > 1)
    {
        int v[argc - 1];
        for (int i = 0; i < argc - 1; i++)
            v[i] = atoi(argv[i + 1]);

        printf("O maior elemento foi: %d", maior(v, argc - 1, v[0]));
    }
    else
        printf("Erro\n");


    if (getchar() != '\n')
        clearBuffer();
    return 0;
}
