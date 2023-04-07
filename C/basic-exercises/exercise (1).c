#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void fill(int m[][7])
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++)
            m[i][j] = rand() % 100;
}

void show(int m[][7])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
            printf("%+4d", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

int pontodesela(int m[][7], int *lin, int *col)
{
    for (int i = 0; i < 5; i++)
    {
        int menorDaLinhaValor = m[i][0];
        int menorDaLinhaPos = 0;

        for (int j = 0; j < 7; j++)
            if (m[i][j] < menorDaLinhaValor)
            {
                menorDaLinhaValor = m[i][j];
                menorDaLinhaPos = j;
            }
        int j = 0;
        for (j; j < 5; j++)
            if (m[j][menorDaLinhaPos] > menorDaLinhaValor)
                break;
        if (j < 5)
            continue;
        *lin = i;
        *col = menorDaLinhaPos;
        return 1;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int a[5][7];
    int pontoL, pontoC;
    char opt;

    while (1)
    {
        printf("Deseja escolher os valores da matriz? [S/N] ");
        scanf(" %c", &opt);
        if (opt == 'S' || opt == 's' || opt == 'N' || opt == 'n')
        {
            while (getchar() != '\n')
                ;
            break;
        }
        printf("Digite uma opção válida, S ou N. ");
    }

    if (opt == 'S' || opt == 's')
    {
        int v;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 7; j++)
            {
                printf("Digite o valor de A[%d][%d]: ", i + 1, j + 1);
                scanf("%d", &v);
                a[i][j] = v;
            }
    }
    else
        fill(a);

    printf("Matriz A:\n");
    show(a);

    if (pontodesela(a, &pontoL, &pontoC))
        printf("Existe um ponto de sela. O elemento de valor %d, da linha %d e coluna %d.\n", a[pontoL][pontoC], pontoL + 1, pontoC + 1);
    else
        printf("Não existe um ponto de sela na matriz.");

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
